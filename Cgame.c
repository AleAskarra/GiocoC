#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "BearLibTerminal.h"
#define W 25
#define H 75//devono essere invertiti

	//variabili globali
	int i,j;
	char map[H][W];
	char cmd;
	int tel; // Variabile per il teletrasporto
	int hero_i = 2, hero_j = 2;
	int corsa=1; // Corsa vale 1 quando il gioco sta andando, quando è finito vale 0 ;
	int star_i = 4, star_j = 4;


//Inizializzo la mappa con 1 punto
init_map(){

    for(i=0;i<H;i++){

	 	for(j=0;j<W;j++){
	 		map[i][j]='.';
		 }
	 }
}

void gen_star(){

	srand(time(NULL));
	star_i = rand()%74+2;
    star_j = rand()%25+1 ;

}



int main(int argc, char *argv[]) {

	int  hero_glyph = 0x40; // creo l'eroe
    int star_glyph = 0x2A;

    terminal_open();

    //Inizializzo la mappa con un punto
	init_map();


	while(corsa==1){
       // while((hero_i != star_i) && (hero_j != star_j)){

        terminal_clear();

        gen_star();
        terminal_put(star_i,star_j,star_glyph);
        terminal_put(hero_i, hero_j, hero_glyph); //passo le posizioni e poi la stampaù

        //terminal_print(2, 1, "\t\tMENU [font=italic]STRUMENTI:[/font]");
        if((hero_i == star_i) && (hero_j == star_j)){
            terminal_print(2, 1, "MORTO[font=italic]!, IN MODO ABBASTANZA TRISTE[/font]");
        }

        terminal_refresh();

         cmd = terminal_read();

		//movimento one position del personaggio
		if(cmd == TK_ESCAPE){
			corsa=0;
		}
		else  if((cmd == TK_S)&&(hero_j<W-1)){
			hero_j++;
		}
		else  if((cmd == TK_W) &&(hero_j>2)){
			hero_j--;
		}
		else  if((cmd == TK_D)&&(hero_i<H-1)){
			hero_i++;
		}
		else  if((cmd == TK_A)&&(hero_i>1)){
			hero_i--;
		}
       //}
	}


    terminal_close();

	return 0;
}
