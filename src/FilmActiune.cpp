#include "FilmActiune.h"
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

FilmActiune::FilmActiune(char* titlu, char* regizor, char* actori, int an, float rating):
    Film(titlu,"Actiune",regizor,actori,an,rating)
{
    //ctor
}

FilmActiune::~FilmActiune()
{
    //dtor
}

void FilmActiune::afisare()
{
    cout<<"Actiune:\n"<<endl;
    Film::afisare();
}
