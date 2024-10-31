//
// text_editor.h
//

#pragma once

#include "gtest/gtest.h"
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

class TextEditorTest : public testing::Test
{
protected:
	TextEditor editor;
};

TEST_F(TextEditorTest, InizializationTest) {};
TEST_F(TextEditorTest, AddTextTest) {};
TEST_F(TextEditorTest, DeleteTextTest) {};
TEST_F(TextEditorTest, cursorRightTest) {};
TEST_F(TextEditorTest, cursorLeftTest) {};

#endif 