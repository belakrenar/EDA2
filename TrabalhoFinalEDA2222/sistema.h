#ifndef SISTEMA_H
#define SISTEMA_H

#include "arvore.h"
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include "venda.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Sistema{
  Arvore<Cliente> clientesCadastrados;
  Arvore<Funcionario> funcionariosCadastrados;
  Arvore<Produto> estoque;
  Arvore<Venda> historicoVendas;
  

  public:

  Sistema(){}

  //arvore de clientes

  void cadastrarCliente(const Cliente& cliente){
    clientesCadastrados.inserir(cliente);
  }

  void removerCliente(const Cliente& cliente){
    clientesCadastrados.remover(cliente);
  }
  
  Cliente* buscarCliente(int id){ //busca por chave primaria / retorna o cliente com esse id
    Cliente procurado(id);
    return clientesCadastrados.buscar(procurado);
  }

  void exibirCliente(const Cliente& cliente){
    cout << cliente << endl;
  }

  void listarClientes(){
    clientesCadastrados.toString();
  }

  //arvore de funcionarios

  void cadastrarFuncionario(const Funcionario& funcionario){
    funcionariosCadastrados.inserir(funcionario);
  }

  void removerFuncionario(const Funcionario& funcionario){
    funcionariosCadastrados.remover(funcionario);
  }

  Funcionario* buscarFuncionario(int id){ //busca por chave primaria / retorna o funcionario com esse id
    Funcionario procurado(id);
    return funcionariosCadastrados.buscar(procurado);
  }

  void listarFuncionarios(){
    funcionariosCadastrados.toString();
  }

  //arvore do estoque de produtos

  void cadastrarProduto(const Produto& produto){
    estoque.inserir(produto);
  }

  void removerProduto(const Produto& produto){
    estoque.remover(produto);
  }

  Produto* buscarProduto(int id){ //busca por chave primaria / retorna o produto com esse id
    Produto procurado(id);
    return estoque.buscar(procurado);
  }

  Produto* buscarTitulo(string titulo){ //retorna produto com esse titulo BUSCA SECN
    return estoque.buscarSecundaria<std::string>(
    std::function<std::string(const Produto&)>(
        [](const Produto& p) { return p.getTitulo(); }
    ),
    titulo
  );
  }

  Tipo stringTipo(string t){ //recebe uma string revista e retorna o tipo revista
    string tipo = t; 
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);

    if (tipo == "livro") return Tipo::LIVRO;
    if (tipo == "revista") return Tipo::REVISTA;
    if (tipo == "hq") return Tipo::HQ;

    throw invalid_argument("Tipo de produto inválido");
  }

  void exibirProduto(const Produto& produto){ //exibe produto especifico
    cout << produto << endl;
  }

  void listarProdutos(){ //lista todos os produtos no estoque
    estoque.toString();
  }

  // arvore do historico de vendas

  void cadastrarVenda(const Venda& venda){
    historicoVendas.inserir(venda);
  }

  void removerVenda(const Venda& venda){
    historicoVendas.remover(venda);
  }

  void exibirVenda(const Venda& venda){
    cout << venda << endl;
  }

  void mostrarHistoricoLivraria(){ //meio inutil 
    historicoVendas.toString(); 
  }

  //funcoes livraria

  void historicoCliente(const Cliente& cliente){ //exibe as vendas que tem esse cliente BUSCA EXAUSTIVA pq olha toda arvore
    historicoVendas.percorrer(
      [&](const Venda& venda){
        return venda.getCliente().getId() == cliente.getId();
      },
      [](const Venda& venda){
        cout << venda << endl;
      }
    );
  }

  void mostrarCategoria(string t){ //exibe todos os produtos desse tipo/categoria BUSCA EXAUSTIVA pq olha toda arvore
    try {
        Tipo tipo = stringTipo(t);

        estoque.percorrer(
            [&](const Produto& p) {
                return p.getTipo() == tipo;
            },
            [](const Produto& p) {
                cout << p << endl;
            }
        );
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
  }



};

#endif