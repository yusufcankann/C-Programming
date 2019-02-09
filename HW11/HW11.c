
/*Yusuf Can Kan - 161044007*/

/*
 *I added the '!!!!!!!!!!' comment line some begining of lines. 
 *This lines means that if you want to test it for different values you must change it inside the code.
 *You can easily reach that line when you find the !!!!!!!! comment lines.
*/

/* For convenience i write the menu.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct customer{

	char name[20];
	char surname[20]; 
	int age;
	char gender[10];
	struct customer *next;

}customers;

typedef struct room{

	int number;
	int capacity; 
	int floor;
	struct customer *cPtr;
	struct room *next;

}rooms;

/*Function prototypes.*/
void add_room_to_end(rooms **Room,int number,int capacity,int floor);					
void add_room_after_room_number (rooms **Room,int number,int capacity,int floor,int after_number);
void add_customer_to_end(customers **Customer,char name[],char surname[],int age,char gender[]);
void link_customers_to_room(rooms **Room,int room_number,customers *Customer);
void remove_room (rooms *Room,int number);
void show_vacancy(rooms *Room);
void get_by_floor(rooms *Room,int floor);
void print_list (rooms *Room);

int main(){

	int choice=0; 				/*For menu function.*/
	int number,capacity,floor,age,i=0,after_number;
	char name[20],temp_surname[20],surname[20],gender[10];
	
	FILE *fPtr1,*fPtr2;
	customers *Customer=NULL;
	rooms *Room=NULL,*head_r=NULL;
	rooms *Room_back=Room; /*For remove function.*/
	
	customers *free_c;	/*for freeing the memory.*/
	rooms *free_r;
	
	fPtr1=fopen("rooms.txt","r");
	fPtr2=fopen("customers.txt","r");

/***************************************Bottom part initializes the files to the linked list***************************************/

	while(fscanf(fPtr1,"%d,%d,%d",&number,&capacity,&floor) != EOF)	/*This part adds the rooms to the linked list.*/
		add_room_to_end(&Room,number,capacity,floor);

	head_r=Room;	/*It stores the head of the linked list.*/
	
	while(fscanf(fPtr2,"%d,%s %s",&number,name,temp_surname) != EOF){ /*It takes every line from the customer.txt.*/
		/*The temp_surname string has surname ,age and gender.*/
		head_r=Room;
		
		while(temp_surname[i]!='\0'){ /*It makes the ',' to ' ' between the surname,age,gender.*/
			if(temp_surname[i]==',')
				temp_surname[i]=' ';
			i++;
		}
		i=0;
		/*Then it takes the surname , age and gender different variables. */
		sscanf(temp_surname,"%s %d %s",surname,&age,gender);
		
		/* It finds for customer to proper room. (With room numbers.) */
		while(head_r != NULL && head_r->number != number)
			head_r=head_r->next;
			
		if(head_r != NULL)
			add_customer_to_end( &(head_r->cPtr),name,surname,age,gender);
	}
	
/***************************************Upper part initializes the files to the linked list****************************************/

/* For convenience i write the menu.*/
/* For convenience i write the menu.*/
/* For convenience i write the menu.*/

	while(choice !=-1){
		printf("\n-----MENU-----");
		printf("\n\n1.add_room_to_end()");
		printf("\n2.add_room_after_room_number()");
		printf("\n3.add_customer_to_end()"); /*In this function I added the room 101.*/
		printf("\n4.link_customers_to_room()");
		printf("\n5.remove _room()");
		printf("\n6.show_vacancy()");
		printf("\n7.get_by_floor()");
		printf("\n8.print_list()");
		printf("\n-1.-> Quit");
		printf("\n\n			Choice:");
		scanf("%d",&choice);
	
		switch(choice){
			case 1:
					printf("\n\n   Enter the room number:");
					scanf("%d",&number);
					printf("\n   Enter the capacity:");
					scanf("%d",&capacity);
					printf("\n   Enter the floor:");
					scanf("%d",&floor);
					add_room_to_end(&Room,number,capacity,floor);
					printf("\n\nRoom has been added successfully!!");
					break;
			case 2:
					printf("\n\n   Enter the room number(Which you want to add after):");
					scanf("%d",&after_number);
					printf("\n   Enter the room number(Which you want to add):");
					scanf("%d",&number);
					printf("\n   Enter the capacity:");
					scanf("%d",&capacity);
					printf("\n   Enter the floor:");
					scanf("%d",&floor);
					add_room_after_room_number (&Room,number,capacity,floor,after_number);
					printf("\n\n   Room has been added successfully!!\n");
					break;
			case 3:	/*In this function I added the room 101.*/
					printf("\n\nIn this function I added the customer to the Room 101.You can change the room inside the menu function code.");
					printf("\n\n   Enter the customer name");
					scanf("%s",name);
					printf("\n   Enter the customer surname");
					scanf("%s",surname);
					printf("\n   Enter the customer age");
					scanf("%d",&age);
					printf("\n   Enter the customer gender");
					scanf("%s",gender);
				
/*!!!!!!!!!!!*/ 	/*
					 *If you can change the pointer (which is first variable) you can change the room. 
					 *For example if you can change it to Room->next->cPtr the room will be 102.
					 */
					add_customer_to_end( &(Room->cPtr),name,surname,age,gender);
					printf("\n\n   Customer has been added successfully!!");
					break;
			case 4:/*In this function I created the customer list inside the menu.*/
					printf("\n\nIn this function I created the customer list inside the menu function for convenience.You can change the list inside the menu function code.");
/*!!!!!!!!!!!*/		/*If you want to change the list which you want to add you can change it bottom side.*/

					customers *customer_list;
				
					customer_list=(customers*)malloc(sizeof(customers));
					
					sprintf(customer_list->name,"Mehmet");
					sprintf(customer_list->surname,"Yılmaz");
					customer_list->age=32;
					sprintf(customer_list->gender,"Male");
					
					customer_list->next=(customers*)malloc(sizeof(customers));
					
					sprintf(customer_list->next->name,"Ayşe");
					sprintf(customer_list->next->surname,"Gül");
					customer_list->next->age=22;
					sprintf(customer_list->next->gender,"Female");
					
					customer_list->next->next=(customers*)malloc(sizeof(customers));
						
					sprintf(customer_list->next->next->name,"Fatma");
					sprintf(customer_list->next->next->surname,"Çiçek");
					customer_list->next->next->age=30;
					sprintf(customer_list->next->next->gender,"Female");
				
					customer_list->next->next->next=NULL;
				
					printf("\n\n   Enter the room number:");
					scanf("%d",&number);
					link_customers_to_room(&Room,number,customer_list);
					printf("\n\n   Customer list has been added successfully to room %d",number);
					break;
			case 5:
					printf("\n\n   Enter the room number which you want to remove:");
					scanf("%d",&number);
					remove_room (Room,number);
					printf("\n\n   Room has been removed successfully!!");
					break;
			case 6:
					printf("\n\n");
					show_vacancy(Room);
					break;
			case 7:
					printf("\n\n   Enter the floor which you want to list:");
					scanf("%d",&floor);
					printf("\n\n");
					get_by_floor(Room,floor);
					break;
			case 8:
					print_list (Room);
					break;
			case -1:
					printf("\n\n		Exiting...\n\n");
					break;
			default:
					printf("\n\n   Invalid input!!");
		}
	}
	
	
	/*It frees the memory.*/
	free_r=Room->next;
	while(free_r != NULL){
		if(Room->cPtr != NULL){
			if (Room->cPtr->next == NULL)
				free(Room->cPtr);
			else{
				free_c = Room->cPtr->next;
				
				while (free_c != NULL){
					free(Room->cPtr);
					Room->cPtr = free_c;
					free_c=Room->cPtr->next;
				}
				free(Room->cPtr);
			}
		}
		free(Room);
		Room = free_r;
		free_r=Room->next;
	}
	free(Room);




	fclose(fPtr1);
	fclose(fPtr2);

	return 0;
}

