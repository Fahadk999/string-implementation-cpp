#include "String.hpp"

// seted the size to keep the count of chars only
std::size_t StrLen (String& strClass) {
    for (const char* ptr = strClass.str; *ptr != '\0'; ptr++) {
        strClass.size++;
    }
    return strClass.size;
}

std::size_t StrLen (const char* _str) {
    std::size_t size = 0;
    for (const char* ptr = _str; *ptr != '\0'; ptr++) {
        size++;
    } return size;
}

String& String::operator = (const String& other) {
    if (this != &other) {
        this->size = StrLen(other.str);
        this->capacity = this->size*2;
        StrCpy(*this, other.str);
    }
    return *this;
}
String& String::operator = (const char* _str) {
    this->size = StrLen(_str);
    this->capacity = this->size*2;
    StrCpy(*this, _str);
    return *this;
}
String& String::operator = (String&& other) noexcept {
    if (this != &other) {
        delete[] this->str;
        this->str = other.str;
        this->size = other.size;
        this->capacity = other.capacity;
        other.str = nullptr;
        other.size = 0;
    }
    return *this;
}

// just double the capacity utile greater than the new capacity
void String::Reserve (const std::size_t& newSize) {
    if (newSize > 0) {
        while (this->capacity < newSize) {
            this->capacity *= 2;
        }
        // Allocate
        if (this->str != nullptr) {
            std::cout << std::endl << "Resrved" << std::endl;
            delete[] this->str;
            this->str = new char[this->capacity+1];
            // copy old + new contents...
        } else {
            std::cout << std::endl << "Resrved" << std::endl;
            this->str = new char[this->capacity+1];
            // copy new contents...
        }
    }
}

void StrCpy (String& bufferClass, const char* other) { 
    // old size + new size
    // if size of other > this.capacity then reserve space
    if (bufferClass.str == other) return;
    else if (other != nullptr) {
        std::size_t&& newLen = StrLen(other);

        // Allocate a new array of capacity
        if (bufferClass.str == nullptr || newLen >= bufferClass.capacity) { 
            bufferClass.Reserve(newLen); }
        else 
            bufferClass.str = new char[bufferClass.capacity+1];

        // Put other into new array
        for (std::size_t i = 0; i < newLen; i++) {
            bufferClass.str[i] = other[i];
        }
    }
}
// prams can be class or char array

// Reserve based on string entered
// then + operator
// return cahr * for chaingin functions here...

