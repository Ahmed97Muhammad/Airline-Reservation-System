#ifndef AIRLINEWORKERS_H
#define AIRLINEWORKERS_H

#include<iostream>
using namespace std;

class Airline_Asset//class for name and city of the airline
{
	protected:
		static string Airline_Name;//saves airline name
		static string City;//saves airline city

	public:
        Airline_Asset(string an, string city );//sets name and city
        void display();//displays name and city
};



class Person//persons class
{
	protected:
		string Phone_Num;//persons phone number
		int Age;//persons age
		string NIC;//persons nic 
		string Adress;//persons adress
		string Name;//persons name


	public:
		Person();//default construtor
		Person(string nic);                            //Takes NIC
		virtual void edit_Info()=0;             //Abstract class
	    Person& operator=(Person &obj);//assignment operator
};

//employee class    relationship:employee is a person
class Employee : public Person
{
	protected:
	int Emp_ID;//unique identity of employee
	static int Count;//employee count
	double Salary;//employees salary
	

	public:
		Employee();//default constructor
		Employee( string nic,int id );                  //Take NIC and Emp_ID
	   virtual void edit_Info()=0;                     //Abstract class
	   void write_To_File();//wrtie the employee info to file
	   int get_Emp_ID();//returns employee id
	   Employee& operator=(Employee &obj);//assignment operator
};


//staff class   relationship:staff member is an employee
class Staff : public Employee
{
	private:
		int Grade;//grade for calculating salary
        string Designation;//department in which he is employeed to

	public:
		Staff();//default constructor
	    Staff( int empid , string nic );//sets nic and employee id
	    void Constructor_Calling( int empid ,string nic );//calls the 2 argument constructor
		void set_Grade(int);//sets the grade
		void edit_Info();//all the info is entered of the staff member
		void pay_Sal();                           //Pays the salary and records it into file
		void display();//dsiplays all the records of staff members
		void set_static_count();//contains the total number of objects of staff members created in a file
		void write_To_File();                   //saves all data on file
		void Salary_writing_in_file();//creates final salrary reord on file
		Staff& operator=(Staff &obj);    //assignment operator
		friend ostream& operator<<(ostream &out ,Staff &obj);//output operator for displaying objects on console
};


//Pilot class   relationship:Pilot is an employee
class Pilot : public Employee
{
	private:
		int Hours;//hours for which pilot can take flights
		double H_Wage;//per hour wage


	public:
		Pilot();//default constructor
		Pilot( int empid ,string nic);//sets nic and employee id
		void Constructor_Calling( int empid ,string nic );//calls the 2 argument constructor
		void set_Hrs(int hrs=0);//sets the grade
		void set_Hrs_wage();//calcultes the salary
		void pay_Wage();                        //Pays the wage, resets Hours to 0
		void edit_Info(); //all the info is entered of the Pilot
		void display();//dsiplays all the records of pilots
		void set_static_count();//contains the total number of objects of Pilots created in a file
		void Salary_writing_in_file();//creates final salrary reord on file
		void write_To_File();                   //saves all data on file
		Pilot& operator+=(const double);         //Increments the flight hours of pilot
		Pilot& operator=(Pilot &obj);    //assignment operator
		friend ostream& operator<<(ostream &out ,Pilot &obj);//output operator for displaying objects on console
};

#endif
