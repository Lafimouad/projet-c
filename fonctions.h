#include <gtk/gtk.h>

void afficher();

int verifier (char login [], char password[]);

void ajouter(char nom[],char prenom[], char username[],char password[],char CIN[],char adresse[],char date[]);

// achref

typedef struct
{

char type_offre[20]; 
char localite_offre[20]; 
char date_expiration[30];
char prix[30];
char quantite[10];
char identifiant_offre[10];

}Offre;

void ajouter_o(Offre o);
void afficher_o(GtkWidget *liste);
void modifier_o (Offre o1);
void supprimer_o (char identifiant[]);
int verifier_os (char id_o[]);
int verifier_o (Offre o1);



// fin achref
//wassim
typedef struct
{
   char identifiantdeoffre[20]; 
   char datereserver[20]; 
   char nbrepersonne[30];
}Client;
void ajouter_offre1(Client c);
void affiche_client(GtkWidget *lista);
int recherche(Offre tab[200],char ch[20]);
int rechercheplace(Offre tab[200],char ch[20]);
void decrementation(Offre tab[200],char ch[20],char ch1[20]);
int test(char ch[20],char ch1[20]);
int tableau_Client(Client u[200]);
int rechercheplace1(Client u[200],char ch[20],int n);
int recherche1(Client u[200],char ch[20]);
void modifind(Client u[200],char ch[20],char ch1[20],char ch2[20]);
void reecriver(Client u[200],int n);
void reecriver1(Offre tab[200],int n);
void supprime(Client u[200],char ch[20]);
void recremetation(Offre tab[200],Client u[200],Client c);
int facture(Offre tab[200],Client u[200],Client c);
int verificationide(Client u[200] ,Client c);

//mouadh

void ajouter(char nom[],char prenom[], char username[],char password[],char CIN[],char adresse[],char date[]);
void supprimer(char CIN[]);
void modifier(char nom[],char prenom[],char username[],char password[],char CIN[],char adresse[],char date[]);
void afficher_client(GtkWidget *liste);
void rechercher(char CIN []);
//fin mouadh

//aymen

void ajouter_reclamation(char type[],char rec[],int id_rec,char reponse[]);
void afficher_reclamation(GtkWidget *liste);
void ajouter_reponse(char id[], char reponsef[]);
void modifier_reclamtion(char id[], char recf[]);
void supprimer_reclamation(char id[]);
//int identifiant();

//fin aymen
