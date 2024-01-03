#include <iostream>
#include <time.h>
#include "swordsmen.h"
#include "rifle.h"
#include "knight.h"
#include "Spearmen.h"
#include "Archer.h"
#include "asserts.h"
#pragma once



using namespace std;


int main() {
	setlocale(0, "Russian");
	srand(time(nullptr));

	Test();

	int k = 0;//шаги
	int c = 0;//наносимый урон
	float s;

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
		try { c = kni->get_damage(rif->get_x(), rif->get_y()); }//расчитываем урон если kni можем дотянуться до rif
		catch (const exception& error) { cout << error.what() << endl; }

		try {
			kni->set_damage(c, s, rif); //kni наносит урон rif

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
	
	BaseUnit** army1 = new BaseUnit * [3]; //  динамический массив из указателей на BaseUnit

	army1[0] = new Archer(0, 0);
	army1[1] = new rifle(1, 0);
	army1[2] = new Knight(3, 0);

	cout << army1[0]->get_range() << endl;

	BaseUnit** army2 = new BaseUnit * [3];

	army2[0] = new Knight(10, 0);
	army2[1] = new Spearmen(11, 0);
	army2[2] = new Spearmen(11, 1);

	while (sqrt(pow(army1[0]->get_x() - army2[1]->get_x(), 2) + pow(army1[0]->get_y() - army2[1]->get_y(), 2)) > army1[0]->get_range()) {
		army1[0]->go_forward();
	}
	cout << "Лучник " << army1[0]->get_st() << endl;

	while (sqrt(pow(army1[1]->get_x() - army2[0]->get_x(), 2) + pow(army1[1]->get_y() - army2[0]->get_y(), 2)) > army1[1]->get_range()) {
		army1[1]->go_forward();
	}
	cout << "Мушкетёр " << army1[1]->get_st() << endl;

	while (sqrt(pow(army1[2]->get_x() - army2[0]->get_x(), 2) + pow(army1[2]->get_y() - army2[0]->get_y(), 2)) > army1[2]->get_range()) {
		army1[2]->go_forward();
	}
	cout << "Рыцарь " << army1[2]->get_st() << endl;



	army2[2]->go_back();

	while ((army1[2]->get_health() > 0) and (army2[2]->get_health() > 0))
	{
		c = 0;//наносимый урон
		try { c = army2[2]->get_damage(army1[2]->get_x(), army1[2]->get_y()); }//расчитываем урон если spearmen можем дотянуться до knight
		catch (const exception& error) { cout << error.what() << endl;
		c = 0; //если дистанция недостаточна для удара
		}

		try {
			/*здесь тип spearmen приводится к BaseUnit, в результате все поля и методы, 
			которых нет в базовом классе будут отброшены
			т.к. set_damage объявлен в базовом классе, то использование dynamic(static)cast не нужно
			cast-используются в том случае, когда нам нужно вызвать метод,
			который есть только в классе потомка, но при объявлении указателей на базовый класс,
			новые поля и методы обрезаются, а вызвать метод нужно.
			в нашем примере это могло выглядеть как:
			BaseUnit* s = Spearmen()
			spearmen* s2 = dynamic_cast<spearmen*>(s)
			spearmen* s2 = (spearmen*)(s)
			s2->set_damage()
			или
			dynamic_cast<Spearmen*> (s)->set_damage()

			если преобразование невозможно, то dynamic_cast бросит исключение и вернёт nullptr
			*/
			army2[2]->set_damage(c, s, army1[2]); //spearmen наносит урон knight

		}

		catch (const exception& error)
		{
			cout << "Рыцарь: " << error.what() << endl;
		}



		if (army1[2]->get_health() <= 0) { //если здоровье knight равно или ниже 0

			cout << "Копейщик win" << endl;

			continue;//выходим из цикла
		}

		try { c = army1[2]->get_damage(army2[2]->get_x(), army2[2]->get_y()); }//если рыцарь сможет дотянуться до коп
		catch (const exception& error) {
			cout << error.what() << endl; //если дистанция недостаточна для удара
			c = 0;
		}
		try {
			army1[2]->set_damage(c, s, army2[2]);//рыцарь бьёт копейщика

		}

		catch (const exception& error)
		{
			cout << "Копейщик: " << error.what() << endl;
		}

		if (army2[2]->get_health() <= 0) {

			cout << "Рыцарь win" << endl;

		}
	}

	cout << "------------" << endl;
	Knight* kni1 = new Knight;
	swordsmen* sw = new swordsmen(1, 0);

	while ((kni1->get_health() > 0) and (sw->get_health() > 0))
	{
		c = 0;//наносимый урон
		try { c = sw->get_damage(kni1->get_x(), kni1->get_y()); }//расчитываем урон если sw можем дотянуться до knight
		catch (const exception& error) {
			cout << error.what() << endl;
			c = 0; //если дистанция недостаточна для удара
		}

		try {
			sw->set_damage(c, s, kni1); //sw наносит урон knight

		}

		catch (const exception& error)
		{
			cout << "Рыцарь: " << error.what() << endl;
		}



		if (kni1->get_health() <= 0) { //если здоровье knight равно или ниже 0

			cout << "Мечник win" << endl;

			continue;//выходим из цикла
		}

		try { c = kni1->get_damage(sw->get_x(), sw->get_y()); }//если рыцарь сможет дотянуться до мечника
		catch (const exception& error) {
			cout << error.what() << endl; //если дистанция недостаточна для удара
			c = 0;
		}
		try {
			kni1->set_damage(c, s, sw);//рыцарь бьёт мечника

		}

		catch (const exception& error)
		{
			cout << "Мечник: " << error.what() << endl;
		}



		if (sw->get_health() <= 0) {

			cout << "Рыцарь win" << endl;

		}
	}



}