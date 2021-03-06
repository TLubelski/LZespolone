#include "LZespolona.hh"
#include <cmath>


/* Basic*/

LZespolona utworzLZ(double _re, double _im)
{
  LZespolona temp;
  temp.re = _re;
  temp.im = _im;
  return temp;
}


/*Op strumieniowe*/
 
std::istream & operator >> (std::istream & strm, LZespolona & z)
{
  char znak; //tymczasowa zmienna znaku
  
  strm >> znak;     //Sprawdzenie (
  if( znak != '(' )
    strm.setstate(std::ios::failbit);
  
  strm >> z.re;     //wczytanie Re
  
  strm >> znak;     //Sprawdzenie znaku + -
  if( znak != '+' && znak != '-' )
    strm.setstate(std::ios::failbit);
  
  strm >> z.im;    //wczytanie Im
  if( znak  == '-' )
    z.im = -z.im;
  
  strm >> znak;  //Sprawdzenie i
  if( znak != 'i')
    strm.setstate(std::ios::failbit);
  
  strm >> znak;  //Sprawdzenie )
  if( znak != ')')
    strm.setstate(std::ios::failbit);

  return strm;
}


std::ostream & operator << (std::ostream & strm, const LZespolona & z)
{
  strm << "(" << z.re << std::showpos << z.im << std::noshowpos << "i)"; 
  return strm;
}


/*Op Wlasne*/

double modul(LZespolona z)
{
  return sqrt( z.re * z.re + z.im * z.im );
}


LZespolona sprzez(LZespolona z)
{
  z.im *= (-1);
  return z;
}  


/*Op Arytmetyczne*/

LZespolona  operator + (LZespolona  z1,  LZespolona  z2)
{
  LZespolona  Wynik;

  Wynik.re = z1.re + z2.re;
  Wynik.im = z1.im + z2.im;
  return Wynik;
}


LZespolona  operator - (LZespolona  z1,  LZespolona  z2)
{
  LZespolona  Wynik;

  Wynik.re = z1.re - z2.re;
  Wynik.im = z1.im - z2.im;
  return Wynik;
}


LZespolona  operator * (LZespolona  z1,  LZespolona  z2)
{
  LZespolona  Wynik;

  Wynik.re = z1.re * z2.re - z1.im * z2.im;
  Wynik.im = z1.re * z2.im + z1.im * z2.re;
  return Wynik;
}


LZespolona  operator / (LZespolona  z1,  double  dzielnik)
{
  LZespolona  Wynik;
  
  if(dzielnik == 0)
  {
    std::cerr << "BLAD: Dzielenie przez 0 ";
    exit(0);
  }

  Wynik.re = z1.re / dzielnik;
  Wynik.im = z1.im / dzielnik;
  return Wynik;
  
}


LZespolona  operator / (LZespolona  z1,  LZespolona  z2)
{
  return ( z1 * sprzez(z2) ) / ( modul(z2) * modul(z2) ); 
}


/*Op Logiczne*/

bool operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  if( Skl1.re == Skl1.re && Skl1.im == Skl2.im )
    return true;
  else
    return false;
}


bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  return !(Skl1 == Skl2);
}
