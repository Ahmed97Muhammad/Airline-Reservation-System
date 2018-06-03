#ifndef TICKETS_H
#define TICKETS_H

#include"airlineworkers_declaration.h"

class Date_Time //Date and time class for including the system date and time
{

	private:
		int d;//days
		int m;//month
		int y;//year
		int hh;//hours
		int mm;//minutes

	public:
		Date_Time();                            //Sets system date time in date members
		void set_D_T();                              //Asks for custom date time for ticket class used for arrival and departure date/time
		friend ostream& operator << (ostream &out,const Date_Time &obj);//displays time and date on console
};

//class passanger   relationship:Passenger is a person
class Passenger: public Person
{
	protected:
		int Boarding_Pass;//boarding pass i.e coniramtion of ticket
		float Cargo_weight;//weight a single person can carry
    public:
        Passenger();//default onstrutor
    	Passenger(int,string);//sets passanger id and nic
	    void set_Cargo(float);//sets the weight
	    void edit_Info();//all the details of passanger are entered
	    friend ostream& operator << (ostream &out,const Passenger &obj);//dipslays the object of passanger
};

//class ticket    reltionship ticket has airline asset  i.e name and city of airline
class Ticket : public Airline_Asset
{
	protected:
		Date_Time Booking;  //object of date and time used to save booking time
		Date_Time Departure;//object of date and time used to set departure time
		Date_Time Arrival;//object of date and time used to save arrival time
		Passenger Pass;//passanger object for saving its record
		static int Tic_Count;//the number of tickets sold
		int Tic_Num;//sets the ticket number automatically unique identity of ticket
		int Gate;//gate from where one has to go
		int Terminal;//terminal of fight
		string Flight_Num;//flight name
		string Destination;//destination where is the ticket broughten to go for
		double Tic_price;//ticket price
		string route;//the total areas it will cover to reach the destination

	public:
		Ticket();                               //asks for all data member  values
		Ticket(int);              //for refund/ticket cancel purposes
		friend ostream& operator << (ostream &out, const Ticket &obj);//dipslays the object of ticket   
		void write2File();//write data on file
};


//class business    relationship business is a ticket
class Business : public Ticket
{
	private:
		string Movie;//movie name you want to watch
		string Food_Menu;//food menu
		static int flag;//number of business class tickets sold
	public:
       Business();//default constructor
       Business(int);//refund purpose constructor itt calls the ticket constructor
	   void Set_Movie_Fm_Rs();//sets food and movie
	   void write2File();//write business record on file
	   friend ostream& operator << (ostream &out, const Business &obj);//dipslays the object of Businees class
};

#endif
