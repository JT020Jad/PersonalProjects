/* Program that will simulate a mathematics quiz game
Author: Mohammad Jad Touihri C19319183
Date: 29/10/2019
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    //display menu section
    int menuSelect;
    int quizTotal;
    int correctAnswer = 0;
    int incorrectAnswer = 0;
    int i;
    int quizAttempt = 0;
    

    
    do
    {
        
        printf("\n\nMathematics Quiz Main Menu:\n\n");
        printf("\n1). Quiz Duration\n");
        printf("2). Start Quiz\n");
        printf("3). Display the number of questions that were answered correctly and incorrectly\n");
        printf("4). Exit Program\n\n");
        scanf("%d", &menuSelect);
        while(getchar() != '\n');
        
        
        //menu input
        switch(menuSelect)
        {
        
            //menu selection 1
            case(1):
            { //start case
                
                printf("\nHow many questions would you like to be asked between 1 and 5?\n");
                scanf("%d", &quizTotal);
                
                
                switch(quizTotal)
                {

                    case(1):
                    {
                        printf("\nYou will be asked %d question(s)\n\n", quizTotal);
                        break;
                    }
            
            
                    case(2):
                    {
                        printf("\nYou will be asked %d question(s)\n\n", quizTotal);
                        break;
                    }
            
            
                    case(3):
                    {
                        printf("\nYou will be asked %d question(s)\n\n", quizTotal);
                        break;
                    }
            
            
                    case(4):
                    {
                        printf("\nYou will be asked %d question(s)\n\n", quizTotal);
                        break;
                    }
            
            
                    case(5):
                    {
                        printf("\nYou will be asked %d question(s)\n\n", quizTotal);
                        break;
                    }
                
                
                //error check
                    default:
                        printf("\nPlease enter a valid input \n\n");
                        scanf("%d", &quizTotal);
                        
                } //end quizTotal switch        
                        
                        
            break;
            } //end case 1
                
                
                
                
            //menu selection 2
            case(2):
            { // start case
                
                
                /*
                                    tells the program that the quiz was completed
                                    to satisfy the condition for menu selection 3
                                */
                quizAttempt++;
                
                
                //resets correct and incorrect counters to 0 for each run
                correctAnswer = 0;
                incorrectAnswer = 0;
                
                
                
                // user inputs for menu selection 2 
                    printf("You will now be asked %d question(s)\n\n", quizTotal);
                
                    //quiz questions
                    for(i = 1; i <= quizTotal; i++)
                    {
                        //local variable
                        int answer;
                        
                        
                        
                        //question 1
                        
                        if(i == 1)
                        {
                            printf("What is 2 + 2?\n");
                            scanf("%d", &answer);
                        
                            if(answer == 4)
                            {
                                printf("Correct!\n\n");
                                correctAnswer++;
                            }   
                        
                            else
                            {
                                printf("Incorrect! - The answer was: 4\n\n");
                                incorrectAnswer++;
                            }
                        }
                        
                        
                        //question 2
                        
                        if(i == 2)
                        {
                            printf("What is 9 * 3?\n");
                            scanf("%d", &answer);
                        
                            if(answer == 27)
                            {
                                printf("Correct!\n\n");
                                correctAnswer++;
                            } //end if question 2
                        
                            else
                            {
                                printf("Incorrect! - The answer was: 27\n\n");
                                incorrectAnswer++;
                            } //end else question 2
                        }
                        
                        
                        //question 3
                        
                        if(i == 3)
                        {
                            printf("What is 4 / 2?\n");
                            scanf("%d", &answer);
                        
                            if(answer == 2)
                            {
                                printf("Correct!\n\n");
                                correctAnswer++;
                            } //end if question 3
                        
                            else
                            {
                                printf("Incorrect! - The answer was: 2\n\n");
                                incorrectAnswer++;
                            } //end else question 3
                        }
                        
                        
                        //question 4
                            
                        if(i == 4)
                        {
                            printf("What is 95 - 7?\n");
                            scanf("%d", &answer);
                        
                            if(answer == 88)
                            {
                                printf("Correct!\n\n");
                                correctAnswer++;
                            } //end if question 4
                        
                            else
                            {
                                printf("Incorrect! - The answer was: 88\n\n");
                                incorrectAnswer++;
                            } //end else question 4
                        }    
                            
                            
                        //question 5
                        
                        if(i == 5)
                        {
                            printf("What is 45 * 2?\n");
                            scanf("%d", &answer);
                        
                            if(answer == 90)
                            {
                                printf("Correct!\n\n");
                                correctAnswer++;
                            } //end if question 5
                        
                            else
                            {
                                printf("Incorrect! - The answer was: 90\n\n");
                                incorrectAnswer++;
                            } //end else question 5
                        }    
                    } //end for   
                    
                    
            break;              
            } //end case 2
                
                
                
            //menu selection 3  
                case(3):
                {
                    if(quizAttempt < 1)
                    {
                        printf("\nSorry you must first complete the quiz\n\n\n");
                    }
            
                    else
                    {
                        printf("\nYou have scored %d question(s) correct\n", correctAnswer);
                        printf("\nYou have scored %d question(s) incorrect\n\n\n", incorrectAnswer);
                    } //end else
                        
                break;    
                } //end case 3      
                
                
            //menu selection 4    
            case(4):
            {
                printf("\n\nProgram will now end\n");
                printf("Press 'Enter' to exit\n");
                
            break;
            } //end case 4
                
                
                
            default: 
            printf("Invalid input\n\n\n\n");
        } //end switch
                
                
                
    } // end outer do
    while(menuSelect != 4);
        
        
        
    flushall();   
    getchar();
    return 0;
} //end main