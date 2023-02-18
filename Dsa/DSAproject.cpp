#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct Details
{
    char product[30];
    float price;
} temp;

void bubbleSortByName(Details arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].product, arr[j + 1].product) > 0)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortByPrice(Details arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].price > arr[j + 1].price)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSortByName(Details arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].product, arr[min_idx].product) < 0)
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void selectionSortByPrice(Details arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].price < arr[min_idx].price)
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSortByName(Details arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Details key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].product, key.product) > 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortByPrice(Details arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Details key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].price > key.price)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n, choice;
    cout << "Enter the number of products: " << endl;
    cin >> n;
    cout << endl;
    Details s[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the " << i + 1 << " product's name: ";
        cin >> s[i].product;
        cout << "Enter the price of " << s[i].product << ": ";
        cin >> s[i].price;
    }
    cout << endl;

    while (true)
    {
        cout << "The products you entered are:" << endl;
        cout << left << setw(20) << "Product" << setw(20) << "|" << setw(20) << "Price" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << left << setw(20) << s[i].product << setw(20) << "|" << setw(20) << s[i].price << endl;
        }
		cout<<endl;
        cout << "How would you like to sort the products?" << endl;
        cout << "1. Sort by name(Bubble sort)" << endl;
        cout << "2. Sort by price(Bubble sort)" << endl;
        cout << "3. Sort by name(Selection sort)" << endl;
        cout << "4. Sort by price(Selection sort)" << endl;
		cout << "5. Sort by name(Insertion sort)" << endl;
        cout << "6. Sort by price(Insertion sort)" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
            	cout<<"BUBBLE SORTING by name"<<endl;
                bubbleSortByName(s, n);
                break;
            case 2:
            	cout<<"BUBBLE SORTING by price"<<endl;
                bubbleSortByPrice(s, n);
                break;
            case 3:
            	cout<<"SELECTION SORTING by name"<<endl;
                selectionSortByName(s, n);
                break;
            case 4:
            	cout<<"SELECTION SORTING by price"<<endl;
                selectionSortByPrice(s, n);
                break;
            case 5:
            	cout<<"INSERTION SORTING by name"<<endl;
                insertionSortByName(s, n);
                break;
            case 6:
            	cout<<"INSERTION SORTING by price"<<endl;
                insertionSortByPrice(s, n);
                break;
            case 7:
            	cout << "Exiting program..." << endl;
                exit(0);
            case 8:
            	cout<<"INVALID CHOICE!!!"<<endl;
            	break;
        }
    }
    return 0;
}

