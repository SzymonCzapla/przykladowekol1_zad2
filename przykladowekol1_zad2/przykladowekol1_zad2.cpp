#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

struct Tablica {
    double* tab = nullptr;
    int rozmiar = 0;
    int zmiany = 0;
};

void alokacja(Tablica& t, int rozmiar) {
    if (t.tab!=nullptr) {
        delete[] t.tab;
    }
    t.rozmiar = rozmiar;
    t.zmiany++;
    t.tab = new double[rozmiar];
}
void delalokacja(Tablica& t) {
    delete[] t.tab;
    t.tab = nullptr;
    t.rozmiar = 0;
    t.zmiany = 0;
}

int main()
{
    int rozmiar=0;
    double liczba;
    Tablica t;
    FILE* plik = nullptr;
    plik = fopen("text.txt", "r");
    while (fscanf(plik,"%lf,",&liczba) == 1) {
        rozmiar++;
    }
    fclose(plik);
    alokacja(t, rozmiar);
    plik = fopen("text.txt", "r");
    for (int i = 0; i < t.rozmiar; i++) {
        fscanf(plik, "%lf,", &t.tab[i]);
        cout << t.tab[i] << ", ";
    }
    fclose(plik);
    delalokacja(t);
    return 0;
}
