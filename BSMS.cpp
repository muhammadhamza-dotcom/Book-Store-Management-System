#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
#include<ctime>
using namespace std;

class books{
	private:
		string bookname,bookid;
		string bookauth;
		string bookpub;
		int price,no_cop;
	public:
		string bkname;
		int p1;
	    void set_price(){
	    	p1=price;
		}
		void set_bookname(){
			bkname=bookname;
		}
		void add_stock(){
			fstream newbook;
			cout<<"\t\t\t\t\t\tAdd New Stock\n";
			cout<<"========================================================================================================================\n";
			cout<<"\nBook ID: ";
			cin.ignore();
			getline(cin,bookid);
			cout<<"Enter Book Name: ";
			getline(cin,bookname);
			cout<<"Enter Author Name: ";
			getline(cin,bookauth);
			cout<<"Enter Publisher: ";
			getline(cin,bookpub);
			cout<<"How many copies: ";
			cin>>no_cop;
			cout<<"Processing...";
			Sleep (1000);
		    cout << ".....";
		    Sleep (1000);
		    cout << ".....";
		    cout<<"\nBook Added!";
			newbook.open("G:\\PRFILES\\Stock.txt",ios::out|ios::app);			
			newbook<<""<<bookid<<endl;
			newbook<<""<<bookname<<endl;
			newbook<<""<<bookauth<<endl;
			newbook<<""<<bookpub<<endl;
			newbook<<""<<no_cop<<endl;
			newbook<<"\n";
			newbook.close();
		}
		void stock_check(){
		string status_check;
		ifstream show("G:\\PRFILES\\Stock.txt");
		cout<<"\t\t\t\t\t\tStock Check\n";
		cout<<"========================================================================================================================\n";
		cout<<"\nOrder:\nBook ID:\nBook Name:\nAuthor:\nBook Publisher:\nAvailable Copies:\n"<<endl;
		cout<<"========================================================================================================================\n";
		while(getline(show,status_check)){
			cout<<"\n\n"<<status_check;		
		}
		show.close();
	    }
	    
	    void book_check(){
        int count=0,copy;
        string booknaam,book_check;
        fstream bcheck("G:\\PRFILES\\Stock.txt");
        bcheck>>bookid;
		bcheck>>bookname;
		bcheck>>bookauth;
		bcheck>>bookpub;
		bcheck>>no_cop;
		cout<<"\t\t\t\t\t\tBook Search\n";
		cout<<"========================================================================================================================\n";
        cout<<"\nEnter Book Name: ";
        cin.ignore();
        getline(cin,booknaam);
        while(getline(bcheck,book_check)){
        	if(booknaam==bookname){
        		cout<<"\nBook Found! ";
        		cout<<"\n\nBook ID: "<<bookid;
        		cout<<"\nBook Name: "<<bookname;
        		cout<<"\nBook Author: "<<bookauth;
        		cout<<"\nPublisher: "<<bookpub;
        		cout<<"\nAvailable Copies: "<<no_cop;
        		count++;
        		break;
			}
		  else{
		    bcheck>>bookid;
		    bcheck>>bookname;
		    bcheck>>bookauth;
		    bcheck>>bookpub;
		    bcheck>>no_cop;
		}
		
		}
		bcheck.close();
		if(count==0){
			cout<<"Book Not Found";
		}
	}
		
		void author_check(){
	    int count=0;
        string author,book_check;
        fstream bcheck("G:\\PRFILES\\Stock.txt");
        bcheck>>bookid;
		bcheck>>bookname;
		bcheck>>bookauth;
		bcheck>>bookpub;
		bcheck>>no_cop;
		cout<<"\t\t\t\t\t\tBook Search\n";
		cout<<"========================================================================================================================\n";
        cout<<"\nEnter Author Name: ";
        cin.ignore();
        getline(cin,author);
        while(getline(bcheck,book_check)){
        	if(author==bookauth){
        		cout<<"\nBook Found! ";
        		cout<<"\n\nBook ID: "<<bookid;
        		cout<<"\nBook Name: "<<bookname;
        		cout<<"\nBook Author: "<<bookauth;
        		cout<<"\nPublisher: "<<bookpub;
        		cout<<"\nAvailable Copies: "<<no_cop;
        		count++;
        		break;
			}
		  else{
		    bcheck>>bookid;
		    bcheck>>bookname;
		    bcheck>>bookauth;
		    bcheck>>bookpub;
		    bcheck>>no_cop;
		}
		
		}
		bcheck.close();
		if(count==0){
			cout<<"No Book Found By: "<<author;
		}
				

}
};



