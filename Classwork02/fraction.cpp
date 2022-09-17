#include <iostream>

class Fraction {
    public:
        Fraction(){}
        Fraction(int numerator): Fraction(numerator, 1) {}
        Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator){}
    
        void printFraction() {  // Выводит дробь в формате 'numerator / denominator'
            std::cout<<numerator<<" / "<<denominator;
            return;
        } 
    
        double calc() {  // Возвращает значение дроби в десятичном виде
            return double(numerator)/double(denominator);
        }

        int getNumerator() {  // Возвращает значение числителя
            return numerator;
        }

        int getDenominator() {  // Возвращает знамечение знаменателя
            return denominator;
        }

        void fracReverse() {  // Перевернуть дробь, знаменатель<->числитель
            int temp = numerator;
            numerator = denominator;
            denominator = temp;
        }

        void fracSimplify() {  // Сокращает дробь по возможности
            int GCD = NOD();
            numerator /= GCD;
            denominator /= GCD;
        }

        void multByNumber(int value) {  // Умножить дробь на число
            numerator = numerator * value;
        }
    
        void multByFrac(const Fraction& other) {
            numerator = numerator * other.numerator;
            denominator = denominator * other.denominator;
        }
    
        Fraction multByFracReturn(const Fraction& other) const {
            return Fraction(numerator * other.numerator, denominator * other.denominator);
        }
    
        void sumFrac(const Fraction& other) {
            numerator = denominator*other.numerator + numerator*other.denominator;
            denominator = denominator*other.denominator;
        }
    
        Fraction sumFracReturn(const Fraction& other) const {
            return Fraction(denominator*other.numerator + numerator*other.denominator, denominator*other.denominator);
        }
    
        void diffFrac(const Fraction& other) {
            numerator = -denominator*other.numerator + numerator*other.denominator;
            denominator = denominator*other.denominator;
        }
    
        Fraction diffFracReturn(const Fraction& other) const {
            return Fraction(-denominator*other.numerator + numerator*other.denominator, denominator*other.denominator);
        }
    
    private:
        int numerator;
        int denominator;
        int NOD(){
            int nod = 1;
            int top = numerator;
            int bot = denominator;
            for(int i=2; i<=numerator && i<=denominator; i++){
                if(top%i==0 && bot%i==0){
                    top/=i;
                    bot/=i;
                    nod*=i;
                    i--;
                }
            }
            return nod;
        }
};

int main(){
    Fraction a = Fraction(18, 24);
    a.fracSimplify();
    a.printFraction();
    return 0;
}