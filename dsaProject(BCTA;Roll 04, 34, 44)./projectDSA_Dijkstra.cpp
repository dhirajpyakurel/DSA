/***************** A program to demonstrate the dijkstra algorithm*********************************
***************Started development 2/09/2023******************************************************
**************@DangerX69***************************************************************************
*************biswashkhanal67@gmail.com**************************************************************
***********Thanks to @GiriKabin & @AayushBasnet for help in debugging, vision and coordination********
***************************************************************************************************/


//START OF PROGRAM
/***HEADERS*///
#include<iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


/***CONSTANTS****/
#define INFINITY 99999
#define SIZE 30

/*********FUNCTIONS********/
void delay(int);//add a delay without any indicator
void delay2(int);//add a delay with an indicator
void dijkstra(int[][SIZE], int, int);//the main brain of the program
void sampledata();//contains code to execute the program using the already initialized sample data
void inputdata();//contains code to take custom input from the user
void endscreen();//The ending Credits
void mainmenu();//Shows the main menu
void helpscreen();//The help section
/****************Visual MANIPULATION FUNCTIONS************/
void red ();void redb ();
void yellow ();void yellowb ();
void blue ();void blueb ();
void purple ();void purpleb ();
void cyan ();void cyanb();
void green ();void greenb ();
void white ();void whiteb ();
void seperationLine(){
	for(int i=0;i<30;i++){
		printf("-*");
	}
}
/*******end of visual manipulation functions*/

/*******END OF FUNCTION DECLARATION******/

/*******Colour Functions **************/
void red () {
  printf("\033[0;31m");
}
void redb () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[0;33m");
}
void yellowb() {
  printf("\033[1;33m");
}

void blue (){
  printf("\033[0;34m");
}
void blueb (){
  printf("\033[1;34m");
}

void purple (){
  printf("\033[0;35m");
}
void purpleb (){
  printf("\033[1;35m");
}

void cyan (){
  printf("\033[0;36m");
}
void cyanb (){
  printf("\033[1;36m");
}

void green (){
  printf("\033[0;32m");
}
void greenb (){
  printf("\033[1;32m");
}

void whiteb (){
  printf("\033[1;37m");
}

void reset () {
  printf("\033[0m");
}
/****Colouring Functions END******/




/*delay function*/
void delay(int time){
	for(int slc=0;slc<5;slc++){
    	Sleep(time);
    	yellowb();
		printf(".");
		
	
}

}
void delay2(int time){
	for(int slc=0;slc<5;slc++){
    	Sleep(time);
	
}
}
/**Class to hold location names at indices*****/
class Places{
	public:
	char place[20];
};

Places pl[30];//creation of an array of objects
int choice;//points to target source location choosen by the user
int distance[SIZE*SIZE];//a list to hold the adjancy matrix




