/* C program that will simulate a game of rock, paper scissors
   
   Author: Mohammad Jad Touihri
   Date: 02/02/2021
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSCORE 5


// Function signature(s)
int* Opponent();
int score(int*);


int main()
{
    int* wins = 0;
    int* losses = 0;

    /*
    char option1[5] = "rock";
    char option2[6] = "paper";
    char option3[9] = "scissors";
    */

    MENU:
    system("cls");
    int* PlayerChoice = 0;
    int* ComputerChoice = 0;
    
    printf("Welcome to this game of Rock, Paper, Scissors\n\n"
           "Please choose:\n"
           "1 for rock\n"
           "2 for paper\n"
           "3 for scissors\n\n");
    
    scanf("%d", &PlayerChoice);
    while(getchar() != '\n');
    fflush(stdin);

    do
    {
        switch( *(PlayerChoice) )
        {
            case 1:
                system("cls");
                printf("You have chosen rock!\n");
                Opponent();

                sleep(2);
                goto MENU;
            break;

            case 2:
                system("cls");
                printf("You have chosen paper!\n");

                sleep(2);
                goto MENU;
            break;

            case 3:
                system("cls");
                printf("You have chosen scissors!\n");

                sleep(2);
                goto MENU;
            break;

            case 4:
                system("cls");
                printf("Goodbye!!");
            break;


            default:
                system("cls");
                printf("Please choose a valid option! (number between 1 and 4)\n"
                    "You have chosen: %d", PlayerChoice);

                sleep(2);
                goto MENU;
                
        } // End switch
    } // End do
    while(PlayerChoice != 4);


    return 0;
} // End main()



// Function for the opponent to choose a random option from 1 to 3
int* Opponent()
{
    int* BotChoice = 0;

    

    return *BotChoice;
} // End Opponent()

