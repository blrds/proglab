#include "acadplan.h"
#include<string>
#include<iostream>

using namespace std;

acadplan::acadplan() {
	id = "";
	name = "";
	person = "";
	target_rate = NAN;
	educationlvl = -1;
	stat = false;
	semester_count = 0;
}

acadplan::acadplan(string id, string name, string person, int target_rate, lvl educationlvl, int semester_count) {
	set_id(id);
	set_name(name);
	set_person(person);
	set_target_rate(target_rate);
	set_educationlvl(educationlvl);
	this->stat = false;
	if (semester_count > 0) {
		this->semester_count = semester_count;
		for (int i = 0; i < semester_count; i++) {
			semester s(0, educationlvl);
			semesters.push_back(s);
		}
	}
}

const string acadplan::get_id() {
	return this->id;
}

bool acadplan::set_id(string new_id) {
	if (stat == false) {
		id = new_id;
		return true;
	}
	else return false;
}

const string acadplan::get_name() {
	return this->name;
}

bool acadplan::set_name(string new_name) {
	if (stat == false) {
		name = new_name;
		return true;
	}
	else return false;
}

const string acadplan::get_person() {
	return this->person;
}

bool acadplan::set_person(string new_person) {
	if (stat == false) {
		person = new_person;
		return true;
	}
	else return false;
}

const int acadplan::get_target_rate() {
	return this->target_rate;
}

bool acadplan::set_target_rate(int new_target_rate) {
	if (stat == false && new_target_rate > 0) {
		target_rate = new_target_rate;
		return true;
	}
	else {
		cout << "Невозможно";
		return false;
	}
}

const string acadplan::get_educationlvl() {
	switch (educationlvl) {
	case 0:return "undergraduate";
	case 1:return "magistracy";
	case 2:return "postgraduate";
	default:return "unknown";
	}
}

bool acadplan::set_educationlvl(lvl lvl) {//при устаноке новой ступень образования все дисциплины удаляются, тк ни одни из них не будет подходить под нынешний уровень
	if (stat == false && (lvl >= 0 && lvl <3)) {
		educationlvl = lvl;
		semesters.clear();
		for (int i = 0; i < semester_count; i++) {
			semester d(0, lvl);
			semesters.push_back(d);
		}
		return true;
	}
	else return false;
}

const string acadplan::get_stat() {
	switch (stat) {
	case true:return "in_action";
	default:return "in edit";
	}
}

bool acadplan::add_semester(int number)
{
	if (!stat && number >= 0 && number <= semesters.size()) {
		vector<semester>::iterator it = semesters.begin() + number;
		semester d(0, educationlvl);
		semester_count++;
		semesters.insert(it, d);
		return true;
	}
	else return false;
}

bool acadplan::del_semester(int semester_number)
{
	if (!stat && semester_number >= 0 && semester_number < semesters.size()) {
		vector<semester>::iterator it = semesters.begin() + semester_number;
		semesters.erase(it);
		semester_count--;
		return true;
	}
	else return false;
}

const int acadplan::get_semesters()
{
	return semester_count;
}

bool acadplan::start() {
	if (fulled()) {
		stat = true;
		return true;
	}
	else return false;
}

void acadplan::stop() {
	this->stat = false;
}

bool acadplan::fulled() {
	if (id == "")return false;
	if (name == "")return false;
	if (person == "")return false;
	if (target_rate != get_sum_rate()) return false;
	if (educationlvl < 0 && educationlvl >= 3)return false;
	if (semester_count <= 0)return false;
	for (semester d : semesters)
		if (d.get_discipline_count() <= 0)return false;
	return true;
}

int acadplan::get_sum_rate()
{
	int sum = 0;
	for (semester d : semesters)
		sum += d.get_all_rate();
	return sum;
}