class customer{
	private:
		string customname;
		string email;
		long long phoneno;
	public:
		
		void add_customer(){
			fstream customer;
			cout<<"\t\t\t\t\t\tAdd Customer\n";
		    cout<<"========================================================================================================================\n";
			cout<<"\nEnter Customer Name: ";
			cin.ignore();
			getline(cin,customname);
			cout<<"Enter Customer's Phone Number: ";
			cin>>phoneno;
			cout<<"Enter Customer's Email Address: ";
			cin.ignore();
			getline(cin,email);
			cout<<"Processing...";
			Sleep (2000);
		    cout << ".....";
		    Sleep (2000);
		    cout << ".....";
		    cout<<"\n\n\nCustomer Added!\n\n";
		    customer.open("G://PRFILES//Customerlist.txt",ios::out|ios::app);
		    customer<<""<<customname<<endl;
		    customer<<""<<phoneno<<endl;
		    customer<<""<<email<<endl;
		    customer<<"\n\n";
		    customer.close();
		}
		void modify_customer(){
			fstream custom,custom1;
			int count=0;
			string customname,email,customer,custom_check,updatename,updatemail;
			long long phoneno,updatephone;
			custom1.open("G://PRFILES//Customerlist1.txt",ios::app|ios::out);
			custom.open("G://PRFILES//Customerlist.txt",ios::in);
			cout<<"\t\t\t\t\t\tCustomer Modification\n";
		    cout<<"========================================================================================================================\n";
			cout<<"\nEnter Customer Name: ";
			cin.ignore();
			getline(cin,customer);
			custom>>customname;
			custom>>phoneno;
			custom>>email;
			while(getline(custom,custom_check)){
				if(customer==customname){
					cout<<"Enter Updated Customer Name: ";
					getline(cin,updatename);
					cout<<"Enter Updated Phone Number: ";
					cin>>updatephone;
					cin.ignore();
					cout<<"Enter Updated Email: ";
					getline(cin,updatemail);
					count++;
					custom1<<""<<updatename<<endl;
		            custom1<<""<<updatephone<<endl;
		            custom1<<""<<updatemail<<endl;
		            custom1<<"\n\n";
		            break;
		    
				}
				else{
				    custom1<<""<<customname<<endl;
		            custom1<<""<<phoneno<<endl;
		            custom1<<""<<email<<endl;
		            custom1<<"\n\n";
		            
		            custom>>customname;
			        custom>>phoneno;
			        custom>>email;
		            
				}
				if(count==0)
				cout<<"Customer Not Found!";
			}
		custom.close();
		custom1.close();
		remove("G://PRFILES//Customerlist.txt");
		rename("G://PRFILES//Customerlist1.txt","G://PRFILES//Customerlist.txt");	
			
		}
		
