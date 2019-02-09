/*Yusuf Can Kan - 161044007*/
#include<stdio.h>

int control(int arr[],char operations[],size_t arr_len);		/*
																 *It calculates the value with the operations. 
																 *It uses this function inside the find_operations function.
																*/

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int
current);

int main(){

	int arr[]={25,12,6,10,32,8};			/*Array*/
	char operations[5]="    ";				/*Operations string*/
	size_t arr_len=6;						/*array lenght*/
	int current=arr[0];						/*It assignes the first element of array to current variable.*/
	int expected_val=44;
	char *a;
	a=find_operations(arr,expected_val,operations,arr_len,1,current);

		printf("\nOperators:%s\n\n",operations);

	return 0;
}
char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int
current){

	int i=0;			/*Forf for loop.*/

	if(cursor < arr_len){				/*It calls itself until cursor comes last value.*/
	
		current += arr[cursor];			/*First it calculates the + operator.*/
		operations[cursor-1]='+';		/*It adds '+' to operations char current location. */
		find_operations(arr,expected_val,operations,arr_len,cursor+1,current);	/*It calls itselt recursively.*/
		current -= arr[cursor];			/*The situation which '+' does not fit, for doing other operations it takes the value which add above.*/
		
		if(expected_val == control(arr,operations,arr_len))	/*It checks the value with control function and calculates the value and if 
															  it is equal to expected value it does not do other operations. */
			return operations;
		else 										/*If it is not equal it deletes the current char.For here it is '+'.*/
			operations[cursor-1]=' ';
		
		current -= arr[cursor];			/*It calculates the '-' operation.*/
		operations[cursor-1]='-';		/*It adds '-' to operations char current location.*/
		find_operations(arr,expected_val,operations,arr_len,cursor+1,current);	/*It calls itselt recursively.*/
		current += arr[cursor];			/*The situation which '-' does not fit, for doing other operations it adds the value which takes above.*/
			
		if(expected_val == control(arr,operations,arr_len))/*It checks the value with control function and calculates the value and if 
															 it is equal to expected value it does not do other operations. */
			return operations;
		else 
			operations[cursor-1]=' ';			/*If it is not equal it deletes the current char.For here it is '+'.*/
		
		current *= arr[cursor];					/*It calculates the '*' operation.*/
		operations[cursor-1]='*';				/*It adds '*' to operations char current location.*/
		find_operations(arr,expected_val,operations,arr_len,cursor+1,current);	/*It calls itselt recursively.*/
		current /= arr[cursor];					/*The situation which '*' does not fit, for doing other operations it divides the value which multiple above.*/
			
		if(expected_val == control(arr,operations,arr_len))	/*It checks the value with control function and calculates the value and if 
															 it is equal to expected value it does not do other operations. */
			return operations;
		else 
			operations[cursor-1]=' ';					/*If it is not equal it deletes the current char.For here it is '+'.*/
	}
	else if(cursor == arr_len){				/*When cursor comes to last value it checks the answer true or not.*/
		if(operations[arr_len-2]==' '){		/*If operations arrays last value is equal to ' '(space character) it makes all string space character.*/
			for(i=0;i<arr_len-2;i++)
				operations[i]=' ';
			return operations;
		}
		
		if(current == expected_val)			/*If function reach the current value it returns operations array.*/
			return operations;
		else
			operations[cursor-2]=' ';
	}
	operations[arr_len-1]='\0';				/*Last it adds the '\0' character to string.*/
}

int control(int arr[],char operations[],size_t arr_len){/*
																 *It calculates the value with the operations. 
																 *It uses this function inside the find_operations function.
														*/
	int i=0,value=0;
	value=arr[0];				/*It assignes the value first element of array.*/
	
	for(i=0;i<arr_len-1;i++){		/*It does the calculations with looking the operations string.*/
		switch(operations[i]){
			case '+':
					value+=arr[i+1];
					break;
			case '-':
					value-=arr[i+1];
					break;
			case '*':
					value*=arr[i+1];
					break;
			default: 
					return 0;
		}
	}
	return value;				/*It returns the answer.*/
}

	













