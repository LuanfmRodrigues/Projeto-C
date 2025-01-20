// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <string>
using namespace std;
// Maximo de produtos no estoque podemos vem outra forma de limitar.
const int MaxProdutos = 60;

void produtos()
{
    //id, nome, quantidade,preco,qtd
    

}
void adicionarex()
{
}
void adicionarnovo(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int &contador)
{  
    contador = 0;
    char choice4;
    do{  
        contador++;
        mat[contador][0]=to_string(contador);
        cout << "Introduzir o nome: ";
        cin >> mat[contador][1];
        cout << "Introduzir a quantidade: ";
        cin >> mat[contador][2];
        cout << "Introduzir o preco: ";
        cin >> mat[contador][3];
        cout << "Deseja adicionar mais produtos?.. (s/n)";
        cin >> choice4;
            
        
    }while (choice4 == 's' || choice4 == 'S');
    for (int i = 0; i < contador+1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[i][j]<< "\t";
        }
        cout << "\n";
    }
}


void remover(){}

//Lembrar que tem que declarar os ponteiros nos parametros para poder pecorre entre funcoes.  
void adicionar(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    int choice3;
    do
    {
        cout << "\n Selecione a opção: \n" << "1- Adicionar Quantidade de produto\n" << "2- Adicionar produto novo\n" << "3- Voltar\n";
        cin >> choice3;
        switch (choice3)
        {
        case 1:
            //Adicionar a um produto ja existente
            adicionarex();
            break;
        case 2:
            
            adicionarnovo(qtd, id, mat, nome, preco, quantidade, contador);
            break;
        case 3:
            break;
        default:
            cout << "\nOpcao errada, tente novamente.\n";
            break;
        }
    
    } while (choice3!= 3);




}
void Stock()
{
    //Tamanho dos ponteiros de quantidade
    int qtd = 100;
    int contador = 0;
    string id;
    string** mat= new string*[qtd];
    string nome;
    double preco;
    int quantidade;
    int choice1;
    
    for (int i = 0; i < 100; i++)
    {
        mat[i] = new string[qtd];
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = "";
        }
    }
    

        
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
            produtos();//Para visualizar os produtos existentes
            break;
        case 4:
            break;
        default:
            cout << "\nOpcao errada, tente novamente.\n";
            break;
        }
    } while (choice1 != 4);
}
void Carrinho() {}
void Venda() {}


int main()
{

    setlocale(LC_ALL, "");
    int choice;
    do {
        cout << "\n \tMenu Principal \n" << "1-Stock \n" << "2-Carrinho\n" << "3-Sair\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Stock();    //Chamar função para entrar no stock, onde se localiza tudo em rela��o a adicionar remover e visualizar stock
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