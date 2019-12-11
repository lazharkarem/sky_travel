#include <gtk/gtk.h>


void
on_button_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_ajouter_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

           

void
ad_activated                           (GtkTreeView     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_combobox2_changed                   (GtkWidget     *objet_graphique,
                                        gpointer         user_data);

void
quitter_clicked                        (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
d__con_clicked                         (GtkWidget      *objet_graphique,
                                        gpointer         user_data);
