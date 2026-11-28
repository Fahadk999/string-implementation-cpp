#include <cstddef>
#include <ostream>
#include <iostream>

std::size_t StrLen (const char*);

class String {
private:
    char* str{nullptr};
    std::size_t size{0}; 
    std::size_t capacity{0};

    void Reserve (const std::size_t&);
public:
    String () = default;
    String (const char* _str) {
        this->size = StrLen(_str);
        this->capacity = this->size*2;
        StrCpy(*this, _str);
    }
    ~String () { delete[] str; str = nullptr; size = 0; }
    String (const String& other) {
        this->size = StrLen(other.str);
        this->capacity = this->size*2;
        StrCpy(*this, other.str);
    }
    String (String&& other) noexcept 
    :
        str(other.str),
        size(other.size) 
    {
        other.str = nullptr;
        other.size = 0;
    }
    
    String& operator = (const String&);
    String& operator = (const char*); 
    String& operator = (String&&) noexcept; 

    char& operator [] (const size_t& index) { return str[index]; }
    const char& operator [] (const size_t& index) const { return str[index]; }

    friend std::size_t StrLen (String& strClass);
    friend void StrCpy (String& bufferClass, const char* other);  
    friend std::ostream& operator << (std::ostream& os, const String& s);
};

inline std::ostream& operator << (std::ostream& os, const String& s) {
    if (s.str != nullptr) 
        os << s.str;
    return os;
}

