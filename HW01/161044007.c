/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
#include<math.h>
#define PI 3.14

double circle_area(double radius);									/*Prototypes*/
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(
	double largest_circle,
	double largest_square,
	double smallest_circle,
	double smallest_square
);

int main(){
	
	double side1,side2;
	
	printf("Enter first Side for rectangle:");
	scanf("%lf",&side1);
	printf("Enter second side for rectangle:");
	scanf("%lf",&side2);
	
	display_results(calc_area_of_largest_circle(side1,side2),
		calc_area_of_largest_square(side1,side2),
		calc_area_of_smallest_circle(side1,side2),
		calc_area_of_smallest_square(side1,side2));
	
	return 0;
}

double circle_area(double radius){			/*  Uses the formula which is pi*r^2    */
	double area;										
	area=(PI*(pow(radius,2)));
	return area;
}

double calc_hypotenuse(int side1, int side2){ 			 /*  Uses hypotenuse theorem which is c^2= a^2 + b^2.  */
	double side3;
	side3=sqrt( (pow(side1,2)) + (pow(side2,2)) );
	return side3;
}

/*The smallest circles radius must be half of the hypotenuse which finds with side1 and side2.*/
double calc_radius_of_smallest_circle(int side1, int side2){		
	double radius;
	radius=calc_hypotenuse(side1,side2);
	radius=radius/2;
	return radius;
}

double calc_radius_of_largest_circle(int side1, int side2){			/*The largest circles radius must be half of the smallest side.*/
	double radius;
	if(side1>=side2){
		radius=(double)side2/2;
	}
	else{
		radius=(double)side1/2;
	}
	return radius;
}

double calc_area_of_smallest_circle(int side1, int side2){			/*Calculates the smallest circles area with radius of the smallest circle.*/
	double area;
	area = circle_area(calc_radius_of_smallest_circle(side1,side2));
	return area;
}

double calc_area_of_largest_circle(int side1, int side2){			/*Calculates the largest circles with radius of the largest circle.*/
	double area;
	area = circle_area(calc_radius_of_largest_circle(side1,side2));
	return area;
}

/*The squares side must be the largest side of the rectangle since if we choose the smallest side rectangle doesn't surrouns the recrangle.*/
double calc_area_of_smallest_square(int side1, int side2){		
	double area;
	if(side1>=side2){
		area=calc_area_of_square (side1);
	}
	else{
		area=calc_area_of_square (side2);
	}
	return area;
}

/*The squares side must be the smallest side of the rectangle since if we choose the largest side square and rectangle intersect with each other.*/
double calc_area_of_largest_square(int side1, int side2){
	double area;
	if(side1>=side2){
		area=calc_area_of_square (side2);
	}
	else{
		area=calc_area_of_square (side1);
	}
	return area;
}

double calc_area_of_square (int side){  /*Area of square = a^2. */
	double area;
	area = pow(side,2);
	return area;
}

void display_results(double largest_circle,
	double largest_square,
	double smallest_circle,
	double smallest_square){
	
	printf("The area of the largest circle that fits inside a rectangle:%20.2lf",largest_circle);
	printf("\nThe area of the largest square that fits inside the rectangle:%18.2lf",largest_square);
	printf("\nThe area of the smallest circle that surrounds the same rectangle:%15.2lf",smallest_circle);
	printf("\nThe area of the smallest square that surrounds the same rectangle:%15.2lf\n\n",smallest_square);
}
