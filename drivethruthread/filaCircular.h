#ifndef _FILA_LINEAR_H_
#define _FILA_LINEAR_H_
#define TAM 30
#define TIPO Pedido
#include "pedido.h"
struct Fila{
    TIPO elementos[TAM];
    int head;
    int tail;
    void inicializa();
    void enqueue(TIPO elemento);
    TIPO dequeue();
    int tamanho();
    bool cheia();
    bool vazia();
    TIPO primeiro();
    void exibir();
};
#endif // _FILA_LINEAR_H_
