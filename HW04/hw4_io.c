/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_io.h"
#include <stdio.h>

/*

	Takes the values of functions.

*/
int read_polynomial3(double * a0, double * a1, double * a2, double * a3){

	printf("Enter A0:");
	scanf("%lf",a0);
	printf("Enter A1:");
	scanf("%lf",a1);
	printf("Enter A2:");
	scanf("%lf",a2);
	printf("Enter A3:");
	scanf("%lf",a3);

	return 0;
}
/*

	Takes the values of functions.

*/

int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){

	printf("Enter A0:");
	scanf("%lf",a0);
	printf("Enter A1:");
	scanf("%lf",a1);
	printf("Enter A2:");
	scanf("%lf",a2);
	printf("Enter A3:");
	scanf("%lf",a3);
	printf("Enter A4:");
	scanf("%lf",a4);

	return 0;
}

void write_polynomial3(double a0, double a1, double a2, double a3){
	
	write_polynomial4(a0,a1,a2,a3,0); /* Calls the other function and gives the last value 0.*/

}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4){

	double read[5]={a0,a1,a2,a3,a4};
	int start=4,count=0; /*Start:For calculating the number of zeros for first terms.  Count:Calculating for the first term of function.*/
	printf("\n");
	
	/*It calculates if the first values zero. If it is zero it passes the terms until the next value is not zero.*/
	while(read[start]==0){ 
		start--;	
	}
	
	/*It turns until value exist.*/
	while(start>0){ 
	
		/*If value is zero it prints '-' before the value and makes value positive.Otherwise it prints '+'.*/
		if(read[start]<0){ 
			printf("-");
			read[start]*=-1;
		}
		else if(read[start]>0 && count!=0){
			printf("+");
		}
		
		if(read[start]!=0){
			/*For the first number.*/
			if(count==0){
				/*It determines the situation of values equal to one.*/
				if(read[start] == 1){
				
					/*If number is 1x^1 it don't write ones.Otherwise it writes x 's upper numbers.*/
					if(start !=1){
						printf("x^%d",start);
					}
					else{
						printf("x");
					}
				}
				else{
					if(start !=1){
						printf("%.1lfx^%d",read[start],start);
					}
					else{
						printf("%.1lfx",read[start]);
					}
				}
			}
			/*For the other number.*/
			else if(count!=0 && start != 1){
				if(read[start] == 1){
					printf("x^%d",start);
				}
				else{
					printf("%.1lfx^%d",read[start],start);
				}
			}
			else if(count!=0 && start == 1){ /*If the number a x'1 it doesnt write 1.*/
				if(read[start] == 1){
					printf("x");
				}
				else{
					printf("%.1lfx",read[start]);
				}
			}
		}
		start--;
		count++;
	}
	/*Writes last terms of equation.*/
	if(read[0]>0 && read[0]!=0){
		printf("+%.1lf",read[0]);
	}
	else if(read[0]<0 && read[0]!=0){
		printf("%.1lf",read[0]);
	}
	printf("\n");
}





