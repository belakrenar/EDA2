#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <iostream>
using namespace std;

class Funcionario{
    static int idAtual;
    int id;
    string nome;
    string cpf;
    string cargo;
    int salario;

    public:

    Funcionario(int i)
      : id(i) {}

    Funcionario(string x, string y, string z, int s)
      : id(idAtual++), nome(x), cpf(y), cargo(z), salario(s) {}

    Funcionario& operator=(const Funcionario& outro) {
    if(this != &outro){
      id = outro.id;
      nome = outro.nome;
      cpf = outro.cpf;
      cargo = outro.cargo;
      salario = outro.salario;
    }
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

    string getCargo(){
      return cargo;
    }

    int getSalario(){
      return salario;
    }

    void toString(ostream& os){
      os << "\nID: " << id << endl
        << "Nome: " << nome << endl
        << "CPF: " << cpf << endl
        << "Cargo: " << cargo << endl
        << "Salario: " << salario << endl;
    }

};

inline ostream& operator<<(ostream& os, Funcionario f) {
    f.toString(os);
    return os;
}

int Funcionario::idAtual = 0;

#endif