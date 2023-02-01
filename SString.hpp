#include <iostream>
#include <cstring>

#ifndef SSTRING_H
#define SSTRING_H
//Задание №3

static size_t count_ = 0;
class SString {

public:
    SString() {
        string_ = new char[81];
        coutnSString_ = count_;
        count_++;
    }

    SString(size_t size) {
        string_ = new char[size + 1];
        coutnSString_ = count_;
        count_++;
    }

    SString(char *str) {
        const size_t size = strlen(str) + 1;
        string_ = new char[size];
        strcpy_s(string_, size, str);
        coutnSString_ = count_;
        count_++;
    }

    ~SString() {
        delete[] string_;
    }

    void SetSStrings() {
        char str[50];
        std::cout << "Enter a string:";
        gets(str);
        delete[] string_;
        size_t size = strlen(str) + 1;
        string_ = new char[size];
        strcpy_s(string_, size, str);
    }

    void ShowString() const {
        size_t size = strlen(string_);
        for (size_t i = 0; i < size; i++) {
            std::cout << string_[i];
        }
        std::cout << std::endl;
    }

    const size_t GetCount() const {
        return coutnSString_;
    }

    const size_t GetSize() const {
        return strlen(string_);
    }


private:
    size_t coutnSString_;
    char *string_;
};

#endif // SSTRING_H