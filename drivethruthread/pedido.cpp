#include "pedido.h"
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

Bebida bebidas[7] =
{
    {"SEM BEBIDA ",' ',0.00},
    {"COCA-COLA  ",'P',3.00},
    {"COCA-COLA  ",'M',4.00},
    {"COCA-COLA  ",'G',5.00},
    {"SUCO DE UVA",'P',2.50},
    {"SUCO DE UVA",'M',3.50},
    {"SUCO DE UVA",'G',4.50}
};

Lanche lanches[11] =
{
    {"SEM LANCHE "      , false, 0.00},
    {"MC LANCHE FELIZ " , false, 12.90},
    {"MC CHICKEN "      , false, 12.90},
    {"ANGUS BACON "     , false, 16.00},
    {"MCNIFICO "        , false, 19.00},
    {"CBO "             , false, 14.00},
    {"BIG TASTY "       , false, 8.00},
    {"HAMBUGUER "       , false, 6.00},
    {"BIG MAC "         , false, 12.00},
    {"DELUXE BACON "    , false, 14.00},
    {"MCFISH "          , false, 12.90}
};

void Lanche::comBatata() {
    srand(time(NULL));
    lanches[rand()%10].batata = true;
}

void Pedido::geraPedido()
{
    srand(time(0));

    this->numPedido = rand() % 1000;
    this->lanche.comBatata();
    this->lanche = lanches[rand() % 10];
    this->bebida = bebidas[rand() % 7];
    this->valor = this->bebida.valor + this->lanche.valor;

    strcpy(this->descricao, this->lanche.nome);

    if (this->lanche.batata) {
        this->valor += 2.00;
        strcat(this->descricao," COM BATATA ");
    }

    strcat(this->descricao, this->bebida.nome);

    char tamanho[13] = "";

    if (this->bebida.tamanho != ' ')
    {
        strcpy(tamanho," TAMANHO   ");
        tamanho[9] = this->bebida.tamanho;
    }

    strcat(this->descricao,tamanho);

    char v[10];
    sprintf(v, "%f", this->valor);

    char v2[10] = "R$    ";

    for (int i = 0; i < 4; i++)
        v2[i+2] = v[i];

    strcat(this->descricao,v2);
}
