#ifndef Product_h
#define Product_h
using namespace std;

class Product
{
public:
	virtual double getGrossPrice();
	Product(double);
protected:
	double netPrice;
};
#endif