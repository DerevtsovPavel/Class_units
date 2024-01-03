#include "c_units.h"

BaseUnit::BaseUnit() {
	health = 100;
	stamina = 100;
	damage[0] = 1;
	hit = 0;
	step = 0;
}

/// меняем макс возм урон
void BaseUnit::set_max_damage()
{
	if ((100 - stamina) % 10 == 0)//уменьшаем за каждые 10 потеряных пунктов
	{
		//если макс урон захочет опуститься ниже мин урона, то задать как мин.урон
		if (damage[1] - 1 <= damage[0])
			damage[1] = damage[0];

		else damage[1]--;
	}
}

///меняем защиту
void BaseUnit::set_protection()
{
	if ((100 - stamina) % 10 == 0)//уменьшаем за каждые 10 потеряных пунктов
	{
		if (protection - 1 == 0) return;
		else protection--;
	}
}

/// нанести урон
int BaseUnit::get_damage(int x, int y)
{
	//если расстояние между объектами больше дистанции атаки, то нет урона
	if (sqrt(pow(coord[0] - x, 2) + pow(coord[1] - y, 2)) > range) throw std::invalid_argument("Недостаточная дистанция");

	else
	{
		int a = damage[0] + rand() % (damage[1] - damage[0] + 1);// наносим урон в диапазоне

		hit++;//ув счётчик ударов
		///если сделали удар
		if (hit == 1)
		{
			if (stamina != 0) rebuild_st();//снижаем стам
			hit = 0;

		}
		return a;
	}
}

///идти вперёд
void BaseUnit::go_forward()
{
	coord[0]++;//меняем х
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();//снижаем запас сил
		step = 0;

	}
}

///идти назад
void BaseUnit::go_back()
{
	coord[0]--;
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;

	}
}

///идти вверх
void BaseUnit::go_up()
{
	coord[1]++;//меняем y
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;
	}
}

///идём вниз
void BaseUnit::go_down()
{
	coord[1]--;
	step++;

	if (step == 3)
	{
		if (stamina != 0) rebuild_st();
		step = 0;
	}
}

float BaseUnit::get_health() const
{
	return health;
}

///изменить здоровье
void BaseUnit::set_health(float hp)
{
	health = hp;
}

int BaseUnit::get_range() const
{
	return range;
}

int BaseUnit::get_x() const
{
	return coord[0];
}

int BaseUnit::get_y() const
{
	return coord[1];
}

int BaseUnit::get_st() const
{
	return stamina;
}

int BaseUnit::get_protection() const
{
	return protection;
}

int BaseUnit::get_armor() const
{
	return armor;
}