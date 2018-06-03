#ifndef ITEMSANDORDERS_DEC_DEF_H
#define ITEMSANDORDERS_DEC_DEF_H

#include<iostream>
#include<fstream>
#include<vector>
#include"tickets_declaration.h"
using namespace std;
class Item//item class
{
	protected:
		  int Prod_Code;//item code
		string Item_Name;                       // oil barrels , engine, leds, printer, AC.

	public:
		
		Item()//default construtor
		{
			
		}
		
		void display()//display on console
		{
			cout<<"\t\tPRODUCT CODES LIST!!!!";
			cout<<"\n\n1 for Oil Barrel\n";
			cout<<"2 for Engine\n";
			cout<<"3 for Led\n";
			cout<<"4 for Printer\n";
			cout<<"5 for AC\n\n";		
		}
		
		void set_code()                 //Sets Prod_Code and uses it to set Item_Name and unit
		{
			
		int a=0;
			
		while(a<1)
		{
	try//Exception handling
    {
   	   cin>>Prod_Code;
   	   if(Prod_Code==0)
   	    {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
			//selection of product code
		switch (Prod_Code)
	   {
			
		case 1:
		{
			Item_Name = "oil barrel";
			cout<<"\nyou have selected: "<<Item_Name<<endl<<endl;
			a++;
			break;
		}
		case 2:
		{
			Item_Name = "Engine";
			cout<<"\nyou have selected: "<<Item_Name<<endl<<endl;
				a++;
			break;
		}
		case 3:
		{
		    Item_Name = "LEDs";
		    cout<<"\nyou have selected: "<<Item_Name<<endl<<endl;
		    	a++;
		    break;
 		}
		case 4:
		{
			Item_Name = " Printers";
			cout<<"\nyou have selected: "<<Item_Name<<endl<<endl;
				a++;
			break;
		}
		case 5:
		{
			Item_Name = "ACs";
			cout<<"\nyou have selected: "<<Item_Name<<endl<<endl;
				a++;
			break;
		}
		default:
		{
			cout<<"Error input right product code!!!!"<<endl;
			break;
		}
		
      }
   }
}
	int get_code()//return product code
	{
		return Prod_Code;
	}
	
};



//class order 
class Order
{
	private:
	    Item it; //relationship order has item 
	    string supplier;//supplier info
		int Qty;//quantity
		double Price;//price of item
		long double total_Cost; //total cost

	public:
		
		Order()//default constructor
		{
			Qty=0;
		}
		
		void ext_order()    //Sends int to Item, sets order_num and increments order_count
		{
			cout<<"TAKING ORDER FROM EXTERNAL SOURCES!!!!!!\n\n";
			
		    	it.display();//displays menu of items list
		    
			cout<<"Enter the product code you are supplying to us  ";
		    it.set_code();	//gets the product code through items function
			
			cout<<"Enter the whole Quantity of the order  ";
		   try//Exception handling
       {
   	   cin>>Qty;
   	   if(Qty==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}	
			
			cout<<"Enter Total price of the order  ";
		try//Exception handling
       {
   	   cin>>total_Cost;
   	   if(total_Cost==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}
			
			
			Price=total_Cost/Qty;
			//writing in particular file for the order you have selected
			switch(it.get_code())
			{
				
			case 1:
			{
					//for writing of external order of oil barrel
			ofstream file("Storing_external_order_for_oil_baarrel.txt",ios::out|ios::app);
			file<<"===================================="<<endl;
			file<<"total price: "<<total_Cost<<endl;
			file<<"PerPrice: "<<Price<<endl;
			file<<"QuantityIs: "<<Qty<<endl;
			file<<"===================================="<<endl;
			file.close();
			
			break;
			} 	
			
			case 2:
			{
					//for writing of external order of engine
			ofstream file("Storing_external_order_for_engine.txt",ios::out|ios::app);
			file<<"===================================="<<endl;
			file<<"total price: "<<total_Cost<<endl;
			file<<"PerPrice: "<<Price<<endl;
			file<<"QuantityIs: "<<Qty<<endl;
			file<<"===================================="<<endl;
			file.close();
			
			break;
			}
			
			case 3:
			{
						//for writing of external order of led
			ofstream file("Storing_external_order_for_led.txt",ios::out|ios::app);
			file<<"===================================="<<endl;
			file<<"total price: "<<total_Cost<<endl;
			file<<"PerPrice: "<<Price<<endl;
			file<<"QuantityIs: "<<Qty<<endl;
			file<<"===================================="<<endl;
			file.close();
			
			break;
			}
			
			case 4:
			{
						//for writing of external order of printer
			ofstream file("Storing_external_order_for_printer.txt",ios::out|ios::app);
			file<<"===================================="<<endl;
			file<<"total price: "<<total_Cost<<endl;
			file<<"PerPrice: "<<Price<<endl;
			file<<"QuantityIs: "<<Qty<<endl;
			file<<"===================================="<<endl;
			file.close();
			
			break;
			}
			
			case 5:
			{
						//for writing of external order of AC
			ofstream file("Storing_external_order_for_AC.txt",ios::out|ios::app);
			file<<"===================================="<<endl;
			file<<"total price: "<<total_Cost<<endl;
		    file<<"PerPrice: "<<Price<<endl;
			file<<"QuantityIs: "<<Qty<<endl;
			file<<"===================================="<<endl;
			file.close();
			
			break;
			}
			
			}
		}
		
		
	  void Int_Order()//mow the internal order taking and supplying to tha airline with the logic fifo
		{
			cout<<"\nDELIVERING PRODUCTS TO THE AIRLINE's INTERNAL DEPARTMENT!!!!!\n\n";	
			it.display();//displays the reoducts menu
			
			cout<<"Enter the product code you want fom our inventory!!!!  ";
		    it.set_code();	//product code selection
			
			cout<<"Enter the whole Quantity of the order  ";
		   try//Exception handling
       {
   	   cin>>Qty;
   	   if(Qty==0)
   	   {
   	   	throw"exception caught of not entering an integer";
		}	
    }
	catch(const char *s)
	{
		cout<<s<<endl;
		exit(0);
	}	
			
			int re=0;
			ifstream file;
			ifstream file_for_console;
			ofstream final_file;
			
			//logic is the code you have selected that type of file is open and that particular external order file is selected for writing order
			switch(it.get_code())
			{
				
			case 1:
			{
			file.open("Storing_external_order_for_oil_baarrel.txt");
			file.seekg(0,ios::end); //points the file pointe to begining
	         if (file.tellg()==0) ///if null then exit
	        {
		      cout<<"\n\nStoring_external_order_for_oil_baarrel.txt IS EMPTY!!!!!";
		      cout<<"\nEXITING THE PROGRAM!!!!\n";
		     exit(0); 
	    }
	file.clear();//clear the eof file error
	file.seekg(0, ios::beg);//points the file pointer to begin
	
			final_file.open("Storing_internal_records_for_oil_baarrel.txt",ios::out|ios::app);
			re=1;
			break;
			} 	
			
			case 2:
			{//same old logic
			file.open("Storing_external_order_for_engine.txt");
			
			file.seekg(0,ios::end); 
	         if (file.tellg()==0) 
	        {
		      cout<<"\n\nStoring_external_order_for_engine.txt IS EMPTY!!!!!";
		      cout<<"\nEXITING THE PROGRAM!!!!\n";
		     exit(0); 
	    }
	file.clear();
	file.seekg(0, ios::beg);
	
	
			final_file.open("Storing_internal_records_for_engine.txt",ios::out|ios::app);	
			re=2;
			break;
			}
			//same old logic
			case 3:
			{		
			file.open("Storing_external_order_for_led.txt");
			
			file.seekg(0,ios::end); 
	         if (file.tellg()==0) 
	        {
		      cout<<"\n\nStoring_external_order_for_led.txt IS EMPTY!!!!!";
		      cout<<"\nEXITING THE PROGRAM!!!!\n";
		     exit(0); 
	    }
	file.clear();
	file.seekg(0, ios::beg);
			
			final_file.open("Storing_internal_records_for_led.txt",ios::out|ios::app);
			re=3;
			break;
			}
			//same old logic
			case 4:
			{		
			file.open("Storing_external_order_for_printer.txt");
			
			file.seekg(0,ios::end); 
	         if (file.tellg()==0) 
	        {
		      cout<<"\n\nStoring_external_order_for_printer.txt IS EMPTY!!!!!";
		      cout<<"\nEXITING THE PROGRAM!!!!\n";
		     exit(0); 
	    }
	file.clear();
	file.seekg(0, ios::beg);
			
			final_file.open("Storing_internal_records_for_printer.txt",ios::out|ios::app);
			re=4;
			break;
			}
			//same old logic
			case 5:
			{		
			file.open("Storing_external_order_for_AC.txt");
			
			file.seekg(0,ios::end); 
	         if (file.tellg()==0) 
	        {
		      cout<<"\n\nStoring_external_order_for_AC.txt IS EMPTY!!!!!";
		      cout<<"\nEXITING THE PROGRAM!!!!\n";
		     exit(0); 
	    }
	file.clear();
	file.seekg(0, ios::beg);
			
			final_file.open("Storing_internal_records_for_AC.txt",ios::out|ios::app);
			re=5;
			break;
			}
		}//after the file is selected now comes the time of reducing the quantity of external order and supplying to internal in the concept of fifo
		
			float perprice,pp=0;
			int quantity,qty;
			string a,b,c,d,e,f;
			vector<string> va,vb,vc,vd,ve,vf;
			vector<int> vquantity;
			vector<float> vperprice;
	
			float cost=0;
			int count=0,ahmed=0;
		    int sam=0;
			qty=Qty;
		  
			//reading from file and saving in vector reason would be tell on monday
		  while(file)
			{
			getline(file,a);
			getline(file,b);
			
			file>>c;
			file>>perprice;
			
			file>>d;
			file>>quantity;
		
			file>>e;
		    file>>f;
		    
		    va.push_back(a);
		    vb.push_back(b);
		    vc.push_back(c);
		    vperprice.push_back(perprice);
		    vd.push_back(d);
		    vquantity.push_back(quantity);
		    ve.push_back(e);
		    vf.push_back(f);
		    ahmed++;
	   }  
	    
	    for(int i=0;i<vquantity.size();i++)
	    {
	    	sam+=vquantity[i];
		}
	  
		//checks that we have that amount of quamtity or not
		
		if(sam<Qty)
		{
			cout<<"\a\a\a\a\a\a\a\a\a\a\n";
			cout<<"we donot have that much order in our stock!!!!!\n";
			system("pause");
		}
		else
		{
			file.clear();//same old logic
	file.seekg(0, ios::beg);//same old logic	
	      count=0;
		  //writing in specefic file of internal order selected
		  while(file)
			{
			count++;
			getline(file,a);
			getline(file,b);
			
			file>>c;
			file>>perprice;
			
			file>>d;
			file>>quantity;
		
			file>>e;
		    file>>f;
		    if(quantity>qty)
		    {
		    	cost=cost+qty*perprice;
			final_file<<"===================================="<<endl;
		    final_file<<"Quantity given: "<<Qty<<endl;
			final_file<<"Each item cost: "<<perprice<<endl;
			final_file<<"Total cost: "<<cost<<endl;
			final_file<<"===================================="<<endl;
			final_file.close();
			break;
			}
			
		    if(quantity==qty)
		    {
		    	cost=cost+qty*perprice;
		    final_file<<"===================================="<<endl;
		    final_file<<"Quantity given: "<<Qty<<endl;
			final_file<<"Each item cost: "<<perprice<<endl;
			final_file<<"Total cost: "<<cost<<endl;
			final_file<<"===================================="<<endl;
			final_file.close();
			break;
		    }
			
			if(quantity<qty)
			{
				qty-=quantity;
				cost+=perprice*quantity;
			}

			}
		file.close();	
		
		//doing the fifo logic first taking quantity then over writing it using vectors
	    ofstream file_overwrite;
				
		if(re==1)
		{
			file_for_console.open("Storing_internal_records_for_oil_baarrel.txt");
			file_overwrite.open("Storing_external_order_for_oil_baarrel.txt");
		}
		if(re==2)
		{
			file_for_console.open("Storing_internal_records_for_engine.txt");
			file_overwrite.open("Storing_external_order_for_engine.txt");
		}
		if(re==3)
		{
			file_for_console.open("Storing_internal_records_for_led.txt");
			file_overwrite.open("Storing_external_order_for_led.txt");
		}
		if(re==4)
		{
			file_for_console.open("Storing_internal_records_for_printer.txt");
		    file_overwrite.open("Storing_external_order_for_printer.txt");
		}
		if(re==5)
		{
			file_for_console.open("Storing_internal_records_for_AC.txt");
		    file_overwrite.open("Storing_external_order_for_AC.txt");
		}
	     
	     int ahm=0,asdfg=0;
	    for(int i=0;i<va.size();i++)
		{
			ahm++;
			if(ahm<=count)
			{
				asdfg=vquantity[i]-Qty;
				Qty-=vquantity[i];
				if(asdfg<=0)
				{
					asdfg=0;
				}
		       file_overwrite<<va[i]<<endl<<vb[i]<<endl<<vc[i]<<" "<<vperprice[i]<<endl<<vd[i]<<" "<<asdfg<<endl<<ve[i]<<endl;
			   asdfg=1;				
			}
			else
			{
				file_overwrite<<va[i]<<endl<<vb[i]<<endl<<vc[i]<<" "<<vperprice[i]<<endl<<vd[i]<<" "<<vquantity[i]<<endl<<ve[i]<<endl;
			}
			
		if(i!=va.size()-1)
		{
			file_overwrite<<vf[i];
		}
        
		}
	     file_overwrite.close();
	     
	     
		int cons=0;
		
		cout<<"\nDISPLAYING ALL ORDERS GIVEN FROM INVENTORY!!!\n\n";
		
		  while(file_for_console)
			{
				cons++;
				
			getline(file_for_console,a);
			getline(file_for_console,b);
			getline(file_for_console,c);
			getline(file_for_console,d);
			file_for_console>>e;
			file_for_console>>f;
			
		    cout<<a<<endl<<"ORDER NO: "<<cons<<endl;
		    cout<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		    
	}
	     file_for_console.close();
	     
	     system("pause");   
			  }	  
		
	}
	
	void final_file()//generating final report of items and orders
	{
		
		ifstream file1b,file1a,file2b,file2a,file3b,file3a,file4b,file4a,file5b,file5a;
		ofstream final_file;
		
		final_file.open("final_records_for_items_and_orders.txt");
		
		file1b.open("Storing_internal_records_for_oil_baarrel.txt");
		file2b.open("Storing_internal_records_for_engine.txt");
		file3b.open("Storing_internal_records_for_led.txt");
		file4b.open("Storing_internal_records_for_printer.txt");
		file5b.open("Storing_internal_records_for_AC.txt");
	    //same old logic
	    file1b.seekg(0,ios::end); 
	    file2b.seekg(0,ios::end); 
	    file3b.seekg(0,ios::end); 
	    file4b.seekg(0,ios::end); 
	    file5b.seekg(0,ios::end); 
	
	    file1a.open("Storing_external_order_for_oil_baarrel.txt");
		file2a.open("Storing_external_order_for_engine.txt");
		file3a.open("Storing_external_order_for_led.txt");
		file4a.open("Storing_external_order_for_printer.txt");			
		file5a.open("Storing_external_order_for_AC.txt");
		//same old logic
		file1a.seekg(0,ios::end); 
		file2a.seekg(0,ios::end); 
		file3a.seekg(0,ios::end); 
		file4a.seekg(0,ios::end); 
		file5a.seekg(0,ios::end); 
		
			
		string a,b,c,d,e,f;
		int ahmed=0;
		final_file<<"\t\tRECORD OF OIL BARRELS!!!\n";
		if(file1a.tellg()!=0)//same old logic
		{
				file1a.clear();//same old logic
	file1a.seekg(0, ios::beg);//same old logic
		final_file<<"\nEXTERNAL ORDER: \n";	
		while(file1a)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file1a,a);
			getline(file1a,b);
			getline(file1a,c);
			getline(file1a,d);
			file1a>>e;
			file1a>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
        if(ahmed<=0)//else if file is empty print this
        {
        	final_file<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file1b.tellg()!=0)//same old logic
		{
				file1b.clear();//same old logic
	file1b.seekg(0, ios::beg);//same old logic
		final_file<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";	
		while(file1b)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file1b,a);
			getline(file1b,b);
			getline(file1b,c);
			getline(file1b,d);
			file1b>>e;
			file1b>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}  
		if(ahmed<=0)//else if file is empty print this
	    {
	    	final_file<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		final_file<<"\n\t\tRECORD OF ENGINES!!\n";
		if(file2a.tellg()!=0)//same old logic
		{
			file2a.clear();//same old logic
	file2a.seekg(0, ios::beg);//same old logic
		final_file<<"\nEXTERNAL ORDER: \n";
			
		while(file2a)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file2a,a);
			getline(file2a,b);
			getline(file2a,c);
			getline(file2a,d);
			file2a>>e;
			file2a>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}	
		}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file2b.tellg()!=0)//same old logic
		{
			file2b.clear();//same old logic
	file2b.seekg(0, ios::beg);	//same old logic
		final_file<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file2b)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file2b,a);
			getline(file2b,b);
			getline(file2b,c);
			getline(file2b,d);
			file2b>>e;
			file2b>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		final_file<<"\n\t\tRECORD OF LED'S !!\n";
		if(file3a.tellg()!=0)
		{	
			file3a.clear();//same old logic
	file3a.seekg(0, ios::beg);//same old logic
	    final_file<<"\nEXTERNAL ORDER: \n";
			
		while(file3a)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file3a,a);
			getline(file3a,b);
			getline(file3a,c);
			getline(file3a,d);
			file3a>>e;
			file3a>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file3b.tellg()!=0)//same old logic
		{
				file3b.clear();//same old logic
	file3b.seekg(0, ios::beg);//same old logic
		final_file<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";			
		while(file3b)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file3b,a);
			getline(file3b,b);
			getline(file3b,c);
			getline(file3b,d);
			file3b>>e;
			file3b>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		final_file<<"\n\t\tRECORD OF PRINTER!!\n";
	    if(file4a.tellg()!=0)//same old logic
	    {	
	    	file4a.clear();//same old logic
	file4a.seekg(0, ios::beg);//same old logic
	    
		final_file<<"\nEXTERNAL ORDER: \n";
			
		while(file4a)//if file not empty then it will print this stuff in final report
		{
			ahmed++;
			getline(file4a,a);
			getline(file4a,b);
			getline(file4a,c);
			getline(file4a,d);
			file4a>>e;
			file4a>>f;
			
		    final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file4b.tellg()!=0)//same old logic
		{
				file4b.clear();//same old logic
	file4b.seekg(0, ios::beg);//same old logic
			final_file<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file4b)//if file not empty then it will print this stuff in final report
		{
		ahmed++;
			getline(file4b,a);
			getline(file4b,b);
			getline(file4b,c);
			getline(file4b,d);
			file4b>>e;
			file4b>>f;
			
		    final_file<<a<<endl<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
	}
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		final_file<<"\n\t\tRECORD OF AC'S !!\n";
	    if(file5a.tellg()!=0)//same old logic
	    {
	    		file5a.clear();//same old logic
	file5a.seekg(0, ios::beg);//same old logic
	    	
	    final_file<<"\nEXTERNAL ORDER: \n";
			
		while(file5a)//if file not empty then it will print this stuff in final report
		{
		ahmed++;
			getline(file5a,a);
			getline(file5a,b);
			getline(file5a,c);
			getline(file5a,d);
			file5a>>e;
			file5a>>f;
			
		final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}
		if(ahmed<=0)//else if file is empty print this
		{
				final_file<<"\nNO EXTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
		
		ahmed=0;
		if(file5b.tellg()!=0)//same old logic
		{
				file5b.clear();//same old logic
	file5b.seekg(0, ios::beg);//same old logic
		final_file<<"\nINTERNAL ORDER/INVENTORY SYSTEM \n";
			
		while(file5b)//if file not empty then it will print this stuff in final report
		{
		ahmed++;
			getline(file5b,a);
			getline(file5b,b);
			getline(file5b,c);
			getline(file5b,d);
			file5b>>e;
			file5b>>f;
			
		   final_file<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f;
		}
		}	
		if(ahmed<=0)//else if file is empty print this
		{
			final_file<<"\nNO INTERNAL ORDER FOR THIS PRODUCT!!!!\n\n";
		}
	 Date_Time obj;
	 final_file<<"\n\tAt date and time:   "<<obj<<endl;
		final_file.close();
	}
	
};


#endif
