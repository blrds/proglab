#pragma once
#include<string>
#include<vector>
#include"discipline.h"
#include"semester.h"

using namespace std;

enum lvl {
	undergraduate, magistracy, postgraduate
};

class acadplan {
private:
	string id, name, person;
	int target_rate, educationlvl, semester_count;
	bool stat;
public:
	vector<semester>semesters;
	acadplan();
	acadplan(string id, string name, string person, int target_rate, lvl educationlvl, int semester_count);
	const string get_id();
	bool set_id(string new_id);
	const string get_name();
	bool set_name(string new_name);
	const string get_person();
	bool set_person(string new_person);
	const int get_target_rate();
	bool set_target_rate(int new_target_rate);
	const string get_educationlvl();
	bool set_educationlvl(lvl lvl);
	const string get_stat();
	bool add_semester(int number);
	bool del_semester(int semester_number);
	const int get_semesters();
	bool start();
	void stop();
	int get_sum_rate();
private:
	bool fulled();
};