#include "text_editor.h"
#include <iostream>

TextEditor::TextEditor() {}
TextEditor::TextEditor(const TextEditor& other)
{
	leftStack = other.leftStack;
	rightStack = other.rightStack;
}
TextEditor& TextEditor::operator=(const TextEditor& other)
{
	if (this != &other)
	{
		leftStack = other.leftStack;
		rightStack = other.rightStack;
	}
	return *this;
}
TextEditor::~TextEditor() {}
void TextEditor::addText(std::string text)
{
	for (char a : text)
	{
		leftStack.push(a);
	}
}
int TextEditor::deleteText(int k)
{
	int count = 0;
	while (!leftStack.empty() && k > 0)
	{
		leftStack.pop();
		--k;
		++count;
	}
	return count;
}
std::string TextEditor::cursorLeft(int k)
{
	while (!leftStack.empty() && k > 0)
	{
		rightStack.push(leftStack.top());
		leftStack.pop();
		--k;
	}
	std::string letter;
	std::stack<char> Stack = leftStack;
	while (!Stack.empty())
	{
		letter = Stack.top() + letter;
		Stack.pop();
	}
	return letter;
}
std::string TextEditor::cursorRight(int k)
{
	while (!rightStack.empty() && k > 0)
	{
		leftStack.push(rightStack.top());
		rightStack.pop();
		--k;
	}
	std::string letter;
	std::stack<char> Stack = rightStack;
	while (!Stack.empty())
	{
		letter = Stack.top() + letter;
		Stack.pop();
	}
	return letter;
}