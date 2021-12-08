#include "FichierAcceCsv.h"

using namespace std;

FichierAcceCsv::FichierAcceCsv()
{
    cout << "Constructeur Fichier acces CSV" << endl;
}

FichierAcceCsv::~FichierAcceCsv()
{
    //dtor
}

string FichierAcceCsv::lireInfos(string ID) {
    cout << "Lirer les infos de " << ID << endl;
    return chercher(ID);
}

string FichierAcceCsv::chercher(string ID) {
    cout << "Chercher les infos pour " << ID << endl;
    return "toto;A";
    //return "titi;R";
    //return "inconnu;R";
}

