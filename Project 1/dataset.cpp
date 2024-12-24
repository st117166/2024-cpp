#include "dataset.h"

std::vector<std::string> Dataset::separation(const std::string& line, char delimiter)
	{
		std::vector<std::string> result;
		std::string current;
		for (char a : line)
		{
			if (a == delimiter)
			{
				result.push_back(current);
				current.clear();
			}
			else
			{
				current += a;
			}
		}
		result.push_back(current);
		return result;
	}

Dataset::Dataset(const std::string& filePath, const std::vector<std::string>& columnNames = {}, bool generateNumber = true) : generateNumber(generateNumber), size(0)
{
	std::ifstream file(filePath);
	if (!file.is_open())
	{
		throw std::runtime_error("Failed to open file");
	}
        
	std::string line;
	std::vector<std::string> headers;

	if (std::getline(file, line))
	{
		headers = separation(line, ',');
	}
	if (columnNames.empty())
	{
		this->columnNames = headers;
	}
	else
	{
		this->columnNames = columnNames;
	}
	if (generateNumber)
	{
		this->columnNames.insert(this->columnNames.begin(), "index");
	}
	size_t rowIndex = 0;
	while (std::getline(file, line))
	{
		auto values = separation(line, ',');
		std::map<std::string, std::string> row;
		if (generateNumber)
		{
			row["index"] = std::to_string(rowIndex++);
		}
		for (size_t i = 0; i < values.size(); ++i)
		{
			row[this->columnNames[generateNumber ? i + 1 : i]] = values[i];
		}
		data.push_back(row);
		++size;
	}
	file.close();
}

void Dataset::head(size_t n = 5) const
{
	n = std::min(n, size);
	std::vector<size_t> columnWidths(columnNames.size(), 0);
	for (size_t i = 0; i < columnNames.size(); ++i)
	{
		columnWidths[i] = columnNames[i].length();
	}
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < columnNames.size(); ++j)
		{
			size_t dataLength = data[i].at(columnNames[j]).length();
			columnWidths[j] = std::max(columnWidths[j], dataLength);
		}
	}
	for (size_t i = 0; i < columnNames.size(); ++i)
	{
		std::cout << std::setw(columnWidths[i] + 2) << columnNames[i];
	}
	std::cout << std::endl;

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < columnNames.size(); ++j)
		{
			std::cout << std::setw(columnWidths[j] + 2) << data[i].at(columnNames[j]);
		}
		std::cout << std::endl;
	}
}

void Dataset::tail(size_t n = 5) const
{
	n = std::min(n, size);
	std::vector<size_t> columnWidths(columnNames.size(), 0);
	for (size_t i = 0; i < columnNames.size(); ++i)
	{
		columnWidths[i] = columnNames[i].length();
	}
	for (size_t i = size - n; i < size; ++i)
	{
		for (size_t j = 0; j < columnNames.size(); ++j)
		{
			size_t dataLength = data[i].at(columnNames[j]).length();
			columnWidths[j] = std::max(columnWidths[j], dataLength);
		}
	}
	for (size_t i = 0; i < columnNames.size(); ++i)
	{
		std::cout << std::setw(columnWidths[i] + 2) << columnNames[i];
	}
	std::cout << std::endl;

	for (size_t i = size - n; i < size; ++i)
	{
		for (size_t j = 0; j < columnNames.size(); ++j)
		{
			std::cout << std::setw(columnWidths[j] + 2) << data[i].at(columnNames[j]);
		}
		std::cout << std::endl;
	}
}

void Dataset::insert(size_t index, const std::vector<std::string>& row)
{
	if (row.size() != columnNames.size() - generateNumber)
	{
		throw std::invalid_argument("The number of elements in a row does not match the number of columns");
	}
	std::map<std::string, std::string> newRow;
	if (generateNumber)
	{
		newRow["index"] = std::to_string(index);
	}
	for (size_t i = 0; i < row.size(); ++i)
	{
		newRow[columnNames[generateNumber ? i + 1 : i]] = row[i];
	}
	data.insert(data.begin() + index, newRow);
	++size;
}

void Dataset::remove(size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of range");
	}
	data.erase(data.begin() + index);
	--size;
}

void Dataset::describe(const std::string& columnName) const 
{
	for (const auto& col : columnNames)
	{
		std::cout << col << std::endl;
	}

	if (std::find(columnNames.begin(), columnNames.end(), columnName) == columnNames.end()) 
	{
		std::cerr << "Error. Column not found " << columnName << std::endl;
		return;
	}

	std::vector<double> values;

	for (const auto& row : data) 
	{
		const std::string& cellValue = row.at(columnName);
		double value = 0.0;
		bool isNegative = false;
		bool hasDecimal = false;
		double decimalFactor = 0.1;

		for (size_t i = 0; i < cellValue.size(); ++i) 
		{
			char ch = cellValue[i];

			if (i == 0 && ch == '-') 
			{ 
				isNegative = true;
				continue;
			}

			if (ch == '.') 
			{ 
				if (hasDecimal) {
					std::cerr << "Error: incorrect number format" << cellValue << std::endl;
					return;
				}
				hasDecimal = true;
				continue;
			}

			if (ch < '0' || ch > '9') 
			{ 
				std::cerr << "Error: incorrect number format" << cellValue << std::endl;
				return;
			}

			if (!hasDecimal) 
			{
				value = value * 10 + (ch - '0');
			}
			else 
			{
				value += (ch - '0') * decimalFactor;
				decimalFactor *= 0.1;
			}
		}

		if (isNegative) 
		{
			value = -value;
		}

		values.push_back(value);
	}

	if (values.empty()) 
	{
		std::cerr << "Error. The column" << columnName << "is empty" << std::endl;
		return;
	}

	double maxVal = values[0];
	double minVal = values[0];
	double sum = 0.0;

	for (double value : values) 
	{
		if (value > maxVal) maxVal = value;
		if (value < minVal) minVal = value;
		sum += value;
	}

	double meanVal = sum / values.size();

	double variance = 0.0;
	for (double value : values) 
	{
		variance += (value - meanVal) * (value - meanVal);
	}
	double stdDev = std::sqrt(variance / values.size());

	std::cout << "Satic values for a column" << columnName << std::endl;
	std::cout << "  Maximum: " << maxVal << std::endl;
	std::cout << "  Minimum: " << minVal << std::endl;
	std::cout << "  Mean: " << meanVal << std::endl;
	std::cout << "  Standart deviation: " << stdDev << std::endl;
}

std::map<std::string, std::string>& Dataset::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}              