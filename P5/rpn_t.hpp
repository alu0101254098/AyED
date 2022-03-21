// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private:
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    //modificacion

    int suma = q.get_sum_even_();
    cout << "La suma de todos los elementos pares es: " << suma << endl;

    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c))
		{
		  int i = c - '0';

      stack_.push(i);

		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
		}
		else {
		  cout << " (es un operador)" << endl;

      operate_(c);

		}
	}
  const int result = stack_.top();
  stack_.pop();

  return result;


}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c' );

  int a, b = 0;
  int result = 0;

  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){

    cout << "   Sacamos de la pila un operando: " << endl;

    b = stack_.top();
    stack_.pop();

    cout << "   Sacamos de la pila otro operando: " << endl;

    a = stack_.top();
    stack_.pop();
  }

  else{

    cout << "   Sacamos de la pila un operando: " << endl;

    a = stack_.top();
    stack_.pop();

  }

	switch (c)
	{
	  case '+':
    result = a + b;
              break;

    case '-':
    result = a - b;
              break;

    case '*':
    result = a * b;
              break;

    case '/':
    result = a / b;
              break;

    case '^':
    result = pow(a, b);
              break;

    case 'r':
    result = sqrt(a);
              break;

    case 'l':
    result = log2(a);
              break;

    case 'c':
    result = pow(a, 2);
              break;

	}


	cout << "   Metemos en la pila el resultado: " << endl;

  stack_.push(result);
}

}
