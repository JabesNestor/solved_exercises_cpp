#include <iostream>

using namespace std;

int main(){
  float nota_1, nota_2, nota_3 ,nota_4,cantidad_studiantes = 4, sumatoria=0,media;

  cout<<"Digita la nota 1: ";cin>>nota_1;  
  cout<<"Digita la nota 2: ";cin>>nota_2;  
  cout<<"Digita la nota 3: ";cin>>nota_3;  
  cout<<"Digita la nota 4: ";cin>>nota_4;  

   sumatoria = nota_1 + nota_2 + nota_3 + nota_4;
   media = sumatoria/cantidad_studiantes;
   cout<<"\nLa nota media: "<<media<<endl;
 
}