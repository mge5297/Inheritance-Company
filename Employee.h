/**********************************************
* Program:  Employee.h                           *
* Author:  Michael Elkins                      *
* Date:   4/17/19                            *
*                                             *
* Abstract:  *
*            *
**********************************************/
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
/**************EMPLOYEE**************************/
class Employee{
	
	friend ostream & operator << (ostream & os, Employee employee) ;
	friend int operator + (Employee & employee1, int weeks);
	friend bool operator < (Employee employee1, Employee employee2);
	
		public:
			Employee();
			Employee(string id,string theName, int vaca);
			double Pay();
			void SetName(string newname);
			string GetName();
			
		protected:
			string ID;
			string name;
			int vacation;
			double income;
	
	
	
};
/************EMPLOYEE****************************************/
Employee::Employee(){
	name = "NO NAME";
	ID = "NO ID";
	vacation = 0;
	income = 0;
}

Employee::Employee(string id, string theName, int vaca){
	name = theName;
	ID = id;
	vacation = vaca;
	income = 0;
}

void Employee::SetName(string newname){
	name = newname;
	
}

string Employee::GetName(){
	return name;
	
}

double Employee::Pay(){
	income = income + 100000;
	return income;
}
/*******************SALARY************************************/
class Salary : public Employee{
	friend ostream & operator <<(ostream & os, Salary salary);
	
		public:
			Salary();
			Salary(string id, string theName, int vaca, double sal , char freq);
			void SetSalary(double sal);
			void SetTravelBudget(double trav);
			bool SetPayFrequency(char freq);
			double Pay();
			void TripExpense(double cost);
			double GetSalary();
		
		protected:
			double salary;
			char frequency;
			double travel;
	
};
/******************SALARY*************************************/
Salary::Salary()
	:Employee(){
	salary = 0;
	frequency = '0';
	income = 0;
	travel = 0;
}


Salary::Salary(string id, string theName, int vaca, double sal , char freq)
	:Employee(id, theName, vaca){
	salary = sal;
	frequency = freq;
	income = 0;
	travel = 0;
	
}
void Salary::SetSalary(double sal){
	salary = sal;
}
void Salary::SetTravelBudget(double trav){
	travel = trav;
}
bool Salary::SetPayFrequency(char freq){
	frequency = freq;
	if (freq == 'M' || freq == 'B')
		return true;
	else
		return false;
	
}
double Salary::Pay(){
	double money = 0;
	if(frequency == 'M'){
		income = income + salary / 12; 
		return salary / 12;
	}
	
	if(frequency == 'B'){
		income = income + salary / 26;	
		return salary / 26;
	}
	
	
	
}
void Salary::TripExpense(double cost){
	travel = travel - cost;
}

double Salary::GetSalary(){
	return salary;
}
/****************Manager**************************************/
class Manager : public Salary{
	
		friend ostream & operator << (ostream & os, Manager manager);
	
		public:
			Manager(string id, string theName, int vaca, double sal , char freq, string model, int year, string License);
			void NewCar(string model, int year);
			void NewLicense(string plate);
			
		protected:
			string car;
			int make;
			string license;
	
};
/****************Manager**************************************/

Manager::Manager(string id, string theName, int vaca, double sal , char freq, string model, int year, string License)
	:Salary(id, theName, vaca , sal, freq){
	car = model;
	make = year;
	license = License;
	income = 0;
}


void Manager::NewCar(string model, int year){
	car = model;
	make = year;
	
}

void Manager::NewLicense(string plate){
	license = plate;
	
}

/****************Technician**************************************/
class Technician : public Salary{
	
	friend ostream & operator << (ostream & os, Technician tech);
	
		public:
			Technician();
			Technician(string id, string theName, int vaca, double sal , char freq, string Cert);
			void AddCertification(string cert, double cost);
			bool HasCertification(string cert);
			
