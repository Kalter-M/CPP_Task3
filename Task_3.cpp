// Task_2.cpp: определяет точку входа для консольного приложения.
//

//Брусенцев Иван Максимович
//Задача №3
//6. Реализовать табель сотрудников для отдела кадров.Предусмотреть управление списком сотрудников 
//предприятия(добавление, редактирование, удаление, просмотр). Список сотрудников должен поддерживать 
//фильтрацию по любому полю и сортировку. Реализовать функцию расчета заработной платы для сотрудников
//за выбранный период(например, месяц, квартал, полугодие, год).



#include "stdafx.h"

#include "Header.h"
#include "Task_3.h"

void PrintMainMenu()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Ввод" << std::endl;
	std::cout << " 2)Вывод" << std::endl;
	std::cout << " 3)Поиск по индексу" << std::endl;
	std::cout << " 4)Добавление" << std::endl;
	std::cout << " 5)Найти все по критерию" << std::endl;
	std::cout << " 6)Отсортировать" << std::endl;
	std::cout << " 0)Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
}

void PrintMenuConsoleFile()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Консоль" << std::endl;
	std::cout << " 2)Файл" << std::endl;
	std::cout << " 0)Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
}

void PrintMenuFindParam()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)По номеру отдела" << std::endl;
	std::cout << " 2)По фамилии" << std::endl;
	std::cout << " 3)По дате поступления" << std::endl;
	std::cout << " 4)По окладу" << std::endl;
	std::cout << " 0)Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
}

//void PrintMenuSearch()
//{
//	std::cout << "-------------------------------------" << std::endl;
//	std::cout << " 1)Простой поиск" << std::endl;
//	std::cout << " 2)Бинарный поиск" << std::endl;
//	std::cout << " 0)Выход" << std::endl;
//	std::cout << "------------------------------" << std::endl;
//	std::cout << "Введите команду: ";
//}

void PrintAction()
{
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Действия с элементом:" << std::endl;
	std::cout << " 1)Печать" << std::endl;
	std::cout << " 2)Изменение" << std::endl;
	std::cout << " 3)Удаление" << std::endl;
	std::cout << " 4)Подсчет зарплаты" << std::endl;
	std::cout << " 0)Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
}

dec::decimal<2> CountSalary(std::vector<Employee>::iterator& it, int month)
{
	return it->Salary * month;
}

void CountSalaryMenu(std::vector<Employee>::iterator& it)
{
	std::string c;
	std::cout << " Подсчет зарплаты: " << "\n";
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)За месяц" << std::endl;
	std::cout << " 2)За квартал" << std::endl;
	std::cout << " 3)За полугодие" << std::endl;
	std::cout << " 4)За год" << std::endl;
	std::cout << " 0)Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
	std::cin >> c;
	try
	{
		int n = std::stoi(c);
		switch (n)
		{
		case 1:
			std::cout << "За месяц: " << CountSalary(it, 1) << std::endl;
			break;
		case 2:
			std::cout << "За квартал: " << CountSalary(it, 3) << std::endl;
			break;
		case 3:
			std::cout << "За полугодие: " << CountSalary(it, 6) << std::endl;
			break;
		case 4:
			std::cout << "За год: " << CountSalary(it, 12) << std::endl;
			break;
		case 0:
			return;
			break;
		default:
			std::cout << "Неверная команда!" << std::endl;
			break;
		}
	}
	catch (...)
	{
		std::cout << "Неверная команда!" << std::endl;
	}
}

void PrintFind()
{
	std::cout << "------------------------------------" << std::endl;
	std::cout << "1 - По табельному номеру" << std::endl;
	std::cout << "2 - По номеру отдела" << std::endl;
	std::cout << "3 - По фамилии" << std::endl;
	std::cout << "4 - По окладу" << std::endl;
	std::cout << "5 - По дате поступлнения" << std::endl;
	std::cout << "6 - По надбавке" << std::endl;
	std::cout << "7 - По налогу" << std::endl;
	std::cout << "8 - По количеству отработанных дней" << std::endl;
	std::cout << "9 - По количеству рабочих дней" << std::endl;
	std::cout << "10 - По начисленной сумме" << std::endl;
	std::cout << "11 - По удержанной сумме" << std::endl;
	std::cout << "0 - Выход" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Введите команду: ";
}

