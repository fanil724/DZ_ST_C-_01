#include "DZ_ST.hpp"
#include "Phonebook.hpp"
#include "Fraction.hpp"
#include "SString.hpp"

int main() {
//задание №1
//    Fraction f(6, 4);
//    Fraction Frac(2, 6);
//    f.Multiplication(Frac);
//    f.SummFraction(Frac);
//    f.ShowFraction();
//    f.reduction();
//    f.ShowFraction();

//Задание №2
    PhoneBook<Contact> phBook;
//    phBook.Add(Contact("Dima", "99999", "8945999", "89561299", "kemper"));
//    phBook.Add(Contact("Dasha", "99999", "8945999", "89561299"));
//    phBook.Add(Contact("alik", "99999", "8945999", "89561299", "noob"));
//    phBook.Add(Contact("Sasha", "99999", "8945999", "89561299"));

//    phBook.PrintPhoneBook();
//    phBook.WritePhonebook();

    phBook.ReadFile();
    phBook.PrintPhoneBook();
    std::cout << std::endl;
    Contact c;
    c.Search(phBook,phBook.GetSize(),"Dima");

//Задание №3
//    SString s(45);
//    SString str("nwetev");
//    str.ShowString();
//    std::cout << s.GetCount()<<std::endl;
//    std::cout << str.GetCount()<<std::endl;
//    s.SetSStrings();
//    s.ShowString();
}
