#include "FichierAccesLog.h"
#include <ctime>

using namespace std;

FichierAccesLog::FichierAccesLog(string nom) : Fichier(nom)
{
    cout << "Constructeur Fichier Acces LOG" << endl;
}

FichierAccesLog::~FichierAccesLog()
{
    //dtor
}

void FichierAccesLog::ecrireJournal(string ID, string nom, char etat) {
    ouvrir('a');
    string dateHeure=lireDateHeure();
    string ligne=dateHeure+';'+ID+';'+nom+';'+etat;
    ecrire1Ligne(ligne);
    fermer();
    cout << "Ecrire dans le journal : " << ligne << endl;
}

string FichierAccesLog::lireDateHeure() {
    time_t dateCourante;
    time(&dateCourante);

    char buffer []="00/00/0000 00:00:00";
    struct tm *detailDate=localtime(&dateCourante);
    //char *laDate="00/00/0000 00:00:00     ";
    sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d",detailDate->tm_mday,detailDate->tm_mon+1,detailDate->tm_year+1900,detailDate->tm_hour,detailDate->tm_min,detailDate->tm_sec);

    string dateHeure=string(buffer); //"24/11/2021 16:54:00";

    cout << "retourne dateHeure : " << dateHeure << endl;
    return dateHeure;
}

//void FichierAccesLog::ecrireLigne(string ligne) {
//    ecrire1Ligne(ligne);
//    cout << "Ecrire la ligne " << ligne << endl;
//*}
