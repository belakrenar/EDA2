#include <iostream>
#include <queue>
#include <functional>
#include <fstream>

using namespace std;

template <typename T>
class Node{
    public:

    T key;  
    Node* esquerda;  
    Node* direita;
    int altura;  

    Node(T dados)
      : key(dados), esquerda(nullptr), direita(nullptr), altura(1) {}
};

//ARVORE AVL

template <typename T>
class Arvore{
  Node<T>* raiz;

  int altura(Node<T>* node){ //retorna altura da arvore
      if(node == nullptr){
        return 0;
      }
      return node->altura;
  }

  int getBalance(Node<T>* node){ //retorna fator de balanceamento
      if(node == nullptr){
        return 0;
      }
      return altura(node->esquerda) - altura(node->direita);
  }

  Node<T>* RSD(Node<T>* y){ //rotação simples a direita -> corrige desequilibrio a esquerda
      Node<T>* x = y->esquerda;
      Node<T>* temp = x->direita;

      x->direita = y;
      y->esquerda = temp;

      y->altura
          = max(altura(y->esquerda), altura(y->direita)) + 1;
      x->altura
          = max(altura(x->esquerda), altura(x->direita)) + 1;

      return x;
  }

  Node<T>* RSE(Node<T>* x){ //rotação simples a esquerda -> corrige desequilibrio a direita
      Node<T>* y = x->direita;
      Node<T>* temp = y->esquerda;

      y->esquerda = x;
      x->direita = temp;

      x->altura
          = max(altura(x->esquerda), altura(x->direita)) + 1;
      y->altura
          = max(altura(y->esquerda), altura(y->direita)) + 1;

      return y;
  }

  Node<T>* adicionar(Node<T>* node, T key){
      if (node == nullptr)
          return new Node<T>(key);
        
      if (key.getId() < node->key.getId())
          node->esquerda = adicionar(node->esquerda, key);
      else if (key.getId() > node->key.getId())
          node->direita = adicionar(node->direita, key);
      else
          return node;

      node->altura = 1
                      + max(altura(node->esquerda),
                            altura(node->direita));

      int balance = getBalance(node);

      if (balance > 1 && key.getId() < node->esquerda->key.getId()) //RSD (simples a direita)
          return RSD(node);

      if (balance < -1 && key.getId() > node->direita->key.getId()) //RSE (simples a esquerda)
          return RSE(node);

      if (balance > 1 && key.getId() > node->esquerda->key.getId()) { //rotação dupla a direita (esquerda-direita)
          node->esquerda = RSE(node->esquerda);
          return RSD(node);
      }

      if (balance < -1 && key.getId() < node->direita->key.getId()) { //rotação dupla a esquerda (direita-esquerda)
          node->direita = RSD(node->direita);
          return RSE(node);
      }

      return node;
  }

  Node<T>* valorMinimo(Node<T>* node){
      Node<T>* current = node;
      while (current->esquerda != nullptr)
          current = current->esquerda;
      return current;
  }

  Node<T>* deletar(Node<T>* raiz, T key){
      if (raiz == nullptr)
          return raiz;

      if (key.getId() < raiz->key.getId())
          raiz->esquerda = deletar(raiz->esquerda, key);
      else if (key.getId() > raiz->key.getId())
          raiz->direita = deletar(raiz->direita, key);
      else {
          if ((raiz->esquerda == nullptr) || (raiz->direita == nullptr)) {
              Node<T>* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
              if (temp == nullptr) {
                  temp = raiz;
                  raiz = nullptr;
              } else
                  *raiz = *temp;
              delete temp;
          } else {
              Node<T>* temp = valorMinimo(raiz->direita);
              raiz->key = temp->key;
              raiz->direita = deletar(raiz->direita, temp->key);
          }
      }

      if (raiz == nullptr)
          return raiz;

      raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

      int balance = getBalance(raiz);
 
      if (balance > 1 && getBalance(raiz->esquerda) >= 0) //RSD
          return RSD(raiz);

      if (balance > 1 && getBalance(raiz->esquerda) < 0) { //rotação dupla a direita (esquerda-direita)
          raiz->esquerda = RSE(raiz->esquerda);
          return RSD(raiz);
      }

      if (balance < -1 && getBalance(raiz->direita) <= 0) //RSE
          return RSE(raiz);

      if (balance < -1 && getBalance(raiz->direita) > 0) { //rotação dupla a esquerda (direita-esquerda)
          raiz->direita = RSD(raiz->direita);
          return RSE(raiz);
      }

      return raiz;
  }

