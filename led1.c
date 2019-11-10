#include <gtk/gtk.h>
#include <stdio.h>
#include <wiringPi.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

typedef enum {OFF,ON} bool;

int led1_wPi=8;
int led2_wPi=8;
int led3_wPi=8;
bool led1=OFF;
bool led2=OFF;
bool led3=OFF;
char led1_string[17];
char led2_string[17];
char led3_string[17];
GdkPixbuf *pixbuf_off;
GdkPixbuf *pixbuf_on;

int wPinumber(int BCM, char *s)
{
	int wPi=-1;
	
	switch (BCM)
	{
		case 2:
			wPi=8;
			sprintf(s,"wPi: %d, PIN: 3",wPi);
			break;
		case 3:
			wPi=9;
			sprintf(s,"wPi: %d, PIN: 5",wPi);
			break;
		case 4:
			wPi=7;
			sprintf(s,"wPi: %d, PIN: 7",wPi);
			break;
		case 5:
			wPi=21;
			sprintf(s,"wPi: %d, PIN: 29",wPi);
			break;
		case 6:
			wPi=22;
			sprintf(s,"wPi: %d, PIN: 31",wPi);
			break;
		case 7:
			wPi=11;
			sprintf(s,"wPi: %d, PIN: 26",wPi);
			break;
		case 8:
			wPi=10;
			sprintf(s,"wPi: %d, PIN: 24",wPi);
			break;
		case 9:
			wPi=14;
			sprintf(s,"wPi: %d, PIN: 21",wPi);
			break;
		case 10:
			wPi=12;
			sprintf(s,"wPi: %d, PIN: 19",wPi);
			break;
		case 11:
			wPi=14;
			sprintf(s,"wPi: %d, PIN: 23",wPi);
			break;
		case 12:
			wPi=26;
			sprintf(s,"wPi: %d, PIN: 32",wPi);
			break;
		case 13:
			wPi=23;
			sprintf(s,"wPi: %d, PIN: 33",wPi);
			break;
		case 14:
			wPi=15;
			sprintf(s,"wPi: %d, PIN: 8",wPi);
			break;
		case 15:
			wPi=16;
			sprintf(s,"wPi: %d, PIN: 10",wPi);
			break;
		case 16:
			wPi=27;
			sprintf(s,"wPi: %d, PIN: 36",wPi);
			break;
		case 17:
			wPi=0;
			sprintf(s,"wPi: %d, PIN: 11",wPi);
			break;
		case 18:
			wPi=1;
			sprintf(s,"wPi: %d, PIN: 12",wPi);
			break;
		case 19:
			wPi=24;
			sprintf(s,"wPi: %d, PIN: 35",wPi);
			break;
		case 20:
			wPi=28;
			sprintf(s,"wPi: %d, PIN: 38",wPi);
			break;
		case 21:
			wPi=29;
			sprintf(s,"wPi: %d, PIN: 40",wPi);
			break;
		case 22:
			wPi=3;
			sprintf(s,"wPi: %d, PIN: 15",wPi);
			break;
		case 23:
			wPi=4;
			sprintf(s,"wPi: %d, PIN: 16",wPi);
			break;
		case 24:
			wPi=5;
			sprintf(s,"wPi: %d, PIN: 18",wPi);
			break;
		case 25:
			wPi=6;
			sprintf(s,"wPi: %d, PIN: 22",wPi);
			break;
		case 26:
			wPi=25;
			sprintf(s,"wPi: %d, PIN: 37",wPi);
			break;
		case 27:
			wPi=2;
			sprintf(s,"wPi: %d, PIN: 13",wPi);
			break;
		default:
			wPi=-1;
	}
	return wPi;
}

void end_program(GtkWidget *wid, gpointer ptr)
{
	digitalWrite(led1_wPi,LOW);
	pinMode(led1_wPi,INPUT);
	digitalWrite(led2_wPi,LOW);
	pinMode(led2_wPi, INPUT);
	digitalWrite(led3_wPi,LOW);
	pinMode(led3_wPi,INPUT);
	gtk_main_quit();
}

void toggle_led1(GtkWidget *wid, gpointer ptr)
{
	if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (wid)))
	{
		digitalWrite(led1_wPi,LOW);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_off);
		gtk_button_set_label(GTK_BUTTON (wid),"ON");
		led1=OFF;
	}
	else
	{
		digitalWrite(led1_wPi,HIGH);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_on);
		gtk_button_set_label(GTK_BUTTON (wid),"OFF");
		led1=ON;
	}
}

void toggle_led2(GtkWidget *wid, gpointer ptr)
{
	if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (wid)))
	{
		digitalWrite(led2_wPi,LOW);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_off);
		gtk_button_set_label(GTK_BUTTON (wid),"ON");
		led2=OFF;
	}
	else
	{
		digitalWrite(led2_wPi,HIGH);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_on);
		gtk_button_set_label(GTK_BUTTON (wid),"OFF");
		led2=ON;
	}
}

