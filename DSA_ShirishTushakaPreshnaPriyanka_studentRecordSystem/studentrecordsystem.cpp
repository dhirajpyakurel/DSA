#include<iostream>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;


class person{
	char name[30];
	char roll[12];
	char phn[100];
public:
	void menu();
	void addrecord();
	void searchrecord();
	void deleterecord();
	void display();
	void sortrecord();
}p[50];
int n=0;


int main()
{
	person p;
	p.menu();
	return 0;
}



void person::menu()
{
	person p;
    char h;
    cout<<"\n\n\n\t\t\t\t  **********STUDENT RECORD SYSTEM*************";
	cout<<"\n\n\n\t\t\t\t\t\t  MENU\t\t\n\n";
	cout<<"\t\t\t\t    1.Add    \t2.Display    \t3.Delete    \n\n\t\t\t\t    4.Search   \t5.Sort    \t6.Exit\n";
	cin>>h;
	switch(h)
	{
		case'1':
			p.addrecord();
			break;
		case'2':
			p.display();
			break;
		case '3':
			p.deleterecord();
			break;
		case'4':
			p.searchrecord();
			break;
		case'5':
			p.sortrecord();
			break;
		case'6':
			exit(1);	
		default:			
			cout<<"Enter valid choice";	
	}
	system("cls");
	menu();
}




void person:: addrecord()
{
     	 system("cls");
         FILE *f;
         person pe;
         f=fopen("class","ab+");	//open append in binary
         cout<<"\nEnter name: ";
         cin>>pe.name;
         cout<<"\nEnter roll:";
         cin>>pe.roll;
         cout<<"\nEnter phone no.:";
         cin>>pe.phn;
         fwrite(&pe,sizeof(pe),1,f);	//write to file	
 		 p[n++] = pe;  
         cout<<"\nrecord saved";
		 fclose(f);
    	 cout<<"\n\nEnter any key";
		 getch();
}





void person:: searchrecord()
{
	system("cls");
	person p;
	FILE *f;
	string name;
	f=fopen("class","rb");			//open read in binary
	if(f==NULL)
	{
    	cout<<"\n error in opening\a";
    	exit(1);	
	}
	cout<<"\nEnter name of person to search\n";
	cin>>name;
	system("cls");
	while(fread(&p,sizeof(p),1,f)==1)
	{
    	if(p.name==name)
    	{
        	cout<<"\nDetail Information About "<<name;
        	printf("\n");
        	cout<<"\nName:"<<p.name<<"\nRoll no:"<<p.roll<<"\nPhone Number:"<<p.phn;
        	goto bottom;
    	}
	}
	cout<<"Not found";
	bottom:	fclose(f);
	cout<<"\nEnter any key";
	getch();
	system("cls");
	menu();	
}






void person::display()
{
	system("cls");
    person p;
    FILE *f;
	f=fopen("class","rb");
	if(f==NULL)
	{
		printf("\nfile opening error in listing :");
		exit(1);
	}
   	printf("\n\n\n\t\t\t\t\t\t  RECORDS \n ");
   	
	printf("\n\t\t\t\tS.N\tName\t\tRoll\t\tMobile Number\n");	
	int  i=1;
	while(fread(&p,sizeof(p),1,f)==1)
	{
		printf("\t\t\t\t");
    	cout<<i;
		cout<<setw(12)<<p.name;		//set width for name
    	cout<<setw(14)<<p.roll;
    	cout<<setw(24)<<p.phn;
    	printf("\n");
		i++;
	}
	fclose(f);
	cout<<("\n\t\t\t\tEnter any key");
	getch();
    system("cls");
	menu();
}



void person::deleterecord()
{
	system("cls");
    person p;
    FILE *f,*ft;
    int flag;	//check if the condition is met
	char name[50];
	f=fopen("class","rb");
	if(f==NULL)
		{
			cout<<("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		ft=fopen("temp","wb+");		
		if(ft==NULL)
            cout<<("file opening error");
		else
        {
			cout<<("Enter NAME:");
			cin>>name;
			while(fread(&p,sizeof(p),1,f)==1)
			{
				if(strcmp(p.name,name)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.name,name)==0)
                	flag=1;
			}
		fclose(f);
		fclose(ft);
		if(flag!=1)
		{
			cout<<("NO CONTACT'S RECORDS TO DELETE.");
			remove("temp.txt");
		}
		else
		{
			remove("class");
			rename("temp","class");		
			cout<<("RECORD DELETED SUCCESSFULLY.");
		}
	n--;
	}
}
 	cout<<("\n Enter any key");
	getch();
    system("cls");
}



void person::sortrecord()
{
	system("cls");
	person *p,temp;
	FILE *f;
	int i,j;
	f=fopen("class","rb");					//open read in binary
	fseek(f,0,SEEK_END);					//put file pointer to the end of file
	int n=ftell(f)/sizeof( person);			//ftell=returns the current position of the file from start	(end=total data/size of each data==no. of data)
	rewind(f);								//moves the indicator to the start of the file
	p=( person*)calloc(n,sizeof( person));  //allocates memory for n elements of size person
	for(i=0;i<n;i++)
	{
		fread(&p[i],sizeof( person),1,f);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
				if(strcmp(p[j].name,p[j+1].name) > 0)
				{
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;				
				}
		}
	}
	printf("\n\n\n\t\t\t\t\t\tSORTED LIST");
	printf("\n\n\t\t\t\tS.N\tName\t\tRoll\t\tMobile Number\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t");
		cout<<i+1;
		cout<<setw(15)<<p[i].name;
    	cout<<setw(11)<<p[i].roll;
    	cout<<setw(24)<<p[i].phn;
    	printf("\n");
	}
	getch();
}
