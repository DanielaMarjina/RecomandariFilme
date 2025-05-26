#include "FilmDrama.h"
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

FilmDrama::FilmDrama(char* titlu, char* regizor, char* actori, int an, float rating):
    Film(titlu,"Drama",regizor,actori,an,rating)
{
    //ctor
}

FilmDrama::~FilmDrama()
{
    //dtor
}

void FilmDrama::afisare(void)
{
    cout<<"Drama:\n"<<endl;
    Film::afisare();
}
