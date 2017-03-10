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
//  FILE:           addRecord.c
//
//  DESCRIPTION:    This file contains the functions to 
//                  manipulate and view the bank account records
//
****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "globalV.h"
#include "record.h"

/*****************************************************************
//
//  Function name:  addRecord
//
//  DESCRIPTION:    This function will add a record to the database
//                 
//
//  Parameters:     rec (struct record **) pointer to the record pointer
//                  num (int) 
//                  char1 (char [])
//                  char2 (char [])
//
//  Return values:  0 : success
//
//                  other than 0: failure
//
****************************************************************/

int addRecord(struct record ** rec, int num, char char1[], char char2[])
{
        struct record * tempRecord = (struct record *) malloc(sizeof (struct record));
        struct record * tempPointer = * rec;

        if(debugmode){
                printf("Function : addRecord(  , %d, %s, %s)\n", num, char1, char2);
        }

        tempRecord->accountno = num;
        strcpy(tempRecord->name, char1);
        strcpy(tempRecord->address, char2);
        tempRecord->next = NULL;
        
        if(tempPointer == NULL)
        {
                *rec = tempRecord;      
        }
        else
        {
                if(tempPointer->accountno >= num)
                {
                        tempRecord->next = tempPointer;
                        *rec = tempRecord;
                }
                while((tempPointer->accountno < num) && tempPointer->next != NULL)
                {
                        if(tempPointer->next->accountno >= num)
                        {
                                tempRecord->next = tempPointer->next;
                                tempPointer->next = tempRecord;
                        }
                        tempPointer = tempPointer->next;
                }
                if((tempPointer->next == NULL) && (tempPointer->accountno < num))
                {
                        tempPointer->next = tempRecord;
                }
        }

        return 0;
}

/*****************************************************************
//
//  Function name:  deleteRecord
//
//  DESCRIPTION:    removes a record from the database
//                 
//
//  Parameters:     rec (pointer to a pointer to record) : 
//                  num (int) : 
//
//  Return values:  0 : success
//
//                  1 : the value was not found
//
****************************************************************/

int deleteRecord(struct record ** rec, int num)
{
        struct record * temp = * rec;
        struct record * temp2;
        int ret = 0;

        if(debugmode){
                printf("Function : deleteRecord(  , %d)\n", num);
        }

        if(*rec != NULL)
        { 
        temp2 = temp->next;

                ret = 1;

                while(temp->accountno == num)
                {
                        *rec = temp->next;
                        free(temp);
                        temp = * rec;
                        temp2 = temp->next;
                        ret = 0;
                }

                while(temp2 != NULL)
                {
                        while(temp2->accountno == num)
                        {
                                temp->next = temp2->next;
                                free(temp2);
                                temp2 = temp->next;
                                ret = 0;
                        }

			temp = temp2;
			temp2 = temp2->next;
                }
        }

        return ret;
}

/*****************************************************************
//
//  Function name:  modifyRecord
//
//  DESCRIPTION:    changes a record in the database
//
//  Parameters:     rec (pointer to a pointer to a record) :
//                  num (int) : 
//
//  Return values:  0 : success
//
//                  other than 0 : failure
//
****************************************************************/

int modifyRecord(struct record * rec, int num, char address[])
{
        struct record * temp = rec;

        if(debugmode){
                printf("Function : modifyRecord(  , %d, %s)\n", num, address);
        }

        if(rec != NULL)
        {
                while(temp != NULL)
                {
                        if(temp->accountno == num)
                        {
                                strcpy(temp->address, address);
                        }

                        if(temp->next == NULL)
                        {
                                break;
                        }

                        temp = temp->next;
                }
        }

        return 0;
}



/*****************************************************************
//
//  Function name:  printAllRecords
//
//  DESCRIPTION:    prints all records in database
//
//  Parameters:     rec (pointer to record) :
//
//  Return values:  none
//
****************************************************************/


void printAllRecords(struct record * rec)
{
        struct record * temp = rec;

        if(debugmode){
                printf("Function : printAllRecords(  )\n");
        }

        if(rec != NULL)
        {
                while(temp != NULL)
                {
                        if(temp->accountno > 0)
                        {
                                printf("{\n");
                                printf("%d\n", temp->accountno);
                                printf("%s", temp->name);
                                printf("%s", temp->address);
                                printf("}\n");
                        }

                        if(temp->next == NULL)
                        {
                                break;
                        }

                        temp = temp->next;
                }
        }
        else
        {
                printf("\nNo accounts stored\n");
        }

}



/*****************************************************************
//
//  Function name:  printRecord
//
//  DESCRIPTION:    prints one record
//
//  Parameters:     rec (pointer to record) : 
//                  num (int)
//
//  Return values:  0 : success
//
//                  other than 0 : failure
//
****************************************************************/


int printRecord(struct record * rec, int num)
{

        struct record * temp = rec;

        if(debugmode){
                printf("Function : printAllRecords(  )\n");
        }

        if(rec != NULL)
        {
                while(temp != NULL)
                {
                        if(temp->accountno == num)
                        {
                                printf("{\n");
                                printf("%d\n", temp->accountno);
                                printf("%s", temp->name);
                                printf("%s", temp->address);
                                printf("}\n");
                        }

                        if(temp->next == NULL)
                        {
                                break;
                        }

                        temp = temp->next;
                }
        }
        else
        {
                printf("\nNo accounts stored\n");
        }

        return 0;
}

