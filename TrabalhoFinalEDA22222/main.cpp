#include "sistema.h"
#include <iostream>

Sistema sistema;

//funcoes clientes

void cadastrarCliente(){
    string nome, cpf;

    cout << "\n--- CADASTRAR CLIENTE ---\n";
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    Cliente cliente(nome, cpf);
    sistema.cadastrarCliente(cliente);

    cout << "Cliente cadastrado com sucesso!\n";
}


void buscarCliente(){
  int id;

  cout << "\n--- BUSCAR CLIENTE ---\n";
  cout << "Digite o ID do cliente que deseja buscar: ";
  cin >> id;

  Cliente* cliente = sistema.buscarCliente(id);
    if (cliente != nullptr) {
        cout << "\nCliente encontrado:\n";
        sistema.exibirCliente(*cliente);
    } else {
        cout << "\nCliente não encontrado.\n";
    }
}

void exibirCliente(){
  cout << "\n--- VISUALIZAR CLIENTE ---\n";

  sistema.listarClientes();

  int id;
  cout << "\nDigite o ID do cliente que deseja visualizar: ";
  cin >> id;

  Cliente* cliente = sistema.buscarCliente(id);
  if (cliente != nullptr) {
      sistema.exibirCliente(*cliente);
      cout << "\nCompras realizadas: \n";
      sistema.historicoCliente(*cliente);
  } else {
      cout << "\nCliente não encontrado.\n";
  }

}

void listarClientes(){
  cout << "\n--- CLIENTES CADASTRADOS ---\n";
  sistema.listarClientes();
}

void removerCliente() {
    int id;

    cout << "\n--- REMOVER CLIENTE ---\n";
    cout << "Digite o ID do cliente que deseja remover: ";
    cin >> id;

    Cliente* cliente = sistema.buscarCliente(id);
    if (cliente != nullptr) {
        char confirmacao;
        cout << "\nCliente encontrado:\n";
        sistema.exibirCliente(*cliente);
        cout << "\nTem certeza que deseja remover este cliente? (s/n): ";
        cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
            sistema.removerCliente(*cliente);
            cout << "Cliente removido com sucesso!\n";
        } else {
            cout << "Remoção cancelada.\n";
        }
    } else {
        cout << "\nCliente não encontrado.\n";
    }
}


//funcoes funcionarios

void cadastrarFuncionario(){
  string nome, cpf, cargo;
  int salario;
  cout << "\n--- CADASTRAR CLIENTE ---\n";

  cout << "Nome: ";
  cin.ignore();
  getline(cin, nome);

  cout << "CPF: ";
  getline(cin, cpf);

  cout << "Cargo: ";
  getline(cin, cargo);

  cout << "Salario: ";
  cin >> salario;

  Funcionario funcionario(nome, cpf, cargo, salario);
  sistema.cadastrarFuncionario(funcionario);

  cout << "\nFuncionário cadastrado com sucesso!\n";

}

void buscarFuncionario(){
    int id;

    cout << "\n--- BUSCAR FUNCIONÁRIO ---\n";
    cout << "Digite o ID do funcionário que deseja buscar: ";
    cin >> id;

    Funcionario* funcionario = sistema.buscarFuncionario(id);
    if (funcionario != nullptr) {
        cout << "\nFuncionário encontrado:\n";
        cout << *funcionario << endl;
    } else {
        cout << "\nFuncionário não encontrado.\n";
    }
}

void listarFuncionarios(){
  cout << "\n--- FUNCIONÁRIOS CADASTRADOS ---\n";
  sistema.listarFuncionarios();
}

