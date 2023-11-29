#include <iostream>
#include <time.h>
//#include "c_units.h"
#include "swordsmen.h"
#include "rifle.h"
#include "knight.h"
#include "Spearmen.h"
#include "Archer.h"


using namespace std;

int main() {
	//BaseUnit* a1 = new BaseUnit(0,1);
	//BaseUnit* a2 = new BaseUnit(5,1);

	setlocale(0, "Russian");
	srand(time(nullptr));

	int k = 0;//шаги
	int c = 0;//наносимый урон
	float s;//вытаскиваем получаемый урон
	float sum1=0 , sum2 = 0;//кто сколько урона нанёс за бой 
	/*
	/// a1 подходит к a2 на дистанцию атаки
	while (sqrt(pow(a1->get_x() - a2->get_x(), 2) + pow(a1->get_y() - a2->get_y(), 2)) > a1->get_range())
	{
		a1->go_forward();
		k++;
		cout << "Шаг " << k << endl;
		cout << "Запас сил " << a1->get_st() << endl;
	}

	cout << a1->get_x() << " " << a2->get_x() << endl;//вывели координаты

	//дерутся пока хотябы у одного есть хп
	while ((a1->get_health() > 0) and (a2->get_health() > 0))
	{
		 c = 0;//наносимый урон
		try { c = a2->get_damage(a1->get_x(), a1->get_y()); }//расчитываем урон если можем дотянуться до а1
		catch (const exception& error) { cout << error.what() << endl; }

		try {  a2->set_damage(c,s,a1); //a2 наносит урон a1
		
		}
		
		catch (const exception& error)
		{	
			cout <<"A1: "<< error.what() << endl;
		}

		sum2 = sum2 + s;

		if (a1->get_health() <= 0) { //если здоровье а1 равно или ниже 0

			cout << "A2 win" << endl;
			
			continue;//выходим из цикла
		}

		try { c = a1->get_damage(a2->get_x(), a2->get_y()); }
		catch (const exception& error) { cout << error.what() << endl; }
		try { a1->set_damage(c,s,a2); 
		
		}

		catch (const exception& error)
		{
			cout << "A2: " << error.what() << endl;
		}

		sum1 = sum1 + s;

		if (a2->get_health() <= 0) {

			cout << "A1 win" << endl;
			
		}
	}

	
	delete a1;
	delete a2;

	cout << "A1 нанёс: " << sum1 << " урона" << endl;
	cout << "A2 нанёс: " << sum2 << " урона" << endl;*/

	swordsmen* sword = new swordsmen(1, 1);

	cout << "Мечник" << endl;
	cout <<"Здоровье: "<< sword->get_health() << endl;
	cout << "Координаты: х=" << sword->get_x() << " y=" << sword->get_y() << endl;

	rifle* rif = new rifle(20, 1);
	cout << "Мушкетёр" << endl;
	cout << "Здоровье: " << rif->get_health() << endl;
	cout << "Дальность стрельбы: " << rif->get_range() << endl;

	k = 0;
	while (sqrt(pow(rif->get_x() - sword->get_x(), 2) + pow(rif->get_y() - sword->get_y(), 2)) > rif->get_range())
	{
		rif->go_back();
		k++;
		cout << "Шаг " << k << endl;
		cout << "Запас сил " << rif->get_st() << endl;
	}

	cout << rif->get_x() << " " << sword->get_x() << endl;//вывели координаты

	while (sword->get_health() > 0)
	{
		try { c = rif->get_damage(sword->get_x(), sword->get_y());
		if (c == 0) cout << "Перезарядка" << endl;
		}
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, sword);

		}

		catch (const exception& error)
		{
			cout << "Мечник: " << error.what() << endl;
		}
	}


	delete sword;

	cout << "---------------" << endl;

	Knight* kni = new Knight(0,0);

	k = 0;
	kni->go_up();
	k++;
	cout << "Шаг " << k << endl;
	cout << "Запас сил " << kni->get_st() << endl;

	
	while (sqrt(pow(rif->get_x() - kni->get_x(), 2) + pow(rif->get_y() - kni->get_y(), 2)) > kni->get_range())
	{
		kni->go_forward();
		k++;
		cout << "Шаг " << k << endl;
		cout << "Запас сил " << kni->get_st() << endl;

		try {
			c = rif->get_damage(kni->get_x(), kni->get_y());
			if (c == 0) cout << "Перезарядка" << endl;
		}
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, kni);

		}

		catch (const exception& error)
		{
			cout << "Рыцарь: " << error.what() << endl;
		}
	}

	//дерутся пока хотябы у одного есть хп
	while ((kni->get_health() > 0) and (rif->get_health() > 0))
	{
		c = 0;//наносимый урон
		try { c = kni->get_damage(rif->get_x(), rif->get_y()); }//расчитываем урон если можем дотянуться до а1
		catch (const exception& error) { cout << error.what() << endl; }

		try {
			kni->set_damage(c, s, rif); //a2 наносит урон a1

		}

		catch (const exception& error)
		{
			cout << "Мушкетёр: " << error.what() << endl;
		}

		

		if (rif->get_health() <= 0) { //если здоровье а1 равно или ниже 0

			cout << "Рыцарь win" << endl;

			continue;//выходим из цикла
		}

		try { c = rif->get_damage(kni->get_x(), kni->get_y()); }
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, kni);

		}

		catch (const exception& error)
		{
			cout << "Рыцарь: " << error.what() << endl;
		}

		

		if (kni->get_health() <= 0) {

			cout << "Мушкетёр win" << endl;

		}
	}

	delete rif;
	delete kni;

	cout << "--------" << endl;
	Archer* ar1 = new Archer();
	Archer* ar2 = new Archer(20);

	cout << "Лучник 2: " << ar2->get_x() << " " << ar2->get_y() << endl;

	rifle* rif1 = new rifle(1);
	rifle* rif2 = new rifle(19);

	Spearmen* sp1 = new Spearmen(2);
	Spearmen* sp2 = new Spearmen(18);

	swordsmen* sw1 = new swordsmen(3);
	swordsmen* sw2 = new swordsmen(17);
}