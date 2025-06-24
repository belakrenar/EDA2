#include "sistema.h"

int main(){
  Sistema sistema;
  //TESTE DE PRODUTOS
  /*
  Livro l1("Dom Casmurro", "Machado de Assis", "Record", 29.90, 220, "1899-01-01");
  Livro l2("1984", "George Orwell", "Companhia das Letras", 45.50, 328, "1949-06-08");
  Revista r1("Superinteressante", "Vários", "Abril", 15.00, 80, "2023-05-01");
  Quadrinho q1("Batman: Ano Um", "Frank Miller", "DC Comics", 35.00, 96, "1987-01-01");
  Quadrinho q2("Homem-Aranha #1", "Stan Lee", "Marvel", 40.00, 100, "1963-03-01");
  Revista r2("Revista 2", "Vários", "Abril", 15.00, 80, "2023-05-01");
  Revista r3("Revista 3", "Vários", "Abril", 15.00, 80, "2023-05-01");


  sistema.cadastrarProduto(l1); //id0
  sistema.cadastrarProduto(l2); //id1
  sistema.cadastrarProduto(r1); //id2
  sistema.cadastrarProduto(q1); //id3
  sistema.cadastrarProduto(q2); //id4

  std::cout << "\n=== PRODUTOS CADASTRADOS ===\n";
  sistema.listarProdutos();

  std::cout << "\n=== BUSCANDO PRODUTOS l2 E q1 ===\n";
  sistema.buscarProduto(l2);
  sistema.buscarProduto(q1);
  
  std::cout << "\n=== REMOVENDO PRODUTOS l2 E q1 ===\n";
  sistema.removerProduto(l2); // Remove "1984"
  sistema.removerProduto(q1); // Remove "Batman: Ano Um"

  std::cout << "\n=== PRODUTOS RESTANTES ===\n";
  sistema.listarProdutos();

  std::cout << "\n=== BUSCANDO PRODUTOS l2 E q1 APÓS REMOÇÃO ===\n";
  sistema.buscarProduto(l2);
  sistema.buscarProduto(q1);
  
  std::cout << "\n=== ADICIONANDO MAIS PRODUTOS ===\n";

  sistema.cadastrarProduto(r2);
  sistema.cadastrarProduto(r3);

  std::cout << "\n=== PRODUTOS CADASTRADOS (FIM) ===\n";
  sistema.listarProdutos();
  */

  //TESTE DE FUNCIONARIOS

  /*
  Funcionario f1("João Silva", "123.456.789-00", "Gerente", 7500);
  Funcionario f2("Maria Oliveira", "987.654.321-00", "Vendedor", 5200);
  Funcionario f3("Carlos Pereira", "456.789.123-00", "Vendedor", 3800);
  Funcionario f4("Ana Souza", "789.123.456-00", "Estagiária", 1800);
  Funcionario f5("Fernanda Lima", "321.654.987-00", "Vendedor", 6200);

  sistema.cadastrarFuncionario(f1);
  sistema.cadastrarFuncionario(f2);
  sistema.cadastrarFuncionario(f3);
  sistema.cadastrarFuncionario(f4);
  sistema.cadastrarFuncionario(f5);

  std::cout << "\n=== FUNCIONARIOS CADASTRADOS ===\n";

  sistema.listarFuncionarios();

  std::cout << "\n=== BUSCANDO FUNCIONARIOS f2 E f4 ===\n";
  sistema.buscarFuncionario(f2);
  sistema.buscarFuncionario(f4);

  std::cout << "\n=== REMOVENDO FUNCIONARIOS f2 E f4 ===\n";
  sistema.removerFuncionario(f2);
  sistema.removerFuncionario(f4);

  std::cout << "\n=== FUNCIONARIOS RESTANTES ===\n";

  sistema.listarFuncionarios();

  std::cout << "\n=== BUSCANDO FUNCIONARIOS f2 E f4 APÓS REMOÇÃO ===\n";
  sistema.buscarFuncionario(f2);
  sistema.buscarFuncionario(f4);

  std::cout << "\n=== CADASTRANDO MAIS FUNCIONARIOS ===\n";

  Funcionario f6("Roberto Nunes", "111.222.333-44", "Supervisor", 5800);
  Funcionario f7("Juliana Mendes", "222.333.444-55", "Engenheira", 9200);
  Funcionario f8("Paulo Costa", "333.444.555-66", "Auxiliar", 3100);

  sistema.cadastrarFuncionario(f6);
  sistema.cadastrarFuncionario(f7);
  sistema.cadastrarFuncionario(f8);

  std::cout << "\n=== FUNCIONARIOS CADASTRADOS (FIM) ===\n";

  sistema.listarFuncionarios();
  */


  //TESTE DE CLIENTES

  /*
  Cliente c1("João da Silva", "123.456.789-00");
  Cliente c2("Maria de Souza", "987.654.321-00");
  Cliente c3("Carlos Lima", "456.789.123-00");
  Cliente c4("Ana Rodrigues", "789.123.456-00");
  Cliente c5("Fernanda Castro", "321.654.987-00");

  sistema.cadastrarCliente(c1);
  sistema.cadastrarCliente(c2);
  sistema.cadastrarCliente(c3);
  sistema.cadastrarCliente(c4);
  sistema.cadastrarCliente(c5);

  std::cout << "\n=== CLIENTES CADASTRADOS ===\n";

  sistema.listarClientes();

  std::cout << "\n=== BUSCANDO CLIENTES c2 E c4 ===\n";
  sistema.buscarCliente(c2);
  sistema.buscarCliente(c4);

  std::cout << "\n=== REMOVENDO CLIENTES c2 E c4 ===\n";
  sistema.removerCliente(c2);
  sistema.removerCliente(c4);

  std::cout << "\n=== CLIENTES RESTANTES ===\n";

  sistema.listarClientes();

  std::cout << "\n=== BUSCANDO CLIENTES c2 E c4 APÓS REMOÇÃO ===\n";
  sistema.buscarCliente(c2);
  sistema.buscarCliente(c4);

  std::cout << "\n=== CADASTRANDO MAIS CLIENTES ===\n";

  Cliente c6("Roberto Nunes", "111.222.333-44");
  Cliente c7("Juliana Mendes", "222.333.444-55");
  Cliente c8("Paulo Costa", "333.444.555-66");

  sistema.cadastrarCliente(c6);
  sistema.cadastrarCliente(c7);
  sistema.cadastrarCliente(c8);

  std::cout << "\n=== CLIENTES CADASTRADOS (FIM) ===\n";

  sistema.listarClientes();
  */


}