#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<limits>


using namespace std;
struct Node
{
	char name[25];                
	long long int phone_number; 
	Node *next; 
	Node *prev; //For linking next and previous contact and is helpful while bubble sorting 
};
class ContactBook
{
	Node *head;
	char x[25];
	long long int y;
	public:
		ContactBook()
		{
			head=NULL;
			x[0] = '\0';
			y=0;
		}

    	void createNode()//Creating a new contact
	    {
	    	if(head==NULL)
	    	{
    	    	Node *newer= new Node;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	    cout<<"Name of Contact: ";
		        cin.getline(x,25);
		        strncpy(newer->name, x, 25);
    		    cout<<"Phone Number: ";
	    	    cin>>y;
		        newer->phone_number=y;
		        newer->next=NULL;
		        newer->prev=NULL;
		        head=newer;
		        cout<<"Contact added successfully."<<endl;
		    }
		    else
		    {
		        Node *newer= new Node;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	    cout<<"Name of Contact: ";
		        cin.getline(x,25);
		        strncpy(newer->name, x, 25);
    		    cout<<"Phone Number: ";
	    	    cin>>y;
		        newer->phone_number=y;
		        newer->next=NULL;
		    	Node *temp=head;
		    	while(temp->next!=NULL)
		    	{
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
		    	cout<<"Contact added successfully."<<endl;	
			}
			getch();
			cout << "\033[2J\033[1;1H";
		}

    	void display()// Displays all contact
    	{
	    	int count=0;
	    	if(head==NULL)
	    	{
		    	cout<<"There are no any contacts.First add some contacts."<<endl;
	    	}
	    	else
	    	{
				Node *temp=head;
	    		bubbleSort();
	    		cout<<"Name:\tNumber:\n"<<endl;
	        	while(temp!=NULL)
	        	{
	        	    count++;
		        	cout<<temp->name;
		        	cout<<"\t"<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
	        	cout<<"Total number of contacts:"<<count<<endl;
	    	}
			getch();
			cout << "\033[2J\033[1;1H";
    	}

    	int search()//Searhes contact individually by both name and number
    	{
    		bool check=false;
	    	Node *temp=head;
	    	cout<<"--------------------------------------------------------------------------"<<endl;
	    	cout<<"Press 1 for searching by Name."<<endl;
	    	cout<<"Press 2 for searching by Number."<<endl;
	    	int choice;
	    	cout<<"Enter your choice: ";
	    	cin>>choice;
	    	if(choice==1 && temp!=NULL)
	    	{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	    cout<<"Name of Contact:";
		        cin.getline(x,25);
		    	while(temp!=NULL)
		    	{
		        	if (strcmp(temp->name, x) == 0)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		check=true;
		        		break;
		        	}
		        	temp=temp->next;
	        	}
	        	if(check==false)
	        	{
	        		cout<<"Contact with same name not found. "<<endl;
				}
	    	}
	    	else if(choice==2)
	    	{
	    		cout<<"Enter the Number to Search: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false)
				{
					cout<<"Contact with same number not found."<<endl;	
				}	
	    	}
			getch();
			cout << "\033[2J\033[1;1H";
            return 0;
	    }

	    void deleteAllContacts() //Deletes all contact 
	    {
			int count=0;
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<"Contact Book is already Empty."<<endl;
	    		cout<<"--------------------------------------------------------------------------"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
					count++;
				}
				head=NULL;
				cout<<count<<" Contacts deleted successfully."<<endl<<"Contact book is empty now."<<endl;
	    		cout<<"--------------------------------------------------------------------------"<<endl;
			}
			getch();
			cout << "\033[2J\033[1;1H";
		}
		
		int deleteContactBySearch() //Delete contact individually  by both name and number
    	{
	    	Node *temp=head;
	    	cout<<"--------------------------------------------------------------------------"<<endl;
	    	cout<<"Press 1 for searching by name."<<endl;
	    	cout<<"Press 2 for searching by Number."<<endl;
	    	int choice;
	    	cout<<"Enter your choice:";
	    	cin>>choice;
	    	if(choice==1)
	    	{
	    		bool check=false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	    cout<<"Name of Contact:";
		        cin.getline(x,25);
	    		while(temp!=NULL)
	    		{
	    	    	if (strcmp(temp->name, x) == 0)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(check==true)
	        	{
	            	int choice;
	            	cout<<"Press 1 to delete the contact shown: ";
	            	cin>>choice;
	            	if(choice==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	            		temp=temp->next;
	            		delete temp1;
	            		temp->prev=NULL;
	            		head=temp;
	            		cout<<"Contact is deleted successfully."<<endl;
			    	}
			    	else if(choice==1 & temp->next==NULL)
			    	{
			    		temp->prev->next=NULL;
			    		delete temp;
			    		cout<<"Contact is deleted successfully."<<endl;
			    	}
			    	else if(choice==1)
			    	{
			    		Node *temp1;
			    		temp1=temp;
			    		temp->prev->next=temp1->next;
			    		temp->next->prev=temp1->prev;
			    		delete temp1;
			    		cout<<"Contact is deleted successfully."<<endl;	
			    	}
			    	else
			    	{
			    		cout<<"Wrong Entry......Try again"<<endl;
		    		}
	            }
	            else if(check==false)
				{
					cout<<"Contact with same name not found."<<endl;
			    }  
	    	}
	    	else if(choice==2)
	    	{
	    		bool check=false;
	    		cout<<"Enter the Number to Delete: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(check==true)
	        	{
	            	int choice;
	            	cout<<"Press 1 to delete the contact shown:";
	        	    cin>>choice;
    	        	if(choice==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;
    	        		temp->prev=NULL;
	            		head=temp;
	            		cout<<"Contact is deleted successfully."<<endl;
			    	}
				    else if(choice==1 & temp->next==NULL)
    				{
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout<<"Contact is deleted successfully."<<endl;
				    }
				    else if(choice==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
		    			cout<<"Contact is deleted successfully."<<endl;	
			    	}
				    else
				    {
				    	cout<<"Wrong Entry......Try again"<<endl;
				    }
	            }
	            else if(check==false)
				{
					cout<<"Contact with same number not found. "<<endl;
				}
	    	}
	    	else
	    	{
	    		cout<<"Mismatch choice.Try again."<<endl;
			}
			getch();
			cout << "\033[2J\033[1;1H";
            return 0;
	    }

	    void bubbleSort() // Used for sorting contact alphabetically
        {
        	Node *temp=head;
            Node *i,*j;
            char n[25];
            long long int n2;
            if(temp==NULL)
            {
            	cout<<"Contact book is empty."<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if (strcmp(i->name, j->name) > 0)
		                {
                            strcpy(n, i->name);
							strcpy(i->name, j->name);
							strcpy(j->name, n);
                            n2=i->phone_number;
                            i->phone_number=j->phone_number;
                            j->phone_number=n2;
                        }
                    }
                }
            }
        }
        
        int editContacts() //Edit contact by both name and number
    	{
	    	Node *temp=head;
	    	cout<<"--------------------------------------------------------------------------"<<endl;
	    	cout<<"Press 1 for searching by Name."<<endl;
	    	cout<<"Press 2 for searching by Number."<<endl;
	    	int choice;
	    	cout<<"Enter your choice:";
	    	cin>>choice;
	    	if(choice==1)
	    	{
	    		bool Echeck=false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	    cout<<"Name of Contact:";
		        cin.getline(x,25);
	    		while(temp!=NULL)
	    		{
	    	    	if (strcmp(temp->name, x) == 0)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}				
	        	if(Echeck==true)
	        	{
	            	int option;
	        	    cout<<"Press 1 to Edit the Contact:";
	            	cin>>option;
	        	    if(option==1)
	        	    {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	        cout<<"Name of Contact: ";
		            cin.getline(x,25);
		            strncpy(temp->name, x, 25);
	            		cout<<"Enter New Number: ";
	            		cin>>y;	
	        	    	temp->phone_number=y;
	        		
	        		    cout<<"Contact Edited Successfully."<<endl;
			    	}
			    	else
			    	{
					    cout<<"Wrong Entry......Try again"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false)
	    	    {
	    	    	cout<<"Contact with same name not found. "<<endl;
				}
	        }
	    	else if(choice==2)
	    	{
	    		bool Echeck=false;
	    		cout<<"Enter the Number to Edit: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		cout<<"Name:"<<temp->name<<endl;
		        		cout<<"Phone Number:"<<temp->phone_number<<endl;
		        		cout<<"--------------------------------------------------------------------------"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true)
	        	{
	            	int option;
	        	    cout<<"Press 1 to Edit the Contact: ";
	            	cin>>option;
	        	    if(option==1)
	        	    {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	   		cout<<"Name of Contact:";
		        	cin.getline(x,25);
		       		strncpy(temp->name, x, 25);
	            		cout<<"Enter New Number:";
	            		cin>>y;
	        	    	temp->phone_number=y;
	        		
	        		    cout<<"Contact Edited Successfully."<<endl;
			    	}
			    	else
			    	{
					    cout<<"Wrong Entry......Try again"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"Contact with same number not found. "<<endl;
	            }
	        }
	        else
			{
			    cout<<"Mismatch choice.Try again."<<endl;
			}
			getch();
			cout << "\033[2J\033[1;1H";
            return 0;
	    }
    	
    	void oflineSave() //for saving name and number in txt file
    	{
    		Node *temp=head;
    		ofstream myfile ("contactbook.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->phone_number<<endl;
    		    	temp=temp->next;		
	        	}
                myfile.close();
                structure();
            }
            else
            {
            	cout<<"File is empty."<<endl;
			}
		}
		
		void reopenCB() 
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
				string line;
                while(std::getline(myfile,line))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          strcpy(newer->name, line.c_str());
	                      newer->next=NULL;
	                      newer->prev=NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							 strcpy(newer->name, line.c_str());
							newer->next=NULL;
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0)
                    	{
                    		 stringstream convert(line);
			       	         convert>>y;
                             temp->phone_number=y;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	stringstream convert(line);
			       	        convert>>y;
		                	temp->phone_number=y;
						}
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"File is Empty so Cannot open...Sorry."<<endl;
			}
		}

		void structure() // For showing choices to user
    	{
			HANDLE console_color;
    		console_color = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console_color,0);
	    	cout<<"===================================================================================="<<endl;
	    	cout<<"1. Add Contact"<<endl;
	    	cout<<"2. Edit the Contact"<<endl;
	    	cout<<"3. Search Contact"<<endl;
	    	cout<<"4. Delete Contact"<<endl;
	    	cout<<"5. Delete All Contacts"<<endl;
	    	cout<<"6. Display All Contacts"<<endl;
            cout<<"7. Exit"<<endl;
	    	cout<<endl<<endl;
	    	int options;
	    	cout<<"Enter the Command: ";
	    	cin>>options;
				SetConsoleTextAttribute(console_color, options);
	    	try
	    	{
	    		if(options>=1&&options<=7)
	    		{
	    			if(options==1)
	            	{
	            		createNode();
	            		oflineSave();
	    	        	structure();
	            	}
	            	else if(options==2)
		        	{
		        		editContacts();
		        		oflineSave();
		        		structure();
			        }
	            	else if(options==3)
	            	{
	    	        	search();
	    	        	structure();
	            	}
	            	else if(options==4)
	            	{
						deleteContactBySearch();
	            		structure();
	            	}
	            	else if(options==5)
	            	{    
						deleteAllContacts();
	            		oflineSave();
	            		structure();	  		
	            	}
	            	else if(options==6)
	            	{
	            		display();
	            		oflineSave();
	            		structure();	
		        	}
                    else if(options==7)
                    {
                        exit (0);
                    }
				}
				else
				{
					throw(options);
				}
			}
			catch(int options)
			{
				cout<<"Wrong choice. Enter correct choice AGAIN."<<endl;
				structure();
			}	
	    }
    	
};

int main() //Main function
{   
    ContactBook cb;
    cb.reopenCB();
	cb.structure();
	return 0;
}