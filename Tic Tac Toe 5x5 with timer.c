#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

char p1=' ',p2=' ',p3=' ',p4=' ',p5=' ';
char p6=' ',p7=' ',p8=' ',p9=' ',p10=' ';
char p11=' ',p12=' ',p13=' ',p14=' ',p15=' ';
char p16=' ',p17=' ',p18=' ',p19=' ',p20=' ';
char p21=' ',p22=' ',p23=' ',p24=' ',p25=' ';

char check[25] = "abcdefghijklmnopqrstuvwxy" ;

int scorep1 = 0, scorep2 = 0;
char rematch = 'N';

void Board(){

	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\t\t\tLeaderBoard\n",p1,p2,p3,p4,p5);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\t\t\tPlayer 1 = %d\n",p6,p7,p8,p9,p10, scorep1);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\t\t\tPlayer 2 = %d\n",p11,p12,p13,p14,p15, scorep2);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p16,p17,p18,p19,p20);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p21,p22,p23,p24,p25);

}

char Position(int pos, int p, char cp1 , char cp2);

void main(){
	int pos,p, i, counter;
	char win = 'D',cp1,cp2;
	
	do{
		p1 = ' ' ,p2 = ' ' ,p3 = ' ' ,p4 = ' ' ,p5 = ' ';
		p6 = ' ' ,p7 = ' ' ,p8 = ' ' ,p9 = ' ' ,p10 = ' ';
		p11 = ' ' ,p12 = ' ' ,p13 = ' ' ,p14 = ' ' ,p15 = ' ';
		p16 = ' ' ,p17 = ' ' ,p18 = ' ' ,p19 = ' ' ,p20 = ' ';
		p21 = ' ' ,p22 = ' ' ,p23 = ' ' ,p24 = ' ' ,p25 = ' ';
		check[25] = "abcdefghijklmnopqrstuvwxy";
		win = 'D';
		counter = 9;
		system("color E");
		printf("Player 1: Enter Your Marker X/O\n");
		scanf(" %c",&cp1);
		
		while(cp1 != 'X')
		{
			if(cp1 == 'O')
			{
				break;
			}
			printf("ERROR Enter again\nPlayer 1: Enter Your Marker X/O\n");
			scanf(" %c",&cp1);
		}
		
		system("cls");
		
		if (cp1 == 'X'){
			cp2 = 'O';
		}
		else cp2 = 'X';
		
		Board();
		
		for (i=1;i<=25;i++)
		{
			if (i%2 == 0){
				printf("\n\nPLAYER 2 TURN (%c)\n",cp2);
				p = 2;
			}
			else
			{
				printf("\n\nPLAYER 1 TURN (%c)\n",cp1);
				p = 1;
			}
		
			printf("At Which Position (1-25) Do You Want To Place Your Marker.\n");
			while(counter != 0)
			{
				
				printf("\rTime left = %ds", counter);
				sleep(1);
				counter--;
				if(kbhit())
				{
					printf("\n");	
					scanf("%d",&pos);
					while((pos < 1 && pos > 25) && (check[pos-1] == 'X' && check[pos-1] == 'O')) 
				    	{
				    		printf("ERROR, position number must EMPTY and between 1 & 25 inclusive.\n");
						printf("At Which Position (1-25) Do You Want To Place Your Marker.\n");	    	
				   	 	scanf("%d",&pos);	
					}
					break;
				}
			}
			if(counter == 0)
			{
				if (i%2 == 0)
				{
					printf("\n\nPLAYER 2 (%c) JUST LOST HIS/HER TURN!\n\a",cp2);
					p = 2;
				}
				else
				{
					printf("\n\nPLAYER 1 (%c) JUST LOST HIS/HER TURN!\n\a",cp1);
					p = 1;
				}
			}
			else
			{
				Position(pos,p,cp1,cp2);	
			}
			counter = 9;
			
			if (check[0] == check[1] && check[0] == check[2] && check[0] == check[4] && check[0] == check[3] ){
		    	win = check[0];
		    	break;
			}
			else if (check[0] == check[5] && check[0] == check[10]  && check[0] == check[15]  && check[0] == check[20]){
				win = check[0];
		    	break;
			}
			else if (check[5] == check[6] && check[5] == check[7]  && check[5] == check[8]  && check[5] == check[9] ){
				win = check[5];
		    	break;
			}
			else if (check[10] == check[11] && check[10] == check[12]  && check[10] == check[13]  && check[10] == check[14]){
				win = check[10];
		    	break;
			}
			else if (check[15] == check[16] && check[15] == check[17]  && check[15] == check[18] && check[15] == check[19]) {
				win = check[0];
		    	break;
			}
			else if (check[20] == check[21] && check[20] == check[22]  && check[20] == check[23]  && check[20] == check[24]){
				win = check[20];
		    	break;
			}
			else if (check[1] == check[6] && check[1] == check[11]  && check[1] == check[16]  && check[1] == check[21]){
				win = check[1];
		    	break;
			}
			else if (check[2] == check[7] && check[2] == check[12]  && check[2] == check[17]  && check[2] == check[22]){
				win = check[2];
		    	break;
			}
			else if (check[3] == check[8] && check[3] == check[13]  && check[3] == check[18]  && check[3] == check[23] ){
				win = check[3];
		    	break;
			}
			else if (check[4] == check[9] && check[4] == check[14]  && check[4] == check[19]  && check[4] == check[24] ){
				win = check[3];
		    	break;
			}
			else if (check[0] == check[6] && check[0] == check[12]  && check[0] == check[18]  && check[0] == check[24] ){
				win = check[0];
		    	break;
			}
			else if (check[4] == check[8] && check[4] == check[12]  && check[4] == check[16]  && check[4] == check[20] ){
				win = check[0];
		    	break;
			}
		}
			if (win == cp1)
			{
				printf("\n\n\nPLAYER 1 WINS !!!\n");
				scorep1++;
			}
			else if (win == cp2)
			{
				printf("\n\n\nPLAYER 2 WINS !!!\n");
				scorep2++;
			}
			else
			{
				printf("IT'S A DRAW !!!\n");
			} 
			printf("REMATCH [Y/N]?\n");
			scanf(" %c", &rematch);
			system("cls");
		}while(rematch == 'Y' || rematch == 'y');
}

