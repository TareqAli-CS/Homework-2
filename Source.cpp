#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
class student
{
	public:
	static int count; // that way i can make id changing one by one
	
	int id;
	string name;
	double avg;
	int number_item; // number of buying items
	
	
	static string fileName; // file to get the name
	student()
	{
		count++; // to add 1 per object To find out how many students
		
		
		fstream file;
	l1:	file.open(fileName.c_str());
		if(file.is_open())
		{
			int numberOfLine=0 ;// Number of lines in the file : number of names in the file
			string line;
			file.clear();
			file.seekg(0); // to start from the beginning
			while(getline(file,line))
			{
				numberOfLine++;	
			}
			file.clear();
			file.seekg(0); // to back from beginning of file
			for(int i=1;i<=count;i++)
			{
				getline(file, name);
				
			}
			if(numberOfLine<count)
			{
				cout<<"file out of name, please enter the name: "; // enter the name manually
				cin>>name; 
			}
		}
		else
		{
			cout<<"file can't open, check its name...."<<endl;
			cout<<"please enter new file name: ";
			cin>>fileName;
			goto l1;
		}
		file.close();
									
		id=count;
		number_item=rand()%4;
		cout<<"enter items for student id:"<<id<<" ";
		cin>>number_item;
		avg=rand()%101;
	//	cout<<"enter average for student id:"<<id<<" ";
	//	cin>>avg;
		
		avg =30;
		
	}
	
};
int student ::count=0;
string student ::fileName="name.txt";
void addStudent(queue<student>&q , int number_student);
void printStudent(queue<student>q);
void total(queue<student>q,int n); //  cafeteria earn
main()
{
	int n_c=rand()%201; // number of cafeteria items
	int n_s=rand()%101; // number of students;
	cout<<"enter number of cafeteria items: ";
	cin>>n_c;
	cout<<"enter number of students: ";
	cin>>n_s;
	
	queue<student>q;
	addStudent(q,n_s);
	printStudent(q);
	total(q,n_c);
	
}
void addStudent(queue<student>&q , int number_student) // add student in order 
{
	queue<student>temp;
	for(int i=0;i<number_student;i++)
	{
		student *a=new student;
		int j=0;
		
		if(a->avg==q.front().avg)
		q.push(*a);
		
		else
		{
			while(!q.empty())
			{
				temp.push(q.front());
				if(a->avg<q.front().avg)
				j++;
				q.pop();		
			}
			for(int k=0;k<j;k++)
			{
				q.push(temp.front());
				temp.pop();	
			}
			q.push(*a);
			while(!temp.empty())
			{
				q.push(temp.front());
				temp.pop();	
			}
		}	
	}
}
void printStudent(queue<student>q)
{
	int id;
	string name;
	int numberOfItems;
	double avg;
	while(!q.empty())
	{
		id=q.front().id;
		name=q.front().name;
		numberOfItems=q.front().number_item;
		avg=q.front().avg;
		

		
		cout<<"ID: "<<id<<"\nName: "<<name<<"\nAvg: "
		<<avg<<"\nNumber of Item: "<<numberOfItems<<endl;
		q.pop();
		cout<<"********************************************\n";
	}
}
void total(queue<student>q,int n) // n : number of cafeteria items
{
	int money=0;
	int cantbuying=0; // number of students that don't buying any item
	//
	int id;
	int numberOfItems;
	double avg;
	//
	while(!q.empty())
	{
		id=q.front().id;
		numberOfItems=q.front().number_item;
		avg=q.front().avg;
//    									
		
		if(numberOfItems==0 )// the student did not want to buy or dont  found items in the cafeteria
		{
			cantbuying++;  //no need to check his average
			goto l3; 	  // Go to the next student
		}
		else if(n==0) // no need to check other students
		{
			while(!q.empty())
			{
				cantbuying++;
				q.pop();
			}
			goto l2; // print and out from the function
		}
		
		if(avg>=90) // all his items for free
		{	
			if(numberOfItems<=n && numberOfItems!=0)
			n=n-numberOfItems; // all item for free 
			
			else if(numberOfItems>n ) 
			{
				
				cout<<"student id ("<<id<<") want to buy "<<numberOfItems<<
				" items and there are just "<<n<<" item in cafeteria"<<endl;
				n=0;	
			}
		}
		else if(avg>=60 && avg<=89)
		{	
			if(numberOfItems<=n && numberOfItems!=0)
			{
				
				numberOfItems--;
				n--; // free item;
				money=money+ numberOfItems  * 10;
				n=n-numberOfItems;
			}
			else if(numberOfItems>n)
			{	
				cout<<"student id ("<<id<<") want to buy "<<numberOfItems<<
				" items and there are just "<<n<<" item in cafeteria"<<endl;			
				
				n--; // free item;
			
				while(n!=0)
				{	
					money=money+10;
					n--;
					numberOfItems--;	
				}
			}
			
		} // avg>=60 && avg<=89
		
		else
		{
			
			if(numberOfItems<=n && numberOfItems!=0)
			{
				
				money=money+(numberOfItems  * 10);
				n=n-numberOfItems;
			}
			else if(numberOfItems>n)
			{
				cout<<"student id ("<<id<<") want to buy "<<numberOfItems<<
				" items and there are just "<<n<<" item in cafeteria"<<endl;
				
				
				while(n!=0)
				{	
					money=money+10;
					n--;
					numberOfItems--;	
				}	
			}
		}// avg<60
		
l3:		q.pop(); 
	}
	
	
l2:	cout<<"=============================================================="<<endl;
	cout<<" The number of students who did not buy anything: "<<cantbuying<<endl;
	cout<<" Total money earned by Cafeteria: $"<<money<<endl;
	cout<<"=============================================================="<<endl;
}
