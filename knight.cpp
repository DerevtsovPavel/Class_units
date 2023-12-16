#include "knight.h"

///конструктор, в котором ставим объект на точку x,y
Knight::Knight(int x , int y )
{
	///остальное определено в c_units

	damage[0] = 3;//мин урон
	damage[1] = 23;//макс урон
	armor = 18;//броня
	protection = 7;//защита
	range = 1;//дистанция атаки
	coord[0] = x;//коорд х на поле
	coord[1] = y;//коорд у на поле
}

/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
void Knight::set_damage(int damag, float& result, BaseUnit* enemy) 
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
void Knight::rebuild_st()
{
	stamina = stamina - 2;//быстрее теряет силы
	set_max_damage();
	set_protection();
}