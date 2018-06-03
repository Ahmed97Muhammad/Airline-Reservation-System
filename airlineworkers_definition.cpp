#include<iostream>
#include<fstream>
#include<ctime>
#include<cstring>
using namespace std;


#include"airlineworkers_declaration.h"
#include"tickets_declaration.h"

Airline_Asset::Airline_Asset( string an, string city )//sets the airline name and city in which its headquater is
{
	Airline_Name=an;
	City=city;
}
string Airline_Asset::Airline_Name="PAKISTAN INTERNATIONAL AIRLINE";
string Airline_Asset::City="KARACHI";

void Airline_Asset::display()//displays the name and city of airline
{
      	cout<<"AIRLINE NAME: "<<Airline_Asset::Airline_Name;
	    cout<<"\nAIRLINE CITY: "<<Airline_Asset::City<<"\n\n";
}


Person::Person( string nic ):NIC(nic)//one argument constructotor sets nic
{   }

Person::Person()//default constructotor
{   }

Person& Person::operator=(Person &obj)//persons assignment operator copies one person to another
{
	if(this!=&obj)//if l.h.s != r.h.s
	{
		Phone_Num=obj.Phone_Num;
		Age=obj.Age;
		NIC=obj.NIC;
		Adress=obj.Adress;
		Name=obj.Name;
	}
	return *this;//objects reference
}


Employee::Employee( string nic , int id ): Person(nic) , Emp_ID(id)//two argument constructotor sets nic and employee id
{   }

Employee::Employee():Emp_ID(0)//default constructotor
{   }
int Employee::Count=0;//static emplyee count

int Employee::get_Emp_ID()//returns employee id
{
	return Emp_ID;
 } 

Employee& Employee::operator=(Employee &obj)//employee assignment operator copies one employee to another
{
	if(this!=&obj)//if l.h.s != r.h.s
	{
		Phone_Num=obj.Phone_Num;
		Age=obj.Age;
		Adress=obj.Adress;
		Name=obj.Name;
	    NIC=obj.NIC;
		Emp_ID=obj.Emp_ID;
	    Salary=obj.Salary;
	}
	return *this;//objects reference
}



Pilot::Pilot()//pilot default construtor
{   }

Pilot::Pilot(int empid , string nic) :Employee( nic , empid )//two argument constructotor sets nic and employee id
{ 
    Salary=0;
}

void Pilot::Constructor_Calling( int empid ,string nic )//calls the above constructor
{
	Emp_ID=empid;
	NIC=nic;
}

