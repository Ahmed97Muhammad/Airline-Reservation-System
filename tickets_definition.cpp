#include <iostream>
#include"tickets_declaration.h"
#include <ctime>
#include<fstream>
using namespace std;

Date_Time::Date_Time()  //stes the current date and time of the system
{
  time_t currentTime;  //time object
  struct tm *localTime;//temporary saving pointer

  time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );  // Convert the current time to the local time

  d    = localTime->tm_mday;   //saves the day
  m  = localTime->tm_mon + 1;  //saves the month
  y = localTime->tm_year + 1900;//saves the year
  hh = localTime->tm_hour;//saves the hour
   mm    = localTime->tm_min;//saves the month
}

void Date_Time::set_D_T()//sets the time for tickets arrival and departure time entry
{
    cout<<endl<<"Day# ";
      
	  try//Exception handling
       {
   	   cin>>d;
   	   if(d==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    } 
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    while(d<1||d>31)//range of days
    {
        cout<<"Invalid Input\tDay# ";
        try//Exception handling
       {
   	   cin>>d;
   	   if(d==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    } 
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    }
    
    
    cout<<"Month# ";
       try//Exception handling
       {
   	   cin>>m;
   	   if(m==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	} 
    while(m<1||m>=13)//range of month
    {
        cout<<"Invalid Input\tMonth# ";
        try//Exception handling
       {
   	   cin>>m;
   	   if(m==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }   
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    }
    
    
    cout<<"Year# ";
       try//Exception handling
       {
   	   cin>>y;
   	   if(y==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    while(y<1990||y>9999)//range of years
    {
        cout<<"Invalid Input\tYear# ";
        try//Exception handling
       {
   	   cin>>y;
   	   if(y==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    }
    
    
    cout<<"Hour: ";
   	   cin>>hh;
    while(hh<0||hh>23)//range of hours
    {
    	cin>>hh;
    }
    
	cout<<"Minute: ";
	cin>>mm;
    while(mm<0||mm>59)//range of minutes
    {
	cout<<"Invalid Minutes\tMinutes: ";
	cin>>mm;
    }
    
}

ostream& operator << (ostream &out,const Date_Time &obj)//displaying time on console
{
    out<<" "<<obj.hh<<":"<<obj.mm<<"  "<<obj.d<<"/"<<obj.m<<"/"<<obj.y<<" ";
    return out;
}


int Ticket::Tic_Count=0;//static count of tickets

//default constructor
Ticket::Ticket():Airline_Asset("PAKISTAN INTERNATIONAL AIRLINE","KARACHI"),Booking(),Departure(),Arrival(),Pass()
{
	
	ifstream file("Static_Count_for_tickets.txt");//check for static file that it contains a number or not if no ticket has sold then there must be a zero
	file.seekg(0,ios::end); //same old logic
	if (file.tellg()==0) //same old logic if file is empty program will terminate
	{
		cout<<"\n\nStatic_Count_for_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//same old logic
	file.seekg(0, ios::beg);//same old logic
	file>>Tic_Count;//gets the count of tickets
	file.close();
	
    Ticket::Tic_Count++;
	Tic_Num=Ticket::Tic_Count;//assigns it to ticket number
    
	ofstream file1("Static_Count_for_tickets.txt");//writes the ticket number sold in file
	file1<<Tic_Count;
	file1.close();
	
	//taking input from user
	cout<<endl<<"Ticket# "<<Tic_Num;
    cout<<endl<<"Booking Time: "<<Booking;
    
    fflush(stdin);
	cout<<endl<<"Flight# ";
    getline(cin,Flight_Num);
    
	fflush(stdin);
	cout<<"Destination: ";
    getline(cin,Destination);
    
	fflush(stdin);
	cout<<"Route: ";
    getline(cin,route);
    
	cout<<"Gate# ";
    	try//Exception handling
       {
   	   cin>>Gate;
   	   if(Gate==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	
    
	cout<<"Terminal# ";
    	try//Exception handling
       {
   	   cin>>Terminal;
   	   if(Terminal==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	
    //writes the ticket price in a file for ease of generating the final record
    ofstream file123("tickets_price_counter.txt",ios::out|ios::app);
	cout<<"Price: Rs. ";
    	try//Exception handling
       {
   	   cin>>Tic_price;
   	   if(Tic_price==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    file123<<Tic_price<<endl;//file writing 
    
	cout<<"Departure Time:";
    Departure.set_D_T();//manually sets the departure time
    
	cout<<"Arrival Time:";
    Arrival.set_D_T();//manually sets the arrival time

    cout<<"Passenger Details: "<<endl;
    //simple taking inout form user
	int bp;
    cout<<"Boarding Pass: ";
    	try//Exception handling
       {
   	   cin>>bp;
   	   if(bp==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	
	string id;
	fflush(stdin);
    cout<<"NIC: ";
    getline(cin,id);
    
	Passenger temp(bp,id);//temporary object created of passanger
    Pass=temp;//saves it in ticket passangers object

    cout<<endl<<"save?(y/n) ";//saving option
    char c;

    try//Exception handling
    {
     cin>>c;
   	if(c>=65 && c<=90 || c>=97 && c<=122)
	   {    }
    else
	 {
		throw"exception caught of not entering an alphabet";
	}	
    }                 
    catch(const char *sas)
	 {
	cout<<sas<<endl;
   exit(0);
    }
	
	if(c=='y')//if yes saves record on file
    {
        Ticket::write2File();
    }
    cout<<endl;
}

Ticket::Ticket(int n):Airline_Asset("PAKISTAN INTERNATIONAL AIRLINE","KARACHI"),Booking(),Departure(),Arrival(),Pass()//refund ticket
{
	int as;
	ifstream file12("Count_for_refundable_tickets.txt");//again check for count in file of static integer
	file12.seekg(0,ios::end); //same old logic of filing
	if (file12.tellg()==0) //if null error and exit
	{
		cout<<"\n\nStatic_Count_for_refudable_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file12.clear();//same logic
	file12.seekg(0, ios::beg);//same logic
	file12>>as;
	file12.close();
	
	ifstream file("Static_Count_for_tickets.txt");//same case with count of tickets as count for refundable tickets
	file.seekg(0,ios::end); 
	if (file.tellg()==0)//if null arror and exit 
	{
		cout<<"\n\nStatic_Count_for_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();
	file.seekg(0, ios::beg);
	file>>Tic_Count;//takes input
	file.close();
	

	if(n==0 || n<0 || n>Tic_Count)//if n is invalid prints the message else
	{
		cout<<"\a\a\a\a\a\a\a\a";
		cout<<"\n\nERROR NO SUCH TICKET NUMBER EXIST IN OUR FILE!!!!1\n\n";
	}
	
	else
	{
	
	double lil;
	int zx=0;
	ifstream fil("tickets_price_counter.txt",ios::out|ios::app);//opens the ticket price counter matches the ticket number and saves it in Tic_Price
	while(fil)
	{
		zx++;
		fil>>lil;
		if(zx==n)
		{
			Tic_price=lil;
		}
	}
	fil.seekg(0, ios::beg);
	fil.close();
		
	 ofstream file1("tickets_price_counter.txt",ios::out|ios::app);//writes the -ve value in file so that at time of salary calculating it subtracts the price of ticket refunded
     double a=Tic_price+Tic_price;
     double b=Tic_price;
	 b-=a;
	file1<<b<<endl;
	file1.close();
	
		
			as++;
	//increments the count of refundable tickets
	ofstream file122("Count_for_refundable_tickets.txt");
	file122<<as;
	file122.close();
		
			Tic_Num=n;
    
    cout<<endl<<"Refund% ";
    float f;
    cin>>f;//refund percent
    while(f>100||f<0)//range of refund percenr
    {
        cout<<"Invalid Input\tRefund% ";
        cin>>f;
    }
    Tic_price=-1*Tic_price*(f/100);

    cout<<"Ticket# "<<Tic_Num<<endl<<"Refunded amount: Rs. "<<-1*Tic_price;
    cout<<endl<<"save?(y/n) ";
    char c;
    
    try//Exception handling
    {
    cin>>c;
   	if(c>=65 && c<=90 || c>=97 && c<=122)
	{    }
    else
	{
		throw"exception caught of not entering an alphabet";
       }
    }                 
    catch(const char *sas)
	 {
	cout<<sas<<endl;
   exit(0);
   }
    
    if(c=='y')//if yessss saves it in record of tickets file
    {
    	
	ofstream file("Record_of_tickets.txt",ios::out|ios::app);
    
	file<<"===================================\n";
	file<<"\t\tTICKET REFUNDED\n";
	file<<"Ticket# "<<Tic_Num<<endl;
    file<<"Refund%: "<<f<<endl;
    file<<"Refund amount: Rs. "<<-1*Tic_price<<endl;
	file<<"===================================\n";
		
		file.close();
    }		
	}

}

ostream& operator << (ostream &out, const Ticket &obj)//outputs the Tickets obj on console
{
    out<<endl<<"Ticket# "<<obj.Tic_Num;
    out<<endl<<"Booking: "<<obj.Booking;
    out<<endl<<"Departure: "<<obj.Departure;
    out<<endl<<"Arrival "<<obj.Arrival;
    out<<endl<<"Flight# "<<obj.Flight_Num;
    out<<endl<<"Destination: "<<obj.Destination;
    out<<endl<<"Route: "<<obj.route;
    out<<endl<<"Gate# "<<obj.Gate;
    out<<endl<<"Terminal# "<<obj.Terminal;
    out<<endl<<"Passenger Details: ";
    out<<obj.Pass<<endl;
    return out;
}


void Ticket::write2File()//printing record of tickets on file
{
    
	ofstream file("Record_of_tickets.txt",ios::out|ios::app);
	
	file<<"===================================\n";
	file<<"Ticket# "<<Tic_Num;
    file<<endl<<"Booking: "<<Booking;
    file<<endl<<"Departure: "<<Departure;
    file<<endl<<"Arrival "<<Arrival;
    file<<endl<<"Flight# "<<Flight_Num;
    file<<endl<<"Destination: "<<Destination;
    file<<endl<<"Route: "<<route;
    file<<endl<<"Gate# "<<Gate;
    file<<endl<<"Terminal# "<<Terminal;
    file<<endl<<"Passenger Details: ";
    file<<Pass;
    file<<"===================================\n";
    
    file.close();
}

int Business::flag=0;

Business::Business():Ticket()//business constructor calls the ticket constructor for saving tickets ifo
{
	//same old logic as it is been written on ticket
    	ifstream file2("Static_Count_for_business_tickets.txt");
	    file2>>flag;
	    file2.close();
	   	file2.seekg(0,ios::end); 
	if (file2.tellg()==0) ///if null error and exit
	{
		cout<<"\n\nStatic_Count_for_business_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file2.clear();
	file2.seekg(0, ios::beg);
	 
	    flag++;
	     
	
    	ofstream file("Static_Count_for_business_tickets.txt");
	    file<<flag;
	    file.close();
	
	Set_Movie_Fm_Rs();//sets movie and food menu
    char c;
    
    try//exception handling
    {
     cin>>c;
   	if(c>=65 && c<=90 || c>=97 && c<=122)
	   {    }
    else
	 {
		throw"exception caught of not entering an alphabet";
	}	
    }                 
    catch(const char *sas)
	 {
	cout<<sas<<endl;
   exit(0);
  }   
    if(c=='y')//if yes then prints record in file of buiness class ticket
        write2File();
}

void Business::Set_Movie_Fm_Rs()//sets ,ovie name and food menu
{
    cout<<"Movie: ";
    getline(cin,Movie);
    cout<<"Food Menu: ";
    getline(cin,Food_Menu);
}

Business::Business(int n):Ticket(n)//calls the refundable ticket constructor of ticket class
{
      
}

void Business::write2File()//write business record on file
{
	ofstream file("Record_of_Business_class_tickets.txt",ios::out|ios::app);//in append mode

	file<<"===================================\n";
	file<<"Ticket# "<<Tic_Num;
    file<<endl<<"Booking: "<<Booking;
    file<<endl<<"Departure: "<<Departure;
    file<<endl<<"Arrival "<<Arrival;
    file<<endl<<"Flight# "<<Flight_Num;
    file<<endl<<"Destination: "<<Destination;
    file<<endl<<"Route: "<<route;
    file<<endl<<"Gate# "<<Gate;
    file<<endl<<"Terminal# "<<Terminal;
    file<<endl<<"Passenger Details: ";
    file<<Pass<<endl;
    file<<endl<<"Movie: "<<Movie;
    file<<endl<<"Food Menu: "<<Food_Menu;
    file<<"===================================\n";
    
    file.close();
    
}

ostream& operator << (ostream &out, const Business &obj)//display on console
{
    Ticket cast=obj;
    out<<cast;
    out<<endl<<"Movie: "<<obj.Movie;
    out<<endl<<"Food Menu: "<<obj.Food_Menu;
}

Passenger::Passenger() : Person()
{

}


Passenger::Passenger(int n,string nic) : Person(nic)//sets the info of passanger
{
    NIC=nic;
	Boarding_Pass=n;
    float f;
    cout<<"Cargo limit: ";
    cin>>f;
    while(f>50||f<0)//range of cargo limit
    {
        cout<<"Incorrect Input! Value must be between 0 and 50: ";
        cin>>f;
    }
    set_Cargo(f);//set cargo function
    cout<<"Passenger Info:";
    edit_Info();//edit all info
}
//set cargo function
void Passenger::set_Cargo(float f)
{
    Cargo_weight=f;
}
//set info of passanger
void Passenger::edit_Info()
{
    fflush(stdin);
	cout<<endl<<"Name: ";
    getline(cin,Name);

    cout<<"Age: ";
		try//Eception handling
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
    cout<<"Phone#: ";
    getline(cin,Phone_Num);
    
    fflush(stdin);
    cout<<"Adress: ";
    getline(cin,Adress);
}

//display on console passangers objects
ostream& operator << (ostream &out,const Passenger &obj)
{
    out<<endl<<"Name: "<<obj.Name;
    out<<endl<<"NIC: "<<obj.NIC;
    out<<endl<<"Age: "<<obj.Age;
    out<<endl<<"Phone#: "<<obj.Phone_Num;
    out<<endl<<"Adress: "<<obj.Adress;
    out<<endl<<"Boarding Pass: "<<obj.Boarding_Pass;
    out<<endl<<"Cargo Limit: "<<obj.Cargo_weight<<endl;
    return out;
}

