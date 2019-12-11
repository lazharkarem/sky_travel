#include <stdio.h>
#include <string.h>
#include "personne.h"
#include <gtk/gtk.h>

num
{
	LOGIN,
	PASSWORD,
	ROLE,
	CIN,
	COLUMNS;
};


void ajouter_agent(agent A)
{
 FILE *f;
 f=fopen("utilisateur.txt","p+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s \n",A.cin,A.nom,A.prenom,A.date_naissance,A.adresse);
 fclose(f);
}
}
  
 

///////////////////////////////////////////////////////////

void afficher_agent(GtkWidget *pListView,int role)
{

enum {
LOGIN,
PASSWORD,
ROLE,
CIN,
TOGGLE_COLUMN,
N_COLUMN
};




GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_tree_view_get_model(pListView);

FILE *f;char var[50],var1[50],var3[50];int var2;
f=fopen("src/admin.txt","r");

void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           4,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      4, !boolean,
                      -1);
 
 
}




if (pListStore == NULL) {





pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("login",
pCellRenderer,
"text", LOGIN,
NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("password",
pCellRenderer,
"text", PASSWORD,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("role",
pCellRenderer,
"text", ROLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("cin",pCellRenderer,"text", CIN,NULL);

gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);
g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	




}

pListStore = gtk_list_store_new(N_COLUMN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT, G_TYPE_STRING,G_TYPE_BOOLEAN);


while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
	{

if (role!=var2)
continue;

GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,LOGIN,var,PASSWORD,var1,ROLE,var2,CIN,var3,TOGGLE_COLUMN,FALSE,-1);



	

}

fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);	
}

/////////////////////
