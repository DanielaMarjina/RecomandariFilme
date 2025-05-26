#include "FilmThriller.h"
#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

FilmThriller::FilmThriller(char* titlu, char* regizor, char* actori, int an, float rating):
    Film(titlu,"Thriller",regizor,actori,an,rating)
{
    //ctor
}

FilmThriller::~FilmThriller()
{
    //dtor
}

void FilmThriller::afisare(void)
{
    cout<<"Thriller:\n"<<endl;
    Film::afisare();
}