/******BRAIN OF THE PROGRAM FUNCTION******************/
	void dijkstra(int Graph[SIZE][SIZE], int numvertices, int startnode){
	/************VARIABLES FOR DIJKSTRA FUNCTION********/
	
	int cost[SIZE][SIZE];//COST MATRIX
	int distance[SIZE];
	int previousnode[SIZE];//HOLDS THE VERTEX INDEX OF PREVIOUS NODE
	int visited[SIZE];//1= Visited node, 0 = unvisited node
	int count;//Number of nodes encountered till now
	int minimumdistance;//MINIMUM DISTANCE
	int nextnode;//holds node which is at minimum distance from current node
	int i;//loop counter 1
	int j;//loop counter 2
	
	
/**********END OF VARIABLES **************/
	
	
/********COST MATRIX EVALUATION*************/
	for(i =0; i<numvertices; i++){
		for(j=0;j<numvertices;j++){
			if(Graph[i][j] == 0){
				cost[i][j] = INFINITY;
			}
			else{
				cost[i][j] = Graph[i][j];
			}
		}
	}
	
	/******END OF COST MATRIX EVALUATION*******/
	
	/*****EVALUATION OF previous node,********************
		********** distance & visited parameters******/
		
		for(i =0; i<numvertices; i++){
			distance[i] = cost[startnode][i];
			previousnode[i] = startnode;
			visited[i] = 0;
		}
	         distance[startnode] = 0;
			 visited[startnode]  = 1;
			 count               = 1;             
	
	
		while(count < (numvertices-1)){
			minimumdistance = INFINITY;
			
			for(i = 0; i<numvertices; i++){
				
				if(distance[i] < minimumdistance && visited[i] == 0){
					
					minimumdistance = distance[i];
					nextnode = i;
				}
			}
			
			visited[nextnode] = 1;
			
			for(i = 0; i<numvertices; i++){
				if(visited[i] == 0 &&
					minimumdistance + cost[nextnode][i] < distance[i]){
					
					distance[i] = minimumdistance + cost[nextnode][i];
					previousnode[i] = nextnode;
				}
			}
			count++;
		}
		
		/*******END OF MAIN LOGIC****/
		//DISPLAYING THE ROUTE AND SHORTEST DISTANCE
		Beep(900, 300);
		 for (i = 0; i < numvertices; i++)
    if (i != startnode) {
    	
		
		blueb();
      printf("\n\n\nShortest Route From");
      whiteb();
      printf(" %s To %s", pl[choice-1].place, pl[i].place);
      delay(300);
      greenb();
      printf("\n\n%s",pl[i].place);
      j=i;
      
do
{
j=previousnode[j];
printf("<--%s",pl[j].place);
}while(j!=startnode);
yellow();
printf("\nShortest Distance from %s to %s: %dkm\n\n", pl[choice-1].place, pl[i].place, distance[i]);
redb();
seperationLine();
Beep(700, 300);Beep(900, 300);
reset();
    }
		
}

/********END OF DIJKSTRA FUNCTION********/
/*******MAIN FUNCTION********/
int main() {
	
	int numLocation = 13;
	int y;
	int inputChoice;
	while(1){
	mainmenu();
	inputChoice = toupper(getch());
	switch(inputChoice){
		case '1':
			
			sampledata();
			
			break;
		case '2':
			inputdata();
			break;
		case 'H':
			helpscreen();
			break;
		default:
			endscreen();
			break;
	}
	
}
  return 0;
}



/*************************SAMPLE DATA*********************************/
void sampledata(){
	int Graph[SIZE][SIZE], i, j, u;
	int numLocation = 13;
	int y;
	char ch;
	
	
		//VERTEXES ENTRY
		//PLACES IN THIS CASE
	
char locationnames[20][20]= {"KATHMANDU", "BHAKTAPUR", "LALITPUR", "KAVREPALANCHOWK",
						 "SINDHUPALCHOWK", "DOLAKHA", "RAMECHHAP", "SINDHULI",
						  "MAKWANPUR", "CHITWAN", "DHADING", "NUWAKOT", "RASUWA" };

for(int i=0;i<numLocation;i++){
	strcpy(pl[i].place, locationnames[i] );
}

//EDGES ENTRY
//DISTANCE IN THIS CASE
	int distanceList[]= {0,	13,	7,	39,	40,	0,	0,	0,	88,	0,	45,	26,	0,
						13,	0,	12,	14,	0,	0,	0,	0,	0,	0,	0,	0,	0,
						7,	12,	0,	25,	0,	0,	0,	0,	38,	0,	0,	0,	0,
						39,	14,	25,	0,	24,	51,	62,	61,	48,	0,	0,	0,	0,
						40,	0,	0,	24,	0,	48,	62,	0,	0,	0,	0,	53,	51,
						0,	0,	0,	51,	48,	0,	53,	0,	0,	0,	0,	0,	0,
						0,	0,	0,	62,	62,	53,	0,	20,	0,	0,	0,	0,	0,
						0,	0,	0,	61,	0,	0,	20,	0,	84,	0,	0,	0,	0,
						88,	0,	38,	48,	0,	0,	0,	84,	0,	72,	59,	0,	0,
						0,	0,	0,	0,	0,	0,	0,	0,	72,	0,	60,	0,	0,
						45,	0,	0,	0,	0,	0,	0,	0,	59,	60,	0,	23,	44,
						26,	0,	0,	0,	53,	0,	0,	0,	0,	0,	23,	0,	27,
						0,	0,	0,	0,	51,	0,	0,	0,	0,	0,	44,	27,	0 };
  int k=0;
  for(i=0;i<numLocation;i++){
  	for(j=0;j<numLocation;j++)
  	{

  			Graph[i][j] = distanceList[k];
  			k++;
	  }
  }
  
  
  system("cls");
  blue();
  printf("USING THE SAMPLE DATA(PROVINCE NO: 3, NEPAL):\n");
do{
		blueb();
		printf("Locations Available: \n");
		delay2(10);
	for (y=0;y<numLocation;y++){
		delay2(10);
		yellow();
		printf("%d.) %s\n", y+1, pl[y].place );
	}
	yellowb();
	printf("Enter INDEX for source location: ");
	reset();
	scanf("%d", &choice);
  
  
	cyan();
	printf("\nSource Location is %s:", pl[choice-1].place);
	delay(100);
	cyanb();
	printf("\nCalculating The shortest paths:");
	reset();
	delay(500);
  	u = choice-1;
  	dijkstra(Graph, numLocation, u);
  	yellowb();
  	printf("\n\nPress 1 to find path for a different source or \n");
  	printf("Press any other key to go back to main menu\n");
  	red();
  	printf("[CAUTION!CONTINUATION FROM HERE WILL CLEAR THE SCREEN!]");
  	reset();
  	ch = getch();
  	system("cls");
  }while(ch == '1' );
}
/*******************************END OF SAMPLE DATA************/

