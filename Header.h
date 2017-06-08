#pragma once


#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <functional>
#include <ctime>
#include "Date.h"
#include "Decimal.h"


class Employee
{
public:
	//��������� �����
	int PersonnelNumber;
	//����� ������
	int Department;
	//�������
	std::string Name;
	//�����
	dec::decimal<2> Salary; // int Salary; 100.00 = 10000 12345 = 123.45 
	//���� ����������� �� ������
	Date EnrollmentDate;
	//������� ��������
	dec::decimal<2> Overhead;
	//���������� �����
	dec::decimal<2> IncomeTax;
	//���-�� ������������ ���� � ������
	int DaysWorked;
	//���-�� ������� ���� � ������
	int AllWorkingDays;
	//���������
	dec::decimal<2> Accrued;
	//��������
	dec::decimal<2> Withheld;

	Employee(int APersonnelNumber, int ADepartment, std::string AName, dec::decimal<2> ASalary, Date AEnrollmentDate,
		dec::decimal<2> AOverhead, dec::decimal<2> AIncomeTax, int ADaysWorked, int AAllWorkingDays, dec::decimal<2> AAccrued, dec::decimal<2> AWithheld)
	{
		PersonnelNumber = APersonnelNumber;
		Department = ADepartment;
		Name = AName;
		Salary = ASalary;
		EnrollmentDate = AEnrollmentDate;
		Overhead = AOverhead;
		IncomeTax = AIncomeTax;
		DaysWorked = ADaysWorked;
		AllWorkingDays = AAllWorkingDays;
		Accrued = AAccrued;
		Withheld = AWithheld;
	}

	Employee()
	{
		PersonnelNumber = 0;
		Department = 0;
		Name = "";
		Salary = 0;
		EnrollmentDate = Date();
		Overhead = 0;
		IncomeTax = 0;
		DaysWorked = 0;
		AllWorkingDays = 0;
		Accrued = 0;
		Withheld = 0;
	}

	~Employee()	{}

	bool operator==(const Employee& that) const
	{
		return	this->PersonnelNumber == that.PersonnelNumber;
	}

	bool operator < (const Employee &that)
	{
		return this->PersonnelNumber < that.PersonnelNumber;
	}
};

std::istream& operator>>(std::istream& cin, Employee &emp)
{
	cin >> emp.PersonnelNumber;
	cin >> emp.Department;
	cin >> emp.Name;
	cin >> emp.Salary;
	std::string temp;
	cin >> temp;
	Date::StrToDate(temp, emp.EnrollmentDate);
	cin >> emp.Overhead;
	cin >> emp.IncomeTax;
	cin >> emp.DaysWorked;
	cin >> emp.AllWorkingDays;
	cin >> emp.Accrued;
	cin >> emp.Withheld;

	return cin;
}

std::ostream& operator<<(std::ostream &cout, const Employee &emp)
{
	cout << std::to_string(emp.PersonnelNumber) + "\t" +
		std::to_string(emp.Department) + "\t" +
		emp.Name + "\t" <<
		emp.Salary << "\t";
	cout << emp.EnrollmentDate << "\t";
	cout << emp.Overhead << "\t" <<
		emp.IncomeTax << "\t" +
		std::to_string(emp.DaysWorked) + "\t" +
		std::to_string(emp.AllWorkingDays) + "\t" <<
		emp.Accrued << "\t" <<
		emp.Withheld << std::endl;;
	return cout;
}

Employee InputEmployee();

//Predicates


class DepartmentPredicate
{
protected:
	int dep;

public:
	DepartmentPredicate(int _dep)
	{
		dep = _dep;
	}

	bool virtual operator () (Employee emp)
	{
		return emp.Department == dep;
	}

	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Department == emp2.Department;
	}
};

class NamePredicate
{
protected:
	std::string name;

public:
	NamePredicate(std::string _name)
	{
		name = _name;
	}

	bool virtual operator () (Employee emp)
	{
		return emp.Name == name;
	}

	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Name == emp2.Name;
	}
};

class EnrollmentDatePredicate
{
protected:
	Date d;

public:
	EnrollmentDatePredicate(Date _d)
	{
		d = _d;
	}

