#include "c_units.h"
#pragma once

///класс рыцарь, сделанный на основе BaseUnit
class Knight :public BaseUnit {

///поля унаследуем от BaseUnit

public:
	///конструктор, в котором ставим объект на точку x,y
	Knight(int x = 0, int y = 0);

	/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
	void set_damage(int damag, float& result, BaseUnit* enemy);

	///перерасчёт stamina -> перерасчёт макс урона, защиты
	void rebuild_st();
};