		void del_customer(){
			fstream custom,custom1;
			int count=0;
			string customname,email,customer,custom_check;
			long long phoneno;
			custom1.open("G://PRFILES//Customerlist1.txt",ios::app|ios::out);
			custom.open("G://PRFILES//Customerlist.txt",ios::in);
			cout<<"\t\t\t\t\t\tCustomer Deletion\n";
		    cout<<"========================================================================================================================\n";
			cout<<"\nEnter Customer Name: ";
			cin.ignore();
			getline(cin,customer);
			custom>>customname;
			custom>>phoneno;
			custom>>email;
			while(getline(custom,custom_check)){
				if(customer==customname){
					count++;
				    cout<<"\nCustomer Deleted Successfully";
		            break;
		    
				}
				else{
				    custom1<<""<<customname<<endl;
		            custom1<<""<<phoneno<<endl;
		            custom1<<""<<email<<endl;
		            custom1<<"\n\n";
		            
		            custom>>customname;
			        custom>>phoneno;
			        custom>>email;
		            
				}
				if(count==0){
				cout<<"Customer Not Found!";
			}
			}
		custom.close();
		custom1.close();
		remove("G://PRFILES//Customerlist.txt");
		rename("G://PRFILES//Customerlist1.txt","G://PRFILES//Customerlist.txt");	
			
        
		}
		
};
class invoice: virtual public books , virtual public customer{
	private:
	 string invonum;
	 string customername;
	 int quan;
	
	public:
	  
	 void gene_invo(){
	 	fstream customer,salesreport;
	 	int count=0;
	 	time_t result = time(nullptr);
	 	string cuscheck,customname,phoneno,email;
	 	customer.open("G://PRFILES//Customerlist.txt",ios::in);
	 	salesreport.open("G://PRFILES//Sales.txt",ios::app|ios::out);
	 	cout<<"\t\t\t\t\t\tInvoice Creator\n";
		cout<<"========================================================================================================================\n";
	 	cout<<"\nEnter Customer Name: ";
	 	cin.ignore();
	 	getline(cin,customername);
	 	customer>>customname;
		customer>>phoneno;
		customer>>email;
		while(getline(customer,cuscheck)){
		if(customername==customname){
		cout<<"Enter Book Name: ";
	 	getline(cin,bkname);
	 	cout<<"Enter Price Of Purchased Item: ";
	 	cin>>p1;
	 	cout<<"Enter Quantity Purchased: ";
	 	cin>>quan;
	 	cout<<"Generating Invoice....";
	 	Sleep (1000);
		cout << ".....";
		Sleep (1000);
		cout << ".....";
	 	
	 	system("cls");
	 	cout<<"\nBookie";
	 	cout<<"\n===============================";
	 	cout<<"\nCustomer Name: "<<customername;
	 	cout<<"\nItem Purchased: "<<bkname;
	 	cout<<"\nTotal Price: "<<p1*0.95;
	 	cout<<"\nQuantity Bought: "<<quan;
	 	cout<<"\n===============================";
	 	cout<<"\nTotal Amount To Be Paid: "<<p1*quan*0.95;
	 	cout<<"\n===============================";
	 	cout<<"\nThanks For Coming By!"<<endl;
	 	cout<<ctime(&result);
	 	count++;
	 	
	 	salesreport<<"Bookie"<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Customer Name: "<<customername<<endl;
	 	salesreport<<"Item Purchased: "<<bkname<<endl;
	 	salesreport<<"Total Price: "<<p1*0.95<<endl;
	 	salesreport<<"Quantity Bought: "<<quan<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Total Amount To Be Paid: "<<p1*quan*0.95<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Thanks For Coming By!"<<endl;
	 	salesreport<<ctime(&result);
	 	salesreport<<"\n\n";
	 	
	    cout<<"\n\nPress any key to go back to the main menu";
	 	getch();
	 	cout<<"\nGoing Back To The Menu...";
			Sleep (1000);
		    cout << ".....";
		    Sleep (1000);
		    cout << ".....";
		    system("cls");
	 	    break;
				
			}
			else{
			customer>>customname;
			customer>>phoneno;
			customer>>email;
			}
			
		}
		if(count==0){
			
	    cout<<"Enter Book Name: ";
	 	getline(cin,bkname);
	 	cout<<"Enter Price Of Purchased Item: ";
	 	cin>>p1;
	 	cout<<"Enter Quantity Purchased: ";
	 	cin>>quan;
	 	cout<<"Generating Invoice....";
	 	Sleep (1000);
		cout << ".....";
		Sleep (1000);
		cout << ".....";
	 	
	 	system("cls");
	 	cout<<"Bookie";
	 	cout<<"\n===============================";
	 	cout<<"\nCustomer Name: "<<customername;
	 	cout<<"\nItem Purchased: "<<bkname;
	 	cout<<"\nTotal Price: "<<p1;
	 	cout<<"\nQuantity Bought: "<<quan;
	 	cout<<"\n===============================";
	 	cout<<"\nTotal Amount To Be Paid: "<<p1*quan;
	 	cout<<"\n===============================";
	 	cout<<"\nThanks For Coming By!"<<endl;
	 	cout<<ctime(&result);
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Bookie"<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Customer Name: "<<customername<<endl;
	 	salesreport<<"Item Purchased: "<<bkname<<endl;
	 	salesreport<<"Total Price: "<<p1<<endl;
	 	salesreport<<"Quantity Bought: "<<quan<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Total Amount To Be Paid: "<<p1*quan<<endl;
	 	salesreport<<"==============================="<<endl;
	 	salesreport<<"Thanks For Coming By!"<<endl;
	 	salesreport<<ctime(&result);
	 	salesreport<<"\n\n";
	 	
	    cout<<"\n\nPress any key to go back to the main menu";
	 	getch();
	 	cout<<"\nGoing Back To The Menu...";
			Sleep (1000);
		    cout << ".....";
		    Sleep (1000);
		    cout << ".....";
		    system("cls");
		    
	 	
	 	
	 	
	 }
	 salesreport.close();
	 customer.close();	
}
    void sales_check(){
    	string sales;
    	cout<<"\t\t\t\t\t\tSales Checker\n";
		cout<<"========================================================================================================================\n";
    	ifstream salesreport("G://PRFILES//Sales.txt");
    	while(getline(salesreport,sales)){
    		cout<<"\n"<<sales;
    		
		}
		salesreport.close();
		
	}
};

