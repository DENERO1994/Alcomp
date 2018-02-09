#include "Book.h"
#include "Product.h"
using namespace std;

Book::Book(double price):Product(price)
{
	netPrice = price;
}

double Book::getGrossPrice()
{
	return netPrice;
}
