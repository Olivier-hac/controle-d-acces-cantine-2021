#include "AffBA63.h"

int main() {
    AffBA63 *afficheur;
    afficheur=new AffBA63("/dev/ttyS1");
    char buffer[50]="Ceci est un essai !!!";

    while(true) {
        printf("Start !\n");
        afficheur->effaceEcran();
        afficheur->placeCurseur(1,1);
        afficheur->ecritChaine("test1");
        sleep(1);
        printf("1\n");
        afficheur->effaceEcran();
        afficheur->placeCurseur(1,1);
        afficheur->ecritChaine(buffer);
        sleep(1);
        printf("2\n");
        afficheur->effaceEcran();
        afficheur->placeCurseur(1,1);
        afficheur->ecritChaine(buffer,8);
        sleep(1);
        printf("3\n");
        afficheur->effaceEcran();
        afficheur->placeCurseur(1,1);
        afficheur->ecritChaine(buffer);
        sleep(1);
    }
}
