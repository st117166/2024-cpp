#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <stdexcept>

class Dataset
{
private:

	std::vector<std::map<std::string, std::string>> data;
	std::vector<std::string> columnNames;
	bool generateNumber;
	size_t size;

	std::vector<std::string> separation(const std::string& line, char delimiter);

public:

	Dataset(const std::string& filePath, const std::vector<std::string>& columnNames = {}, bool generateNumber = true);

	void head(size_t n = 5) const;
	void tail(size_t n = 5) const;
	void insert(size_t index, const std::vector<std::string>& row);
	void remove(size_t index);
	void describe(const std::string& columnName) const;

	std::map<std::string, std::string>& operator[](size_t index);
};
