/*****************************************************************
//
//  NAME:           Zachery Knoebel
//
//  HOMEWORK:       project 1
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           Mar 02, 2017
//
//  FILE:           getaddress.c
//
//  DESCRIPTION:    This file contains the function to get  
//                  addresses
//
****************************************************************/

#include <stdio.h>

#include "globalV.h"
#include "record.h"
#include "pj1.h"

void printEnter();
void printGetaddress();
void printGetName();
void printGetAccountno();
void printDefault();

/*****************************************************************
//
//  Function name:  print1
//
//  DESCRIPTION:    prints to std out for option 1 in the menu and
//                  collects information necessary to run
//                  addRecord, then runs addrecord
//
//  Parameters:     struct record ** start
//                  pointer to the pointer to the start of the
//                  linked list of bank accounts
//
//  Return values:  void
//
****************************************************************/

void print1(struct record ** start)
{
        int accountno = 0;
        char name[25];
        char address[80];
        char throwaway[100];

        if(debugmode){
                printf("Function : print1(  )\n");
        }

        printGetAccountno();
        scanf("%d", &accountno);
        fgets(throwaway, sizeof throwaway, stdin);

        printGetName();
        fgets(name, sizeof name, stdin);

        printGetaddress();
        getaddress(address, 80);

        addRecord(start, accountno, name, address);
        printEnter();
}

/*****************************************************************
//
//  Function name:  print2
//
//  DESCRIPTION:    prints to std out for option 2 in the menu and
//                  collects information necessary to run
//                  modifyRecord, then runs modifyRecord
//
//  Parameters:     struct record ** start
//                  pointer to the pointer to the start of the
//                  linked list of bank accounts
//
//  Return values:  void
//
****************************************************************/

void print2(struct record * start)
{
        struct record * pointerToRecord = start;
        int accountno = 0;
        char address[80];
        char throwaway[100];

        if(debugmode){
                printf("Function : print2(  )\n");
        }

        printGetAccountno();
        scanf("%d", &accountno);
        fgets(throwaway, sizeof throwaway, stdin);

        printGetaddress();
        getaddress(address, 80);

        modifyRecord(pointerToRecord, accountno, address);
        printEnter();

}

/*****************************************************************
//
//  Function name:  print3
//
//  DESCRIPTION:    prints to std out for option 3 in the menu and
//                  collects information necessary to run
//                  printRecord, then runs printRecord
//
//  Parameters:     struct record ** start
//                  pointer to the pointer to the start of the
//                  linked list of bank accounts
//
//  Return values:  void
//
****************************************************************/

void print3(struct record * start)
{
        struct record * pointerToRecord = start;
        int accountno = 0;
        char throwaway[100];

        if(debugmode){
                printf("Function : print3(  )\n");
        }

        printGetAccountno();
        scanf("%d", &accountno);
        fgets(throwaway, sizeof throwaway, stdin);

        printRecord(pointerToRecord, accountno);
        printEnter();

}

/*****************************************************************
//
//  Function name:  print4
//
//  DESCRIPTION:    prints to std out for option 4 in the menu and
//                  runs printAllRecords
//
//  Parameters:     struct record ** start
//                  pointer to the pointer to the start of the
//                  linked list of bank accounts
//
//  Return values:  void
//
****************************************************************/

void print4(struct record * rec)
{

        struct record * pointerToRecord = rec;

        if(debugmode){
                printf("Function : print4(  )\n");
        }

        printAllRecords(pointerToRecord);
        printEnter();

}

/*****************************************************************
//
//  Function name:  print5
//
//  DESCRIPTION:    prints to std out for option 5 in the menu and
//                  collects information necessary to run
//                  deleteRecord
//
//  Parameters:     struct record ** start
//                  pointer to the pointer to the start of the
//                  linked list of bank accounts
//
//  Return values:  void
//
****************************************************************/