class staff: virtual public books , virtual public invoice , virtual public customer{
	private:
		string name;
		string pass;		
	public:
		char ch3;
		void set_name(string naam){
			naam=name;
		}
		
		void set_pass(string passwd){
			passwd=pass;
		}
	
		void staff_login(){
		int count=0;
        string user_check,username,password,staffname,email;
        long long phoneno;
        ifstream check("G:\\PRFILES\\Staff.txt");
        cout<<"\t\t\t\t\t\tStaff Login\n";
        cout<<"========================================================================================================================\n";
        cout<<"\nEnter Username: ";
        cin>>name;
        cout<<"Enter Password: ";
        cin>>pass;
        check>>staffname;
		check>>phoneno;
		check>>email;
		check>>username;
		check>>password;
        while(getline(check,user_check)){
        	if(name==username && pass==password){
        		system("cls");
        		whatsnext();
        		count++;
        	    break;
			}
			check>>staffname;
		    check>>phoneno;
		    check>>email;
			check>>username;
			check>>password;
		}
		check.close();
		if(count==0){
			cout<<"Username or Password Incorrect!";
			cout<<"\n\nPress Enter To Try Again!";
			getch();
			system("cls");
			staff_login();
		}
		}
	

		void whatsnext(){
			int choice,ch1;
			cout<<"Welcome "<<name<<"!"<<"\nIt is nice to see you :)\n";
			cout<<"========================================================================================================================\n";
			cout<<"\nWhat would you like to do today ?";
			cout<<"\n\n1.Book Search";
			cout<<"\n2.Generate Invoice";
			cout<<"\n3.Add New Customer";
			cout<<"\n4.Modify Current Customer Details";
			cout<<"\n5.Delete a Customer";
			cout<<"\n6.Add stock";
			cout<<"\n7.Stock Status Check";
			cout<<"\n8.Check Sales Report";
			cout<<"\n9.Exit\n\n";
			cout<<"========================================================================================================================\n";
			cin>>choice;
			switch(choice){
				case 1:
					system("cls");
					cout<<"\t\t\t\t\t\tBook Search\n";
					cout<<"========================================================================================================================\n";
					cout<<"\n1.Search Book By Name\n2.Search Book By Author\n\n";
					cout<<"========================================================================================================================\n";
					cin>>ch1;
		
				switch(ch1){
					case 1:					
						do{
					   system("cls");
					   book_check();
					   cout<<"\n\nWant To Search For Another Book? (Y/N)\n";
					   cin>>ch3;
					   
					}
					while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
					case 2:
					   do{
					   system("cls");
					   author_check();
					   cout<<"\n\nWant To Search For Another Book? (Y/N)\n";
					   cin>>ch3;
					   
					}
					while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
				}
				break;
				
				case 2:
				   system("cls");
				   gene_invo();
				   whatsnext();
				   break;
				case 3:
					do{
					   system("cls");
					   add_customer();
					   cout<<"\nWant To Add More? (Y/N)\n";
					   cin>>ch3;
					   
					}
					while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
				    
				case 4:
						do{
					   system("cls");
					   modify_customer();
					   cout<<"\nWant To Update More? (Y/N)\n";
					   cin>>ch3;
					   
					}
					while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
					
				case 5:
					do{
					   system("cls");
					   del_customer();
					   cout<<"\nWant To Delete More? (Y/N)\n";
					   cin>>ch3;
					   
					}
					while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
				case 6:
					do{
					system("cls");
				    add_stock();
				    cout<<"\n\nWant to Add more? (Y/N)\n";
				    cin>>ch3;
				    }
				    while(ch3 == 'Y' || ch3 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
						
					case 7:
					do{
					system("cls");
					stock_check();
					cout<<"\n\nBack To The Menu (Y/N)\n";
				    cin>>ch3;
				    }
				    while(ch3 == 'N' || ch3 == 'n');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;	
					case 8:
					do{
					system("cls");
					sales_check();
					cout<<"\n\nBack To The Menu (Y/N)\n";
				    cin>>ch3;
				    }
				    while(ch3 == 'N' || ch3 == 'n');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsnext();
					break;
					case 9:
					exit(0);
					default:
					  cout<<"\nInvalid Choice! \n\nPress any key to try again";
			          getch();	
			          system("cls");
					  whatsnext();	
			}
		
		
			}		
	

		
};


class admin: virtual public staff{
	private:
		string name,username,name1;
		string pass;
	public:
		string naam,email;
		string passwd,assignpass;
		long long phone;
		
		
		void set_pass(){
			passwd=pass;
		}
	
