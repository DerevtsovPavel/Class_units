#include "knight.h"

///�����������, � ������� ������ ������ �� ����� x,y
Knight::Knight(int x , int y )
{
	///��������� ���������� � c_units

	damage[0] = 3;//��� ����
	damage[1] = 18;//���� ����
	armor = 25;//�����
	protection = 7;//������
	range = 1;//��������� �����
	coord[0] = x;//����� � �� ����
	coord[1] = y;//����� � �� ����
}

/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
void Knight::set_damage(int damag, float& result, BaseUnit* enemy)
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
void Knight::rebuild_st()
{
	stamina = stamina - 2;//������� ������ ����
	set_max_damage();
	set_protection();
}