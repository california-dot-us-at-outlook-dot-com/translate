#include "translate.h"

//struct addrinfo *res,hints;
char *appiddd="20180814000194109";
char *passwddd="D3RNNJBRSCVrN4qFMtPV";
char *saltdd="1435660288";
GtkWidget*window;
GtkWidget*Elabel,*button,*table,*Clabel,*input,*output;

void trans(){
 struct addrinfo *res,hints;
 memset(&hints,0,sizeof(hints));
 hints.ai_family=PF_UNSPEC;
 hints.ai_socktype=SOCK_STREAM;
 getaddrinfo(Domain,Port,&hints,&res);
 gdk_threads_enter();
 char *inp=gtk_entry_get_text((GtkObject*)input);
 gdk_threads_leave();
 //printf("%s\n",inp);
 if(strlen(inp)>0){
  char *outp=E2C(appiddd,inp,saltdd,passwddd,res);
  printf(">>> %s | %s\n",inp,outp);
  gdk_threads_enter();
  gtk_entry_set_text((GtkObject*)output,outp);
  gdk_threads_leave();
 }else{
    gtk_entry_set_text((GtkObject*)output,"");

 }
}

int main(int argc,char**argv){


 gtk_init(&argc,&argv);
 window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
 gtk_window_set_resizable((GtkObject*)window,FALSE);
 gtk_window_set_keep_above(GTK_WINDOW(window),TRUE);
 gtk_window_set_title(GTK_WINDOW(window),"Translate");
 gtk_container_set_border_width(GTK_CONTAINER(window),10);
 Elabel=gtk_label_new("English");
 Clabel=gtk_label_new("Chinese");
 input=gtk_entry_new_with_max_length(64);
 output=gtk_entry_new_with_max_length(64);
 button=gtk_button_new_with_label("Trans");
 table=gtk_table_new(8,16,TRUE);
 gtk_table_attach_defaults((GtkTable*)table,Elabel,0,14,0,5);
 gtk_table_attach_defaults((GtkTable*)table,Clabel,20,32,0,5);
 gtk_table_attach_defaults((GtkTable*)table,input,0,14,5,16);
 gtk_table_attach_defaults((GtkTable*)table,output,18,32,5,16);
 gtk_table_attach_defaults((GtkTable*)table,button,14,18,5,16);
 gtk_entry_set_text((GtkObject*)output,"请确保网络连接正常");

 gtk_signal_connect((GtkObject*)button,"clicked",G_CALLBACK(trans),NULL);

 gtk_container_add(GTK_CONTAINER(window),table);
 g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
 gtk_widget_show_all(window);

 gdk_threads_enter();
 gtk_main();
 gdk_threads_leave();

 return 0;
}