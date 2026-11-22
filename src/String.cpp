#include "String.hpp"

String& String::operator = (const String& other) {
    if (this != &other) {
        StrCpy(*this, other.str);
    }
    return *this;
}
String& String::operator = (const char* _str) {
    StrCpy(*this, _str);
    return *this;
}
String& String::operator = (String&& other) noexcept {
    if (this != &other) {
        delete[] str;
        this->str = other.str;
        this->size = other.size;
        other.str = nullptr;
        other.size = 0;
    }
    return *this;
}

void String::Reserve (const std::size_t& newCap) {
    // cap will be 2 pwr always
    char* tempStr;
    if (newCap > 0) {
        this->capacity = 1;
        while (this->capacity+1 <= newCap) {
            this->capacity *= 2; 
        }
        if (this->str != nullptr) {
            tempStr = this->str;
            delete[] this->str;
        }
        this->str = new char[this->capacity+1];
        StrCpy(*this, tempStr);
    }
}