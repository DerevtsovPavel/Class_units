#include "c_units.h"
#pragma once

class Spearmen :public BaseUnit {
	///поля унаследуем от BaseUnit
public:

	Spearmen(int x = 0, int y = 0);

	/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
	void set_damage(int damag, float& result, BaseUnit* enemy);

	///перерасчёт stamina -> перерасчёт макс урона, защиты
	void rebuild_st();
};