	bool virtual operator () (Employee emp)
	{
		return (emp.EnrollmentDate == d);
	}

	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return (emp1.EnrollmentDate == emp2.EnrollmentDate);
	}
};

class SalaryPredicate
{
protected:
	dec::decimal<2> salary;

public:
	SalaryPredicate(dec::decimal<2> _salary)
	{
		salary = _salary;
	}

	bool virtual operator () (Employee emp)
	{
		return emp.Salary == salary;
	}

	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Salary == emp2.Salary;
	}
};

//Comparators

class PersonnelNumberComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.PersonnelNumber < emp2.PersonnelNumber;
	}
};

class DepartmentComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Department < emp2.Department;
	}
};

class NameComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Name < emp2.Name;
	}
};

class EnrollmentDateComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		if (emp1.EnrollmentDate < emp2.EnrollmentDate) return true;
		return false;
	}
};

class SalaryComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Salary < emp2.Salary;
	}
};

class OverheadComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Overhead < emp2.Overhead;
	}
};

class IncomeTaxComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.IncomeTax < emp2.IncomeTax;
	}
};

class DaysWorkedComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.DaysWorked < emp2.DaysWorked;
	}
};

class AllWorkingDaysComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.AllWorkingDays < emp2.AllWorkingDays;
	}
};

class AccruedComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Accrued < emp2.Accrued;
	}
};

class WithheldComparator
{
public:
	bool virtual operator () (Employee emp1, Employee emp2)
	{
		return emp1.Withheld < emp2.Withheld;
	}
};

//SubVectorsCreators

class PersonnelNumberSubVector
{
protected:
	int per;
	std::vector<Employee>* v;

public:
	PersonnelNumberSubVector(int _per)
	{
		per = _per;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.PersonnelNumber == per)
			(*v).push_back(emp);
	}
};

class DepartmentSubVector
{
protected:
	int dep;
	std::vector<Employee>* v;

public:
	DepartmentSubVector(int _dep)
	{
		dep = _dep;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Department == dep)
			(*v).push_back(emp);
	}
};

class NameSubVector
{
protected:
	std::string name;
	std::vector<Employee>* v;

public:
	NameSubVector(std::string _name)
	{
		name = _name;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Name == name)
			(*v).push_back(emp);
	}
};

class EnrollmentDateSubVector
{
protected:
	Date d;
	std::vector<Employee>* v;
public:
	EnrollmentDateSubVector(Date _d)
	{
		d = _d;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.EnrollmentDate == d)
			(*v).push_back(emp);
	}
};

class SalarySubVector
{
protected:
	dec::decimal<2> salary;
	std::vector<Employee>* v;
public:
	SalarySubVector(dec::decimal<2> _salary)
	{
		salary = _salary;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Salary == salary)
			(*v).push_back(emp);
	}
};

class OverheadSubVector
{
protected:
	dec::decimal<2> over;
	std::vector<Employee>* v;
public:
	OverheadSubVector(dec::decimal<2> _over)
	{
		over = _over;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Overhead == over)
			(*v).push_back(emp);
	}
};

class IncomeTaxSubVector
{
protected:
	dec::decimal<2> inco;
	std::vector<Employee>* v;
public:
	IncomeTaxSubVector(dec::decimal<2> _inco)
	{
		inco = _inco;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.IncomeTax == inco)
			(*v).push_back(emp);
	}
};

class DaysWorkedSubVector
{
protected:
	int d;
	std::vector<Employee>* v;

public:
	DaysWorkedSubVector(int _d)
	{
		d = _d;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.DaysWorked == d)
			(*v).push_back(emp);
	}
};

class AllWorkingDaysSubVector
{
protected:
	int d;
	std::vector<Employee>* v;

public:
	AllWorkingDaysSubVector(int _d)
	{
		d = _d;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.AllWorkingDays == d)
			(*v).push_back(emp);
	}
};

class AccruedSubVector
{
protected:
	dec::decimal<2> acc;
	std::vector<Employee>* v;
public:
	AccruedSubVector(dec::decimal<2> _acc)
	{
		acc = _acc;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Accrued == acc)
			(*v).push_back(emp);
	}
};

