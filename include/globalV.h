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
//  FILE:           globalV.h
//
//  DESCRIPTION:    This file contains the global variable
//                  "debugmode" used to check if the program is
//                  in debug mode
//
****************************************************************/

/*
// include file for project 1
*/

#ifndef SHAREFILE_INCLUDED
#define SHAREFILE_INCLUDED
#ifdef MAIN_FILE
int debugmode;
#else
extern int debugmode;
#endif
#endif
