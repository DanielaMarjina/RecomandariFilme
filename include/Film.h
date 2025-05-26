#ifndef FILM_H
#define FILM_H
#include <iostream>
#include <cstring>

using namespace std;

class Film
{
protected:
    char* titlu;
    char* gen;
    char* regizor;
    int an;
    float rating;
    char* actori;
    static int nrFilme;

public:
    Film(const char* titlu="", const char* gen="", const char* regizor="", const char* actori="", int an=0, float rating=0.0);
    virtual ~Film();
    Film(const Film& other);
    virtual void afisare(void);
    const char* getGen() const
    {
        return gen;
    }
    const char* getTitlu() const
    {
        return titlu;
    }

    bool operator >(const Film& other) const;
    bool operator!=(const Film& other) const;
    bool operator<(const Film& other) const;
    bool operator ==(const Film& other) const;
    Film& operator =(const Film& other);

    friend ostream& operator<<(ostream& out, const Film& f);
    friend void afisareTitluSimplu(const Film& f);

    static int getNrFilme();

};

#endif // FILM_H
