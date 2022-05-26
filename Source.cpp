#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
class student
{
	public:
	static int count;
	
	int id;
	string name;
	double avg;
	int number_item; // number of buying items
	
	
	static string fileName;
	student()
	{
		count++; // to add 1 per object To find out how many students
		
		
		fstream file;
	l1:	file.open(fileName.c_str());
		if(file.is_open())
		{
			int numberOfLine=0 ;// Number of lines in the file
			string line;
			file.clear();
			file.seekg(0);
			while(getline(file,line))
			{
				numberOfLine++;
				
			}
			file.clear();
			file.seekg(0); // to return from beginning of file
			for(int i=1;i<=count;i++)
			{
				getline(file, name);
			}
			if(numberOfLine<count)
			{
				cout<<"file out of name, please enter name: ";
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
									
		
		number_item=rand()%4;
		avg=rand()%101;
		id=count;
	}
	
};
int student ::count=0;
string student ::fileName="name.txt";
void addRandomStudent(queue<student>&q);
void printStudent(queue<student>q);
void total(queue<student>q,int n); //  cafeteria earn
main()
{
	//int n_c=rand()%201; // number of cafeteria items
	int n_c=8;
	queue<student>q;
	addRandomStudent(q);
	printStudent(q);
	total(q,n_c);
	
	
}
void addRandomStudent(queue<student>&q) // add student in order 
{
	queue<student>temp;
//	int number_student=rand()%101;
	int number_student=7;
	for(int i=0;i<number_student;i++)
	{
		student *a=new student;
		int j=0;
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
void printStudent(queue<student>q)
{
	student s;
	while(!q.empty())
	{
		
		s=q.front();
		cout<<"ID: "<<s.id<<"\nName: "<<s.name<<"\nAvg: "
		<<s.avg<<"\nNumber of Item: "<<s.number_item<<endl;
		q.pop();
		cout<<"********************************************\n";
	}
}
void total(queue<student>q,int n) // n : number of cafeteria item
{
	int money=0;
	int cantbuying=0; // number of students that don't buying any item
	while(!q.empty())
	{
		
		if(q.front().avg>=90)
		{
			
			if(n>=q.front().number_item && q.front().number_item!=0)
			n=n-q.front().number_item; // all item for free 
			else if(q.front().number_item==0 || n==0 )
			cantbuying++;
			else if(q.front().number_item>n &&  n==0)
			{
				
				cout<<"student id ("<<q.front().id<<") want to buy "<<q.front().number_item<<
				"items and there are just "<<n<<" item in cafeteria"<<endl;
				n=0;
				
			}
		}
		else if(q.front().avg>=60 && q.front().avg<=89)
		{
			
			if(q.front().number_item<=n && q.front().number_item!=0)
			{
				q.front().number_item--;
				n--; // free item;
				money=money+ q.front().number_item  * 10;
				n=n-q.front().number_item;
			}
			else if(q.front().number_item==0 || n==0)
			{
				cantbuying++;
			}
			else if(q.front().number_item>n)
			{
				
				cout<<"student id ("<<q.front().id<<") want to buy "<<q.front().number_item<<
				"items and there are just "<<n<<" item in cafeteria"<<endl;			
				
				n--; // free item;
				
				while(n!=0)
				{
						
						money=money+10;
						n--;
						q.front().number_item--;	
				}
				
			}
			
		}
		
		else
		{
			
			if(q.front().number_item<=n && q.front().number_item!=0)
			{
				
				money=money+(q.front().number_item  * 10);
				n=n-q.front().number_item;
			}
			else if(q.front().number_item==0 || n==0)
			{
				cantbuying++;
			}
			else if(q.front().number_item>n)
			{
				cout<<"student id ("<<q.front().id<<") want to buy "<<q.front().number_item<<
				" items and there are just "<<n<<" item in cafeteria"<<endl;
				
				
				while(n!=0)
				{
					
						money=money+10;
						n--;
						q.front().number_item--;	
				}
				
				
			}
		}
		
		q.pop();
	}
	
	
	
	
	cout<<"==============================="<<endl;
	cout<<" number of student dont buy anything: "<<cantbuying<<endl;
	cout<<"==============================="<<endl;
	cout<<" total money cafeteria earn: "<<money<<endl;
}
