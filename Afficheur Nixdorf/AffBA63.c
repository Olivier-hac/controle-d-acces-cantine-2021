#include "AffBA63.h"

AffBA63::AffBA63(const char *dev)
{
    fd_serie = myseropen(dev);
	error= (fd_serie==-1);
}

AffBA63::~AffBA63()
{
}

void AffBA63::reculeDuneCase() {
    trame[0]=0x08;
	send_data(trame, 1);
}

void AffBA63::ligneSuivante() {
    trame[0]=0x0a;
	send_data(trame, 1);
}

void AffBA63::debutLigne() {
    trame[0]=0x0d;
	send_data(trame, 1);
}

void AffBA63::effaceFinLigne() {
    trame[0]=0x1b;
	trame[1]='[';
	trame[2]='0';
	trame[3]='K';
	send_data(trame, 4);
}

void AffBA63::defPays(int codePays) {
    trame[0]=0x1b;
	trame[1]='R';
	trame[2]=codePays;
	send_data(trame, 3);
}

char *AffBA63::afficheIdentification() {
	trame[0]=0x1b;
	trame[1]='[';
	trame[2]='0';
	trame[3]='c';
	send_data(trame, 4);
	
	return (char *) trame;
}

void AffBA63::effaceEcran() {
    trame[0]=0x1b;
	trame[1]='[';
	trame[2]='2';
	trame[3]='J';
	send_data(trame, 4);
}

void AffBA63::placeCurseur(int ligne, int colonne) {
	int taille=6;
	trame[0]=0x1b;
	trame[1]='[';
	trame[2]='0'+ligne;
	trame[3]=';';
	trame[5]=trame[6]='H';
	if (colonne>99) colonne%=100;
	if (colonne>9) {
		trame[4]='0'+((int) (colonne/10));
		trame[5]='0'+(colonne%10);
		taille++;
	} else trame[4]='0'+colonne;
	send_data(trame, taille);
}

void AffBA63::ecritChaine(const char *chaine){
	//for (int i=0; i<taille; i++) if ((chaine[i]==0x0A) || (chaine[i]==0x0D)) chaine[i]='x';
	int taille=strlen(chaine);
    send_data((unsigned char *) chaine, taille);
}

void AffBA63::ecritChaine(const char *chaine, int taille){
	unsigned char buf[taille+1];
	for (int i=0;i<taille;i++) {
		if ((chaine[i] == 0x0A) || (chaine[i]==0x0D)) {
			buf[i]=0;
		}
		else buf[i]=(unsigned char)(chaine[i]);
	}
	buf[taille]=0;
	//taille=strlen(buf);
	//for (int i=0; i<taille; i++) if ((chaine[i]==0x0A) || (chaine[i]==0x0D)) chaine[i]='x';
	ecritChaine((const char *)buf);
}

/*------------------------------------------
 Fonction : send_data
-------------------------------------
 - gestion de l'envoi des caractères
-------------------------------------
 - Entrée : fd : descripteur du port de la source
 						*buf : pointeur sur le buffer d'envoi
 						*psize : pointeur sur le nombre de caractère à envoyer
 - Sortie : etat : retourne 0 si OK et -1 si il y a une  erreur
 						*buf et *psize sont modifiés dans la fonction et disponibles en dehors
---------------------------------------------*/
int AffBA63::send_data(unsigned char *buf, int psize)
{
	int rv, offset = 0;

	while (psize > 0)
	{
		rv = write(fd_serie, buf + offset, psize); //envoi de la donnée
		if ((rv == -1) && (errno == EAGAIN)) continue;

		else if (rv)
		{
			psize -= rv;
			offset += rv;
		}
	}
	
	return offset;
}

/*------------------------------------------
 Fonction : myseropen
-------------------------------------
 - ouverture du port série
-------------------------------------
 - Entr?e : *dev : chaine contenant l'identificateur du port à utiliser
 - Sortie : entier indiquant s'il y a eu erreur
---------------------------------------------*/
int AffBA63::myseropen(const char *dev)
{
	int fd_ser = -1, one = 1;
	struct termios newtio;
	
	fd_ser = open(dev, O_RDWR); //ouverture en I/O
	if (fd_ser == -1)
		return -1;

	if (tcgetattr(fd_ser, &newtio) == -1) //récupère les paramètres en cours
		return -1;

	cfmakeraw(&newtio); //paramètres par défaut de la liaison
	cfsetospeed(&newtio, B9600); //fixe la vitesse de sortie à 9600 bds
	cfsetispeed(&newtio, 0);	// idem pour l'entrée
	newtio.c_cflag |= (PARENB+PARODD); //parité paire
	
	if (tcsetattr(fd_ser, TCSANOW, &newtio) == -1) //fixe les paramètres
		return -1;
	
	if (ioctl(fd_ser, FIONBIO, &one) == -1)	// mode nonblocking
		return -1;
	
	tcflush(fd_ser, TCIOFLUSH); //vide les tampons d'E et S

	return fd_ser;

}

