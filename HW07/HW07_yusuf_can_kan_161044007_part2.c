/*Yusuf Can Kan - 161044007*/
#include<stdio.h>

void write_all_dates();   /*This function writes the dates which entered the user to input_date.txt file. */
void convert_date();	  /*This function converts the dates which inside the input_date.txt files*/

int main(){
	write_all_dates();
	convert_date();
	return 0;
}

void write_all_dates(){
	
	FILE *IPtr = fopen("input_date.txt","w");		/*Opens the input_date.txt files.*/
	
	int day,month,year;
	int day_end,month_end,year_end;
	int d,m,y;			/*day-month-year*/
	int condition=0;	
	char start_date[20];
	char end_date[20];
	char temp1[5],temp2[5];		/*For storing the '/ / /' characters.*/
	int day_count=30;
	
	printf("\nEnter a Start Date (dd/mm/yyyy):");
	scanf("%s",start_date);
	sscanf(start_date,"%d %c %d %c %d",&day,temp1,&month,temp2,&year); /*Takes the start date in the string.*/
	
	printf("\n\nEnter a End Date (dd/mm/yyyy):");
	scanf("%s",end_date);
	sscanf(end_date,"%d %c %d %c %d",&day_end,temp1,&month_end,temp2,&year_end);	/*Takes the end date in the string.*/
	
	if( (month == 4 || month == 6 || month == 9 || month == 11) && day>30 ){	/*It controls the dates is valid or invalid.*/
		printf("\nThis month has only 30 day..!!");
		condition = 1;
	}
	else if( (month == 1 || month == 3 || month == 5 || month == 7 || 
	          month == 8 || month == 10 || month == 12) && day>31 ){
		printf("\nThis month has only 31 day..!!");
		condition = 1;
	}
	else if( month == 2 && day>28 && year%4!=0 ){
		printf("\nThis month has only 28 day..!!");
		condition = 1;
	}
	else if( month == 2 && day>29 && year%4==0 ){
		printf("\nThis month has only 29 day..!!");
		condition = 1;
	}
	else if(day<=0 || month<=0 || day_end<0 || month_end<0 || month>12 || month_end>12){
		printf("\n\n Invalid Input!!");
		condition=1;
	}
	printf("\n Start Date: %d/%d/%d \n",day,month,year);				/*Prints the dates which entered.*/
	printf("\n End Date: %d/%d/%d \n",day_end,month_end,year_end);
	
	d=day;		/*It assignes the date and month for using the below loops.*/
	m=month;
		
	while(year <= year_end && condition == 0){/*Year loop.*/
		while(m <= 12 && condition == 0){	/*Month loop.*/
			if(m == 4 || m == 6 || m == 9 || m == 11) /*It assignes the valid month valid day.*/
				day_count=30;
			else if( m == 2 && year % 4 == 0)
				day_count=29;
			else if( m == 2 && year % 4 != 0)
				day_count=28;
			else 
				day_count=31;
			while(d <= day_count && condition == 0){/*Day loop.*/
				if(d >= day_end && m >= month_end && year >= year_end) /*If the day comes the end_date it stops.*/
					condition++;
				if(d<10)								/*It writes dates to file.*/
					fprintf(IPtr,"0%d/",d);
				else
					fprintf(IPtr,"%d/",d);
				if(m<10)
					fprintf(IPtr,"0%d/",m);
				else 
					fprintf(IPtr,"%d/",m);
					
				fprintf(IPtr,"%d\n",year);
				d++;		/*increases the day.*/
			}
			d=1;
			m++;	/*increases the mounth and makes the day 1.*/
		}
		m=1;
		year++;	/*increases the year and makes the month 1.*/
	}
	fclose(IPtr);	
}

void convert_date(){
	int d,m,y;				/*day-month-year*/
	char a,b;				/*For storing the '/ / /' caracters.*/
	char dates[100];
	int month_code[13]={0,0,3,2,5,0,3,5,1,4,6,2,4};		/*For calculating the day. It comes from Schwerdtfeger's method.*/
	int century_code[4]={0,5,3,1};						/*For calculating the day. It comes from Schwerdtfeger's method.*/
	int day;
	int century;
	int i;							/*For calculating the day.*/
	 
	
	FILE *IPtr = fopen("input_date.txt","r");			/*It opens the files.*/
	FILE *OPtr = fopen("new_date.txt","w");

	while(fgets(dates,100,IPtr) != NULL){
	
		sscanf(dates, "%d %c %d %c %d",&d,&a,&m,&b,&y);		/*It takes the dates.*/
		
		
		if(m >= 3){					/*This part for calculating the day. This method depends on a month so this part seperates month.*/
			century = y/100;		/*Calculates century.*/
			i = y - 100 * century;	/*i is going to use general formula below.*/
		}
		else if(m == 1 || m == 2){
			century = (y-1) / 100;			/*Calculates century.*/
			i = (y-1) - 100 * century;		/*i is going to use general formula below.*/	
		}
		day=d + 1+ month_code[m] + century_code[century%4] + i + ( i/4 ) ; /*Schwerdtfeger's method.*/
		day%=7; 
		if(day == 0)
			day=7;
								/*It writes the days*/
		switch(day){
			case 1:
					fprintf(OPtr,"Sunday");
					break;
			case 2:
					fprintf(OPtr,"Monday");
					break;
			case 3:
					fprintf(OPtr,"Tuesday");
					break;
			case 4:
					fprintf(OPtr,"Wednesday");
					break;
			case 5:
					fprintf(OPtr,"Thursday");
					break;
			case 6:
					fprintf(OPtr,"Friday");
					break;
			case 7:
					fprintf(OPtr,"Saturday");
					break;
		}					
										/*It writes the months.*/
		switch(m){
			case 1:
				fprintf(OPtr,",January");
				break;
			case 2:
				fprintf(OPtr,",February");
				break;
			case 3:
				fprintf(OPtr,",March");
				break;
			case 4:
				fprintf(OPtr,",April");
				break;
			case 5:
				fprintf(OPtr,",May");
				break;
			case 6:
				fprintf(OPtr,",June");
				break;
			case 7:
				fprintf(OPtr,",July");
				break;
			case 8:
				fprintf(OPtr,",August");
				break;
			case 9:
				fprintf(OPtr,",September");
				break;
			case 10:
				fprintf(OPtr,",October");
				break;
			case 11:
				fprintf(OPtr,",November");
				break;
			case 12:
				fprintf(OPtr,",December");
				break;
		}
		fprintf(OPtr," %d,%d\n",d,y);
	}
	
	fclose(IPtr);
	fclose(OPtr);
	
}
