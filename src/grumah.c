// grumah.c
// by burlapjack 2021


#include <stdlib.h>
#include <ncurses.h>
#include <stdint.h>
#include <string.h>
#include "../include/graphics.h"
#include "../include/component.h"
#include "../include/entity.h"
#include "../include/entity_prefabs.h"
#include "../include/system.h"
#include <locale.h>

int main(){
	/* initialize ncurses */

	setlocale(LC_ALL, "");
	unsigned int startx, starty, win_width, win_height;
	initscr();
	WINDOW *win_main;
	cbreak();
	
	noecho();
	win_height = 24;
	win_width = 80;

	/* Window centering calculation */
	if(LINES < win_height) starty = 0; else starty = (LINES - win_height) / 2;  
	if(COLS <  win_width) startx = 0; else startx = (COLS - win_width) / 2; 

	/* ncurses main_window */
	win_main = newwin(win_height,win_width,starty,startx);
	box(win_main, 0, 0);	
	keypad(win_main,TRUE);
	nodelay(win_main, TRUE);
	curs_set(0);


	/* Entities */
	unsigned int next_entity_id = 1;

	/* Initialize Entity lists (arrays of component objects) */
	ComponentPosition* cp;
	ComponentDraw* cd;
	ComponentStats* cs;
	ComponentMenuOption* co;
	
	size_t size_init = 20;	
	size_t cp_size = size_init;
	size_t cd_size = size_init;
	size_t cs_size = size_init;
	size_t co_size = size_init;

	entity_list_init_all(20, &cp, &cd, &cs, &co);
	
	entity_prefab_create_title_menu(&next_entity_id, &co, &co_size, &cp, &cp_size);

	/* game loop */
	int ch;
	unsigned int game_loop_run = 1;		
	unsigned int game_state = 1;		

	while(game_loop_run == 1){
		ch = wgetch(win_main);
		system_menu(win_main, co, co_size, cp, cp_size, ch, &game_state);
		graphics_draw_titlescreen(win_main,9,2);
		wrefresh(win_main);
	}


	/* free all dynamically allocated memory */
	entity_list_free_all(cp, cd, cs, co);
	delwin(win_main);
	endwin();

	return EXIT_SUCCESS;
}