			void add_staff(){
			fstream newmem;
			cout<<"\t\t\t\t\t\tAdd Staff\n";
		    cout<<"========================================================================================================================\n";
			cout<<"\nEnter Name: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter Phone no: ";
			cin>>phone;
			cout<<"Enter email Address: ";
			cin.ignore();
			getline(cin,email);
			cout<<"Assign a username(No Spaces): ";
			getline(cin,username);
			cout<<"Assign a password: ";
			getline(cin,assignpass);
			cout<<"Processing...";
			Sleep (1000);
		    cout << ".....";
		    Sleep (1000);
		    cout << ".....";
		    cout<<"\nNew Staff Member Added!";
			newmem.open("G:\\PRFILES\\Staff.txt",ios::out|ios::app);
			newmem<<""<<name<<endl;
			newmem<<""<<phone<<endl;
			newmem<<""<<email<<endl;
			newmem<<""<<username<<endl;
			newmem<<""<<assignpass<<endl;
			newmem<<"\n";
			newmem.close();
						
			
		}
		void modify_staff(){
			fstream staff,staff1;
			int count=0;
			string staffname,email,staffmember,staff_check,updatename,updatemail,assignname,assignpass,updateuname,updatepass;
			long long phoneno,updatephone;
			staff1.open("G://PRFILES//Staff1.txt",ios::app|ios::out);
			staff.open("G://PRFILES//Staff.txt",ios::in);
			cout<<"\t\t\t\t\t\tStaff Modification\n";
			cout<<"========================================================================================================================\n";
			cout<<"\nEnter Staff Member's Name: ";
			cin.ignore();
			getline(cin,staffmember);
			staff>>staffname;
			staff>>phoneno;
			staff>>email;
			staff>>assignname;
			staff>>assignpass;
			while(getline(staff,staff_check)){
				if(staffmember==staffname){
					count++;
					cout<<"Enter Updated Staff Member's Name: ";
					getline(cin,updatename);
					cout<<"Enter Updated Phone Number: ";
					cin>>updatephone;
					cin.ignore();
					cout<<"Enter Updated Email: ";
					getline(cin,updatemail);
					cout<<"Enter Updated Username(No Spaces): ";
					getline(cin,updateuname);
					cout<<"Enter Updated Password: ";
					getline(cin,updatepass);
					staff1<<""<<updatename<<endl;
		            staff1<<""<<updatephone<<endl;
		            staff1<<""<<updatemail<<endl;
		            staff1<<""<<updateuname<<endl;
		            staff1<<""<<updatepass<<endl;
		            staff1<<"\n";
		            break;
		    
				}
				else{
				    staff1<<""<<staffname<<endl;
		            staff1<<""<<phoneno<<endl;
		            staff1<<""<<email<<endl;
		            staff1<<""<<assignname<<endl;
		            staff1<<""<<assignpass<<endl;
		            staff1<<"\n";
		            
		            staff>>staffname;
			        staff>>phoneno;
			        staff>>email;
			        staff>>assignname;
			        staff>>assignpass;
				}
				if(count==0)
				cout<<"Staff Member Not Found!";
			}
		staff.close();
		staff1.close();
		remove("G://PRFILES//Staff.txt");
		rename("G://PRFILES//Staff1.txt","G://PRFILES//Staff.txt");
}
			
