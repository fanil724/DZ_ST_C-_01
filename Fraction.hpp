#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

//задание №1
class Fraction {
public:
    Fraction() {
    }

    Fraction(int number1, int number2) : numerator_(number1), denominator_(number2) {
    }

    void SetNumeration(int number) {
        numerator_ = number;
    }

    void SetDenominator(int number) {
        denominator_ = number;
    }

    void reduction() {
        int number = 1;
        for (int i = 2; i < std::min(numerator_, denominator_); i++) {
            if (numerator_ % i == 0 && denominator_ % i == 0) {
                number = i;
            }
        }
        numerator_ /= number;
        denominator_ /= number;
    }

    void SummFraction(Fraction fractoin) {
        if (denominator_ == fractoin.denominator_) {
            numerator_ = (numerator_ + fractoin.numerator_);
        } else {
            numerator_ = (numerator_ * fractoin.denominator_ + denominator_ * fractoin.numerator_);
            denominator_ = (denominator_ * fractoin.denominator_);
        }
    }

    void DifferenceFraction(Fraction fractoin) {
        if (denominator_ == fractoin.denominator_) {
            numerator_ = (numerator_ - fractoin.numerator_);
        } else {
            numerator_ = (numerator_ * fractoin.denominator_ - denominator_ * fractoin.numerator_);
            denominator_ = (denominator_ * fractoin.denominator_);
        }
    }

    void Multiplication(Fraction fractoin) {
        numerator_ *= fractoin.numerator_;
        denominator_ *= fractoin.denominator_;
    }

    void Division(Fraction fractoin) {
        numerator_ *= fractoin.denominator_;
        denominator_ *= fractoin.numerator_;
    }

    void ShowFraction() {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }

private:
    int numerator_;
    int denominator_;
};
#endif // FRACTION_H
