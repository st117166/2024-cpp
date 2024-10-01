#include <iostream>
#include <string>
using namespace std;

void TextEditor();
void addText(string text);
int deleteText(int k);
string cursorLeft(int k);
string cursorRight(int k);
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

void addText(string text)
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
string cursorLeft(int k)
{
	while (leftVertex >= 0 && k > 0)
	{
		if (rightVertex < max_size - 1)
		{
			rightStack[++rightVertex] = leftStack[leftVertex--];
		}
		k--;
	}
	string leftres(leftStack, leftVertex + 1);
	return leftres;
}
string cursorRight(int k)
{
	while (rightVertex >= 0 && k > 0)
	{
		if (leftVertex < max_size - 1)
		{
			leftStack[++leftVertex] = rightStack[rightVertex--];
		}
		k--;
	}
    string rightres(rightStack, rightVertex + 1);

	return rightres;
}
int main(int argc, char* argv[])

{
	TextEditor();
	addText("abcgef");
	cout << cursorLeft(2) << endl;
	addText("ghjklm");
	cout << cursorRight(3) << endl;
	cout << deleteText(5) << endl;
	cout << cursorLeft(3) << endl;

	return 0;
}