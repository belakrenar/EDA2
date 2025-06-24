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

  void cadastrarCliente(const Cliente& cliente){
    arvoreClientes.inserir(cliente);
  }

  void removerCliente(const Cliente& cliente){
    arvoreClientes.remover(cliente);
  }

  void buscarCliente(const Cliente& cliente){ //busca por id
    if(arvoreClientes.buscar(cliente)){
      cout << "\nCliente encontrado.\n";
    }else{
      cout << "\nEsse cliente não possui cadastro na livraria.\n";
    }
  }

  void listarClientes(){
    cout << "\n=== CLIENTES ===\n";
    arvoreClientes.toString();
  }

  //arvore de funcionarios

  void cadastrarFuncionario(const Funcionario& funcionario){
    arvoreFuncionarios.inserir(funcionario);
  }

  void removerFuncionario(const Funcionario& funcionario){
    arvoreFuncionarios.remover(funcionario);
  }

  void buscarFuncionario(const Funcionario& funcionario){ //busca por id
    if(arvoreFuncionarios.buscar(funcionario)){
      cout << "\nFuncionario encontrado.\n";
    }else{
      cout << "\nEsse funcionario não trabalha nessa livraria.\n";
    }
    arvoreFuncionarios.buscar(funcionario);
  }

  void listarFuncionarios(){
    cout << "\n=== FUNCIONARIOS ===\n";
    arvoreFuncionarios.toString();
  }

  //arvore do estoque de produtos

  void cadastrarProduto(const Produto& produto){
    arvoreEstoque.inserir(produto);
  }

  void removerProduto(const Produto& produto){
    arvoreEstoque.remover(produto);
  }

  void buscarProduto(const Produto& produto){ //busca por id
    if(arvoreEstoque.buscar(produto)){
      cout << "\nProduto encontrado.\n";
    }else{
      cout << "\nEsse produto não se encontra em estoque.\n";
    }
  }

  void listarProdutos(){
    cout << "\nPRODUTOS NO ESTOQUE: \n";
    arvoreEstoque.toString();
  }

};

#endif