void Pilot::edit_Info()//sets the data of pilot
{
	set_static_count();//reads the count of pilots in file
	
	Count++;
	
	
	ofstream file("Set_Count_for_pilot's.txt");//saves the count on file
	file<<Count;
	file.close();
	
	
	cout<<"EMPLOYEE NUMBER :  "<<Count<<endl;//employee record number
	
	//rest of the data of pilot
	fflush(stdin);
	cout<<"Enter the Employee's name:   ";
	getline(cin,Name);
	
	cout<<"Enter the Employee's age:    ";
		try//Exception handling
       {
   	   cin>>Age;
   	   if(Age==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    } 
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	
	fflush(stdin);
	cout<<"Enter the Employee's phone number:    ";
	getline(cin,Phone_Num);
	
	fflush(stdin);
	cout<<"Enter the employee's address:    ";
	getline(cin,Adress);
	
}

void Pilot::set_Hrs(int hrs)//set hours of pilot
{
    Hours=hrs;
}

void Pilot::set_Hrs_wage()//set hours wage of pilot
{
	H_Wage = 11999;
}

void Pilot::pay_Wage()//claculate the salry of pilot
{
	double a= H_Wage * Hours;
	Salary+=a;
	Hours=0;
}

void Pilot::set_static_count()//reads the count of pilot stors in pilot
{
	ifstream file("Set_Count_for_pilot's.txt");
		file.seekg(0,ios::end); 
	if (file.tellg()==0) //check if file is empty or not
	{
		cout<<"\n\nSet_Count_for_pilot's.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//clears the eof error
	file.seekg(0, ios::beg);//points the file to begining
	file>>Count;
	file.close();
}

void Pilot::display()//displays the record of pilot
{
	string a="\t\tPILOT'S RECORD NUMBER: ";
	static int c=1;
	
	cout<<a<<c<<endl<<endl;
	cout<<"====================================================="<<endl;
    
	a="PILOT'S NAME:  ";
    cout<<a<<Name<<endl;
    
	a="PILOT'S NIC:  ";
    cout<<a<<NIC<<endl;
    
	a="PILOT'S AGE:  ";
    cout<<a<<Age<<endl;
    
	a="PILOT'S ADRESS:  ";
    cout<<a<<Adress<<endl;
    
	a="PILOT'S PHONE NUMBER:  ";
    cout<<a<<Phone_Num<<endl;
    
	a="PILOT'S ID:   ";
    cout<<a<<Emp_ID<<endl;
    
    a="PILOT'S SALARY:  ";
    cout<<a<<Salary<<endl;
    cout<<"====================================================="<<endl<<endl<<endl;
    
    c++;
    
}

void Pilot::Salary_writing_in_file()//saves the salary record in file i.e final salary report
{
	Date_Time obj;  //for setting current date and time
	
	ofstream file("Salary_Records.txt",ios::out|ios::app);//file open in append mode
	file<<"====================================================="<<endl;
	file<<"PILOT'S ID: "<<Emp_ID<<"\t";
	file<<"SALARY PAID IS: "<<Salary<<"\n"<<"AT DATE AND TIME: ";
	file<<obj<<"\n";
	file<<"====================================================="<<endl;
	file.close();
}

void Pilot::write_To_File()//writes the record of pilot in file
{
    string a="\t\tPILOT'S RECORD NUMBER: ";
	
	ofstream file("Pilot_Records.txt",ios::out|ios::app);//opens in append mode
    
	file<<a<<Count<<endl<<endl;
    file<<"====================================================="<<endl;
    
	a="PILOT'S NAME:  ";
    file<<a<<Name<<endl;
    
	a="PILOT'S NIC:  ";
    file<<a<<NIC<<endl;
    
	a="PILOT'S AGE:  ";
    file<<a<<Age<<endl;
    
	a="PILOT'S ADRESS:  ";
    file<<a<<Adress<<endl;
    
	a="PILOT'S PHONE NUMBER:  ";
    file<<a<<Phone_Num<<endl;
    
    
    a="PILOT'S SALARY:  ";
    file<<a<<Salary<<endl;
    
    a="PILOT'SID:   ";
    file<<a<<Emp_ID<<endl;
    file<<"====================================================="<<endl;
    
    file.close();
}

Pilot& Pilot::operator+=(const double increment)//operator for increasing flight hours of a pilot i.e overtime work
{
	Hours = increment;
	pay_Wage();//calls the salry calculating function
	Hours=0;
}

Pilot& Pilot::operator=(Pilot &obj)//assignment operator of filot for coppying one object to anothe
{
	if(this!=&obj)//if l.h.s!=r.h.s
	{
		Phone_Num=obj.Phone_Num;
		Age=obj.Age;
		Adress=obj.Adress;
		Name=obj.Name;
	    Emp_ID=obj.Emp_ID;
		NIC=obj.NIC;
	    Salary=obj.Salary;
	}
	return *this;//returns reference of pilots object
}

ostream& operator<<(ostream &out,Pilot &obj)//displays on console the object of pilot
{
	string a="\t\tPILOT'S RECORD NUMBER: ";
	static int c=1;
	
	out<<a<<c<<endl<<endl;
	out<<"==============================================="<<endl;
    
	a="PILOT'S NAME:  ";
    out<<a<<obj.Name<<endl;
    
	a="PILOT'S NIC:  ";
    out<<a<<obj.NIC<<endl;
    
	a="PILOT'S AGE:  ";
    out<<a<<obj.Age<<endl;
    
	a="PILOT'S ADRESS:  ";
    out<<a<<obj.Adress<<endl;
    
	a="PILOT'S PHONE NUMBER:  ";
    out<<a<<obj.Phone_Num<<endl;
    
	a="PILOT'S ID:   ";
    out<<a<<obj.Emp_ID<<endl;
    
    a="PILOT'S SALARY:  ";
    out<<a<<obj.Salary<<endl;
    out<<"==============================================="<<endl<<endl<<endl;
    
    c++;
    return out;
}


Staff::Staff()//default onstructor of staff
{   }

Staff::Staff(int empid , string nic) :Employee( nic , empid )//sets nic and employee id
{ 
    Salary=0;
}

void Staff::Constructor_Calling( int empid ,string nic )//calss the constructor
{
	Emp_ID=empid;
	NIC=nic;
}


void Staff::set_static_count()//sets the count of staff objects made an saves it on file
{
	ifstream file("Set_Count_for_staff.txt");
	
	//same logic as mention everywhere
	file.seekg(0,ios::end); 
	if (file.tellg()==0) 
	{
		cout<<"\n\nSet_Count_for_pilot's.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();
	file.seekg(0, ios::beg);

	file>>Count;
	file.close();
}

void Staff::edit_Info()//sets the details of staff members
{
	
	set_static_count();//gets the count of staff from filing
	
	Count++;
	
	ofstream file("Set_Count_for_staff.txt");//increments the count and saves i in file
	file<<Count;
	file.close();
	
	cout<<"STAFF NUMBER :  "<<Count<<endl;
	
	//rest of the data saving
	fflush(stdin);
	cout<<"Enter the Staff Member's name:   ";
	getline(cin,Name);
	
	cout<<"Enter the Staff Member's age:    ";
	  try//Exception handling
       {
   	   cin>>Age;
   	   if(Age==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    } 
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	
	fflush(stdin);
	cout<<"Enter the Staff Member's phone number:    ";
	getline(cin,Phone_Num);
	
	fflush(stdin);
	cout<<"Enter the Staff Member's address:    ";
	getline(cin,Adress);
	
	fflush(stdin);
	cout<<"Enter the Staff Member's designation:    ";
	getline(cin,Designation);
	
}

void Staff::set_Grade(int grade)//sets grade of staff members
{
	Grade=grade;
}

void Staff::pay_Sal()//calculates the salry
{
   Salary = Grade * 11999;	
}

void Staff::display()//displays the object of staff on console
{
	string a="\t\tSTAFF MEMBER'S RECORD NUMBER: ";
	static int c=1;
	
	cout<<a<<c<<endl<<endl;
    cout<<"==============================================="<<endl;
    
	a="STAFF MEMBER'S NAME:  ";
    cout<<a<<Name<<endl;
    
	a="STAFF MEMBER'S NIC:  ";
    cout<<a<<NIC<<endl;
    
	a="STAFF MEMBER'S AGE:  ";
    cout<<a<<Age<<endl;
    
	a="STAFF MEMBER'S ADRESS:  ";
    cout<<a<<Adress<<endl;
    
	a="STAFF MEMBER'S PHONE NUMBER:  ";
    cout<<a<<Phone_Num<<endl;
    
	a="STAFF MEMBER'S ID:   ";
    cout<<a<<Emp_ID<<endl;
    
    a="STAFF MEMBER'S GRADE:  ";
    cout<<a<<Grade<<endl;
    
    a="STAFF MEMBER'S DESIGNATION:  ";
    cout<<a<<Designation<<endl;
	
	a="STAFF MEMBER'S SALARY:  ";
    cout<<a<<Salary<<endl;
    
    cout<<"==============================================="<<endl<<endl<<endl;
    c++;
    
}

void Staff::Salary_writing_in_file()//writes salary record of staff member in file
{
	Date_Time obj;
	
	ofstream file("Salary_Records.txt",ios::out|ios::app);//in append mode
	file<<"====================================================="<<endl;
	file<<"STAFF MEMBER'S ID: "<<Emp_ID<<"\t";
	file<<"SALARY PAID IS: "<<Salary<<"\n"<<"AT DATE AND TIME: ";
	file<<obj<<"\n";
	file<<"====================================================="<<endl;
}

void Staff::write_To_File()//writes record of staff member in file
{
	
	ofstream file("STAFF MEMBER'S_Records.txt",ios::out|ios::app);//append mode
    string a="\t\tSTAFF MEMBER'S RECORD NUMBER: ";
	
	file<<a<<Count<<endl<<endl;
    file<<"==============================================="<<endl;
    
	a="STAFF MEMBER'S NAME:  ";
    file<<a<<Name<<endl;
    
	a="STAFF MEMBER'S NIC:  ";
    file<<a<<NIC<<endl;
    
	a="STAFF MEMBER'S AGE:  ";
    file<<a<<Age<<endl;
    
	a="STAFF MEMBER'S ADRESS:  ";
    file<<a<<Adress<<endl;
    
	a="STAFF MEMBER'S PHONE NUMBER:  ";
    file<<a<<Phone_Num<<endl;
    
    a="STAFF MEMBER'S GRADE:  ";
    file<<a<<Grade<<endl;
    
    a="STAFF MEMBER'S DESIGNATION:  ";
    file<<a<<Designation<<endl;
	
	a="STAFF MEMBER'S SALARY:  ";
    file<<a<<Salary<<endl;
    
    a="STAFF MEMBER'S ID:   ";
    file<<a<<Emp_ID<<endl;
    
    
    file<<"==============================================="<<endl;
    
    file.close();
}


Staff& Staff::operator=(Staff &obj)//assignment operator for staff objects
{
	if(this!=&obj)//if l.h.s!=r.h.s
	{
		Phone_Num=obj.Phone_Num;
		Age=obj.Age;
		Adress=obj.Adress;
		Name=obj.Name;
	    Emp_ID=obj.Emp_ID;
		NIC=obj.NIC;
	    Salary=obj.Salary;
	    Designation=obj.Designation;
	    Grade=obj.Grade;
	}
	return *this;//return objects reference
}

ostream& operator<<(ostream &out,Staff &obj)//displays object on console
{
	string a="\t\tSTAFF MEMBER'S RECORD NUMBER: ";
	static int c=1;//static count
	
	cout<<a<<c<<endl<<endl;
    cout<<"==============================================="<<endl;
    
	a="STAFF MEMBER'S NAME:  ";
    cout<<a<<obj.Name<<endl;
    
	a="STAFF MEMBER'S NIC:  ";
    cout<<a<<obj.NIC<<endl;
    
	a="STAFF MEMBER'S AGE:  ";
    cout<<a<<obj.Age<<endl;
    
	a="STAFF MEMBER'S ADRESS:  ";
    cout<<a<<obj.Adress<<endl;
    
	a="STAFF MEMBER'S PHONE NUMBER:  ";
    cout<<a<<obj.Phone_Num<<endl;
    
	a="STAFF MEMBER'S ID:   ";
    cout<<a<<obj.Emp_ID<<endl;
    
    a="STAFF MEMBER'S GRADE:  ";
    cout<<a<<obj.Grade<<endl;
    
    a="STAFF MEMBER'S DESIGNATION:  ";
    cout<<a<<obj.Designation<<endl;
	
	a="STAFF MEMBER'S SALARY:  ";
    cout<<a<<obj.Salary<<endl;
    
    cout<<"==============================================="<<endl<<endl<<endl;
    c++;
    
}
