#include <iostream>
#include <math.h>
#define PI 3.14159265359
using namespace std;

float distanciaEuclidiana(float x1, float x2, float y1, float y2);
float coordx(float xo, float vo, float t, float angulo);
float coordy(float yo, float vo, float t, float angulo);
void disparosOfensivos(float d, float yo, float yod);
void mostrarInforme(float t, float angulo, float rapidezInicial, float xofensivo, float yofensivo);
void disparosDefensivos(float d, float yo, float yod);

int main()
{
    float d; //Supondre esta distancia siempre constante para cada ejecucion
    float alturaenemigo; //Supondre esta altura siempre constante para cada ejecucion
    float alturaNuestra;

    //Obtener datos iniciales del espia
    cout << "Distancia horizontal a la que esta el enemigo de nosotros: " << endl;
    cin >> d;
    cout << "Altura respecto al suelo del canhon enemigo" << endl;
    cin >> alturaenemigo;
    cout << "Altura respecto al suelo de nuestro canhon" << endl;
    cin >> alturaNuestra;

    //Generar al menos tres disparos que comprometan la integridad del cañon defensivo
    disparosOfensivos(d, alturaenemigo, alturaNuestra);

    /*Generar al menos tres disparos defensivos que compromentan la integridad del cañon ofensivo
     * Seran aquellos enviados por el cañon defensivo que terminen a una distancia de no más de 0.025d
     * del cañon enemigo
    */
    disparosDefensivos(d, alturaenemigo, alturaNuestra);
    return 0;
}

void disparosOfensivos(float d, float yo, float yod){
    float anguloEnemigo = 45; //Para la simulacion iniciare con el angulo que da mas alcance horizontal
    float rapidezInicial = 35.4;
    short int contDisparosCorrectos = 0;
    float xdofensivo = 0;
    float ydofensivo = 0;
    while(contDisparosCorrectos < 3){ //Simulare 3 disparos ofensivos validos
        for(int t=3; t<100; t++){
            /*Supondre que el minimo tiempo minimo que le toma al disparo enemigo
             * llegar a nosotros es 3 segundos y el maximo es 200s o 3.3 minutos
            */
            xdofensivo = coordx(0, rapidezInicial, t, anguloEnemigo);
            ydofensivo = coordy(yo, rapidezInicial, t, anguloEnemigo);
            if(distanciaEuclidiana(xdofensivo, d, ydofensivo, yod) <= 0.05*d){
                /*Si la distancia del disparo ofensivo respecto a nuestro cañon
                 * es menor o igual a 0.05*d (rango de accion de la bala)
                 * ese disparo representa un problema
                */
                contDisparosCorrectos += 1;
                cout << contDisparosCorrectos << endl;
                mostrarInforme(t, anguloEnemigo, rapidezInicial, xdofensivo, ydofensivo);
                break;
            }
      }
        if(anguloEnemigo < 90){
            anguloEnemigo += 2;
        }else{
            anguloEnemigo += 45;
            rapidezInicial += 3;
        }
    }
}

void mostrarInforme(float t, float angulo, float rapidezInicial, float xofensivo, float yofensivo){
    cout << "El disparo ofensivo peligroso estara en la posicion \n"
         <<"(" << xofensivo<<","<<yofensivo << ")\n"
        << " Tiempo de llegada al punto respecto al sistema defensivo: " << t-2 << " segundos\n"
        << " Angulo de lanzamiento: " << angulo
        << " Rapidez de lanzamiento: " << rapidezInicial << endl;
}


float distanciaEuclidiana(float x1, float x2, float y1, float y2){

    return sqrt(pow((x1 - x2), 2) + pow((y1-y2),2));
}

float coordx(float xo, float vo, float t, float angulo){
    return xo + vo*cos(angulo*PI/180)*t;
}

float coordy(float yo, float vo, float t, float angulo){
    return yo + vo*sin(angulo*PI/180)*t - 0.5*9.81*pow(t,2);
}
