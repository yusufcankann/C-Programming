/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
void printf_digit(int count,int denominator,int number);
int main(){

	int number;
	int temp;
	int count=0;
	int i=0,j=0;
	int denominator=1;
	
	printf("Enter the number:");
	scanf("%d",&number);
	temp = number;
	/*
	 *Calculates the number has how many digits.
	 *Calculates denominator for dividing the number tens floors.
	 *Controls the numbers range.
	 */
	if(number>=23 && number<=98760){
		while(temp>0){
			temp/=10;
			count++;
			denominator*=10;	
		}
	}
	else{
		printf("Not in range!!!\n");
	}
	denominator/=10;
	printf_digit(count,denominator,number);
	return 0;
}
/*
 *Prints digits.
*/
void printf_digit(int count,int denominator,int number){
	int i;
	for(i=count;i>0;i--){
	
		if(i==5){
			printf("\n\nThe fifth digit is %d",number / denominator);
			/*Decreases the number for accessing next digit.*/
			number-=(denominator*(number / denominator));
			/*Using for dividing number to 10000.*/
			denominator /=10; 
		}
		else if(i==4){
			printf("\nThe fourth digit is %d",number / denominator);
			number-=(denominator*(number / denominator));
			denominator /=10;
		}
		else if(i==3){
			printf("\nThe third digit is %d",number / denominator);
			number-=(denominator*(number / denominator));
			denominator /=10;
		}
		else if(i==2){
			printf("\nThe second digit is %d",number / denominator);
			number-=(denominator*(number / denominator));
			denominator /=10;
		}
		else if(i==1){
			printf("\nThe first digit is %d\n\n",number / denominator);
			number-=(denominator*(number / denominator));
			denominator /=10;
		}
	}

}
