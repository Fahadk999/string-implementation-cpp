#include <cstddef>
#include <iostream>
#include <utility>


std::size_t StrLen (const char* _str) {
    std::size_t size = 0;
    for (const char* ptr = _str; *ptr != '\0'; ptr++) {
        size++;
    } return size+1;
}

class String {
private:
    char* str{nullptr};
    std::size_t size{0}; 

public:
    // Rule of Three -- done
    // Rule of Five -- done
    String (const char* _str) {
        StrCpy(*this, _str);
    }
    ~String () { delete[] str; str = nullptr; size = 0; }
    String (const String& other) {
        StrCpy(*this, other.str);
    }
    String (String&& other) noexcept {
        StrCpy(*this, other.str);
        delete[] other.str;
        other.str = nullptr;
        other.size = 0;
    }
    
    String& operator = (const String& other) {
        if (this != &other) {
            StrCpy(*this, other.str);
        }
        return *this;
    }
    String& operator = (const char* _str) {
        StrCpy(*this, _str);
        return *this;
    }
    String& operator = (String&& other) noexcept {
        if (this != &other) {
            StrCpy(*this, other.str);
            delete[] other.str;
            other.str = nullptr;
            other.size = 0;
        }
        return *this;
    }
    char& operator [] (const size_t& index) { return str[index]; }
    const char& operator [] (const size_t& index) const { return str[index]; }

    friend std::size_t StrLen (String& strClass);
    friend void StrCpy (String& bufferClass, const char* other);  
    friend std::ostream& operator << (std::ostream& os, const String& s);
};

std::ostream& operator << (std::ostream& os, const String& s) {
    if (s.str != nullptr) 
        os << s.str;
    return os;
}
void StrCpy (String& bufferClass, const char* other) { 
    // prams (buffer, stwr), buffer and stwr can be class or char array
    // size of other, then buffclass
    bufferClass.size = StrLen(other);
    if (bufferClass.str != nullptr) {
        delete[] bufferClass.str;
    }
    bufferClass.str = new char[bufferClass.size];
    for (size_t i = 0; i < bufferClass.size; i++) {
        bufferClass.str[i] = other[i];
    }
}

std::size_t StrLen (String& strClass) {
    for (const char* ptr = strClass.str; *ptr != '\0'; ptr++) {
        strClass.size++;
    }
    strClass.size += 1;
    return strClass.size++;
}

int main () {
    String str2 = "Hello this is now a r val string";
    String str1 = std::move(str2);
    std::cout << str1[3];
    
    return 0;
}
