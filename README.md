Acest proiect C++ implementează o aplicație orientată pe obiect pentru gestionarea și recomandarea filmelor. Conține o ierarhie de clase pentru diverse genuri de filme, operatori suprascrişi, clase abstracte și template-uri. Utilizatorul poate vizualiza toate filmele, filtra după gen, vedea topuri și compara filme direct din consolă. 

Funcționalități: 
- Afișarea tuturor filmelor
- Recomandarea filmului lunii
- Top 3 filme după rating
- Căutare filme după gen
- Sortare filme după rating (pentru un gen dat)
- Comparare între două filme (titlu și rating)
- Afișarea numărului total de filme

Structura:
- Clasa Film: conține atribute comune (titlu, gen, regizor, actori, an, rating), are operatori suprascrişi, conține metoda virtuală afisare()
- Clase derivate pentru genuri de film: FilmActiune, FilmComedie, FilmDrama, FilmThriller, FilmDragoste, fiecare suprascrie metoda afisare()
- Interfața IRecomandabil: conține metoda pur virtuală recomanda() const
- Clasa FilmRecomandabil: moștenește Film și IRecomandabil, implementează recomanda() cu afișare titlu în majuscule
- Template InfoGenerica<T>: afișează generic informații despre un film sau mesaj personalizat
- Clasa RecomandariFilme: încarcă filmele din fișier, oferă acces la lista de filme prin metode

Tehnologii:
- Limbaj: C++
- Tehnici: moștenire, clase abstracte, template-uri, vectori de pointeri, operatori suprascrişi

