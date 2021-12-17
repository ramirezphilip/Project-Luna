#include "luna.h"

//This function calculates how many days have passed between the base date (01/01/2000) and the user inputted date -1. We use the input year- 1 because whatever the inputted date is doesnt necessarily count as a full year yet. -Isabella
			
int pastYearstoDaysCalc(struct lunaDate* theDate){
	int counting;
	int leapcount=0;
	int nonleapcount=0;
	for(counting=2000; counting <= ((theDate->year)-1); counting++){
		if (((counting % 4 == 0) && (counting % 100 != 0)) || (counting%400 == 0)){
			leapcount++;}
		else{
			nonleapcount++;}
		}
	return (leapcount*366) + (nonleapcount*365);
}

//This function will determine whether or not the user inputted year is a leap year or not. -Isabella 

int isitaLeapYear(struct lunaDate* theDate){
	if (((theDate->year % 4 == 0) && (theDate->year % 100 != 0)) || (theDate->year%400 == 0)){
		return 1;}
	  else{
		return 0;}
}

//This function will convert months to days for a non leap year. -Philip
int monthstoDays(struct lunaDate* theDate){
	switch((theDate->month)){
		case 01:
			return (theDate->day);
			break;
		case 02: 
			return (theDate->day) + 31;
			break;
		case 03:
			return (theDate->day) + 59;
			break;
		case 04:
			return (theDate->day) + 90;
			break;
		case 05:
			return (theDate->day) + 120;
			break;
		case 06:
			return (theDate->day) + 151;
			break;
		case 07:
			return (theDate->day) + 181;
			break;
		case 8: 
			return (theDate->day) + 212;
			break;
		case 9: 
			return (theDate->day) + 243;
			break;
		case 10:
			return (theDate->day) + 273;
			break;
		case 11:
			return (theDate->day) + 304;
			break;
		case 12: 
			return (theDate->day) + 334;
			break;
		default:
			return 0;
			printf("Invalid Date.\n");
		}
}

//This function will convert months to days for a leap year. -Philip

int monthstoDaysleap(struct lunaDate* theDate){
	switch((theDate->month)){
		case 01:
			return (theDate->day);
			break;
		case 02: 
			return (theDate->day) + 31;
			break;
		case 03:
			return (theDate->day) + 60;
			break;
		case 04:
			return (theDate->day) + 91;
			break;
		case 05:
			return (theDate->day) + 122;
			break;
		case 06:
			return (theDate->day) + 152;
			break;
		case 07:
			return (theDate->day) + 182;
			break;
		case 8:
			return (theDate->day) + 213;
			break;
		case 9:
			return (theDate->day) + 244;
			break;
		case 10:
			return (theDate->day) + 274;
			break;
		case 11:
			return (theDate->day) + 305;
			break;
		case 12:
			return (theDate->day) + 335;
			break;
		default:
			return 0;
			printf("Invalid Date.\n");
	}
}
//This function will add together the days from the past year conversion and the current year conversion. -Isabella
int totaldaysYAY(struct lunaDate* theDate){
	isitaLeapYear(theDate); 
	if (isitaLeapYear(theDate)==1 ){
		return monthstoDays(theDate)+ pastYearstoDaysCalc(theDate);}
	else{
		return monthstoDaysleap(theDate)+ pastYearstoDaysCalc(theDate);}    
}


//This function will determine, using the moldulus operator and the total days since 2000, where the remainder relates to the moonphase and thus tell the user what phase the moon will be in. -Philip	
void moonphase(lunastage){
	if(lunastage>=0 && lunastage <=1){
		printf("On your inputted date, there will be a new moon!\n");}
        else if(lunastage>1 && lunastage<=7){
	        printf("On your inputted date, there will be a waxing crescent!\n");}
	else if(lunastage>7 && lunastage<=8){
		printf("On your inputted date, there will be a waxing quarter!\n");}
	else if(lunastage>8 && lunastage<=15){
		printf("On your inputted date, there will be a waxing gibbous!\n");}
	else if(lunastage>15 && lunastage<=16){
		printf("On your inputted date, there will be a full moon!\n");}
	else if(lunastage>16 && lunastage<=22){
		printf("On your inputted date, there will be a waning gibbous!\n");}
	else if(lunastage>22 && lunastage<=23){
		printf("On your inputted date, there will be a waning quarter!\n");}
	else if(lunastage>23 && lunastage<=28){
		printf("On your inputted date, there will be a waning crescent!\n");}
	else{
		printf("Something went wrong :(");}
}
//This function is the utlization of all our functions. -Isabella & Philip
int running(){   
	struct lunaDate* theDate = (struct lunaDate*) malloc(sizeof(struct lunaDate));       
	printf("Enter a date in the future in MM/DD/YYYY: ");
	scanf("%02u/%02u/%04u", &(theDate->month), &(theDate->day), &(theDate->year));

	pastYearstoDaysCalc(theDate); 
	int lunastage = totaldaysYAY(theDate) % 28;

       	moonphase(lunastage);
	return 0;
}









			
