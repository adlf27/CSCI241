//*****************************************************************
   // FILE:      BookStore.h
   // AUTHOR:    Luis Aguinaga
   // LOGON ID:  z1811673
   // DUE DATE:  09/20/2016
   // 
   // PURPOSE:   Contains the declaration for the BookStore class.
   //*****************************************************************
#ifndef BOOKSTORE_H // header guard 
#define BOOKSTORE_H

#include "Book.h"

class BookStore
{

	private:
		Book bookobject[30]; //array of 30 book objects
		int num_bk_stored = 0; //number of books actually stored in array
	public:
		BookStore(); //constructor
		BookStore(const char*); //alternate constructor
		//function prototypes
		void sortByISBN();
		int searchForISBN(char*);
		void processOrder(const char*);
		void print();
};



#endif