void removerFuncionario() {
    int id;

    cout << "\n--- REMOVER FUNCIONÁRIO ---\n";
    cout << "Digite o ID do funcionário que deseja remover: ";
    cin >> id;

    Funcionario* funcionario = sistema.buscarFuncionario(id);
    if (funcionario != nullptr) {
        char confirmacao;
        cout << "\nFuncionário encontrado:\n";
        cout << *funcionario << endl;
        cout << "\nTem certeza que deseja remover este funcionário? (s/n): ";
        cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
            sistema.removerFuncionario(*funcionario);
            cout << "Funcionário removido com sucesso!\n";
        } else {
            cout << "Remoção cancelada.\n";
        }
    } else {
        cout << "\nFuncionário não encontrado.\n";
    }
}


//funcoes produtos

void cadastrarProduto() {
    string titulo, autor, editora, data, tipoStr;
    double preco;
    int paginas;

    cout << "\n--- CADASTRAR PRODUTO ---\n";

    cout << "Título: ";
    cin >> ws; getline(cin, titulo);

    cout << "Autor: ";
    getline(cin, autor);

    cout << "Editora: ";
    getline(cin, editora);

    cout << "Preço: R$";
    cin >> preco;

    cout << "Número de páginas: ";
    cin >> paginas;

    cout << "Data de publicação (ex: 2023-05-18): ";
    cin >> ws; getline(cin, data);

    cout << "Tipo (livro / revista / hq): ";
    getline(cin, tipoStr);

    try {
        Tipo tipo = Produto::tipoFromString(tipoStr);

        Produto novo(titulo, autor, editora, preco, paginas, data, tipo);
        sistema.cadastrarProduto(novo);

        cout << "\nProduto cadastrado com sucesso!\n";
    } catch (const invalid_argument& e) {
        cout << "\nErro ao cadastrar produto: " << e.what() << "\n";
    }
}

void buscarProduto() {
    int id;

    cout << "\n--- BUSCAR PRODUTO ---\n";
    cout << "Digite o ID do produto que deseja buscar: ";
    cin >> id;

    Produto* produto = sistema.buscarProduto(id);
    if (produto != nullptr) {
        cout << "\nProduto encontrado:\n";
        sistema.exibirProduto(*produto);
    } else {
        cout << "\nProduto não encontrado.\n";
    }
}

void listarProdutos(){
  cout << "\n--- PRODUTOS DA LIVRARIA ---\n";
  sistema.listarProdutos();
}

void buscarProdutoPorTitulo() {
    string titulo;

    cout << "\n--- BUSCAR PRODUTO POR TÍTULO ---\n";
    cout << "Digite o título do produto que deseja buscar: ";
    cin.ignore();
    getline(cin, titulo);

    Produto* produto = sistema.buscarTitulo(titulo);
    if (produto != nullptr) {
        cout << "\nProduto encontrado:\n";
        sistema.exibirProduto(*produto);
    } else {
        cout << "\nProduto com o título \"" << titulo << "\" não encontrado.\n";
    }
}

void visualizarPorCategoria() {
    int escolha;
    string tipo;

    cout << "\n--- VISUALIZAR PRODUTOS POR CATEGORIA ---\n";
    cout << "1 - Livros\n";
    cout << "2 - Revistas\n";
    cout << "3 - HQs\n";
    cout << "Escolha a categoria: ";
    cin >> escolha;

    switch (escolha) {
        case 1:
            tipo = "livro";
            break;
        case 2:
            tipo = "revista";
            break;
        case 3:
            tipo = "hq";
            break;
        default:
            cout << "Opção inválida!\n";
            return;
    }

    cout << "\n--- PRODUTOS DA CATEGORIA: " << tipo << " ---\n";
    sistema.mostrarCategoria(tipo);
}

void removerProduto() {
    int id;

    cout << "\n--- REMOVER PRODUTO ---\n";
    cout << "Digite o ID do produto que deseja remover: ";
    cin >> id;

    Produto* produto = sistema.buscarProduto(id);
    if (produto != nullptr) {
        char confirmacao;
        cout << "\nProduto encontrado:\n";
        sistema.exibirProduto(*produto);
        cout << "\nTem certeza que deseja remover este produto? (s/n): ";
        cin >> confirmacao;

        if (confirmacao == 's' || confirmacao == 'S') {
            sistema.removerProduto(*produto);
            cout << "Produto removido com sucesso!\n";
        } else {
            cout << "Remoção cancelada.\n";
        }
    } else {
        cout << "\nProduto não encontrado.\n";
    }
}


