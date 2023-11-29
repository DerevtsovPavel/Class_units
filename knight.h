#include "c_units.h"
#pragma once

///����� ������, ��������� �� ������ BaseUnit
class Knight :public BaseUnit {

///���� ���������� �� BaseUnit

public:
	///�����������, � ������� ������ ������ �� ����� x,y
	Knight(int x = 0, int y = 0);

	/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
	void set_damage(int damag, float& result, BaseUnit* enemy);

	///���������� stamina -> ���������� ���� �����, ������
	void rebuild_st();
};
