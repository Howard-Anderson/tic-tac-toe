/*
 * Filename: main.c
 *
 * Author: Howard Anderson.
 *
 * Date: 14/12/2022.
 *
 * Description: Main file for the Board Game.
 *
 */

#include<stdio.h>

#include "box.h"


int main(int argc, char** argv) {
	printf("\n\n");
	printf("\t\t+-------------+\n");
	printf("\t\t| TIC TAC TOE |\n");
	printf("\t\t+-------------+\n");
	char status = 'D';
	char positions[9] = "012345678";
	for(int i = 1; i < 6; i++) {
		draw(3,3,'X',positions);
		printf("\n\nPositions: %s",positions);
		if(i > 2 && has_won('X',positions)) { status = 'X'; break; }
		draw(3,3,'O',positions);
		if(i > 2 && has_won('O',positions)) { status = 'O'; break; }
		printf("\n\nPositions: %s",positions);
		printf("\n\n");
	}
	switch(status) {
		case 'X': 
			printf("\n\n[ $ ] Player X has Won !!\n\n"); break;
		case 'O':
			printf("\n\n[ $ ] Player O has Won !!\n\n"); break;
		case 'D':
			printf("\n\n[ $ ] Drawn !!"); 
	}
	printf("\n\n");
	return 0;
}
