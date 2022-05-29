#include <iostream>
#include "Vector.h"
#include <vector>
#include <sstream>
#include <chrono>



using namespace std;

int main()
{
    int sz = 100000000;
    int indeksas = 0;
    vector<long int> a;
    Vector<long int> b;
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    for (int i = 1; i < sz; i++) {
        if (a.capacity() == a.size()) {
            indeksas++;
        }
        a.push_back(i);
    }
    cout << indeksas << endl;
    indeksas = 0;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "STL 10000 eiluciu: " << diff.count() << " s\n";


    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < sz; i++) {
        if (b.capacity() == b.size()) {
            indeksas++;
        }
        b.push_back(i);
    }
    cout << indeksas;
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << "CUSTOM 10000 eiluciu: " << diff.count() << " s\n";
}

