
#include<iostream>
using namespace std;
class queue
{
	int F,R;
	int que[10];
	public :
	int isqempty();
	int isqfull();
	void enque(int p);
	int deque();
	void display();
	queue()
	{
		F=-1;
		R=-1;
	}
};

int queue ::  isqempty()
{
	if(F=R == -1||F>R)
	{return 1;}
	else
	{return 0;}
}

int queue :: isqfull()
{
	if(R==9)
	{return 1;}
	else
	{return 0;}
}

void queue :: enque(int p)
{
	if(isqfull())
	cout<<"\nSorry, there is no space for job addition !\n";
	else
	{
		if(F=R==-1)
		{
			F=0;
			R=0;
		}
		que[R]=p;
		R++;
	}
}

int queue :: deque()
{
	if(isqempty())
	{
		cout<<"\nSorry ,no jobs are added\n";
		return 0;
	}
	
	int h;
	h=que[F];
	F++;
	cout<<"\nJob "<<h<<" processed successfully !\n";
	return h;
	
}

void queue ::display()
{
	for(int i=F;i<R;i++)
	{
		cout<<que[i]<<endl;	
	}	
}


int main()
{	int d,k;
	char x;
	queue s;
	cout<<"WELCOME TO JOBQUE";
	do{
		cout<<"\n1.Insert Job\n2.Remove Job\n3.Show status of Queue\n4.Exit\nEnter you choice :";
		cin>>d;
		switch(d) 
		{
				case 1:
				{
					cout<<"\nEnter Job :";
					cin>>k;
					s.enque(k);
					break;
					
				}
			case 2:
				{
					s.deque();
					break;
				}
			case 3:
				{
					s.display();
					break;
				}
			case 4:
				{
					return 0;
					break;
				}
			default :
				{
					cout<<"\nEnter valid choice !";
					
				}
		}
		cout<<"\ndo you want to continue ? y/n ";
		cin>>x;		
	} while(x=='y'||x=='Y');
	return 0;
}
