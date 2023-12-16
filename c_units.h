#include <iostream>
#include <stdexcept>
#include <string>

#pragma once
///Базовый класс для юнита, на его основе создаются другие. Абстрактный!
class BaseUnit {
protected:
	float health;//здоровье
	int damage[2];// урон d[0]-мин.возможный d[1]-макс.возможный(меняется от stamina)
	int stamina;//запас сил
	int protection;//защита
	int armor;//броня
	int range;//дистанция атаки
	int coord[2];//тек. координаты объекта coord[0]=x, coord[1]=y. Начало в левом нижнем углу

	char hit;//кол-во ударов (не более 3?) (для расчётов stamina)
	char step;//кол-во шагов (не более 3) (для расчётов stamina)

public:

	BaseUnit();

	/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
	void virtual set_damage(int damag, float& result, BaseUnit* enemy) = 0;//делаем абстрактный метод

	/// меняем макс возм урон
	void set_max_damage();

	///меняем защиту
	void set_protection();

	///перерасчёт stamina -> перерасчёт макс урона, защиты
	void virtual rebuild_st() = 0;//абстрактный метод
	

	/// нанести урон
	int get_damage(int x, int y);

	///идти вперёд
	void go_forward();

	///идти назад
	void go_back();

	///идти вверх
	void go_up();

	///идём вниз
	void go_down();

	float get_health() const;

	void set_health(float hp);
	
	int get_range() const;

	int get_x() const;

	int get_y() const;

	int get_st() const;

	int get_protection() const;

	int get_armor() const;
};