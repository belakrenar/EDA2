#include "sistema.h"

int main() {
  Sistema sistema;

  //TESTE CLIENTES

  Cliente c1("João Silva", "111.111.111-11");
  Cliente c2("Maria Souza", "222.222.222-22");
  sistema.cadastrarCliente(c1);
  sistema.cadastrarCliente(c2);

  cout << "\n=== LISTA DE CLIENTES ===\n";
  sistema.listarClientes();

  Cliente* encontrado = sistema.buscarCliente(c1.getId());
  if (encontrado) {
    cout << "\nCliente encontrado:\n";
    sistema.exibirCliente(*encontrado);
  }

  sistema.removerCliente(c2);
  cout << "\n=== LISTA DE CLIENTES APÓS REMOÇÃO ===\n";
  sistema.listarClientes();

  // TESTE CADASTRO FUNCIONARIOS
  Funcionario f1("Carlos", "333.333.333-33", "Vendedor", 3000);
  Funcionario f2("Ana", "444.444.444-44", "Caixa", 2800);
  sistema.cadastrarFuncionario(f1);
  sistema.cadastrarFuncionario(f2);

  cout << "\n=== LISTA DE FUNCIONÁRIOS ===\n";
  sistema.listarFuncionarios();

  sistema.removerFuncionario(f1);
  cout << "\n=== FUNCIONÁRIOS APÓS REMOÇÃO ===\n";
  sistema.listarFuncionarios();

  //TESTE LIVROS

  Livro l1("1984", "George Orwell", "Companhia das Letras", 39.90, 300, "1949-06-08");
  Revista r1("Superinteressante", "Vários", "Abril", 19.90, 90, "2023-01-01");
  Quadrinho hq1("Batman", "Frank Miller", "DC", 29.90, 100, "1987-03-01");

  sistema.cadastrarProduto(l1);
  sistema.cadastrarProduto(r1);
  sistema.cadastrarProduto(hq1);

  cout << "\n=== LISTA DE PRODUTOS ===\n";
  sistema.listarProdutos();

  Produto* achado = sistema.buscarTitulo("1984");
  if (achado) {
    cout << "\nProduto com título '1984':\n";
    sistema.exibirProduto(*achado);
  }

  cout << "\n=== PRODUTOS DO TIPO 'revista' ===\n";
  sistema.mostrarCategoria("revista");

  // TESTE VENDAS
  Venda venda1(c1, f2, l1, "2024-06-25");
  Venda venda2(c1, f2, r1, "2024-06-26");
  sistema.cadastrarVenda(venda1);
  sistema.cadastrarVenda(venda2);

  cout << "\n=== HISTÓRICO DE VENDAS ===\n";
  sistema.mostrarHistoricoLivraria();

  cout << "\n=== VENDAS DO CLIENTE JOÃO SILVA ===\n";
  sistema.historicoCliente(c1);

  return 0;
}
