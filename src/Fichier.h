#ifndef FICHIER_H
#define FICHIER_H

#include <fstream>
#include <iostream>

using namespace std;

class Fichier
{
    public:
        Fichier(string nom);
        void ouvrir(char mode);
        string nom;
        void ecrire1Ligne(string chaine);
        string lire1ligne();
        void fermer();
        fstream fichier;

    protected:

    private:
};

#endif // FICHIER_H
