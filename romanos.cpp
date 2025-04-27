#include "romanos.hpp"
#include <bits/stdc++.h>
using namespace std;
int romanos_para_decimal(char const * num_romano)
{
  map<string, int> dict_numeros = numeros_romanos();
  if (strlen(num_romano) == 1){
    auto it = dict_numeros.find(num_romano);
    if (it != dict_numeros.end()){
      return dict_numeros[num_romano];
    } else {
      return -1;
    }
  } else {
    int contador = 0;
    for(int i=0; i<strlen(num_romano); i++){
      string atual(1, num_romano[i]);
      int valor_decimal = dict_numeros[atual];
      contador+=valor_decimal;
    }
    return contador;
  }
  return 0; 
}
map<string, int> numeros_romanos(){
  map<string, int> numeros_romanos;
  numeros_romanos["I"] = 1;
  numeros_romanos["V"] = 5;
  numeros_romanos["X"] = 10;
  numeros_romanos["L"] = 50;
  numeros_romanos["C"] = 100;
  numeros_romanos["D"] = 500;
  numeros_romanos["M"] = 1000;
  return numeros_romanos;
}
 