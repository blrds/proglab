#pragma once
#include<string>
using namespace std;

class discipline
{
private:
	string name;
	int rate, educatelvl;
public:
	discipline(string name, int rate, int educatelvl);
	const string get_name();
	const int get_rate();
	const int get_educatelvl();
};

