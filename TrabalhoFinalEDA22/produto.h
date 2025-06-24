#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>

using namespace std;

enum class Tipo{
  LIVRO,
  REVISTA,
  HQ,
};

class Produto{
  protected:
  static int idAtual;
  int id;
  string titulo;
  string autor;
  string editora;
  double preco;
  int paginas;
  string dataPublicacao;
  Tipo tipo;

  public:

  Produto(string t, string a,string ed, double p, int pg, string data, Tipo tp)
    : id(idAtual++), titulo(t), autor(a), editora(ed), preco(p), paginas(pg), dataPublicacao(data), tipo(tp) {}

  virtual ~Produto() = default;

  Produto& operator=(const Produto& outro) {
    if(this != &outro){
      id = outro.id;
      titulo = outro.titulo;
      autor = outro.autor;
      editora = outro.editora;
      preco = outro.preco;
      paginas = outro.paginas;
      dataPublicacao = outro.dataPublicacao;
      tipo = outro.tipo;
    }
    return *this;
  }

  int getId(){
    return id;
  }

  string getTitulo(){
    return titulo;
  }

  string getAutor(){
    return autor;
  }

  string getEditora(){
    return editora;
  }

  double getPreco(){
    return preco;
  }

  int getPaginas(){
    return paginas;
  }

  string getTipo(){
    switch(tipo){
      case Tipo::LIVRO: return "Livro";
      case Tipo::REVISTA: return "Revista";
      case Tipo::HQ: return "HQ";
      default: return "O tipo do produto não foi definido.";
    }
  }

  void toString(ostream& os){
    os << "\nID: " << id << endl
       << "Categoria: " << getTipo() << endl
       << "Título: " << titulo << endl
       << "Autor: " << autor << endl
       << "Editora: " << editora << endl
       << "Data de publicação: " << dataPublicacao << endl
       << paginas << " páginas" << endl
       << "Preço: R$" << preco;
  }

};

class Livro : public Produto{  
  public:

  Livro(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::LIVRO) {}

};

class Revista : public Produto{
  int edicao;  
  public:

  Revista(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::REVISTA) {}
};

class Quadrinho : public Produto{
  public:

  Quadrinho(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::HQ) {}
};

int Produto::idAtual = 0;

inline ostream& operator<<(ostream& os, Produto p) {
    p.toString(os);
    return os;
}

#endif