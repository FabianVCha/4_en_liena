#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/events.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


using namespace std;


ALLEGRO_DISPLAY* ventana;
ALLEGRO_FONT* letra;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_EVENT evento;
ALLEGRO_FONT* titulo;



/////////////////////// Funciones //////////////////
void imprimirTablero(int[20][20], int, int, char, char);
int ingresarFila(int, int, char[20], char[20]);
void crearTablero(int& n, int& m);
bool columnaLlenaYUbicacion(int[20][20], int, int, int, char[20], char[20]);


int play();
int puntajes();
int Seleccion();
int juego_azul();
int ficha_roja();
int ficha_amarilla();
int opc = 0;

int main() {
	int opc = 0;
	int x=-1, y=-1;
	int fonx1 = 1, fony1 = 1, fonx2 = 1, fony2 = 1;
	////////////////VENTANA_EMERGENTE/////////////
	
	//inicializacion de funciones de arreglo
	
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();

	//define fuente y tamaño de la ventana 
	letra = al_load_font("Power Breakfast DEMO.otf", 70, 0);
	ventana = al_create_display(1380, 900);
	queue = al_create_event_queue();
	titulo = al_load_font("Power Breakfast DEMO.otf", 110, 50);





		
	//eventos iniciados

	
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());


	//permanencia de la ventana y las letras

	while (evento.keyboard.keycode != ALLEGRO_KEY_X && true){





		al_wait_for_event(queue, &evento);
				

		
			
	
				al_draw_filled_circle(760, 400, 1000, al_map_rgb(255, 255, 255));
	
				al_draw_filled_circle(-585, -486, 1200, al_map_rgb(230, 150, 0));
				al_draw_filled_circle(-585, -486, 1000, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(-585, -486, 950, al_map_rgb(230, 150, 0));



				al_draw_filled_circle(1512, 1400, 993, al_map_rgb(250, 0, 0));
				al_draw_filled_circle(1512, 1400, 793, al_map_rgb(0, 0, 0));
				al_draw_filled_circle(1512, 1400, 743, al_map_rgb(250, 0, 0));



		al_draw_text(titulo, al_map_rgb(255, 97, 71), 350, 90, NULL, " CUATRO EN LINEA ");
		

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN); 
		{

			x = evento.mouse.x;
			y = evento.mouse.y;

			
		}


		if (x >= 473 && y <= 408 && x <= 741 && y >= 323) {

			
			al_draw_filled_rectangle(473, 408, 741, 323, al_map_rgb(0, 0, 0));

			al_draw_text(letra, al_map_rgb(255, 97, 71), 545, 315, NULL, "JUGAR");

			al_draw_filled_circle(510, 355, 14, al_map_rgb(250, 0, 0));
			al_draw_filled_circle(510, 355, 12, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(510, 355, 7, al_map_rgb(250, 0, 0));

			
				if (evento.mouse.button & 1) {

					play();

				}

		}
		else {
			al_draw_filled_rectangle(473, 408, 741, 323, al_map_rgb(0, 0, 0));
			al_draw_text(letra, al_map_rgb(250, 97, 71), 545, 315, NULL, "JUGAR");
		}





		if (x >= 473 && y >= 443 && x <= 741 && y <= 528) {

			al_draw_filled_rectangle(473, 443, 741, 528, al_map_rgb(0, 0, 0));
			al_draw_text(letra, al_map_rgb(255, 97, 71), 540, 440,  NULL, "PUNTOS");

			al_draw_filled_circle(510, 480, 14, al_map_rgb(250, 0, 0));
			al_draw_filled_circle(510, 480, 12, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(510, 480, 7, al_map_rgb(250, 0, 0));
		
				if (evento.mouse.button & 1) {
	
					al_draw_filled_rectangle(473, 443, 741, 528, al_map_rgb(0, 0, 0));
					al_draw_text(letra, al_map_rgb(255, 97, 71), 540, 440, NULL, "PUNTOS");
				}

		}
		else {
			al_draw_filled_rectangle(473, 443, 741, 528, al_map_rgb(0, 0, 0));
			al_draw_text(letra, al_map_rgb(255, 97, 71), 540, 440, NULL, "PUNTOS");
		}	




		
		if (x >= 473 && y >= 578 && x <= 741 && y <= 663 ) {

			al_draw_filled_rectangle(473, 578, 741, 663, al_map_rgb(0, 0, 0));

			al_draw_text(letra, al_map_rgb(255, 97, 71), 525, 575, NULL, " SALIR ");

			al_draw_filled_circle(510, 615, 14, al_map_rgb(250, 0, 0));
			al_draw_filled_circle(510, 615, 12, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(510, 615, 7, al_map_rgb(250, 0, 0));
		
			if (evento.mouse.button & 1) {

					return 1;
				}

		}
		else {

			al_draw_filled_rectangle(473, 578, 741, 663, al_map_rgb(0, 0, 0));
			al_draw_text(letra, al_map_rgb(255, 97, 71), 525, 575, NULL, " SALIR ");

		}
	




		al_flip_display();
	}



	return 0;

}


int play() {


	

	int x = -1, y = -1;

	while (evento.keyboard.keycode != ALLEGRO_KEY_X || true) {

		


		al_wait_for_event(queue, &evento);

		al_clear_to_color(al_map_rgb(255, 255, 255));



		al_draw_text(titulo, al_map_rgb(255, 97, 71), 450, 10, NULL, "REGLAS DE JUEGO");

		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 120, NULL, "-SE TIENE QUE ESCOGER EL ESPACIO DE JUEGO.");

		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 200, NULL, "-EL ESPACIO DE JUEGO NO TIENE QUE SER MENOR A 3 LINEAS.");

		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 280, NULL, "-EL JUEGO REQUIERE DE 2 JUGADORES");

		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 360, NULL, "-SI LAS FICHAS DE ALGUN JUGADOR FORMAN UNA LINEA DE 4");
		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 420, NULL, " ESE JUGADOR SE LLEVA LA VIVTORIA.");
		
		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 500, NULL, "-SI NINGUN JUGADOR TIENE UNA LINEA DE 4 FICHAS ES UN");
		al_draw_text(letra, al_map_rgb(255, 97, 71), 50, 560, NULL, " EMPATE.");


		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN);
		{

			x = evento.mouse.x;
			y = evento.mouse.y;


		}



		if (x <= 850 && y <= 750 && x >= 360 && y >= 650) {
			al_draw_filled_rectangle(850, 750, 360, 650, al_map_rgb(0, 0, 0));

			al_draw_filled_circle(450, 690, 14, al_map_rgb(250, 0, 0));
			al_draw_filled_circle(450, 690, 12, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(450, 690, 7, al_map_rgb(250, 0, 0));

			al_draw_text(letra, al_map_rgb(255, 97, 71), 500, 650, NULL, "SIGUIENTE");

			if (evento.mouse.button & 1) {

				Seleccion();

			}
		}
		else {

			al_draw_filled_rectangle(850, 750, 360, 650, al_map_rgb(0, 0, 0));
			al_draw_text(letra, al_map_rgb(255, 97, 71), 500, 650, NULL, "SIGUIENTE");

		}

		al_flip_display();

	}

	return 1;
}


