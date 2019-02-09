/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"
#include "math.h"
#include <stdio.h>

/*

 * Yusuf Can Kan - 161044007
 * I used math.h for taking absolute value for bisection method. ( function: root_find_between_2_values() ).

*/

double integral(double f(double x), double xs, double xe, double delta){/*Takes the integral between 2 range.*/
																		/*Finds the area which under the functions graphics.*/
	int i=0;
	double answer=0;
	
	/*It takes a small recktangle under the functian and it slides it.*/
	while(xs<xe){
		answer+=( f(xs)*delta );
		xs+=delta;
	}
	return answer;	
}

double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){ /*Takes the integral between 2 range.*/
																										  /*Finds the volume which under the functions graphics.*/
	int i,j;
	double answer;
	double ys_backup=ys;
	/*It takes a small rectangular parallelepiped under the functian and it slides it.*/
	while(xs<xe){
		while(ys<ye){
			answer+=(delta*delta) * f(xs,ys);
			ys+=delta;
		}
		ys=ys_backup;
		xs+=delta;
	}
	return answer;
}
/*Takes the derivatives of the function for any values.*/
int derivatives(double f(double a), double x, double eps, double *d1, double *d2){
	
	int answer;
	if(eps!=0){
	
		*d1= (f(x+eps) - f(x-eps)) / (2*eps); 
		*d2= (f(x+eps) - 2*f(x) + f(x-eps)) / (eps*eps);
		return 1;
		
	}
	else
		return -1;
}
/*Compares the derivatives values which real value and calculated value with above function.*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	
	double deriv1,deriv2;
	derivatives(f,x,eps,&deriv1,&deriv2);

	*e1= deriv1 - (d1(x));
	*e2= deriv2 - (d2(x));
	
	return 0;
}

/*	
	*Sorts the 2 values.
	*This function will help us when we found the first derivatives roots we have to sorts it from smaller value to bigger.
*/
void swap(double *a,double *b){

	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*This function finds a root between 2 values with bisection method.*/
double root_find_between_2_values(double f(double x),double value1,double value2){

	double left,right,mid;
	/*It values are same it means there is no root between them.*/
	if(f(value1)*f(value2) > 0){
		return -1;
	}
	/*This parts sorts the values for finding which part is left and which part is right side.*/
	if(value1 > value2){
		left=value2;
		right=value1;
	}
	else if(value2 > value1){
		left=value1;
		right=value2;
	}
	/*It turns until the range be smaller than 0.001*/
	while(fabs(f(left)-f(right))>0.001){
		mid=(left+right) / 2.0;
		
		if( f(mid) == 0 ){
			return mid;
		}
		else if(f(mid)*f(left) < 0){
			right=mid;
		}
		else if(f(mid)*f(right) < 0){
			left = mid;
		}
	}
	return (left+right)/2.0;
}

int root_find_end_values(double f(double x),double value1,double value2,double *root1,double *root2){
	double left,right,left_1,right_1;
	/*It finds which value is left side of graphic.*/
	if(value1 > value2){
		right = value1;
		right_1 = value1;
		left = value2;
		left_1 =value2;
	}
	else if(value2 > value1){
		right = value2;
		right_1 = value2;
		left = value1;
		left_1 = value1;
	}
	
	/*
		*It decreases or increases the value until the values sign is become the opposite.
		*After the value become the opposite it takes first value and other value and it find roots with bisection method which that function is above that.
	*/
	if(f(left)>0){
		while(f(left_1)>0){
			left_1-=0.05;
		}
		*root1=root_find_between_2_values(f,left,left_1);
	}
	else if(f(left)<0){
	
		while(f(left_1)<0){
			left_1-=0.05;
		}
		*root1=root_find_between_2_values(f,left,left_1);
	}
	/*It does the same thing for the right values.*/
	if(f(right)>0){
		while(f(right_1)>0){
			right_1+=0.05;
		}
		*root2=root_find_between_2_values(f,right,right_1);
	}
	else if(f(right)<0){
	
		while(f(right_1)<0){
			right_1+=0.05;
		}
		*root2=root_find_between_2_values(f,right,right_1);
	}
	return 0;
}

/*
 * If the function returns -1 it means function doesn't work  
 * One of the reasons may be that one of the root may be imaginery number or there is no real root.
 *
 * !!!!!!!!!!!!!!!   If all the roots are imaginery the function enters the infinite loop.Because function doesn't have any real roots.  !!!!!!!!!!!!!!!!!!!!!!
 *
*/

int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4){
	/*
	  *Assume that our function is ax^4 + bx^3 + cx^2 + d^x + e 
	  *f'(x)  =4ax^3 + 3bx^2 + 2cx + d
	  *f''(x) =12ax^2 + 6bx + 2c 
	*/
	double d_1,d_2;	
	double a,b,c,d,e;
	double d1_a=0,d1_b=0,d1_c=0,d1_d=0;		/*For first derivative.*/
	double d2_a=0,d2_b=0,d2_c=0;			/*For second derivative*/
	double delta;
	double d2_root1,d2_root2;
	double d1_root1,d1_root2,d1_root3;
	int control;
	
	derivatives(f,0,0.00001,&d_1,&d_2);
	
	e=f(0);   /*f(0) gives us e.*/
	d=d_1;	  /* f'(0) gives us d.*/
	c=d_2/2;	  /* f''(0) gives us 2c.*/
	
	/*f(1) + f(-1) = 2a + 2c + 2e   and we know c and e.*/
	a = ( (f(1)+f(-1)) / 2 ) - e - c;
	
	/*f(1) = a+b+c+d+e*/
	b = f(1) - a - c - d - e;
	
	
	/*If the function is dx+e*/
	if((a>= -0.0001 && a <= 0.0001) && (b>= -0.0001 && b <= 0.0001) && (c>= -0.0001 && c <= 0.0001)){
		*x1=(-1*e)/d;
		
		*x2=0;
		*x3=0;
		*x4=0;
		return 0;
	}
	/*If the function is cx^2+dx+e*/
	else if((a>= -0.0001 && a <= 0.0001) && (b>= -0.0001 && b <= 0.0001)){
		delta = d*d-4*c*e;
		/*
		 *It finds root with deltas help.
		 *b^2-4ac
		 *-b - root(delta)  / 2a
		 *-b + root(delta)  / 2a.
		*/
		if(delta>0){
			*x1=( (-1*d)+sqrt(delta) ) / (2*c);
			*x2=( (-1*d)-sqrt(delta) ) / (2*c);
			*x3=0;
			*x4=0;
			return 0;
		}
		else if(delta==0){
			*x1= (-1*d)/(2*c);
			*x2=0;
			*x3=0;
			*x4=0;
			return 0;
		}
		else if(delta<-1){
			*x1=0;
			*x2=0;
			*x3=0;
			*x4=0;
			return 0;
		}
	}
	/*If the function is bx^3+cx^2+dx+e*/
	else if(a>= -0.0001 && a <= 0.0001){
		/*First derivative*/
		d1_c = d;
		d1_b = 2*c;
		d1_a = 3*b;
		
		double d1(double x){return d1_a*x*x + d1_b*x + d1_c;}
		
		delta = d1_b*d1_b-4*d1_a*d1_c;
		
		if(delta>0){
			d1_root1=(-1*d1_b+sqrt(delta))/(2.0*d1_a);
			d1_root2=(-1*d1_b-sqrt(delta))/(2.0*d1_a);
		}
		else if(delta==0){
			d1_root1=(-1*d1_b+sqrt(delta))/(2.0*d1_a);
		}
		else if(delta<-1){
			return -1;
		}
	
		*x1 = root_find_between_2_values(f,d1_root1,d1_root2);

		/*İf function doesn't work it returns -1.*/
		if( !(f(d1_root1) > -0.000001 && f(d1_root1) < 0.000001) && d1_root1==-1 ){
			return -1;	
		}


		control=root_find_end_values(f,d1_root1,d1_root2,x2,x3);
		/*İf function doesn't work it returns -1.*/
		if(control == -1){
			return -1;
		}
		*x4=0;
		
		printf("%lf - %lf \n",*x1,f(*x1));
		printf("%lf - %lf \n",*x2,f(*x2));
		printf("%lf - %lf \n",*x3,f(*x3));
		return 0;
		
	}

	
	/*If the function is ax^4+bx^3+cx^2+dx+e*/
	else{
		/* 
		 *We have all coefficenf of our function. 
		 *It means we have function of first and second derivative.
		 
		*/	
		/*First derivative*/
		d1_d = d ;
		d1_c = 2*c;
		d1_b = 3*b;
		d1_a = 4*a;
		/*Second derivative*/
		d2_c = 2*c;
		d2_b = 6*b;
		d2_a = 12*a;
	
		double d1(double x){return d1_a*x*x*x + d1_b*x*x + d1_c*x + d1_d;}
		double d2(double x){return d2_a*x*x + d2_b*x + d2_c;}
	
		delta = d2_b*d2_b-4*d2_a*d2_c;
	

		if(delta>0){
			d2_root1=(-1*d2_b+sqrt(delta))/(2.0*d2_a);
			d2_root2=(-1*d2_b-sqrt(delta))/(2.0*d2_a);
		}
		else if(delta==0){
			d2_root1=(-1*d2_b+sqrt(delta))/(2.0*d2_a);
		}
		else if(delta<-1){
			return -1;
		}
		
		 /*
		 *Functions second derivatives roots gives us first derivatives equations local maximum and local minimum points.
		 *With using that values it finds the root between and near them with using bisection method.
		 *It uses root_find_end_values() function for near that points.
		 *It uses root_find_between_2_values for between local min and local max values.
		*/
	
	
		d1_root1 = root_find_between_2_values(d1,d2_root1,d2_root2);
	

		/*İf function doesn't work it returns -1.*/
		if( !(f(d1_root1) > -0.000001 && f(d1_root1) < 0.000001) && d1_root1==-1 ){
			return -1;	
		}


		control=root_find_end_values(d1,d2_root1,d2_root2,&d1_root2,&d1_root3);
		/*İf function doesn't work it returns -1.*/
		if(control == -1){
	
			return -1;
	
		}
		/*
		 *When it finds the functions first derivatives roots it sorts that for finding its places.
		 *(for finding which one is left which one is middle and which one is right).
		 *It uses swap() function for sorting.
		*/
	
		if(d1_root1 > d1_root2){
			swap(&d1_root1,&d1_root2);
		}
		if(d1_root2 > d1_root3){
			swap(&d1_root3,&d1_root2);
		}
		if(d1_root1 > d1_root3){
			swap(&d1_root1,&d1_root3);
		}
	
		/*
		 *The last part it calculates the main functions root with using first derivatives roots.
		*/
		*x1 = root_find_between_2_values(f,d1_root1,d1_root2);
		*x2 = root_find_between_2_values(f,d1_root2,d1_root3);
		control=root_find_end_values(f,d1_root1,d1_root3,x3,x4);

		return 0;
	}
}


