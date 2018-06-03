#ifndef AIRLINEWORKERSMAIN_H
#define AIRLINEWORKERSMAIN_H
#include<stdlib.h>
#include<iostream>
#include"mylinklist.h"
using namespace std;

void Display_on_Console()//displays the final recors of salary on consoe from file
{
	ifstream file("Salary_Records.txt");
	file.seekg(0,ios::end); //calculates the length of file
	if (file.tellg()==0) //if file is null then error would be displayed and program will terminate
	{
		cout<<"\n\nSalary_Records.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//clears the eof errors
	file.seekg(0, ios::beg);
	
	while(file)//traverse the file and displays it in console
	{
		string a,b,c,d;
		getline(file,a);
		getline(file,b);
		getline(file,c);
		getline(file,d);
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;			
	}
	file.close();
}


int AirlineWorkers()
{		
	system("COLOR 3B");
	linklist<Pilot> Pilot_List;//linklist for pilots objecs saving on file
    linklist<Staff> Staff_List;//linklist for staff objecs saving on file
	int a,choice;
	
	while(choice!=3)//selection of going to which database
	{
	
	system("cls");
	
	cout<<"\t\tWELCOME TO DATA BASE OF AIRLINE AUDIT SYSTEM: \n\n";
	cout<<"Enter your choice: \n";
	cout<<"1 For entering a PILOT's' data system \n";
	cout<<"2 For entering a STAFF MEMBER's' data system \n";
	cout<<"3 Going back to selection of airline audit system's\n";
	
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
	
	cout<<"\n\n";
	
	switch(choice)//selection of going to internal systems of piot or staffs dta base
	{
		case 1:
			{
			system("cls");
			cout<<"\t\tPILOT'S DATA BASE: \n\n\n";
	while(a!=5)
	{
		cout<<"enter your choice: \n";
		cout<<"1 For entering a pilot's data \n";
		cout<<"2 For displaying all pilot's record \n";
		cout<<"3 For searching a particular PILOT's record by his employee id \n";
		cout<<"4 for displaying salary records on console \n";
		cout<<"5 For going back to selection of choice between Pilot and Staff members.....\n";
		
		   try//Exception handling
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
			
		cout<<"\n\n";
		switch(a)
		{
			
			case 1:
				{//creates a pilot object gathers all the information place it in to the file with the help of link list
					system("cls");
					Pilot obj;
					string b;   int c,d;
   	  
   	                obj.edit_Info();//gets all the info
   	  
	                cout<<"Enter Pilot's NIC no:   ";
   	                getline(cin,b);
   	                
					cout<<"Enter Pilot's ID:   ";
   	                try//Exceptiion handing
                    {
   	               cin>>c;
   	                  if(c==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
	            
   	                cout<<"Enter Pilot's flight hours:   ";
   	                 try//Exceptiion handing
                    {
   	               cin>>d;
   	                  if(d==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		          exit(0);
	            }
   	  
   	               cout<<endl<<endl;
   	  
                   obj.Constructor_Calling(c,b);//sets nic
   	               obj.set_Hrs(d);//set hiurs
   	  
                   obj.set_Hrs_wage();
                   obj.pay_Wage();//calculates salry of the pilot
                   
                   char f;
                   cout<<"Do you want to increment the flight hours of the pilot (y or Y) ?? ";
                    
					try//Exceptiion handing
                    {
   	                cin>>f;
   	                
					if(f>=65 && f<=90 || f>=97 && f<=122)
	                  {    }
	                 else
	                {
	               	throw"Exception caught of not entering an alphabet";
				   }	
                }                 
                 	catch(const char *sas)
	              {
		           cout<<sas<<endl;
		           exit(0);
		            }
                   //increments the flight hours of a piot i.e overtime work of a pilot
				   if(f=='y'||f=='Y')
                   {
                   	
					int j;
                   	cout<<"\nEnter the number of hours you want to increment: ";
                   	
                   	 try
                    {
   	               cin>>j;
   	                  if(j==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
                   	
					obj+=j;
					
				   }
				   
                   obj.Salary_writing_in_file();//saves only emplyee id and sary of each employee
                   obj.write_To_File();	//saves the whole record on file
                   
				   Pilot_List.addatend(obj);//linklist used to add objects
				   
				   cout<<endl<<endl;
				   system("cls");
					
					break;
				}
				
			case 2:
			    {
			    	system("cls");
			    	cout<<endl;
			    	
			    	cout<<"\t\tDISPLAYING ALL PILOT'S RECORDS!!!!1\n\n";
					
					Pilot_List.displaypilot();//traverses the whole file of pilot's recors
			    	
			    	cout<<endl<<endl;
					system("pause");
					break;
				}
			case 3:
			    {//searching pilot b its employee id
			    	system("cls");
			    	int id;
			    	cout<<"\nEnter the PILOT's id you want to search: \n";
			    	
					 try//Exceptiion handing
                    {
   	               cin>>id;
   	                  if(id==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
					
					Pilot_List.search_by_id(id);//search the employee by its id and displays on console
			    	system("pause");
					break;
					}
			case 4:
			    {
				  system("cls");
				  cout<<"\n\t\tDISPLAYING SALARY RECORDS: \n\n";
				  Display_on_Console();//displays salry recors on console
				  system("pause");
				  break;
				}			
			case 5:
			    {
			    	system("cls");
			    	cout<<"\nGoing back to selection of choice b/w pilot and staff member!!!!\n\n";
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
	     break;
     }
         case 2:
         	{
         		system("cls");
         	int s;
			cout<<"\t\tSTAFF MEMBER's' DATA BASE: \n\n\n";
	     while(s!=5)
	   {
		cout<<"enter your choice: \n";
		cout<<"1 For entering a STAFF MEMBER's' data \n";
		cout<<"2 For displaying all STAFF MEMBER's' record \n";
		cout<<"3 For searching a particular STAFF MEMBERS record by his employee id \n";
		cout<<"4 For displaying Salary Records....\n";
		cout<<"5 For going back to selection of choice between Pilot and Staff members.....\n";
				
		   try//Exceptiion handing
       {
   	       cin>>s;
   	   if(s==0)
   	   {
   	   	throw"Exception caught of not entering an integer";
		  }
    } 
	catch(const char *d)
	{
		cout<<d<<endl;
		exit(0);
	}
		
		cout<<"\n\n";
		switch(s)
		{
			
			case 1://creates a staff object gathers all the information place it in to the file with the help of link list
				{
					system("cls");
					Staff obj;
					string b,d;   int c,g;
   	  
   	                obj.edit_Info();//sts all the info
   	  
	                cout<<"Enter STAFF MEMBER's' NIC no:   ";
   	                getline(cin,b);
   	                
					cout<<"Enter STAFF MEMBER's' ID:   ";
   	                 try//Exceptiion handing
                    {
   	               cin>>c;
   	                  if(c==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
   	                
					cout<<"Enter STAFF MEMBER's' GRADE:   ";
   	                 try//Exceptiion handing
                    {
   	               cin>>g;
   	                  if(g==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
   	                
   	                
   	               cout<<endl<<endl;
   	  
                   obj.Constructor_Calling(c,b);//stes ic and empid
                   obj.set_Grade(g);//sets grade
                   
                   obj.pay_Sal();//calculates salry on the basis of grades
                   obj.Salary_writing_in_file();//writes salary on file
                   
                   obj.write_To_File();	//writes the whole data of staff objects on file
				   Staff_List.addatend(obj);//adds object to file using linklist
				   
				   cout<<endl<<endl;
				   system("cls");
					
					break;
				}
				
			case 2:
			    {
			    	system("cls");
			    	cout<<endl;
			    	
			    	cout<<"\t\tDISPLAYING ALL STAFF MEMBER'S RECORDS!!!!1\n\n";
					
					Staff_List.displayallstaff();//displays all the staff details on file
			    	
			      cout<<endl<<endl;
					system("pause");
			    	break;
				}
			
			case 3:
			    {
			    	system("cls");
					
					int id;
			    	cout<<"\nEnter the STAFF MEMBERS id you want to search: \n";
			    	
					 try//Exceptiion handing
                    {
   	               cin>>id;
   	                  if(id==0)
   	                 {
   	   	          throw"Exception caught of not entering an integer";
		            }	
               } 
	           catch(const char *s)
	          {
		          cout<<s<<endl;
		         exit(0);
	            }
			    		
					Staff_List.tforstaff(id);//search foe stagg members employee id
			    	system("pause");
					break;
					}
			case 4:
			    {
				  system("cls");
				  cout<<"\n\t\tDISPLAYING SALARY RECORDS: \n\n";
				  Display_on_Console();//displays salary recors on console
				  system("pause");
				  break;
				}							
			case 5:
			    {
			    	system("cls");
			    	cout<<"\nGoing back to selection of choice b/w pilot and staff member!!!!\n\n";
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
	    break;
	 }
	 case 3:
	 	{
			    system("cls");
			    cout<<"\nGoing back to selection of airline audit system's !!!!\n\n";
			    break;
		 }
		default:
		{
			system("cls");
				cout<<"\a\a\a\a\a\a\a\a\a\a";
				cout<<"CHOICES ARE: 1,2 and 3 only......\n\n";
				break;
		 } 
   }	 
}
}

#endif