		void del_staff(){
			fstream staff,staff1;
			int count=0;
			string staffname,email,staffmember,staff_check,assignname,assignpass;
			long long phoneno;
			staff1.open("G://PRFILES//Staff1.txt",ios::app|ios::out);
			staff.open("G://PRFILES//Staff.txt",ios::in);
			cout<<"\t\t\t\t\t\tStaff Deletion\n";
			cout<<"========================================================================================================================\n";
			cout<<"\nEnter Staff Member's Name: ";
			cin.ignore();
			getline(cin,staffmember);
		    staff>>staffname;
			staff>>phoneno;
			staff>>email;
			staff>>assignname;
			staff>>assignpass;
			while(getline(staff,staff_check)){
				if(staffmember==staffname){
					count++;
				    cout<<"Staff Member Deleted Successfully!";
		            break;
		    
				}
				else{
				    staff1<<""<<staffname<<endl;
		            staff1<<""<<phoneno<<endl;
		            staff1<<""<<email<<endl;
		            staff1<<""<<assignname<<endl;
		            staff1<<""<<assignpass<<endl;
		            staff1<<"\n";
		            
		            staff>>staffname;
			        staff>>phoneno;
			        staff>>email;
			        staff>>assignname;
			        staff>>assignpass;
				}
				if(count==0){
				cout<<"Staff Member Not Found!";
			}
			}
		staff.close();
		staff1.close();
		remove("G://PRFILES//Staff.txt");
		rename("G://PRFILES//Staff1.txt","G://PRFILES//Staff.txt");	
			
			
			
		}
		void stock_checkup(){
		string status_check;
		ifstream show("G:\\PRFILES\\Stock.txt");
		cout<<"\t\t\t\t\t\tStock Check\n";
		cout<<"========================================================================================================================\n";
		cout<<"\nOrder:\nBook ID:\nBook Name:\nAuthor:\nBook Publisher:\nAvailable Copies:\n"<<endl;
		cout<<"========================================================================================================================\n";
		while(getline(show,status_check)){
			cout<<"\n\n"<<status_check;		
		}
		show.close();
		}
		
