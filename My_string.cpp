#include<cstring>
#include"My_string.h"
const int main_size = 16;
My_string::My_string(const char* input) {
    int len = strlen(input);
    if(len <= main_size) {
        st_string.length = len;
        for (int i = 0;i < len;++i) {
            st_string.string[i] = input[i];
        }
        st_string.string[len] = '\0';
        dyn_string.size = 0;
        dyn_string.word = nullptr;
    }
    else {
        dyn_string.size = len;
        dyn_string.word  = new char[len + 1];
        for (int i = 0;i < len;++i) {
            dyn_string.word[i] = input[i];
        }
        dyn_string.word[len] = '\0'; 
        st_string.length = 0;
        st_string.string[0] = '\0';
    }
}

const char* My_string::print() const {
    if (dyn_string.size > main_size) {
        return dyn_string.word;
    }
    return st_string.string;
}

My_string::~My_string() {
    if (dyn_string.size > main_size) {
        delete[]dyn_string.word;
    }
}