		protected:
			string certifications;
			double education;	
	
};
/****************Technician**************************************/
Technician::Technician()
	:Salary(){
		
	certifications = "uncertified";
	income = 0;
	education = 0;
}

Technician::Technician(string id, string theName, int vaca, double sal , char freq, string Cert)
	:Salary(id, theName, vaca , sal, freq){
	certifications = Cert;
	income = 0;
	education = 0;
	
}

void Technician::AddCertification(string cert, double cost){
	if(certifications == ""){
		certifications = cert;
		education = education + cost;
	}
	else{
		certifications = certifications + ", " + cert;
		education = education + cost;
	}
	
}

bool Technician::HasCertification(string cert){
	if(certifications.find(cert) == -1)
		return false;
	else
		return true;
	
}
/****************Hourly**************************************/
class Hourly : public Employee{
		
	friend ostream & operator << (ostream & os, Hourly hour);
	friend double operator % (Hourly & hour , double percent);
	friend double operator ^ (Hourly & hour, double increase);
		public:
			Hourly(string id,string theName, int vaca, double payrate);
			void SetPayRate(double newrate);
			double TimeCardEntry(double worked);
			double Pay();
			
		protected:
			double rate;
			double hours;
	
	
};
/****************Hourly**************************************/
Hourly::Hourly(string id,string theName, int vaca, double payrate)
	:Employee(id, theName, vaca){
	rate = payrate;
	hours = 0;
	income = 0;
	
}

void Hourly::SetPayRate(double newrate){
	rate = newrate;
}

double Hourly:: TimeCardEntry(double worked){
	hours = hours + worked;
	return hours;
}

double Hourly::Pay(){
	double paid;
	
	if (hours > 40.00){
		paid = 40.00 * rate + (hours - 40.00) * rate * 1.5;
		income = income + paid;
		hours = 0;
		return paid;
	}
	else{
		paid = rate * hours;
		income = income + paid;
		hours = 0;
		return paid;
				
	}
	
}

/**************************Fulltime**********************************/
class Fulltime : public Hourly{
		
	friend ostream & operator << (ostream & os, Fulltime fulltime);
	
		public:
			Fulltime(string id,string theName, int vaca, double payrate, int grade);
			int Anniversary();
			void SetPayGrade(int grade);
						
		protected:
			int yrserv;
			int paygrade;
	
	
};
/****************Fulltime**************************************/
Fulltime::Fulltime(string id,string theName, int vaca, double payrate,int grade)
	:Hourly(id, theName, vaca, payrate){
	paygrade = grade;
	hours = 0;
	income = 0;
	yrserv = 0;
	
}

int Fulltime::Anniversary(){
	
	yrserv++;
	return yrserv;
	
}

void Fulltime::SetPayGrade(int grade){
	paygrade = grade;
}


/**************************Parttime**********************************/
class Parttime : public Hourly{
		
	friend ostream & operator << (ostream & os, Parttime parttime);
	
		public:
			Parttime(string id,string theName, int vaca, double payrate, int max , bool stud);
			void SetMaximum(int newmax);
			void Graduated();
			bool Schedule(double hrs);
			double Pay();
						
		protected:
			int maxhr;
			bool student;
	
	
};
/****************Parttime**************************************/
Parttime::Parttime(string id,string theName, int vaca, double payrate,int max , bool stud)
	:Hourly(id, theName, vaca, payrate){
	maxhr = max;
	student = stud;
	hours = 0;
	income = 0;
	
	
}

void Parttime::SetMaximum(int newmax){
	
	maxhr = newmax;
	
}

void Parttime::Graduated(){
	student = false;
}

bool Parttime::Schedule(double hrs){
	if(hours + hrs > maxhr){
		return false;
	}
	else{
		return true;
	}
	
}

double Parttime::Pay(){
	double paid;
	paid = rate * hours;
	income = income + paid;
	hours = 0;
	return paid;
	
}


