#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


void
on_button_login_clicked                 (GtkWidget       *objet_graphique1,
                                        gpointer         user_data)
{
int x;
	GtkWidget *a ,*b , *c, *login, *Interface_admin,*interface_client,*Interface_agent;
	char login1 [20], password[20];
	
	login=lookup_widget (objet_graphique1,"login");
	a=lookup_widget (objet_graphique1,"entryusername");
	b=lookup_widget (objet_graphique1,"entrypassword");
	c=lookup_widget (objet_graphique1,"labelvide");
	
	strcpy(login1,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(b)));
	x=verifier(login1,password);

	if (x==1) {
		Interface_admin=create_Interface_admin();
		gtk_widget_show (Interface_admin);
		gtk_widget_hide (login);}
	if (x==2) {
		Interface_agent=create_Interface_agent();
		gtk_widget_show (Interface_agent);
		gtk_widget_hide (login);}
	if (x==3) {
		interface_client=create_interface_client();
		gtk_widget_show (interface_client);
		gtk_widget_hide (login);}
	else
	{ gtk_label_set_text(GTK_LABEL(c),"authentification non validée");}


}


void
on_button_anuler_clicked        (GtkButton *button, gpointer user_data)
{
gtk_main_quit();

}




// achref

void on_ajouter_offre_clicked(GtkWidget *objet_graphique2 , gpointer user_data)
{


Offre o;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6;
GtkWidget *Interface_agent;
Interface_agent=lookup_widget(objet_graphique2 ,"Interface_agent");
input1=lookup_widget(objet_graphique2 ,"type_offre");
input2=lookup_widget(objet_graphique2 ,"localite_offre");
input3=lookup_widget(objet_graphique2 ,"date_expiration");
input4=lookup_widget(objet_graphique2 ,"prix");
input5=lookup_widget(objet_graphique2 ,"quantite");
input6=lookup_widget(objet_graphique2 ,"identifiant_offre");

strcpy(o.type_offre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.localite_offre,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.date_expiration,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.quantite,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(o.identifiant_offre,gtk_entry_get_text(GTK_ENTRY(input6)));
ajouter_o(o);
}


void on_afficher_offre_clicked (GtkWidget *objet_graphique3 , gpointer user_data)
{


GtkWidget *Interface_agent;
GtkWidget *Catalogue_interfaceClient;
GtkWidget *treeviewCatalogueA;


Interface_agent=lookup_widget(objet_graphique3,"Interface_agent");
gtk_widget_destroy(Interface_agent);
Catalogue_interfaceClient=lookup_widget(objet_graphique3,"Catalogue_interfaceClient");
Catalogue_interfaceClient=create_Catalogue_interfaceClient();
gtk_widget_show(Catalogue_interfaceClient);
treeviewCatalogueA=lookup_widget(Catalogue_interfaceClient,"treeviewCatalogueA");
afficher_o(treeviewCatalogueA);
}


void on_retour_inteface_agent_clicked(GtkWidget *objet_graphique4 , gpointer user_data)
{
GtkWidget *Interface_agent, *Catalogue_interfaceClient;
Catalogue_interfaceClient=lookup_widget(objet_graphique4 ,"Catalogue_interfaceClient");

gtk_widget_destroy(Catalogue_interfaceClient);
Interface_agent=create_Interface_agent();
gtk_widget_show(Interface_agent);
}
//wassim
void
on_routour_clicked                     (GtkWidget *objet_graphique5 , gpointer user_data)
{

GtkWidget *interface_client, *reserver_interfaceclient;
reserver_interfaceclient=lookup_widget(objet_graphique5 ,"reserver_interfaceclient");

gtk_widget_destroy(reserver_interfaceclient);
//interface_client=lookup_widget(objet_graphique5 ,"interface_client");
interface_client=create_interface_client();
gtk_widget_show(interface_client);



}


void
on_reserver_client_clicked             (GtkWidget *objet_graphique7 , gpointer user_data)
{char ch[20],h[20];
Offre tab[200];
Client c;
Client u[200];
int i,a,x;
	GtkWidget *input1, *input2,*input3,*output1,*win_affich,*output2;
GtkWidget *interface_client;
interface_client=lookup_widget(objet_graphique7 ,"interface_client");
GtkWidget *treeview;
input1=lookup_widget(objet_graphique7 ,"identifiantdeoffre");
input2=lookup_widget(objet_graphique7 ,"datereserver");
input3=lookup_widget(objet_graphique7 ,"nbrepersonne");

output1=lookup_widget(objet_graphique7 ,"labelidentifiant");

strcpy(c.identifiantdeoffre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.datereserver,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nbrepersonne,gtk_entry_get_text(GTK_ENTRY(input3)));



if((recherche(tab,c.identifiantdeoffre)==1)&&(verificationide(u,c)!=-1))
{ajouter_offre1(c);
i=rechercheplace(tab,c.identifiantdeoffre);
decrementation(tab,c.nbrepersonne,c.identifiantdeoffre);
x=facture(tab,u,c);
sprintf(h,"%d",x);

gtk_label_set_text(GTK_LABEL(output1), h );



}
else 
gtk_label_set_text(GTK_LABEL(output1),"identifiant invalide");




}


void
on_afficher_reservation_clicked        (GtkWidget *objet_graphique7 , gpointer user_data)
{GtkWidget *interface_client,*win_affich,*treeview;
interface_client=lookup_widget(objet_graphique7 ,"interface_client");
gtk_widget_destroy(interface_client);

win_affich=lookup_widget(objet_graphique7,"reserver_interfaceclient");
win_affich=create_reserver_interfaceclient();

gtk_widget_show(win_affich);

treeview=lookup_widget(win_affich,"treeviewclient");
affiche_client(treeview);


}





void
on_modifier_client1_clicked             (GtkWidget       *objet_graphique8,
                                        gpointer         user_data)
{char ch[20];
Offre tab[200];
Client c;
Client u[200];
int i;
	GtkWidget *input1, *input2,*input3,*output1,*treeview,*win_affich;
GtkWidget *interface_client;
interface_client=lookup_widget(objet_graphique8 ,"interface_client");

input1=lookup_widget(objet_graphique8 ,"identifiantdeoffre1");
input2=lookup_widget(objet_graphique8 ,"datereserver1");
input3=lookup_widget(objet_graphique8 ,"nbrepersonne1");

//output1=lookup_widget(objet_graphique8 ,"labelidentifiant1");

strcpy(c.identifiantdeoffre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.datereserver,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.nbrepersonne,gtk_entry_get_text(GTK_ENTRY(input3)));
printf("%s %s %s",c.identifiantdeoffre,c.datereserver,c.nbrepersonne);
if(recherche1(u,c.identifiantdeoffre)==1)
{
recremetation(tab,u,c);
decrementation(tab,c.nbrepersonne,c.identifiantdeoffre);
modifind(u,c.nbrepersonne,c.datereserver,c.identifiantdeoffre);


gtk_widget_destroy(interface_client);

win_affich=lookup_widget(objet_graphique8,"reserver_interfaceclient");
win_affich=create_reserver_interfaceclient();
gtk_widget_show(win_affich);
treeview=lookup_widget(win_affich,"treeviewclient");
affiche_client(treeview);
//gtk_label_set_text(GTK_LABEL(output1),"succée");
}
//else
//gtk_label_set_text(GTK_LABEL(output1),"invalide");
 
}




void
on_supprimie_client_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *input1,*output1,*treeview,*win_affich,*interface_client;
Client c;
Offre tab[200];
Client u[200];
input1=lookup_widget(button ,"identifiantdeoffre3");
output1=lookup_widget(button ,"labelidentifiant3");
strcpy(c.identifiantdeoffre,gtk_entry_get_text(GTK_ENTRY(input1)));
if(recherche1(u,c.identifiantdeoffre)==1)
{recremetation(tab,u,c);
supprime(u,c.identifiantdeoffre);

gtk_label_set_text(GTK_LABEL(output1),"succeé");

interface_client=lookup_widget(button,"interface_client");

gtk_widget_destroy(interface_client);

win_affich=lookup_widget(button,"reserver_interfaceclient");
win_affich=create_reserver_interfaceclient();
gtk_widget_show(win_affich);
treeview=lookup_widget(win_affich,"treeviewclient");
affiche_client(treeview);
}
else 
gtk_label_set_text(GTK_LABEL(output1),"verifier votre identifiant ??");


}
//fin wassim
// achref
void
on_modifier_offre_clicked (GtkButton *objet_graphique4,gpointer         user_data)
{
Offre o;
GtkWidget *a1, *a2,*a3,*a4,*a5,*a6;
GtkWidget *Interface_agent;
GtkWidget *Catalogue_interfaceClient;
GtkWidget *treeviewCatalogueA;
Interface_agent=lookup_widget(objet_graphique4 ,"Interface_agent");
a1=lookup_widget(objet_graphique4 ,"type_offreM");
a2=lookup_widget(objet_graphique4 ,"localite_offreM");
a3=lookup_widget(objet_graphique4 ,"date_expirationM");
a4=lookup_widget(objet_graphique4 ,"prixM");
a5=lookup_widget(objet_graphique4 ,"quantiteM");
a6=lookup_widget(objet_graphique4 ,"identifiant_offreM");

strcpy(o.type_offre,gtk_entry_get_text(GTK_ENTRY(a1)));
strcpy(o.localite_offre,gtk_entry_get_text(GTK_ENTRY(a2)));
strcpy(o.date_expiration,gtk_entry_get_text(GTK_ENTRY(a3)));
strcpy(o.prix,gtk_entry_get_text(GTK_ENTRY(a4)));
strcpy(o.quantite,gtk_entry_get_text(GTK_ENTRY(a5)));
strcpy(o.identifiant_offre,gtk_entry_get_text(GTK_ENTRY(a6)));
modifier_o (o);

Interface_agent=lookup_widget(objet_graphique4,"Interface_agent");
gtk_widget_destroy(Interface_agent);
Catalogue_interfaceClient=lookup_widget(objet_graphique4,"Catalogue_interfaceClient");
Catalogue_interfaceClient=create_Catalogue_interfaceClient();
gtk_widget_show(Catalogue_interfaceClient);
treeviewCatalogueA=lookup_widget(Catalogue_interfaceClient,"treeviewCatalogueA");
afficher_o(treeviewCatalogueA);

	
}



