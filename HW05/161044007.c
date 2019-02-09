/*
	 *Yusuf Can Kan
	 *161044007
*/
#include<stdio.h>
#include<stdlib.h>

typedef enum {
	white_man, black_man, white_king, black_king, empty
}piece;

typedef enum {
	white = 10, black = 20
}player;

void init_board(piece board[][8]); /* It initializes the first board. */
void display_board(piece board[][8]); /* It displays board. */
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p); /*
																				   *It moves pieces. 
																			       *Return Values:
																				   *-1:The player p is trying to move a piece that does not belong to him
																				   *-2: The move is not allowed.
 																				   *-n>=0: The move is allowed and it is executed with n of opponents pieces captured.
																				  */
																				  
void king_convert(piece board[][8]); /*It controls first and seventh row for if there is any pieces must convert king.*/
int capture_control(piece board[][8], int *from_x, int *from_y, player p); /*
																			*After the normal pieces move it checks that 
																		    *is there any capture move. If there is it does that and returns 1. 
																		    *Otherwise returns -1.
																		   */
																		    
int capture_king_control(piece board[][8],int *from_x,int *from_y,player p);/*
																			 *It does the same thing which capture_control function did.
																			 *But this function does that for king pieces.
																			*/
																			 
int move_control(piece board[][8],int from_x, int from_y, player p);/*
																						 *After the competitors move it controls that is there any mandatory moves or not.
																						 *If the choosen move is competible to that returns 1.
																						 *Otherwise it returns 0.
																						*/
int move_capture_control(piece board[][8],int from_x, int from_y,player p);/*It checks the normal pieces capture situation for move_control function.*/
int move_capture_king_control(piece board[][8],int from_x,int from_y,player p);/*It checks the king pieces capture situation for move_control function.*/
int check_end_of_game(piece board[][8]); /*It controls is the game end or not.*/
void init_sample2_board(piece board[][8]); /*It initializes the board for sample_game_2 funtion.*/
void sample_game_1(); /*Sample game 1.*/
void sample_game_2(); /*Sample game 2.*/

