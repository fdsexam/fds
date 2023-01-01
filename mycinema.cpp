#include<iostream>
#include<string>
using namespace std;


class node{  
     public:
        node *prev;
        
        //data
        int flag;
        int seatno;
        string moviename;
        float price;

        node *next;
    
};


class cinemax{

    public:
    node *arr[10]; //global

    public:
    cinemax()
    {
        for(int i=0;i<10;i++)
        {
            arr[i]=0;
        }
    }

    public:
        void create(){
            //arr[i] = head;
            node* cur;
            
            for(int i=0; i<10; i++){

                for(int j=0; j<7; j++){

                    node *temp = new node;
                    temp->flag = 0;
                    temp->seatno = j+1;
                    temp->moviename = "Ram Sita";
                    temp->price = 100;

                    if(arr[i] == NULL){
                        arr[i] = temp;
                        cur = temp;
                    }
                    else{
                        cur->next = temp;
                        temp->prev = cur;
                        temp->next = arr[i];
                        arr[i]-> prev = temp;
                        cur = temp;
                    }
                }

            }
        }

    public: 
        void display(){
            for(int i=0; i<10; i++){
                node *temp = arr[i];

                cout<<"Row :"<<i+1<<"\n";

                for(int j=0; j<7; j++){
                    cout<<temp->seatno<< "|" << temp->flag << "|" << temp->moviename <<"|" << temp->price << "|" <<endl;
                    
                    temp = temp->next;
                }
            }
        }

    public:
        void avaiableSeats(){
            for(int i=0; i<10; i++){
                node* temp = arr[i];

                cout<<"Row :"<<i+1<<"\n";

                for(int j=0; j<7; j++){
                    
                    if(temp->flag == 0) cout<<temp->seatno<< "|" << temp->flag << "|" << temp->moviename <<"|" << temp->price << "|" <<endl;
                    
                    temp = temp->next;

                }
            }
        }

    public:
        void bookSeat(){
            int row;
            int seatNo;

            cout<<"Enter the Row No :"<<endl;
            cin>>row;
            cout<<"Enter the Seat No :"<<endl;
            cin>>seatNo;

            if(row > 10 || row <= 0){
                cout<<"Plase Enter the Row No less than or Equal 10 and Greater than or Equal to 1";
                
                return;
            }

            if(seatNo > 7 || seatNo <= 0){
                cout<<"Please Enter the seatNo less than or Equal 7 and greater than Equal to 1";

                return;
            }

            node* temp = arr[row - 1];

            for(int i=0; i<seatNo - 1; i++){
                temp = temp->next;
            }
            
            if(temp->flag == 1){
                cout<<"Seat Is already Booked"<<endl;
                return;
            }
            else{
                temp->flag = 1;
                cout<<"Seat Booked Succesfully!"<<endl;
            }
        }



     public:
        void cancleSeat(){
            int row;
            int seatNo;

            cout<<"Enter the Row No :"<<endl;
            cin>>row;
            cout<<"Enter the Seat No :"<<endl;
            cin>>seatNo;

            if(row > 10 && row <= 0){
                cout<<"Plase Enter the Row No less than or Equal 10 and Greater than or Equal to 1";
                
                return;
            }

            if(seatNo > 7 && seatNo <= 0){
                cout<<"Please Enter the seatNo less than or Equal 7 and greater than Equal to 1";

                return;
            }

            node* temp = arr[row - 1];
            for(int i=0; i<seatNo - 1; i++){
                temp = temp->next;
            }
            
            if(temp->flag == 0){
                cout<<"Seat is Not Booked"<<endl;
                return;
            }
            else{
                temp->flag = 0;
                cout<<"Seat is Cancaled"<<endl;
            }
        }
};


int main(){

    cinemax c;
    c.create();
    c.display();
    c.bookSeat();
    c.avaiableSeats();
    c.cancleSeat();
    c.avaiableSeats();
    return 0;
}
