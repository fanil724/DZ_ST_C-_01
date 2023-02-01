#include <iostream>
#include <cstring>
#include "DZ_ST.hpp"


#ifndef PHONEBOOK_H
#define PHONEBOOK_H


template<typename T>
class PhoneBook {
public:
    PhoneBook() {};

    void Add(T elment) {
        T *arr = new T[size + 1];
        if (size == 0) {
            arr[size] = elment;
        } else {
            for (int i = 0; i < size; i++) {
                arr[i] = phonebook_[i];
            }
            arr[size] = elment;
        }
        size += 1;
        delete[] phonebook_;
        phonebook_ = arr;
    }

    T &operator[](size_t index) {
        return phonebook_[index];
    }

    size_t &GetSize() {
        return size;
    }

    void Remove(int index) {
        T *arr = new T[size - 1];
        for (int i = index; i < size - 1; i++) {
            phonebook_[i] = phonebook_[i + 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = phonebook_[i];
        }
        size -= 1;
        delete[] phonebook_;
        phonebook_ = arr;
    }

    void PrintPhoneBook() {
        for (int i = 0; i < size; i++) {
            phonebook_[i].PrintContact();
        }
    }


    void ReadFile() {
        std::string s;
        int i = 0;
        std::ifstream file("PhoneBook.txt");
        while (std::getline(file, s)) {
            Add(Contact().Read(s));
            i++;
        }
        file.close();

    }

    void WritePhonebook() {
        for (int i = 0; i < size; i++) {
            phonebook_[i].WriteFile();
        }
    }

    ~PhoneBook() {
        delete[] phonebook_;
    };

private:
    size_t size = 0;
    T *phonebook_ = new T[size];
};

#endif // PHONEBOOK_H