void
on_supprimer_offre_clicked (GtkButton  *objet_graphique5, gpointer  user_data)
{
	char identifiant[40];
GtkWidget *a;
GtkWidget *Interface_agent;
GtkWidget *Catalogue_interfaceClient;
GtkWidget *treeviewCatalogueA;
Interface_agent=lookup_widget(objet_graphique5 ,"Interface_agent");

a=lookup_widget(objet_graphique5 ,"identifiant_offreS");


strcpy(identifiant,gtk_entry_get_text(GTK_ENTRY(a)));
supprimer_o (identifiant);

Interface_agent=lookup_widget(objet_graphique5,"Interface_agent");
gtk_widget_destroy(Interface_agent);
Catalogue_interfaceClient=lookup_widget(objet_graphique5,"Catalogue_interfaceClient");
Catalogue_interfaceClient=create_Catalogue_interfaceClient();
gtk_widget_show(Catalogue_interfaceClient);
treeviewCatalogueA=lookup_widget(Catalogue_interfaceClient,"treeviewCatalogueA");
afficher_o(treeviewCatalogueA);

}
//mouadh

void
on_buttonInscription_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *a ,*b,*c,*d,*e,*f,*g ,*Interface_acceuil, *login;
	char nom[20],prenom[20],username [20],password[20],CIN[20],adresse[20],date[20];
	
	a=lookup_widget(objet_graphique,"mentrynom");
	b=lookup_widget(objet_graphique,"mentryprenom");
	c=lookup_widget(objet_graphique,"mentryusername");
	d=lookup_widget(objet_graphique,"mentrypassword");
	e=lookup_widget(objet_graphique,"mentryCIN");
	f=lookup_widget(objet_graphique,"mentryadresse");
	g=lookup_widget(objet_graphique,"mentrydate");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(b)));
        strcpy(username,gtk_entry_get_text(GTK_ENTRY(c)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(d)));
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(e)));
	strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(f)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(g)));
        ajouter(nom,prenom,username,password,CIN,adresse,date);

	login=create_login();
	Interface_acceuil=lookup_widget(objet_graphique,"Interface_acceuil");
	gtk_widget_hide(Interface_acceuil);
	gtk_widget_show (login);

}

