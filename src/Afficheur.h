#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <iostream>

using namespace std;

class Afficheur
{
    public:
        Afficheur();
        virtual ~Afficheur();
        void afficher(string texte);

    protected:

    private:
};

#endif // AFFICHEUR_H
