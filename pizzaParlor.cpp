
#include<iostream>
using namespace std;

class pizza
{
    int f,r;
    int que[10];
    public:
    pizza(){
        f=-1;
        r=-1;
        for(int i=0;i<9;i++)
        {
            que[i]=0;
        }
    }
    void enque(int k);
    void deque();
    int isqfull();
    int isqempty();
    void pending();
};

int main()
{
    int j;
    static pizza s;
    cout<<"\nWELCOME TO PIZZA PARLOUR\n";
    cout<<"1.Place Order\n2.Process order\n3.Check pending orders\n4.Exit\nEnter your choice :";
    cin>>j;
    switch(j)
    {
        case 1:
        int d;
        cout<<"\nPlease enter your id no. :";
        cin>>d;
        s.enque(d);
        main();
        break;
        case 2:
        s.deque();
        main();
        break;
        case 3:
        s.pending();
        main();
        break;
        case 4:
        return 0;
        break;
        default :
        cout<<"enter valid choice !";
        main();
        break;
    }
}

int pizza :: isqfull()
{
    if(f==(r+1)%10)
    return 1;
    else
    return 0;
}
int pizza :: isqempty()
{
    if((f==-1 && r==-1) )
    return 1;
    else
    return 0;
}
void pizza :: enque(int k)
{
    if(isqfull())
    cout<<"Currently Queue is FULL ! please try after some time.";
    else
    {
        if(f==-1 && r==-1)
        {
            f=0;
            r=0;
        }
        else
        r=(r+1)%10;
        
        que[r]=k;
        cout<<"Order placed successfully !";
    }
}
void pizza :: deque()
{
    if(isqempty())
    cout<<"All orders are already processed";
    else
    {   int h;
        f=(f+1)%10;
        h=que[f];
        cout<<"Order placed by id "<<h<<" processed successfully !";
    }
}

void pizza :: pending()
{   if(!isqempty())
    {
    int g;
    g=f;
    while(g!=r)
    {
        cout<<que[g]<<"->";
        g=(g+1)%10;
    }
    cout<<que[g];
    }
    else
    cout<<"There are no pending orders !";

}
