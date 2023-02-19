#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>

using namespace std;

char re = 'y';

void swap(int &a, int &b) //swaps integers a and b
{
	int temp=a;
	a=b;
	b=temp;
}

void bar(int l) //generates bar of length l
{
	int i;
	cout << "  [";
	for(i=0; i<l; i++)
		cout << "=";
	cout << "]" <<endl;
}

void list(int a[],int size) //lists elements of array
{
	int i;
	cout << "  >";
	for(int i=0; i<size; i++)
		cout<< " " << a[i];
	cout << endl;
	
}

void display(int a[], int size) //displays full array as list of bars
{
	int i;
	
	cout<<endl;
	for(i=0; i<size; i++)
		bar(a[i]);
	cout<<endl;
}

bool csort(int a[],int size) //checks if array is sorted
{
	int i, j;
	
	for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(a[j]> a[j+1])
			{
				return 0;
			}
		}
	}
	return 1;
	
}

void bubble(int a[], int size) //bubble sort step by step
{
	int i, j;
	
	system("CLS");
	cout << endl;
	cout<<" ***************                  Bubble Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout<<endl;
	list(a,size);
	display(a,size);
	getch();
	
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto askb;
	}
	
	for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(a[j]> a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
		
		system("CLS");
		cout << endl;
	    cout << " ***************                  Bubble Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i+1 << endl;
		cout << endl;
		list(a,size);
		display(a,size);
		
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		getch();

	}
	
	askb:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto askb;
	}
		
}

void abubble(int a[], int size) //bubble sort with clock
{
	int i, j;
	
	system("CLS");
	cout << endl;
	cout<<" ***************                  Bubble Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout << endl;
	list(a,size);
	display(a,size);
	sleep(2);
	
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto askba;
	}
	
	for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-1; j++)
		{
			if(a[j]> a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
				
		system("CLS");
		cout << endl;
	    cout << " ***************                  Bubble Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i+1 << endl;
		cout << endl;
		list(a,size);
		display(a,size);
		
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		usleep(15000); //delay of 150ms

	}
	
	askba:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto askba;
	}
		
}

void selection(int a[], int size) //selection sort step by step
{
	int i,j,mn;
	
	system("CLS");
	cout << endl;
	cout << " ***************                  Selection Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout << endl;
	list(a,size);
	display(a,size);
	getch();
	
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto asks;
	}
	
	for (i = 0; i < size; i++) 
	{
		mn = i;
		for (j = i + 1; j < size; j++) 
		{
			if (a[j] < a[mn]) 
				mn = j;
		}
		
		swap(a[mn], a[i]);
		
		system("CLS");
		cout << endl;
	    cout << " ***************                  Selection Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i+1 << endl;
		cout << endl;
		list(a,size);
		display(a,size);
		
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		getch();
		
	}
	
	asks:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto asks;
	}
}

void aselection(int a[], int size) //selection sort with clock
{
	int i,j,mn;
	
	system("CLS");
	cout << endl;
	cout << " ***************                  Selection Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout << endl;
	list(a,size);
	display(a,size);
	sleep(2);
	
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto asksa;
	}
	
	for (i = 0; i < size; i++) 
	{
		mn = i;
		
		for (j = i + 1; j < size; j++) 
		{
			if (a[j] < a[mn]) 
				mn = j;
		}
		
		swap(a[mn], a[i]);
		
		system("CLS");
		cout << endl;
	    cout<<" ***************                  Selection Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i+1 << endl;
		cout<<endl;
		list(a,size);
		display(a,size);
		
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		usleep(15000); //delay of 150ms
		
	}
	
	asksa:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto asksa;
	}
}


void insertion(int a[], int size) //insertion sort step by step
{
	int i, j, k;
	
	system("CLS");
	cout << endl;
	cout << " ***************                  Insertion Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout << endl;
	list(a,size);
	display(a,size);
	getch();
	
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto aski;
	}
	
	for(int i=1; i  < size; i++) 
	{
		int j = i;
		
		for(j=i; j>0; j--)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
			}
		}
		
		system("CLS");
		cout << endl;
	    cout << " ***************                  Insertion Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i << endl;
		cout << endl;
		list(a,size);
		display(a,size);
	
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		getch();
		
	}
	
	aski:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto aski;
	}
	
}


void ainsertion(int a[], int size) //insertion sort with clock
{
	int i, j, k;
	
	system("CLS");
	cout << endl;
	cout << " ***************                  Insertion Sort                  *************** ";
	cout << endl;
	cout << endl << "\tInitial Array::" << endl;
	cout << endl;
	list(a,size);
	display(a,size);
	sleep(2);
	if(csort(a, size))
	{
		cout << "\tArray is already sorted! " << endl;
		getch();
		goto askia;
	}
	
	for(int i=1; i  < size; i++) 
	{
		int j = i;
		
		for(j=i; j>0; j--)
		{
			if(a[j] < a[j-1])
			{
				swap(a[j], a[j-1]);
			}
		}
		
		system("CLS");
		cout << endl;
	    cout << " ***************                  Insertion Sort                  *************** ";
		cout << endl;
		cout << endl << "\tFor Iteration  :: " << i << endl;
		cout << endl;
		list(a,size);
		display(a,size);
	
		if(csort(a, size))
		{
			cout << "\tArray is sorted! " << endl;
			break;
		}
		
		usleep(15000); //delay of 150ms
		
	}
	
	askia:cout << endl << "   Do you wish to continue? (y/n) ";
	cin >> re;
	
	if(re=='y'|| re == 'n')
		return;
	else
	{
		cout << "Invalid input.";
		goto askia;
	}
	
}

