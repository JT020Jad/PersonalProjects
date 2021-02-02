/* Program that stores student data and allows for
searching of student Surnames and sorting of student data

Algorithm Assignment
Author: C19319183 Mohammad Jad Touihri
Compiler: Atom


references:
http://www2.cs.uregina.ca/~hilder/cs833/Other%20Reference%20Materials/The%20C%20Programming%20Language.pdf
https://beginnersbook.com/2015/02/c-program-to-sort-set-of-strings-in-alphabetical-order/
https://www.geeksforgeeks.org/c-program-sort-array-names-strings/

*/

//Header Files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Symbolic Names
#define TOTAL_OF_ALL 46 //total number of students in all groups (42 + 4)

#define DT265A_TOTAL 14 //total number of students in DT265A + 1
#define DT265C_TOTAL 10 //total number of students in DT265C + 1
#define DT265B_TOTAL 15 //total number of students in DT265B + 1
#define DT8900_TOTAL 7 //total number of students in DT8900 + 1


//Structure Template(s)
struct student_template
{
  char First_Name[30];
  char Surname[30];
  char Student_Number[7];
  char Full_or_Part[12];
};


//Functions Signature(s)
void Combined_List (struct student_template DT265A[],
                    struct student_template DT265C[],
                    struct student_template DT265B[],
                    struct student_template DT8900[],
                    struct student_template combined[]);


void Surname_Sort (struct student_template temporary,
                  struct student_template combined[]); // Function to sort the Surnames


void Surname_Search (struct student_template combined[]); // Function to search for Surnames



int main()
{

  struct student_template DT265A[DT265A_TOTAL] = {{"Mohammad", "Aouihri", "C00001", "Part"},
                                                  {"Mohammad", "Bouihri", "C00002", "Part"},
                                                  {"Mohammad", "Couihri", "C00003", "Part"},
                                                  {"Mohammad", "Douihri", "C00004", "Part"},
                                                  {"Mohammad", "Eouihri", "C00005", "Part"},
                                                  {"Mohammad", "Fouihri", "C00006", "Part"},
                                                  {"Mohammad", "Gouihri", "C00007", "Part"},
                                                  {"Mohammad", "Houihri", "C00008", "Part"},
                                                  {"Mohammad", "Iouihri", "C00009", "Part"},
                                                  {"Mohammad", "Jouihri", "C00010", "Part"},
                                                  {"Mohammad", "Kouihri", "C00011", "Part"},
                                                  {"Mohammad", "Louihri", "C00012", "Part"},
                                                  {"Mohammad", "Mouihri", "C00013", "Part"}};



  struct student_template DT265C[DT265C_TOTAL] = {{"Mohammad", "Nouihri", "C00014", "Part"},
                                                  {"Mohammad", "Oouihri", "C00015", "Part"},
                                                  {"Mohammad", "Pouihri", "C00016", "Part"},
                                                  {"Mohammad", "Qouihri", "C00017", "Part"},
                                                  {"Mohammad", "Rouihri", "C00018", "Part"},
                                                  {"Mohammad", "Souihri", "C00019", "Part"},
                                                  {"Mohammad", "Touihri", "C00020", "Part"},
                                                  {"Mohammad", "Uouihri", "C00021", "Part"},
                                                  {"Mohammad", "Vouihri", "C00022", "Part"}};



  struct student_template DT265B[DT265B_TOTAL] = {{"Mohammad", "wouihri", "C00023", "Full"},
                                                  {"Mohammad", "Xouihri", "C00024", "Full"},
                                                  {"Mohammad", "Youihri", "C00025", "Full"},
                                                  {"Mohammad", "Zouihri", "C00026", "Full"},
                                                  {"Mohammad", "AAouihri", "C00027", "Full"},
                                                  {"Mohammad", "BBouihri", "C00028", "Full"},
                                                  {"Mohammad", "CCouihri", "C00029", "Full"},
                                                  {"Mohammad", "DDouihri", "C00030", "Full"},
                                                  {"Mohammad", "EEouihri", "C00031", "Full"},
                                                  {"Mohammad", "FFouihri", "C00032", "Full"},
                                                  {"Mohammad", "GGouihri", "C00033", "Full"},
                                                  {"Mohammad", "HHouihri", "C00034", "Full"},
                                                  {"Mohammad", "IIouihri", "C00035", "Full"},
                                                  {"Mohammad", "JJouihri", "C00036", "Full"}};



  struct student_template DT8900[DT8900_TOTAL] = {{"Mohammad", "KKouihri", "C00037", "Full"},
                                                  {"Mohammad", "LLouihri", "C00038", "Full"},
                                                  {"Mohammad", "MMouihri", "C00039", "Full"},
                                                  {"Mohammad", "NNouihri", "C00040", "Full"},
                                                  {"Mohammad", "OOouihri", "C00041", "Full"},
                                                  {"Mohammad", "PPouihri", "C00042", "Full"}};


//**************************************************************************************************************
//*************************************************************************************************************
//All THE STUDENT DATA IS ABOVE THIS LINE, FUNCTIONS AND ALGORITHMS, ETC. WILL BE BELOW
//*************************************************************************************************************
//**************************************************************************************************************

  struct student_template temporary;
  struct student_template combined[TOTAL_OF_ALL];

  Combined_List(DT265A, DT265C, DT265B, DT8900, combined);  // Function to combine all of the classes into one big structure

  int exit = 0;
  int Menu_Options = 0;


  while(exit == 0)
   {
      printf("Please choose an option: \n");
      printf("1). Sort the data by Surname \n");
      printf("2). Search for a specific Surname \n");
      printf("3). Exit \n");


      // User Input
      scanf("%d", &Menu_Options);
      while(getchar() != '\n');
      fflush(stdin);


      switch(Menu_Options)
      {
        case 1:
        {
          Surname_Sort(temporary, combined);
          Menu_Options = 0;
          break;
        } // End case 1


        case 2:
        {
          Surname_Search(combined);
          Menu_Options = 0;
          break;
        } // End case 2


        case 3:
        {
          exit = 1;
          printf("Press Enter: \n");
          break;
        } //end case 3


        default:
        {
          printf("Error, Invalid Input! \n\n");
        } // End default
      } // End Switch
    } // End while


  getchar();
  return 0;
} // End main()



