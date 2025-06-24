// cliente.h
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
    static int idAtual;      
    const int id;            
    std::string nome;
    std::string cpf;

public:
    Cliente(std::string nome, std::string cpf);

    int getId() const;
    std::string getNome() const;
    std::string getCpf() const;
};

#endif
