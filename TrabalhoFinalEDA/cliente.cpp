/*#include <iostream>
using namespace std;

class Cliente{
    static int idAtual;
    const int id;
    string nome;
    string cpf;

    public:

    Cliente(string x, string y){
      id(idAtual++);
      nome = x;
      cpf = y;
    }

    int getId(){
      return id;
    }

};

int Cliente::idAtual = 0;*/

#include "cliente.h"

int Cliente::idAtual = 0;

Cliente::Cliente(std::string nome, std::string cpf)
    : id(idAtual++), nome(nome), cpf(cpf) {}

int Cliente::getId() const {
    return id;
}

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getCpf() const {
    return cpf;
}
