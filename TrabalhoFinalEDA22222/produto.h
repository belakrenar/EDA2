#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

enum class Tipo {
  LIVRO,
  REVISTA,
  HQ, 
};

class Produto {
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
  Produto(int i) : id(i) {}

  Produto(string t, string a, string ed, double p, int pg, string data, Tipo tp)
    : id(idAtual++), titulo(t), autor(a), editora(ed), preco(p), paginas(pg), dataPublicacao(data), tipo(tp) {}

  Produto(int i, string t, string a, string ed, double p, int pg, string data, Tipo tp)
    : id(i), titulo(t), autor(a), editora(ed), preco(p), paginas(pg), dataPublicacao(data), tipo(tp) {}

  virtual ~Produto() = default;

  Produto& operator=(const Produto& outro) {
    if (this != &outro) {
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

  int getId() const { return id; }
  string getTitulo() const { return titulo; }
  string getAutor() const { return autor; }
  string getEditora() const { return editora; }
  double getPreco() const { return preco; }
  int getPaginas() const { return paginas; }
  string getDataPublicacao() const { return dataPublicacao; }
  Tipo getTipo() const { return tipo; }

  string getTipoString() const {
    switch (tipo) {
      case Tipo::LIVRO: return "livro";
      case Tipo::REVISTA: return "revista";
      case Tipo::HQ: return "hq";
      default: return "desconhecido";
    }
  }

  static Tipo tipoFromString(const string& tipoStr) {
    if (tipoStr == "livro") return Tipo::LIVRO;
    if (tipoStr == "revista") return Tipo::REVISTA;
    if (tipoStr == "hq") return Tipo::HQ;
    throw invalid_argument("Tipo de produto inválido: " + tipoStr);
  }

  static Produto fromString(const string& linha) {
    stringstream ss(linha);
    int id, paginas;
    string titulo, autor, editora, data, tipoStr;
    double preco;

    ss >> id >> titulo >> autor >> editora >> preco >> paginas >> data >> tipoStr;

    Tipo tipo = tipoFromString(tipoStr);
    if (id >= idAtual) idAtual = id + 1;

    return Produto(id, titulo, autor, editora, preco, paginas, data, tipo);
  }

  string toString() const {
    stringstream ss;
    ss << "ID: " << id << "\n"
       << "Categoria: " << getTipoString() << "\n"
       << "Título: " << titulo << "\n"
       << "Autor: " << autor << "\n"            
       << "Editora: " << editora << "\n"
       << "Data de publicação: " << dataPublicacao << "\n"
       << paginas << " páginas\n"
       << "Preço: R$" << preco;
    return ss.str();
  }

  friend ostream& operator<<(ostream& os, const Produto& p) {
    os << p.id << " " << p.titulo << " " << p.autor << " " << p.editora << " "
       << p.preco << " " << p.paginas << " " << p.dataPublicacao << " " << p.getTipoString();
    return os;
  }
};

int Produto::idAtual = 0;

class Livro : public Produto {
public:
  Livro(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::LIVRO) {}
};

class Revista : public Produto {
public:
  Revista(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::REVISTA) {}
};

class Quadrinho : public Produto {
public:
  Quadrinho(string t, string a, string ed, double p, int pg, string data)
    : Produto(t, a, ed, p, pg, data, Tipo::HQ) {}
};

#endif