int main(){
	/*For convenience i created a menu.*/
	int choice=0;
	printf("\n\n1.Sample Game 1");
	printf("\n2.Sample Game 2");
	printf("\n       Choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:	sample_game_1();
				break;
		case 2:	sample_game_2();
				break;
		default:
				printf("Invalid Input....");
	}
	
	return 0;
}
/*İt initializes the board for beginning of the game.*/
void init_board(piece board[][8]){
	int i,j;
	int arr[8][8]={
		{4,4,4,4,4,4,4,4},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{4,4,4,4,4,4,4,4},
		{4,4,4,4,4,4,4,4},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{4,4,4,4,4,4,4,4}
	};
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(arr[i][j] == 0) board[i][j] = white_man;
			else if(arr[i][j] == 1) board[i][j] = black_man;
			else if(arr[i][j] == 4) board[i][j] = empty;
		}
	}
}
/*İt initializes the board for sample 2.*/
void init_sample2_board(piece board[][8]){
	int i,j;
	int arr[8][8]={
		{4,4,4,4,4,4,4,4},
		{4,4,1,1,1,1,4,4},
		{4,1,1,1,1,4,1,1},
		{1,1,1,4,4,1,4,1},
		{4,4,0,0,0,1,0,0},
		{0,0,0,0,0,4,0,0},
		{4,4,0,0,0,0,4,4},
		{4,4,4,4,4,4,4,4}
	};
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(arr[i][j] == 0) board[i][j] = white_man;
			else if(arr[i][j] == 1) board[i][j] = black_man;
			else if(arr[i][j] == 4) board[i][j] = empty;
		}
	}
}
/*It displays the board.*/
void display_board(piece board[][8]){
	int i,j;
	printf("\n");
	for(i=0;i<8;i++){
		printf(" ");
		for(j=0;j<8;j++){
			if(board[i][j] == white_man){
				printf("w");
			}
			else if(board[i][j] == black_man){
				printf("b");
			}
			else if(board[i][j] == white_king){
				printf("W");
			}
			else if(board[i][j] == black_king){
				printf("B");
			}
			else if(board[i][j] == empty){
				printf("-");
			}
		}
		printf("\n");
	}
	printf("\n");
}
/*It checks end of the game. It counts the pieces. If one of them is 0 it means the game is end.*/
int check_end_of_game(piece board[][8]){
	int w=0,b=0;
	int i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(board[i][j] == white_man || board[i][j] == white_king ) w++;
			else if(board[i][j] == black_man || board[i][j] == black_king ) b++;
		}
	}
	if(w==0) return black;
	else if(b==0) return white;
	else -1;
}
/*It plays sample game 2.*/
void sample_game_2(){

	piece board[8][8];
	init_sample2_board(board);
	display_board(board);

	move(board,1,5,1,4,white);
	move(board,1,3,1,5,black);
	move(board,3,4,3,3,white);
	move(board,5,4,3,4,black);
	move(board,3,3,1,3,white);
	move(board,2,1,0,1,black);
	move(board,3,5,3,4,white);
	move(board,1,5,3,5,black);
	move(board,3,4,3,3,white);
	move(board,3,2,3,4,black);
	move(board,6,5,5,5,white);
	move(board,5,7,5,4,black);
	move(board,6,4,4,4,white);
}
/*It plays end to end game. In the last it checks game is end or not.*/
void sample_game_1(){

	piece board[8][8];	
	init_board(board);
	display_board(board);
	
	move(board,0,5,0,4,white);
	move(board,3,2,3,3,black);
	move(board,1,5,1,4,white);
	move(board,4,2,4,3,black);
	move(board,7,5,7,4,white);
	move(board,2,2,2,3,black);
	move(board,1,4,1,3,white);
	move(board,1,2,1,4,black);
	move(board,0,4,2,4,white);
	move(board,5,2,5,3,black);
	move(board,2,5,1,5,white);
	move(board,5,1,5,2,black);
	move(board,2,0,4,0,white);
	move(board,5,3,5,4,black);
	move(board,4,0,4,2,white);
	move(board,5,2,5,3,black);
	move(board,6,4,6,3,white);
	move(board,5,3,7,3,black);
	move(board,5,5,5,4,white);
	move(board,6,2,6,3,black);
	move(board,4,5,4,4,white);
	move(board,7,7,7,4,black);
	move(board,5,4,5,3,white);
	move(board,6,3,4,3,black);
	move(board,2,6,2,5,white);
	move(board,5,1,6,1,black);
	move(board,5,6,5,5,white);
	move(board,0,2,0,3,black);
	move(board,5,5,5,4,white);
	move(board,7,4,4,4,black);
	move(board,6,5,5,5,white);
	move(board,4,7,3,7,black);
	move(board,1,6,1,5,white);
	move(board,3,7,3,5,black);
	move(board,2,5,2,4,white);
	move(board,0,7,1,7,black);
	move(board,2,4,3,4,white);
	move(board,3,3,3,5,black);
	move(board,1,5,2,5,white);
	move(board,3,5,1,5,black);
	if(check_end_of_game(board) == white){
		printf("White Win!\n");
	}
	else if(check_end_of_game(board) == black){
		printf("Black Win!\n");
	}
}
/*It looks the first and last row and it checks regular pieces for converting the king.*/
void king_convert(piece board[][8]){
	int i,j;
	for(i=0;i<8;i++){
		if(board[0][i] == white_man)
			board[0][i] = white_king;
		if(board[7][i] == black_man)
			board[7][i] = black_king;
	}
}
/*
	*After the normal pieces move it checks that 
	*is there any capture move. If there is it does that and returns 1. 
	*Otherwise returns -1.
*/
int capture_control(piece board[][8], int *from_x, int *from_y, player p){
	
	if(p == white){
		/*If there is capture on the left side it does that for white regular piece. */
		if( (board[*from_y][*from_x-1]==black_man || board[*from_y][*from_x-1]==black_king) && board[*from_y][*from_x-2] == empty && *from_x-2>=0){
			board[*from_y][*from_x-2] = white_man;
			board[*from_y][*from_x] = empty;
			board[*from_y][*from_x-1] = empty;
			*from_x-=2;
			display_board(board);
			return 1;
		}
		/*If there is capture on the right side it does that for white regular piece. */
		else if( (board[*from_y][*from_x+1]==black_man || board[*from_y][*from_x+1]==black_king) && board[*from_y][*from_x+2] == empty && *from_x+2<=7 ){
			board[*from_y][*from_x+2] = white_man;
			board[*from_y][*from_x] = empty;
			board[*from_y][*from_x+1] = empty;
			*from_x+=2;
			display_board(board);
			return 1;
		}
		/*If there is capture on the upper side it does that for white regular piece. */
		else if( (board[*from_y-1][*from_x]==black_man || board[*from_y-1][*from_x]==black_king) && board[*from_y-2][*from_x] == empty && *from_y-2>=0 ){
			board[*from_y-2][*from_x] = white_man;
			board[*from_y][*from_x] = empty;
			board[*from_y-1][*from_x] = empty;
			*from_y-=2;
			display_board(board);
			return 1;
		}
		else return -1;

	}
	else if(p == black){
		/*If there is capture on the left side it does that for black regular piece. */
		if( (board[*from_y][*from_x-1]==white_man || board[*from_y][*from_x-1]==white_king) && board[*from_y][*from_x-2] == empty && *from_x-2>=0 ){
			board[*from_y][*from_x-2] = black_man;
			board[*from_y][*from_x] = empty;
			board[*from_y][*from_x-1] = empty;
			*from_x-=2;
			display_board(board);
			return 1;
		}
		/*If there is capture on the right side it does that for black regular piece. */
		else if( (board[*from_y][*from_x+1]==white_man || board[*from_y][*from_x+1]==white_king) && board[*from_y][*from_x+2] == empty && *from_x+2<=7){
			board[*from_y][*from_x+2] = black_man;
			board[*from_y][*from_x] = empty;
			board[*from_y][*from_x+1] = empty;
			*from_x+=2;
			display_board(board);
			return 1;

		}
		/*If there is capture on the upper side it does that for black regular piece. */
		else if( (board[*from_y+1][*from_x]==white_man || board[*from_y+1][*from_x]==black_king) && board[*from_y+2][*from_x] == empty && *from_y+2<=7){
			board[*from_y+2][*from_x] = black_man;
			board[*from_y][*from_x] = empty;
			board[*from_y+1][*from_x] = empty;
			*from_y+=2;
			display_board(board);
			return 1;
		}
		else return -1;
	}
}

