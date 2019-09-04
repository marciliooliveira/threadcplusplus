#include <iostream>
#include <random>
#include <thread>
#include <cmath>
#include <mutex>

using namespace std;
mutex mtx;

int nInternos = 0;
int niter = 1000000;

void calculaMonteCarlo () {

    int total=0;
    double z;
    double pi;
    srand(time(NULL));
    double x, y;
    for (int i=1; i<=niter/2; i++)
    {
        x = (double)random()/RAND_MAX;
        y = (double)random()/RAND_MAX;
        z = sqrt((x*x)+(y*y));

        if (z<=1)
        {
            total++;
        }
    }

    mtx.lock();
    nInternos += total;
    mtx.unlock();

}

int main()
{

    auto inic = chrono::high_resolution_clock::now();

    thread t1(calculaMonteCarlo);
    thread t2(calculaMonteCarlo);

    t1.join();
    t2.join();

    double pi = ((double)nInternos/(double)niter)*4.0;          //p = 4(m/n)
    cout << pi << endl;

    return 0;
}
