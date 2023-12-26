#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
srand((unsigned int) time(NULL));

int no=rand()%100;
int guess=0;


do{
    cout<<"guss the number between 0-99 \n";
cin>>guess;
    if(guess>no){
        cout<<"to high!"<<endl;
    }
    else if(guess<no){
        cout<<"to low!"<<endl;

    }
    else{
        cout<<"you won"<<endl;
    }
}while(guess != no);

return 0;
}