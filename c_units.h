#include <iostream>
#include <stdexcept>
#include <string>

#pragma once
///������� ����� ��� �����, �� ��� ������ ��������� ������. �����������!
class BaseUnit {
protected:
	float health;//��������
	int damage[2];// ���� d[0]-���.��������� d[1]-����.���������(�������� �� stamina)
	int stamina;//����� ���
	int protection;//������
	int armor;//�����
	int range;//��������� �����
	int coord[2];//���. ���������� ������� coord[0]=x, coord[1]=y. ������ � ����� ������ ����

	char hit;//���-�� ������ (�� ����� 3?) (��� �������� stamina)
	char step;//���-�� ����� (�� ����� 3) (��� �������� stamina)

public:

	BaseUnit();

	/// ������� ���� damag ������� enemy. result-���������� ��� �������� ���������� �����
	void virtual set_damage(int damag, float& result, BaseUnit* enemy) = 0;//������ ����������� �����

	/// ������ ���� ���� ����
	void set_max_damage();

	///������ ������
	void set_protection();

	///���������� stamina -> ���������� ���� �����, ������
	void virtual rebuild_st() = 0;
	

	/// ������� ����
	int get_damage(int x, int y);

	///���� �����
	void go_forward();

	///���� �����
	void go_back();

	///���� �����
	void go_up();

	///��� ����
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