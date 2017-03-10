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
//  FILE:           record.h
//
//  DESCRIPTION:    This file contains the struct "record"
//
****************************************************************/

/*
// include file for project 1
*/

struct record
{
    int                accountno;
    char               name[25];
    char               address[80];
    struct record*     next;
};
