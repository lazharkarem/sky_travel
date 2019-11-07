#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_buttonHello_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char nom[50],hello[50];
GtkWidget *input;
GtkWidget *output;
input = lookup_widget(objet_graphique, "entryNom") ;
output = lookup_widget(objet_graphique, "labelHello") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
sayHello(nom,hello);
gtk_label_set_text(GTK_LABEL(output),hello);





}

