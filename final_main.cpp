#include<iostream>
#include"airlineworkersmain.h"
#include"itemsandordersmain.h"
#include"ticketsmain.h"
#include<stdlib.h>
using namespace std;
main()
{
	
	int a;
	cout<<"\t\tWELCOME TO AIRLINE AUDIT SYSTEM!!!!\n\n";
	
	while(a!=4)
	{ 
		system("COLOR 1F");  //changes the console colr	
	cout<<"Enter your choice: \n";
	cout<<"1 For entering audit system's data base \n";
	cout<<"2 For entering ticket system \n";
	cout<<"3 For entering ordering components system \n";
    cout<<"4 For exiting!!!\n\n";
	
	//Exception handling of entering only integer
	  try
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
	
	switch(a)
	{
		case 1:
			{
	         system("cls");
			 AirlineWorkers();//goes to the header file of airlineworkers main
				break;
			}
		case 2:
			{
	         system("cls");
			  tickets_main();//goes to the header file of tickets main
			  break;
			}
		case 3:
			{
	         system("cls");
			 	items_orders_main();//goes to the header file of items and orders main
				 		break;
			}
		case 4:
		     {
		     	cout<<"\n\n\t\tEXITING THE PROGRAM!!!!!\n";
		     	cout<<"\n\tMADE BY:\n";
				cout<<"\t\tMUHAMMAD AHMED\n";
		     	cout<<"\t\tHAMMAD AFTAB\n";
		     	cout<<"\t\tSAMEER UDDIN\n";
		     	cout<<"\t\tABDULLAH BIN AHMED\n";
				 
				 exit(0);
			 }		
        default:
        	{
        		system("cls");
				cout<<"\a\a\a\a\a\a\a\a\a\a";
				cout<<"CHOICES ARE: 1,2,3 and 4 only......\n\n";
				break;
			}
	    }
   }
}