std::string InputFileName()
{
	std::string name;
	std::cout << "Введите имя файла: ";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	if (name == "") name = "default";
	return name + ".txt";
}

void SubAction(EmpContainer& sub, std::string& c, bool& flag)
{
	if (sub.Size() != 0)
	{
		std::cout << " Размер подсписка: " << sub.Size() << "\n";
		std::cout << "-------------------------------------" << std::endl;
		std::cout << " 1)Вывод в консоль" << std::endl;
		std::cout << " 2)Вывод в файл" << std::endl;
		std::cout << " 0)Выход" << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "Введите команду: ";
		std::cin >> c;
		try
		{
			std::string FName;

			int n = std::stoi(c);
			switch (n)
			{
			case 1:
				ConsoleOutput(sub);
				break;
			case 2:
				FName = InputFileName();
				sub.FileOutput(std::fstream(FName, std::ios::out));
				break;
			case 0:
				flag = false;
				break;
			default:
				std::cout << "Неверная команда!" << std::endl;
				break;
			}
		}
		catch (...)
		{
			std::cout << "Неверная команда!" << std::endl;
		}
	}
	else
	{
		flag = false;
		std::cout << "Ничего не найдено!" << std::endl;
	}
}

void SearchAction(bool found, EmpContainer& cont, std::vector<Employee>::iterator& it, std::string c, bool& flag)
{
	if (found)
	{
		std::cout << "Запись найдена! \n";
		flag = true;
		int n;
		while (flag)
		{
			PrintAction();
			std::cin >> c;
			try
			{
				n = std::stoi(c);
				switch (n)
				{
				case 1:
					std::cout << *it;
					break;
				case 2:
					cont.Change(it);
					break;
				case 3:
					cont.Remove(it);
					flag = false;
					break;
				case 4:
					CountSalaryMenu(it);
					break;
				case 0:
					flag = false;
					break;
				default:
					std::cout << "Неверная команда!" << std::endl;
					break;
				}
			}
			catch (...)
			{
				std::cout << "Неверная команда!" << std::endl;
			}
		}
	}
	else
		std::cout << "Запись не найдена \n";
		flag = false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	EmpContainer cont = EmpContainer();
	EmpContainer sub;
	std::string c;
	std::string str;
	int n;
	bool flag;
	bool binarySearch;
	bool found;
	std::string FName;
	std::vector<Employee>::iterator it;

	while (true)
	{
		PrintMainMenu();
		std::cin >> c;
		try
		{
			n = std::stoi(c);
			switch (n)
			{
			case 1:
				flag = true;
				while (flag)
				{
					PrintMenuConsoleFile();
					std::cin >> c;
					try
					{
						n = std::stoi(c);
						switch (n)
						{
						case 1:
							ConsoleInput(cont);
							flag = false;
							break;
						case 2:
							FName = InputFileName();
							cont.FileInput(std::fstream(FName, std::ios::in));
							flag = false;
							break;
						case 0:
							flag = false;
							break;
						default:
							std::cout << "Неверная команда!" << std::endl;
							break;
						}
					}
					catch (...)
					{
						std::cout << "Неверная команда!" << std::endl;
					}
				}
				break;
			case 2:
				flag = true;
				while (flag)
				{
					PrintMenuConsoleFile();
					std::cin >> c;
					try
					{
						n = std::stoi(c);
						switch (n)
						{
						case 1:
							ConsoleOutput(cont);
							flag = false;
							break;
						case 2:
							FName = InputFileName();
							cont.FileOutput(std::fstream(FName, std::ios::out));
							flag = false;
							break;
						case 0:
							flag = false;
							break;
						default:
							std::cout << "Неверная команда!" << std::endl;
							break;
						}
					}
					catch (...)
					{
						std::cout << "Неверная команда!" << std::endl;
					}
				}
				break;
			case 3:
				try
				{
					if (cont.Size() != 0)
					{
						flag = true;
						while (flag)
						{
							int num = InputInt("Введите индекс: ", true, 1, cont.Size());
							it = cont.FindByIndex(num);
							SearchAction(true, cont, it, c, flag);
						}
					}
					else
					{
						std::cout << "Контейнер пуст!" << std::endl;
						flag = false;
					}
				}
				catch (...) 
				{
					flag = false;
				}
				break;
			case 4:
				try
				{
					cont.Add(InputEmployee());
				}
				catch (...) {
					flag = false;
				}
				break;

			//НАЙТИ ПО КРИТЕРИЮ
			case 5:
				flag = true;
				while (flag)
				{
					std::cout << "Поиск по параметру" << std::endl;
					PrintFind();
					std::cin >> c;
					try
					{
						n = std::stoi(c);
						switch (n)
						{
						case 1:
							sub = cont.FindSubVectByPersonnelNumber(InputInt("Введите табельный номер: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 2:
							sub = cont.FindSubVectByDepartment(InputInt("Введите номер отдела: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 3:
							std::cout << "Введите фамилию: ";
							std::cin >> str;
							sub = cont.FindSubVectByName(str);
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 4:
							sub = cont.FindSubVectBySalary(InputDecimal("Введите оклад: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 5:
							sub = cont.FindSubVectByEnrollmentDate(InputDate(true, "Введите дату поступления: "));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;

						case 6:
							sub = cont.FindSubVectByOverhead(InputDecimal("Введите надбавку: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 7:
							sub = cont.FindSubVectByIncomeTax(InputDecimal("Введите налог: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 8:
							sub = cont.FindSubVectByDaysWorked(InputInt("Введите кол-во отработанных дней в месяце: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 9:
							sub = cont.FindSubVectByAllWorkingDays(InputInt("Введите кол-во рабочих дней в месяце: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 10:
							sub = cont.FindSubVectByAccrued(InputDecimal("Введите начислено: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 11:
							sub = cont.FindSubVectByWithheld(InputDecimal("Введите удержано: ", true));
							flag = true;
							while (flag)
								SubAction(sub, c, flag);
							break;
						case 0:
							flag = false;
						}
					}
					catch (...)
					{
						std::cout << "Неверная команда!" << std::endl;
					}
				}

				break;
			//СОРТИРОВКА
			case 6:
				flag = true;
				while (flag)
				{
					std::cout << "Сортировка" << std::endl;
					PrintFind();
					std::cin >> c;
					try
					{
						n = std::stoi(c);
						switch (n)
						{
						case 1:	
							flag = true;
							cont.SortByPersonnelNumber();
							break;
						case 2:
							flag = true;
							cont.SortByDepartment();
							break;
						case 3:
							flag = true;
							cont.SortByName();
							break;
						case 4:
							flag = true;
							cont.SortBySalary();
							break;
						case 5:
							flag = true;
							cont.SortByEnrollmentDate();
							break;
						case 6:
							flag = true;
							cont.SortByOverhead();
							break;
						case 7:
							flag = true;
							cont.SortByIncomeTax();
							break;
						case 8:
							flag = true;
							cont.SortByDaysWorked();
							break;
						case 9:
							flag = true;
							cont.SortByAllWorkingDays();
							break;
						case 10:
							flag = true;
							cont.SortByAllAccrued();
							break;
						case 11:
							flag = true;
							cont.SortByWithheld();
							break;
						case 0:
							flag = false;
						}
						ConsoleOutput(cont);
					}
					catch (...)
					{
						std::cout << "Неверная команда!" << std::endl;
					}
				}

				break;
			case 0:
				return 0;
				break;
			default:
				std::cout << "Неверная команда!" << std::endl;
				break;
			}
		}
		catch (...)
		{
			std::cout << "Неверная команда!" << std::endl;
		}
	}
	return 0;
}
