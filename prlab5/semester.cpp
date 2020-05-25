#include "semester.h"

int semester::find_discipline(const string& name)//������ ������� ���������� � ������� ��� -1, ���� ����� ���
{
	for (int i = 0; i < disciplines.Size(); i++) {
		if (disciplines[i].get_name() == name)return i;
	}
	return -1;
}

semester::semester() : discipline_count(0), educate_lvl(0)
{
}

semester::semester(int discipline_count, int educate_lvl)
{
	if (discipline_count == 0)this->discipline_count = discipline_count;
	if (educate_lvl >= 0 && educate_lvl<3)this->educate_lvl = educate_lvl;
}

bool semester::add_discipline(string name, int rate, int educate_lvl)//������� ����������, ���� �� ��� �� ������, ���-�� ������ ������ 0, ������� ����������� ��������� � ����.������,
{//���������� � ����� ������ ��� ���
	if (name != "" && rate > 0 && educate_lvl == this->educate_lvl && find_discipline(name) == -1) {
		discipline d(name, rate, educate_lvl);
		disciplines.push_back(d);
		discipline_count++;
		return true;
	}
	return false;
}

bool semester::delete_discipline(string name)//������� ���������� � ������ name, ���� ����� ��� �� ������ false
{
	int pos = find_discipline(name);
	if (pos != -1) {
		discipline_count--;
		disciplines.erase(pos);
		return true;
	}
	return false;
}

const int semester::get_discipline_count()
{
	return discipline_count;
}

int semester::get_all_rate()//����� ������ ���� ��������� �� �������
{
	int sum = 0;
	for (int i = 0; i<disciplines.Size(); i++)
		sum += disciplines[i].get_rate();
	return sum;
}

string semester::get_all_disciplines()//������ � ���������� ���� ���������
{
	string str = "";
	for (int i = 0; i<disciplines.Size(); i++)
		str += disciplines[i].get_name() + " ";
	return str;
}