#ifndef Book_h
#define Book_h
#include "Product.h"
using namespace std;

class Book : public Product
{
public:
	Book(double);
	double getGrossPrice();
};
#endif