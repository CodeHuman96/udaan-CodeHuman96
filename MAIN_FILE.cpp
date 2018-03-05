#include <bits/stdc++.h>
using namespace std;
char ch3;
	
class book_d
{
	public:
	string author_name;
	string book_name;
	bool avai;
	string stud_id;
	book_d()
	{
		stud_id="";
		avai=1;
	}
			
};
bool search(char ch1, string str)
{
	bool flag = false;
	ifstream file;
	file.open("DATA.TXT", ios::in | ios::app);
	book_d book_obj;
	file.read((char*)&book_obj, sizeof(book_obj));
	while(!file.eof() || !flag )
	{
	 	
		if(book_obj.avai==false)	return false;
		if(ch1=='1')
	 		if(book_obj.author_name==str)
			 			flag = true;
		else if(ch1=='2')
		 	if(book_obj.book_name==str)	
			 	flag =true;			
				
		
	}
	return flag;
}
void reserve_book()
{
	ifstream file;
	file.open("DATA.TXT", ios::in | ios::app);
	string stud_id;
	cout<<"\nEnter Student ID:";
	cin>>stud_id;
	char ch1;
	cout<<"Search by:\n1.)Book name\n2.)Author Name";
	cin>>ch1;
	string str;
	cout<<"Enter the string:\n";
	cin>>str;
	bool flag = false;
	book_d book_obj;
	file.read((char*)&book_obj, sizeof(book_obj));
	while(!file.eof())
	 	
		if(book_obj.avai==false)	break;
		if(ch1=='1')
	 		if(book_obj.author_name==str)
			 			flag = true;
		else if(ch1=='2')
		 	if(book_obj.book_name==str)	
			 	flag =true;	
		if(flag)	
			{
					book_obj.stud_id=stud_id;
		book_obj.avai = 0;
		cout<<"\nBook Issues to :"<<stud_id;
		return ;
		}			
		cout<<"\nBook not available";
		return ;		
	}
		
	//
	

void return_book()
{
	string stud_id;
	cout<<"\nEnter Student ID:";
	cin>>stud_id;
	bool flag= false;
	ifstream file;
	file.open("DATA.TXT", ios::in | ios::app);
	book_d book_obj;
	file.read((char*)&book_obj, sizeof(book_obj));
	while(!file.eof() || !flag )
	{
	 	
		if(book_obj.avai==false && book_obj.stud_id==stud_id)
		{
			cout<<"\nBook returned";
			book_obj.avai=1;
			return ;
		}
				
	}
	cout<<"\nError: file not found or book never issued";
	return ;
	
}
void record_print()
{
	
	ifstream file;
	file.open("DATA.TXT", ios::in | ios::app);
	cout<<"\n\n\n#################################################################";
	cout<<"\nBook Records";
	string line;
	while( getline(file,line))
	{
		cout<<line<<endl;
	}
	cout<<"\n\n__________________________________________________________________________";
	return ;
	
}
int main()
{
	ch3='y';
	do{
		
		ifstream file;
		file.open("DATA.TXT", ios::in | ios::app);
		int ch;
		cout<<"Menu:\n1.)Search\n2.)Reserve\n3.)Return book\n4.)Records of all the books\n";
		cin>>ch;
		if(ch==1)
		{
			char ch1,ch2;
					 cout<<"Search by:\n1.)Book name\n2.)Author Name";
					 cin>>ch1;
					 string str;
					 cout<<"Enter the string:\n";
					 cin>>str;
					  if(search(ch1, str )==false)	
					 {
						 	cout<<"\nBook not available";
						 	break;			
					 }
					 cout<<"Book found: enter 1 to reserve:";
					 cin>>ch2;
					 if(ch2=='1')
						 	reserve_book();
		}
		else if(ch==2) reserve_book();
		else if(ch==3) return_book();
		else if(ch==4)	record_print();
		else cout<<"Enter valid option!!";
		
	cout<<"\n\nTo continue enter y|Y";
	cin>>ch3;
	} while(ch3=='Y' || ch3== 'y');
	return 0;
}