class WithheldSubVector
{
protected:
	dec::decimal<2> w;
	std::vector<Employee>* v;
public:
	WithheldSubVector(dec::decimal<2> _w)
	{
		w = _w;
		v = new std::vector<Employee>();
	}

	std::vector<Employee> getSet()
	{
		return *v;
	}

	void virtual operator () (Employee emp)
	{
		if (emp.Withheld == w)
			(*v).push_back(emp);
	}
};

template <class T>
class Container
{
public:

	Container(int size)
	{
		vect = std::vector<T>(size);
	}

	Container()
	{
		vect = std::vector<T>();
	}

	~Container() {}

	void Add(T el) {
		//if (!Find(el))
		//{
			vect.push_back(el);
		//}
		//else
		//	return false;
	}


	bool Find(T el, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> &it)
	{
		it = std::find(vect.begin(), vect.end(), el);
		return it != vect.end();
	}

	bool Find(T el)
	{
		std::vector<T>::iterator it =
			std::find(vect.begin(), vect.end(), el);
		return it != vect.end();
	}

	template<class Predicate>
	bool FindBy(Predicate &pred, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> &it)
	{
		std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> tmpIt;
		tmpIt = std::find_if(vect.begin(), vect.end(), pred);
		if (tmpIt == vect.end())
			return false;
		it = tmpIt;
		return true;
	}

	std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> FindByIndex(int index)
	{
		if (index < 1 || index > Size())
			throw "������������ ������";
		std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> it = vect.begin();
		for (int i = 1; i < index; i++)
		{
			it++;
		}
		return it;
	}

	template<class Comparator>
	bool FindByBinary(Comparator &comp, T &bibb, std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> &it)
	{
		std::sort(vect.begin(), vect.end(), comp);
		std::_Vector_iterator<std::_Vector_val<std::_Simple_types<T>>> tmpIt;
		tmpIt = std::lower_bound(vect.begin(), vect.end(), bibb, comp);
		if (tmpIt == vect.end() || comp(bibb, *tmpIt))
			return false;
		it = tmpIt;
		return true;
	}

	template<class SubVector>
	std::vector<T> FindSubSetBy(SubVector v)
	{
		std::for_each(vect.begin(), vect.end(), v);
		return v.getSet();
	}

	template<class T>
	void Sort(T &comp)
	{
		std::sort(vect.begin(), vect.end(), comp);
	};

	int Size()
	{
		return vect.size();
	}

	void Clear()
	{
		vect.clear();
	}

protected:
	std::vector<T> vect;
};


void InputEmployeChange(std::vector<Employee>::iterator &it);

class EmpContainer : public Container<Employee>
{
public:

	EmpContainer(std::vector<Employee> v)
	{
		vect = v;
	}

	EmpContainer()
	{
		vect = std::vector<Employee>();
	}

	void Remove(std::vector<Employee>::iterator it)
	{
		vect.erase(it);
	}

	void Change(std::vector<Employee>::iterator &it)
	{
		InputEmployeChange(it);
	}

	bool FindByDepartment(int  dep, std::vector<Employee>::iterator &it)
	{
		DepartmentPredicate p = DepartmentPredicate(dep);
		return FindBy(p, it);
	}

	bool FindByName(std::string name, std::vector<Employee>::iterator &it)
	{
		NamePredicate p = NamePredicate(name);
		return FindBy(p, it);
	}
	
	bool FindByEnrollmentDate(Date date, std::vector<Employee>::iterator &it)
	{
		EnrollmentDatePredicate p = EnrollmentDatePredicate(date);
		return FindBy(p, it);
	}

	bool FindBySalary(dec::decimal<2> salary, std::vector<Employee>::iterator &it)
	{
		SalaryPredicate p = SalaryPredicate(salary);
		return FindBy(p, it);
	}

	bool FindByDepartmentBinary(int dep, std::vector<Employee>::iterator &it)
	{
		DepartmentComparator c = DepartmentComparator();
		Employee employee = Employee();
		employee.Department = dep;

		return FindByBinary(c, employee, it);
	}

