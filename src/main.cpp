#include "Matriz.hpp"
int main()
{
    Matriz *tabela = new Matriz();
    short int tamanho;
    string linha;
    fstream arq;

    arq.open("dataset/input.data");
    if(arq.is_open())
    {
        arq >> tamanho;
        getline(arq, linha);
        short int **mat = new short int* [tamanho];
        for(short int i=0; i<tamanho;i++)
            mat[i]=new short int[tamanho];
        tabela->setTamanho(tamanho);
        while(!arq.eof())
        {
            tabela->Leitura(arq,mat);
            if(tabela->getVerificador()==0)
                tabela->Inicio(mat);
        }
    }   
    arq.close();
}
