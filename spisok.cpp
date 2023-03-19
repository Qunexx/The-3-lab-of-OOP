// The third lab of OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
//Перегрузка операторов


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <locale>
#include <windows.h>
#include "game.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Эта программа была сделана Андреем Романовым из ИВТ-21 \n";
	cout << "ЭЛЕМЕНТЫ СТРУКТУРЫ" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1)Присваивание одного элемента структуры данных другому" << endl;
	cout << "----------------------------------------------------------------" << endl;

	class Element* Graph1 = new Element("anton","ork","male","mage","20","213","180","80","1","1");
	class Element* Graph2 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "50", "1", "1");

	cout << "До:" << endl;
	cout << "{{firstGraph}}" << endl;
	cout << Graph1;
	cout << "{{secondGraph}}" << endl;
	cout << Graph2;

	Graph1 = Graph2;

	cout << "-----------------------------------------------------" << endl;
	cout << "После:" << endl;
	cout << "{{firstGraph}}" << endl;
	cout << Graph1;
	cout << "{{secondGraph}}" << endl;
	cout << Graph2;

	cout << "----------------------------------------------------------------" << endl;
	cout << "2)Сравнение на равенство структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "{{ == }}" << endl;

	 class Element* Graph3 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "50", "1", "1");
	class Element* Graph4 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "50", "1", "1");

	cout << "{{ firstGraph }}" << endl;
	cout << Graph3 << endl;
	cout << "{{ secondGraph }}" << endl;
	cout << Graph4 << endl;

	if (*Graph3 == *Graph4)
	{
		cout << "Графы равны" << endl;
	}
	else
	{
		cout << "Графы не равны" << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ != }}" << endl;

	class Element* Graph5 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");
	class Element* Graph6 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "50", "1", "1");

	cout << "{{ firstGraph }}" << endl;
	cout << Graph5 << endl;
	cout << "{{ secondGraph }}" << endl;
	cout << Graph6 << endl;

	if (*Graph5 != *Graph6)
	{
		cout << "Графы не равны" << endl;
	}
	else
	{
		cout << "Графы равны" << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "3)Cравнение элементов структуры данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	cout << "{{ < }}" << endl;

	class Element* Graph7 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");
	class Element* Graph8 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "90", "1", "1");

	if (*Graph7 < *Graph8)
	{
		cout << "Граф с " << Graph7->getWeight() << " с весом " << Graph7->getWeight() << " меньше чем " <<
			"граф c " << Graph8->getWeight() << " с весом " << Graph8->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ <= }}" << endl;

	class Element* Graph9 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");
	class Element* Graph10 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "79", "1", "1");

	if (*Graph9 <= *Graph10)
	{
		cout << "Граф с " << Graph9->getWeight() << " с весом " << Graph9->getWeight() << " меньше или равен чем " <<
			"граф c " << Graph10->getWeight() << " с весом " << Graph10->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ > }}" << endl;

	class Element* Graph11 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");
	class Element* Graph12 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "79", "1", "1");

	if (*Graph11 > *Graph12)
	{
		cout << "Граф с " << Graph11->getWeight() << " с весом " << Graph11->getWeight() << " больше " <<
			"граф c " << Graph12->getWeight() << " с весом " << Graph12->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ >= }}" << endl;

	class Element* Graph13 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");
	class Element* Graph14 = new Element("okcana", "ork", "female", "warrior", "22", "213", "150", "79", "1", "1");

	if (*Graph13 >= *Graph14)
	{
		cout << "Граф с " << Graph13->getWeight() << " с весом " << Graph13->getWeight() << " больше или равен " <<
			"граф c " << Graph14->getWeight() << " с весом " << Graph14->getWeight() << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "4)Вывод в поток элементов структуры данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	class Element* Graph15 = new Element("anton", "ork", "male", "mage", "20", "213", "180", "80", "1", "1");

	cout << Graph15 << endl;


	cout << "СТРУКТУРЫ ДАННЫХ" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "6)Присваивание одной структуры данных другой" << endl;
	cout << "----------------------------------------------------------------" << endl;

	class spisok* struct1 = new spisok();
	class spisok* struct2 = new spisok();
	struct1->initStruct();
	struct2->initStruct();

	cout << "----------------------------------------------------------------" << endl;
	cout << "Количество элементов до присваивания 1 структуры: " << struct1->amount()<< endl;
	cout << "Количество элементов до присваивания 2 структуры: " << struct2->amount() << endl;
	cout << "----------------------------------------------------------------" << endl;

	struct1 = struct2;

	cout << "Количество элементов после присваивания 1 структуры: " << struct1->amount() << endl;
	cout << "Количество элементов после присваивания 2 структуры: " << struct2->amount() << endl;

	cout << "----------------------------------------------------------------" << endl;
	cout << "7)Сравнение структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	spisok* struct3 = new spisok();
	spisok* struct4 = new spisok();

	struct3->initStruct();
	struct4->initStruct();
	



	if (*struct3 < *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " меньше чем {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 <= *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " меньше или равна {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 > *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " больше чем {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 >= *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " больше или равна {{" << struct4 << "}}" << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "7)Cравнение на равенство структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	spisok* struct5 = new spisok();
	spisok* struct6 = new spisok();

	struct5->initStruct();
	struct6->initStruct();

	if (*struct5 == *struct6)
	{
		cout << "Графы равны по весу между собой" << endl;
	}
	else if (*struct5 != *struct6)
	{
		cout << "Графы не равны между собой по весу" << endl;
	}
        
}




