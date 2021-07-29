/* ui.c
 * by burlapjack 2021
 * user interface configurations
 */

#include <ncurses.h>
#include <stdarg.h>
#include "../include/component.h"
#include "../include/ui.h"

void ui_start_menu_draw(WINDOW *w, UiMenu *m, int input, int *game_loop_run){
	

	/* menu logic */
	switch(input){
		case KEY_DOWN:
			if (m->highlighted == 0) {
				m->highlighted = 1;
				//wrefresh(w);
			}
			break;

		case KEY_UP:
			if (m->highlighted == 1){
			   	m->highlighted = 0;
				//wrefresh(w);
			}
			break;	

		case KEY_ENTER:
			if (m->highlighted == 1){
				game_loop_run = 0;	
			}
			break;
	}

	/* Draw the menu */

	mvwprintw(w, m->y, m->x, "Grumah"); 

	if (m->highlighted == 0){
		wattron(w, A_REVERSE);
		mvwprintw(w, m->y+2, m->x, "Start New Game"); 
		wattroff(w, A_REVERSE);
		mvwprintw(w, m->y+3, m->x, "Exit");
	} 
	else {
		mvwprintw(w, m->y+2, m->x, "Start New Game"); 
		wattron(w, A_REVERSE);
		mvwprintw(w, m->y+3, m->x, "Exit");
		wattroff(w, A_REVERSE);
	}
	wrefresh(w);

}






