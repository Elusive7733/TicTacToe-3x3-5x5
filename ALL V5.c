#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

char a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',z=' ',j=' ';

char p1=' ',p2=' ',p3=' ',p4=' ',p5=' ';
char p6=' ',p7=' ',p8=' ',p9=' ',p10=' ';
char p11=' ',p12=' ',p13=' ',p14=' ',p15=' ';
char p16=' ',p17=' ',p18=' ',p19=' ',p20=' ';
char p21=' ',p22=' ',p23=' ',p24=' ',p25=' ';

char check[25] = "abcdefghijklmnopqrstuvwxy" ;
char check3x3[9] = {'1','2','3','4','5','6','7','8','9'};

int  end,scoreP1=0,scoreP2=0;
int  cp3x3,cp5x5,resumegame3x3 = 0,resumegame5x5 = 0,noposleft3x3=0,noposleft5x5=0;
char p1name3x3[50],p2name3x3[50];
char p1name5x5[50],p2name5x5[50];


void Board3x3();
void Game3x3();
char Position3x3(int pos, int p, char cp1 , char cp2);
void Restart3x3();

void Board();
void Game();
char Position(int pos, int p, char cp1 , char cp2);
void Restart();

void whichgame();

void MENU(){
	
	int choicemenu;
	
	system("color E");
	
//	printf("\n MENU \n");
//	getch();
	printf("\t\t\t\tTIC TAC TOE\n\n\n\n");
	printf("1 - Play GAME\n");
	printf("2 - Quit GAME\n");
	printf("\n\nWhat do you want to do?\n");
	scanf("%d",&choicemenu);
	
	if (choicemenu == 1){
		whichgame();
//		printf("\n BACK IN MENU \n");
//		getch();
	}
	else{
		end = choicemenu;
	}
}


void main(){

	do {
		system("cls");
//		printf("\n MAIN \n");
//		getch();
		if (resumegame3x3 == 0)
		{
			Restart3x3();
		}
		if (resumegame5x5 == 0)
		{
			Restart();
		}
//		getch();
		
		MENU();
//		printf("end in Main = %d",end);
//		getch();
		if (end == 2){
			break;
		}
	}while (end != 2);
	system("cls");
//	printf("\n END \n");
	
	
}


