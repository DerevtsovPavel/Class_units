#include <cassert>
#include "knight.h"
#include "rifle.h"
#include "swordsmen.h"
#include "Archer.h"
#include "Spearmen.h"
#include "c_units.h"
#pragma once

void Test()
{
	Knight* k = new Knight();
	assert(k->get_armor() == 18);
	assert(k->get_health() == 100);
	assert(k->get_protection() == 7);
	assert(k->get_range() == 1);
	assert(k->get_x() == 0);
	assert(k->get_y() == 0);

	Archer* a = new Archer(6, 6);
	assert(a->get_range() == 10);
	assert(a->get_x() == 6);
	assert(a->get_y() == 6);


	for (int i = 0; i < 6; i++)
		k->go_forward();

	assert(k->get_x() == 6);
	assert(k->get_y() == 0);
	assert(k->get_st() == 96);

	for (int i = 0; i < 6; i++)
		k->go_up();

	assert(k->get_x() == 6);
	assert(k->get_y() == 6);
	assert(k->get_st() == 92);

	float m;
	try {
		k->set_damage(10, m, a);
	}
	catch(...)
	{ }
	assert(abs(a->get_health() - 98.59)<0.01);

	try {
		k->set_damage(100, m, a);
	}
	catch(...)
	{ }
	assert(abs(a->get_health() - 6.65) < 0.01);


	std::string s;
	try {
		k->set_damage(5, m, a);
	}
	catch (const std::exception& error)
	{
		 s = error.what();
	}
	assert(s == "Защита уклонением");

	try {
		a->set_damage(9, m, k);
	}
	catch (const std::exception& error)
	{
		s = error.what();
	}
	assert(s == "Защита бронёй");

	

	int c = k->get_damage(6, 6);

	assert(c >= 3 and c <= 23);
	assert(k->get_st() == 90);
	assert(k->get_protection() == 6);
	 c = k->get_damage(6, 6);
	assert(c >= 3 and c <= 22);

	delete k;

	rifle* r = new rifle();
	assert(r->get_range() == 4);
	assert(r->get_damage(1,1) == 50);

	for (int i = 0; i < 11; i++)
	{
		r->go_back();
		r->go_down();
	}

	assert(r->get_x() == -11);
	assert(r->get_y() == -11);
	assert(r->get_st() == 92);
	assert(r->get_protection() == 4);
	
	for (int i = 0; i < 4; i++)
		r->get_damage(-9, -9);
	assert(r->get_damage(-9, -9) == 50);
	delete r;
}