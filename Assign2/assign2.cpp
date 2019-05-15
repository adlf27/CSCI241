#include <iostream>
#include "Book.h"
#include "BookStore.h"

using std::cout;
using std::endl;

int main()
{
	BookStore Bk("bookdata");
	Bk.print();
	Bk.processOrder("orders.txt");
	Bk.print();
	return 0;
}
