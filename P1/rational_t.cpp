// AUTOR: Jonathan Martínez Pérez
// FECHA: 26/02/2020
// EMAIL: alu010124098@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_tl

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos

// pauta de estilo [83]: tipo retornado en línea anterior al método
int
rational_t::get_num() const
{
  return num_;
}



int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{ 

bool result = fabs(value() - r.value()) < precision;
return result;

}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{

bool result = value() - r.value() > precision;
return result;

}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{

bool result = r.value() - value() > precision;
return result;

}


// operaciones
rational_t
rational_t::add(const rational_t& r)
{

rational_t suma(num_ * r.get_den() + den_ * r.get_num(), den_ * r.get_den());
return suma;

}



rational_t
rational_t::substract(const rational_t& r)
{

rational_t resta(num_ * r.get_den() - den_ * r.get_num(), den_ * r.get_den());
return resta;

}



rational_t
rational_t::multiply(const rational_t& r)
{

rational_t multiplicacion(num_ * r.get_num(), den_ * r.get_den());
return multiplicacion;

}



rational_t
rational_t::divide(const rational_t& r)
{

rational_t division(num_ * r.get_den(), den_ * r.get_num());
return division;

}
bool
rational_t::is_indet()
{

if(den_ != 0)
return 0;


}





// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
