// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
using namespace std;
void produtos(int &qtd, string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");
    for (int i = 0; i < contador; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << "\t|";
        }
        cout << "\n";
    }

    

}
void adicionarEx(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador)
{
    system("cls");

    int valorid;
    int acrescento;
    cout << "Id do produto que quer acrescentar: ";
    cin >> valorid;
    if (valorid > contador && valorid < 1)
    {
        cout << "\nId introduzido invalido ou nao existente";
    }else
    {
        valorid=valorid - 1;
        for (int j = 0; j < 4; j++)
        {
            cout << mat[valorid][j] << "\t";
        }
        cout << "\nIntroduzir a quantidade do produto que deseja acrescentar: ";
        cin >> acrescento;
        mat[valorid][2] = to_string(stoi(mat[valorid][2]) + acrescento);
        cout << "\nNova quantidade: " << mat[valorid][2];
        
    }
}
void adicionarNovo(int &qtd, string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");

    int contadorinterno = 0;//para quando se refizer a ação nao mostrar os itens todos que foram adicionados
    char choice4;
    do{  
        contadorinterno++;
        mat[contador][0]=to_string(contadorinterno);
        cout << "Introduzir o nome: ";
        cin >> mat[contador][1];
        cout << "Introduzir a quantidade: ";
        cin >> mat[contador][2];
        cout << "Introduzir o preco: ";
        cin >> mat[contador][3];
        contador++;//para depois representar o numero de itens totais no inventario
        if (contador>qtd)
        {
            qtd++;
        }
        cout << "Deseja adicionar mais produtos?.. (s/n)\n";
        cin >> choice4;
            
        
    }while (choice4 == 's' || choice4 == 'S');
    for (int i = 0; i < contadorinterno; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[i][j]<< "\t|";
        }
        cout << "\n";
    }
}


void remover()
{
    system("cls");

}

//Lembrar que tem que declarar os ponteiros nos parametros para poder pecorre entre funcoes.  
void adicionar(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");

    int choice3;
    do
    {
        cout << "\n Selecione a opção: \n" << "1- Adicionar Quantidade de produto\n" << "2- Adicionar produto novo\n" << "3- Voltar\n";
        cin >> choice3;
        switch (choice3)
        {
        case 1:
            //Adicionar a um produto ja existente
            adicionarEx(qtd, id, mat, nome, preco, quantidade, contador);
            break;
        case 2:
            
            adicionarNovo(qtd, id, mat, nome, preco, quantidade, contador);
            break;
        case 3:
            break;
        default:
            cout << "\nOpcao errada, tente novamente.\n";
            break;
        }
    
    } while (choice3!= 3);




}
void Stock(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador)
{
    system("cls");
    int choice1;  
    do
    {
        cout << " 1-Adicionar \n" << " 2-Remover \n" << " 3- Produtos \n" << " 4-Sair \n";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            adicionar(qtd,id, mat, nome, preco, quantidade, contador);//Para adicionar artigos ao stock ou acrescentar ao stock existente
            break;
        case 2:
            remover();//Para remover artigos do stock existente
            break;
        case 3:
            produtos(qtd, id, mat, nome, preco, quantidade, contador);//Para visualizar os produtos existentes
            break;
        case 4:
            break;
        default:
            cout << "\nOpcao errada, tente novamente.\n";
            break;
        }
    } while (choice1 != 4);
}
void Carrinho()
{
    system("cls");
}
void Venda() 
{
    system("cls");
}


int main()
{
    //inicialização das variaveis todas
    int qtd = 100;
    int contador = 0;//contador de todos os produtos que se tem
    string id;
    string** mat = new string * [qtd];//matriz onde se guarda os valores de produtos todos
    string nome;
    double preco;
    int quantidade;

    //inicialização da matriz
    for (int i = 0; i < 100; i++)
    {
        mat[i] = new string[qtd];
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = "";
        }
    }
    setlocale(LC_ALL, "");
    int choice;
    do {
        cout << "\n \tMenu Principal \n" << "1-Stock \n" << "2-Carrinho\n" << "3-Sair\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Stock(qtd, id, mat, nome, preco, quantidade, contador);    //Chamar função para entrar no stock, onde se localiza tudo em rela��o a adicionar remover e visualizar stock
            break;
        case 2:
            Carrinho(); //Chamar função para o carrinho que vai permitir fazer vendas
            break;
        case 3:
            cout << "Sair \n";
        default:
            cout << "Escolha outra opçãp.\n";
            break;
        }
        
    } while (choice != 3);
}