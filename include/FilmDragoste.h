#ifndef FILMDRAGOSTE_H
#define FILMDRAGOSTE_H
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

class FilmDragoste : public Film
{
    public:
        FilmDragoste(char* titlu="", char* regizor="", char* actori="", int an=0, float rating=0.0);
        ~FilmDragoste();
        void afisare(void) override;
};

#endif // FILMDRAGOSTE_H
