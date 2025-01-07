# include<iostream>

using namespace std; 

int main(){
  int precio_producto = 0; 
  int porcentaje = 16;
  int iva = 0;
  cout<<"Digita el precio del producto "; cin>>precio_producto;

  iva = precio_producto * porcentaje/100;

  cout<<"\nPrecio del producto "<<precio_producto<<endl;
  cout<<"El producto con IVA es: "<<(iva + precio_producto)<<endl;
   

  return 0;
}
