/* Program that will perform security authorisation
based on numberic codes consisting of Four digits
between 0 and 9 inclusive

Author: C19319183 Mohammad Touihri
Date of last revision: 14/05/2020

Compiler: Atom
*/


// Header Files
#include <stdio.h> // Standard input/output commands for C
#include <stdlib.h> // Standard library for C. Allows additional functions such as the rand() command
#include <Windows.h> // Enables functionality for things such as the sleep() command and the system() command
#include <time.h> // Used in the srand() function. Allows for use of the current time as a seed for the srand() function


//Symbolic Names
#define CODESIZE 4


// Structure Templates
struct code_counter
{
  int correct_code;
  int wrong_code;
};


// Structre Variable(s)
struct code_counter counter;



// Function Signatures
int* RandomNumber (int*); //Function to Generate Random numbers
void swap (int*); // Function to encrypt the number chosen/generated
void Memory_Clear (int*); // Function to initialise ChosenAccessCode array with all 0

void MainMenu (void); // Function to launch the main menu
int MenuOption1 (int*); // Function for Menu Option 1
int MenuOption2 (int*); // Function for Menu Option 2
void MenuOption3 (int*); // Function for Menu Option 3
void MenuOption4 (int*); // Function for Menu Option 4
void MenuOption5 (void); // Function for Menu Option 5


// Default Authorised Access Code
const unsigned int access_code [CODESIZE] = {4, 5, 2, 3};


int main()
{
  srand(time(0)); // Use current time as seed for random generator
  MainMenu(); // Call Main Menu function


  getchar();
  return 0;
} // End main()


// Implement MainMenu()
void MainMenu(void)
{

  // Variables
  int ChosenAccessCode[CODESIZE];
  int Menu_Options = 0;      // In charge of the menu choices

  int Generated_Or_Not = 0; // Tells the program whether a code has been generated or not
  int encrypted = 0;       // Tell the program whether the code has been encrypted or not

  Memory_Clear(ChosenAccessCode);

  do
  {
    printf("\tMain Menu:\n"
           "1). Enter a code or generate a random code\n"
           "2). Encrypt Code\n"
           "3). Compare Encrypted Code With Access Code\n"
           "4). Decrypt an already encrypted code\n"
           "5). Display correct/incorrect attempts\n"
           "6). Exit Program\n\n");

         scanf("%d",&Menu_Options);
         while(getchar() != '\n'); // Check for character input


         switch(Menu_Options)
         {
           case 1:
           {
             system("cls");
             Generated_Or_Not = MenuOption1(ChosenAccessCode);
             Menu_Options = 0;
             printf("\n\n");
             break;
           } // End case 1

           case 2:
           {
             system("cls");
             if(Generated_Or_Not == 1)
             {
                 encrypted = MenuOption2(ChosenAccessCode);
                 Menu_Options = 0;
                 printf("\n\n");
              } // End if

              else if (encrypted == 1)
              {
                printf("Number Already Encrypted!");
                sleep(1);
                system("cls");
              } // End else if

              else
              {
                printf("Sorry, You must generate a number first! (Option 1)\n\n");
                sleep(1);
                system("cls");
              } // End else
              break;
           } // End case 2

           case 3:
           {
             system("cls");
             if(encrypted == 1)
             {
                 system("cls");
                 MenuOption3(ChosenAccessCode);
                 Menu_Options = 0;
                 printf("\n\n");
              } // End if

              else
              {
                printf("Sorry, You must encrypt your number first! (Option 2)\n\n");
                sleep(1);
                system("cls");
              } // End else
              break;
           } // End case 3

           case 4:
           {
             system("cls");
              if(encrypted == 1)
              {
                 system("cls");
                 MenuOption4(ChosenAccessCode);
                 Menu_Options = 0;
                 printf("\n\n");
              } // End if

              else
              {
                printf("Sorry, You must encrypt your number first! (Option 2)\n\n");
                sleep(1);
                system("cls");
              } // End else
              break;
           } // End case 4

           case 5:
           {
             system("cls");
             if(Generated_Or_Not == 1)
             {
                 system("cls");
                 MenuOption5();
                 Menu_Options = 0;
                 printf("\n\n");
              } // End if

              else
              {
                printf("Sorry, You must encrypt your number first! (Option 2)\n\n");
                sleep(1);
                system("cls");
              }
              break;
           } // End case 5

           case 6:
           {
             system("cls");
             printf("Exiting Program....\n");
             exit(0);
           } // End case 6


           default:
           {
             printf("Please Enter A Valid Input!\n\n");
           } // End default

         } // End switch
  } // End do
  while(Menu_Options != 6); // End while

} // End MainMenu()


