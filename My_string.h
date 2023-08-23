#ifndef STRING_H
#define STRING_H
class My_string {
public:
    My_string(const char* input);
    My_string(const My_string&);
    My_string& operator=(const My_string&);
    const char* print() const;
    ~My_string();


private:
    struct dynamic
    {
        unsigned int size;
        char* word;

    };

    union staticc
    {
        unsigned int length;
        char string[16];
    };


    dynamic dyn_string;
    staticc st_string;
};
#endif //STRING_H
