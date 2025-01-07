#include <iostream>
using namespace std;

int main(){
    float a,b,c,d,resultado = 0;

    cout<<"Digita el valor a: "; cin>>a;
    cout<<"Digita el valor b: "; cin>>d;
    cout<<"Digita el valor c: "; cin>>c;
    cout<<"Digita el valor d: "; cin>>d;

    resultado = (a+b)/(c+d);

    cout.precision(2);
    cout<<"El resultado es de: "<<resultado<<endl;
}