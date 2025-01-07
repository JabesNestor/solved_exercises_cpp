# include <iostream>

using namespace std;

/**
 * @brief Main function to calculate the final grade based on practice, theory, and participation scores.
 *
 * This program prompts the user to input their scores for practice, theory, and participation.
 * It then calculates the final grade by applying the following weightings:
 * - Practice: 30%
 * - Theory: 60%
 * - Participation: 10%
 *
 * The final grade is the sum of the weighted scores.
 *
 * @return int Returns 0 upon successful execution.
 */
int main(){
    float practica, teoria, participacion, nota_final = 0;

    cout<<"Digite la nota de practica: "; cin>>practica;
    cout<<"Digite la nota teorica: "; cin>>teoria;
    cout<<"Digite la nota de participacio: "; cin>>participacion;

    practica *= 0.30;
    teoria *= 0.60;
    participacion *= 0.10;

    nota_final = practica + teoria + participacion;

    cout << "\nLa nota final es de: " << nota_final << endl;
    return 0;
}