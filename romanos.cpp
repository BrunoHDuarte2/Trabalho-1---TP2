// Copyright 2025 Bruno Henrique Duarte
#include "romanos.hpp"
#include <bits/stdc++.h>
#include <string>
#include <map>
int romanos_para_decimal(char const * num_romano) {
  std::map<std::string, int> dict_numeros = numeros_romanos();
  // Para os dois primeiros caso de teste se avalia a string de somente um char;
  if (strlen(num_romano) == 1) {
    // Se o algarismo passado faz parte do mapeamento feito, retorna o valor.
    // Senão, o algarismo não existe
    auto it = dict_numeros.find(num_romano);
    if (it != dict_numeros.end()) {
      return dict_numeros[num_romano];
    } else {
      return -1;
    }
  } else {
    // Para o terceiro e quarto caso de teste
    int contador = 0;
    // Se itera sobre os char da string passada e convertendo para decimal.
    // Se o valor em num_romano[i] for menor que num_romano[i+1]
    // Então se soma ao contador num_romano[i+1]-num_romano[i];
    for (int i = 0; i < strlen(num_romano); i++) {
      std::string atual(1, num_romano[i]);
      std::string prox(1, num_romano[i+1]);
      int valor_decimal_atual = dict_numeros[atual];
      int valor_decimal_prox = dict_numeros[prox];
      if (valor_decimal_prox > valor_decimal_atual) {
        contador += (valor_decimal_prox-valor_decimal_atual);
        i += 1;
      } else {
        contador+=valor_decimal_atual;
      }
    }
    return contador;
  }
}
// Função para retornar o mapeamento dos algarismos romanos em valores decimais.
std::map< std::string, int > numeros_romanos() {
  std::map<std::string, int> numeros_romanos;
  numeros_romanos["I"] = 1;
  numeros_romanos["V"] = 5;
  numeros_romanos["X"] = 10;
  numeros_romanos["L"] = 50;
  numeros_romanos["C"] = 100;
  numeros_romanos["D"] = 500;
  numeros_romanos["M"] = 1000;
  return numeros_romanos;
}
