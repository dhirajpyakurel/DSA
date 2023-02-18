#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
class Node
{
	public:
		int rollno;
	    string name;
	    long long int contactno;
	    char gender;
	    float marks,per;
	    Node *next_add;
};
class Record_System
{
	public:
		Node *head = NULL; 
		
		void Insert(){
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			int r;
			string n;
			char g;
			long long cn;
			float m;
			
			SetConsoleTextAttribute(h,6);
			cout<<"\n\n Enter Roll no. : ";
			cin>>r;
			cout<<"\n\n Enter Name : ";
			cin>>n;
			cout<<"\n\n Enter 'M'for male and 'F'for female : ";
			cin>>g;
			cout<<"\n\n Enter Contact No. : ";
			cin>>cn;
			cout<<"\n Full Marks = 600";
			cout<<"\n\n Enter Scored Marks : ";
			cin>>m;
			Node *new_node = new Node;
			new_node -> rollno = r;
			new_node -> name = n;
			new_node -> marks = m;
			new_node -> contactno = cn;
			new_node -> gender = g;
			new_node -> per = m/600*100;
			new_node -> next_add = NULL;
			if(head == NULL){
				head = new_node;
			}
			else
			{
				Node *ptr = head;
				while(ptr-> next_add != NULL){
					ptr = ptr->next_add;
				}
				ptr -> next_add = new_node;
			}
			cout<<"\n\n New Record Inserted Successfully....";
		}
		
		void Search()
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			if(head == NULL){
				SetConsoleTextAttribute(h,4);
				cout<<"\n\n !!! List is Empty !!!";
			}
			else
			{
				int r, found = 0;
				SetConsoleTextAttribute(h,4);
				cout<<"\n\n Enter roll no for search: ";
				cin>>r;
				Node *ptr = head;
				while(ptr !=NULL)
				{
					if(r == ptr -> rollno){
						SetConsoleTextAttribute(h,6);
						cout <<"\n\n Roll No :"<<ptr -> rollno;
						cout <<"\n\n Name : "<<ptr -> name;
						cout <<"\n\n Gender : "<<ptr -> gender;
						cout <<"\n\n Contact No : "<<ptr -> contactno;
						cout <<"\n\n Marks : "<< ptr -> marks;
						if(ptr -> marks > 600){
							cout << "\n\n Percentage % : Out of range";
						}else
						{
							cout <<"\n\n Percentage % : "<< ptr->per<<"%";
						}
						
						found++;
					}
					ptr = ptr -> next_add;
				}
				if(found == 0)
				{
					cout <<"\n\n Search Roll No."<<r<<" Can't Found...";
				}
			}
		}
	    void Count()
	    {
	    	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	    	if(head == NULL)
	    	{
	    		SetConsoleTextAttribute(h,4);
	    		cout<<"\n\n !!! List is Empty !!! ";
			}
			else
			{
				int c=0;
				Node *ptr = head;
				while(ptr != NULL)
				{
					c++;
					ptr = ptr -> next_add;
				}
				SetConsoleTextAttribute(h,3);
				cout << "\n\n Total No. of Students: "<<c;
			}
		}
		void Update()
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			if(head == NULL){
				SetConsoleTextAttribute(h,4);
	    		cout<<"\n\n !!! List is Empty !!! ";
			}
			else
			{
				int r, found = 0;
				cout<<"\n\n Enter roll no for updating: ";
				cin>>r;
				Node *ptr = head;
				while(ptr !=NULL)
				{
					if(r == ptr -> rollno)
					{
						
						cout<<"\n\n Enter New Roll no. : ";
			            cin>>ptr -> rollno;
						cout<<"\n\n Enter Name: ";
						cin>>ptr -> name;
						cout<<"\n\n Enter Gender: ";
						cin>>ptr -> gender;
						cout<<"\n\n Enter Contact No.: ";
						cin>>ptr -> contactno;
						cout<<"\n Full Marks = 600";
						cout<<"\n\n Enter marks: ";
						cin>>ptr -> marks;
						ptr -> per = ptr -> marks/600 *100;
						cout <<"\n\n Record Updated Successfully...";
						found++;
					}
					ptr = ptr -> next_add;
				}
				if(found == 0)
				{
					cout <<"\n\n Updated Roll No."<<r<<" Can't Found...";
				}
			}
	    }
	    void Delete()
		{
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			if(head == NULL){
				SetConsoleTextAttribute(h,4);
	    		cout<<"\n\n !!! List is Empty !!! ";
			}
			else
			{
				int r, found = 0;
				cout<<"\n\n Enter roll no for deletion: ";
				cin>>r;
				if(r == head -> rollno)
				{
					Node *ptr = head;
					head = head -> next_add;
					cout<<"\n\n Record Deleted Successfully...";
					found ++;
					delete ptr;
				}
				else
				{
					Node *pre = head;
					Node *ptr = head -> next_add;
					while(ptr != NULL)
					{
						if(r == ptr -> rollno)
						{
							pre -> next_add = ptr -> next_add;
							cout<<"\n\n Record Deleted Successfully...";
							found ++;
							delete ptr;
							break;
						}
						pre = ptr;
						ptr = ptr -> next_add;
					}
				}
				if(found == 0)
				{
					cout <<"\n\n Delete Roll No."<<r<<"Can't Found...";
					
				}
			}
	    }
	    void Display()
	    {
	    	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			if(head == NULL){
				SetConsoleTextAttribute(h,4);
	    		cout<<"\n\n !!! List is Empty !!! ";
			}
			else
			{
				Node *ptr = head;
				while(ptr !=NULL)
				{
					SetConsoleTextAttribute(h,6);
					cout <<"\n\n Roll No. :"<<ptr -> rollno;
					cout <<"\n\n Name : "<<ptr -> name;
					cout <<"\n\n Gender : "<<ptr -> gender;
					cout <<"\n\n Contact No. : "<<ptr -> contactno;
					cout <<"\n\n Marks : "<< ptr -> marks;
					if(ptr -> marks > 600){
							cout << "\n\n Percentage % : Out of range";
					}else
					{
						cout <<"\n\n Percentage % : "<< ptr->per<<"%";
					}
					cout <<"\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
					
					ptr = ptr -> next_add;
				}
			}
		}
};
int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	Record_System obj;
	top:
	system("cls");
	int choice;

	SetConsoleTextAttribute(h,12);
	cout <<"\n STUDENTS RECORD SYSTEM :";
	cout<<"\n";
	
	SetConsoleTextAttribute(h,11);
	cout <<"\n Enter:";
	
	SetConsoleTextAttribute(h,7);
	cout <<"\n1. Insert Record";
	cout <<"\n2. Search Record";
	cout <<"\n3. Count No of Students";
	cout <<"\n4. Update Record";
	cout <<"\n5. Delete Record";
	cout <<"\n6. Display all record";
	cout <<"\n7. exit";
	
	SetConsoleTextAttribute(h,11);
	cout <<"\n\n Enter Your Choice: ";
	cin>> choice;
	switch(choice)
	{
		case 1:
			system("cls");
			obj.Insert();
			break;
		case 2:
			system("cls");
			obj.Search();
			break;
		case 3:
			system("cls");
			obj.Count();
			break;
		case 4:
			system("cls");
			obj.Update();
			break;
		case 5:
			system("cls");
			obj.Delete();
			break;
		
		case 6:
			system("cls");
			obj.Display();
			break;
		case 7:
			exit(0);
		default:
			SetConsoleTextAttribute(h,4);
			cout<<"\n\n Invalid Choice....Please try again!!!";
	}
	getch();
	goto top;

}
