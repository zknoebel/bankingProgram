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
#include <string.h>

#include "globalV.h"

/*****************************************************************
//
//  Function name:  getaddress
//
//  DESCRIPTION:    parses multiple lines of text and delimits at
//                  multiple new lines (\n\n)
//
//  Parameters:     char address[]
//                  the address to be stored
//
//                  int length
//                  the maximum length of the address
//
//  Return values:  void
//
****************************************************************/

void getaddress(char address[], int length)
{

        char line[80];

        if(debugmode){
                printf("Function : getaddress(%s, %d)\n", address, length);
        }

        fgets(line, length, stdin);
        strcpy(address, line);
        while(fgets(line, length, stdin))
        {
                strcat(address, line);
                if(strcmp(line, "\n") == 0)
                {
                        break;
                }
        }
}

