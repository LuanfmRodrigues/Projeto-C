// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
using namespace std;
// Maximo de produtos no estoque podemos vem outra forma de limitar.
const int MaxProdutos = 60;

void produtos(int* id, string *nome, int* quantidade, double* preco, int& qtd)
{

    if(qtd == 0)
    {
        cout << "\n Não existe stock \n";
    }else{
        cout << "\n Produtos no STOCK \n";
        for (int i = 0; i < qtd; i++){
            
            cout << "ID do produto: " << id[i] << "NOME do produto: " << nome[i] << "QUANTIDADE dos produtos: " << quantidade[i] << "PREÇO do produto: \n\n" << preco[i] << endl;      
            
        }
    }

}
void adicionarex(){}
void adicionarnovo( int* id, string* nome, int* quantidade, double* preco, int& qtd)
{
    //cout << "\nIntroduza o id do produto\n";
    //int qtd = 40;  

    char choice4;
    do{
        if (qtd >= MaxProdutos){
            cout << "\n ---------- STOCK CHEIO --------- \n";
            break;
        }   
        //ciacao dos produtos com sua viaveis. arrumar uma forma de o id ser automatico.
        cout << "insira o ID do produto: ";
        cin >> id[qtd];
        cin.ignore();
        cout << "Nome do produto: ";
        
        getline(cin, nome[qtd]);
        cout << "Quantidade de produtos: ";
        cin >>quantidade[qtd];
        cout << "Qual é o preço do produto: ";
        cin >> preco[qtd];
        qtd++;

            
        cout << "Deseja adicionar mais produtos?.. (s/n)";
        cin >> choice4;
            
        
    }while (choice4 == 's' || choice4 == 'S');

}


void remover(){}

//Lembrar que tem que declarar os ponteiros nos parametros para poder pecorre entre funcoes.  
void adicionar(int* id, string* nome,int* quantidade,double* preco,int& qtd)
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
            
            adicionarnovo(id, nome, quantidade, preco, qtd);
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
    int qtd = 0;
    int* id = new int[MaxProdutos];
    string* nome = new string[MaxProdutos];
    int* quantidade= new int[MaxProdutos];
    double* preco= new double[MaxProdutos];
    int choice1;

        
    do
    {
        cout << " 1-Adicionar \n" << " 2-Remover \n" << " 3- Produtos \n" << " 4-Sair \n";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            adicionar(id, nome, quantidade, preco, qtd);//Para adicionar artigos ao stock ou acrescentar ao stock existente
            break;
        case 2:
            remover();//Para remover artigos do stock existente
            break;
        case 3:
            produtos(id, nome, quantidade, preco, qtd);//Para visualizar os produtos existentes
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