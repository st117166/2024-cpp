#include "string.h"
#include <iostream>

String::String(const char* str) {
    size = strlen(str);
    this->str = new char[size + 1];
    for (size_t i = 0; i <= size; ++i)
        this->str[i] = str[i];
}

String::String(size_t n, char c) : size(n), str(0)
{
    this->str = new char[size + 1];
    for (int i = 0; i < size; this->str[i] = c, ++i);
    str[size] = '\0';
}

String::~String()
{
    delete[] str;
}

String::String(const String& other) :size(other.size)
{
    str = new char[size + 1];
    strcpy(str, other.str);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] this->str;
        this->size = other.size;
        this->str = new char[this->size + 1];
        strcpy(this->str, other.str);
    }

    return *this;
}

void String::append(const String& other)
{
    size += other.size;
    char* new_str = new char[size + 1];
    strcpy(new_str, str);
    strcat(new_str, other.str);
    delete[] str;
    str = new_str;
}
String String::operator[](size_t null) const
{
    return StringRange(*this, null);
}
const char* String::getStr() const
{
    return str;
}
size_t String::getSize() const
{
    return size;
}
StringRange::StringRange(const String& parent, size_t null) : parent(parent), null(null) {}
String StringRange::operator[](size_t end) const
{
    if (null == end)
    {
        return String(" ");
    }
    size_t new_size = end - null;
    char* new_str = new char[new_size + 1];
    strncpy(new_str, parent.getStr() + null, new_size);
    new_str[new_size] = '\0';
    return String(new_str);
}
std::ostream& operator<<(std::ostream& os, const String &string)
{
    os << string.getStr();
    return os;
}