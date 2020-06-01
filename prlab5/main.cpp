#include "acadplan.h"
#include<string>
#include<windows.h>
#include<locale.h>
#include<iostream>

using namespace std;

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	acadplan a = acadplan("f","ff","fff",100,lvl(0), 1);
	cout << "Запуск пустого плана\n";
	cout << a.start() << "\n";
	cout << "\nЗаполнение и вывод основных параметров\n";
	a.set_id("aa");
	cout << a.get_id() << "\n";
	a.set_name("bb");
	cout << a.get_name() << "\n";
	a.set_person("cc");
	cout << a.get_person() << "\n";
	a.set_target_rate(100);
	cout << a.get_target_rate() << "\n";
	a.set_educationlvl(lvl(1));
	cout << a.get_educationlvl() << "\n";
	cout << "\nПроверка работоспособности семестров и ступеней ВО\n";
	cout << a.get_semesters() << "\n";
	cout << a.semesters[0].get_all_disciplines() << "\n";
	cout << a.semesters[0].add_discipline("math", 50, lvl(2)) << "\n";//не добавится, тк ступень образования не совпадает
	cout << a.semesters[0].add_discipline("math", 50, lvl(1)) << "\n";//добавится, тк ступень образования совпадает
	cout << a.semesters[0].add_discipline("math", 50, lvl(1)) << "\n";//не добавится, тк уже есть такой предмет
	cout << a.semesters[0].get_all_disciplines() << "\n";
	cout << a.semesters[0].delete_discipline("ne math") << "\n";//не удалиится, тк такого предмета нет
	cout << a.semesters[0].delete_discipline("math") << "\n";//удалится, тк такой предмет есть
	cout << a.semesters[0].get_all_disciplines() << "\n";
	a.semesters[0].add_discipline("math", 50, lvl(1));
	a.semesters[0].add_discipline("ne math", 25, lvl(1));
	a.add_semester(0);
	cout << a.semesters[0].get_all_disciplines() << "\n";
	cout << a.semesters[1].get_all_disciplines() << "\n";
	a.semesters[0].add_discipline("math", 25, lvl(1));
	cout << a.semesters[0].get_all_rate() << "\n";
	cout << a.semesters[1].get_all_rate() << "\n";
	cout << "\nВывод всех параметров\n";
	cout << a.get_target_rate() << "\n";
	cout << a.get_sum_rate() << "\n\n";
	cout << a.get_id() << "\n";
	cout << a.get_name() << "\n";
	cout << a.get_person() << "\n";
	cout << a.get_educationlvl() << "\n";
	cout << a.get_semesters() << "\n";
	cout << a.get_stat() << "\n";
	cout << a.semesters[0].get_all_disciplines() << " " << a.semesters[0].get_discipline_count() << "\n";
	cout << a.semesters[1].get_all_disciplines() << " " << a.semesters[1].get_discipline_count() << "\n";
	cout << "\nЗапуск плана\n";
	cout << a.start();
}