void toggle_led3(GtkWidget *wid, gpointer ptr)
{
	if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (wid)))
	{
		digitalWrite(led3_wPi,LOW);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_off);
		gtk_button_set_label(GTK_BUTTON (wid),"ON");
		led3=OFF;
	}
	else
	{
		digitalWrite(led3_wPi,HIGH);
		gtk_image_set_from_pixbuf(GTK_IMAGE (ptr),pixbuf_on);
		gtk_button_set_label(GTK_BUTTON (wid),"OFF");
		led3=ON;
	}
}

void spin1_changed(GtkWidget *wid, gpointer ptr)
{
	if(led1_wPi!=led2_wPi&&led1_wPi!=led3_wPi)
	{
		digitalWrite(led1_wPi,LOW);
		pinMode(led1_wPi,INPUT);
	}
	led1_wPi= wPinumber (gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(wid)),&led1_string[0]);
	pinMode(led1_wPi,OUTPUT);
	if(led1)
		digitalWrite(led1_wPi,HIGH);
	else
		digitalWrite(led1_wPi,LOW);
	gtk_label_set_text(GTK_LABEL(ptr), led1_string);
}

void spin2_changed(GtkWidget *wid, gpointer ptr)
{
	if(led2_wPi!=led1_wPi&&led2_wPi!=led3_wPi)
	{
		digitalWrite(led2_wPi,LOW);
		pinMode(led2_wPi,INPUT);
	}
	led2_wPi= wPinumber (gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(wid)),&led2_string[0]);
	pinMode(led2_wPi,OUTPUT);
	if(led2)
		digitalWrite(led2_wPi,HIGH);
	else
		digitalWrite(led2_wPi,LOW);
	gtk_label_set_text(GTK_LABEL(ptr), led2_string);
}

void spin3_changed(GtkWidget *wid, gpointer ptr)
{
	if(led3_wPi!=led1_wPi&&led3_wPi!=led2_wPi)
	{
		digitalWrite(led3_wPi,LOW);
		pinMode(led3_wPi,INPUT);
	}
	led3_wPi= wPinumber (gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(wid)),&led3_string[0]);
	pinMode(led3_wPi,OUTPUT);
	if(led3)
		digitalWrite(led3_wPi,HIGH);
	else
		digitalWrite(led3_wPi,LOW);
	gtk_label_set_text(GTK_LABEL(ptr), led3_string);
}
	
void main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	
	wiringPiSetup();
	pinMode(led1_wPi,OUTPUT);
	digitalWrite(led1_wPi,LOW);
	
	GtkBuilder *builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"led1.glade",NULL);
	GtkWidget *win=(GtkWidget *)gtk_builder_get_object(builder,"window1");
	GtkWidget *img1=(GtkWidget *)gtk_builder_get_object(builder,"image1");
	GtkWidget *img2=(GtkWidget *)gtk_builder_get_object(builder,"image2");
	GtkWidget *img3=(GtkWidget *)gtk_builder_get_object(builder,"image3");
	pixbuf_off=(GdkPixbuf *)gdk_pixbuf_new_from_file_at_size("light-off-icon.jpg",96,-1,NULL);
	pixbuf_on=(GdkPixbuf *)gdk_pixbuf_new_from_file_at_size("light-on-icon.jpg",96,-1,NULL);
	gtk_image_set_from_pixbuf(GTK_IMAGE (img1),pixbuf_off);
	gtk_image_set_from_pixbuf(GTK_IMAGE (img2),pixbuf_off);
	gtk_image_set_from_pixbuf(GTK_IMAGE (img3),pixbuf_off);
	g_signal_connect(win,"delete_event",G_CALLBACK(end_program),NULL);
	GtkWidget *btn1=(GtkWidget *)gtk_builder_get_object(builder,"togglebutton1");
	g_signal_connect(btn1,"toggled",G_CALLBACK(toggle_led1),img1);
	GtkWidget *btn2=(GtkWidget *)gtk_builder_get_object(builder,"togglebutton2");
	g_signal_connect(btn2,"toggled",G_CALLBACK(toggle_led2),img2);
	GtkWidget *btn3=(GtkWidget *)gtk_builder_get_object(builder,"togglebutton3");
	g_signal_connect(btn3,"toggled",G_CALLBACK(toggle_led3),img3);
	GtkWidget *lbl5=(GtkWidget *)gtk_builder_get_object(builder,"label5");
	GtkWidget *lbl6=(GtkWidget *)gtk_builder_get_object(builder,"label6");
	GtkWidget *lbl7=(GtkWidget *)gtk_builder_get_object(builder,"label7");
	GtkWidget *spin1=(GtkWidget *)gtk_builder_get_object(builder,"spinbutton1");
	GtkWidget *spin2=(GtkWidget *)gtk_builder_get_object(builder,"spinbutton2");
	GtkWidget *spin3=(GtkWidget *)gtk_builder_get_object(builder,"spinbutton3");
	g_signal_connect(spin1,"value-changed",G_CALLBACK(spin1_changed),lbl5);
	g_signal_connect(spin2,"value-changed",G_CALLBACK(spin2_changed),lbl6);
	g_signal_connect(spin3,"value-changed",G_CALLBACK(spin3_changed),lbl7);
	gtk_widget_show_all(win);
	gtk_main();	
}