	bool FindByNameBinary(std::string name, std::vector<Employee>::iterator &it)
	{
		NameComparator c = NameComparator();
		Employee employee = Employee();
		employee.Name = name;

		return FindByBinary(c, employee, it);
	}

	bool FindByEnrollmentDateBinary(Date date, std::vector<Employee>::iterator &it)
	{
		EnrollmentDateComparator c = EnrollmentDateComparator();
		Employee employee = Employee();
		employee.EnrollmentDate = date;

		return FindByBinary(c, employee, it);
	}

	bool FindBySalaryBinary(dec::decimal<2> salary, std::vector<Employee>::iterator &it)
	{
		DepartmentComparator c = DepartmentComparator();
		Employee employee = Employee();
		employee.Salary = salary;

		return FindByBinary(c, employee, it);
	}

	EmpContainer FindSubVectByPersonnelNumber(int num)
	{
		PersonnelNumberSubVector psv = PersonnelNumberSubVector(num);

		return EmpContainer(FindSubSetBy(psv));
	}
	
	EmpContainer FindSubVectByDepartment(int dep)
	{
		DepartmentSubVector dsv = DepartmentSubVector(dep);
		
		return EmpContainer(FindSubSetBy(dsv));
	}

	EmpContainer FindSubVectByName(std::string name)
	{
		NameSubVector nsv = NameSubVector(name);
		
		return EmpContainer(FindSubSetBy(nsv));
	}

	EmpContainer FindSubVectByEnrollmentDate(Date date)
	{
		EnrollmentDateSubVector esv = EnrollmentDateSubVector(date);
		
		return EmpContainer(FindSubSetBy(esv));
	}

	EmpContainer FindSubVectBySalary(dec::decimal<2> salary)
	{
		SalarySubVector ssv = SalarySubVector(salary);

		return EmpContainer(FindSubSetBy(ssv));
	}

	EmpContainer FindSubVectByOverhead(dec::decimal<2> o)
	{
		SalarySubVector osv = SalarySubVector(o);

		return EmpContainer(FindSubSetBy(osv));
	}

	EmpContainer FindSubVectByIncomeTax(dec::decimal<2> i)
	{
		SalarySubVector isv = SalarySubVector(i);

		return EmpContainer(FindSubSetBy(isv));
	}

	EmpContainer FindSubVectByDaysWorked(int d)
	{
		DepartmentSubVector dsv = DepartmentSubVector(d);

		return EmpContainer(FindSubSetBy(dsv));
	}

	EmpContainer FindSubVectByAllWorkingDays(int d)
	{
		DepartmentSubVector dsv = DepartmentSubVector(d);

		return EmpContainer(FindSubSetBy(dsv));
	}

	EmpContainer FindSubVectByAccrued(dec::decimal<2> a)
	{
		SalarySubVector asv = SalarySubVector(a);

		return EmpContainer(FindSubSetBy(asv));
	}

	EmpContainer FindSubVectByWithheld(dec::decimal<2> w)
	{
		SalarySubVector wsv = SalarySubVector(w);

		return EmpContainer(FindSubSetBy(wsv));
	}

	void SortByPersonnelNumber()
	{
		PersonnelNumberComparator comp = PersonnelNumberComparator();
		Sort(comp);
	}

	void SortByDepartment()
	{
		DepartmentComparator comp = DepartmentComparator();
		Sort(comp);
	}

	void SortByName()
	{
		NameComparator comp = NameComparator();
		Sort(comp);
	}

	void SortBySalary()
	{
		SalaryComparator comp = SalaryComparator();
		Sort(comp);
	}

	void SortByEnrollmentDate()
	{
		EnrollmentDateComparator comp = EnrollmentDateComparator();
		Sort(comp);
	}

	void SortByOverhead()
	{
		OverheadComparator comp = OverheadComparator();
		Sort(comp);
	}

	void SortByIncomeTax()
	{
		IncomeTaxComparator comp = IncomeTaxComparator();
		Sort(comp);
	}

	void SortByDaysWorked()
	{
		DaysWorkedComparator comp = DaysWorkedComparator();
		Sort(comp);
	}

