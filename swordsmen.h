#include "c_units.h"
#pragma once

///класс мечник, сделан на основе класса Base
class swordsmen :public BaseUnit {
//поля унаследуем от Base
public:
	///конструктор, в котором нужно поставить объект на точку x,y
	swordsmen(int x = 0, int y = 0);

	/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
	void set_damage(int damag, float& result, BaseUnit* enemy);

	///перерасчёт stamina -> перерасчёт макс урона, защиты
	void rebuild_st();
};
