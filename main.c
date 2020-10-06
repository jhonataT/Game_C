// // gcc conio.o main.c main
// gcc -c func.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "conio.h"

      
    void delay(int number_of_seconds) { 
        // Converting time into milli_seconds 
        int milli_seconds = 10000 * number_of_seconds; 
  
        // Storing start time 
        clock_t start_time = clock(); 
  
        // looping till required time is not achieved 
        while (clock() < start_time + milli_seconds); 
    } 

    typedef struct { // scoring system
        char nickName;
        int errors;
        int scoring;
    } player;


    void initing(int number, int x_number, int y_number){
        void borders(int x_border, int y_border, int index);
        c_clrscr();
        borders(0, 0, 0);

        srand(time(NULL));

        while(1){
            delay(1);
            c_textbackground(0);
            c_textcolor(4);
            number = rand() % 10;
            x_number = (rand() % 111) + 5;
            y_number = (rand() % 22) + 3;

            c_gotoxy(x_number, y_number);
            printf("%d", number);

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

    void options_portuguese(char screen[], int bg_color, int x_option, int y_option){
        void options_english(char screen[], int bg_color, int x_option, int y_option);
        
        int position = 0; 

        c_gotoxy(x_option, 13);
        printf("%s\n", screen);
        
        c_textbackground(0);
        
        // c_textbackground(13);
        screen = "Creditos  ";
        c_gotoxy(x_option, 14);
        printf("%s\n", screen);

        c_gotoxy(x_option, 15);
        screen = "Linguagem  ";
        printf("%s\n", screen);
            
        while(1) {
        
            int input = c_getch();
            c_gotoxy(x_option, 18);
            printf("tecla: %d\n", input);

            if(input == 66 && position == 0){
                
                position = 1;
                
                c_textbackground(0);
                screen = "Novo Jogo";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Creditos";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Linguagem";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }

            else if(input == 66 && position == 1){
                
                position = 2;
                
                c_textbackground(0);
                screen = "Novo Jogo";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Creditos";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Linguagem";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);
                c_textbackground(0);

            }
            else if(input == 65 && position == 2){
                
                position = 1;
                
                c_textbackground(0);
                screen = "Novo Jogo";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Creditos";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Linguagem";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }
            else if(input == 65 && position == 1){
                
                position = 0;
                
                c_textbackground(13);
                screen = "Novo Jogo";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Creditos";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Linguagem";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }
            else if(input == 10 && position == 0) initing(0, 0, 0);
            else if(input == 10 && position == 1) printf(" \n"); //credits
            else if(input == 10 && position == 2) {
                //Language:

                position = 5;

                c_textbackground(0);
                screen = "Português  ";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Inglês  ";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Voltar     ";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

                while(1) { // language while;
                    input = c_getch();

                    if(input == 65 && position == 5) {
                        position = 4;
                    
                        c_textbackground(0);
                        screen = "Português  ";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "Inglês  ";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "Voltar     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);
                       
                    }
                    else if(input == 65 && position == 4) {
                        position = 3;
                    
                        c_textbackground(13);
                        screen = "Português  ";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "Inglês  ";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "Voltar     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 66 && position == 3) {
                        position = 4;
                    
                        c_textbackground(0);
                        screen = "Português  ";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "Inglês  ";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "Voltar     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 66 && position == 4) {
                        position = 5;
                    
                        c_textbackground(0);
                        screen = "Português  ";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "Inglês  ";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "Voltar     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 10 && position == 5){
                        c_textbackground(13);
                        options_portuguese("Novo Jogo  ", 0, 50, 12);
                    }
                    else if(input == 10 && position == 4){
                       c_textbackground(13); 
                       options_english("New Game  ", 0, 50, 12);
                    } 
                    else if(input == 10 && position == 3){
                        c_textbackground(13);
                        options_portuguese("Novo Jogo  ", 0, 50, 12);
                    }
                }

            }
        };
    }

    void options_english(char screen[], int bg_color, int x_option, int y_option) {

        int position = 0; 

        c_gotoxy(x_option, 13);
        printf("%s\n", screen);
        
        c_textbackground(0);
        
        // c_textbackground(13);
        screen = "Credits  ";
        c_gotoxy(x_option, 14);
        printf("%s\n", screen);

        c_gotoxy(x_option, 15);
        screen = "Language  ";
        printf("%s\n", screen);
            
        while(1) {
        
            int input = c_getch();
            c_gotoxy(x_option, 18);
            printf("tecla: %d\n", input);

            if(input == 66 && position == 0){
                
                position = 1;
                
                c_textbackground(0);
                screen = "New Game";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Credits";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Language";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }

            else if(input == 66 && position == 1){
                
                position = 2;
                
                c_textbackground(0);
                screen = "New Game";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Credits";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Language";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);
                c_textbackground(0);

            }
            else if(input == 65 && position == 2){
                
                position = 1;
                
                c_textbackground(0);
                screen = "New Game";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "Credits";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Language";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }
            else if(input == 65 && position == 1){
                
                position = 0;
                
                c_textbackground(13);
                screen = "New Game";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Credits";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "Language";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

            }
            else if(input == 10 && position == 0) initing(0, 0, 0);
            else if(input == 10 && position == 1) printf(" \n"); //credits
            else if(input == 10 && position == 2) {
                //Language:

                position = 5;

                c_textbackground(0);
                screen = "Portuguese";
                c_gotoxy(x_option, 13);
                printf("%s\n", screen);

                c_textbackground(0);
                screen = "English";
                c_gotoxy(x_option, 14);
                printf("%s\n", screen);

                c_textbackground(13);
                screen = "back     ";
                c_gotoxy(x_option, 15);
                printf("%s\n", screen);

                while(1) { // language while;
                    input = c_getch();

                    if(input == 65 && position == 5) {
                        position = 4;
                    
                        c_textbackground(0);
                        screen = "Portuguese";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "English";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "back     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);
                       
                    }
                    else if(input == 65 && position == 4) {
                        position = 3;
                    
                        c_textbackground(13);
                        screen = "Portuguese";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "English";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "back     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 66 && position == 3) {
                        position = 4;
                    
                        c_textbackground(0);
                        screen = "Portuguese";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "English";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "back     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 66 && position == 4) {
                        position = 5;
                    
                        c_textbackground(0);
                        screen = "Portuguese";
                        c_gotoxy(x_option, 13);
                        printf("%s\n", screen);

                        c_textbackground(0);
                        screen = "English";
                        c_gotoxy(x_option, 14);
                        printf("%s\n", screen);

                        c_textbackground(13);
                        screen = "back     ";
                        c_gotoxy(x_option, 15);
                        printf("%s\n", screen);

                    }
                    else if(input == 10 && position == 5){
                        c_textbackground(13);
                        options_english("New Game  ", 0, 50, 12);
                    }
                    else if(input == 10 && position == 4){
                       c_textbackground(13); 
                       options_english("New Game  ", 0, 50, 12);
                    } 
                    else if(input == 10 && position == 3){
                        c_textbackground(13);
                        options_portuguese("Novo Jogo  ", 0, 50, 12);
                    }
                }


            }

        };

    }

    int main(){
    
        c_clrscr();
        borders(0, 0, 0);
        c_textbackground(13);
        options_english("New Game", 0, 50, 12);

    }
