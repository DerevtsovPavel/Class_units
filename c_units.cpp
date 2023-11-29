#include "c_units.h"

BaseUnit::BaseUnit() {
	health = 100;
	stamina = 100;
	damage[0] = 1;
	hit = 0;
	step = 0;
}

/// ������ ���� ���� ����
void BaseUnit::set_max_damage()
{
	if ((100 - stamina) % 10 == 0)//��������� �� ������ 10 ��������� �������
	{
		//���� ���� ���� ������� ���������� ���� ��� �����, �� ������ ��� ���.����
		if (damage[1] - 1 <= damage[0])
			damage[1] = damage[0];

		else damage[1]--;
	}
}

///������ ������
void BaseUnit::set_protection()
{
	if ((100 - stamina) % 10 == 0)//��������� �� ������ 10 ��������� �������
	{
		if (protection - 1 == 0) return;
		else protection--;
	}
}

/// ������� ����
int BaseUnit::get_damage(int x, int y)
{
	//���� ���������� ����� ��������� ������ ��������� �����, �� ��� �����
	if (sqrt(pow(coord[0] - x, 2) + pow(coord[1] - y, 2)) > range) throw std::invalid_argument("������������� ���������");

	else
	{
		int a = damage[0] + rand() % (damage[1] - damage[0] + 1);// ������� ���� � ���������

		hit++;//�� ������� ������
		///���� ������� 3 �����
		if (hit == 1)
		{
			if (stamina != 0) rebuild_st();//������� ����
			hit = 0;

		}
		return a;
	}
}

///���� �����
void BaseUnit::go_forward()
{
	coord[0]++;//������ �
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();//������� ����� ���
		step = 0;

	}
}

///���� �����
void BaseUnit::go_back()
{
	coord[0]--;
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;

	}
}

///���� �����
void BaseUnit::go_up()
{
	coord[1]++;//������ y
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;
	}
}

///��� ����
void BaseUnit::go_down()
{
	coord[1]--;
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;
	}
}

float BaseUnit::get_health() const
{
	return health;
}

///�������� ��������
void BaseUnit::set_health(float hp)
{
	health = hp;
}

int BaseUnit::get_range() const
{
	return range;
}

int BaseUnit::get_x() const
{
	return coord[0];
}

int BaseUnit::get_y() const
{
	return coord[1];
}

int BaseUnit::get_st() const
{
	return stamina;
}

int BaseUnit::get_protection() const
{
	return protection;
}

int BaseUnit::get_armor() const
{
	return armor;
}