	void SortByAllWorkingDays()
	{
		AllWorkingDaysComparator comp = AllWorkingDaysComparator();
		Sort(comp);
	}

	void SortByAllAccrued()
	{
		AccruedComparator comp = AccruedComparator();
		Sort(comp);
	}

	void SortByWithheld()
	{
		WithheldComparator comp = WithheldComparator();
		Sort(comp);
	}

	void FileInput(std::fstream& fin)
	{
		if (fin.is_open())
		{
			std::istream_iterator<Employee> is(fin);
			vect.clear();
			Employee emp = *is++;
			while (!fin.fail() && !fin.eof())
			{
				Add(emp);
				emp = *is++;
			}
			if (emp.PersonnelNumber != 0)
			Add(emp);
			fin.close();
		}
		else
			std::cout << "���� �� ������!" << std::endl;
	}

	void FileOutput(std::fstream& fout)
	{
		if (fout.is_open())
		{
			copy(vect.begin(), vect.end(), std::ostream_iterator<Employee>(fout, "\n"));
			fout.close();
		}
		else
			std::cout << "������ ������";
	}

	void Output(std::ostream_iterator<Employee> os)
	{
		copy(vect.begin(), vect.end(), os);
	}

};



static void PrintHead();

void ConsoleInput(EmpContainer& cont)
{
	std::string temp;
	Employee emp;
	while (true)
	{
		try
		{
			emp = InputEmployee();
		}
		catch (...)
		{
			return;
		}
		cont.Add(emp);

		std::cout << "�������� ��� ����? (0 - ���)\n";
		std::cin >> temp;

		if (std::stoi(temp) == 0) return;		
	}
}

void ConsoleOutput(EmpContainer& cont)
{
	if (cont.Size() != 0)
	{
		PrintHead();
		cont.Output(std::ostream_iterator<Employee>(std::cout, "\n"));
	}
	else
	{
		std::cout << "��������� ����!\n";
	}
}

dec::decimal<2> InputDecimal(std::string message = "", bool isAdd = false, dec::decimal<2> min = (dec::decimal<2>)0,
	dec::decimal<2> max = (dec::decimal<2>)100000)
{
	std::string str;
	dec::decimal<2> res;

	while (true) {
		std::cout << message;
		try {
			std::cin >> str;
			if (str == "�����") throw "�����";
			if (str == "=" && !isAdd) return dec::decimal_cast<2>(-1);
			float tmpflt = std::stof(str);
			res = dec::decimal_cast<2>(str);
			while ((res < min || res > max)&&(str != "=")) {
				std::cout << "������ (�������� < " << min << " ��� �������� > " << max << "). ���������: " << std::endl;
				std::cin >> str;
				res = dec::decimal_cast<2>(str);
			}
			std::cout << std::endl;
			return res;
		}
		catch (...) {
			std::cout << "��������� �����!" << std::endl;
		}
	}
}

int InputInt(std::string message = "", bool isAdd = false, int min = 0, int max = 1000000)
{
	std::string str;
	int res;

	while (true)
	{
		std::cout << message;
		try
		{
			std::cin >> str;
			if (str == "�����") throw "�����";
			if (str == "=" && !isAdd) return -1;
			res = std::stoi(str);
			while (res < min || res > max)
			{
				std::cout << "������ (�������� < " << min << " ��� �������� > " << max << "). ���������: " << std::endl;
				std::cin >> str;
				res = std::stoi(str);
			}
			std::cout << std::endl;
			return res;
		}
		catch (...)
		{
			std::cout << "��������� �����!" << std::endl;
		}
	}
}

Date InputDate(bool isAdd = false, std::string message = "������� ���� � ������� ��.��.����: ") {
	Date date = Date();

	std::string buf;
	bool ok = false;
	while (!ok)
	{
		std::cout << message;
		std::cin >> buf;
		if (buf == "�����") throw "�����";
		if (buf == "=" && !isAdd) return Date();
		ok = Date::StrToDate(buf, date);
		if (!ok)
			std::cout << "�������� ��������!";
	}
	return date;
}

