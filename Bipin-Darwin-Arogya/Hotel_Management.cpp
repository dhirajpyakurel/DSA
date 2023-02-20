#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<conio.h>
using namespace std;
class Node
{
public:
	int id, date, cost, days;
	string name, roomtype;
	Node *next_add;
};

class Linked_List
{

public:
	Node *head = NULL;
	void insert()
	{

		fstream file;
		file.open("Customer_Details.txt", ios::app);

		int x, n, s, num, i, d;
		string rt, nm;
		cout << "\n\t\t\tEnter Room ID : ";
		cin >> i;
		cout << "\n\t\t\tEnter Customer Name : ";
		cin >> nm;
		cout << "\n\t\t\tEnter Allocated Date : ";
		cin >> d;

		cout << "\n\t\t\tWe have following rooms for you:-\n"
			 << endl;
		cout << "\t\t\t1.  Deluxe---->4000" << endl;
		cout << "\t\t\t2.  Suite---->3000" << endl;
		cout << "\t\t\t3.  Standard---->2000" << endl;
		cout << "\t\t\t4.  Joint---->1000" << endl;
		cout << "\n\t\t\tHow many rooms do you want?";
		cin >> num;
		cout << "\n\t\t\tChoose the room -> ";
		cin >> x;
		cout << "\n\t\t\tFor How Many Days Will You Stay? ";
		cin >> n;
		Node *new_node = new Node;
		new_node->days = n;
		if (x == 1)
		{
			cout << "\t\t\tYou have chosen room Deluxe." << endl;
			s = 4000 * n * num;
			new_node->cost = s;
			rt = "Deluxe";
		}

		else if (x == 2)
		{
			cout << "\t\t\tYou have chosen room Suite." << endl;
			s = 3000 * n * num;
			new_node->cost = s;
			rt = "Suite";
		}
		else if (x == 3)
		{
			cout << "\t\t\tYou have chosen room Standard." << endl;
			s = 2000 * n * num;
			new_node->cost = s;
			rt = "Standard";
		}
		else if (x == 4)
		{
			cout << "\t\t\tYou have chosen room Joint." << endl;
			s = 1000 * n * num;
			new_node->cost = s;
			rt = "Joint";
		}
		else
		{
			cout << "\t\t\tPlease choose a room " << endl;
		}
		cout << "\t\t\tThe cost of your room is = " << s << endl
			 << endl;
		cout << "\t\t\tThank You For Choosing Our Hotel!!!" << endl;

		new_node->id = i;
		new_node->date = d;
		new_node->name = nm;
		new_node->roomtype = rt;
		new_node->next_add = NULL;

		file << new_node->id << "\n";
		file << new_node->name << "\n";
		file << new_node->date << "\n";
		file << new_node->roomtype << "\n";

		if (head == NULL)
		{
			head = new_node;
		}
		else
		{
			Node *ptr = head;
			while (ptr->next_add != NULL)
			{
				ptr = ptr->next_add;
			}
			ptr->next_add = new_node;
		}
		cout << "\nRoom Details Inserted";
	}
	void search()
	{

		if (head == NULL)
		{
			cout << "\n\t\t\t The List is Empty";
		}
		else
		{
			int t_id, count = 0;
			cout << "\n\t\t\tEnter your Room ID : ";
			cin >> t_id;

			Node *ptr = head;
			while (ptr != NULL)
			{
				if (t_id == ptr->id)
				{
					cout << "\n\t\t\tRoom ID : " << ptr->id;
					cout << "\n\t\t\tCustomer Name : " << ptr->name;
					cout << "\n\t\t\tRoom Allocated Date : " << ptr->date;
					cout << "\n\t\t\tYour Room type is " << ptr->roomtype;
					count++;
				}
				ptr = ptr->next_add;
			}
			if (count == 0)
			{
				cout << "\n\nCannot Search";
			}
		}
		getch();
		return;
	}
	void count()
	{
		if (head == NULL)
		{
			cout << "\n\nLinked List Empty";
		}
		else
		{
			int c = 0;
			Node *ptr = head;
			while (ptr != NULL)
			{
				c++;
				ptr = ptr->next_add;
			}
			cout << "\n\nNumber of records : " << c;
		}
		getch();
	}

	void search_in_file()
	{
		printf("Enter ID of customer to Search: ");
		string id;
		cin >> id;
		string s1, s2, s3, s4;
		ifstream in("Customer_Details.txt");
		while (getline(in, s1) && getline(in, s2) && getline(in, s3) && getline(in, s4))
		{
			if (s1 == id)
			{
				cout << "Match Found for ID: " << id << endl;
				cout << "Id: " << s1 << endl;
				cout << "Name: " << s2 << endl;
				cout << "Date: " << s3 << endl;
				cout << "Room Type: " << s4 << endl;
			}
			else
			{
				continue;
			}
		}
		getch();
	}

