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
void addstudent(queue<student>&q);
void printStudent(queue<student>q);
main()
{
	int n_c=rand()%201; // number of cafeteria items
	queue<student>q;
	addstudent(q);
	printStudent(q);
	
}
void addstudent(queue<student>&q) // add random students less than 100
{
	int number_student=rand()%101;
	for(int i=0;i<number_student;i++)
	{
		student a;
		student b;
		queue<student>temp;
		while(!q.empty())
		{
			b=q.front();
			q.pop();
			if(b.avg<a.avg)
			
		}
		q.push(a);
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
