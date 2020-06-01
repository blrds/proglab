#include "discipline.h"

discipline::discipline() {
	name = "";
	rate = 0;
	educatelvl = lvl(0);
}

discipline::discipline(string name, int rate, lvl educatelvl)
{
	this->name = name;
	this->rate = rate;
	this->educatelvl = educatelvl;
}

const string discipline::get_name()
{
	return name;
}

const int discipline::get_rate()
{
	return rate;
}

const lvl discipline::get_educatelvl()
{
	return educatelvl;
}

discipline discipline::operator=(const discipline &a)
{
	name = a.name;
	rate = a.rate;
	educatelvl = a.educatelvl;
	return *this;
}