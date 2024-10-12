#include "text_editor.h"
#include <iostream>

int main(int argc, char* argv[])
{
	TextEditor editor;
	editor.addText("abcdefghijklm");
	std::cout << editor.cursorLeft(2) << std::endl;
	TextEditor editor1 = editor;
	std::cout << editor1.deleteText(5) << std::endl;
	std::cout << editor.cursorRight(3) << std::endl;

	return 0;
}