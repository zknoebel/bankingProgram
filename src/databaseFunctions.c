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
//  DATE:           Mar 01, 2017
//
//  FILE:           dadabaseFunctions.c
//
//  DESCRIPTION:    This file contains the functions to read and 
//                  write to .txt files
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "record.h"
#include "globalV.h"


/*****************************************************************
//
//  Function name:  readfile
//
//  DESCRIPTION:    parses a .txt file full of account structures 
//                  and puts them into memory
//
//  Parameters:     struct record ** start
//                  a pointer to a pointer that marks the start of 
//                  the linked list that stores the bank account
//                  information
//
//                  char filename[ ]
//                  the name of the file to be read in
//
//  Return values:  0 : success
//
//                  other than 0: error
//
****************************************************************/

int readfile(struct record ** start, char filename[])
{
        
        FILE * file;
        char trash[25];
        struct record * temp = * start;
        char line[80];
        
        if(debugmode)
        {
                printf("Function : readfile(  , %s)\n", filename);
        }

        if(access(filename, F_OK) == -1)
        {
                *start = NULL;
        }
        else
        {
                file = fopen(filename, "rt");

                while(fgets(trash, 25, file) != NULL)
                {

                        fscanf(file, "%d", &(temp->accountno));
                        fgets(trash, 25, file);

                        fgets(temp->name, 25, file);

                        fgets(line, 80, file);
                        strcpy(temp->address, line);
                        while(fgets(line, 80, file))
                        {
                                strcat(temp->address, line);
                                if(strcmp(line, "\n") == 0)
                                {
                                        break;
                                }
                        }

                        fgets(trash, 25, file);
                        temp->next = malloc(sizeof(struct record));
                        temp = temp->next;
                        temp->next = NULL;
                }

                fclose(file);
        }
        return 0;
}

/*****************************************************************
//
//  Function name:  writefile
//
//  DESCRIPTION:    writes the linked list of bank account 
//                  information into a text file
//
//  Parameters:     struct recore * start
//                  a pointer to the start of the linked list 
//                  holding the bank account information
//
//                  char filename[ ]
//                  the name of the file to be read in
//
//  Return values:  0 : success
//
//                  other than 0: error
//
****************************************************************/

void writefile(struct record * start, char filename[])
{

        FILE *file = fopen(filename, "w");
        struct record * temp = start;

        if(debugmode)
        {
                printf("Function : writefile(  , %s)\n", filename);
        }

        if(start != NULL)
        {
                while(temp != NULL)
                {
                        if(temp->accountno > 0)
                        {
                                fprintf(file, "{\n");
                                fprintf(file, "%d\n", temp->accountno);
                                fprintf(file, "%s", temp->name);
                                fprintf(file, "%s", temp->address);
                                fprintf(file, "}\n");
                        }

                        if(temp->next == NULL)
                        {
                                break;
                        }

                        temp = temp->next;
                }
        }

        fclose(file);

}

