#include "rifle.h"

///�����������, � ������� ����� ��������� ������ �� ����� x,y
rifle::rifle(int x, int y )
{
	//��������� ������������ � Base

	reload = 0;
	damage = 50;
	armor = 6;
	protection = 4;
	range = 4;
	coord[0] = x;
	coord[1] = y;
}

/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
void rifle::set_damage(int damag, float& result, BaseUnit* enemy)
{
	if (damag == 0) return;

	else {
		float k = abs(damag - enemy->get_armor());//����������� ������� ����� ������������� ������
		enemy->set_health(enemy->get_health() - k);
		result = k;
		std::string s = "�������";
		s = s + " " + std::to_string(k);//������� ������������ ������� ����� ������
		throw std::invalid_argument(s);
	}
}

/// ������ ���� ���� ���� (��� �������� ����� ������ ���� ����������)
void rifle::set_max_damage()
{

}

///���������� stamina -> ���������� ���� �����, ������
void rifle::rebuild_st()
{
	stamina--;
	set_max_damage();
	set_protection();
}

/// ������� ����
int rifle::get_damage(int x, int y)
{
	//���� ���������� ����� ��������� ������ ��������� �����, �� ��� �����
	if (sqrt(pow(coord[0] - x, 2) + pow(coord[1] - y, 2)) > range) throw std::invalid_argument("������������� ���������");

	else
	{
		if (reload == 0) {

			hit++;//�� ������� ������
			///���� ������� 3 �����
			if (hit == 1)
			{
				if (stamina != 0) rebuild_st();//������� ����
				hit = 0;

			}
			reload = 4;
			return damage;
		}
		else {
			reload--;
			return 0;
		}
	}
}