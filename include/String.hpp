#include <cstddef>
#include <ostream>

inline std::size_t StrLen (const char*);

class String {
private:
    char* str{nullptr};
    std::size_t size{0}; 
    std::size_t capacity{0};

    void Reserve (const std::size_t&);
public:
    String () = default;
    String (const char* _str) {
        StrCpy(*this, _str);
    }
    ~String () { delete[] str; str = nullptr; size = 0; }
    String (const String& other) {
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

// seted the size to keep the count of chars only
inline std::size_t StrLen (String& strClass) {
    for (const char* ptr = strClass.str; *ptr != '\0'; ptr++) {
        strClass.size++;
    }
    return strClass.size;
}

inline std::size_t StrLen (const char* _str) {
    std::size_t size = 0;
    for (const char* ptr = _str; *ptr != '\0'; ptr++) {
        size++;
    } return size;
}

inline std::ostream& operator << (std::ostream& os, const String& s) {
    if (s.str != nullptr) 
        os << s.str;
    return os;
}

inline void StrCpy (String& bufferClass, const char* other) { 
    // prams (buffer, stwr), buffer and stwr can be class or char array
    // size of other, then buffclass
    if (other != nullptr) {
        auto* tempSize = &bufferClass.size;
        *tempSize = StrLen(other);
        if (bufferClass.str != nullptr) {
            delete[] bufferClass.str;
        }
        if (*tempSize+1 > bufferClass.capacity) {
            bufferClass.Reserve(*tempSize);
        } else {
            bufferClass.str = new char[*tempSize];
        }
        for (size_t i = 0; i < *tempSize; i++) {
            bufferClass.str[i] = other[i];
        }
    }
}