void Combined_List(struct student_template DT265A[], struct student_template DT265C[], struct student_template DT265B[], struct student_template DT8900[], struct student_template combined[])
{
  register int i; // index variable


  for(i = 0; i < DT265A_TOTAL; i++)
  {
    combined[i] = DT265A[i];
  } // End for


  for(i = 0; i < DT265C_TOTAL; i++)
  {
    combined[i + DT265A_TOTAL] = DT265C[i];
  } // End for


  for(i = 0; i < DT265B_TOTAL; i++)
  {
    combined[i + DT265A_TOTAL + DT265C_TOTAL] = DT265B[i];
  } // End for


  for(i = 0; i < DT8900_TOTAL; i++)
  {
    combined[i + DT265A_TOTAL + DT265C_TOTAL + DT265B_TOTAL] = DT8900[i];
  } // End for

} // End combined_List()



// Implement Surname Sorting
void Surname_Sort(struct student_template temporary, struct student_template combined[])
{
  register int i,j; // Index Variables
  register int pointer_location; // This variable is what will tell us where the cursor/step is at to keep track of the sorting

  for(i = 0; i < TOTAL_OF_ALL; i++)
  {
    pointer_location = i;

    for(j = 0; j < TOTAL_OF_ALL; j++)
    {
      if(strcmp(combined[pointer_location].Surname, combined[j].Surname) > 0)
      {
        pointer_location = j;
      } // End if
    } // End inner for


    if(pointer_location != i)
    {
      temporary = combined[i];
      combined[i] = combined[pointer_location];
      combined[pointer_location] = temporary;
    }
  } // End outer for


  for(i = 0; i < TOTAL_OF_ALL; i++)
  {
    printf("%s \t", combined[i].First_Name);
    printf("%s \t", combined[i].Surname);
    printf("%s \t", combined[i].Student_Number);
    printf("%s\n", combined[i].Full_or_Part);
  } // End for

  printf("\n");
} // End Surname_Sort()




//Implement Surname Searching
void Surname_Search(struct student_template combined[])
{
  int minimum_value = 0;
  int maximum_value = TOTAL_OF_ALL - 1;
  int middle_value;
  char Surname[30];


  //User Input
  printf("\nEnter any surname: \n");
  scanf("%s", &Surname);
  fflush(stdin);

  printf("\n");

  while(minimum_value <= maximum_value)
  {
    middle_value = (minimum_value + maximum_value)/2;
    if(strcmp(Surname, combined[middle_value].Surname) == 0)
    {
      printf("%s \t", combined[middle_value].First_Name);
      printf("%s \t", combined[middle_value].Surname);
      printf("%s \t", combined[middle_value].Student_Number);
      printf("%s\n", combined[middle_value].Full_or_Part);
      printf("\n\n");
      minimum_value = 60;
    } // End if

    else if(strcmp(Surname, combined[middle_value].Surname) > 0)
    {
      minimum_value = middle_value + 1;
    } // End else if

    else
    {
      maximum_value = middle_value - 1;
    } // End else
  } // End while



  if(minimum_value != 50)
  {
    puts("Surname not found\n");
  } // End if


} // End Surname_Search()
