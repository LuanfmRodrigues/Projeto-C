// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
void produtos(int &qtd, string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");
    for (int i = 0; i < contador; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << mat[i][j] << "\t|";
        }
        cout << "\n";
    }

    

}
void adicionarEx(int &qtd, string &id, string** mat, string &nome, double& preco, int& quantidade, int& contador)
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

    //int contadorinterno = 0;//para quando se refizer a ação nao mostrar os itens todos que foram adicionados
    char choice4;
    do{  
        // o contador interno nao tava deixando atualizar, tive que retirar e acrescentar o contador +1
        mat[contador][0]=to_string(contador +1);
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
    for (int i = 0; i < contador; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << left << setw(15) << mat[i][j]<< "\t|";
        }
        cout << "\n";
    }
}


void remover(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");

    int valorid;
    char choice5;
    
    cout << "\tQual o id do produto que quer remover: \n";
    cin >> valorid;
    
    //validação se existe o id do produto.
    if( valorid < 1 || valorid > contador)
    {
        cout << "\nId informado não existe!!!\n";
    }

    valorid = valorid -1;

    cout << "\tNome do produto: " << mat[valorid][1]<< "\n";
    cout << "\tQuantidade do produto: " << mat[valorid][2]<< "\n";
    cout << "\tPreço do produto: " << mat[valorid][3]<< endl<< "\n";

    cout << " Deseja remover o o produto, (s/n)";
    cin >> choice5;

   if(choice5 == 's' || choice5 == 'S')
   {
    // o loop vai deslocar o produto solicitado para ultima posição.
      
    for (int i = valorid; i < contador -1 ; i++)
    {
        mat[i][0] = mat[i+1][0];
        mat[i][1] = mat[i+1][1];        mat[i][2] = mat[i+1][2];
        mat[i][3] = mat[i+1][3];
    }
     // o contador é -1 para limpar o ultimo produto.
    mat[contador -1][0]= "";
    mat[contador -1][1]= "";
    mat[contador -1][2]= "";
    mat[contador -1][3]= "";
    contador --;

    //o loop é para atualizacao dos ids do produtos fazendo andar uma casa, para não ficar um buraco entre ids apos ser removido.  
    for (int i = valorid; i < contador; i++)
    {
        mat[i][0] = to_string(i + 1); 
    }

    cout << "\nProduto removido!\n";
   }else{
    cout << "\nRemoção cancelada\n";
   }
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
            remover(qtd,id, mat, nome, preco, quantidade, contador);//Para remover artigos do stock existente
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
void adicionarCarrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho)
{
    system("cls");
    int escolha;
    int carrinholoop = 1;
    do {
        system("cls");
        for (int i = 0; i < contador; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << left << setw(15) << mat[i][j] << "\t|";
            }
            cout << "\n";
        }
        cout << "Introduza o id do produto que deseja adicionar ao carrinho: \n";
        cin >> id;
        cout << "E a sua quantidade: \n";
        cin >> quantidade;

        if (quantidade > stoi(mat[stoi(id) - 1][2]))
        {
            cout << "\nNão existe stock suficiente\n";
        }
        else
        {
            for (int i = 0; i < carrinholoop; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    carrinho[i][j] = mat[stoi(id)][j];//acrescentar a matriz do carrinho o produto da matriz com o stock
                }
            }
            carrinho[stoi(id)][2] = quantidade;
            cout << "\n Carrinho: \n";
            for (int i = 0; i < carrinholoop; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << carrinho[i][j];
                }
            }
            carrinholoop++;
        }
        cout << "\nContinuar = 1\n";
        cout << "\nSair = 0\n";
        cin >> escolha;
    } while (escolha != 0);

}
void removerCarrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho)
{
    system("cls");

}
void Carrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho)
{
    system("cls");
    /*adicionar item ao carrinho, adicionar quantidade de item
     remover item do carrinho, remover quantidade do item
     venda.
     sair.
     */
    int escolha;
    do {
        cout << "\n \tCarrinho \n" << "1-Adicionar ao carrinho \n" << "2-Remover do carrinho\n" << "3-Venda\n" << "4-Sair\n";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            adicionarCarrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho);
            break;
        case 2:
            removerCarrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho);
            break;
        case 3:
            break;
        case 4:
            cout << "Sair \n";
            break;
        default:
            cout << "Escolha outra opçãp.\n";
            break;
        }

    } while (escolha != 3);
}
void Venda()
{
    system("cls");
    /*Fatura
    troco
    listar produtos
    data
    cliente aleatorio que nao paga
    iva 
    numero do cliente
    numero fatura
    total sem e com iva
    valor pago*/
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
    string** carrinho = new string * [20];//matriz onde se guarda os valores do carrinho de venda

    //inicialização da matriz
    for (int i = 0; i < 100; i++)
    {
        mat[i] = new string[qtd];
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = "";
        }
    }
    for (int i = 0; i < 20; i++)
    {
        carrinho[i] = new string[20];
        for (int j = 0; j < 3; j++)
        {
            carrinho[i][j] = "";
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
            Carrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho); //Chamar função para o carrinho que vai permitir fazer vendas
            break;
        case 3:
            cout << "Sair \n";
        default:
            cout << "Escolha outra opçãp.\n";
            break;
        }
        
    } while (choice != 3);
}