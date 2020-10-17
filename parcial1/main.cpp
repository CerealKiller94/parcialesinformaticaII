#include <iostream>

using namespace std;



int main()
{
    float anguloOfensivo = 0;
    float alturaOfensivo = 0;
    float velocidadInicialEnemigo = 0;
    float distanciaOfensivoDefensivo = 0;

    cout << "Escriba la altura del disparo enemigo " << endl;
    cin >> alturaOfensivo;

    cout << "Escriba la velocidad inicial del lanzamiento enemigo " << endl;
    cin >> velocidadInicialEnemigo;

    cout << "Escriba el angulo del enemigo en grados" << endl;
    cin >> anguloOfensivo;

    cout << "Escriba la distancia a la que estamos del enemigo" << endl;
    cin >> distanciaOfensivoDefensivo;
    return 0;
}