  void emOrdem(Node<T>* raiz){ //imprime a arvore em ordem
      if (raiz != nullptr) {
          emOrdem(raiz->esquerda);
          cout << raiz->key << "\n";
          emOrdem(raiz->direita);
      }
  }

  Node<T>* buscar(Node<T>* raiz, T key){
      if (raiz == nullptr)
          return nullptr;
      if (raiz->key.getId() == key.getId())
          return raiz;
      if (key.getId() < raiz->key.getId())
          return buscar(raiz->esquerda, key);
      return buscar(raiz->direita, key);
  }

  template <typename U>
  Node<T>* buscarSecundaria(Node<T>* no, const std::function<U(const T&)>& func, const U& valor){
      if (no == nullptr) return nullptr;

      Node<T>* encontrado = buscarSecundaria(no->esquerda, func, valor);
      if (encontrado != nullptr) return encontrado;

      if (func(no->key) == valor)
          return no;

      return buscarSecundaria(no->direita, func, valor);
  }

  void emOrdemFiltrado(Node<T>* no, const function<bool(const T&)>& filtro, const function<void(const T&)>& acao) const { //percorre a arvore em ordem + verifica se uma condição é verdadeira para realizar uma ação
    if (no == nullptr) return;
    emOrdemFiltrado(no->esquerda, filtro, acao);
    if (filtro(no->key)) acao(no->key);
    emOrdemFiltrado(no->direita, filtro, acao);
  }
  
  void exibir(Node<T>* no) { //mostra um elemento de forma "bonita" pro usuario
    if (!no) return;
    exibir(no->esquerda);
    cout << no->key.toString() << "\n\n";
    exibir(no->direita);
  }

  public:

  Arvore() : raiz(nullptr) {}

  void inserir(T key){
    raiz = adicionar(raiz, key);
  }
  /*
  insere novo elemento mantendo a ordem correta
  */

  void remover(T key){
    raiz = deletar(raiz, key);
  }
  /*
  remove um elemento e ajusta a arvore se necessário
  */

  T* buscar(T key){
    Node<T>* no = buscar(raiz, key);
    if(no) return &(no->key);
    return nullptr;
  }
  /*
  Busca por chave primária
  - busca um objeto na árvore com base na chave primária (nesse caso id) e retorna um ponteiro para ele (se ele existir)
  */

  template <typename U>
  T* buscarSecundaria(const std::function<U(const T&)>& func, const U& valor){
    Node<T>* no = buscarSecundaria(raiz, func, valor);
    if(no) return &(no->key);
    return nullptr;
  }
  /*
  Busca por chave secundária
  - percorre a arvore em ordem e retorna o primeiro nó que atende ao critério
  */


  void percorrer(const function<bool(const T&)>& condicao, const function<void(const T&)>& acao) const {
    emOrdemFiltrado(raiz, condicao, acao);
  }
  /*
  Busca Exaustiva/Linear
  - percorre todos os nós na arvore em ordem e verifica se uma condição é verdadeira
  - uma ação é executada com todos os nós que atenderem ao critério
  */

  void toString(){
    exibir(raiz);
    cout << endl;
  }
  /*
  Imprime todos os nós da arvore em ordem
  */
  
  void construirArvoreComArquivo(const string& filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao tentar acessar o arquivo " << filename
            << endl;
        return;
    }

    string linha;
    while (getline( file, linha)) {
        T obj = T::fromString(linha);
        inserir(obj);               
    }

    file.close();
  }
  /*
  lê os dados de um arquivo e insere cada item na arvore
  */
  
  void salvarEmArquivo(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return;
    }

    percorrer(
        [](const T&) { return true; },   // percorre todos
        [&file](const T& obj) { file << obj << endl; }
    );

    file.close();
  }

  /*
  salva todos os elementos da árvore em um arquivo de texto
  */

};

template<typename T>
void inicializarArvoreComArquivo(Arvore<T>& arvore, const string& filename) {
    ifstream test(filename);
    if (test.good()) {
        arvore.construirArvoreComArquivo(filename);
    } else {
        ofstream createFile(filename); // cria vazio
        createFile.close();
    }
}
/*
prepara a árvore a partir de um arquivo, ou cria o arquivo se ele ainda não existir
- se existir, chama construirArvoreComArquivo()
- se não existir, cria um arquivo vazio com esse nome
*/
