#include <iostream>
#include <fstream>
#include <iomanip>
#include "BookStore.h"
#include <cstring>

using std::fixed;
using std::setprecision;
using std::strcpy;
using std::strcmp;
using std::setw;
using std::right;
using std::left;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

//default constructor
BookStore::BookStore()
{
}
//alternate constructor that takes one paramater, name of the database file.
BookStore::BookStore(const char* file_name)
{
	ifstream infile; //decleres a input file stream
	infile.open(file_name, ios::binary);
// if loop to check if the file open succesfully.
	if(infile)
	{
		infile.read((char*) this, sizeof(BookStore));
		infile.close();
	}
	else
	{
		cout << "Error opening file." << endl;
	}
	sortByISBN();


}
//print method, takes no parameters, returns nothing.
// prints the book objects from the database file.
void BookStore::print()
{
	cout << "Book Inventory Listing" << endl;
	cout <<left<<setw(14)<< "ISBN" << left << setw(44) <<  "Title" << right << setw(5) << "Price" << right << setw(6)<< "Qty"<< endl;
	cout << endl;
//for loop to print each element of the database file
	for(int i=0; i < num_bk_stored; i++)
	{
		cout << left << setw(14) <<  bookobject[i].getISBN();
		cout << left << setw(44) <<  bookobject[i].getTitle();
		cout << right << setw(5) << fixed << setprecision(2) << bookobject[i].getPrice();
		cout << right << setw(6) << bookobject[i].getQuantity();
		cout << endl;
	}
}
//this method takes no paramete and returns nothing.
//it sorts the isbn for ascending order
void BookStore::sortByISBN()
{
	int i, j;
	Book bucket;
//for loop to get the  amount of books stored in file
	for(i = 1; i < num_bk_stored; i++)
	{
		bucket.getISBN() ==  bookobject[i].getISBN();
//for loop to compare  the book objects to the bucket
		for(j = i; (j>0) && (strcmp(bookobject[j-1].getISBN(), bucket.getISBN()) > 0); j--)
		{
			bookobject[j].getISBN() == bookobject[j-1].getISBN();
		}
		bookobject[j].getISBN() == bucket.getISBN();
	}
}
//this method takes one parameter and returns an integer
//this method checks for the isbn from the file 
int BookStore::searchForISBN(char* searchISBN)
{
	int low = 0;
	int high = num_bk_stored - 1;
	int mid;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(bookobject[mid].getISBN(), searchISBN) == 0)
			return mid;
		if(strcmp(bookobject[mid].getISBN(), searchISBN) < 0)
			high =  mid - 1;
		else
			low = mid + 1; 
	}
	return -1;

}
//method takes in one parameter and returns nothing.
//proccess the order of the books in the file by searching for isbn.
void BookStore::processOrder(const char* orderFile)
{
	ifstream infile;
	char orderNumber[7];
	char isbn[11];
	int orderQuantity;
	int numShipped;

	infile.open(orderFile);
//checks if file was open succesfully
	if(infile)
	{
		infile >> orderNumber[7];
//while loop contiues until it reaches the end of the file
		while(!infile.eof())
		{
			infile >> isbn[11];
			infile >> orderQuantity;

			int index = searchForISBN(isbn);
			if(index == -1)
			{
				cout << "Error ISBN does not exit." << endl;
			}
			else
			{
				numShipped = bookobject[index].fulfillOrder(orderQuantity);
				cout<< "Order Listing" << endl;
				cout << "Order " << orderNumber[7] << ": ";
				cout << " ISBN " << isbn << ", ";
				cout << numShipped << " of " << orderQuantity << " shipped, ";
				cout << "order total $ " << orderQuantity * bookobject[index].getPrice();
				cout << endl;
			}
			infile >> orderNumber[7];
		}
		infile.close();

	}
	else
		cout << "Cannot open File." << endl;
}