	void update_in_list(){
		if (head == NULL)
		{
			cout << "\n\t\t\tThe List is Empty";
		}
		else
		{
			int t_id, found = 0;
			cout << "\n\t\t\tEnter Your Room ID : ";
			cin >> t_id;

			Node *ptr = head;

			while (ptr != NULL)
			{
				if (t_id == ptr->id)
				{

					cout << "\n\t\t\tEnter new Room ID : ";
					cin >> ptr->id;

					cout << "\n\t\t\tCustomer Name : ";
					cin >> ptr->name;

					cout << "\n\t\t\tAllocated Date : ";
					cin >> ptr->date;

					cout << "\n\t\t\tPlease Choose Your Room Here : ";

					prompt();
					cout << "\n\nRecord Updated Successfully";
					found++;
				}
				ptr = ptr->next_add;
			}
			if (found == 0)
			{
				cout << "\n\nUpdated Room ID " << t_id << "Can't Found";
			}
		}
		getch();
	}
	void update()
	{

		cout<<"\n\t\t\tEnter ID of customer to update: ";
		int num;
		string id;
		cin >> id;
		string s1, s2, s3, s4;
		ifstream in("Customer_Details.txt");
		ofstream out("temp.txt", ios::out);
		while (getline(in, s1) && getline(in, s2) && getline(in, s3) && getline(in, s4))
		{
			if (s1 == id)
			{
				cout << "\n\t\t\tEnter new ID: ";
				cin >> s1;
				cout << "\n\t\t\tEnter new name: ";
				cin >> s2;
				cout << "\n\t\t\tEnter new date: ";
				cin >> s3;
				cout << "\n\t\t\tWe have following rooms for you:-\n"
			 << endl;
				cout << "\t\t\t1.  Deluxe---->4000" << endl;
				cout << "\t\t\t2.  Suite---->3000" << endl;
				cout << "\t\t\t3.  Standard---->2000" << endl;
				cout << "\t\t\t4.  Joint---->1000" << endl;
				cout << "Enter new room type:";
				cin >> num;
		if (num == 1)
		{
			cout << "\t\t\tYou have chosen room Deluxe." << endl;
			s4 = "Deluxe";
		}

		else if (num == 2)
		{
			cout << "\t\t\tYou have chosen room Suite." << endl;
			;
			s4= "Suite";
		}
		else if (num == 3)
		{
			cout << "\t\t\tYou have chosen room Standard." << endl;
			s4 = "Standard";
		}
		else if (num == 4)
		{
			cout << "\t\t\tYou have chosen room Joint." << endl;
			s4= "Joint";
		}
		else
		{
			cout << "\t\t\tPlease choose a room " << endl;
			return;
		}

				
				out << s1 << endl
					<< s2 << endl
					<< s3 << endl
					<< s4 << endl;
			}
			else
			{
				out << s1 << endl
					<< s2 << endl
					<< s3 << endl
					<< s4 << endl;
			}
		}
		in.close();
		out.close();
		remove("Customer_Details.txt");
		rename("temp.txt", "Customer_Details.txt");
		getch();
	}

	void del()
	{
		if (head == NULL)
		{
			cout << "List is Empty";
		}
		else
		{

			int t_id, found = 0;
			cout << "\n\nEnter Student ID for Deletion";
			cin >> t_id;
			if (t_id == head->id)
			{
				Node *ptr = head;
				head = head->next_add;
				cout << "\n\nRecord Deleted Successfully";
				found++;
				delete ptr;
			}
			else
			{
				Node *pre = head;
				Node *ptr = head->next_add;
				while (ptr != NULL)
				{
					if (t_id == ptr->id)
					{
						pre->next_add = ptr->next_add;
						cout << "\n\nRecord Deleted Successfully";
						found++;
						delete ptr;
						break;
					}
					pre = ptr;
					ptr = ptr->next_add;
				}
			}
			if (found == 0)
			{
				cout << "\n\nCould not delete  " << t_id << "room id";
			}
		}
		getch();
	}