void
on_mbuttonajouter_clicked              (GtkButton       *mobjet_graphique,
                                        gpointer         user_data)
{	GtkWidget *Interface_agent;
	GtkWidget *Interface_acceuil;
	Interface_agent=lookup_widget(mobjet_graphique ,"Interface_agent");

gtk_widget_hide(Interface_agent);
Interface_acceuil=create_Interface_acceuil();
gtk_widget_show(Interface_acceuil);

}


void
on_mbuttonDel_clicked                  (GtkWidget   *mobjet_graphique11 , gpointer user_data)
{	GtkWidget *a,*Interface_admin,*mafficher ;
	GtkWidget *mtreeview1;
	char	CIN[20];
	a=lookup_widget(mobjet_graphique11,"mentrycinDel");
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(a)));
	supprimer(CIN);
	Interface_admin=lookup_widget(mobjet_graphique11,"Interface_admin");
	gtk_widget_hide(Interface_admin);
	mafficher=lookup_widget(mobjet_graphique11,"mafficher");
	mafficher=create_mafficher();
	gtk_widget_show(mafficher);
	mtreeview1=lookup_widget(mafficher,"mtreeview1");
	afficher_client(mtreeview1);

}


void
on_mbuttonMod_clicked                  (GtkWidget       *mobjet_graphique10,
                                        gpointer         user_data)
{	GtkWidget *a ,*b,*c,*d,*e,*f,*g,*Interface_admin,*mafficher ;
	GtkWidget *mtreeview1;
	char nom[20],prenom[20],username [20],password[20],CIN[20],adresse[20],date[20];
	a=lookup_widget(mobjet_graphique10,"mentrynomMod");
	b=lookup_widget(mobjet_graphique10,"mentryprenomMod");
	c=lookup_widget(mobjet_graphique10,"mentryusernameMod");
	d=lookup_widget(mobjet_graphique10,"mentrypassMod");
	e=lookup_widget(mobjet_graphique10,"mentrycinMod");
	f=lookup_widget(mobjet_graphique10,"mentryadresseMod");
	g=lookup_widget(mobjet_graphique10,"mentrydateMod");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(b)));
        strcpy(username,gtk_entry_get_text(GTK_ENTRY(c)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(d)));
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(e)));
	strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(f)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(g)));
        modifier(nom,prenom,username,password,CIN,adresse,date);
	Interface_admin=lookup_widget(mobjet_graphique10,"Interface_admin");
	gtk_widget_hide(Interface_admin);
	mafficher=lookup_widget(mobjet_graphique10,"mafficher");
	mafficher=create_mafficher();
	gtk_widget_show(mafficher);
	mtreeview1=lookup_widget(mafficher,"mtreeview1");
	afficher_client(mtreeview1);

}


