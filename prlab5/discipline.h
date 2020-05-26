#pragma once
#include<string>
using namespace std;

class discipline
{
public:
	discipline();
	discipline(string name, int rate, int educatelvl);
	const string get_name();
	const int get_rate();
	const int get_educatelvl();
private:
	string name;
	int rate, educatelvl;
};

enum class lvl { //
	undergraduate, magistracy, postgraduate
};
