#ifndef FILMACTIUNE_H
#define FILMACTIUNE_H
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

class FilmActiune : public Film
{
    public:
        FilmActiune(char* titlu="", char* regizor="", char* actori="", int an=0, float rating=0.0);
        ~FilmActiune();
        void afisare() override;
};

#endif // FILMACTIUNE_H
