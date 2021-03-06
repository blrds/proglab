#pragma once
#include<string>
using namespace std;

enum class lvl {
	undergraduate, magistracy, postgraduate
};
static bool operator==(const lvl left, const int right)
{
	return static_cast<int>(left) == right;
}
static bool operator>=(const lvl left, const int right)
{
	return static_cast<int>(left) >= right;
}
static bool operator<=(const lvl left, const int right)
{
	return static_cast<int>(left) <= right;
}
static bool operator>(const lvl left, const int right)
{
	return static_cast<int>(left) > right;
}
static bool operator<(const lvl left, const int right)
{
	return static_cast<int>(left) < right;
}


class discipline
{
public:
	discipline();
	discipline(string name, int rate, lvl educatelvl);
	const string get_name();
	const int get_rate();
	const lvl get_educatelvl();
	discipline operator=(const discipline&);
private:
	string name;
	int rate;
	lvl educatelvl;
};

