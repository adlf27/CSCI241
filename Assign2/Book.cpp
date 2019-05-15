#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::strcpy;
using std::setprecision;
using std::fixed;
//default book constructor
Book::Book()
{
}
//alternate constructor takes in four parameter
Book::Book(char* newISBN, char* newTitle, double newPrice, int newQuantity)
{
	//initilizes data members
	strcpy(isbn, newISBN);
	strcpy(title, newTitle);
	setPrice(newPrice);
	setQuantity(newQuantity);

}
//getISBN method return the isbn and takes no parameters
char* Book::getISBN()
{
	return isbn;
}
//getTitle method takes no parameter, returns  the title
char* Book::getTitle()
{
	return title;
}
//getPrice method returns a double and takes no parameters.
//gets the price
double Book::getPrice()
{
	return price;
}
//this method gets the qauntity returns an in and takes no parameters
int Book::getQuantity()
{
	return quantity;
}
//this method sets the price. returns nothing and takes in one paramater
void Book::setPrice(double  newPrice)
{
//if loop to check if new price is greater than  or eqaul to 0
	if(newPrice >= 0)
	{
		price = newPrice;
	}
	else
		price = 0;
}
//sets qauntitu method. returns nothing, takes in one parameter
void Book::setQuantity(int newQuantity)
{
	if(newQuantity >= 0)
        {
                quantity = newQuantity;
        }
        else
                quantity = 0;

}
//this method takes in one parameter returns an int.
//purpose is to get the amount of books ordered and check if the 
//order can be process
int Book::fulfillOrder(int books_ordered)
{
	int num_bk_ship = 0;
//if loop to check if amount order is less than zero. if it is print error msg.
	if(books_ordered < 0)
	{
		cout << "The order cannot Process." << endl;

	} 
	else if(books_ordered <= quantity)
	{
		cout << "This order can be process." << endl;
		num_bk_ship = books_ordered;
		quantity -= books_ordered;
	}
	else
	{
		cout << "This order cannot be completely process." << endl;
		num_bk_ship = quantity;
		quantity = 0;
	}
	return num_bk_ship;


}
//print method. returns nothing, takes no paramaters.
//prints the isbn, title , price, and quantity of books
void Book::print()
{
	cout << setw(14) << left << isbn;
	cout << setw(44) << left << title;
	cout << setw(5) <<  right << fixed << setprecision(2)<< price;
	cout << setw(6) << right <<  quantity;
}
