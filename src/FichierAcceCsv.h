#ifndef FICHIERACCECSV_H
#define FICHIERACCECSV_H

#include <iostream>

using namespace std;

class FichierAcceCsv
{
    public:
        FichierAcceCsv();
        ~FichierAcceCsv();
        string lireInfos(string ID);
    protected:

    private:
        string chercher(string ID);
};

#endif // FICHIERACCECSV_H
