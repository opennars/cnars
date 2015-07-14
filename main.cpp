#include <string>
#include <iostream>

using namespace std;

/** Generic Truth with parameterizable generic "frequency" type  */
template<class T> class Truth {
    float c;
    T f;

    public:

        Truth(T f, float c) {
            this->f = f;
            this->c = c;
        }

        T freq() {
            return f;
        }
};

/** Unit scalar frequency Truth value, 0..1.0 (float) */
class UTruth : public Truth<float> {
    public:
        UTruth(float f=0, float c=0) : Truth(f, c) {
        }
};

class Budget {

    float p, d, q;

    public:
        Budget(float priority=0, float durability=0, float quality=0) {
            set(priority, durability, quality);

            this->d = durability;
            this->q = quality;
        }

        void set(float pp, float dd, float qq) {
            setPri(pp);
            setDur(dd);
            setQua(qq);
        }

        void setPri(float pp) { this->p = pp; }
        void setDur(float dd) { this->d = dd; }
        void setQua(float qq) { this->q = qq; }

        float pri() {
            return p;
        }
        float dur() {
            return d;
        }
        float qua() {
            return q;
        }
};

class Term {
};

class Atom : public Term, public std::string {

    public:
        Atom(char* name) : string(name) {
        }

};

class Var : public Atom {
};

class Compound : public Term {
};


int main()
{

    Truth<float> t = Truth<float>(0.5f, 0.5f);
    cout << t.freq() << endl;

    UTruth u = UTruth(0.5f, 0.5f);

    Budget b = Budget();
    b.set(0.25f, 0.25f, 0.25f);

    cout << b.pri() << endl;

    Atom a = Atom("SELF");
    cout << a << endl;


    return 0;
}
