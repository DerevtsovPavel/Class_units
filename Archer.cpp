#include "Archer.h"

Archer::Archer(int x , int y )
{
	//��������� ���������� � Base

	damage[1] = 15;
	armor = 8;
	protection = 6;
	range = 10;
	coord[0] = x;
	coord[1] = y;
}

/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
void Archer::set_damage(int damag, float& result, BaseUnit* enemy)
{
	if (damag == 0) return;

	if (damag - enemy->get_protection() < 0) { result = 0; throw std::invalid_argument("������ ����������"); }

	else if (enemy->get_armor() / damag >= 2) {//���� ����� ����������� ���� � 2 � ����� ���
		throw std::invalid_argument("������ �����");
		result = 0;
	}

	else {
		float k = abs((damag - enemy->get_armor() - (1.0 * enemy->get_protection() / damag)));//����������� ������� ����� ������������� ������
		enemy->set_health(enemy->get_health() - k);
		result = k;
		std::string s = "�������";
		s = s + " " + std::to_string(k);//������� ������������ ������� ����� ������
		throw std::invalid_argument(s);
	}
}

///���������� stamina -> ���������� ���� �����, ������
void Archer::rebuild_st()
{
	stamina--;
	set_max_damage();
	set_protection();
}