#include <gtest/gtest.h>
#include "text_editor.h"
#include "text_editor.cpp"

class TextEditorTest : public testing::Test {
protected:
    TextEditor editor;
};

TEST_F(TextEditorTest, InitializationTest) 
{
    EXPECT_NO_THROW(TextEditor());
}

TEST_F(TextEditorTest, AddTextTest) 
{
    editor.addText("abcde");
    EXPECT_EQ(editor.cursorLeft(5), "abcde");
}

TEST_F(TextEditorTest, DeleteTextTest) 
{
    editor.addText("abcde");
    int deleted = editor.deleteText(3);
    EXPECT_EQ(deleted, 3);
    EXPECT_EQ(editor.cursorLeft(2), "ab");
}

TEST_F(TextEditorTest, CursorLeftTest) 
{
    editor.addText("abcde");
    editor.cursorLeft(2);
    EXPECT_EQ(editor.cursorLeft(3), "ab");
}

TEST_F(TextEditorTest, CursorRightTest) 
{
    editor.addText("abcde");
    editor.cursorLeft(5);
    editor.cursorRight(3);
    EXPECT_EQ(editor.cursorRight(2), "de");
}