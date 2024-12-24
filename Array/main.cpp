#include <iostream>
#include <stdexcept>
#include "Array.h"

int main() {
 
    int data[] = { 1, 5, 3, 9, 2 };
    Array<int> intArray(data, 5);

    std::cout << "Array of integers: ";
    intArray.show();

    try 
    {
        int minInt = intArray.minimum();
        std::cout << "Minimum value in int array: " << minInt << std::endl;
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    double dataDouble[] = { 1.5, 2.3, 0.7, 4.1 };
    Array<double> doubleArray(dataDouble, 4);

    std::cout << "Array of doubles: ";
    doubleArray.show();

    try 
    {
        double minDouble = doubleArray.minimum();
        std::cout << "Minimum value in double array: " << minDouble << std::endl;
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}