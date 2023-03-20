#ifndef __MATRIZ_HPP
#define __MATRIZ_HPP
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class Matriz
{
    private: 
        short int tamanho;
        short int total;

    public:
    Matriz();
    void setTamanho(short int tamanho);
        short int getTamanho();
    void setTotal(short int total);
        short int getTotal();
    void Leitura(fstream& arq, short int **mat);
    void Inicio(short int **mat);
};
#endif