//funcao de registrar venda

void registrarVenda() {
    int idCliente, idFuncionario, idProduto;
    string data;

    cout << "\n--- REGISTRAR VENDA ---\n";

    sistema.listarClientes();

    // Selecionar cliente
    cout << "ID do comprador: \n";
    cin >> idCliente;
    Cliente* cliente = sistema.buscarCliente(idCliente);
    if (!cliente) {
        cout << "Cliente não encontrado.\n";
        return;
    }
    
    sistema.listarFuncionarios();

    // Selecionar funcionário
    cout << "ID do vendedor: \n";
    cin >> idFuncionario;
    Funcionario* funcionario = sistema.buscarFuncionario(idFuncionario);
    if (!funcionario) {
        cout << "Funcionário não encontrado.\n";
        return;
    }

    sistema.listarProdutos();

    // Selecionar produto
    cout << "ID do produto: \n";
    cin >> idProduto;
    Produto* produto = sistema.buscarProduto(idProduto);
    if (!produto) {
        cout << "Produto não encontrado.\n";
        return;
    }

    // Inserir data
    cout << "Data da venda: ";
    cin >> ws;
    getline(cin, data);

    // Criar e registrar venda
    Venda novaVenda(*cliente, *funcionario, *produto, data);
    sistema.cadastrarVenda(novaVenda);

    cout << "\nVenda registrada com sucesso!\n";
}



//menus

void menuClientes(){
    int opcao;
    do {
        cout << "\n--- MENU CLIENTES ---\n";
        cout << "1 - Cadastrar cliente\n";
        cout << "2 - Buscar cliente\n";
        cout << "3 - Exibir cliente\n";
        cout << "4 - Listar clientes\n";
        cout << "5 - Remover cadastro\n";
        cout << "0 - Voltar ao menu principal\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: buscarCliente(); break;
            case 3: exibirCliente(); break;
            case 4: listarClientes(); break;
            case 5: removerCliente(); break;
            case 0: break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void menuFuncionarios() {
    int opcao;
    do {
        cout << "\n--- MENU FUNCIONÁRIOS ---\n";
        cout << "1 - Cadastrar funcionário\n";
        cout << "2 - Buscar funcionário\n";
        cout << "3 - Listar funcionários\n";
        cout << "4 - Remover cadastro\n";
        cout << "0 - Voltar ao menu principal\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarFuncionario(); break;
            case 2: buscarFuncionario(); break;
            case 3: listarFuncionarios(); break;
            case 4: removerFuncionario(); break;
            case 0: break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}

void menuEstoque() {
    int opcao;
    do {
        cout << "\n--- MENU ESTOQUE ---\n";
        cout << "1 - Cadastrar produto\n";
        cout << "2 - Buscar produto por ID\n";
        cout << "3 - Listar todos os produtos\n";
        cout << "4 - Buscar produto por título\n";
        cout << "5 - Visualizar por categoria\n";
        cout << "6 - Remover produto\n";
        cout << "0 - Voltar ao menu principal\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: buscarProduto(); break;
            case 3: listarProdutos(); break;
            case 4: buscarProdutoPorTitulo(); break;
            case 5: visualizarPorCategoria(); break;
            case 6: removerProduto(); break;
            case 0: break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);
}


int main() {
    int opcao;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1 - Clientes\n";
        cout << "2 - Funcionários\n";
        cout << "3 - Estoque\n";
        cout << "4 - Registrar venda\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: menuClientes(); break;
            case 2: menuFuncionarios(); break;
            case 3: menuEstoque(); break;
            case 4: registrarVenda(); break;
            case 0: cout << "Encerrando programa...\n"; break;
            default: cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
