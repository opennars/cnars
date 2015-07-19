#include <string>
#include <iostream>
#include <w32api/msxml.h>
#include <w32api/evntprov.h>

using namespace std;

/** Generic Truth with parameterizable generic "frequency" type  */
template<typename T>
struct Truth {
    float c;
    T freq;

    Truth(T f1, float c1) : c(c1), freq(f1) { }
};

/** Unit scalar frequency Truth value, 0..1.0 (float) */
struct UTruth : Truth<float> {
    UTruth(float f = 0, float c = 0) : Truth(f, c) { }
};

struct Budget {
    float pri;
    float dur;
    float qua;

    Budget(float priority, float durability, float quality) : pri(priority), dur(durability), qua(quality) { }
};

class Term {
};

struct Atom : public Term  {
    std::string name;
    Atom(const char *nm) : name(nm) { }

    //http://stackoverflow.com/questions/1964256/how-to-make-a-c-class-compatible-with-stringstream-objects

};

std::istream &operator>>(std::istream &str, Atom &outPoint) { return str >> outPoint.name; }
std::ostream &operator<<(std::ostream &str, const Atom &inPoint) { return str << inPoint.name; }

struct Var : public Atom {
    Var(const char *name) : Atom(name) { }
};

struct Compound : public Term {
};

int main() {
    Truth<float> t(0.5f, 0.5f);
    cout << t.freq << endl;
    UTruth u(0.5f, 0.5f);
    Budget b(u.freq, 0.25f, 0.25f);
    cout << u.c << endl << b.pri << endl;
    Atom a("SELF");
    cout << a << endl;
    return 0;
}