#ifndef FICHIERACCECSV_H
#define FICHIERACCECSV_H

#include "Fichier.h"
#include <iostream>

using namespace std;

class FichierAcceCsv : public Fichier
{
    public:
        FichierAcceCsv(string nom);
        ~FichierAcceCsv();
        string lireInfos(string ID);
    protected:

    private:
        string chercher(string ID);
};

#endif // FICHIERACCECSV_H
