#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct State
{
	string Name, Capital, Language, Сhapter,Political,Money;
	uint16_t Population, Square;
};

void CreateState(State* Gos, int i)
{
	
	cout << "Введите название страны: \n";
	cin >> Gos[i].Name;
	cout << "Введите столицу страны: \n";
	cin >> Gos[i].Capital;
	cout << "Введите язык государства: \n";
	cin >> Gos[i].Language;
	cout << "Введите главу государства: \n";
	cin >> Gos[i].Сhapter;
	cout << "Введите государственный строй: \n";
	cin >> Gos[i].Political;
	cout << "Введите денежную единицу: \n";
	cin >> Gos[i].Money;
	cout << "Введите численность населения: \n";
	string Population;
	cin >> Population;

	int Population1 = atoi(Population.c_str());

	while (Population1 == 0)
	{
		cout << "Некорректное значение численности населения \n";
		cout << "Введите численность населения: \n";
		cin >> Population;
		Population1 = atoi(Population.c_str());

	}
	Gos[i].Population = Population1;
	cout << "Введите занимаемую площадь: \n";
	string Square;
	cin >> Square;

	int Square1 = atoi(Square.c_str());

	while (Square1 == 0)
	{
		cout << "Некорректное значение площади государства \n";
		cout << "Введите площадь государства: \n";
		cin >> Square;
		Square1 = atoi(Square.c_str());
	}

	Gos[i].Square = Square1;
}
		State* AddCreateState(State * Gos, int n)
		{
			State* tempGos = new State[n + 1];

			for (int i = 0; i < n; i++)
			{
				tempGos[i] = Gos[i];
			}
			delete[] Gos;

			Gos = tempGos;

			return Gos;
		}

		void Display(State* Gos, int n) 
		{
			system("cls");
			cout << "№" << "Государство\t" << "|Столица\t" << "|Язык\t" << "|Глава\t" << "|Строй\t" << "|Денежная единица\t" << "|Население\t" << "|Площадь\t" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < n; i++) 
			{
				cout << i + 1 << "  |" << Gos[i].Name << "  |" << "\t" << Gos[i].Capital << "  |" << "\t" << Gos[i].Language << "  |" << "\t" << Gos[i].Сhapter << "  |" << "\t" << Gos[i].Political << "  |" << "\t" << Gos[i].Population << "  |" << "\t" << Gos[i].Square << endl;
			}

			cout << endl;
			cout << endl;
	    }

		

		void FindState(State* Gos, int n) 
		{
			int number;
			string name,capital;
			cout << "1 <-- Найти государство по названию\n";
			cout << "2 <-- Найти государство по столице\n";
			cin >> number;
			switch (number)
			{
			case 1:
				cout << "Введите название государства";
				cin >> name;
				for (int i = 0; i < n; i++)
				{
					if (Gos[i].Name == name)

						cout << i + 1 << "  |" << Gos[i].Name << "  |" << "\t" << Gos[i].Capital << "  |" << "\t" << Gos[i].Language << "  |" << "\t" << Gos[i].Сhapter << "  |" << "\t" << Gos[i].Political << "  |" << "\t" << Gos[i].Population << "  |" << "\t" << Gos[i].Square << endl;

				}
			case 2:
				cout << "Введите столицу государства";
				cin >> capital;
				for (int i = 0; i < n; i++) 
				{
					if (Gos[i].Capital == capital)

					cout << i + 1 << "  |" << Gos[i].Name << "  |" << "\t" << Gos[i].Capital << "  |" << "\t" << Gos[i].Language << "  |" << "\t" << Gos[i].Сhapter << "  |" << "\t" << Gos[i].Political << "  |" << "\t" << Gos[i].Population << "  |" << "\t" << Gos[i].Square << endl;
				}
			default:
				break;
			}
			
		}

		void sortingState(State* Gos, int n)
		{
			int num = 0;
			for (int i = 0; i < n; i++) 
			{
				for (int j = num; j < n; j++)
				{
					if (Gos[i].Population < Gos[j].Population)
					{
						swap(Gos[i], Gos[j]);
						
					}
					
				}
				num++;
			}
			
		}



int main()
{
	setlocale(LC_ALL, "Russian");

	int n,i;
	cout << "Введите количество государств: ";
	cin >> n;

	State* Gos = new State[n];
	State* AddCreateState(State* Gos, int n);
	for (i = 0; i < n; i++)
	{
		CreateState(Gos, i);

	}
	

	int Answer;
	returnMenu:
	cout << "1 <-- Добавить страну.\n";
	cout << "2 <-- Вывести на экран.\n";
	cout << "3 <-- Найти.\n";
	cout << "4 <-- Сортировка\n";
	cin >> Answer;
	switch (Answer)
	{
	case 1:

		Gos = AddCreateState(Gos, n);
		n = n++;
		CreateState(Gos,i);
		i = i++;
		goto returnMenu;
	case 2:
		Display(Gos, n);
		goto returnMenu;
	case 3:
		FindState(Gos, n);
		goto returnMenu;
	case 4:
		sortingState(Gos,n);
		goto returnMenu;
	default:
		break;
	}
	
}
