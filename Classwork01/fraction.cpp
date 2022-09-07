#include <iostream>

class Fraction {
    public:
        Fraction(int numerator, int denominator) {
            _numerator = numerator;
            _denominator = denominator;
        }
    
        void printFraction() {  // Выводит дробь в формате 'numerator / denominator'
            std::cout<<_numerator<<" / "<<_denominator;
            return;
        }
    
        double calc() {  // Возвращает значение дроби в десятичном виде
            return double(_numerator)/double(_denominator);
        }

        int getNumerator() {  // Возвращает значение числителя
            return _numerator;
        }

        int getDenominator() {  // Возвращает знамечение знаменателя
            return _denominator;
        }
    
    private:
        int _numerator;
        int _denominator;
};

int main(){
    Fraction a = Fraction(17, 25);
    a.printFraction();
    return 0;
}