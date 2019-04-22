#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

struct State
{
	string Name, Capital, Language, Сhapter;
	uint16_t Population, Square, Money;
};

void CreateState(State* Gos, int p)
{
	for (int i = 0; i < p; i++)
	{
		cout << "Введите название " << i << " страны: \n";
		getline(cin, Gos[i].Name);
		cout << "Введите столицу страны: \n";
		getline(cin, Gos[i].Capital);
		cout << "Введите язык государства: \n";
		getline(cin, Gos[i].Language);
		cout << "Введите главу государства: \n";
		getline(cin, Gos[i].Сhapter);
		cout << "Введите численность населения: \n";
		cin >> Gos[i].Population;
		cout << "Введите занимаемую площадь: \n";
		cin >> Gos[i].Square;
		cout << "Введите денежную единицу: \n";
		cin >> Gos[i].Money;

		
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите количество государств: ";
	cin >> n;

	State* Gos = new State[n];
	CreateState(Gos, n);


	

}