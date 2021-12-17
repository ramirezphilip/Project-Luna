#ifndef LUNA_H
#define LUNA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int running();
int pastYearstoDaysCalc(); 
int finalmonthstoDays;
int monthstoDays();
int monthstoDaysleap();
int isitaLeapYear();
int totaldaysYAY();
int LunaProject();

void moonphase();
int lunastage;
float lunarvar;

struct lunaDate {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

#endif /*LUNA_H*/
