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
  const int id;
  string titulo;
  string autor;
  string editora;
  double preco;
  int paginas;
  string dataPublicacao;
  Tipo tipo;

  public:

  Produto(string t, string a,string ed, double p, int pg, string data, Tipo tp){
    id(idAtual++);
    titulo = t;
    autor = a;
    editora = ed;
    preco = p;
    paginas = pg;
    dataPublicacao = data;
    tipo = tp;
  }

};

class Livro : public Produto{  
  public:

  Livro(string t, string a, string ed, double p, int pg, int e, string data)
    : Produto(t, a, ed, p, pg, e, data, Tipo::LIVRO) {}

  friend ostream& operator<<(ostream& os, const Livro& l) {
        os << "ID: " << l.id << endl
           << "Categoria: livro" << endl
           << "Título: " << l.titulo << endl
           << "Autor: " << l.autor << endl
           << "Editora: " << l.editora << endl
           << "Data de publicação: " << l.dataPublicacao << endl
           << l.paginas << " páginas" << endl
           << "Preço: R$" << l.preco;
        return os;
  }
};

class Revista : public Produto{
  int edicao;  
  public:

  Revista(string t, string a, string ed, double p, int pg, int e, string data, int edic)
    : Produto(t, a, ed, p, pg, e, data, Tipo::REVISTA), edicao(edic) {}

  friend ostream& operator<<(ostream& os, const Revista& r) {
        os << "ID: " << r.id << endl
           << "Categoria: revista" << endl
           << "Título: " << r.titulo << endl
           << "Autor: " << r.autor << endl
           << "Editora: " << r.editora << endl
           << "Data de publicação: " << r.dataPublicacao << endl
           << "Edição: " << r.edicao << endl
           << r.paginas << " páginas" << endl
           << "Preço: R$" << r.preco;
        return os;
  }
};

class Quadrinho : public Produto{
  int edicao;

  public:

  Quadrinho(string t, string a, string ed, double p, int pg, int e, string data, int edic)
    : Produto(t, a, ed, p, pg, e, data, Tipo::HQ), edicao(edic) {}

  friend ostream& operator<<(ostream& os, const Revista& r) {
        os << "ID: " << r.id << endl
           << "Categoria: HQ" << endl
           << "Título: " << r.titulo << endl
           << "Autor: " << r.autor << endl
           << "Editora: " << r.editora << endl
           << "Data de publicação: " << r.dataPublicacao << endl
           << "Edição: " << r.edicao << endl
           << r.paginas << " páginas" << endl
           << "Preço: R$" << r.preco;
        return os;
  }

};

int Produto::idAtual = 0;