/*
	*It does the same thing which capture_control function did.
	*But this function does that for king pieces.
*/
int capture_king_control(piece board[][8],int *from_x,int *from_y,player p){
	int a;
	if(	p == white){
		/*It looks the right of the pieces for is there any capture pieces.*/
		a=*from_x+1;
		while(board[*from_y][a] != black_man && board[*from_y][a] != black_king && a<=7){	
			if(board[*from_y][a]==white_man || board[*from_y][a]==white_king) /*If is there any same color pieces it stops.*/
				a=8;
			a++;	
		}
		/*If is there any it does the move.*/
		if(a<7 && board[*from_y][a+1]==empty){
			board[*from_y][a+1] = white_king;
			board[*from_y][*from_x]=empty;
			board[*from_y][a] = empty;
			*from_x=a+1;
			display_board(board);
			return 1;
		}
		/*It looks the left of the pieces for is there any capture pieces.*/
		a=*from_x-1;
		while(board[*from_y][a] != black_man && board[*from_y][a] != black_king && a>=0){
			if(board[*from_y][a]==white_man || board[*from_y][a]==white_king) /*If is there any same color pieces it stops.*/
				a=-1; 
			a--;
		}
		/*If is there any it does the move.*/
		if(a>0 && board[*from_y][a-1]==empty){
			
			board[*from_y][a-1] = white_king;
			board[*from_y][*from_x]=empty;
			board[*from_y][a] = empty;
			*from_x=a-1;
			display_board(board);
			return 1;
		}
		/*It looks the down side of the pieces for is there any capture pieces.*/
		a=*from_y+1;
		while(board[a][*from_x] != black_man && board[a][*from_x] != black_king && a<=7){
			if(board[a][*from_x]==white_man || board[a][*from_x]==white_king)/*If is there any same color pieces it stops.*/
				a=8;
			a++;
		}
		/*If is there any it does the move.*/
		if(a<7 && board[a+1][*from_x]==empty){
			board[a+1][*from_x] = white_king;
			board[*from_y][*from_x]=empty;
			board[a][*from_x] = empty;
			*from_y=a+1;
			display_board(board);
			return 1;
		}
		/*It looks the upper side of the pieces for is there any capture pieces.*/
		a=*from_y-1;
		while(board[a][*from_x] != black_man && board[a][*from_x] != black_king && a>=0){
			
			if(board[a][*from_x]==white_man || board[a][*from_x]==white_king) /*If is there any same color pieces it stops.*/
				a=-2;
			a++;
		}
		/*If is there any it does the move.*/
		if(a>0 && board[a-1][*from_x]==empty){
			board[a-1][*from_x] = white_king;
			board[*from_y][*from_x]=empty;
			board[a][*from_x] = empty;
			*from_y=a-1;
			display_board(board);
			return 1;
		}
	}
	/*It does the same thing for the black_king pieces.*/
	else if(p == black){
		a=*from_x+1;
		while(board[*from_y][a] != white_man && board[*from_y][a] != white_king && a<=7){
			if(board[*from_y][a]==black_man || board[*from_y][a]==black_king)
				a=8;
			a++;
		}

		if(a<7 && board[*from_y][a+1]==empty){
			
			board[*from_y][a+1] = black_king;
			board[*from_y][*from_x]=empty;
			board[*from_y][a] = empty;
			*from_x=a+1;
			display_board(board);
			return 1;
		}
		a=*from_x-1;
		
		while(board[*from_y][a] != white_man && board[*from_y][a] != white_king && a>=0){
			if(board[*from_y][a]==black_man || board[*from_y][a]==black_king)
				a=-1;
			a--;
		}

		if(a>0 && board[*from_y][a-1]==empty){
			
			board[*from_y][a-1] = black_king;
			board[*from_y][*from_x]=empty;
			board[*from_y][a] = empty;
			*from_x=a-1;
			display_board(board);
			return 1;
		}
		a=*from_y+1;
		while(board[a][*from_x] != white_man && board[a][*from_x] != white_king && a<=7){
			if(board[a][*from_x]==black_man || board[a][*from_x]==black_king) a=8;
			a++;
		}

		if(a<7 && board[a+1][*from_x]==empty){
			
			board[a+1][*from_x] = black_king;
			board[*from_y][*from_x]=empty;
			board[a][*from_x] = empty;
			*from_y=a+1;
			display_board(board);
			return 1;
		}
		a=*from_y-1;
		while(board[a][*from_x] != white_man && board[a][*from_x] != white_king && a>=0){
			if(board[a][*from_x]==black_man || board[a][*from_x]==black_king) a=-2;
			a++;
		}

		if(a>0 && board[a-1][*from_x]==empty){
			
			board[a-1][*from_x] = black_king;
			board[*from_y][*from_x]=empty;
			board[a][*from_x] = empty;
			*from_y=a-1;
			display_board(board);
			return 1;
		}
	}
	return -1;	
}
/*It checks the normal pieces capture situation for move_control function.
 *If there is any it returns 1.
*/
int move_capture_control(piece board[][8],int from_x, int from_y,player p){
	/*It checks the around the pieces for capture for black and white pieces.*/
	if(p == white){
		if( (board[from_y][from_x-1]==black_man || board[from_y][from_x-1]==black_king) && board[from_y][from_x-2] == empty && from_x-2>-1 ) return 1;
		else if( (board[from_y][from_x+1]==black_man || board[from_y][from_x+1]==black_king) && board[from_y][from_x+2] == empty && from_x+2<8) return 1;
		else if( (board[from_y-1][from_x]==black_man || board[from_y-1][from_x]==black_king) && board[from_y-2][from_x] == empty && from_y-2>-1 ) return 1;
		else return -1;
	}
	else if(p == black){
		if( (board[from_y][from_x-1]==white_man || board[from_y][from_x-1]==white_king) && board[from_y][from_x-2] == empty && from_x-2>-1) return 1;
		else if( (board[from_y][from_x+1]==white_man || board[from_y][from_x+1]==white_king) && board[from_y][from_x+2] == empty && from_x+2<8) return 1;
		else if( (board[from_y+1][from_x]==white_man || board[from_y+1][from_x]==black_king) && board[from_y+2][from_x] == empty && from_y-2>-1) return 1;
		else return -1;
	}
	else return 0;
}
/*It checks the king pieces capture situation for move_control function.
 *If there is any it returns 1.
*/
int move_capture_king_control(piece board[][8],int from_x,int from_y,player p){
	int a;
	if(	p == white){
	    /*It checks the right side of the pieces.*/
		a=from_x+1;
		while(board[from_y][a] != black_man && board[from_y][a] != black_king && a<=7){
			if(board[from_y][a]==white_man || board[from_y][a]==white_king) a=8;
			a++;	
		}
		if(a<7 && board[from_y][a+1]==empty) return 1;
		/*It checks the left side of the pieces.*/
		a=from_x-1;
		while(board[from_y][a] != black_man && board[from_y][a] != black_king && a>=0){
			if(board[from_y][a]==white_man || board[from_y][a]==white_king) a=-1;
			a--;
		}
		if(a>0 && board[from_y][a-1]==empty) return 1;
		/*It checks the down side of the pieces.*/
		a=from_y+1;
		while(board[a][from_x] != black_man && board[a][from_x] != black_king && a<=7){
			if(board[a][from_x]==white_man || board[a][from_x]==white_king) a=8;
			a++;
		}
		if(a<7 && board[a+1][from_x]==empty) return 1;
		/*It checks the up side of the pieces.*/
		a=from_y-1;
		while(board[a][from_x] != black_man && board[a][from_x] != black_king && a>=0){
			if(board[a][from_x]==white_man || board[a][from_x]==white_king)a=-2;
			a++;
		}
		if(a>0 && board[a-1][from_x]==empty) return 1;
	}
	else if(p == black){
		/*It checks the right side of the pieces.*/
		a=from_x+1;
		while(board[from_y][a] != white_man && board[from_y][a] != white_king && a<=7){
			if(board[from_y][a]==black_man || board[from_y][a]==black_king)a=8;
			a++;
		}

		if(a<7 && board[from_y][a+1]==empty) return 1;
		/*It checks the left side of the pieces.*/
		a=from_x-1;
		while(board[from_y][a] != white_man && board[from_y][a] != white_king && a>=0){
			if(board[from_y][a]==black_man || board[from_y][a]==black_king) a=-1;
			a--;
		}
		if(a>0 && board[from_y][a-1]==empty) return 1;
		/*It checks the down side of the pieces.*/
		a=from_y+1;
		while(board[a][from_x] != white_man && board[a][from_x] != white_king && a<=7){
			if(board[a][from_x]==black_man || board[a][from_x]==black_king) a=8;
			a++;
		}
		if(a<7 && board[a+1][from_x]==empty) return 1;
		/*It checks the up side of the pieces.*/
		a=from_y-1;
		while(board[a][from_x] != white_man && board[a][from_x] != white_king && a>=0){
			if(board[a][from_x]==black_man || board[a][from_x]==black_king) a=-2;
			a++;
		}
		if(a>0 && board[a-1][from_x]==empty) return 1;
	}
	return 0;	
}
/*
	*After the competitors move it controls that is there any mandatory moves or not.
	*If the choosen move is competible to that returns 1.
	*Otherwise it returns 0.
*/
int move_control(piece board[][8],int from_x, int from_y, player p){
	int i,j;
	if(p==white){
		/* If the choosen pieces has capture situation it doesn't  looks the other pieces.*/
		if(board[from_y][from_x]==white_man && move_capture_control(board,from_x,from_y,p) == 1 ) return 1;
		else if(board[from_y][from_x]==white_king && move_capture_king_control(board,from_x,from_y,p) == 1 ) return 1;
		/*
		 *It looks all the pieces on the board. If one of them our pieces it returns 1.
		 *If there is any piece which has capture situation and it doesn't belong our piece it returns 0.
		*/
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(board[i][j]==white_man && move_capture_control(board,j,i,p) == 1 && (from_x==j && from_y==i) ) return 1;
				else if(board[i][j]==white_king && move_capture_king_control(board,j,i,p) == 1 && (from_x==j || from_y==i) ) return 1;
				if(board[i][j]==white_king && move_capture_king_control(board,j,i,p) == 1 && (from_x!=j || from_y!=i)) return 0;
				else if(board[i][j]==white_man && move_capture_control(board,j,i,p) == 1 && (from_x!=j || from_y!=i)) return 0;
			}
		}
		return 1;
	}
	else if(p==black){
		/* If the choosen pieces has capture situation it doesn't  looks the other pieces.*/
		if(board[from_y][from_x]==black_man && move_capture_control(board,from_x,from_y,p) == 1) return 1;
		else if(board[from_y][from_x]==black_king && move_capture_king_control(board,from_x,from_y,p) == 1 ) return 1;
		/*
		 *It looks all the pieces on the board. If one of them our pieces it returns 1.
		 *If there is any piece which has capture situation and it doesn't belong our piece it returns 0.
		*/
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(board[i][j]==black_man && move_capture_control(board,j,i,p) == 1 && (from_x==j && from_y==i) ) return 1;
				else if(board[i][j]==black_king && move_capture_king_control(board,j,i,p) == 1 && (from_x==j || from_y==i) ) return 1;
				if( board[i][j]==black_king && move_capture_king_control(board,j,i,p) == 1 && (from_x!=j || from_y!=i)) return 0;
				else if( board[i][j]==black_man && move_capture_control(board,j,i,p) == 1 && (from_x!=j || from_y!=i)) return 0;
			}
		}
		return 1;
	}
}
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	
	int capture=0,count=0;
	int control=0;
	int i,cap_index;
	king_convert(board);
	/*If there is mandatory move and our move doesn't that it returns -2.*/
	if(move_control(board,from_x,from_y,p) == 0){
		display_board(board);
		return -2;
	}
	/*If the user choose the coordinate which doesnt belong the board it returns -2.*/
	if(from_x < 0 || from_x > 7 || from_y < 0 || from_y > 7 || to_x <0 || to_x >7 ||  to_y <0 || to_y >7 ){
		display_board(board);
		return -2;
	}
	/*white regular piece situation.*/
	if(board[from_y][from_x] == white_man && p == white){
		/*If the move direction is backward it returns -2.*/
		if(to_y > from_y){
			display_board(board);
			return -2;
		}
		/*If the move does not has capture situation it controls that and it does that.*/
		if(  abs( (from_x+from_y) - (to_x+to_y) ) == 1){
			if(board[to_y][to_x] == empty){
				board[to_y][to_x] = white_man;
				board[from_y][from_x] = empty;
				king_convert(board);
			}
			else{
				display_board(board);
				return -2;
			}
		}
		/*If the move has capture situation.*/
		else if( abs( (from_x+from_y) - (to_x+to_y) ) == 2 ){
			/*If it is right side.*/
			if(to_x - from_x == -2){
				if( (board[from_y][from_x-1]==black_man || board[from_y][from_x-1]==black_king) && board[from_y][from_x-2] == empty ){
					
					board[to_y][to_x] = white_man;
					board[from_y][from_x] = empty;
					board[from_y][from_x-1] = empty;
					from_x-=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count = capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					display_board(board);	
					return -2;
				}
			}
			/*If it is left side.*/
			else if(to_x - from_x == 2){
				if( (board[from_y][from_x+1]==black_man || board[from_y][from_x+1]==black_king) && board[from_y][from_x+2] == empty ){
					board[from_y][from_x+2] = white_man;
					board[from_y][from_x] = empty;
					board[from_y][from_x+1] = empty;
					from_x+=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count = capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					display_board(board);
					return -2;
				}
			}
			/*If it is upper side.*/
			else if(to_y - from_y == -2){
				if( (board[from_y-1][from_x]==black_man || board[from_y-1][from_x]==black_king) && board[from_y-2][from_x] == empty ){
					board[from_y-2][from_x] = white_man;
					board[from_y][from_x] = empty;
					board[from_y-1][from_x] = empty;
					from_y-=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count += capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					display_board(board);
					return -2;
				}
			}
			else{
				display_board(board);
				return -2;
			}
		}
	}	
	else if(board[from_y][from_x] == black_man && p==black ){
		/*If the move direction is backward it returns -2. */
		if(to_y < from_y){
				display_board(board);
				return -2;
		}
		/*If the move does not has capture situation it controls that and it does that.*/
		if(  abs( (from_x+from_y) - (to_x+to_y) ) == 1){
			if(board[to_y][to_x] == empty){
				board[to_y][to_x] = black_man;
				board[from_y][from_x] = empty;
				king_convert(board);
			}
			else{
				display_board(board);
				return -2;
			}
		}
		/*If the move has capture situation.*/
		else if( abs( (from_x+from_y) - (to_x+to_y) ) == 2 ){
			/*If it is right side*/
			if(to_x - from_x == -2){
				if( (board[from_y][from_x-1]==white_man || board[from_y][from_x-1]==white_king) && board[from_y][from_x-2] == empty ){
					board[to_y][to_x] = black_man;
					board[from_y][from_x] = empty;
					board[from_y][from_x-1] = empty;
					from_x-=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count = capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					display_board(board);
					return -2;
				}
			}
			/*If it is left side*/
			else if(to_x - from_x == 2){
				if( (board[from_y][from_x+1]==white_man || board[from_y][from_x+1]==white_king) && board[from_y][from_x+2] == empty ){
					
					board[from_y][from_x+2] = black_man;
					board[from_y][from_x] = empty;
					board[from_y][from_x+1] = empty;
					from_x+=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count = capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					return -2;
				}
			}
			/*If it is down side*/
			else if(to_y - from_y == 2){
				if( (board[from_y+1][from_x]==white_man || board[from_y+1][from_x]==white_king) && board[from_y+2][from_x] == empty ){
					board[from_y+2][from_x] = black_man;
					board[from_y][from_x] = empty;
					board[from_y+1][from_x] = empty;
					from_y+=2;
					king_convert(board);
					display_board(board);
					capture++;
					/*After the move this loop controls that is there any other capture situation. If it is it does that until there is no left.*/
					while(count!=-1){
						count=0;
						count = capture_control(board,&from_x,&from_y,p);
						capture+=count;
						king_convert(board);
					}
					capture++;
				}
				else{
					return -2;
				}
			}
		}
		else{
			display_board(board);	
			return -2;
		}
	}
	/*For the white king*/
	else if(board[from_y][from_x] == white_king && p == white){
		/*If the move is cross it returns -2.*/
		if( abs(from_y-to_y)>0 && abs(from_x-to_x)>0 ){
			display_board(board);	
			return -2;
		}
		/* y axis situation.*/
		if(abs(from_y-to_y)>0 && abs(from_x-to_x) == 0){
			/*If the move is valid and upper side.*/
			if(from_y-to_y < 0 && board[to_y][to_x] == empty){
				for(i=from_y+1;i<=to_y;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[i][from_x] == white_man || board[i][from_x] == white_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the black pieces between the from and to coordinates.*/
					if(board[i][from_x] == black_man || board[i][from_x] == black_king) capture++;
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				/*If there is 1 or 0 piece it can move.*/
				else if(capture == 1 || capture == 0){
				/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=from_y+1;
						while(board[cap_index][to_x] != black_man && board[cap_index][to_x] != black_king ) cap_index++;

						board[cap_index][to_x] = empty;
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
			/*If the move is valid and down side.*/
			else if(from_y-to_y > 0 && board[to_y][to_x] == empty){
				for(i=to_y;i<=from_y-1;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[i][from_x] == white_man || board[i][from_x] == white_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the black pieces between the from and to coordinates.*/
					if(board[i][from_x] == black_man || board[i][from_x] == black_king) capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				/*If there is 1 or 0 piece it can move.*/
				else if(capture == 1 || capture == 0){
					/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=to_y;
						while(board[cap_index][to_x] != black_man && board[cap_index][to_x] != black_king ) cap_index++;
						board[cap_index][to_x] = empty;
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
					}
					else{
						display_board(board); 
						return -2;
					}
				}
			}
		}
		/*x axis situation*/
		else if(abs(from_y-to_y)==0 && abs(from_x-to_x) > 0){
		/*If the move is valid and right side.*/
			if(from_x-to_x < 0 && board[to_y][to_x] == empty){
				for(i=from_x+1;i<=to_x;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[from_y][i] == white_man || board[from_y][i] == white_king && capture == 0){
						display_board(board);	
						return -2;
					}
					/*It calculates the black pieces between the from and to coordinates.*/
					if(board[from_y][i] == black_man || board[from_y][i] == black_king) capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				/*If there is 1 or 0 piece it can move.*/
				else if(capture == 1 || capture == 0){
					/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=from_x+1;
						while(board[to_y][cap_index] != black_man && board[to_y][cap_index] != black_king ) cap_index++;
						board[to_y][cap_index] = empty;
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
					
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
			/*If the move is valid and left side.*/
			else if(from_x-to_x > 0 && board[to_y][to_x] == empty){
				for(i=to_x;i<=from_x-1;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[from_y][i] == white_man || board[from_y][i] == white_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the black pieces between the from and to coordinates.*/
					if(board[from_y][i] == black_man || board[from_y][i] == black_king) capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture !=1 && capture !=0){
					display_board(board);
					return -2;	
				}
				else if(capture == 1 || capture == 0){
					/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=to_x;
						while( board[to_y][cap_index] != black_man && board[to_y][cap_index] != black_king ) cap_index++;
						board[to_y][cap_index] = empty;
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
				
						board[to_y][to_x] = white_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
		}
		else{
			display_board(board);
			return -2;
		}
	}
	/*For the black king*/
	else if(board[from_y][from_x] == black_king && p == black){
		/*If the move is cross it returns -2.*/
		if( abs(from_y-to_y)>0 && abs(from_x-to_x)>0 ){
			display_board(board);	
			return -2;
		}
		/* y axis situation.*/
		if(abs(from_y-to_y)>0 && abs(from_x-to_x) == 0){
			/*If the move is valid and down side.*/
			if(from_y-to_y < 0 && board[to_y][to_x] == empty){
				for(i=from_y+1;i<=to_y;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[i][from_x] == black_man || board[i][from_x] == black_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the white pieces between the from and to coordinates.*/
					if(board[i][from_x] == white_man || board[i][from_x] == white_king)
						capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				else if(capture == 1 || capture == 0){
					/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=from_y+1;
						while(board[cap_index][to_x] != white_man && board[cap_index][to_x] != white_king ) cap_index++;
						board[cap_index][to_x] = empty;
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
							capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
			/*If the move is valid and up side.*/
			else if(from_y-to_y > 0 && board[to_y][to_x] == empty){
				for(i=to_y;i<=from_y-1;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[i][from_x] == black_man || board[i][from_x] == black_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the white pieces between the from and to coordinates.*/
					if(board[i][from_x] == white_man || board[i][from_x] == white_king) 
						capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				else if(capture == 1 || capture == 0){
				/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
					if(capture == 1){
						cap_index=to_y;
						while(board[cap_index][to_x] != white_man && board[cap_index][to_x] != white_king ) cap_index++;
						board[cap_index][to_x] = empty;
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_y=to_y;
						display_board(board);
					}
					else{
						display_board(board);	
						return -2;
					}
				}
			}
		}
		/*x axis situation*/
		else if(abs(from_y-to_y)==0 && abs(from_x-to_x) > 0){
			/*If the move is valid and right side.*/
			if(from_x-to_x < 0 && board[to_y][to_x] == empty){
				for(i=from_x+1;i<=to_x;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[from_y][i] == black_man || board[from_y][i] == black_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the white pieces between the from and to coordinates.*/
					if(board[from_y][i] == white_man || board[from_y][i] == white_king)
						capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture != 1 && capture !=0){
					display_board(board);
					return -2;	
				}
				/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
				else if(capture == 1 || capture == 0){
					if(capture == 1){
						cap_index=from_x+1;
						while(board[to_y][cap_index] != white_man && board[to_y][cap_index] != white_king ) cap_index++;
						board[to_y][cap_index] = empty;
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
			/*If the move is valid and left side.*/
			else if(from_x-to_x > 0 && board[to_y][to_x] == empty){
				for(i=to_x;i<=from_x-1;i++){
					/*If there is same color piece between the road it doesn't move.*/
					if(board[from_y][i] == black_man || board[from_y][i] == black_king && capture == 0){
						display_board(board);
						return -2;
					}
					/*It calculates the white pieces between the from and to coordinates.*/
					if(board[from_y][i] == white_man || board[from_y][i] == white_king) 
						capture++;	
				}
				/*If there is more than one piece it doesn't move.*/
				if(capture !=1 && capture !=0){
					display_board(board);
					return -2;	
				}
				/*If capture is 1 it does the move and controls around the piece is there any other capture situation or not.*/
				else if(capture == 1 || capture == 0){
					if(capture == 1){
						cap_index=to_x;
						while( board[to_y][cap_index] != white_man && board[to_y][cap_index] != white_king ) cap_index++;
						board[to_y][cap_index] = empty;
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
						/*Capture situations control loops.*/
						while(count!=-1){
							count=0;
							count = capture_king_control(board,&from_x,&from_y,p);
							capture+=count;
						}
						capture++;
					}
					/*If capture is 0 it does the move. */
					else if(capture == 0){
						board[to_y][to_x] = black_king;
						board[from_y][from_x] = empty;
						from_x=to_x;
						display_board(board);
					}
					else{
						display_board(board);
						return -2;
					}
				}
			}
		}
		else{
			display_board(board);	
			return -2;
		}
	}
	/*If the user pick the wrong piece it returns -1.*/
	else if(board[from_y][from_x] == black_man && p==white){
		display_board(board);
		return -1;
	}
	else if(board[from_y][from_x] == white_man && p==black){
		display_board(board);
		return -1;
	}
	else if(board[from_y][from_x] == white_king && p==black){
		display_board(board);
		return -1;
	}
	else if(board[from_y][from_x] == black_king && p==white){
		display_board(board);
		return -1;
	}
	else{
		display_board(board);
		return -2;
	}
	king_convert(board);
	display_board(board);
	check_end_of_game(board);
	return capture;
}


















