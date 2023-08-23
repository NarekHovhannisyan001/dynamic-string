#include<iostream>
#include"My_string.h"


int main() {
    My_string st("Hello");
    My_string s("Hello my name is C++");
    std::cout << "The fist string is: "  << st.print() << std::endl;
    std::cout << "The second string is: " << s.print() << std::endl;
    return 0;
}