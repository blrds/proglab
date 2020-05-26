#include"discipline.h"
#include"myVector.h"

class semester
{
public:
	semester();
	semester(int discipline_count, int educate_lvl);
	bool add_discipline(string name, int rate, int educate_lvl);
	bool delete_discipline(string name);
	const int get_discipline_count();
	int get_all_rate();
	string get_all_disciplines();
private:
	myVector<discipline>disciplines;
	int discipline_count, educate_lvl;
	int find_discipline(const string& name);
};