/*************CUSTOM INPUT **************************/
void inputdata(){
	int Graph[SIZE][SIZE], i, j, u;
	int numLocation;
	int y;
	char ch;
	int distanceList[SIZE*SIZE];
	  system("cls");
	  blue();
  	printf("USING CUSTOM INPUT AS DATA:\n");
  	yellowb();
	printf("\nPlease Paste the appropriate formated input block: \n");
	redb();
	scanf("%d", &numLocation);
		//VERTEXES ENTRY
	//PLACES IN THIS CASE
	cyanb();
	for( i =0;i<numLocation;i++){
		std::cin>>pl[i].place;
	}
	purpleb();
	for(i =0;i<numLocation*numLocation;i++){
		std::cin>>distanceList[i];
	}
	
  int k=0;
  for(i=0;i<numLocation;i++){
  	for( j=0;j<numLocation;j++)
  	{

  			Graph[i][j] = distanceList[k];
  			k++;
	  }
  }
  yellowb();
  printf("\nData Entered Successfully ! Press any key to continue");
  getch();
  system("cls");
  do{
		blueb();
		printf("Locations Available: \n");
		delay2(10);
	for (y=0;y<numLocation;y++){
		delay2(10);
		yellow();
		printf("%d.) %s\n", y+1, pl[y].place );
	}
	
	yellowb();
	printf("Enter INDEX for source location: ");
	reset();
	scanf("%d", &choice);
	cyan();
	printf("\nSource Location is %s:", pl[choice-1].place);
	delay(100);
	cyanb();
	printf("\nCalculating The shortest paths:");
	reset();
	delay(500);
  	u = choice-1;
  	dijkstra(Graph, numLocation, u);
  	yellowb();
  	printf("\n\nPress 1 to find path for a different source or \n");
  	printf("Press any other key to go back to main menu\n");
  	red();
  	printf("[CAUTION!CONTINUATION FROM HERE WILL CLEAR THE SCREEN!]");
  	reset();
  	ch = getch();
  	system("cls");
  }while(ch =='1');
}

