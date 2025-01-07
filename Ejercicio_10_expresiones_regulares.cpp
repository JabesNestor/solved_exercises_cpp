#include <iostream> 
#include <math.h> 
 using namespace std;

 int main(){
    float a,b,c, x_1 = 0,x_2 = 0;
    cout<<"Escribe el valor a: ";cin>>a;
    cout<<"Escribe el valor b: ";cin>>b;
    cout<<"Escribe el valor c: ";cin>>c;
    
    x_1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    x_2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    cout << "X_1: " << x_1 << endl;
    cout << "X_2: " << x_2 << endl;


    return 0;
 }