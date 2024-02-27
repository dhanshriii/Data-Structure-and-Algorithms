//This is a Library management system using array data structure
/*The user can :
	1) Insert the Books in the library
 	2) Display the books present in the library
  	3) Search for any book
   	4) Update any book details
    	5) Delete any book record
*/
#include<iostream>
using namespace std;
int n, i; //Globally declaring a variable

class Library{
	int bid,price;
	char *title, *aut, *pub, *ISBN;
	
	public :
		 void accept();
		 void display();
		 void search();
		 void update();
		 void del();
}b[10];

void Library :: accept(){
	//Assigning the memory dynamically to the variables as we dont know the size the name of the book or athor name or any of the mentioned below
	//Inorder to avoid memory wastage
	title = new char;   
	aut = new char;		
	pub = new char;
	ISBN = new char;
	
	cout<<"Enter the Book details !";
	cout<<"\nEnter the Book ID : ";
	cin>>bid;
	cout<<"\nEnter the Title of the book : ";
	cin>>title;
	cout<<"\nENter the Author of the book : ";
	cin>>aut;
	cout<<"\nEnter the Publisher of the book : ";
	cin>>pub;
	cout<<"\nEnter the ISBN no of the book : ";
	cin>>ISBN;
	cout<<"\nEnter the price of the book : ";
	cin>>price;
}

void Library :: display(){
	cout<<"\n"<<bid<<"\t"<<title<<"\t"<<aut<<"\t"<<pub<<"\t"<<ISBN<<"\t"<<price;
	
}

void Library :: search(){
	int bookid,f = 0;
	cout<<"\nEnter the the ID of the book you wat to search : ";
	cin>>bookid;
	for(i = 0;i < n; i++){
		if(bookid == b[i].bid){
			f = 1;
			cout<<"\nBook Found!!\nThe details of the book are :\n";
			cout<<"\n"<<bid<<"\t"<<title<<"\t"<<aut<<"\t"<<pub<<"\t"<<ISBN<<"\t"<<price;
			b[i].display();	
			break;	
			}
			}
		if(f == 0){
			cout<<"\nThe book is not present in the library!";
		}
			
	
}

void Library :: update(){
	int bookid, f = 0;
	cout<<"Enter the book ID of the book which you want to update : ";
	cin>>bookid;
	
	for(i = 0; i < n; i++){
		if(bookid == b[i].bid){
			f = 1;
			cout<<"\nBook found!!\nPut the new details of the book : ";
			b[i].accept();
			cout<<"\nThe updated details are !\n";
			cout<<"\n"<<bid<<"\t"<<title<<"\t"<<aut<<"\t"<<pub<<"\t"<<ISBN<<"\t"<<price;
			b[i].display();
			break;
		}
	}
	if(f == 0){
		cout <<"\nThe book is not present in the library";
	}
}

void Library :: del(){
	int bookid, f =0;;
	cout<<"\nEnter the ID of the book which you want ot delete : ";
	cin>>bookid;
	for(i = 0; i < n ; i++){
		if(bookid == b[i].bid){
			f = 1;
			do{
				b[i] = b[i + 1];
				i++;
			}while(i < n);
		}
		n--;
		cout<<"\nRecord deleted";
		break;
		if(f == 0){
			cout<<"\nRecord not found";
		}
	}	
}

int main(){

	int ch;
	int choice;
	do{
		cout<<"\nWelcome to the library Management System!";
		cout<<"\n1. Accept Book";
		cout<<"\n2. Display";
		cout<<"\n3. Search";
		cout<<"\n4. Update";
		cout<<"\n5. Delete";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			case 1 :
				cout<<"\nEnter the number of books you want to add :";
				cin>>n;
				for(i = 0;i < n; i++){
					b[i].accept();
				}
				break;
				
			case 2 :
				cout<<"\nBook ID\tTitle\tAuthor\tPublisher\tISBN\tPrice";
				for(i = 0; i < n; i++){
					b[i].display();
				}
				break;
				
			case 3 :
				b[i].search();
				break;
				
			case 4 :
				b[i].update();
				break;
				
			case 5 :
				b[i].del();
				break;
				
			case 6 :
				exit(0);
		
		}
		cout<<"\nDo you want to continue :(0/1)";
		
		cin>>choice;
		
	}while(choice == 1);
	
return 0;
	
}























