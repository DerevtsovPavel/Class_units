#include "c_units.h"
#pragma once
///мушкетёр
class rifle :public BaseUnit {
protected:
	//остальное унаследуем от Base
	int damage;//урон фиксированый, не снижается
	int reload;//счётчик перезарядки
public:

	///конструктор, в котором нужно поставить объект на точку x,y
	rifle(int x = 0, int y = 0);

	/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
	void set_damage(int damag, float& result, BaseUnit* enemy) override;

	/// меняем макс возм урон (для объектов этого класса урон неизменный)
	void set_max_damage();

	///перерасчёт stamina -> перерасчёт макс урона, защиты
	void rebuild_st() override;

	/// нанести урон
	int get_damage(int x, int y);
};
