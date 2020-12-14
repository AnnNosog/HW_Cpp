#include <iostream>

using namespace std;

class Plan
{
private:
	string markOfPlan;
	string modelOfPlan;
	int maxSpeed;
	int maxHeight;
public:
	Plan(string _mark, string _model, int _speed, int _height) : markOfPlan(_mark), modelOfPlan(_model), maxSpeed(_speed), maxHeight(_height) {}

	virtual int Cost()
	{
		return maxSpeed * 1000 + maxHeight * 100;
	}

	void Information()
	{
		cout << "Mark of plan: " << markOfPlan << endl;
		cout << "Model of plan: " << modelOfPlan << endl;
		cout << "Maximum speed(km/h): " << maxSpeed << endl;
		cout << "Maximum height(m): " << maxHeight << endl;
		cout << "Cost of plan: " << Cost() << endl;
	}
};

class Bomber : public Plan
{
public:

	Bomber(string _mark, string _model, int _speed, int _height) : Plan(_mark, _model, _speed, _height) {}

	virtual int Cost() override
	{
		return Plan::Cost() * 2;
	}
};

class Fighter : public Plan
{
public:

	Fighter(string _mark, string _model, int _speed, int _height) : Plan(_mark, _model, _speed, _height) {}

	virtual int Cost() override
	{
		return Plan::Cost() * 3;
	}

};


int main()
{
	Plan plan("A310", "Airbus", 858, 11000);
	Bomber bomber("B-52", "Stratofortress", 957, 16765);
	Fighter fighter("F-22", "Raptor", 2410, 19812);

	plan.Information();

	cout << endl << endl;

	bomber.Information();

	cout << endl << endl;

	fighter.Information();


	system("pause");
	return 0;
}
