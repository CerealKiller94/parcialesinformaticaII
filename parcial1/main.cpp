#include <iostream>
#include <math.h>

using namespace std;

float tiempoCaida(float vo, float angulo, float altura);
float desplazamientoMaximo(float tmax, float xInicial, float vo, float angulo);
bool registrarDisparo(float distancia, float altura);

int main()
{
    float distanciaOfensivoDefensivo = 0;
    float alturaOfensivo = 0;
    bool esPeligroso = true;
    cout << "Escriba la distancia a la que estamos del enemigo" << endl;
    cin >> distanciaOfensivoDefensivo;
    cout << "Escriba la altura del disparo enemigo " << endl;
    cin >> alturaOfensivo;

    esPeligroso = registrarDisparo(distanciaOfensivoDefensivo, alturaOfensivo);
    if(!esPeligroso){
        cout << "Disparo sin consecuencias para nosotros " << endl;
    }
}

bool registrarDisparo(float distancia, float altura){

    float anguloOfensivo = 0;
    float velocidadInicialEnemigo = 0;
    float tcaida = 0;
    float xmax = 0;

    cout << "Escriba la velocidad inicial del lanzamiento enemigo " << endl;
    cin >> velocidadInicialEnemigo;

    cout << "Escriba el angulo del enemigo en grados" << endl;
    cin >> anguloOfensivo;

    tcaida = tiempoCaida(velocidadInicialEnemigo, anguloOfensivo, altura);
    xmax = desplazamientoMaximo(tcaida, 0.0, velocidadInicialEnemigo, anguloOfensivo);
    if(xmax < distancia*0.95){
        return false;
    }
    return true;
}


float tiempoCaida(float vo, float angulo, float altura){
    float a = -4.9;
    float b = vo*sin(angulo*3.14159/180);
    float c = altura;

    float t1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
    float t2 = (-b - sqrt(pow(b,2) - 4*a*c))/(2*a);

    if(t1 > 0){
        return t1;
    }
    return t2;
}

float desplazamientoMaximo(float tmax, float xInicial, float vo, float angulo){
    return xInicial + vo*cos(angulo*3.14159/180)*tmax;
}
