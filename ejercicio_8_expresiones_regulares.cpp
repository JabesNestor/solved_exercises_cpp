#include <iostream>
using namespace std;

int main(){
 float  cateto_a, cateto_b, resultado=0; 
 cout<<"Escribe el valor del cateto 1: ";cin>>cateto_a; 
 cout<<"Escribe el valor del cateto 2: ";cin>>cateto_b;

 cateto_a *= 2;
 cateto_b *=2;
 resultado = cateto_a + cateto_b;
 
 cout<<"\nEl resultado es "<<resultado;

 return 0;
}