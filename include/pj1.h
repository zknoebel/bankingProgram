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
//  FILE:           pj1.h
//
//  DESCRIPTION:    This file contains function prototypes for
//                  project 1
//
****************************************************************/

/*
// include file for project 1
*/

int addRecord (struct record **, int, char [ ],char [ ]);
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [ ]); /* This should modify the address field */
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);

void print1(struct record **);
void print2();
void print3();
void print4();
void print5();
void print6();
void print7();
void printMenu();
void printDefault();
void printError();

void getaddress(char [], int);