char Position(int pos, int p, char cp1 , char cp2){
	char temp;
	switch (pos){
		case 1:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p1 = temp;
			check[0] = temp;
			system("cls");
			Board();
			break;
		case 2:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p2 = temp;
			check[1] = temp;
			system("cls");
			Board();
		break;
		case 3:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p3 = temp;
			check[2] = temp;
			system("cls");
			Board();
		break;
		case 4:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p4 = temp;
			check[3] = temp;
			system("cls");
			Board();
		break;
		case 5:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p5 = temp;
			check[4] = temp;
			system("cls");
			Board();
		break;
		case 6:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p6 = temp;
			check[5] = temp;
			system("cls");
			Board();
		break;
		case 7:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p7 = temp;
			check[6] = temp;
			system("cls");
			Board();
		break;
		case 8:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p8 = temp;
			check[7] = temp;
			system("cls");
			Board();
		break;
		case 9:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p9 = temp;
			check[8] = temp;
			system("cls");
			Board();
		break;
		case 10:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p10 = temp;
			check[9] = temp;
			system("cls");
			Board();
		break;
		case 11:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p11 = temp;
			check[10] = temp;
			system("cls");
			Board();
		break;
		case 12:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p12 = temp;
			check[11] = temp;
			system("cls");
			Board();
		break;
		case 13:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p13 = temp;
			check[12] = temp;
			system("cls");
			Board();
		break;
		case 14:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p14 = temp;
			check[13] = temp;
			system("cls");
			Board();
		break;
		case 15:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p15 = temp;
			check[14] = temp;
			system("cls");
			Board();
		break;
		case 16:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p16 = temp;
			check[15] = temp;
			system("cls");
			Board();
		break;
		case 17:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p17 = temp;
			check[16] = temp;
			system("cls");
			Board();
		break;
		case 18:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p18 = temp;
			check[17] = temp;
			system("cls");
			Board();
		break;
		case 19:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p19 = temp;
			check[18] = temp;
			system("cls");
			Board();
		break;
		case 20:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p20 = temp;
			check[19] = temp;
			system("cls");
			Board();
		break;
		case 21:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p21 = temp;
			check[20] = temp;
			system("cls");
			Board();
		break;
		case 22:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p22 = temp;
			check[21] = temp;
			system("cls");
			Board();
		break;
		case 23:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p23 = temp;
			check[22] = temp;
			system("cls");
			Board();
		break;
		case 24:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p24 = temp;
			check[23] = temp;
			system("cls");
			Board();
		break;
		case 25:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			p25 = temp;
			check[24] = temp;
			system("cls");
			Board();
		break;
	}
}
