#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
    static int idAtual;
    const int id;
    std::string nome;
    std::string cpf;
    std::string cargo;
    int salario;

public:
    Funcionario(std::string nome, std::string cpf, std::string cargo, int salario);

    int getId() const;
    std::string getNome() const;
    std::string getCpf() const;
    std::string getCargo() const;
    int getSalario() const;
};

#endif
