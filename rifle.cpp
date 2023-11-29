#include "rifle.h"

///конструктор, в котором нужно поставить объект на точку x,y
rifle::rifle(int x, int y )
{
	//остальное определяется в Base

	reload = 0;
	damage = 50;
	armor = 6;
	protection = 4;
	range = 4;
	coord[0] = x;
	coord[1] = y;
}

/// наносим урон damag объекту enemy. result-переменная для подсчёта нанесённого урона
void rifle::set_damage(int damag, float& result, BaseUnit* enemy)
{
	if (damag == 0) return;

	else {
		float k = abs(damag - enemy->get_armor());//расчитываем сколько урона действительно пройдёт
		enemy->set_health(enemy->get_health() - k);
		result = k;
		std::string s = "Получил";
		s = s + " " + std::to_string(k);//выводим пользователю сколько урона прошло
		throw std::invalid_argument(s);
	}
}

/// меняем макс возм урон (для объектов этого класса урон неизменный)
void rifle::set_max_damage()
{

}

///перерасчёт stamina -> перерасчёт макс урона, защиты
void rifle::rebuild_st()
{
	stamina--;
	set_max_damage();
	set_protection();
}

/// нанести урон
int rifle::get_damage(int x, int y)
{
	//если расстояние между объектами больше дистанции атаки, то нет урона
	if (sqrt(pow(coord[0] - x, 2) + pow(coord[1] - y, 2)) > range) throw std::invalid_argument("Недостаточная дистанция");

	else
	{
		if (reload == 0) {

			hit++;//ув счётчик ударов
			///если сделали 3 удара
			if (hit == 1)
			{
				if (stamina != 0) rebuild_st();//снижаем стам
				hit = 0;

			}
			reload = 4;
			return damage;
		}
		else {
			reload--;
			return 0;
		}
	}
}