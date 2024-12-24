template <class T>
class Array 
{
private:
	T* array;
	size_t size;

public:

	Array() : array(nullptr), size(0) {}

	Array(T* b, size_t s) 
	{
		size = s;
		array = new T[size];
		for (size_t i = 0; i < size; ++i) 
		{
			array[i] = b[i];
		}
	}

	void show() 
	{
		for (size_t i = 0; i < size; ++i) 
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
	}

	T minimum() 
	{
		if (size == 0) 
		{
			throw std::out_of_range("Array is empty.");
		}
		T min = array[0];
		for (size_t i = 1; i < size; ++i) 
		{
			if (array[i] < min) 
			{
				min = array[i];
			}
		}
		return min;
	}

	~Array() {
		delete[] array;
	}
};