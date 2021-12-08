#ifndef FICHIERACCESLOG_H
#define FICHIERACCESLOG_H

#include "Fichier.h"
#include <iostream>

using namespace std;

class FichierAccesLog : public Fichier
{
    public:
        FichierAccesLog(string nom);
        ~FichierAccesLog();
        void ecrireJournal(string ID, string nom, char etat);

    protected:

    private:
        string lireDateHeure();
        //void ecrireLigne(string ligne);
};

#endif // FICHIERACCESLOG_H
