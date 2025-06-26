#ifndef VENDA_H
#define VENDA_H

#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include <string>
#include <iostream>

class Venda{
  static int idAtual;
  int id;
  Cliente cliente;
  Funcionario vendedor;
  Produto produtoComprado;
  string data;

  public:

  Venda(const Cliente& c, const Funcionario& f, const Produto& p, string d)
    : id(idAtual++), cliente(c), vendedor(f), produtoComprado(p), data(d) {}

  Venda& operator=(const Venda& outro) {
    if(this != &outro){
      id = outro.id;
      cliente = outro.cliente;
      vendedor = outro.vendedor;
      produtoComprado = outro.produtoComprado;
      data = outro.data;
    }
    return *this;
  }

  int getId() const{
    return id;
  }

  Cliente getCliente() const{
    return cliente;
  }

  Funcionario getVendedor() const{
    return vendedor;
  }

  Produto getProdutoComprado() const{
    return produtoComprado;
  }

  string getData() const{
    return data;
  }

  void setCliente(const Cliente& c) {
    cliente = c;
  }

  void setVendedor(const Funcionario& f) {
    vendedor = f;
  }

  void setProdutoComprado(const Produto& p) {
    produtoComprado = p;
  }

  void setData(string d) {
    data = d;
  }


  void toString(ostream& os){
  os << "\nID: " << id << endl
     << "Cliente: " << cliente.getNome() << endl
     << "Vendedor: " << vendedor.getNome() << endl
     << "Produto: " << produtoComprado.getTitulo()  << " | Categoria: " << produtoComprado.getTipoString() << endl
     << "Valor: R$" << produtoComprado.getPreco() << endl
     << "Data: " << data << endl;
  }

};

inline ostream& operator<<(ostream& os, Venda v) {
    v.toString(os);
    return os;
}

int Venda::idAtual = 0;

#endif