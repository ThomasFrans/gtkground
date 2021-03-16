// Include gtk
#include <gtk/gtk.h>
#include <stdio.h>

gboolean on_close (GtkWidget *widget){
  gtk_widget_hide(widget);
  printf("Closed screen\n");
  return TRUE;
}

void on_button_press(GtkWidget *widget, GtkWidget *window) {
  printf("Opened screen\n");
  gtk_widget_show (window);
}

static void on_activate (GtkApplication *app) {
  // Create a new window
  GtkWidget *window = gtk_application_window_new (app);
  GtkWidget *window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  GtkWidget *button = gtk_button_new_with_label("hello");
  GtkWidget *image = gtk_image_new_from_file("./res/froot.png");
  
  
  gtk_window_set_title(GTK_WINDOW (window), (const gchar*)"Main Window");
  gtk_window_set_title(GTK_WINDOW (window2), (const gchar*)"Non-Resizable Window");
  gtk_window_set_resizable(GTK_WINDOW (window2), FALSE);
  //gtk_window_set_transient_for (GTK_WINDOW (window2), GTK_WINDOW (window));
  //gtk_window_set_modal(GTK_WINDOW (window2), TRUE);
  gtk_window_set_icon_from_file (GTK_WINDOW (window), (const gchar*)"./res/froot.ico", NULL);
  g_signal_connect(button, "clicked", G_CALLBACK (on_button_press), window2);
  g_signal_connect(window2, "delete-event", G_CALLBACK (on_close), NULL);
  gtk_container_add( GTK_CONTAINER (window), button);
  gtk_container_add( GTK_CONTAINER (window2), image);
  gtk_widget_show(button);
  gtk_widget_show(image);
  gtk_window_present (GTK_WINDOW (window));
  //gtk_window_present (GTK_WINDOW (window2));
}

int main (int argc, char *argv[]) {
  // Create a new application
  GtkApplication *app = gtk_application_new ("com.example.GtkApplication",
                                             G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
  return g_application_run (G_APPLICATION (app), argc, argv);
}
