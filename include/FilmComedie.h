#ifndef FILMCOMEDIE_H
#define FILMCOMEDIE_H
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

class FilmComedie : public Film
{
    public:
        FilmComedie(char* titlu="", char* regizor="", char* actori="", int an=0, float rating=0.0);
        ~FilmComedie();
        void afisare(void) override;
};

#endif // FILMCOMEDIE_H
