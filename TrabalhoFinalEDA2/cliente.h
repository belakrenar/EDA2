#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include <iostream>
using namespace std;

class Cliente{
    static int idAtual;
    const int id;
    string nome;
    string cpf;

    public:

    Cliente(string x, string y)
      : id(idAtual++), nome(x), cpf(y) {}

    Cliente& operator=(const Cliente& outro) {
    nome = outro.nome;
    cpf = outro.cpf;
    return *this;
    }
  

    int getId(){
      return id;
    }

    string getNome(){
      return nome;
    }

    string getCpf(){
      return cpf;
    }

};

int Cliente::idAtual = 0;

#endif