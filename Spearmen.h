#include "c_units.h"
#pragma once

class Spearmen :public BaseUnit {
	///���� ���������� �� BaseUnit
public:

	Spearmen(int x = 0, int y = 0);

	/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
	void set_damage(int damag, float& result, BaseUnit* enemy);

	///���������� stamina -> ���������� ���� �����, ������
	void rebuild_st();
};
