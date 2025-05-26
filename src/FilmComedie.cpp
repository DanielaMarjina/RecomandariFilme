#include "FilmComedie.h"
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

FilmComedie::FilmComedie(char* titlu, char* regizor, char* actori, int an, float rating):
    Film(titlu,"Comedie",regizor,actori,an,rating)
{
    //ctor
}

FilmComedie::~FilmComedie()
{
    //dtor
}

void FilmComedie::afisare(void)
{
    cout<<"Comedie:\n"<<endl;
    Film::afisare();
}
