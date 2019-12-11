#include <gtk/gtk.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int id_h(char log[],char password[], char hello[])
{
	FILE *f;
	
	char var[50];char var1[50];char var3[50];int var2;
	f=fopen("src/admin.txt","r");
	
	
		while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
		{
			if(!strcmp(log,var) && !strcmp(password,var1) )
			{
				strcpy(hello , "yes");
				strcat(hello," ");
				strcat(hello,log);
				
				fclose(f);
					
				return var2;
			}

			
		}

				strcpy(hello , "info invalid");
				fclose(f);
				return 0;
		
}


//////////////////////
void afficher_agent1(GtkWidget *pListView,int role)
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
pColumn = gtk_tree_view_column_new_with_attributes("LOGIN",
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
///////////////////////////////////////

void afficher_agent(GtkWidget *pListView)
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
pColumn = gtk_tree_view_column_new_with_attributes("LOGIN",
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


GtkTreeIter pIter;

gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,LOGIN,var,PASSWORD,var1,ROLE,var2,CIN,var3,TOGGLE_COLUMN,FALSE,-1);



	

}

fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 
g_object_unref(pListStore);	
}




////////////////////////////////////////
int ajouter_h(char log[50],char password[50],int role,char cin[50])
{
FILE *f;
char var[50],var1[50],var3[50];int var2;
f=fopen("src/admin.txt","a+");


while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
	{
if(strcmp(var,log)==0)
return 3;
 if(strlen(cin)!=8)
return 4;
if (strcmp(cin,var3)==0)
return 5;
if(strlen(log)==0)
return 6;
if(strlen(password)==0 )
return 7;
if(strlen(cin)==0 )
return 8;
		for(int i=0;i<strlen(cin);i++)
		{
if((cin[i] < '0') || (cin[i] > '9') )
			{
fclose(f);
return 0;	
			}
		}
	}
	
fprintf(f,"%s %s %d %s\n",log,password,role,cin);
fclose(f);	
return 1;
}
///////////////////////////

void modifier_comptes(char login[50],char password[50],char cin[50],int role)
{
FILE *f,*f1;
char var[50];char var1[50];int var2;char var3[50];
f=fopen("src/admin.txt","r");
f1=fopen("src/tampo.txt","a+");
while(fscanf(f,"%s %s %d %s",var,var1,&var2,var3)!=EOF)
	{
if (strcmp(var3,cin)==0)
		{
fprintf(f1,"%s %s %d %s \n",login,password,role,var3);

	
		}
else
fprintf(f1,"%s %s %d %s \n",var,var1,var2,var3);
	}
fclose(f1);
fclose(f);
rename("src/tampo.txt","src/admin.txt");	
}


/////////////////////////////////////

void supprimer_h(char cin[50])
{
  FILE *f;
  FILE *f1;

  char ch1[50], ch2[50],ch4[50];int ch3;

  f = fopen("src/admin.txt","r");
  f1 = fopen("src/tompo.txt","w+");
  
    while(fscanf(f,"%s %s %d %s",ch1,ch2,&ch3,ch4) != EOF)
    {
      if (strcmp(ch4,cin)!=0)
	{
         
 fprintf(f1,"%s %s %d %s \n",ch1,ch2,ch3,ch4);
  	}  
    }
  

  fclose(f);
  fclose(f1);
remove("src/admin.txt");
  rename("src/tompo.txt","src/admin.txt");
}

	

		