/*This function adds the room to the end of the room list.*/
void add_room_to_end(rooms **Room,int number,int capacity,int floor){
	/*First it finds the end of the list recursively.*/
	if(*Room != NULL)							
		add_room_to_end( &((*Room)->next),number,capacity,floor);

	else if(*Room == NULL){
		*Room=(rooms*)malloc(sizeof(rooms));
		(*Room)->number=number;
		(*Room)->capacity = capacity;
		(*Room)->floor = floor;
		(*Room)->next = NULL;
		(*Room)->cPtr = NULL;
	}
}

/*This function adds the room to the given room number.*/
void add_room_after_room_number (rooms **Room,int number,int capacity,int floor,int after_number){
	/*First it finds the room recursively.*/
	if( (*Room) != NULL && (*Room)->number != after_number)
		add_room_after_room_number (&((*Room)->next),number,capacity,floor,after_number);
	else{
		/*If the choosen room does not exits it adds the room to end of the list.*/
		if((*Room) == NULL){
			*Room=(rooms*)malloc(sizeof(rooms));
			(*Room)->number=number;
			(*Room)->capacity = capacity;
			(*Room)->floor = floor;
			(*Room)->next = NULL;
		}
		else if( (*Room) != NULL && (*Room)->number == after_number){
			rooms *add_room;
			add_room = (rooms*)malloc(sizeof(rooms));
			(add_room)->number=number;
			(add_room)->capacity = capacity;
			(add_room)->floor = floor;
			(add_room)->cPtr = NULL;
			(add_room)->next = (*Room)->next;
			(*Room)->next = (add_room);
		}
	}
}

