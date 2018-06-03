#ifndef MYLINKLIST_H
#define MYLINKLIST_H

#include<fstream>
#include"airlineworkers_declaration.h"
//my linklist for objects saving in file of both pilots and staff
template<typename t>
class linklist;

template<typename t>
class node
{
	t obj;//object reference
	node<t> *next;//next points to the next object
	public:
		node<t>():next('\0')//default constructor
		{
			
		}
		node<t>(t a):next('\0')//takes temporary object and saves it
		{
			obj=a;
		}
		friend class linklist<t>;
};

template<typename t>
class linklist
{
	node<t> *first;//points to the first object
	node<t> *last;//points to the last object
	public:
		linklist<t>():first('\0'),last('\0')//default constructor
		{
			
		}
		void addatend(t a)//add object
		{
			node<t> *dummy=new node<t>(a);//dummy object created
			if(first=='\0')//if first position contains no object then save it as first
			{
				first=dummy;
				last=first;
			}
			else
			{
				last->next=dummy;//else saves it at last->next and last=last->nest simply makes the last->next object as second last object
				last=dummy;
				last->next='\0';
			}
		}
		void search_by_id(int id)//search record of pilot by its id
		{
			
	    ifstream file;
	    file.open("Pilot_Records.txt");
	    
	    file.seekg(0,ios::end); 
	if (file.tellg()==0) //if pilots records is empty that there is no record the exits the program
	{
		cout<<"\n\nPilot_Records.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();
	file.seekg(0, ios::beg);
	    
		    string a,b,c,d,e,f,g,h,i,j,l,m;
        int k,q=0,as=0; 
        while(file)//else reads the file and if the id matches it prints it on console
	   {
		q++;
	 	getline(file,a);
     	getline(file,b);
     	getline(file,c);
    	getline(file,d);
     	getline(file,e);
		getline(file,f);
		getline(file,g);
		getline(file,h);
		getline(file,i);
		
		file>>j;
		file>>k;
		
		file>>m;
		file>>l;
		
		 if(k==id)
		 {
		 	as++;
		 	if(q>1)
		 	{
		      cout<<"\t"<<l;
	        }
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e;
		cout<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j<<"  "<<k<<endl<<m<<"\n";
        }   
       }
       
       cout<<endl<<endl;
       
	   if(as==0)//if not matches any record then display this message
           {
           	cout<<"\a\a\a\a\\a\a\a\a";
           	cout<<"\nwrong id entered no such employee exist!!!!!\n\n";
		   }
		   
	file.close();
   }
       
       void tforstaff(int id)//search record of staff by its id
       {
	    ifstream file;
	    file.open("STAFF MEMBER'S_Records.txt");
	    
		file.seekg(0,ios::end); 
	if (file.tellg()==0) //if staff records is empty that there is no record the exits the program
	{
		cout<<"\n\nSTAFF MEMBER'S_Records.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();
	file.seekg(0, ios::beg);
		
	     string a,b,c,d,e,f,g,h,i,j,k,l,m,n,p,q;
	     int o,z=0,as=0; 
         while(file)//else reads the file and if the id matches it prints it on console
	    {
		z++;
	 	getline(file,a);
     	getline(file,b);
     	getline(file,c);
    	getline(file,d);
     	getline(file,e);
		getline(file,f);
		getline(file,g);
		getline(file,h);
		getline(file,i);
		getline(file,j);
		getline(file,k);
		
		file>>l;
		file>>m;
		file>>n;
		file>>o;
		
		file>>p;
		file>>q;
		
		if(o==id)
		{
		   as++;
		   if(z>1)
		   {
		   	cout<<"\t"<<q;
		   }
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j;
		cout<<endl<<k<<endl;
		cout<<l<<" "<<m<<" "<<n<<"  "<<o<<"\n"<<p<<"\n";
       }
   }
       
	   cout<<endl<<endl;
       
	   if(as==0)//if not matches any record then display this message
           {
           	cout<<"\a\a\a\a\a\a\a\a";
           	cout<<"\nwrong id entered no such employee exist!!!!!\n\n";
		   }
	file.close();
	   }
       
		void displaypilot()//displays all records present on file
		{
		
		ifstream file;
	    file.open("Pilot_Records.txt");
	    
		file.seekg(0,ios::end); 
	if (file.tellg()==0) //if file is empty the program will terminate displaying the error message
	{
		cout<<"\n\nPilot_Records.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();
	file.seekg(0, ios::beg);
	    string a,b,c,d,e,f,g,h,i,j,l,m;
        int k,q=0,as=0; 
        while(file)//reads the file till eof
	   {
		q++;
	 	getline(file,a);
     	getline(file,b);
     	getline(file,c);
    	getline(file,d);
     	getline(file,e);
		getline(file,f);
		getline(file,g);
		getline(file,h);
		getline(file,i);
		
		file>>j;
		file>>k;
		
		file>>m;
		file>>l;
		
		 	as++;
		 	if(q>1)
		 	{
		      cout<<"\t"<<l;
	        }//printing on console
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e;
		cout<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j<<"  "<<k<<endl<<m<<"\n";    
		  	
		}
	}
		void displayallstaff()
		{
			
			    ifstream file;
	    file.open("STAFF MEMBER'S_Records.txt");
	    
	    file.seekg(0,ios::end); //calculates the total length of file
	if (file.tellg()==0) //if file is empty the program will terminate displaying the error message
	{
		cout<<"\n\nSTAFF MEMBER'S_Records.txt IS EMPTY!!!!!";
		cout<<"\nEXITING THE PROGRAM!!!!\n";
		exit(0); 
	}
	file.clear();//clears the eof error
	file.seekg(0, ios::beg);//points the file pointer to begin
		
	     string a,b,c,d,e,f,g,h,i,j,k,l,m,n,p,q;
	     int o,z=0,as=0; 
         while(file)//reads the file till eof
	    {
		z++;
	 	getline(file,a);
     	getline(file,b);
     	getline(file,c);
    	getline(file,d);
     	getline(file,e);
		getline(file,f);
		getline(file,g);
		getline(file,h);
		getline(file,i);
		getline(file,j);
		getline(file,k);
		
		file>>l;
		file>>m;
		file>>n;
		file>>o;
		
		file>>p;
		file>>q;
		
		   as++;
		   if(z>1)
		   {
		   	cout<<"\t"<<q;
		   }//printing on console
		cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i<<endl<<j;
		cout<<endl<<k<<endl;
		cout<<l<<" "<<m<<" "<<n<<"  "<<o<<"\n"<<p<<"\n";	
			
		}
	}
};

#endif
