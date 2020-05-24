#include "discipline.h"

discipline::discipline(string name, int rate, int educatelvl)
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

const int discipline::get_educatelvl()
{
	return educatelvl;
}