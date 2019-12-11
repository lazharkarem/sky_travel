#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


void
on_button_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char log[50]; char password[50];char hello [50];FILE* f;



GtkWidget *input;
GtkWidget *login1;
GtkWidget *output;
GtkWidget  *listeview;
GtkWidget *login;
GtkWidget *window_menu;

login = lookup_widget(objet_graphique,"login");
login1 = lookup_widget(objet_graphique,"entry2");
input=lookup_widget(objet_graphique,"entry3");
output = lookup_widget(objet_graphique, "msg") ;

strcpy(log,gtk_entry_get_text(GTK_ENTRY(login1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input)));

int x=id_h(log,password,hello);

		if(x==1)
		{

gtk_label_set_text(GTK_LABEL(output),hello);
window_menu=create_menu();
		gtk_widget_show (window_menu);
		gtk_widget_hide(login);



listeview = lookup_widget(window_menu,"treeview1");
afficher_agent(listeview);


		}
else

gtk_label_set_text(GTK_LABEL(output),hello);



}
//////////////////////////////////










///////////

void
on_ajouter_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data){
char logs[50],passwords[50],CIN[50], role[50];int x; 
	GtkWidget *input3;
	GtkWidget *input4;	
	GtkWidget *input5;
	GtkWidget *output;
	GtkWidget *combobox1;
	GtkWidget *menu;
	GtkWidget *listeview;

input3=lookup_widget(objet_graphique,"entry10");
input4=lookup_widget(objet_graphique,"entry9");
input5=lookup_widget(objet_graphique,"entry8");
combobox1=lookup_widget(objet_graphique,"combobox2");
output=lookup_widget(objet_graphique,"LABEL");

menu=lookup_widget(objet_graphique, "menu");


strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(logs,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(passwords,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input5)));
printf("hhhhh");
if (strcmp(role,"admin")==0)
		{
printf("hhhhh");
 x=ajouter_h(logs,passwords,1,CIN); 
listeview = lookup_widget(menu,"treeview1");
 afficher_agent(listeview);
		}

else if (strcmp(role,"agent")==0)
		{
 x=ajouter_h(logs,passwords,2,CIN);
listeview = lookup_widget(menu,"treeview1");
 afficher_agent(listeview); 
		}

else if (strcmp(role,"client")==0)
		{
 x=ajouter_h(logs,passwords,3,CIN);
listeview = lookup_widget(menu,"treeview1"); 
 afficher_agent(listeview);
		}
if(x==5)
gtk_label_set_text(GTK_LABEL(output),"CIN Existe");
else if(x==20)
gtk_label_set_text(GTK_LABEL(output),"compte ajouté");
else if(x==3)
gtk_label_set_text(GTK_LABEL(output),"login existe");
else if(x==0)
gtk_label_set_text(GTK_LABEL(output),"format CIN erroné");
else if(x==4)
gtk_label_set_text(GTK_LABEL(output),"format CIN erroné");
else
gtk_label_set_text(GTK_LABEL(output),"ajout avec succes");
}







void
on_supprimer_clicked                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{ 
GtkWidget *input1;
GtkWidget *menu;
GtkWidget *listeview;

char cin[50];

menu = lookup_widget(objet_graphique,"menu");

input1 = lookup_widget(objet_graphique,"entry8");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_h(cin);
listeview = lookup_widget(menu,"treeview1");
afficher_agent(listeview); 
}


void
on_modifier_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)

{

GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *combobox1;

	GtkWidget *listeview;
	GtkWidget *menu;

	char login[50],password[50],cin[50],role[50];

	//menu = lookup_widget(objet_graphique,"menu");
menu=lookup_widget(objet_graphique, "menu");


input1 = lookup_widget(objet_graphique,"entry10");
input2=lookup_widget(objet_graphique,"entry9");
input3=lookup_widget(objet_graphique,"entry8");
//input4=lookup_widget(objet_graphique,"entry15");
combobox1=lookup_widget(objet_graphique,"combobox2");

strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));



if (strcmp(role,"admin")==0)
{
modifier_comptes(login,password,cin,1);
listeview = lookup_widget(menu,"treeview1");
afficher_agent(listeview);
}
else if(strcmp(role,"agent")==0)
{
modifier_comptes(login,password,cin,2);
listeview = lookup_widget(menu,"treeview1");
afficher_agent(listeview);
}
else if(strcmp(role,"client")==0)
{
modifier_comptes(login,password,cin,3);
listeview = lookup_widget(menu,"treeview1");
afficher_agent(listeview);
}


}


///////////










void
ad_activated                           (GtkTreeView     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

gint *role;
  	gchar *login;
	gchar *password;
	gchar *cin;
   
	GtkWidget *input1;
	GtkWidget *input2;	
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *menu;
	GtkWidget *listeview;
        
        GtkTreeIter iter;


listeview = lookup_widget(objet_graphique,"treeview1");

GtkTreeModel *model = gtk_tree_view_get_model (GTK_TREE_VIEW(lookup_widget(objet_graphique,"treeview1")));
 

   if (gtk_tree_model_get_iter(model, &iter, path)) {
      gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &login, 1, &password,2,&role,3,&cin, -1);

                                                       }
menu = lookup_widget(objet_graphique,"menu");

input1 = lookup_widget(menu,"entry10");
input2=lookup_widget(menu,"entry9");
input3=lookup_widget(menu,"entry8");
input4=lookup_widget(menu,"combobox2");

gtk_entry_set_text(GTK_ENTRY(input1),login);
gtk_entry_set_text(GTK_ENTRY(input2),password);
gtk_entry_set_text(GTK_ENTRY(input3),cin);

}




void
on_combobox2_changed                   (GtkWidget     *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *combobox1;
GtkWidget *menu;
GtkWidget *listeview;
char role[50];


combobox1=lookup_widget(objet_graphique, "combobox2");
menu=lookup_widget(objet_graphique, "menu");
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
listeview = lookup_widget(menu,"treeview1");

GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(listeview));
gtk_list_store_clear(model);
if (strcmp(role,"admin")==0)
{
//gtk_widget_destroy(listeview);

//listeview = gtk_tree_view_new();
//init_listeview(listeview);
afficher_agent1(listeview,1);
}
else if(strcmp(role,"agent")==0)
{
afficher_agent1(listeview,2);
}
else if(strcmp(role,"client")==0)
{
afficher_agent1(listeview,3);
}

}


void
quitter_clicked                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();

}


void
d__con_clicked                         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *login;
GtkWidget *window_menu;
window_menu=lookup_widget(objet_graphique,"menu");
login=create_login() ;
gtk_widget_hide(window_menu);
gtk_widget_show (login);

}

