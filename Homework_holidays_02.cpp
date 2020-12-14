#include <iostream>

using namespace std;

class CPerson
{
protected:
	string name;
	string lastName;
	string patronymic;
public:
	CPerson(string _name, string _lastN, string _patron) : name(_name), lastName(_lastN), patronymic(_patron){}
	~CPerson() = default;

	virtual void ShowData() = 0
	{
		cout << "Name: " << name << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Patronymic: " << patronymic << endl;
	}
};

class CStudent : public CPerson
{
private:
	float GPA;
public:
	CStudent(string _name, string _lastN, string _patron, float _gpa) : CPerson(_name, _lastN, _patron), GPA(_gpa)	{}
	~CStudent() = default;

	virtual void ShowData()
	{
		CPerson::ShowData();
		cout << "GPA: " << GPA << endl;
	}
};

enum Position
{
	Teacher,
	Senoir_teacher,
	Associate_professor,
	Professor
};

string printPosition(Position _posit)
{
	switch (_posit)
	{
	case Teacher:
		return "Teacher";		
	case Senoir_teacher:
		return "Senoir teacher";		
	case Associate_professor:
		return "Associate professor";		
	case Professor:
		return "Professor";		
	default:
		break;
	}
}

class CProfessor : public CPerson
{
private:
	int publication;
	Position posit;
	int age;
public:
	CProfessor(string _name, string _lastN, string _patron, int _publicat, Position _posit, int _age) : CPerson(_name, _lastN, _patron), publication(_publicat), posit(_posit), age(_age)	{}
	~CProfessor() = default;

	virtual void ShowData()
	{
		CPerson::ShowData();
		cout << "Publication: " << publication << endl;
		cout << "Position: " << printPosition(posit) << endl;		
		cout << "Age: " << age << endl;
	}
};


int main()
{
	const int sizeArr = 5;

	CPerson *massPers[sizeArr]
	{
		new CProfessor("Ivan", "Petrov", "Semenovoch", 3, Teacher, 32),
		new CStudent("Andrei", "Smirnov", "Petrovich", 8.6),
		new CStudent("Ekaterina", "Sokolova", "Aleksandrovna", 9.8),
		new CProfessor("Petr", "Ivanov", "Ivanovich", 15, Professor, 56),
		new CStudent("Dmitri", "Mihailov", "Petrovich", 8.6)
	};

	for (size_t i = 0; i < sizeArr; i++)
	{
		massPers[i]->ShowData();
		cout << endl;
	}	

	for (size_t i = 0; i < sizeArr; i++)
	{
		delete massPers[i];
	}	

	system("pause");
	return 0;
}
