#ifndef ITEMSANDORDERSMAIN_H
#define ITEMSANDORDERSMAIN_H


#include<iostream>
#include"itemsandorders_dec_def.h"
#include"tickets_declaration.h"
#include<cstdlib>
using namespace std;

void Display_console()//displays all the record store on internal and external order files
{
	int ahmed=0;//flag which checks whether file is empty or not
			ifstream file1b,file1a,file2b,file2a,file3b,file3a,file4b,file4a,file5b,file5a;
		
		//opening all the files in ifstream mode for taking input and displaying
		file1b.open("Storing_internal_records_for_oil_baarrel.txt"); //file of internal order of oil barrels records
		file2b.open("Storing_internal_records_for_engine.txt");//file of internal order of engine reords
		file3b.open("Storing_internal_records_for_led.txt");//file of internal order of leds reords
		file4b.open("Storing_internal_records_for_printer.txt");//file of internal order of printer reords
		file5b.open("Storing_internal_records_for_AC.txt");//file of internal order of AC reords
	    
	    //calculating the files length
	    file1b.seekg(0,ios::end); 
	    file2b.seekg(0,ios::end); 
	    file3b.seekg(0,ios::end); 
	    file4b.seekg(0,ios::end); 
	    file5b.seekg(0,ios::end); 
	
	//opening all the files in ifstream mode for taking input and displaying	
	    file1a.open("Storing_external_order_for_oil_baarrel.txt");//file of external order of oil barrels reords
		file2a.open("Storing_external_order_for_engine.txt");//file of external order of engine reords
		file3a.open("Storing_external_order_for_led.txt");//file of external order of led reords
		file4a.open("Storing_external_order_for_printer.txt");//file of external order of printer reords			
		file5a.open("Storing_external_order_for_AC.txt");//file of external order of AC reords
		
		//calculating the files length
		file1a.seekg(0,ios::end); 
		file2a.seekg(0,ios::end); 
		file3a.seekg(0,ios::end); 
		file4a.seekg(0,ios::end); 
		file5a.seekg(0,ios::end); 
		
			cout<<"\t\tRECORD OF OIL BARRELS!!!\n";
		string a,b,c,d,e,f;
		if(file1a.tellg()!=0)//if file is not empty
		{
				file1a.clear();//removes all eof errors
	file1a.seekg(0, ios::beg);//sets the file pointer to first value
		cout<<"\nEXTERNAL ORDER: \n";	
		while(file1a)//traverses the whole file and takes input  P.S same case goes with the rest of the remaining files!!!!
		{
			ahmed++;
			getline(file1a,a);
			getline(file1a,b);
			getline(file1a,c);
			getline(file1a,d);
			file1a>>e;
			file1a>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
        if(ahmed<=0)//if file is empty then this message is displayed
        {
        	cout<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file1b.tellg()!=0)//if file is not empty
		{
				file1b.clear();//removes all eof errors
	file1b.seekg(0, ios::beg);//sets the file pointer to first value
		cout<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";	
		while(file1b)
		{
			ahmed++;
			getline(file1b,a);
			getline(file1b,b);
			getline(file1b,c);
			getline(file1b,d);
			file1b>>e;
			file1b>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}  
		if(ahmed<=0)//if file is empty then this message is displayed
	    {
	    	cout<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		cout<<"\n\t\tRECORD OF ENGINES!!\n";
		if(file2a.tellg()!=0)//if file is not empty
		{
			file2a.clear();//removes all eof errors
	file2a.seekg(0, ios::beg);//sets the file pointer to first value
		cout<<"\nEXTERNAL ORDER: \n";
			
		while(file2a)
		{
			ahmed++;
			getline(file2a,a);
			getline(file2a,b);
			getline(file2a,c);
			getline(file2a,d);
			file2a>>e;
			file2a>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}	
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file2b.tellg()!=0)//if file is not empty
		{
			file2b.clear();//removes all eof errors
	file2b.seekg(0, ios::beg);//sets the file pointer to first value	
		cout<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file2b)
		{
			ahmed++;
			getline(file2b,a);
			getline(file2b,b);
			getline(file2b,c);
			getline(file2b,d);
			file2b>>e;
			file2b>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		cout<<"\n\t\tRECORD OF LED'S !!\n";
		if(file3a.tellg()!=0)//if file is not empty
		{	
			file3a.clear();//removes all eof errors
	file3a.seekg(0, ios::beg);//sets the file pointer to first value
	    cout<<"\nEXTERNAL ORDER: \n";
			
		while(file3a)
		{
			ahmed++;
			getline(file3a,a);
			getline(file3a,b);
			getline(file3a,c);
			getline(file3a,d);
			file3a>>e;
			file3a>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file3b.tellg()!=0)//if file is not empty
		{
				file3b.clear();//removes all eof errors
	file3b.seekg(0, ios::beg);//sets the file pointer to first value
		cout<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";			
		while(file3b)
		{
			ahmed++;
			getline(file3b,a);
			getline(file3b,b);
			getline(file3b,c);
			getline(file3b,d);
			file3b>>e;
			file3b>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		cout<<"\n\t\tRECORD OF PRINTER!!\n";
	    if(file4a.tellg()!=0)//if file is not empty
	    {	
	    	file4a.clear();//removes all eof errors
	file4a.seekg(0, ios::beg);//sets the file pointer to first value
	    
		cout<<"\nEXTERNAL ORDER: \n";
			
		while(file4a)
		{
			ahmed++;
			getline(file4a,a);
			getline(file4a,b);
			getline(file4a,c);
			getline(file4a,d);
			file4a>>e;
			file4a>>f;
			
		    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file4b.tellg()!=0)//if file is not empty
		{
				file4b.clear();//removes all eof errors
	file4b.seekg(0, ios::beg);//sets the file pointer to first value
			cout<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file4b)
		{
		ahmed++;
			getline(file4b,a);
			getline(file4b,b);
			getline(file4b,c);
			getline(file4b,d);
			file4b>>e;
			file4b>>f;
			
		    cout<<a<<endl<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
	}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		cout<<"\n\t\tRECORD OF AC'S !!\n";
	    if(file5a.tellg()!=0)//if file is not empty
	    {
	    		file5a.clear();//removes all eof errors
	file5a.seekg(0, ios::beg);//sets the file pointer to first value
	    	
	    cout<<"\nEXTERNAL ORDER: \n";
			
		while(file5a)
		{
		ahmed++;
			getline(file5a,a);
			getline(file5a,b);
			getline(file5a,c);
			getline(file5a,d);
			file5a>>e;
			file5a>>f;
			
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//if file is empty then this message is displayed
		{
				cout<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file5b.tellg()!=0)//if file is not empty
		{
				file5b.clear();//removes all eof errors
	file5b.seekg(0, ios::beg);//sets the file pointer to first value
		cout<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file5b)
		{
		ahmed++;
			getline(file5b,a);
			getline(file5b,b);
			getline(file5b,c);
			getline(file5b,d);
			file5b>>e;
			file5b>>f;
			
		   cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}	
		if(ahmed<=0)//if file is empty then this message is displayed
		{
			cout<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		Date_Time obj;   //sets the curent date and time
	 cout<<"\n\tAt date and time:   "<<obj<<endl;
}

//main function for items and order system

void items_orders_main()
{
		system("color b3");
	int choice;
	while(choice!=5)
	{
	system("cls");
	cout<<"\t\tWELCOME TO AIRLINE'S ORDERING SYSTEM!!!!\n\n";
	cout<<"Enter your choice: \n";
	cout<<"1 For entering the system of taking order from external sources \n";
	cout<<"2 For entering the system of supplying order to the airline \n";
    cout<<"3 For generating final records on file \n";
	cout<<"4 For displaying final records on cosole\n";
	cout<<"5 Going back to selection of airline audit system's\n";
    
	  try//Exception handling
       {
   	   cin>>choice;
   	   if(choice==0)
   	   {
   	   	throw"Exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
    
	
	
	switch(choice)
    {
    	case 1:
    		{
    			system("cls");
    			Order obj;
                obj.ext_order(); //takes external order i.e from external sources
                break;
			}
		case 2:
		    {
		    	system("cls");
	           Order obj;
               obj.Int_Order(); //supplies stock to the airline in terms of fifo
               break;
			}
		case 3:
		   {
			system("cls");
			Order obj;
			obj.final_file(); //generates the final report
			cout<<"\n\tSUCESSFULLY GENERATED!!!!!\n";
			system("pause");
			break;
			}	
        case 4:
        	{
        		system("cls");
            Display_console();//displays the final report on console
			system("pause");
			break;	
			}
		case 5:
		    {
			    system("cls");//takes back to final main file
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

