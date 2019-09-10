#ifndef _PEDIDO_H_
#define _PEDIDO_H_
struct Bebida
{
    char nome[20];
    char tamanho;
    float valor;
}extern bebidas[7];

struct Lanche {
    char nome[20];
    bool batata;
    float valor;
    void comBatata();
} extern lanches[11];

struct Pedido
{
    int numPedido;
    Bebida bebida;
    Lanche lanche;
    float valor;
    char descricao[100];
    void geraPedido();
};
#endif // _PEDIDO_H_
