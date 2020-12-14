#include <iostream>

using namespace std;

class Property
{
protected:
	int worth;
public:
	Property(int _worth) : worth(_worth) {}
	virtual int TaxCalculation() = 0;
};

class Appartment : public Property
{
public:
	Appartment(int _worth) : Property(_worth) {}

	virtual int TaxCalculation()
	{
		return worth / 1000;
	}
};

class Car : public Property
{
public:
	Car(int _worth) : Property(_worth) {}

	virtual int TaxCalculation()
	{
		return worth / 200;
	}
};

class CountryHouse : public Property
{
public:
	CountryHouse(int _worth) : Property(_worth) {}

	virtual int TaxCalculation()
	{
		return worth / 500;
	}
};


int main()
{
	const int sizeArr = 7;

	Property *prop[sizeArr]{		
		new Appartment(500000),
		new Appartment(350000),
		new Appartment(10000),
		new Car(15000),
		new Car(3000),
		new CountryHouse(150000),
		new CountryHouse(50000)
	};	

	for (size_t i = 0; i < sizeArr; i++)
	{
		cout << prop[i]->TaxCalculation() << endl;
	}

	for (size_t i = 0; i < sizeArr; i++)
	{
		delete prop[i];
	}


	system("pause");
	return 0;
}
