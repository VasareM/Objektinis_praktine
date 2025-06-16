#ifndef egzaminine_klase_h
#define egzaminine_klase_h

#include <string>

class kompleksinis_skaicius
{
    private:
        double re, im; // realioji ir menamoji
    public:
        kompleksinis_skaicius(): re{0}, im{0} {};// default konstruktorius
        kompleksinis_skaicius(double r, double i) : re{r}, im{i} {} ; // parametrinis konstruktorius su 2 par

        //getter'iai
        inline double realioji() const {return re;}
        inline double menamoji() const {return im;}

        //setter'iai
        void setRe(double realioji) {re=realioji;}
        void setIm(double menamoji) {im=menamoji;}

        // papildomi metodai
        operator+,operator-, operator*, operator+=, operator-=, operator*=, operator++, operator-- 

        // perdengti operatoriai input output
        operator<<, operator>>
};


#endif