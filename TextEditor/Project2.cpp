#include <iostream>
#include <string>

void TextEditor();
void addText(std::string text);
int deleteText(int k);
std::string cursorLeft(int k);
std::string cursorRight(int k);
const int max_size = 100000;
char leftStack[max_size];
char rightStack[max_size];
int leftVertex = -1;
int rightVertex = -1;

void TextEditor()
{
	leftVertex = -1;
	rightVertex = -1;
}

void addText(std::string text)
{
	for (char a : text)
	{
		if (leftVertex < max_size - 1)
		{
			leftStack[++leftVertex] = a;
		}
	}
}
int deleteText(int k)
{
	int count = 0;
	while (leftVertex >= 0 && k > 0)
	{
		leftVertex--;
		count++;
		k--;
	}
	return count;
}
std::string cursorLeft(int k)
{
	while (leftVertex >= 0 && k > 0)
	{
		if (rightVertex < max_size - 1)
		{
			rightStack[++rightVertex] = leftStack[leftVertex--];
		}
		k--;
	}
	std::string leftres(leftStack, leftVertex + 1);
	return leftres;
}
std::string cursorRight(int k)
{
	while (rightVertex >= 0 && k > 0)
	{
		if (leftVertex < max_size - 1)
		{
			leftStack[++leftVertex] = rightStack[rightVertex--];
		}
		k--;
	}
    std::string rightres(rightStack, rightVertex + 1);

	return rightres;
}
int main(int argc, char* argv[])

{
	TextEditor();
	addText("abcgef");
	std::cout << cursorLeft(2) << std::endl;
	addText("ghjklm");
	std::cout << cursorRight(3) << std::endl;
	std::cout << deleteText(5) << std::endl;
	std::cout << cursorLeft(3) << std::endl;

	return 0;
}