void endscreen(){
	system("cls");
	green();
	printf(" --------------------------------------------------------------------------------------------------------------\n");
	blue();
	printf("|**************************************************************************************************************|\n");
	red();
	printf("|************************************                                    **************************************|\n");
	cyan();
	printf("|***********************************                                      *************************************|\n");
	purple();
	printf("|*********************************    Thanks For Using our Application!    ************************************|\n");
	yellow();
	printf("|********************************       Application Programmed in C++       ***********************************|\n");
	reset();
	printf("|*******************************          Creation Date: 2/15/2023           **********************************|\n");
	printf("|******************************                 Created by:                   *********************************|\n");
	printf("|*******************************       *        Kabin Giri        *          **********************************|\n");
	yellow();
	printf("|********************************    ***      Biswash Khanal      ***       ***********************************|\n");
	purple();
	printf("|*********************************     *       Aayush Basnet      *        ************************************|\n");
	cyan();
	printf("|**********************************           BATCH:-2077BCTA             *************************************|\n");
	red();
	printf("|***********************************                                     **************************************|\n");
	blue();
	printf("|**************************************************************************************************************|\n");
	green();
	printf(" --------------------------------------------------------------------------------------------------------------\n");	
	getch();
	exit(0);
}
void mainmenu(){
	system("cls");
	 cyan();
	printf(" --------------------------------------------------------------------------------------------------------------\n");
	printf("|**************************************************************************************************************|\n");
	printf("|*************************************                             ********************************************|\n");
	printf("|************************************                               *******************************************|\n");
	printf("|***********************************             SHORTEST            ******************************************|\n");
	printf("|**********************************            PATH   FINDER          *****************************************|\n");
	printf("|***********************************        DIJKSTRA  ALGORITHM      ******************************************|\n");
	printf("|************************************                               *******************************************|\n");
	printf("|*************************************                             ********************************************|\n");
	printf("|**************************************************************************************************************|\n");
	printf(" --------------------------------------------------------------------------------------------------------------\n\n\n");
	yellow();
	printf("Press '1' to use the built in sample data(Province 3, NEPAL), \n");
	printf("Press '2' to input the locations and Adjacency Matrix, \n");
	printf("Press 'H' to learn about custom input system, or \n");
	printf("Press any other key to exit the program!\n\n");
	red();
	printf("[WARNING! GIVING INCORRECTLY FORMATTED INPUT TO THE APPLICATION CAN CAUSE UNWANTED BEHAVIOUR]\n");
	printf("[IF ANY UNUSUAL BEHAVIOUR OCCURS PLEASE VERIFY THE INPUT DATA FORMAT and try again!]\n");
	green();
	printf("PRESS 'H' to LEARN MORE ABOUT THE INPUT FORMATTING\n");
	reset();
}
void helpscreen(){
		system("cls");
	green();
	printf("|*****************************************************************|\n");
	printf("\t\t\t\tHELP SECTION\n");
	printf("|*****************************************************************|\n");
	reset();
	cyan();
	printf("Correct format should be used for providing custom input for the application\n");
	printf("The required parameters in the input are :\n1.)Number of locations, \n2.)Names of the locations, \n3.)The respective adjacency matrix elements\n");
	printf("Each parameter should be seperated by some form of WHITESPACE\n");
	reset();
	printf("Format:\n");
	green();
	printf("N name[0] name[1] ....... name[N] adj[0][0] adj[0][1] ........adj[N][N]\n");
	reset();
	printf("For example: \n");
	
	printf("For 3 location named A, B and C where adj[][] values are known\n");
	green();
	printf("3 A B C 0 1 2 1 0 3 3 2 0     is a valid input, Also\n");
	printf("3\n");
	printf("A B C\n");
	printf("0 1 2\n");
	printf("1 0 3\n");
	printf("3 2 0\n");
	reset();
	printf("is also a valid input\n");
	cyan();
	printf("Remember to put the value for adj matrix 0 for the same node, or to a node towards which edge doesnt exist!\n");
	yellow();
	printf("\n\nPress Any key to go back to the main menu!");
	reset();
	getch();
	
}
/***************** End of First successful Run*********************************
*************** 2/15/2023******************************************************
**************@DangerX69***************************************************************************
*************biswashkhanal67@gmail.com**************************************************************
***********Thanks to @GiriKabin & @AayushBasnet for help in debugging, vision and coordination********
***************************************************************************************************/