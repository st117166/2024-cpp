#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <stack>
#include <string>

class TextEditor
{
private:
	std::stack<char> leftStack;
	std::stack<char> rightStack;
public:
	TextEditor();
	TextEditor(const TextEditor& other);
	TextEditor& operator=(const TextEditor& other);
	~TextEditor();
	void addText(std::string text);
	int deleteText(int k);
	std::string cursorLeft(int k);
	std::string cursorRight(int k);
};

#endif 