void Game3x3(){
	
	int pos=0,p=0,i,x,counter=9,flag = 0,E=0,c=9;
	char win = 'D',cp1,cp2,reset = 'N';
	
	system("color F");
//	printf("noposleft3x3 = %d\n",noposleft3x3);
//	getch();
	
	if (resumegame3x3 == 0){
		printf("%s: Enter Your Marker X/O\n",p1name3x3);
		scanf(" %c",&cp1);

	
		while(cp1 != 'X')
		{
			if(cp1 == 'O')
			{
				break;
			}
			printf("ERROR! Must be X or O.\n%s: Enter Your Marker X/O\n",p1name3x3);
			scanf(" %c",&cp1);
		}
			
		system("cls");
		
		if (cp1 == 'X'){
			cp2 = 'O';
			cp3x3 = 0;
		}
		else 
		{
			cp2 = 'X';
			cp3x3 = 1;
		}
	}
	else
	{
		if (cp3x3 == 0){
			cp1 = 'X';
			cp2 = 'O';
		}
		else
		{
			cp1 = 'O';
			cp2 = 'X';	
		}	
	}
	Board3x3();
	
	if (resumegame3x3 != 0)
	{
		printf("\nPress Y if you want to Reset\n");
		scanf(" %c",&reset);
		if (reset == 'Y'){
			resumegame3x3=0;
			cp3x3=0;
			noposleft3x3=0;
			main();
		}
	}
	
	for (i=1;i<=c;i++)
	{		
			if (E == 2){
				resumegame3x3 = 1;
				main();
			}
			
			flag = 0;
				if (i%2 == 0){
					printf("\n\n%s TURN (%c)\n",p2name3x3,cp2);
					p = 2;
				}
				else
				{
					printf("\n\n%s TURN (%c)\n",p1name3x3,cp1);
					p = 1;
				}
				printf("If Both Players Press -1 , The Game will Stop.\n");
				printf("At Which Position (1-9) Do You Want To Place Your Marker.\n");
			while(counter != 0)
			{
				printf("\rTime left = %ds", counter);
				sleep(1);
				counter--;
				if(kbhit())
				{
					printf("\n");
					scanf(" %d",&pos);
					if (pos != -1)
					{
						while(flag == 0)
						{
							if(pos == 0)
							{
								printf("ERROR - Position must be an integer\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else if(pos < 1 || pos > 9)
							{
								printf("ERROR - Position number must be between 1 & 9 inclusive.\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else if(check3x3[pos-1] == 'X' || check3x3[pos-1] == 'O')
							{
								printf("ERROR - Position taken. Position Number must be empty.\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else
							{
							 	flag = 1;
							}
							fflush(stdin);
						}
					
					}
					break;
				}
			}
//				printf("noposleft3x3 = %d\n",noposleft3x3);
//				getch();
				if (pos == -1){
					E++;
					c++;
					continue;
				}
			if(counter == 0)
			{
				if (i%2 == 0){
					printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a",p2name3x3,cp2);
					p = 2;
				}
				else
				{
					printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a",p1name3x3,cp1);
					p = 1;
				}
			}
			else
			{
				E = 0;
				Position3x3(pos,p,cp1,cp2);	
			}
			counter = 9;
			    
				if (check3x3[0] == check3x3[1] && check3x3[0] == check3x3[2]){
			    	win = check3x3[0];
			    	break;
				}
				else if (check3x3[0] == check3x3[3] && check3x3[0] == check3x3[6]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[2] == check3x3[5] && check3x3[2] == check3x3[8]){
					win = check3x3[2];
			    	break;
				}
				else if (check3x3[6] == check3x3[7] && check3x3[6] == check3x3[8]){
					win = check3x3[6];
			    	break;
				}
				else if (check3x3[0] == check3x3[3] && check3x3[0] == check3x3[6]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[2] == check3x3[4] && check3x3[2] == check3x3[6]){
					win = check3x3[2];
			    	break;
				}
				else if (check3x3[0] == check3x3[4] && check3x3[0] == check3x3[8]){
					win = check3x3[0];
			    	break;
				}
				else if (check3x3[3] == check3x3[4] && check3x3[3] == check3x3[5]){
					win = check3x3[3];
			    	break;
				}
				else if (check3x3[1] == check3x3[4] && check3x3[1] == check3x3[7]){
					win = check3x3[1];
			    	break;
				}
				else
				{
					noposleft3x3 = 0;
					for (x=0;x<9;x++){
						
						if (check3x3[x] == 'X' || check3x3[x] == 'O')
						{
							noposleft3x3++;	
						}
					}
				}
				
				if ( noposleft3x3 == 9)
				{
				break;
				}
	}
	
	if (win == cp1){
		printf("\n\n\n%s WINS !!!",p1name3x3);
		resumegame3x3 = 0;
		cp3x3 = -1;
		noposleft3x3 = 0;
		scoreP1++;
	}
	else if (win == cp2){
		printf("\n\n\n%s WINS !!!",p2name3x3);
		resumegame3x3 = 0;
		cp3x3 = -1;
		noposleft3x3 = 0;
		scoreP2++;
	}
	else
	{
		printf("IT'S A DRAW !!!");
		resumegame3x3 = 0;
		cp3x3 = -1;
		noposleft3x3 = 0;
	}
}

void Board3x3(){ 


	printf("\t|\t|\n   %c    |   %c   |   %c    \t\t\tScore %s = %d\n\t|\t|\t\t\t\tScore %s = %d\n",a,b,c,p1name3x3,scoreP1,p2name3x3,scoreP2);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",d,e,f);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",g,h,z);

}

char Position3x3(int pos, int p, char cp1 , char cp2){
	char temp;
	switch (pos){
		case 1:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			a = temp;
			check3x3[0] = temp;
			system("cls");
			Board3x3();
		break;
		case 2:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			b = temp;
			check3x3[1] = temp;
			system("cls");
			Board3x3();
		break;
		case 3:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			c = temp;
			check3x3[2] = temp;
			system("cls");
			Board3x3();
		break;
		case 4:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			d = temp;
			check3x3[3] = temp;
			system("cls");
			Board3x3();
		break;
		case 5:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			e = temp;
			check3x3[4] = temp;
			system("cls");
			Board3x3();
		break;
		case 6:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			f = temp;
			check3x3[5] = temp;
			system("cls");
			Board3x3();
		break;
		case 7:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			g = temp;
			check3x3[6] = temp;
			system("cls");
			Board3x3();
		break;
		case 8:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			h = temp;
			check3x3[7] = temp;
			system("cls");
			Board3x3();
		break;
		case 9:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			z = temp;
			check3x3[8] = temp;
			system("cls");
			Board3x3();
		break;
	
	}
}

void Restart3x3(){
	a=' ' ; b=' ' ; c=' ' ; d=' ' ; e=' ' ; f=' ' ; g=' ' ; h=' ' ; z=' ' ; j=' ';
	int i ;
	for (i=0;i<9;i++){
		check3x3[i] = i + 1;
	}
}

void Board(){

	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c    \t\tScore %s = %d\n\t|\t|\t|\t|\t\t\tScore %s = %d\n",p1,p2,p3,p4,p5,p1name5x5,scoreP1,p2name5x5,scoreP2);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p6,p7,p8,p9,p10);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p11,p12,p13,p14,p15);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p16,p17,p18,p19,p20);
	printf("--------|-------|-------|-------|--------\n");
	printf("\t|\t|\t|\t|\n%5c   |%4c   |%4c   |%4c   |%4c   \n\t|\t|\t|\t|\n",p21,p22,p23,p24,p25);

}

void Game(){
	int pos=0,p=0, i,x, counter = 9,flag,E=0,c=25;
	char win = 'D',cp1,cp2,reset = 'N';

	system("Color E");
	
	if (resumegame5x5 == 0){
		printf("%s: Enter Your Marker X/O\n",p1name5x5);
		scanf(" %c",&cp1);
		
		while(cp1 != 'X')
		{
			if(cp1 == 'O')
			{
				break;
			}
			printf("ERROR! Must be X or O\n%s: Enter Your Marker X/O\n");
			scanf(" %c",&cp1);
		}
		
		
		system("cls");
		
		if (cp1 == 'X'){
			cp2 = 'O';
			cp5x5 = 0;
		}
		else{
			cp2 = 'X';
			cp5x5 = 1;
		}
	}
	else
	{
		if (cp5x5 == 0){
			cp1 = 'X';
			cp2 = 'O';
		}
		else
		{
			cp1 = 'O';
			cp2 = 'X';	
		}	
	}
	
	Board();
	
	if (resumegame5x5 != 0)
	{
		printf("\nPress Y if you want to Reset\n");
		scanf(" %c",&reset);
		if (reset == 'Y'){
			resumegame5x5=0;
			cp5x5=0;
			noposleft5x5=0;
			main();
		}
	}
	
	for (i=1;i<=c;i++){
			if (E == 2){
				resumegame5x5 = 1;
				main();
				
			}
			
			flag =0;
				if (i%2 == 0){
					printf("\n\n%s TURN (%c)\n",p2name5x5,cp2);
					p = 2;
				}
				else
				{
					printf("\n\n%s TURN (%c)\n",p1name5x5,cp1);
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
					scanf(" %d",&pos);
					if (pos != -1)
					{
						while(flag == 0)
						{
							if(pos == 0)
							{
								printf("ERROR - Position must be an integer\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else if(pos < 1 || pos > 25)
							{
								printf("ERROR - Position number must be between 1 & 25 inclusive.\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else if(check[pos-1] == 'X' || check[pos-1] == 'O')
							{
								printf("ERROR - Position taken. Position Number must be empty.\n");
								flag = 0;
								fflush(stdin);
								scanf(" %d", &pos);
							}
							else
							{
							 	flag = 1;
							}
							fflush(stdin);
						}
					
					}
				break;
				}
			}
			if (pos == -1){
				E++;
				c++;
				continue;
			}
			
			if(counter == 0)
			{
				if (i%2 == 0){
					printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a",p2name5x5,cp2);
					p = 2;
				}
				else
				{
					printf("\n\n%s (%c) JUST LOST HIS/HER TURN!\n\a",p1name5x5,cp1);
					p = 1;
				}
			}
			else
			{	
				if (pos == -1)
				{
					E++;
				}
				else
				{
					E = 0;
					Position(pos,p,cp1,cp2);	
				}
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
				else
				{
					noposleft5x5 = 0;
					for (x=0;x<25;x++)
					{
						if (check[x] == 'X' || check[x] == 'O')
						{
							noposleft5x5++;	
						}
					}
				}
				
				if (noposleft5x5 == 25)
				{
					break;
				}
	}
	
	if (win == cp1){
		printf("\n\n\n%s WINS !!!",p1name5x5);
		cp5x5 = -1;
		resumegame5x5 = 0;
		noposleft5x5 = 0;
		scoreP1++;
	}
	else if (win == cp2){
		printf("\n\n\n%s WINS !!!",p2name5x5);
		cp5x5 = -1;
		resumegame5x5 = 0;
		noposleft5x5 = 0;
		scoreP2++;
	}
	else{
		printf("IT'S A DRAW !!!");
		cp5x5 = -1;
		resumegame5x5 = 0;
		noposleft5x5 = 0;
	}
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

void Restart(){
	 p1 = ' ' ;  p2 = ' ' ;  p3 = ' ' ;  p4 = ' ' ;  p5 = ' ' ;
	 p6 = ' ' ;  p7 = ' ' ;  p8 = ' ' ;  p9 = ' ' ; p10 = ' ' ;
	p11 = ' ' ; p12 = ' ' ; p13 = ' ' ; p14 = ' ' ; p15 = ' ' ;
	p16 = ' ' ; p17 = ' ' ; p18 = ' ' ; p19 = ' ' ; p20 = ' ' ;
	p21 = ' ' ; p22 = ' ' ; p23 = ' ' ; p24 = ' ' ; p25 = ' ' ;
	
	 check[0] = 'a' ;  check[1] = 'b' ;  check[2] = 'c' ;  check[3] = 'd' ;  check[4] = 'e' ;
	 check[5] = 'f' ;  check[6] = 'g' ;  check[7] = 'h' ;  check[8] = 'i' ;  check[9] = 'j' ;
	check[10] = 'k' ; check[11] = 'l' ; check[12] = 'm' ; check[13] = 'n' ; check[14] = 'o' ;
	check[15] = 'p' ; check[16] = 'q' ; check[17] = 'r' ; check[18] = 's' ; check[19] = 't' ;
	check[20] = 'u' ; check[21] = 'v' ; check[22] = 'w' ; check[23] = 'x' ; check[24] = 'y' ; 
	
}

void whichgame(){
	
	char rematch;
	int choicegame;
	system("cls");
//	printf("\n WHICH GAME\n");
//	getch();
	printf("1 - Tic Tac Toe 3x3\n");
	printf("2 - Tic Tac Toe 5x5\n");
	printf("3 - Return to Main MENU\n");
	printf("\nWhat do you want to do?\n");
	scanf("%d",&choicegame);
//	printf("Choicegame in WG = %d",choicegame);
//	getch();
	
	if (choicegame == 1)
	{
			system("cls");
			if (resumegame3x3 == 0)
			{
				printf("Player 1: Enter Your Name.\n");
				fflush(stdin);
				gets(p1name3x3);
				system("cls");
				printf("Player 2: Enter Your Name.\n");
				fflush(stdin);
				gets(p2name3x3);
				system("cls");
			}
			
			do
			{
	    		rematch = 'N';	    		
				Game3x3();
				printf("\nIf you want to Play Again. Press Y\n");
				scanf(" %c",&rematch);
		
				if (rematch == 'Y'){

					system("cls");
					Restart3x3();
				}
				else
				{
					system("cls");
					Board3x3();
					getch();
					scoreP1 = 0;
					scoreP2 = 0;
					break;
				}
		
			}while(rematch == 'Y');
			
	}
	else if (choicegame == 2)
	{
			system("cls");
			if (resumegame5x5 == 0)
			{
				printf("Player 1: Enter Your Name.\n");
				fflush(stdin);
				gets(p1name5x5);
				system("cls");
				printf("Player 2: Enter Your Name.\n");
				fflush(stdin);
				gets(p2name5x5);
				system("cls");
			}
			
			do
			{
	    		rematch = 'N';	    		
				Game();
				printf("\nIf you want to Play Again. Press Y\n");
				scanf(" %c",&rematch);
		
				if (rematch == 'Y'){
					system("cls");
					Restart();
				}
				else
				{
					system("cls");
					Board();
					getch();
					scoreP1 = 0;
					scoreP2 = 0;
					break;
				}
		
			}while(rematch == 'Y');
	
	}
	else if (choicegame == 3)
	{
	}
	else
	{
		printf("WRONG CHOICE!\nPlease Enter Again.");
	 	getch();
	 	whichgame();
	}
}




