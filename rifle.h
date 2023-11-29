#include "c_units.h"
#pragma once
///�������
class rifle :public BaseUnit {
protected:
	//��������� ���������� �� Base
	int damage;//���� ������������, �� ���������
	int reload;//������� �����������
public:

	///�����������, � ������� ����� ��������� ������ �� ����� x,y
	rifle(int x = 0, int y = 0);

	/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
	void set_damage(int damag, float& result, BaseUnit* enemy);

	/// ������ ���� ���� ���� (��� �������� ����� ������ ���� ����������)
	void set_max_damage();

	///���������� stamina -> ���������� ���� �����, ������
	void rebuild_st();

	/// ������� ����
	int get_damage(int x, int y);
};
