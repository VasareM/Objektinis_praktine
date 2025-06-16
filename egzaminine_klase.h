#ifndef egzaminine_klase_h
#define egzaminine_klase_h

using std::endl;

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
        //operator+,operator-, operator*, operator+=, operator-=, operator*=, operator++, operator-- 
        friend kompleksinis_skaicius operator+ (const kompleksinis_skaicius &a, const kompleksinis_skaicius &b) {
            return kompleksinis_skaicius {a.realioji() + b.realioji(), a.menamoji() + b.menamoji()};
        }
        // perdengti operatoriai input output
        //operator<<, operator>>
        friend std::ostream& operator<<(std::ostream& out, const kompleksinis_skaicius &a) {
            out << a.re << (a.im < 0 ? " - " : " + ") << std::abs(a.im) << "i" << endl;
            return out;
        }
        friend std::istream& operator>>(std::istream& in, kompleksinis_skaicius &a) {
            in >> a.re >> a.im;
            return in;
        }
};


#endif