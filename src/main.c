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
//  DATE:           Mar 03, 2017
//
//  FILE:           main.c
//
//  DESCRIPTION:    This file contains the main function for the 
//                  program
//
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "record.h"
#include "pj1.h"
#define MAIN_FILE
#include "globalV.h"

void menu();

/*****************************************************************
//
//  Function name:  main
//
//  DESCRIPTION:    a user interface for the banking system
//
//  Parameters:     none
//
//  Return values:  0 : success
//
//                  other than 0 : failure
//
****************************************************************/

int main(int argc, char * argv[])
{

        int menuChoice = 0;
        char throwAway[100];
        struct record * start = (struct record *) malloc(sizeof(struct record));
        char fileName[] = "saveAccounts.txt";

        if(argc > 1)
        {
                debugmode = (strcmp(argv[1], "debug") == 0);
        }

        if((debugmode && (argc ==2))||(argc == 1)) 
        {

                readfile(&start, fileName);

                printMenu();

                while(1){

                        menuChoice = 0;
                        scanf("%d", &menuChoice);
                        fgets(throwAway, sizeof throwAway, stdin);

                        switch(menuChoice)
                        {

                                case 1 :
                                        print1(&start);
                                        break;
                                case 2 :
                                        print2(start);
                                        break;
                                case 3 :
                                        print3(start);
                                        break;
                                case 4 :
                                        print4(start);
                                        break;
                                case 5 :
                                        print5(&start);
                                        break;
                                case 6 :
                                        print6();
                                        writefile(start, fileName);
                                        return 0;
                                case 7 :
                                        print7();
                                        break;
                                default :
                                        printDefault();
                                        break;
                        }
                }
        }
        else
        {
                printError();
                return 1;
        }
}