void print5(struct record ** start)
{
        struct record ** pointerToRecordPointer = start;
        int accountno = 0;
        char throwaway[100];

        if(debugmode){
                printf("Function : print5(  )\n");
        }

        printGetAccountno();
        scanf("%d", &accountno);
        fgets(throwaway, sizeof throwaway, stdin);


        deleteRecord(pointerToRecordPointer, accountno);
        printEnter();

}

/*****************************************************************
//
//  Function name:  print6
//
//  DESCRIPTION:    prints to std out for option 6 in the menu
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void print6()
{
        if(debugmode){
                printf("Function : print6()\n");
        }

        printf("\nExiting Program Now\n\n");
}

/*****************************************************************
//
//  Function name:  print7
//
//  DESCRIPTION:    prints the menu options to std out
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void print7()
{ 
        if(debugmode){
                printf("Function : print7()\n");
        }

        printDefault();
        printf("\n(1) : Add a new record in the database\n");
        printf("(2) : Modify a record in the database using the accountno as the key\n");
        printf("(3) : Print information about a record using the accountno as the key\n");
        printf("(4) : Print all information in the database\n");
        printf("(5) : Delete an existing record from the database using the accountno as a key\n");
        printf("(6) : Quit the program\n");
        printf("(7) : Help\n\n");

        printEnter();
}

/*****************************************************************
//
//  Function name:  printMenu
//
//  DESCRIPTION:    prints the program title, whether debug mode  
//                  is on, and then prints the menu options to 
//                  std out
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printMenu()
{
        if(debugmode){
                printf("Function : printMenu()\n");
        }

        printf("\n -------------------------------------------------------------------------------\n");
        printf("|                              BANKING PROGRAM                                 |\n");
        printf("|      ----------------------------------------------------------------        |\n");
        if(debugmode)
        {
                printf("|                               debug mode on                                  |\n");
        }
        printf("|                                                                              |\n");
        printf("|                                    menu                                      |\n");
        printf(" -------------------------------------------------------------------------------\n\n");
        print7();
}

/*****************************************************************
//
//  Function name:  printDefault
//
//  DESCRIPTION:    prints default instructions to std out
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printDefault()
{
        if(debugmode){
                printf("Function : printDefault()\n");
        }

        printf("\nMake a selection by typing the number of that option and then pressing enter\n");
        printf("Or type 7 and press enter for help\n\n");
        printEnter();
}

/*****************************************************************
//
//  Function name:  printEnter
//
//  DESCRIPTION:    prints a line to instruct users to enter a 
//                  number on the screen
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printEnter()
{
        if(debugmode){
                printf("Function : printEnter()\n");
        }

        printf("\nEnter a number from the menu : ");
}

/*****************************************************************
//
//  Function name:  printError
//
//  DESCRIPTION:    prints usage instructions for running the
//                  program
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printError()
{
        if(debugmode){
                printf("Function : printError()\n");
        }

        printf("\nUsage : pj1 [option]\n\n");
        printf("     debug : This option will print out extra information while the program is\n");
        printf("             running, for debugging purposes.\n\n");
}

/*****************************************************************
//
//  Function name:  printGetAccountno
//
//  DESCRIPTION:    prints a line to instruct users to enter an
//                  account number on the screen
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printGetAccountno()
{
        if(debugmode){
                printf("Function : printGetAccountno()\n");
        }

        printf("\nEnter account number : ");
}

/*****************************************************************
//
//  Function name:  printGetName
//
//  DESCRIPTION:    prints a line to instruct users to enter a
//                  name on the screen
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printGetName()
{
        if(debugmode){
                printf("Function : printGetName()\n");
        }

        printf("\nEnter name (must be less than 25 characters) : ");
}

/*****************************************************************
//
//  Function name:  printGetAddress
//
//  DESCRIPTION:    prints a line to instruct users to enter an
//                  address on the screen
//
//  Parameters:     none
//
//  Return values:  void
//
****************************************************************/

void printGetaddress()
{
        if(debugmode){
                printf("Function : printGetaddress()\n");
        }

        printf("\nPress Enter after each line and hold Enter when finished entering address\n");
        printf("(Must be less than 80 characters long)\n");
        printf("\nEnter address: ");
}
