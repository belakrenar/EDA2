#ifndef SISTEMA_H
#define SISTEMA_H

#include "arvore.h"
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include <iostream>

using namespace std;

class Sistema{
  Arvore<Cliente> arvoreClientes;
  Arvore<Funcionario> arvoreFuncionarios;
  Arvore<Produto> arvoreEstoque;

  public:

  Sistema(){}

  //arvore de clientes

  void cadastraCliente(const Cliente& cliente){
    arvoreClientes.inserir(cliente);
  }

  void removerCliente(const Cliente& cliente){
    arvoreClientes.remover(cliente);
  }

  void buscarCliente(const Cliente& cliente){ //busca por id
    arvoreClientes.buscar(cliente);
  }

  //arvore de funcionarios

  void cadastrarFuncionario(const Funcionario& funcionario){
    arvoreFuncionarios.inserir(funcionario);
  }

  void removerFuncionario(const Funcionario& funcionario){
    arvoreFuncionarios.remover(funcionario);
  }

  void buscarFuncionario(const Funcionario& funcionario){ //busca por id
    arvoreFuncionarios.buscar(funcionario);
  }

  //arvore do estoque de produtos

  void cadastrarProduto(const Produto& produto){
    arvoreEstoque.inserir(produto);
  }

  void removerProduto(const Produto& produto){
    arvoreEstoque.remover(produto);
  }

  void buscarProduto(const Produto& produto){ //busca por id
    arvoreEstoque.buscar(produto);
  }

  void listarProdutos(){
    cout << "PRODUTOS NO ESTOQUE: \n";
    arvoreEstoque.toString();
  }

};

#endif