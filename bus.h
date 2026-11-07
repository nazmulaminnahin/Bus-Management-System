#ifndef BUS_H
#define BUS_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

// Global variables declaration (extern so they can be shared across files)
extern char user[20];
extern char pass[20];
extern char ch[10][130];
extern char name[32][100];
extern char number[32][2];
extern int num1[32];
extern int trno;

// Function prototypes
void login();
void reset_password();
void bus();
void name_number(int booking, char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();

#endif