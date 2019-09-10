#include <iostream>
#include <cstdlib>
#include "filaCircular.h"
using namespace std;
void Fila::inicializa()
{
    this->head = -1;
    this->tail = -1;
}
void Fila::enqueue(TIPO elemento)
{
    if (!this->cheia())
    {
        if (this->vazia())
            this->head++;
        this->tail = (this->tail + 1) % TAM;
        this->elementos[this->tail] = elemento;
    }
    //else
      //  cout << "FILA CHEIA" << endl;
}
TIPO Fila::dequeue()
{
    if (!this->vazia())
    {
        TIPO elemento = this->elementos[this->head];
        if (this->head == this->tail)
        {
            this->head = -1;
            this->tail = -1;
        }
        else
            this->head = (this->head + 1) % TAM;
        return elemento;
    }
    else
    {
        cout << "FILA VAZIA" << endl;
        Pedido p;
        return p;
    }
}
int Fila::tamanho()
{
    if (!this->vazia())
        if (this->tail >= this->head)
            return this->tail - this->head + 1;
        else
            TAM - this->head + this->tail + 1;
    else
        return 0;
}
bool Fila::vazia()
{
    if (this->head == -1)
        return true;
    else
        return false;
}
bool Fila::cheia()
{
    if (((this->tail + 1) % TAM) == this->head)
        return true;
    else
        return false;
}
TIPO Fila::primeiro()
{
    if(!this->vazia())
        return this->elementos[this->head];
    else
    {
        cout << "FILA VAZIA" << endl;
        Pedido p;
        return p;
    }
}
void imprimeElemento(Fila *f, int i)
{
    cout << f->elementos[i].descricao;
    if (i == f->head)
        cout << " <-- HEAD";
    if (i == f->tail)
        cout << " <-- TAIL";
    cout << endl;
}
void Fila::exibir()
{
    for (int i = 0; (i < TAM) || this->head != this->tail; i=(i+1)%TAM) {

        //if (this->tail >= this->head)
        //    if (i < this->head || i > this->tail)
        //        cout << "---" << endl;
        //    else
        //        imprimeElemento(this, i);
        //else
        //    if (i < this->head && i > this->tail)
        //        cout << "---" << endl;
        //    else
                imprimeElemento(this, i);
    }
}
