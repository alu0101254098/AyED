// AUTOR:Jonathan Martínez Pérez
// FECHA: 26/05/2020
// EMAIL: alu0101254098@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 6
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include <iostream>
#include "maze_t.hpp"

using namespace std;

int main()
{
  maze_t M;

  cin >> M;

  cout << M << endl;

  if (M.solve())
  {
    cout << "¡¡ Se ha encontrado una salida al laberinto !!" << endl;
    cout << M << endl;
  }
  else
    cout << "No se ha podido encontrar la salida del laberinto..." << endl;

  return 1;
}
