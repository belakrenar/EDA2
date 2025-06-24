#include "sistema.h"

int main(){
  Sistema sistema;

  Livro l1("Dom Casmurro", "Machado de Assis", "Record", 29.90, 220, "1899-01-01");
  Livro l2("1984", "George Orwell", "Companhia das Letras", 45.50, 328, "1949-06-08");
  sistema.cadastrarProduto(l1);
  sistema.cadastrarProduto(l2);
  
  sistema.listarProdutos();

}