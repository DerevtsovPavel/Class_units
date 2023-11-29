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

	int k = 0;//����
	int c = 0;//��������� ����
	float s;//����������� ���������� ����
	float sum1=0 , sum2 = 0;//��� ������� ����� ���� �� ��� 
	/*
	/// a1 �������� � a2 �� ��������� �����
	while (sqrt(pow(a1->get_x() - a2->get_x(), 2) + pow(a1->get_y() - a2->get_y(), 2)) > a1->get_range())
	{
		a1->go_forward();
		k++;
		cout << "��� " << k << endl;
		cout << "����� ��� " << a1->get_st() << endl;
	}

	cout << a1->get_x() << " " << a2->get_x() << endl;//������ ����������

	//������� ���� ������ � ������ ���� ��
	while ((a1->get_health() > 0) and (a2->get_health() > 0))
	{
		 c = 0;//��������� ����
		try { c = a2->get_damage(a1->get_x(), a1->get_y()); }//����������� ���� ���� ����� ���������� �� �1
		catch (const exception& error) { cout << error.what() << endl; }

		try {  a2->set_damage(c,s,a1); //a2 ������� ���� a1
		
		}
		
		catch (const exception& error)
		{	
			cout <<"A1: "<< error.what() << endl;
		}

		sum2 = sum2 + s;

		if (a1->get_health() <= 0) { //���� �������� �1 ����� ��� ���� 0

			cout << "A2 win" << endl;
			
			continue;//������� �� �����
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

	cout << "A1 ����: " << sum1 << " �����" << endl;
	cout << "A2 ����: " << sum2 << " �����" << endl;*/

	swordsmen* sword = new swordsmen(1, 1);

	cout << "������" << endl;
	cout <<"��������: "<< sword->get_health() << endl;
	cout << "����������: �=" << sword->get_x() << " y=" << sword->get_y() << endl;

	rifle* rif = new rifle(20, 1);
	cout << "�������" << endl;
	cout << "��������: " << rif->get_health() << endl;
	cout << "��������� ��������: " << rif->get_range() << endl;

	k = 0;
	while (sqrt(pow(rif->get_x() - sword->get_x(), 2) + pow(rif->get_y() - sword->get_y(), 2)) > rif->get_range())
	{
		rif->go_back();
		k++;
		cout << "��� " << k << endl;
		cout << "����� ��� " << rif->get_st() << endl;
	}

	cout << rif->get_x() << " " << sword->get_x() << endl;//������ ����������

	while (sword->get_health() > 0)
	{
		try { c = rif->get_damage(sword->get_x(), sword->get_y());
		if (c == 0) cout << "�����������" << endl;
		}
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, sword);

		}

		catch (const exception& error)
		{
			cout << "������: " << error.what() << endl;
		}
	}


	delete sword;

	cout << "---------------" << endl;

	Knight* kni = new Knight(0,0);

	k = 0;
	kni->go_up();
	k++;
	cout << "��� " << k << endl;
	cout << "����� ��� " << kni->get_st() << endl;

	
	while (sqrt(pow(rif->get_x() - kni->get_x(), 2) + pow(rif->get_y() - kni->get_y(), 2)) > kni->get_range())
	{
		kni->go_forward();
		k++;
		cout << "��� " << k << endl;
		cout << "����� ��� " << kni->get_st() << endl;

		try {
			c = rif->get_damage(kni->get_x(), kni->get_y());
			if (c == 0) cout << "�����������" << endl;
		}
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, kni);

		}

		catch (const exception& error)
		{
			cout << "������: " << error.what() << endl;
		}
	}

	//������� ���� ������ � ������ ���� ��
	while ((kni->get_health() > 0) and (rif->get_health() > 0))
	{
		c = 0;//��������� ����
		try { c = kni->get_damage(rif->get_x(), rif->get_y()); }//����������� ���� ���� ����� ���������� �� �1
		catch (const exception& error) { cout << error.what() << endl; }

		try {
			kni->set_damage(c, s, rif); //a2 ������� ���� a1

		}

		catch (const exception& error)
		{
			cout << "�������: " << error.what() << endl;
		}

		

		if (rif->get_health() <= 0) { //���� �������� �1 ����� ��� ���� 0

			cout << "������ win" << endl;

			continue;//������� �� �����
		}

		try { c = rif->get_damage(kni->get_x(), kni->get_y()); }
		catch (const exception& error) { cout << error.what() << endl; }
		try {
			rif->set_damage(c, s, kni);

		}

		catch (const exception& error)
		{
			cout << "������: " << error.what() << endl;
		}

		

		if (kni->get_health() <= 0) {

			cout << "������� win" << endl;

		}
	}

	delete rif;
	delete kni;

	cout << "--------" << endl;
	Archer* ar1 = new Archer();
	Archer* ar2 = new Archer(20);

	cout << "������ 2: " << ar2->get_x() << " " << ar2->get_y() << endl;

	rifle* rif1 = new rifle(1);
	rifle* rif2 = new rifle(19);

	Spearmen* sp1 = new Spearmen(2);
	Spearmen* sp2 = new Spearmen(18);

	swordsmen* sw1 = new swordsmen(3);
	swordsmen* sw2 = new swordsmen(17);
}