// Function for choosing/generating a user code
int MenuOption1(int* UserCode)
{
  int Option1Choices;

  MENU1:printf("Input a code or generate a random one:\n"
               "1). Input Code Manually\n"
               "2). Generate a Random Code\n\n");

         scanf("%d", &Option1Choices);
         while(getchar() != '\n');


  if(Option1Choices == 1)
  {
      MANUAL_INPUT:printf("\nEnter Four Digits, one at a time\n\n");

      for(int i = 0; i < CODESIZE; i++)
      {
        printf("Enter Digit:\n");
        scanf("%d", &( *(UserCode + i) ) );
        while(getchar() != '\n'); // Reject character inputs

        if( *(UserCode + i) < 10 && *(UserCode + i) >= 0)
        {
          continue;
        } // End if

        else
        {
          i--;
          printf("Please Enter a Valid Number between 0 and 9 inclusive:\n ");
        } // End else
      } // End for


      printf("\nYou have entered:\n");
      for(int i = 0; i < CODESIZE; i++)
      {
        printf("%d",  *(UserCode + i) );
      } // End for

  } // Outer if


  else if(Option1Choices == 2)
  {
    system("cls");

    printf("Generating Random 4 Digit Access Code:\n");
    UserCode = RandomNumber(UserCode);


    for(int i = 0; i < CODESIZE; i++)
    {
      printf("%d", *(UserCode + i) );
    } // End for

  } // End else if



  else
  {
    printf("Please Enter a Valid Input\n\n");
    goto MENU1;
  } // End else


return 1;
} // End MenuOption1()



// Function to encrypt the user code
int MenuOption2(int* UserCode)
{

  char Option2Choices;

  MENU2:
  printf("Encrypt the code: ");
  for(int i = 0; i < CODESIZE; i++)
  {
    printf("%d", *(UserCode + i) );
  } // End for


  puts("\n\nType 'Y' for yes or 'N' for No\n");
  scanf("%1s", &Option2Choices);


  switch(Option2Choices)
  {


      case 'Y':
      case 'y':
      {

        swap(UserCode); // Function to encrypt the code


        for(int i = 0; i < CODESIZE; i++)
        {

          // Check if the digits are in between 0 and 9 and add 1 to them
          if( *(UserCode + i) <= 9 && *(UserCode + i) >= 0)
          {
            *(UserCode + i) = *(UserCode + i) + 1;

            // Check if digits are greater than 9
            if( *(UserCode + i) > 9)
            {
              *(UserCode + i) = 0;
            }// End innermost if
          } // End next if
        } // End for


        printf("Encrypted Code is:\n");
        for(int i = 0; i < CODESIZE; i++)
        {
          printf("%d", *(UserCode + i) );
        } // End for

        break;
      } // End case 'y'


      case 'n':
      case 'N':
      {
        MainMenu();
        break;
      } // End case 'n'


      default:
      {
        printf("Invalid Input!\n\n");
        goto MENU2;
      } // End default
  } // End switch


return 1;
system("cls");
} // End MenuOption2()



// Function to compare the user code with the access code
void MenuOption3(int* UserCode)
{

  // variables
  int same = 0;
  static int correct = 0;
  static int incorrect = 0;

  printf("Now Comparing User Code with Encrypted Access Code....\n\n");

  for(int i = 0; i < CODESIZE; i++)
  {
    if( *(UserCode + i) == *(access_code + i) )
    {
      same++;
    } // end if
  } // End for

  sleep(1);
  system("cls");
  if(same == CODESIZE)
  {
    printf("Correct Code Entered, Access Granted\n\n");
    correct++;
  } // End if


  else
  {
    printf("Sorry, Wrong Code Entered, Access is Denied\n\n");
    incorrect++;
  } // End else


  //increment the structure members
  counter.wrong_code = incorrect;
  counter.correct_code = correct;


} // End MenuOption3()


// Function to Decrypt an encrypted code
void MenuOption4(int* UserCode)
{

  for(int i = 0; i < CODESIZE; i++)
  {

    // Check if the digits are in between 0 and 9 and take 1 away from them
    if( *(UserCode + i ) <= 9 && *(UserCode + i ) >= 0)
    {
      *(UserCode + i) = *(UserCode + i) - 1;


      // Check if digits are less than 0
      if( *(UserCode + i) == -1)
      {
        *(UserCode + i) = 9;
      } // End inner if

    } // End outer if

  } // End for

  // Function to swap the digits
  swap(UserCode);
  system("cls");


  puts("\nThe Decrypted User Code is: ");
  for(int i = 0; i < CODESIZE; i++)
  {
    printf("%d", *(UserCode + i) );
  } // End for
  sleep(1);

} // End MenuOption4()




// Function to display the number of correct and incorrect codes Entered
void MenuOption5(void)
{
  system("cls");
  printf("The Correct Code was entered: %d times\n", counter.correct_code );
  printf("The Incorrect Code was entered: %d times\n\n\n", counter.wrong_code );
  sleep(1);
} // End MenuOption5()






// Function to initialise the array with all 0
void Memory_Clear(int* UserCode)
{
  for(int i= 0; i < CODESIZE; i++)
  {
    *(UserCode + i) = 0;
  }
}


// Function to generate random access code
int* RandomNumber(int RandomCode[CODESIZE])
{

  for(int i = 0; i < CODESIZE; i++)
  {
    *(RandomCode + i) = rand() % 10;
  } // End for


return RandomCode;
} // End RandomNumber()


// Function to encrypt the number
void swap(int *EncryptedCode)
{
  //Temp variable
  int Switch = *EncryptedCode;


  //Switch 1st digit with the 3rd digit
  *(EncryptedCode + 0) = *(EncryptedCode + 2);
  *(EncryptedCode + 2) = Switch;


  //Switch 2nd digit wih the 4th digit
  Switch = *(EncryptedCode + 1);
  *(EncryptedCode + 1) = *(EncryptedCode + 3);
  *(EncryptedCode + 3) = Switch;

} // End swap()