	void delete_from_file()
	{
		printf("Enter ID of customer to Delete: ");
		string id;
		cin >> id;
		string s1, s2, s3, s4;
		ifstream in("Customer_Details.txt");
		ofstream out("temp.txt", ios::out);
		while (getline(in, s1) && getline(in, s2) && getline(in, s3) && getline(in, s4))
		{
			if (s1 == id)
			{
				continue;
			}
			else
			{
				out << s1 << endl
					<< s2 << endl
					<< s3 << endl
					<< s4 << endl;
			}
		}
		in.close();
		out.close();
		remove("Customer_Details.txt");
		rename("temp.txt", "Customer_Details.txt");
		getch();
	}
	void show()
	{
		Node *ptr = head;
		if (head == NULL)
		{
			cout << "\n\nLinked List is Empty";
			return;
		}
		else
		{

			while (ptr != NULL)
			{

				cout << "\n\n Room ID : " << ptr->id;
				cout << "\n\n Customers Name : " << ptr->name;
				cout << "\n\n Customers Allocated Date : " << ptr->date;
				cout << "\n\n Customers Room Type: " << ptr->roomtype;
				ptr = ptr->next_add;
			}
		}
		getch();
		return;
	}
	void showFile()
	{
		string str;
		string s1, s2, s3, s4;
		int i = 1;
		ifstream in("Customer_Details.txt");
		while (getline(in, s1) && getline(in, s2) && getline(in, s3) && getline(in, s4))
		{
			cout << "\n\n\t\tCustomer " << i << ":" << endl;
			cout << "\n\t\tCustomer ID is : " << s1 << endl;
			cout << "\t\tCustomer Date is : " << s3 << endl;
			cout << "\t\tCustomer Name is : " << s2 << endl;
			cout << "\t\tCustomer Roomtype is : " << s4 << endl;
			i++;
		}
		getch();
		return;
	}

	void prompt()
	{
		int num;
		Node *ptr = head;
		cout << "\n\t\t\tWe have following rooms for you:-\n"
			 << endl;
		cout << "\t\t\t1.  Deluxe---->4000" << endl;
		cout << "\t\t\t2.  Suite---->3000" << endl;
		cout << "\t\t\t3.  Standard---->2000" << endl;
		cout << "\t\t\t4.  Joint---->1000" << endl;
		cout << "\n\t\t\tEnter a number : ";
		cin >> num;
		if (num == 1)
		{
			cout << "\t\t\tYou have chosen room Deluxe." << endl;
			ptr->roomtype = "Deluxe";
		}

		else if (num == 2)
		{
			cout << "\t\t\tYou have chosen room Suite." << endl;
			;
			ptr->roomtype = "Suite";
		}
		else if (num == 3)
		{
			cout << "\t\t\tYou have chosen room Standard." << endl;
			ptr->roomtype = "Standard";
		}
		else if (num == 4)
		{
			cout << "\t\t\tYou have chosen room Joint." << endl;
			ptr->roomtype = "Joint";
		}
		else
		{
			cout << "\t\t\tPlease choose a room " << endl;
			return;
		}
	}
};
int main()
{
	Linked_List obj;
	int choice;
	while (1)
	{
		system("cls");
		cout << "\n";
		cout << "\t\t\t\t\t\tWe Welcome You To Our Hotel" << endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------"<<endl;
		cout << "\t\t\t\t\t______You can easily book your rooms here______\n\n";
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		system("Color 0A");
		cout << "\n     \t\t\tOur Services                     \t\t\tDescription" << endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t1.Allocate Room                      ---->\t\tInsert New Room"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t2.Search Room                        ---->\t\tSearch Room with your RoomID"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t3. Search for records in file        ---->\t\tNo. of Records"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t4.Total Room Records                 ---->\t\tNo. of Records"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t5.Update Room (List)                 ---->\t\tUpdated Room Record"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t6.Update Room (File)                 ---->\t\tUpdated Room Record"<<endl;	
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t7.Delete Room                        ---->\t\tDelete Room with RoomID"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t8.Delete Room  Records from file     ---->\t\tDelete Room with RoomID"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t9.Display Room Records               ---->\t\tDisplay Room Records"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t10.Display From Files                ---->\t\tDisplay From Files"<<endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t11.Exit                              ---->\t\tExit Menu" << endl;
		cout<<"\t\t----------------------------------------------------------------------------------------------------------";


		cout << "\n\n\n\t\t\tEnter Your Choice : ";
		
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			obj.insert();
			break;

		case 2:
			system("cls");
			obj.search();
			break;
		case 3:
			system("cls");
			obj.search_in_file();
			break;
		case 4:
			system("cls");
			obj.count();
			break;

		case 5:
			system("cls");
			obj.update_in_list();
			break;
		case 6:
			system("cls");
			obj.update();
			break;	

		case 7:
			system("cls");
			obj.del();
			break;
		case 8:
			system("cls");
			obj.delete_from_file();
			break;
		case 9:
			system("cls");
			obj.show();
			break;
		case 10:
			system("cls");
			obj.showFile();
			break;
		case 11:
			cout << "\n\t\t\tProgram Terminated Successfully";
			exit(0);
		default:
			cout << "\n\t\t\tYou Entered Invalid Number";
			break;
		}
	}
	getch();
}