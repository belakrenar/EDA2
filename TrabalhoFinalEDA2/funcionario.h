#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
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

    Funcionario(int i, string x, string y, string z, int s)
      : id(i), nome(x), cpf(y), cargo(z), salario(s) {}

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

    int getId() const{
      return id;
    }

    string getNome() const{
      return nome;
    }

    string getCpf() const{
      return cpf;
    }

    string getCargo() const{
      return cargo;
    }

    int getSalario() const{
      return salario;
    }

    static Funcionario fromString(const string& linha){
      stringstream ss(linha);
      int id, salario;
      string nome, cpf, cargo;
      ss >> id >> nome >> cpf >> cargo >> salario;

      if (id >= idAtual) {
        idAtual = id + 1;
      }

      return Funcionario(id, nome, cpf, cargo, salario);
    }

    friend ostream& operator<<(ostream& os, const Funcionario& f) {
        os << f.id << " " << f.nome << " " << f.cpf << " " << f.cargo << " " << f.salario;
        return os;
    }

    string toString () const{
      stringstream ss;
      ss << "\nID: " << id << endl
        << "Nome: " << nome << endl
        << "CPF: " << cpf << endl
        << "Cargo: " << cargo << endl
        << "Salario: " << salario << endl;

      return ss.str();
    }

};

int Funcionario::idAtual = 0;

#endif