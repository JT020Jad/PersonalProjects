/* Program that simulates a lotto
game, and allows a user to choose
six numbers for a chance to win a prize

Author: C19319183 Mohammad Jad Touihri
Date: 08/03/2020
Compiler: Atom
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For the Ascii Title Art

#define SIZE 6


//Function Signature(s)
void Memory_Clear (int*); // Ensure the arrays are empty from the start
void MenuOption1 (int*); // Choose numbers
void MenuOption2 (int*); // Display the chosen numbers
void MenuOption3 (int*); // Sort the numbers into an ordered list
void MenuOption4 (int*); // Compare the chosen numbers with the winning numbers
void MenuOption5 (int*); // Disply the frequency of the numbers chosen each time a new set of numbers are entered

// Global Index Variables
int i;
int j;

// Global Winning Lotto Numbers
const int winning_numbers[SIZE] = {1, 3, 5, 7, 9, 11};


int main()
{
  int Menu_Options = 0;
  int numbers[SIZE];
  int choice_completion = 0;
  Memory_Clear(numbers); // Array Clearing function


  printf(R"EOF(
        LL             tt    tt               SSSSS   iii                          lll          tt
        LL       oooo  tt    tt     oooo      SS            mmm  mm mmm   uu   uu  lll    aaaa  tt     oooo    rr rr
        LL      oo  oo tttt  tttt  oo  oo     SSSSS   iii  mmm   mm  mm   uu   uu  lll  aa  aa  tttt  oo  oo   rrr
        LL      oo  oo tt    tt    oo  oo         SS  iii  mmm   mm  mm   uu   uu  lll aa   aa  tt    oo  oo   rr
        LLLLLLL  oooo   tttt  tttt  oooo      SSSSS   iii  mmm   mm  mm    uuuuu   lll  aaa aa  tttt   oooo    rr
        )EOF");

    printf("\n\n\n");


    do
    {
      printf("\tMain Menu:\n"
              "1). Choose Numbers\n"
              "2). Display the chosen numbers\n"
              "3). Sort number choices in ascending order\n"
              "4). Compare choice numbers with winning numbers\n"
              "5). Display the frequency of the numbers entered each time\n"
              "6). Exit the Program\n\n");

        scanf("%d", &Menu_Options);
        while(getchar() != '\n');


        switch(Menu_Options)
        {
          case 1:
          {
            MenuOption1(numbers);
            printf("\n\n");
            Menu_Options = 0;
            choice_completion++;
            break;
          } // End case 1


          case 2:
          {
            if(choice_completion < 1)
            {
              printf("Sorry, you must choose your numbers first\n\n");
              Menu_Options = 0;
              break;
            } // End if
            else
            {
              MenuOption2(numbers);
              printf("\n\n");
              Menu_Options = 0;
              break;
            } // End else
          } // End case 2


          case 3:
          {
            if(choice_completion < 1)
            {
              printf("Sorry, you must choose your numbers first\n\n");
              Menu_Options = 0;
              break;
            } // End if
            else
            {
              MenuOption3(numbers);
              printf("\n\n");
              Menu_Options = 0;
              break;
            } // End else
          } // End case 3


          case 4:
          {
            if(choice_completion < 1)
            {
              printf("Sorry, you must choose your numbers first\n\n");
              Menu_Options = 0;
              break;
            } // End if
            else
            {
              MenuOption4(numbers);
              printf("\n\n");
              Menu_Options = 0;
              break;
            } // End else
          } // End case 4


          case 5:
          {
            if(choice_completion < 1)
            {
              printf("Sorry, you must first choose your numbers\n\n");
              Menu_Options = 0;
              break;
            } // End if
            else
            {
              MenuOption5(numbers);
              printf("\n\n");
              Menu_Options = 0;
              break;
            } // End else
          } // End case 5


          case 6:
          {
            printf("Exiting Program....\n");
            exit(0);
          } // End case 6


          default:
          {
            printf("Please enter a valid input\n\n");
          } // End default

        } //End switch
      } // End do
      while(Menu_Options != 6);


  getchar();
  return 0;
} // End main()

// Implement Memory_Clear()
void Memory_Clear(int* number_choices)
{
  for(i = 0; i < SIZE; i++)
  {
    *(number_choices + i) = 0;
  } // End for

} // End Memory_Clear()


// Implement MenuOption1()
void MenuOption1(int* number_choices)
{
  printf("Enter your choice of numbers (from 1 - 42 inclusive):\n");
  for(i = 0; i < SIZE; i++)
  {
    scanf("%d", &( *(number_choices + i) ) );
    while(getchar() != '\n');
    if( *(number_choices + i) > 0 && *(number_choices + i) < 43)
    {
      continue;
    } // End if
    else
    {
      i--;
      printf("Input out of bounds. Please enter a valid input\n\n");
    } // End else

    fflush(stdin);
  } // End for

} // End MenuOption1()


// Implement MenuOption2()
void MenuOption2(int* number_choices)
{
  printf("\nYour choice of numbers are:\n");
  for(j = 0; j < SIZE; j++)
 {
    printf("%d\n", *(number_choices + j) );
  } // End for

} // End MenuOption2()


// Implement MenuOption3()
void MenuOption3(int* number_choices)
{
  int temp;

  for (i = 0; i < SIZE-1; i++)
  {
   	for(j = 0; j < SIZE-1; j++)
   	{
   		if(*(number_choices + j) > *(number_choices + j + 1))
   		{
   			temp = *(number_choices + j);
   			*(number_choices + j) = *(number_choices + j + 1);
   			*(number_choices + j + 1) = temp;
   		} // End if
   	} // End inner for
   } // End outer for

   printf("Numbers have been sorted\n\n");

} // End MenuOption3()


void MenuOption4(int* number_choices)
{
  int match = 0;

  for(i = 0; i < SIZE; i++)
  {

    for(j = 0; j < SIZE; j++)
    {
      if(*(winning_numbers + i) == *(number_choices + j))
      {
        match++;
      } // End if
    } // End inner for
  } // End outer for


  switch(match)
  {
    case 6:
    {
      printf("You have won the Jackpot!!\n");
      break;
    } // End jackpot case

    case 5:
    {
      printf("You have won a New Car!!\n");
      break;
    } // End new car case

    case 4:
    {
      printf("You have won a Weekend Away!!\n");
      break;
    } // End Weekend Away Case


    case 3:
    {
      printf("You have won a Cinema Pass!!\n");
      break;
    } // End Cinema Pass case

    default:
    {
      printf("Sorry, You have not won anything. Better Luck next time!\n\n");
    } // End default
  } // End switch

} // End MenuOption4()


void MenuOption5(int *number_choices)
{
  int incrementals[SIZE];
  int counter;

  for(i = 0; i < SIZE; i++)
  {
    counter = 1;

    for(j = i + 1; j < SIZE; j++)
    {
      if( *(number_choices + i) == *(number_choices + j) ) //check for duplicate elements
      {
        counter++;
        *(incrementals + j) = 0; //Error Check: Ensures that the same element is not counted twice
      }//end if
    }//end inner for

    if(*(incrementals + i) != 0)
    {
      *(incrementals + i) = counter;
    }//end if
  } // End outer for


  printf("The Frequency of numbers chosen are:\n");
  for(i = 0; i < SIZE; i++)
  {
    if ( *(incrementals + i) != 0)
    {
      printf("The number %d is selected %d times\n", *(number_choices + i), *(incrementals + i) );
    }//end if
  }//end for

} // End MenuOption5()
