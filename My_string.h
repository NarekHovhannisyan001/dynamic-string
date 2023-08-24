#ifndef STRING_H
#define STRING_H
#include <iostream>

class My_string;
std::ostream& operator<<(std::ostream&,const My_string&);
std::istream& operator>>(std::istream&, My_string&);

class My_string {
public:
    My_string();
    My_string(const char* input);
    My_string(const My_string&);
    My_string(const std::string&);
    My_string& operator=(const My_string&);
    My_string& operator=(const std::string&);
    My_string& operator=(const char*);
    My_string& operator+=(const My_string&);
    My_string& operator+=(const std::string&);
    My_string& operator+=(const char );
    My_string operator+(const My_string&);

    const char* c_str() const;
    unsigned int size() const;
    bool empty() const;
    void reset();
    ~My_string();


private:
    friend std::ostream& operator<<(std::ostream&, const My_string&);
    friend std::istream& operator>>(std::istream&,  My_string&);
    struct dynamic
    {
        unsigned int m_size;
        char* m_word;

    };

    struct staticc
    {
        unsigned int m_length;
        char m_string[17];
    };


    dynamic dyn_string;
    staticc st_string;
};

//c#include "My_string.cpp"
#endif //STRING_H