/**********************Overloaded Operators***********************************/
	ostream & operator << (ostream & os, Employee employee){
		os << fixed << setprecision(2);
		os << "ID:" << employee.ID << "  Name:" << employee.name << "  YTD:" << employee.income << "  Weeks:"
		 << employee.vacation << endl;
		 
		 return os;
	}
	
	int operator + (Employee & employee1, int weeks){
		employee1.vacation = employee1.vacation + weeks;
		
		 
		 return employee1.vacation;
	}
	
	double operator % (Hourly & hour , double percent){
		hour.rate = hour.rate * (percent + 1);
		
		return hour.rate;
		
	}
	
	ostream & operator << (ostream & os, Salary _salary){
		os << fixed << setprecision(2);
		os << "ID:" << _salary.ID << "  Name:" << _salary.name << "  YTD:" << _salary.income << "  Weeks:"
		 << _salary.vacation << endl << "YrPay:" << _salary.salary << "  ParFreq:" << _salary.frequency 
		 << "  Travel:" << _salary.travel << endl;
		 
		 return os;
	}
		
	ostream & operator << (ostream & os, Manager manager){
		os << fixed << setprecision(2);
		os << "ID: " << manager.ID << "  Name: " << manager.name << "  YTD: " << manager.income << "  Weeks: "
		 << manager.vacation << endl << "YrPay: " << manager.salary << "  PayFreq: " << manager.frequency 
		 << "  Travel: " << manager.travel << endl << "Vehicle: " << manager.make << "  " << manager.car << "  License: "
		  << manager.license << endl;
		 
		 return os;
	}
	
	ostream & operator << (ostream & os, Technician tech){
		os << fixed << setprecision(2);
		os << "ID:" << tech.ID << "  Name:" << tech.name << "  YTD:" << tech.income << "  Weeks:"
		 << tech.vacation << endl << "YrPay:" << tech.salary << "  ParFreq:" << tech.frequency 
		 << "  Travel:" << tech.travel << endl << "Certifications: " << tech.certifications << "  Education Budget: "
		  << tech.education << endl;
		 
		 return os;
	}
	
	ostream & operator << (ostream & os, Hourly hour){
		os << fixed << setprecision(2);
		os << "ID:" << hour.ID << "  Name:" << hour.name << "  YTD:" << hour.income << "  Weeks:"
		 << hour.vacation << endl << "Hourly Rate: " << hour.rate << "  Hours Worked: " << hour.hours << endl;
		 
		 return os;
	}

	ostream & operator << (ostream & os, Fulltime fulltime){
		os << fixed << setprecision(2);
		os << "ID:" << fulltime.ID << "  Name:" << fulltime.name << "  YTD:" << fulltime.income << "  Weeks:"
		 << fulltime.vacation << endl << "Hourly Rate: " << fulltime.rate << "  Hours Worked: " << fulltime.hours << endl 
		 << "Yrs Served: " << fulltime.yrserv << "  PayGrade: " << fulltime.paygrade << endl;
		 
		 return os;
	}
	
	double operator ^ (Hourly & hour, double increase){
		hour.hours = hour.hours + increase;
		return hour.hours;
		
	}

	ostream & operator << (ostream & os, Parttime parttime){
		string stud;
		if(parttime.student){
			stud = "Yes";
		}
		else
			stud ="No";
		
		os << fixed << setprecision(2);
		os << "ID:" << parttime.ID << "  Name:" << parttime.name << "  YTD:" << parttime.income << "  Weeks:"
		 << parttime.vacation << endl << "Hourly Rate: " << parttime.rate << "  Hours Worked: " << parttime.hours << endl 
		 << "Max Hours: " << parttime.maxhr << "  Student: " << stud << endl;
		 
		 return os;
	}
	
	bool operator < (Employee employee1, Employee employee2){
		if(employee1.ID < employee2.ID){
			return true;
		}
		else
			return false;
		
	}

