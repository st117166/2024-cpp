#include <iostream>
#include <cstddef> 
#include <cstring> 

struct String {
public:
    String(const char* str = "");
    String(size_t n, char c);
    ~String();

    String(const String& other);
    String& operator=(const String& other);

    void append(const String& other);

    virtual String operator[](size_t null) const;
    size_t getSize() const;
    const char* getStr() const;
    friend std::ostream& operator<<(std::ostream& os, const String& string);
protected:
    size_t size;
    char* str;
};

struct StringRange : public String
{
    StringRange(const String& parent, size_t null);
    String operator[](size_t end) const;
private:
    size_t null;
    const String& parent;
    
};