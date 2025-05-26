#include "RecomandariFilme.h"
#include <iostream>
#include <cstring>
#include "Film.h"
#include "FilmComedie.h"
#include "FilmActiune.h"
#include "FilmDragoste.h"
#include "FilmDrama.h"
#include "FilmThriller.h"
#include <fstream>
#include <sstream>
using namespace std;

RecomandariFilme::RecomandariFilme(const string fisier)
{
    incarcaDinFisier(fisier);
}

RecomandariFilme::~RecomandariFilme()
{
    for (int i = 0; i < nrFilme; i++)
    {
        delete listaFilme[i];
    }
}

void RecomandariFilme::incarcaDinFisier(const string& numeFisier)
{
    ifstream fisier(numeFisier);
    if (!fisier)
    {
        cerr << "Eroare la deschiderea fisierului!\n";
        return;
    }

    string linie;
    while (getline(fisier, linie) && nrFilme < 15)
    {
        stringstream ss(linie);
        string titlu, gen, regizor, actori, anStr, ratingStr;
        getline(ss, titlu, ',');
        getline(ss, gen, ',');
        getline(ss, regizor, ',');
        getline(ss, actori, ',');
        getline(ss, anStr, ',');
        getline(ss, ratingStr, ',');

        int an = stoi(anStr);
        float rating = stof(ratingStr);

        listaFilme[nrFilme++] = new Film((char*)titlu.c_str(), (char*)gen.c_str(), (char*)regizor.c_str(), (char*)actori.c_str(), an, rating);

    }
     fisier.close();
}
