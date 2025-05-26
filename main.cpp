#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include "Film.h"
#include "FilmComedie.h"
#include "FilmActiune.h"
#include "FilmDragoste.h"
#include "FilmDrama.h"
#include "FilmThriller.h"
#include "RecomandariFilme.h"

using namespace std;

template <typename T>
void afiseazaInfoFilm(T film)
{
    film.afisare();
}

template <typename T>
class InfoGenerica
{
    T data;
public:
    InfoGenerica(T data) : data(data) {}
    void afiseaza()
    {
        cout << "Info: " << data << endl;
    }
};

class IRecomandabil
{
public:
    virtual void recomanda() const = 0;
    virtual ~IRecomandabil() {}
};

class FilmRecomandabil : public Film, public IRecomandabil
{
public:
    FilmRecomandabil(char* titlu, char* gen, char* regizor, char* actori, int an, float rating)
        : Film(titlu, gen, regizor, actori, an, rating) {}

    void recomanda() const override
    {
        string titluStr = titlu;
        transform(titluStr.begin(), titluStr.end(), titluStr.begin(), ::toupper);
        cout << "Filmul preferat al lunii: " << titluStr << "\n";
    }
};

void sorteazaFilmeDupaGen(Film** filme, int n, const string& genCautat)
{
    Film* genFilme[100];
    int k = 0;

    for (int i = 0; i < n; ++i)
    {
        Film* f = filme[i];
        if (f != nullptr)
        {
            string genFilm = f->getGen();
            transform(genFilm.begin(), genFilm.end(), genFilm.begin(), ::tolower);
            if (genFilm == genCautat)
                genFilme[k++] = f;
        }
    }

    if (k == 0)
    {
        cout << "Nu exista filme de genul " << genCautat << ".\n";
        return;
    }

    for (int i = 0; i < k - 1; ++i)
        for (int j = i + 1; j < k; ++j)
            if (*genFilme[i] < *genFilme[j])
                swap(genFilme[i], genFilme[j]);

    cout << "Filmele din genul " << genCautat <<" sortate dupa rating:\n";
    for (int i = 0; i < k; ++i)
        genFilme[i]->afisare();
}

void top3Filme(Film** filme, int n)
{
    Film* top[3] = {nullptr, nullptr, nullptr};

    for (int i = 0; i < n; ++i)
    {
        Film* f = filme[i];
        if (f == nullptr) continue;

        for (int j = 0; j < 3; ++j)
        {
            if (top[j] == nullptr || *f > *top[j])
            {
                for (int k = 2; k > j; --k)
                    top[k] = top[k - 1];
                top[j] = f;
                break;
            }
        }
    }

    cout << "Top 3 filme cu cel mai mare rating:\n";
    for (int i = 0; i < 3 && top[i]; ++i)
    {
        cout << "Locul " << i + 1 << ":\n";
        top[i]->afisare();
    }
}


int main()
{
    RecomandariFilme recomandari("filme.txt");

    FilmRecomandabil f1((char*)"Inception", (char*)"Thriller", (char*)"Nolan", (char*)"Leonardo DiCaprio si Tom Hardy", 2010, 4.5);
    InfoGenerica<string> info("O experienta captivanta care te provoaca sa gandesti dincolo de realitate!");


    int optiune;
    string genCautat;

    do
    {
        cout << "\n=== RECOMANDARI FILME ===\n";
        cout << "1. Afiseaza toate filmele\n";
        cout << "2. Filmul preferat al lunii\n";
        cout << "3. Afiseaza top 3 filme\n";
        cout << "4. Cauta filme dupa gen\n";
        cout << "5. Sorteaza filme dintr-un gen dupa rating\n";
        cout << "6. Compara doua filme\n";
        cout << "7. Vezi numarul total de filme\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;
        cin.ignore();

        system("cls");

        switch (optiune)
        {
        case 1:
            for (int i = 0; i < 15; i++)
            {
                Film* f = recomandari.getFilm(i);
                if (f != nullptr)
                    f->afisare();
            }
            break;

        case 2:
            f1.recomanda();
            afiseazaInfoFilm(f1);
            info.afiseaza();
            break;

        case 3:
            top3Filme(recomandari.getListaFilme(), 15);
            break;

        case 4:
            cout << "Introdu genul (Actiune, Comedie, Drama, Thriller, Dragoste): ";
            cin>>genCautat;
            cout<<endl;
            for (char& c : genCautat)
                c = tolower(c);
            for (int i = 0; i < 15; i++)
            {
                Film* f = recomandari.getFilm(i);
                if (f != nullptr)
                {
                    string genFilm = f->getGen();
                    for (char& c : genFilm)
                        c = tolower(c);
                    if (genFilm == genCautat)
                    {
                        f->afisare();
                    }
                }
            }
            break;

        case 5:
        {
            cout << "Introdu genul pentru sortare (Actiune, Comedie, Drama, Thriller, Dragoste): ";
            cin >> genCautat;
            for (char& c : genCautat)
                c = tolower(c);
            sorteazaFilmeDupaGen(recomandari.getListaFilme(), 15, genCautat);
            break;
        }

        case 6:
        {
            string titlu1, titlu2;
            cout << "Introdu titlul primului film: ";
            getline(cin, titlu1);
            cout << "Introdu titlul celui de-al doilea film: ";
            getline(cin, titlu2);

            Film* film1 = nullptr;
            Film* film2 = nullptr;

            for (int i = 0; i < 15; ++i)
            {
                Film* f = recomandari.getFilm(i);
                if (f != nullptr)
                {
                    string titluFilm = f->getTitlu();

                    string t1 = titlu1, t2 = titlu2, tFilm = titluFilm;
                    transform(t1.begin(), t1.end(), t1.begin(), ::tolower);
                    transform(t2.begin(), t2.end(), t2.begin(), ::tolower);
                    transform(tFilm.begin(), tFilm.end(), tFilm.begin(), ::tolower);

                    if (tFilm == t1)
                        film1 = f;
                    if (tFilm == t2)
                        film2 = f;
                }
            }

            if (film1 && film2)
            {
                cout << *film1 << endl;
                cout << *film2 << endl;

                if (*film1 > *film2)
                    cout << film1->getTitlu() << " are rating mai mare decat " << film2->getTitlu() << ".\n";
                else if (*film2 > *film1)
                    cout << film2->getTitlu() << " are rating mai mare decat " << film1->getTitlu() << ".\n";
                else
                    cout << film2->getTitlu() << " are rating egal cu " << film1->getTitlu() << ".\n";

                if (*film1 == *film2)
                    cout << "Filmele au acelasi titlu.\n";
            }
            else
            {
                cout << "Unul sau ambele titluri nu au fost gasite in lista.\n";
            }
            break;
        }

        case 7:
            cout<<"Numarul total de filme: "<<Film::getNrFilme()<<". \n";
            break;

        case 0:
            cout << "Iesire\n";
            break;

        default:
            cout << "Optiune invalida\n";
        }
    }
    while (optiune != 0);

    return 0;
}
