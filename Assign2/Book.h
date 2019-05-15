//**********************************************************
// File:	Book.h
// Author:	Luis Aguinaga
// Logon ID	z1811673
// Due Date:	09/20/2016
//
// Purpose:	Contains the declaration for the Book Class.
//**********************************************************

#ifndef BOOK_H
#define BOOK_H

class Book
{
	public:
		Book(); //constructor
		//alternate constructor takes in four parameters
		Book(char* newISBN, char* newTitle, double newPrice, int newQuantity);
		//get method returns isbn.
		char* getISBN();
		//get method returns title.
		char* getTitle();
		//get method returns price.
		double getPrice();
		//get method returns quantity.
		int getQuantity();
		//set method returns double price
		void setPrice(double);
		//set method returns  nothing
		void setQuantity(int);
		int fulfillOrder(int);
		void print();
	private:
		char isbn[11]{};
		char title[41]{};
		double price = 0;
		int  quantity = 0;
};
#endif
