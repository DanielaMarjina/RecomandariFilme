#include "Film.h"
#include <iostream>
#include <cstring>
using namespace std;

int Film::nrFilme = 0;

Film::Film( const char* titlu, const char* gen,const char* regizor, const char* actori, int an, float rating)
{
    if (titlu == nullptr || strlen(titlu) == 0)
        throw invalid_argument("Titlul nu poate fi vid.");
    if (gen == nullptr || strlen(gen) == 0)
        throw invalid_argument("Genul nu poate fi vid.");
    if (regizor == nullptr || strlen(regizor) == 0)
        throw invalid_argument("Regizorul nu poate fi vid.");
    if (actori == nullptr || strlen(actori) == 0)
        throw invalid_argument("Actorii nu pot fi vid.");
    if (an < 1900 || an > 2025)
        throw std::invalid_argument("Anul este invalid.");
    if (rating < 0.0f || rating > 5.0f)
        throw std::invalid_argument("Rating-ul trebuie sa fie intre 0 si 5.");

    this->titlu=new char[strlen(titlu)+1];
    strcpy(this->titlu,titlu);
    this->gen=new char[strlen(gen)+1];
    strcpy(this->gen,gen);
    this->regizor=new char[strlen(regizor)+1];
    strcpy(this->regizor,regizor);
    this->actori=new char[strlen(actori)+1];
    strcpy(this->actori,actori);
    this->an=an;
    this->rating=rating;
    nrFilme++;
}

Film::~Film()
{
    delete []titlu;
    delete []gen;
    delete []regizor;
    delete []actori;
}

Film::Film(const Film& other)
{
    titlu = new char[strlen(other.titlu) + 1];
    strcpy(titlu, other.titlu);
    gen = new char[strlen(other.gen) + 1];
    strcpy(gen, other.gen);
    regizor = new char[strlen(other.regizor) + 1];
    strcpy(regizor, other.regizor);
    actori = new char[strlen(other.actori) + 1];
    strcpy(actori, other.actori);
    an = other.an;
    rating = other.rating;
    nrFilme++;
}

Film& Film::operator=(const Film& other)
{
    if (this != &other)
    {
        delete[] titlu;
        delete[] gen;
        delete[] regizor;
        delete[] actori;

        titlu = new char[strlen(other.titlu) + 1];
        strcpy(titlu, other.titlu);
        gen = new char[strlen(other.gen) + 1];
        strcpy(gen, other.gen);
        regizor = new char[strlen(other.regizor) + 1];
        strcpy(regizor, other.regizor);
        actori = new char[strlen(other.actori) + 1];
        strcpy(actori, other.actori);
        an = other.an;
        rating = other.rating;
    }
    return *this;
}

void Film::afisare(void)
{
    cout<<"Titlu: "<<titlu<<endl;
    cout<<"Gen: "<<gen<<endl;
    cout<<"Regizor: "<<regizor<<endl;
    cout<<"Anul: "<<an<<endl;
    cout<<"Actorii principali: "<<actori<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Ratingul Danielei: "<<rating<<" stele. \n\n"<<endl;
}

bool Film::operator>(const Film& other) const
{
    return this->rating > other.rating;
}

bool Film::operator==(const Film& other) const
{
    return strcmp(this->titlu, other.titlu) == 0;
}

bool Film::operator!=(const Film& other) const
{
    return !(*this == other);
}
bool Film::operator<(const Film& other) const
{
    return this->rating < other.rating;
}

ostream& operator<<(ostream& out, const Film& f)
{
    out << "Titlu: " << f.titlu << " | Gen: " << f.gen << " | Rating: " << f.rating;
    return out;
}

void afisareTitluSimplu(const Film& f)
{
    cout << f.titlu << endl;
}

int Film::getNrFilme()
{
    return nrFilme;
}
