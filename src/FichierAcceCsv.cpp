#include "FichierAcceCsv.h"

using namespace std;

FichierAcceCsv::FichierAcceCsv(string nom) : Fichier(nom)
{

    cout << "Constructeur Fichier acces CSV" << endl;
}

FichierAcceCsv::~FichierAcceCsv()
{
    //dtor
}

string FichierAcceCsv::lireInfos(string ID) {
    cout << "Lirer les infos de " << ID << endl;
    ouvrir('r');
    return chercher(ID);
}

string FichierAcceCsv::chercher(string ID) {
    cout << "Chercher les infos pour " << ID << endl;
    bool trouve=false;
    string infos="";
    string ligne="";
    while ((ligne=lire1ligne())!="_-_EOF_-_") {
        int pos=ligne.find(";"); //recherche premier ';'
        if (pos!=string::npos) { //si on l'a trouvé
            if (ID==ligne.substr(0,pos)) return ligne.substr(pos+1);
        }
    }
    return "inconnu;R";
    //return "titi;R";
    //return "inconnu;R";
}