int Seleccion() {

	int x = -1, y = -1;

	while (true || evento.keyboard.keycode != ALLEGRO_KEY_X) {
		
		al_wait_for_event(queue, &evento);
		al_register_event_source(queue, al_get_mouse_event_source());



		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_filled_circle(760, 400, 1000, al_map_rgb(255, 255, 255));

		al_draw_text(titulo, al_map_rgb(255, 97, 71), 240, 40, NULL, "SELECCIONE SU FICHA JUGADOR 1");

		
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

			x = evento.mouse.x;
			y = evento.mouse.y;


		}

		al_draw_text(letra, al_map_rgb(255, 97, 71), 400, 520, NULL, "AZUL");

		al_draw_text(letra, al_map_rgb(255, 97, 71), 900, 520, NULL, "ROJO");

		if (sqrt(pow(x - 440, 2) + pow(y - 390, 2)) <= 150){

			al_draw_filled_circle(440, 390, 150, al_map_rgb(65, 105, 225));
			al_draw_filled_circle(440, 390, 120, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(440, 390, 100, al_map_rgb(65, 105, 225));

			if (evento.mouse.button & 1) {

				juego_azul();
				

			}


		}
		else {
			al_draw_filled_circle(440, 390, 150, al_map_rgb(65, 105, 225));
			al_draw_filled_circle(440, 390, 120, al_map_rgb(0, 0, 0));

		}



		if (sqrt(pow(x - 940, 2) + pow(y - 390, 2)) <= 150) {
			al_draw_filled_circle(940, 390, 150, al_map_rgb(255, 0, 0));
			al_draw_filled_circle(940, 390, 120, al_map_rgb(0, 0, 0));
			al_draw_filled_circle(940, 390, 100, al_map_rgb(255, 0, 0));

		}
		else {
			al_draw_filled_circle(940, 390, 150, al_map_rgb(255, 0, 0));
			al_draw_filled_circle(940, 390, 120, al_map_rgb(0, 0, 0));


		}

		
		

		al_flip_display();
	}
	return 1;
}

int juego_azul(){

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_circle(760, 400, 1000, al_map_rgb(255, 255, 255));

	while (true) {
		al_wait_for_event(queue, &evento);
		al_register_event_source(queue, al_get_mouse_event_source());

		al_draw_filled_rectangle(19, 235, 35, 800, al_map_rgb(196, 196, 196));


		al_flip_display();
	}

	
	return 1;
}