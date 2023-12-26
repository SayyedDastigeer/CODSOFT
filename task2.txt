#include<iostream>

using namespace std;

 float addition(float a, float b){
    return a+b;
}
float subtract(float a, float b){
    return a-b;
}

float multiply(float a, float b){
    return a*b;
}
float divide (float a, float b){
    return a/b;
}

int main(){
int sw,a,b;
do{
    cout<<"enter what you want to perform :\n 1.add(+)\n 2.subtract(-)\n 3.multiply(*)\n 4.divide(/)\n 5.exit\n";
    cin>>sw;
    if(sw==5){
        break;
    }
    cout<<"enter first number : \n";
    cin>>a;
    cout<<"enter second number : \n";
    cin>>b;
    
    switch(sw){
        case 1: 
        cout<<addition(a,b)<<endl;
        break;
        case 2:
        cout<<subtract(a,b)<<endl;
        break;
        case 3:
        cout<<multiply(a,b)<<endl;
        break;
        case 4:
        cout<<divide(a,b)<<endl;
        break;
        case 5:
        break;
        default :
        cout<<"invalid choice\n";
    }
}while(sw!=5);


return 0;
}