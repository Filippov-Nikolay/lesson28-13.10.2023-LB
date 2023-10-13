#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
#include <Windows.h>

using namespace std;

typedef pair<string, string> myPair;

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	/*
	deque<int> vec{ 1, 2, 3, 4, 5 };

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	cout << endl;


	// vector<int>::iterator ptr;


	vec.push_back(6);
	vec.insert(vec.begin()+2, 100);

	vec.pop_back();

	for (auto ptr = vec.begin(); ptr != vec.end(); ptr++) {
		cout << *ptr << endl;
	}
	cout << endl;
	*/

	/*
	list<int> arr{ 1, 2, 3, 4, 5 };

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;

	arr.push_front(100);
	arr.pop_front();
	arr.push_back(100);

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << endl;
	}
	*/

	/*
	multiset<int> arr{ 2, 5, 4, 1, 3, 6 };
	arr.insert(4);
	arr.insert(8);
	arr.insert(7);

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	*/

	/*
	multimap<int, string> arr;
	arr.insert(make_pair(1, "Hello"));
	arr.insert(pair<int, string>(2, "Привет"));
	arr.insert(myPair(3, "Hello hello"));
	arr.insert(myPair(3, "Hello hello"));

	for (auto it = arr.begin(); it != arr.end(); it++) {
		cout << it->first << " - " << it->second << endl;
	}
	*/

	/*
		Реализовать небольшой словарь
		1) Использовать контейнер map
		2) Функциональность: 
			добавление
			удаление
			редактирование
			поиск
		3) Предусмотреть меню
	*/

	map<string, string> arr;
	int userChoice = 0;
	int index = 1;
	bool flag = true;
	string temp = "";
	string temp1 = "";

	do {
		cout << "Меню: " << endl;
		cout << "1. Добавить" << endl;
		cout << "2. Удалить" << endl;
		cout << "3. Редактировать" << endl;
		cout << "4. Поиск" << endl;
		cout << "5. Вывод" << endl;
		cout << "0. Выход" << endl;
		cout << "> ";
		cin >> userChoice;

		if (userChoice > 5 || userChoice < 0) {
			cout << "Вы ввели неверный пункт меню!" << endl << endl;
		}
		else if (userChoice == 0) {
			cout << "До свидания!" << endl;
			break;
		}
		else {
			if (userChoice == 1) {
				do {
					cout << "Введите слово которое хотите добавить (англ): ";
					cin >> temp;

					if (temp == "Exit0")
						break;

					cout << "Введите слово которое хотите добавить (рус): ";
					cin >> temp1;
					
					arr.insert(myPair(temp, temp1));
									
					if (flag) {
						cout << "Для выхода напишите: Exit0" << endl << endl;
						flag = false;
					}
					
				} while (temp != "Exit0");
				cout << endl;
			}
			else if (userChoice == 2) {
				cout << "Введите слово которое хотите удалить(англ): ";
				cin >> temp;
				
				if (arr.find(temp) == arr.end())
					cout << "Такого слова нет!" << endl;
				else {
					arr.erase(arr.find(temp));
					cout << "Элемент удалён" << endl;
				}
			}
			else if (userChoice == 3) {
				cout << "Введите слово которое хотите редактировать(англ): ";
				cin >> temp;

				if (arr.find(temp) == arr.end())
					cout << "Такого слова нет!" << endl;
				else {
					auto it = arr.find(temp);

					cout << "Введите новое слово(рус): ";
					cin >> temp1;

					it->second = temp1;

					cout << "Элемент отредактирован" << endl;
				}
			}
			else if (userChoice == 4) {
				cout << "Введите слово которое хотите найти: ";
				cin >> temp;

				if (arr.find(temp) == arr.end())
					cout << "Слово не найдено!" << endl;
				else {
					auto it = arr.find(temp);
					cout << it->first << " - " << it->second << endl;				
				}
			}
			else if (userChoice == 5) {
				for (auto it = arr.begin(); it != arr.end(); it++) {
					cout << it->first << " - " << it->second << endl;
				}
				cout << endl;
			}
		}

	} while (userChoice != 0 || userChoice > 5 || userChoice < 0);

	return 0;
}