#ifndef RECOMANDARIFILME_H
#define RECOMANDARIFILME_H
#include <iostream>
#include <cstring>
#include "Film.h"
#include "FilmComedie.h"
#include "FilmActiune.h"
#include "FilmDragoste.h"
#include "FilmDrama.h"
#include "FilmThriller.h"
#include <fstream>
using namespace std;

class RecomandariFilme
{
    Film* listaFilme[15];
    int nrFilme=0;
public:
    RecomandariFilme(const string fisier="");
    ~RecomandariFilme();
    void incarcaDinFisier(const string& numeFisier);
    Film* getFilm(int index) const
    {
        return listaFilme[index];
    }

    Film** getListaFilme()
    {
        return listaFilme;
    }
};

#endif // RECOMANDARIFILME_H
