MyTextEditor: main.o text_editor.o
	g++ main.o text_editor.o -o MyTextEditor
main.o: main.cpp
	g++ -c main.cpp
text_editor.o: text_editor.cpp
	g++ -c text_editor.cpp
clean:
	rm -r MyTextEditor *.o