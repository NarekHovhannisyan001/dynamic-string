#include <cstring>
#include <iostream>

#include "My_string.h"

const int main_size = 16;


My_string::My_string() {
    st_string.m_length = 0;
    st_string.m_string[0] = '\0';
    dyn_string.m_size = 0;
    dyn_string.m_word = nullptr;

} 
My_string::My_string(const char* input) {
    int len = strlen(input);
    if(len <= main_size) {
        st_string.m_length = len;
        for (int i = 0;i < len;++i) {
            st_string.m_string[i] = input[i];
        }
        st_string.m_string[len] = '\0';
        dyn_string.m_size = 0;
        dyn_string.m_word = nullptr;
    }
    else {
        dyn_string.m_size = len;
        dyn_string.m_word  = new char[len + 1];
        for (int i = 0;i < len;++i) {
            dyn_string.m_word[i] = input[i];
        }
        dyn_string.m_word[len] = '\0'; 
        st_string.m_length = 0;
        st_string.m_string[0] = '\0';
    }
}

My_string::My_string(const My_string& st) {
    if (st.dyn_string.m_size > main_size) {
        this->dyn_string.m_size = st.dyn_string.m_size;
        this->dyn_string.m_word = new char[dyn_string.m_size + 1];
        for (int i = 0;i < st.dyn_string.m_size;++i) {
           this->dyn_string.m_word[i] = st.dyn_string.m_word[i];
        }
        st_string.m_length = 0;
        st_string.m_string[0] = '\0';
    }
    else {
        this->st_string.m_length = st.st_string.m_length;
        for (int i = 0;i < st.st_string.m_length;++i) {
           this->st_string.m_string[i] = st.st_string.m_string[i];
        }
        this->dyn_string.m_size = 0;
        this->dyn_string.m_word = nullptr;
    }
    
}

My_string::My_string(const std::string& str) {
    if (str.size() > main_size) {
        dyn_string.m_size = str.size();
        dyn_string.m_word = new char[dyn_string.m_size + 1];
        for (int i = 0;i < str.size();++i) {
           dyn_string.m_word[i] = str[i];
        }
        st_string.m_length = 0;
        st_string.m_string[0] = '\0';

    }
    else {
        st_string.m_length = str.size();
       for (int i = 0;i < str.size();++i) {
           st_string.m_string[i] = str[i];
        }
        dyn_string.m_size = 0;
        dyn_string.m_word = nullptr;
    }
}


My_string& My_string::operator=(const My_string& st) {
    if (this == &st) {
        std::cerr << "THis the same object:" << std::endl;
        return *this;
    }
    if (st.dyn_string.m_size > main_size) {
        delete[] this->dyn_string.m_word;
        this->dyn_string.m_size = st.dyn_string.m_size;
        this->dyn_string.m_word = new char[dyn_string.m_size + 1];
        for (int i = 0;i < st.dyn_string.m_size;++i) {
           this->dyn_string.m_word[i] = st.dyn_string.m_word[i];
        }
        this->dyn_string.m_word[this->dyn_string.m_size] = '\0';
        st_string.m_length = 0;
        st_string.m_string[0] = '\0';
    }
    else {
        this->st_string.m_length = st.st_string.m_length;
        for (int i = 0;i < st.st_string.m_length;++i) {
           this->st_string.m_string[i] = st.st_string.m_string[i];
        }
        this->st_string.m_string[st_string.m_length] = '\0';
        this->dyn_string.m_size = 0;
        this->dyn_string.m_word = nullptr;
    }
    return *this;
}


My_string& My_string::operator=(const std::string& str) {
    My_string tmp(str);
    operator=(tmp);
    return *this;

}

My_string& My_string::operator=(const char* charr) {
    My_string tmp(charr);
    operator=(tmp);
    return *this;
}



std::ostream& operator<<(std::ostream& os, const My_string& st) {
    if (st.dyn_string.m_size > main_size) {
        int i = 0;
        while (st.dyn_string.m_word[i] != '\0')
        {
            os << st.dyn_string.m_word[i];
            ++i;
        }
        
    }
    else {
        int i = 0;
        while (st.st_string.m_string[i] != '\0')
        {
            os << st.st_string.m_string[i];
            ++i;
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, My_string& st) {
    std::string temp;
    std::getline(is, temp);
    st = My_string(temp.c_str());
    return is;
}



My_string& My_string::operator+=(const My_string& obj) {
    unsigned int len = size();
    unsigned int len_obj = obj.size();
    unsigned int tmp_size = len + len_obj;
    if (len + len_obj > main_size) {
        char* tmp = new char[tmp_size + 1];
        if (len > main_size) {
        for (int i = 0;i < len;++i) {
            tmp[i] = dyn_string.m_word[i];
        }
        }
        else {
            for (int i = 0;i < len;++i) {
                tmp[i] = st_string.m_string[i - len];
        }
        }
        if (obj.dyn_string.m_size > main_size) {
        for (int i = size();i < tmp_size;++i) {
            tmp[i] = dyn_string.m_word[i - len];
        }
        }
        else {
            for (int i = obj.dyn_string.m_size;i < tmp_size;++i) {
                tmp[i] = st_string.m_string[i - len];
        }
        }
        delete[]dyn_string.m_word;
        dyn_string.m_word = tmp;
        dyn_string.m_size = tmp_size;
        st_string.m_length = 0;
        st_string.m_string[0] = '\0';
        
    }
    else {
        for (int i = len;i < len + len_obj;++i) {
            st_string.m_string[i] = obj.st_string.m_string[i - len];
        }
        st_string.m_length = tmp_size;
        dyn_string.m_size = 0;
        dyn_string.m_word = nullptr;
    }
    return *this; 
}




My_string& My_string::operator+=(const std::string& str) {
    My_string tmp(str);
    *this += tmp;
    return *this;
}

My_string My_string::operator+(const My_string& other) {
    My_string tmp(*this);
    operator+=(other);
    std::swap(tmp, *this);
    return tmp;
}


const char* My_string::c_str() const {
    if (dyn_string.m_size > main_size) {
        return dyn_string.m_word;
    }
    return st_string.m_string;
}

My_string::~My_string() {
    if (dyn_string.m_size > main_size) {
        delete[]dyn_string.m_word;
    }
}


unsigned int My_string::size() const {
    if (dyn_string.m_size > main_size) {
        return dyn_string.m_size;
    }
    return st_string.m_length;
}


bool My_string::empty() const {
    if (dyn_string.m_size > 0 || st_string.m_length > 0) {
        return false;
    }
    return true;
}
    
void My_string::reset() {
    if (dyn_string.m_size > main_size) {
        delete[] dyn_string.m_word;
        dyn_string.m_word = new char('\0');
        dyn_string.m_size = 0;
        return;
    }
    st_string.m_length = 0;
    st_string.m_string[0] = '\0';
}

