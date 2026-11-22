#include "String.hpp"
#include <iostream>
#include <utility>

int main () {
    String str2 = "Hello this is now a r val string";
    String str1 = std::move(str2);
    std::cout << str1[3] << std::endl;
    
    return 0;
}
