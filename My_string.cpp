#include<cstring>
#include<iostream>
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

My_string::My_string(const My_string& st) {
    if (st.dyn_string.size > main_size) {
        this->dyn_string.size = st.dyn_string.size;
        this->dyn_string.word = new char[dyn_string.size + 1];
        for (int i = 0;i < st.dyn_string.size;++i) {
           this->dyn_string.word[i] = st.dyn_string.word[i];
        }
        st_string.length = 0;
        st_string.string[0] = '\0';
    }
    else {
        this->st_string.length = st.st_string.length;
        for (int i = 0;i < st.st_string.length;++i) {
           this->st_string.string[i] = st.st_string.string[i];
        }
        this->dyn_string.size = 0;
        this->dyn_string.word = nullptr;
    }
    
}

My_string& My_string::operator=(const My_string& st) {
    if (this == &st) {
        std::cerr << "THis the same object:" << std::endl;
        return *this;
    }
    if (st.dyn_string.size > main_size) {
        delete[] this->dyn_string.word;

       this->dyn_string.size = st.dyn_string.size;
        this->dyn_string.word = new char[this->dyn_string.size + 1];
        for (int i = 0; i < st.dyn_string.size; ++i) {
            this->dyn_string.word[i] = st.dyn_string.word[i];
        }
        this->dyn_string.word[this->dyn_string.size] = '\0';
        this->st_string.length = 0;
        this->st_string.string[0] = '\0';
    }
    else {
        this->st_string.length = st.st_string.length;
        for (int i = 0;i < st.st_string.length;++i) {
            this->st_string.string[i] = st.st_string.string[i];
        }
        this->st_string.string[this->st_string.length] = '\0';
        this->dyn_string.size = 0;
        this->dyn_string.word = nullptr;
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
