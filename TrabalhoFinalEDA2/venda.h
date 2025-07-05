#ifndef VENDA_H
#define VENDA_H

#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

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

  Venda(int i, const Cliente& c, const Funcionario& f, const Produto& p, string d)
    : id(i), cliente(c), vendedor(f), produtoComprado(p), data(d) {}

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

static Venda fromString(const string& linha) {
    stringstream ss(linha);

    int idVenda;

    int idCliente;
    string nomeCliente, cpfCliente;
    
    int idFuncionario;
    string nomeFuncionario, cpfFuncionario, cargo;
    int salario;

    int idProduto, paginas;
    string titulo, autor, editora, dataPubli, tipoStr;
    double preco;

    string dataVenda;

    ss >> idVenda
       >> idCliente >> nomeCliente >> cpfCliente
       >> idFuncionario >> nomeFuncionario >> cpfFuncionario
       >> cargo >> salario
       >> idProduto >> titulo >> autor >> editora >> preco >> paginas >> dataPubli >> tipoStr
       >> dataVenda;

    Cliente cliente(idCliente, nomeCliente, cpfCliente);
    Funcionario funcionario(idFuncionario, nomeFuncionario, cpfFuncionario, cargo, salario);
    Tipo tipoProduto = Produto::tipoFromString(tipoStr);
    Produto produto(idProduto, titulo, autor, editora, preco, paginas, dataPubli, tipoProduto);

    if (idVenda >= idAtual) idAtual = idVenda + 1;

    return Venda(idVenda, cliente, funcionario, produto, dataVenda);
}


friend ostream& operator<<(ostream& os, const Venda& v) {
    os << v.id << " "
       << v.cliente.getId() << " " << v.cliente.getNome() << " " << v.cliente.getCpf() << " "
       << v.vendedor.getId() << " " << v.vendedor.getNome() << " " << v.vendedor.getCpf() << " "
       << v.vendedor.getCargo() << " " << v.vendedor.getSalario() << " "
       << v.produtoComprado.getId() << " " << v.produtoComprado.getTitulo() << " "
       << v.produtoComprado.getAutor() << " " << v.produtoComprado.getEditora() << " "
       << v.produtoComprado.getPreco() << " " << v.produtoComprado.getPaginas() << " "
       << v.produtoComprado.getDataPublicacao() << " " << v.produtoComprado.getTipoString() << " "
       << v.data;
    return os;
}


  string toString() const{
  stringstream ss;
  ss << "\nID: " << id << endl
     << "Cliente: " << cliente.getNome() << endl
     << "Vendedor: " << vendedor.getNome() << endl
     << "Produto: " << produtoComprado.getTitulo()  << " | Categoria: " << produtoComprado.getTipoString() << endl
     << "Valor: R$" << produtoComprado.getPreco() << endl
     << "Data: " << data << endl;

     return ss.str();
  }

};

int Venda::idAtual = 0;

#endif