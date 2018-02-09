#include "Product.h"
using namespace std;

Product::Product(double price)
{
	netPrice = price;
}

double Product::getGrossPrice()
{
	return netPrice * 1.21;
}