/*It adds the customer to the end of a partial customer list. */
void add_customer_to_end(customers **Customer,char name[],char surname[],int age,char gender[]){
	/*First it finds the end of the customer list recursively.*/
	if(*Customer != NULL)
		add_customer_to_end( &((*Customer)->next),name,surname,age,gender);
		
	else if(*Customer == NULL){
		*Customer=(customers*)malloc(sizeof(customers));
		sprintf( (*Customer)->name,"%s",name);
		sprintf( (*Customer)->surname,"%s",surname);
		(*Customer)->age = age;
		sprintf( (*Customer)->gender,"%s",gender);
		(*Customer)->next=NULL;
	}
}

/*It adds partial customer list to a room.*/
void link_customers_to_room(rooms **Room,int room_number,customers *Customer){
	/*First it finds the room revursively.*/
	if((*Room) != NULL && (*Room)->number != room_number)
		link_customers_to_room( &((*Room)->next),room_number,Customer);
	else if((*Room) == NULL)
		printf("\nThere is no room %d",room_number);
	else 
		(*Room)->cPtr = Customer;
}
/*It removes the room.*/
void remove_room (rooms *Room,int number){
	if(Room->number == number)
		Room = Room -> next;
	else if(Room->next!=NULL && Room->next->number != number)
		remove_room (Room->next,number);
	else if(Room->next==NULL)
		printf("\nThere is no room %d",number);
	else if(Room->next->number == number)
		Room->next = Room->next->next;
}

/*It showes the empty room recursively..*/
void show_vacancy(rooms *Room){
	if(Room->cPtr == NULL)
		printf("Room:%d (Floor: %d,Capacity: %d)\n",Room->number,Room->floor,Room->capacity);
	if(Room->next !=NULL)
		show_vacancy(Room->next);
}

/*It prints the room which in the given floor.*/
void get_by_floor(rooms *Room,int floor){
	if(Room->floor == floor)
		printf("Room:%d (Floor: %d-Capacity: %d)\n",Room->number,Room->floor,Room->capacity);
	if(Room->next !=NULL)
		get_by_floor(Room->next,floor);
}

/*It prints the all rooms and customers.*/
void print_list (rooms *Room){
	printf("Room:%d (Floor: %d,Capacity: %d):\n",Room->number,Room->floor,Room->capacity);
	if(Room->cPtr != NULL){
		customers *iter;
		iter=Room->cPtr;
		while(iter != NULL){
			printf("->%s %s(%d-%s)\n",iter->name,iter->surname,iter->age,iter->gender);
			iter=iter->next;
		}
		printf("\n");
	}
	else
		printf("->Empty\n\n");

	if(Room->next !=NULL)
		print_list (Room->next);	/*It call itselves recursivelt until end of the list.*/
}




