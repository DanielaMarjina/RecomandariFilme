#ifndef FILMDRAMA_H
#define FILMDRAMA_H
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

class FilmDrama : public Film
{
    public:
        FilmDrama(char* titlu="", char* regizor="", char* actori="", int an=0, float rating=0.0);
        ~FilmDrama();
        void afisare(void) override;
};

#endif // FILMDRAMA_H
