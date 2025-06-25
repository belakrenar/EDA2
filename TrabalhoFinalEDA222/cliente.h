#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include <iostream>
using namespace std;

class Cliente{
    static int idAtual;
    int id;
    string nome;
    string cpf;

    public:

    Cliente()
      : id(-1), nome(""), cpf("") {}

    Cliente(string x, string y)
      : id(idAtual++), nome(x), cpf(y) {}

    Cliente& operator=(const Cliente& outro) {
      if(this != &outro){
        id = outro.id;
        nome = outro.nome;
        cpf = outro.cpf;
      }
    return *this;
    }

    int getId() const{
      return id;
    }

    string getNome(){
      return nome;
    }

    string getCpf(){
      return cpf;
    }

    void toString(ostream& os){
    os << "\nID: " << id << endl
       << "Nome: " << nome << endl
       << "CPF: " << cpf << endl;
  }

};

inline ostream& operator<<(ostream& os, Cliente c) {
    c.toString(os);
    return os;
}

int Cliente::idAtual = 0;

#endif