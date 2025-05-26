#ifndef FILMTHRILLER_H
#define FILMTHRILLER_H
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

class FilmThriller : public Film
{
    public:
        FilmThriller(char* titlu="", char* regizor="", char* actori=nullptr, int an=0, float rating=0.0);
        ~FilmThriller();
        void afisare(void) override;
};

#endif // FILMTHRILLER_H
