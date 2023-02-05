#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include "DZ_ST.hpp"


class PhoneBook {
public:
    PhoneBook() : size(0),
                  phonebook_{new Contact[size]} {}


    PhoneBook(const PhoneBook &another)
            : PhoneBook(another.phonebook_, another.GetSize()) {}

    PhoneBook(PhoneBook &&another) noexcept
            : size(std::exchange(another.size, 0ull)),
              phonebook_(std::exchange(another.phonebook_, nullptr)) {}

    PhoneBook &operator=(PhoneBook &&another) noexcept {
        if (&another == this)
            return *this;
        delete[] phonebook_;
        size = std::exchange(another.size, 0ull);
        phonebook_ = std::exchange(another.phonebook_, nullptr);
        return *this;
    }

    ~PhoneBook() {
        delete[] phonebook_;
    };

    void Add(Contact elment) {
        Contact *arr = new Contact[size + 1];
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

    size_t Search(const char *names) {
        for (int i = 0; i < size; i++) {
            if (strcmp(names, phonebook_[i].GetName()) == 0) {
                return i;
            }
        }
        return -1;
    };

    Contact &operator[](size_t index) {
        return phonebook_[index];
    }

    const size_t &GetSize() const {
        return size;
    }
     size_t &GetSize()  {
        return size;
    }
    void Remove(int index) {
        Contact *arr = new Contact[size - 1];
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


private:
    PhoneBook(const Contact array[], const size_t size_)
            : size(size_), phonebook_(new Contact[size]) {
        for (size_t i = 0; i < size; i++)
            phonebook_[i] = array[i];
    }

    size_t size = 0;
    Contact *phonebook_ = new Contact[size];
};

#endif // PHONEBOOK_H
