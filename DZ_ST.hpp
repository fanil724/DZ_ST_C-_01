#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>


#ifndef DZ_ST_H
#define DZ_ST_H

//Задание №2
class Contact {
public:
    Contact() {};

    Contact(const char *name, const char *home, const char *work, const char *mobile)
            : contact_information_{new char[1]{""}} {
        const size_t sizeName = strlen(name) + 1;
        Name_ = new char[sizeName];
        strcpy_s(Name_, sizeName, name);
        const size_t sizeHome = strlen(home) + 1;
        home_phone_ = new char[sizeHome];
        strcpy_s(home_phone_, sizeHome, home);
        const size_t sizeWork = strlen(work) + 1;
        work_phone_ = new char[sizeWork];
        strcpy_s(work_phone_, sizeWork, work);
        const size_t sizeMobile = strlen(mobile) + 1;
        mobile_phone_ = new char[sizeMobile];
        strcpy_s(mobile_phone_, sizeMobile, mobile);
    }

    Contact(const char *name, const char *home, const char *work, const char *mobile, const char *info) :
            Contact(name, home, work, mobile) {
        delete[] contact_information_;
        const size_t sizeInfo = strlen(info) + 1;
        contact_information_ = new char[sizeInfo];
        strcpy_s(contact_information_, sizeInfo, info);
    }

    Contact(const Contact &contact) :
            Contact(contact.Name_, contact.home_phone_,
                    contact.work_phone_, contact.mobile_phone_,
                    contact.contact_information_) {}

    Contact &operator=(const Contact &contact) noexcept {
        Contact phoneBook_copy(contact);
        this->sswap(phoneBook_copy);
        return *this;
    }

    Contact(Contact &&contact) noexcept
            : Name_(contact.Name_), home_phone_(contact.home_phone_),
              work_phone_(contact.work_phone_), mobile_phone_(contact.mobile_phone_),
              contact_information_(contact.contact_information_) {
        contact.Name_ = nullptr;
        contact.home_phone_ = nullptr;
        contact.work_phone_ = nullptr;
        contact.mobile_phone_ = nullptr;
        contact.contact_information_ = nullptr;
    }

    Contact& operator=(Contact&& contact) noexcept {
        if (this == &contact)
            return *this;
//        delete[] Name_;
//        delete[] home_phone_;
//        delete[] work_phone_;
//        delete[] mobile_phone_;
//        delete[] contact_information_;

        Name_ = contact.Name_;
        home_phone_ = contact.home_phone_;
        work_phone_ = contact.work_phone_;
        mobile_phone_ = contact.mobile_phone_;
        contact_information_ = contact.contact_information_;

        contact.Name_ = nullptr;
        contact.home_phone_ = nullptr;
        contact.work_phone_ = nullptr;
        contact.mobile_phone_ = nullptr;
        contact.contact_information_ = nullptr;

        return *this;
    }

//    ~Contact() {
//        delete[] Name_;
//        delete[] work_phone_;
//        delete[] home_phone_;
//        delete[] mobile_phone_;
//        delete[] contact_information_;
//    };

    void sswap(Contact &another) noexcept {
        using std::swap;

        swap(another.Name_, Name_);
        swap(another.home_phone_, home_phone_);
        swap(another.work_phone_, work_phone_);
        swap(another.mobile_phone_, mobile_phone_);
        swap(another.contact_information_, contact_information_);
    }

    void SetName(const char *name) {
        const size_t sizeName = strlen(name) + 1;
        Name_ = new char[sizeName];
        strcpy_s(Name_, sizeName, name);
    }

    void SetHome(const char *home) {
        const size_t sizeHome = strlen(home) + 1;
        home_phone_ = new char[sizeHome];
        strcpy_s(home_phone_, sizeHome, home);
    }

    void SetWork(const char *work) {
        const size_t sizeWork = strlen(work) + 1;
        work_phone_ = new char[sizeWork];
        strcpy_s(work_phone_, sizeWork, work);
    }

    void SetMobile(const char *mobile) {
        const size_t sizeMobile = strlen(mobile) + 1;
        mobile_phone_ = new char[sizeMobile];
        strcpy_s(mobile_phone_, sizeMobile, mobile);
    }

    void SetInfo(const char *info) {
        const size_t sizeInfo = strlen(info) + 1;
        contact_information_ = new char[sizeInfo];
        strcpy_s(contact_information_, sizeInfo, info);
    }




    void Show(const char *ch) {
        size_t size = strlen(ch);
        for (size_t i = 0; i < size; i++) {
            std::cout << ch[i];
        }
        std::cout << std::endl;
    }

    void PrintContact() {
        std::cout << "Name: ";
        Show(Name_);
        std::cout << "Home phone: ";
        Show(home_phone_);
        std::cout << "Work phone: ";
        Show(work_phone_);
        std::cout << "Mobile phone: ";
        Show(mobile_phone_);
        std::cout << "Info: ";
        Show(contact_information_);
        std::cout << std::endl;
    }

    void WriteFile() {
        std::ofstream out;
        out.open("PhoneBook.txt", std::ios::app);
        if (out.is_open()) {
            out << Name_ << " " << home_phone_ << " " << work_phone_ << " " << mobile_phone_ << " "
                << contact_information_ << " \0" << std::endl;
        }
        out.close();
    }

    Contact Read(std::string s) {
        Contact c;
        std::string str = s.substr().erase(s.find(' '));
        s = s.substr(s.find(' ') + 1);
        const size_t sizeName = str.length() + 1;
       // delete[] c.Name_;
        c.Name_ = new char[sizeName];
        strcpy(c.Name_, str.c_str());

        str = s.substr().erase(s.find(' '));
        s = s.substr(s.find(' ') + 1);
        //delete[] c.home_phone_;
        const size_t sizeHome = s.length();
        c.home_phone_ = new char[sizeHome];
        strcpy(c.home_phone_, str.c_str());

        str = s.substr().erase(s.find(' '));
        s = s.substr(s.find(' ') + 1);
        const size_t sizeWork = s.length();
        //delete[] c.work_phone_;
        c.work_phone_ = new char[sizeWork];
        strcpy(c.work_phone_, str.c_str());

        str = s.substr().erase(s.find(' '));
        s = s.substr(s.find(' ') + 1);
        const size_t sizeMobile = s.length();
        //delete[] c.mobile_phone_;
        c.mobile_phone_ = new char[sizeMobile];
        strcpy(c.mobile_phone_, str.c_str());
        if (s.empty()) {
            return c;
        }
        str = s.substr().erase(s.find(' '));
        s = s.substr(s.find(' ') + 1);
        const size_t sizeInfo = s.length();
        //delete[] c.contact_information_;
        c.contact_information_ = new char[sizeMobile];
        strcpy(c.contact_information_, str.c_str());
        return c;
    }


    [[nodiscard]] inline const char *GetName() {
        return Name_;
    }

    [[nodiscard]] inline const char *GetHomePhone() {
        return home_phone_;
    }

    [[nodiscard]] inline const char *GetWorkPhone() {
        return work_phone_;
    }

    [[nodiscard]] inline const char *GetMobilePhone() {
        return mobile_phone_;
    }

    [[nodiscard]] inline const char *GetInfo() {
        return contact_information_;
    }


private:
    char *Name_;
    char *home_phone_;
    char *work_phone_;
    char *mobile_phone_;
    char *contact_information_;

};


#endif // DZ_ST_H