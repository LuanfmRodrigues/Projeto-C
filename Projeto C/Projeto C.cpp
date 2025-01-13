// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
using namespace std;

void produtos(int* id, int qtd, string *nome, int* quantidade, double* preco)
{
if(qtd==0)
{
    cout << "\n Nao existe stock";
}else 
{
    for (int i = 0; i < qtd; i++)
    {
        cout << "Id: " << id <<"\t Nome: "<< nome << "\t Quantidade: " << quantidade << "\t Preco: " << preco;
    }
}
}
void adicionarex(){}
void adicionarnovo()
{
    cout << "\nIntroduza o id do produto\n";
}
void remover(){}
void adicionar(int* id, int qtd, string* nome, int* quantidade, double* preco)
{
    int choice3;
    do
    {
        cout << "\n Selecione a opção: \n" << "1- Adicionar produto\n" << "2- Adicionar produto novo\n" << "3- Voltar\n";
        cin >> choice3;
        switch (choice3)
        {
        case 1:
            //Adicionar a um produto ja existente
            adicionarex();
            break;
        case 2:
            //adicionar produto novo a lista
            adicionarnovo();
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
    int qtd = 0;//Tamanho dos ponteiros de quantidade
    int* id = new int[qtd];
    string* nome = new string;
    int* quantidade= new int[qtd];
    double* preco= new double[qtd];
    int choice1;
    
    do
    {
        cout << "\n 1-Addicionar produto \n" << "\n 2-Remover produto \n" << "\n 3- Produtos \n" << "\n 4-Sair \n";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            adicionar(id, qtd, nome, quantidade, preco);//Para adicionar artigos ao stock ou acrescentar ao stock existente
            break;
        case 2:
            remover();//Para remover artigos do stock existente
            break;
        case 3:
            produtos(id, qtd, nome, quantidade, preco);//Para visualizar os produtos existentes
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
            Stock();    //Chamar função para entrar no stock, onde se localiza tudo em relação a adicionar remover e visualizar stock
            break;
        case 2:
            Carrinho(); //Chamar função para o carrinho que vai permitir fazer vendas
            break;
        default:
            break;
        }
        
    } while (choice != 3);
}