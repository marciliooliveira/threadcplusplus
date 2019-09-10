#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "filaCircular.h"
#include <thread>
#include <windows.h>
#include <cstring>
#include <ctime>

using namespace std;
Fila f;
void chegadaPedidos()
{
    for (int i = 0; i < 50; i++)
    {
        Pedido p;
        p.geraPedido();
        f.enqueue(p);
        Beep(523,200);
        Sleep(rand()%5000+1000);
    }
}
void verFila()
{
    system("cls");
    f.exibir();
    system("pause");
    system("cls");
}
void atender()
{
    system("cls");
    if (!f.vazia())
    {
        Pedido p = f.dequeue();
        cout << "Atendendo cliente: " << p.numPedido << endl << p.descricao << endl;;
    }
    else
        cout << "NAO HA CLIENTES" << endl;
    system("pause");
    system("cls");
}
int main()
{
    f.inicializa();
    srand(time(0));
    thread t(chegadaPedidos);
    int opcao;
	do
    {
        cout << "1. VER FILA DE PEDIDOS" << endl;
        cout << "2. ATENDER PROXIMO CLIENTE" << endl;
        cout << "0. SAIR" << endl;
        cin >> opcao;
        switch (opcao)
        {
            case 1 : verFila(); break;
            case 2 : atender(); break;
        }
    }while(opcao != 0);
	t.join();
    return 0;
}