Employee InputEmployee()
{
	int _PersonnelNumber;
	int _Department;
	std::string _Name;
	dec::decimal<2> _Salary;
	Date _EnrollmentDate;
	dec::decimal<2> _Overhead;
	dec::decimal<2> _IncomeTax;
	int _DaysWorked;
	int _AllWorkingDays;
	dec::decimal<2> _Accrued;
	dec::decimal<2> _Withheld;

	std::cout << "���� ���������� � ����������" << std::endl;

	_PersonnelNumber = InputInt("��������� �����: ",true, 1);

	_Department = InputInt("����� ������: ", true);

	std::cout << "�������: ";
	std::cin >> _Name;
	std::cout << std::endl;

	_Salary = InputDecimal("�����: ", true);

	_EnrollmentDate = InputDate(true);

	_Overhead = InputDecimal("������� ��������: ", true);
	_IncomeTax = InputDecimal("���������� �����: ", true);
	_DaysWorked = InputInt("���������� ����: ", true, 0, 31);
	_AllWorkingDays = InputInt("������� ���� � ������: ", true, 0, 31);
	_Accrued = InputDecimal("���������: ", true);
	_Withheld = InputDecimal("��������: ", true);

	return Employee(_PersonnelNumber, _Department, _Name, _Salary, _EnrollmentDate, _Overhead, _IncomeTax, _DaysWorked,
		_AllWorkingDays, _Accrued, _Withheld);
}

void InputEmployeChange(std::vector<Employee>::iterator &it)
{
	std::cout << "-------------���������-------------" << std::endl;
	std::cout << "������� = ����� ����������" << std::endl;

	std::string tmpstr = "";

	int tmpint = InputInt("������� ��������� �����(������� " + std::to_string(it->PersonnelNumber) + "): ");
	if (tmpint != -1) it->PersonnelNumber = tmpint;

	tmpint = InputInt("������� ����� ������(������� " + std::to_string(it->Department) + "): ");
	if (tmpint != -1) it->Department = tmpint;
	
	std::cout << "������� �������(�������: " + it->Name + "): ";
	std::cin >> tmpstr;
	if (tmpstr != "=") it->Name = tmpstr;

	dec::decimal<2> tmpdec = InputDecimal("������� �����(�������: " + dec::toString(it->Salary) + "): ");
	if (tmpdec != dec::decimal_cast<2>(-1)) it->Salary = tmpdec;

	std::string datestr = it->EnrollmentDate.to_string();
	Date dt = InputDate(false, "������� ���� �����������(��.��.����)(������� : " + datestr + ")");
	Date defDt = Date();
	if (!(dt == defDt))
		it->EnrollmentDate = dt;

	tmpdec = InputDecimal("������� ������� ��������(�������: " + dec::toString(it->Overhead) + "): ");
	if (tmpdec != dec::decimal_cast<2>(-1)) it->Overhead = tmpdec;

	tmpdec = InputDecimal("������� ���������� �����(�������: " + dec::toString(it->IncomeTax) + "): ");
	if (tmpdec != dec::decimal_cast<2>(-1)) it->IncomeTax = tmpdec;

	tmpint = InputInt("������� ��� - �� ������������ ���� � ������(������� " + std::to_string(it->DaysWorked) + "): ", false, 0, 31);
	if (tmpint != -1) it->DaysWorked = tmpint;

	tmpint = InputInt("������� ���-�� ������� ���� � ������(������� " + std::to_string(it->AllWorkingDays) + "): ", false, 0, 31);
	if (tmpint != -1) it->AllWorkingDays = tmpint;

	tmpdec = InputDecimal("������� ���������(�������: " + dec::toString(it->Accrued) + "): ");
	if (tmpdec != dec::decimal_cast<2>(-1)) it->Accrued = tmpdec;

	tmpdec = InputDecimal("������� ��������(�������: " + dec::toString(it->Withheld) + "): ");
	if (tmpdec != dec::decimal_cast<2>(-1)) it->Withheld = tmpdec;
}

static void PrintHead()
{
	std::cout << "��������� �\t" << "� ������\t" << "�������\t" << "�����\t" << "���� �����������\t" << "��������\t" << "�����������\t" << "������� ����\t" << "���������\t" << "��������\n";
}