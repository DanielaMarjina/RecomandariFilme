#include "FilmDragoste.h"
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

FilmDragoste::FilmDragoste(char* titlu, char* regizor, char* actori, int an, float rating):
    Film(titlu,"Dragoste",regizor,actori,an,rating)
{
    //ctor
}

FilmDragoste::~FilmDragoste()
{
    //dtor
}

void FilmDragoste::afisare(void)
{
    cout<<"Dragoste: \n"<<endl;
    Film::afisare();
}
