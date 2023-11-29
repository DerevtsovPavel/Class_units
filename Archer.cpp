#include "Archer.h"

Archer::Archer(int x , int y )
{
	//остальное определено в Base

	damage[1] = 15;
	armor = 8;
	protection = 6;
	range = 10;
	coord[0] = x;
	coord[1] = y;
}

/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
void Archer::set_damage(int damag, float& result, BaseUnit* enemy)
{
	if (damag == 0) return;

	if (damag - enemy->get_protection() < 0) { result = 0; throw std::invalid_argument("Защита уклонением"); }

	else if (enemy->get_armor() / damag >= 2) {//если броня превосходит урон в 2 и более раз
		throw std::invalid_argument("Защита бронёй");
		result = 0;
	}

	else {
		float k = abs((damag - enemy->get_armor() - (1.0 * enemy->get_protection() / damag)));//расчитываем сколько урона действительно пройдёт
		enemy->set_health(enemy->get_health() - k);
		result = k;
		std::string s = "Получил";
		s = s + " " + std::to_string(k);//выводим пользователю сколько урона прошло
		throw std::invalid_argument(s);
	}
}

///перерасчёт stamina -> перерасчёт макс урона, защиты
void Archer::rebuild_st()
{
	stamina--;
	set_max_damage();
	set_protection();
}