void
on_mbuttonafficher_clicked             (GtkWidget *mobjet_graphique3 , gpointer user_data)
{	GtkWidget *Interface_admin;
GtkWidget *mafficher;
GtkWidget *mtreeview1;

Interface_admin=lookup_widget(mobjet_graphique3,"Interface_admin");
gtk_widget_hide(Interface_admin);
mafficher=lookup_widget(mobjet_graphique3,"mafficher");
mafficher=create_mafficher();
gtk_widget_show(mafficher);
mtreeview1=lookup_widget(mafficher,"mtreeview1");
afficher_client(mtreeview1);

}


void
on_mbutton_retour_clicked              (GtkWidget *mobjet_graphique4 , gpointer user_data)
{
GtkWidget *Interface_admin, *mafficher;
mafficher=lookup_widget(mobjet_graphique4 ,"mafficher");

gtk_widget_destroy(mafficher);
Interface_admin=create_Interface_admin();
gtk_widget_show(Interface_admin);

}
//fin mouadh
  


//*/////////////////////////////////////////////////*//*/////
void
on_recherchenontraite_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_reservenontraite_clicked            (GtkWidget      *objet_graphique ,
                                        gpointer         user_data)
{
GtkWidget *jour,*Interface_agent,*Catalogue_interfaceClient,*treeviewCatalogueA; 
GtkWidget *mois; 
GtkWidget *annee; 
GtkWidget *nbre,*input1;
Client c;
char x[20],y[20],z[20],h[20];
int j,m,a,n; 
Offre tab[200];

jour=lookup_widget(objet_graphique,  "spinbuttondatejour"); 
mois=lookup_widget(objet_graphique , "spinbuttondatemois"); 
annee=lookup_widget(objet_graphique , "spinbuttondateannee"); 
nbre=lookup_widget(objet_graphique , "spinbuttonnbre"); 
input1=lookup_widget(objet_graphique ,"identifiantdeoffre4");

j=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
m=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
a=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
n=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nbre));

sprintf(x,"%d",j);
sprintf(y,"%d",m);
sprintf(z,"%d",a);
sprintf(h,"%d",n);
strcat(x,"/");
strcat(y,"/");
strcat(y,z);
strcat(x,y);
strcpy(c.identifiantdeoffre,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.datereserver,x);
printf("%s",x);
strcpy(c.nbrepersonne,h);

if(recherche(tab,c.identifiantdeoffre)==1)
{ajouter_offre1(c);
Interface_agent=lookup_widget(objet_graphique,"Interface_agent");
gtk_widget_destroy(Interface_agent);

Catalogue_interfaceClient=lookup_widget(objet_graphique,"Catalogue_interfaceClient");
Catalogue_interfaceClient=create_Catalogue_interfaceClient();
gtk_widget_show(Catalogue_interfaceClient);
treeviewCatalogueA=lookup_widget(Catalogue_interfaceClient,"treeviewCatalogueA");


affiche_client(treeviewCatalogueA);}

}

