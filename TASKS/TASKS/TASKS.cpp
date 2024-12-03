#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
using namespace std;

class Tasks
{
public:
	string getName() const
	{
		return name;
	}
	string getTask() const
	{
		return task;
	}

	Tasks(string task, string name, int days = 0,double time = 0.0)
	{
		this->time = time;
		this->days = days;
		this->name = name;
		this->task = task;

		cout << "\'" << task << "\' added to base. Info:\n" << "*working - " << name << "\n*time to make - " << time
			<< "\n*working term - " << days << endl << endl;
	}

	void display() const
	{
		cout << "Task: " << task << "\n"
			<< "*Working: " << name << "\n"
			<< "*Time to make: " << time << "\n"
			<< "*Working term: " << days << endl << endl;
	}

private:
	int days;
	double time;
	string name;
	string task;
};


void addTask(vector<Tasks>& taskV)
{
	int days;
	double time;
	string name, task;

	cout << "Input task name: ";
	cin.ignore();					// прибирання допоміжних символів по типу "\n"
	getline(cin, task);				// запис рядка

	cout << "Input working name: ";
	getline(cin, name);

	cout << "Input working term (or just 0): ";
	cin >> days;

	cout << "Input time to make (or just 0): ";
	cin >> time;
	cout << endl;

	taskV.emplace_back(task, name, days, time);		// додавання у вектор 
}

void searchTask(const vector<Tasks>& taskV)			// передається посилання на вектор для оптимізації
{
	int ch = 0;
	cout << "Menu: 1. Search by Task name ; 2. Search by working name" << endl;
	cin >> ch;
	string searchTask;
	string searchName;

	switch (ch)
	{
	case 1:
		cout << "Input text: ";
		cin.ignore();
		getline(cin, searchTask);

		for (const auto& task : taskV) {				// пошук по вектору через ітератор
			if (task.getTask() == searchTask) {			// якщо ітератор = елементу, що шукається
				cout << "Task found!" << endl << endl;
				task.display();
				return;
			}
		}
		cout << "Task named \"" << searchTask << "\" not found.\n";
		break;

	case 2:
		cout << "Input text: ";
		cin.ignore();
		getline(cin, searchName);

		for (const auto& task : taskV) {
			if (task.getName() == searchName) {
				cout << "Task found!" << endl << endl;
				task.display();
				return;
			}
		}
		cout << "Task named \"" << searchName << "\" not found.\n";
		break;
	default:
		cout << "Invalid number, please try again" << endl;
	}
}

void allTask(const vector<Tasks>& taskV)
{
	// Лямбда-функція
	for_each(taskV.begin(), taskV.end(), [](const Tasks& task) {	// перебір всього вектору та вивід всіх елементів
		task.display();
		cout << "--------------------\n";
	});
}

int main()
{

	Tasks t1("Wash cup", "Igor");
	Tasks t2("Clean room", "Mike", 5);
	Tasks t3("Buy boots", "Alex", 0.30);
	Tasks t4("Make food", "Vitalii", 1 , 3.00);
	vector<Tasks> taskV = { t1, t2, t3, t4 };

	int c = 0;
	while(true)
	{
		cout << "Menu: 1. Add task; 2. Search task; 3. Display all tasks; 4. Exit" << endl;
		cin >> c;

		switch (c)
		{
		case 1:
			addTask(taskV);
			break;
		case 2:
			searchTask(taskV);
			break;
		case 3:
			allTask(taskV);
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid number, please try again" << endl;
		}
	}

	system("pause");
}
