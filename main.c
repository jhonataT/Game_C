// // gcc conio.o main.c main
// gcc -c func.c (to .o)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "conio.h"

int terminal[25][117], player_errors = 0, player_scoring = 0;

void borders();

void delay(double number_of_seconds) { 
    // Converting time into milli_seconds 
    double milli_seconds = 1000000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds); 
} 

void ponctuation(int res){
    if(res == 0) ++player_errors;
    else ++player_scoring;

    c_gotoxy(40, 28);
    printf("Scoring: %d", player_scoring);
    c_gotoxy(70, 28);
    printf("Errors: %d", player_errors);
    c_gotoxy(90, 28);
    printf("Answer: ");
    c_gotoxy(99, 28);
    if(player_errors >= 10) exit(0);
    else return;
}

void initing(int number, int x_number, int y_number){
    
    c_textbackground(0);
    c_gotoxy(40, 28);
    printf("Scoring: %d", player_scoring);
    c_gotoxy(70, 28);
    printf("Errors: %d", player_errors);
    c_gotoxy(90, 28);
    printf("Answer: ");
    c_gotoxy(99, 28);
    
    for(int i = 0; i < 24; i++){
        for(int j = 0; j < 117; j++){
            terminal[i][j] = 0;
        }
    }

    srand(time(NULL));

    while(1){
        c_gotoxy(99, 28);
        
        delay(1.5);

        number = rand() % 10;
        x_number = (rand() % 116) + 2;
        y_number = (rand() % 24) + 2;

        if(terminal[y_number][x_number] == 0){
            terminal[y_number][x_number] = 1;
            c_textcolor(rand() % 16);
            c_gotoxy(x_number, y_number);
            printf("%d", number);
            c_gotoxy(99, 28);
            delay(1.5);
            if(c_kbhit()){
                int player = c_getch();
                if(player == '0' && number == 0) ponctuation(1);
                else if(player == '1' && number == 1) ponctuation(1);
                else if(player == '2' && number == 2) ponctuation(1);
                else if(player == '3' && number == 3) ponctuation(1);
                else if(player == '4' && number == 4) ponctuation(1);
                else if(player == '5' && number == 5) ponctuation(1);
                else if(player == '6' && number == 6) ponctuation(1);
                else if(player == '7' && number == 7) ponctuation(1);
                else if(player == '8' && number == 8) ponctuation(1);
                else if(player == '9' && number == 9) ponctuation(1);
                else ponctuation(0);
            } else ponctuation(0);

            
        }  

    }
}

void borders(int x_border, int y_border, int index){
    c_textbackground(15);
    if(index == 290) return;
    else {
        if(x_border <= 118 && y_border == 0) {
            x_border++;
            c_gotoxy(x_border, y_border);
            printf(" ");
            borders(x_border, y_border, index + 1);
        }
        else if(x_border == 119 && y_border <= 25) {
            y_border++;
            c_gotoxy(x_border, y_border);
            printf(" ");
            borders(x_border, y_border, index + 1);
        }
        else if(x_border > 0 && y_border == 26) {
            x_border--;
            c_gotoxy(x_border, y_border);
            printf(" ");
            borders(x_border, y_border, index + 1);
        }
        else if(x_border == 0 && y_border > 0) {
            y_border--;
            c_gotoxy(x_border, y_border);
            printf(" ");
            borders(x_border, y_border, index + 1);
        }
    }
}

int main(){
    c_clrscr();
    borders(0, 0, 0);
    initing(0, 0, 0);
}
