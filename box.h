/* 
 * Filename: box.h
 *
 * Author: Howard Anderson.
 *
 * Date: 14/12/2022.
 *
 * Description: Implements to draw boxes on demand.
 *
 */

#include<stdio.h>
#include<stdbool.h>

/* DESIGN:
 * =============
 * | x | x | x |
 * =============
 * | x | x | x |
 * =============
 */

bool has_won(char player,char* position) {
	if(position[0] == position[3] && position[6] == player) { return true; }
	if(position[1] == position[4] && position[7] == player) { return true; }
	if(position[2] == position[5] && position[8] == player) { return true; }
	if(position[0] == position[1] && position[2] == player) { return true; }
	if(position[3] == position[4] && position[5] == player) { return true; }
	if(position[6] == position[7] && position[8] == player) { return true; }
	if(position[0] == position[4] && position[8] == player) { return true; }
	if(position[2] == position[4] && position[6] == player) { return true; }
	return false;
}

void draw_grid(unsigned int num_box, unsigned int box_space, unsigned int place, char player, char* x) {
	//char x[16] = "0123456789ABCDEF";
	//static char x[16] = "                ";
	static unsigned int index = 0;
	x[place] = player; 
	printf("\n\t");
	for(int i = 0; i <= box_space; i++) { printf("="); }
	printf("\n\t");
	for(int i = 0; i <= box_space; i++) {
		if(i == 0 || i % 4 == 0) { printf("|"); }
		else if( i % 2 == 0) { 
			printf("%c",x[index++]); 
			if(index == 9) { index = 0; }
		}
		else { printf(" "); }
	} 

}	

void draw(unsigned int rows, unsigned int columns, char player, char* positions) {
	unsigned int position;
	printf("\nPlayer %c: Enter Position: ", player);
	scanf("%d",&position);
	if(positions[position] != 'X' && positions[position] != 'O') {
		unsigned int box_space = (columns * 5) - columns;
		for(int i = 0; i < rows; i++) { draw_grid(columns,box_space,position,player,positions); }
		printf("\n\t");
		for(int i = 0; i <= box_space; i++) { printf("="); }
	}
	else { printf("\n[ ! ] Player %c: Illegal Move !!",player); }
}



