#include <iostream>
#include <thread>

using namespace std;

struct foo {
    int x = 1;
    int y;
};

static struct foo f;

void sum_a()
{
    int s = 0;
    for (int i = 0; i < 100000000; i++)
        s += f.x;
}

void inc_b()
{
    for (int i = 0; i < 100000000; i++)
        ++f.y;
}


int main()
{

    // calcula tempo init

    thread t0(inc_b);
    thread t1(sum_a);

    t0.join();
    t1.join();

    //chamada sequencial!
    sum_a();
    inc_b();

    // calcula tempo finish

    return 0;
}
