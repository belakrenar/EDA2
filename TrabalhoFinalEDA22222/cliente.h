#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
using namespace std;

class Cliente{
    static int idAtual;
    int id;
    string nome;
    string cpf;

    public:

    Cliente(int i)
      : id(i) {}

    Cliente(string x, string y)
      : id(idAtual++), nome(x), cpf(y) {}

    Cliente(int i, const string& x, const string& y) 
      : id(i), nome(x), cpf(y) {}
    

    static Cliente fromString(const string& linha){
      stringstream ss(linha);
      int id;
      string nome, cpf;
      ss >> id >> nome >> cpf;

      if (id >= idAtual) {
        idAtual = id + 1;
      }

      return Cliente(id, nome, cpf);
    }

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

    string getNome() const{
      return nome;
    }

    string getCpf() const{
      return cpf;
    }

    friend ostream& operator<<(ostream& os, const Cliente& c) {
        os << c.id << " " << c.nome << " " << c.cpf;
        return os;
    }

    string toString() const {
        stringstream ss;
        ss << "ID: " << id << "\n"
           << "Nome: " << nome << "\n"
           << "CPF: " << cpf;
        return ss.str();
    }

};

int Cliente::idAtual = 0;

#endif