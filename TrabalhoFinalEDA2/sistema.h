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

  Sistema() {
    inicializarArvoreComArquivo(clientesCadastrados, "clientes.txt");
    inicializarArvoreComArquivo(funcionariosCadastrados, "funcionarios.txt");
    inicializarArvoreComArquivo(estoque, "produtos.txt");
    inicializarArvoreComArquivo(historicoVendas, "vendas.txt");
  } 

  //arvore de clientes

  void cadastrarCliente(const Cliente& cliente){
    clientesCadastrados.inserir(cliente);
    clientesCadastrados.salvarEmArquivo("clientes.txt");
  }

  void removerCliente(const Cliente& cliente){
    clientesCadastrados.remover(cliente);
    clientesCadastrados.salvarEmArquivo("clientes.txt");
  }
  
  Cliente* buscarCliente(int id){ //busca por chave primaria / retorna o cliente com esse id
    Cliente procurado(id);
    return clientesCadastrados.buscar(procurado);
  }

  void exibirCliente(const Cliente& cliente){ //exibe um cliente específico
    cout << cliente.toString() << endl;
  }

  void listarClientes(){ //lista todos os clientes cadastrados
    clientesCadastrados.toString();
  }

  //arvore de funcionarios

  void cadastrarFuncionario(const Funcionario& funcionario){
    funcionariosCadastrados.inserir(funcionario);
    funcionariosCadastrados.salvarEmArquivo("funcionarios.txt");
  }

  void removerFuncionario(const Funcionario& funcionario){
    funcionariosCadastrados.remover(funcionario);
    funcionariosCadastrados.salvarEmArquivo("funcionarios.txt");
  }

  Funcionario* buscarFuncionario(int id){ //busca por chave primaria / retorna o funcionario com esse id
    Funcionario procurado(id);
    return funcionariosCadastrados.buscar(procurado);
  }

  void listarFuncionarios(){ //lista todos os funcionários cadastrados
    funcionariosCadastrados.toString();
  }

  //arvore do estoque de produtos

  void cadastrarProduto(const Produto& produto){
    estoque.inserir(produto);
    estoque.salvarEmArquivo("produtos.txt");
  }

  void removerProduto(const Produto& produto){
    estoque.remover(produto);
    estoque.salvarEmArquivo("produtos.txt");
  }

  Produto* buscarProduto(int id){ //busca por chave primaria / retorna o produto com esse id
    Produto procurado(id);
    return estoque.buscar(procurado);
  }

  Produto* buscarTitulo(string titulo){ //retorna produto com esse titulo
    return estoque.buscarSecundaria<std::string>(
    std::function<std::string(const Produto&)>(
        [](const Produto& p) { return p.getTitulo(); }
    ),
    titulo
  );
  }

  Tipo stringTipo(string t){ //ex: recebe uma string revista e retorna o tipo revista
    string tipo = t; 
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);

    if (tipo == "livro") return Tipo::LIVRO;
    if (tipo == "revista") return Tipo::REVISTA;
    if (tipo == "hq") return Tipo::HQ;

    throw invalid_argument("Tipo de produto inválido");
  }

  void exibirProduto(const Produto& produto){ //exibe produto especifico
    cout << produto.toString() << endl;
  }

  void listarProdutos(){ //lista todos os produtos no estoque
    estoque.toString();
  }

  // arvore do historico de vendas

  void cadastrarVenda(const Venda& venda){
    historicoVendas.inserir(venda);
    historicoVendas.salvarEmArquivo("vendas.txt");
  }

  void removerVenda(const Venda& venda){
    historicoVendas.remover(venda);
    historicoVendas.salvarEmArquivo("vendas.txt");
  }

  void exibirVenda(const Venda& venda){
    cout << venda.toString() << endl;
  }

  void mostrarHistoricoLivraria(){
    historicoVendas.toString(); 
  }

  //funcoes livraria

  void historicoCliente(const Cliente& cliente){ //exibe as compras feitas por um cliente
    historicoVendas.percorrer(
      [&](const Venda& venda){
        return venda.getCliente().getId() == cliente.getId();
      },
      [](const Venda& venda){
        cout << venda.toString() << endl;
      }
    );
  }

  void mostrarCategoria(string t){ //exibe todos os produtos desse tipo/categoria que estão no estoque
    try {
        Tipo tipo = stringTipo(t);

        estoque.percorrer(
            [&](const Produto& p) {
                return p.getTipo() == tipo;
            },
            [](const Produto& p) {
                cout << p.toString() << endl;
            }
        );
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
  }

  void resetarSistema() { //função para resetar tudo (não ta sendo usada)
    ofstream("clientes.txt").close();
    ofstream("funcionarios.txt").close();
    ofstream("produtos.txt").close();
    ofstream("vendas.txt").close();

    clientesCadastrados = Arvore<Cliente>();
    funcionariosCadastrados = Arvore<Funcionario>();
    estoque = Arvore<Produto>();
    historicoVendas = Arvore<Venda>();

    cout << "Sistema resetado com sucesso. Arquivos esvaziados e árvores limpas.\n";
          }


};

#endif