void rgen() // for randomly generating array
{
	int size, i;
	
	rstart:
	
	system("CLS"); 
	cout << endl;
    cout << " ***************                 SORTING TECHNIQUES USING C++                 *************** ";
	cout << endl << endl;
	
	cout << "   Enter size of array      ::  ";
	sinput:cin >> size;
	
	if (cin.fail())
	{
    	cin.clear();
		cin.ignore(512, '\n');
    	cout << "   Input is not a number. Input a valid number :: ";
    	goto sinput;
	}
	
	if( size<0 || size>50)
	{
		cout << "   Invalid Size. Enter another size for array  :: ";
		goto sinput;
	}
		
	int array[size];
	srand(time(0)); //randomises program time
	
	cout << "   Randomly Generated Array :: ";
	for(int i=0; i<size; i++)
	{
		array[i]=rand()%100; //assigns a random value from 0 to 99
	}
	
	list(array,size);
	display(array,size);
	
	int choice;
	
    cout << " ***************                  Select method for sorting::                  *************** ";
	cout << endl;
	cout << "\n  [1] Bubble Sort\t\t[11] Step-by-step Bubble Sort  \n  [2] Selection Sort\t\t[22] Step-by-step Selection Sort  \n  [3] Insertion Sort\t\t[33] Step-by-step Insertion Sort  \n  [5] Generate Array   \n  [9] Back   \n";
	choice:printf("\n     >>  ");
	cin >> choice;		
	switch(choice)
	{
		case 1:
			abubble(array,size);
			break;
		case 2:
			aselection(array,size);
			break;
		case 3:
			ainsertion(array,size);
			break;
		case 11:
			bubble(array,size);
			break;
		case 22:
			selection(array,size);
			break;
		case 33:
			insertion(array,size);
			break;
		case 5:
			goto rstart;
		case 9:
			return;
		default:
			if (cin.fail())
			{
		    	cin.clear(); //flushes cin
				cin.ignore(512, '\n');
			}
			cout << " Invalid input! Enter valid input! ";
			goto choice;
	}
	
}

void mgen() //for manually inputting array
{
	int size, i;
	
	rstart:
	
	system("CLS"); 
	cout << endl;
    cout << " ***************                 SORTING TECHNIQUES USING C++                 *************** ";
	cout << endl << endl;
	
	cout << "   Enter size of array      ::  ";
	sinput:cin >> size;
	
	if (cin.fail())
	{
    	cin.clear(); //flushes cin
		cin.ignore(512, '\n');
    	cout << "   Input is not a number. Input a valid number :: ";
    	goto sinput;
	}
	
	if( size<0 || size>50)
	{
		cout << "   Invalid Size. Enter another size for array  :: ";
		goto sinput;
	}
		
	int array[size];
	srand(time(0));
	
	cout << "   Input array elements     ::  ";
	for(int i=0; i<size; i++)
	{
		cin >> array[i];
	}
	
	system("CLS"); 
	cout << endl;
    cout << " ***************                 SORTING TECHNIQUES USING C++                 *************** ";
	cout << endl << endl;
	
	cout << "   No of elements in array      ::  " << size << endl;
	cout << "   Array elements               ::  ";
	
	list(array,size);
	display(array,size);
	
	int choice;
	
    cout << " ***************                  Select method for sorting::                  *************** ";
	cout << endl;
	cout << "\n  [1] Bubble Sort\t\t[11] Step-by-step Bubble Sort  \n  [2] Selection Sort\t\t[22] Step-by-step Selection Sort  \n  [3] Insertion Sort\t\t[33] Step-by-step Insertion Sort  \n  [5] Generate Array   \n  [9] Back   \n";
	choice:printf("\n     >>  ");
	cin >> choice;		
	switch(choice)
	{
		case 1:
			abubble(array,size);
			break;
		case 2:
			aselection(array,size);
			break;
		case 3:
			ainsertion(array,size);
			break;
		case 11:
			bubble(array,size);
			break;
		case 22:
			selection(array,size);
			break;
		case 33:
			insertion(array,size);
			break;
		case 5:
			goto rstart;
		case 9:
			return;
		default:
			if (cin.fail())
			{
		    	cin.clear();
				cin.ignore(512, '\n');
			}
			cout << " Invalid input! Enter valid input! ";
			goto choice;
	}
	
}

int main()
{
	int size, i;
	sstart:
	
	system("CLS"); 
	cout << endl;
    cout << " ***************                 SORTING TECHNIQUES USING C++                 *************** ";
	cout << endl << endl;
	int choice;
	
    cout << "                                             MENU                                             ";
	cout << endl;
	cout << "\n  [1] Generate Random Array \n  [2] Manually Input Array  \n  [9] Exit   \n";
	minput:cout << "\n     >>  ";
	cin >> choice;
			
	switch(choice)
	{
		case 1:
			rgen();
			break;
		case 2:
			mgen();
			break;
		case 9:
			exit(0);
		default:
			if (cin.fail())
			{ 
		    	cin.clear(); //flushes cin
				cin.ignore(512, '\n');
			}
			cout << " Invalid input! Enter valid input! ";
			goto minput;
	}
	
	if(re=='y')
		goto sstart;
		
}



