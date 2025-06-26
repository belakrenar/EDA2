#include <iostream>
#include <queue>
#include <functional>

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

template <typename T>
class Arvore{
  Node<T>* raiz;

  int altura(Node<T>* node){
      if(node == nullptr){
        return 0;
      }
      return node->altura;
  }

  int getBalance(Node<T>* node){
      if(node == nullptr){
        return 0;
      }
      return altura(node->esquerda) - altura(node->direita);
  }

  Node<T>* RSD(Node<T>* y){
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

  Node<T>* RSE(Node<T>* x){
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

      if (balance > 1 && key.getId() < node->esquerda->key.getId())
          return RSD(node);

      if (balance < -1 && key.getId() > node->direita->key.getId())
          return RSE(node);

      if (balance > 1 && key.getId() > node->esquerda->key.getId()) {
          node->esquerda = RSE(node->esquerda);
          return RSD(node);
      }

      if (balance < -1 && key.getId() < node->direita->key.getId()) {
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

      if (balance > 1 && getBalance(raiz->esquerda) >= 0)
          return RSD(raiz);

      if (balance > 1 && getBalance(raiz->esquerda) < 0) {
          raiz->esquerda = RSE(raiz->esquerda);
          return RSD(raiz);
      }

      if (balance < -1 && getBalance(raiz->direita) <= 0)
          return RSE(raiz);

      if (balance < -1 && getBalance(raiz->direita) > 0) {
          raiz->direita = RSD(raiz->direita);
          return RSE(raiz);
      }

      return raiz;
  }

  void emOrdem(Node<T>* raiz){
      if (raiz != nullptr) {
          emOrdem(raiz->esquerda);
          cout << raiz->key << "\n";
          emOrdem(raiz->direita);
      }
  }
  /*  
  bool buscar(Node<T>* raiz, T key){
      if (raiz == nullptr)
          return false;
      if (raiz->key.getId() == key.getId())
          return true;
      if (key.getId() < raiz->key.getId())
          return buscar(raiz->esquerda, key);
      return buscar(raiz->direita, key);
  }
  */

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

  void emOrdemFiltrado(Node<T>* no, const function<bool(const T&)>& filtro, const function<void(const T&)>& acao) const {
    if (no == nullptr) return;
    emOrdemFiltrado(no->esquerda, filtro, acao);
    if (filtro(no->key)) acao(no->key);
    emOrdemFiltrado(no->direita, filtro, acao);
  }
  
  
  public:

  Arvore() : raiz(nullptr) {}

  void inserir(T key){
    raiz = adicionar(raiz, key);
  }

  void remover(T key){
    raiz = deletar(raiz, key);
  }

  T* buscar(T key){
    Node<T>* no = buscar(raiz, key);
    if(no) return &(no->key);
    return nullptr;
  }

  template <typename U>
  T* buscarSecundaria(const std::function<U(const T&)>& func, const U& valor){
    Node<T>* no = buscarSecundaria(raiz, func, valor);
    if(no) return &(no->key);
    return nullptr;
  }

  void percorrer(const function<bool(const T&)>& condicao, const function<void(const T&)>& acao) const {
    emOrdemFiltrado(raiz, condicao, acao);
  }

  void toString(){
    emOrdem(raiz);
    cout << endl;
  }
};