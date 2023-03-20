#include "Matriz.hpp"

Matriz :: Matriz()
{
    this->tamanho=tamanho;
}

short int Matriz :: getTamanho()
{
    return tamanho;
}

short int Matriz :: getTotal()
{
    return total;
}

void Matriz :: setTamanho(short int tamanho)
{
    this->tamanho=tamanho;
}

void Matriz :: setTotal(short int total)
{
    this->total=total;
}


void Matriz :: Leitura(fstream& arq, short int **mat)
{
    string linha;
    vector <string> vectorfrase;
    vector <short int> vectorinteiro;
    getline(arq, linha);
    char *caracter, vector[linha.length()-1];
    strcpy(vector, linha.c_str());
    for(short int i=0; i<getTamanho(); i++)
    {
        caracter=strtok(vector," ");
        while (caracter)
        {
            vectorfrase.push_back(caracter);
            caracter = strtok(NULL," "); //até o caracter ser nulo
        }
        if(i!=getTamanho())
        {
            getline(arq, linha);
            strcpy(vector, linha.c_str());
        }
    }
    for(short int i=0; i<vectorfrase.size(); i++)
        vectorinteiro.push_back(stoi(vectorfrase[i]));
    short int progresso=0;
    for(short int i=0; i<getTamanho(); i++)
    {
        for(short int j=0; j<getTamanho(); j++)
        {
            mat[i][j]=vectorinteiro[progresso];
            progresso++;
        }
    }
    cout << "-----------------------------------------------------\n\n[MATRIZ]\n\n";
    for(short int i=0; i<getTamanho(); i++)
    {
        for(short int j=0; j<getTamanho(); j++)
        {
            cout << "[" << mat[i][j] <<"]\t";
        }
        cout<<"\n";
    }
}

void Matriz :: Inicio(short int **mat)
{
    short int linha, coluna;
    unsigned short int total=0;
    cout << "\nDigite as coordenadas da Matriz (linha - de 0 a " << getTamanho() << " - coluna - de 0 a " << getTamanho() <<") para o início da caminhada:\nLinha:";
    cin >> linha;
    cin.ignore();
    cout << "Coluna:";
    cin >> coluna;
    setTotal(mat[linha][coluna]);
    mat[linha][coluna]=-1;
    // j+1(direita) j-1(esquerda) i+1(baixo) i+1 e j+1(Diagonal direta) i+1 e j-1 (diagonal esquerda)
    while(linha+coluna != getTamanho()+getTamanho()-2)
    {
        total = total + getTotal();
        if(linha == getTamanho()-1)
        {
            coluna=coluna+1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        else if(coluna == getTamanho()-1)
        {
            linha=linha+1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        else if(mat[linha][coluna+1] >= mat[linha+1][coluna+1] && mat[linha][coluna+1] >= mat[linha+1][coluna] && mat[linha][coluna+1] >= mat[linha+1][coluna-1] && mat[linha][coluna+1] >= mat[linha][coluna-1])
        {
            coluna=coluna+1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        else if(mat[linha][coluna-1] >= mat[linha+1][coluna-1] && mat[linha][coluna-1] >= mat[linha+1][coluna] && mat[linha][coluna-1] >= mat[linha+1][coluna+1] && mat[linha][coluna-1] >= mat[linha][coluna+1])
        {
            coluna=coluna-1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna-1]=-1;
        }
        else if(mat[linha+1][coluna] >= mat[linha+1][coluna+1] && mat[linha+1][coluna] >= mat[linha][coluna+1] && mat[linha+1][coluna] >= mat[linha+1][coluna-1] && mat[linha+1][coluna] >= mat[linha][coluna-1])
        {          
            linha=linha+1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        else if (mat[linha+1][coluna+1] >= mat[linha][coluna+1] && mat[linha+1][coluna+1] >= mat[linha][coluna-1] && mat[linha+1][coluna+1] >= mat[linha+1][coluna] && mat[linha+1][coluna+1] >= mat[linha+1][coluna-1])
        {
            linha=linha+1;
            coluna=coluna+1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        else if(mat[linha+1][coluna-1] >= mat[linha][coluna+1] && mat[linha+1][coluna-1] >= mat[linha][coluna-1] && mat[linha+1][coluna-1] >= mat[linha+1][coluna] && mat[linha+1][coluna-1] >= mat[linha+1][coluna+1])
        {
            linha=linha+1;
            coluna=coluna-1;
            setTotal(mat[linha][coluna]);
            mat[linha][coluna]=-1;
        }
        if(linha==getTamanho()-1 && coluna==getTamanho()-1)
        {
            cout << "\n";
            for(short int i=0; i<getTamanho(); i++)
            {
                for(short int j=0; j<getTamanho(); j++)
                {
                    cout << "[" << mat[i][j] <<"]\t";
                }
                cout<<"\n";
            }
            total = total + getTotal();
            cout << "\nChegou ao fim!" << "\nTotal percorrido:" << total << endl;
        }
    }
}
