#ifndef TICKETSMAIN_H
#define TICKETSMAIN_H

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
#include"tickets_declaration.h"


void ticket_report() //dipllays the final record of tickets on console
{
		ofstream final("final_record_of_tickets.txt");

    int count=0,flag=0,as=0,a=0;  //counts of files
	double sum=0;//claculating the sum of all the tickets sold and refunded
    
	ifstream file("Static_Count_for_tickets.txt");  //if there is no ticket sold then error message would be displayed and prograam will exit
	file.seekg(0,ios::end); //calculates the total length of file
	if (file.tellg()==0) //checking file is null or not
	{
		cout<<"\n\nStatic_Count_for_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//clears the eof file error
	file.seekg(0, ios::beg);//points the file pointe to begining
	file>>count;
	file.close();
	
	final<<"===================================\n";
	final<<"Total number of tickets sold are: "<<count<<endl;

    ifstream file2("Static_Count_for_business_tickets.txt");
	file2.seekg(0,ios::end); //same logic as previously mention
	if (file2.tellg()==0) //these are the check so that file must not be empty and if no ticket has sold then there should be zero
	{                     //just to justify that no ticket has stolen
		cout<<"\n\nStatic_Count_for_business_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file2.clear();//same logic as previously mention
	file2.seekg(0, ios::beg);//same logic as previously mention
	file2>>flag;
	file2.close();
	 
	final<<"Business class Tickets are: "<<flag<<endl; //business class tickets from file
    final<<"Economy class Tickets are: "<<count-flag<<endl;//economy class tickets by subtracting business tickets form total tickets
    
	ifstream file12("Count_for_refundable_tickets.txt");
	file12.seekg(0,ios::end); //same logic as previously mention
	if (file12.tellg()==0) //same logic as previously mention
	{
		cout<<"\n\nCount_for_refundable_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file12.clear();//same logic as previously mention
	file12.seekg(0, ios::beg);//same logic as previously mention
	file12>>as;
	file12.close();
	
	final<<"number of tickets refunded are: "<<as<<endl;
	 
	 
	 ifstream file1("tickets_price_counter.txt",ios::out|ios::app);
      	file1.seekg(0,ios::end); //same logic as previously mention
	if (file1.tellg()==0) //same logic as previously mention
	{
		cout<<"\n\ntickets_price_counter.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file1.clear();//same logic as previously mention
	file1.seekg(0, ios::beg);//same logic as previously mention
	
	double asd;
	vector<double> v;//vector class used for saving the prices of tickets from tickets price counter file
	  while(file1)
      {
	     file1>>asd;
	     v.push_back(asd);
	  }
	file1.close();
	
	for(int i=0;i<v.size()-1;i++)//calculates the whole sum
	{
		sum+=v[i];
	}
	
	 final<<"After total ticket sold and refunded the amount is: "<<sum<<endl;//prints the total sum
	 Date_Time obj;//gets the system date and time
	 final<<"\tAt date and time:  "<<obj<<endl;
	 final<<"===========================================\n";
	 
	 final.close();
}

void Display_Console()//displays on console
{
	ifstream file("final_record_of_tickets.txt");//checks if the final record is present or not
	file.seekg(0,ios::end); 
	if (file.tellg()==0)// if not program wiil terminate
	{
		cout<<"\n\nfinal_record_of_tickets.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//same logic as previously mention
	file.seekg(0, ios::beg);//same logic as previously mention
	string a,b,c,d,e,f,g,h;
	
	getline(file,a);
	getline(file,b);
	getline(file,c);
	getline(file,d);
	getline(file,e);		//taking input from file in form of strings
	getline(file,f);
	getline(file,g);
	getline(file,h);
	                        //displaying the records form file on console
	cout<<"\n\tTICKETS REPORT!!!!\n\n";
	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl;
	
	file.close();
}



void tickets_main()//main definition for tickets
{
	    cout<<endl<<endl<<endl;
    system("COLOR 8F");//changes the system color
    
    int a;
    while(a!=5)
    {
    	system("cls");
    cout<<"TICKET SALES MENU";
    cout<<endl<<endl;

    cout<<"Enter the corresponding digit for the required task:\n";

    cout<<"1)\tEnter a new ticket record";
    cout<<endl<<"2)\tRefund a ticket";
    cout<<endl<<"3)\tGenerate ticket sales report"<<endl;
    cout<<"4)\tDipslaying ticket sales report on console\n";
    cout<<"5)\tGoing back to selection of airline audit system's\n";
    	
    	try//Exception hanling
       {
   	   cin>>a;
   	   if(a==0)
   	   {
   	   	throw"Exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
	cout<<endl;
    	
    switch(a)
    {
        case 1:
        	{
        		system("cls");
            char c;
            cout<<"Business or Economy(b/e): ";  //choice of tickets
            cin>>c;
            while(c!='e'&& c!='E'&& c!='b'&& c!='B')
            {
                cout<<"Invalid Input!\tReenter Selection: ";
                cin>>c;
            }
            if(c=='e'|| c=='E')//mades object for economy ticket
            {
                Ticket t;
            }
            else if(c=='b'||c=='B')//mades object for business ticket
            {
                Business t;
            }
            break;

			}
        case 2:
            {
            	system("cls");
            int n;
            cout<<"Enter Ticket#: ";//refunding the ticket with respect to ticket number
           
		    try//exception handling
           {
   	         cin>>n;
   	         if(n==0)
   	       {
   	   	     throw"Exception caught of not entering an integer";
		   }	
          }
	       catch(const char *s)
	      {
		    cout<<s<<endl;
		    exit(0);
	       }
		
			Ticket t(n);//calls the constructor for refunding the ticket
            system("pause");
            break;	
			}

        case 3:
        	{
        		system("cls");
            cout<<"Generating Report...."<<endl;
			ticket_report();//generates final retprt on txt file
            system("pause");
			break;	
			}
        case 4:
        	{
        		system("cls");
            Display_Console();//opens the final record file and displays it on the console
			system("pause");
			break;	
			}
		case 5:
		    {
			    system("cls");
			    cout<<"\nGoing back to selection of airline audit system's !!!!\n\n";
			    break;
			}			
		default:
		   {
		   	    system("cls");
				cout<<"\a\a\a\a\a\a\a\a\a\a";
				cout<<"CHOICES ARE: 1,2,3,4 and 5 only......\n\n";
				break;
			}		
    }   
	} 
}

#endif