		void salesreport(){
		string sales;
    	ifstream salesreport("G://PRFILES//Sales.txt");
    	cout<<"\t\t\t\t\t\tSales Checker\n";
		cout<<"========================================================================================================================\n";
    	while(getline(salesreport,sales)){
    		cout<<"\n"<<sales;
		}
		salesreport.close();
		}
		
			
			
		
		void whatsadminnext(){
			int choice;
			char ch1;
			cout<<"Welcome "<<name1<<"!"<<"\nIt is nice to see you :)\n";
			cout<<"========================================================================================================================\n";
			cout<<"\nWhat would you like to do today ?\n";
			cout<<"\n1.Add A New Staff Member";
			cout<<"\n2.Modify Current Staff Details";
			cout<<"\n3.Delete a Staff Member";
			cout<<"\n4.Stock Status Check";
			cout<<"\n5.Check Sales Report";
			cout<<"\n6.Exit\n\n";
			cout<<"========================================================================================================================\n";
			cin>>choice;
			switch(choice){
				case 1: 
				    do{
					
				    system("cls");
				    add_staff();
				    cout<<"\n\nWant To Add more? (Y/N)\n";
				    cin>>ch1;
	            }
				    while(ch1 == 'Y' || ch1 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsadminnext();
					break;
					
					case 2:
					 	do{
					   system("cls");
					   modify_staff();
					   cout<<"\nWant To Update More? (Y/N)\n";
					   cin>>ch1;
					   
					}
					while(ch1 == 'Y' || ch1 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsadminnext();
					break;
						
				    case 3:
				    do{
					   system("cls");
					   del_staff();
					   cout<<"\nWant To Delete More? (Y/N)\n";
					   cin>>ch1;
					   
					}
					while(ch1 == 'Y' || ch1 == 'y');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsadminnext();
					break;	
					
					case 4:
					do{
					system("cls");
					stock_checkup();
					cout<<"\n\nBack To The Menu (Y/N)\n";
				    cin>>ch1;
				    }
				    while(ch1 == 'N' || ch1 == 'n');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsadminnext();
					break;	
					
					case 5:
					do{
					system("cls");
					salesreport();
					cout<<"\n\nBack To The Menu (Y/N)\n";
				    cin>>ch1;
				    }
				    while(ch1 == 'N' || ch1 == 'n');
				    cout<<"Going Back The Menu";
				    Sleep (1000);
		            cout << ".....";
		            Sleep (1000);
		            cout << ".....";
		            system("cls");
		            whatsadminnext();
					break;
					
					case 6:
					exit(0);
					default:
					cout<<"\nInvalid Choice! \n\nPress any key to try again";
			        getch();	
			        system("cls");
					whatsadminnext();	
			}
			
			
		}
		void admin_login(){
		int count=0;
        string user_check,username,password;
        long long phoneno;
        ifstream check("G:\\PRFILES\\Admin.txt");
        cout<<"\t\t\t\t\t\tAdmin Login\n";
        cout<<"========================================================================================================================\n";
        cout<<"\nEnter Username: ";
        cin>>name1;
        cout<<"Enter Password: ";
        cin>>pass;
		check>>username;
		check>>password;
        while(getline(check,user_check)){
        	if(name1==username && pass==password){
        		system("cls");
        		whatsadminnext();
        		count++;
        	    break;
			}
			check>>username;
			check>>password;
		}
		check.close();
		if(count==0){
			cout<<"Username or Password Incorrect!";
			cout<<"\n\nPress Enter To Try Again!";
			getch();
			system("cls");
			admin_login();
		}
		}
		void welscr(){
		string choice;
		system("Color 0D");
		cout<<"\t\t\t\t\t\tWelcome to Bookie\n";
		cout<<"========================================================================================================================\n";
		cout<<"\nPlease Specify\n"<<endl;
		cout<<"1.Staff Login"<<endl;
		cout<<"2.Admin Login\n\n";
		cout<<"========================================================================================================================\n";
		cin>>choice;
	   
		if(choice=="1"){
			system("cls");
			staff_login();
		}
		else if(choice=="2"){
			system("cls");
		    admin_login();
	    }
		else if(choice !="1" || choice !="2"){
			cout<<"\nInvalid Choice! \n\nPress any key to try again";
			getch();
			system("cls");
			welscr();
		}
	}
	

};

main()
{
  admin a1;
  a1.welscr();
  
}
