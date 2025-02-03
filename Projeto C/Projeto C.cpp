// Projeto C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <random>
#include <chrono>
using namespace std;
void tempo()
{
    // Pega o tempo atual do sistema
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    // Usa localtime_s para obter a data e hora atual
    struct tm time_info;
    localtime_s(&time_info, &now_time); // Note que aqui usamos localtime_s

    // Exibe a data e hora formatada
    cout << "Data e Hora atuais: "
        << time_info.tm_mday << "/"
        << time_info.tm_mon + 1 << "/" // Meses começam de 0
        << time_info.tm_year + 1900 << " " // O ano começa de 1900
        << time_info.tm_hour << ":"
        << time_info.tm_min << ":"
        << time_info.tm_sec << endl;
}
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

int gerarNumero() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1000000, 9999999);
    return distrib(gen);
}
int faturanumero()
{
    random_device rd;
    mt19937 ger(rd());
    uniform_int_distribution<> distrib(100000000000, 999999999999);
    return distrib(ger);
}
void remover(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
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
            return;
        case 2:
            
            adicionarNovo(qtd, id, mat, nome, preco, quantidade, contador);
            return;
        case 3:
            return;
        default:
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            return;
        case 2:
            remover(qtd,id, mat, nome, preco, quantidade, contador);//Para remover artigos do stock existente
            return;
        case 3:
            produtos(qtd, id, mat, nome, preco, quantidade, contador);//Para visualizar os produtos existentes
            return;
        case 4:
            return;
        default:
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nOpcao errada, tente novamente.\n";
            break;
        }
    } while (choice1 != 4);
}
void adicionarCarrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& carrinholoop, int& sigma)
{
    system("cls");
    int escolha=1;
    do {
        system("cls");
        for (int i = 0; i < contador; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << mat[i][j] << "\t|";
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
                    carrinho[i][j] = mat[stoi(id) - 1][j];//acrescentar a matriz do carrinho o produto da matriz com o stock
                }
            }
            mat[stoi(id) - 1][2] = to_string(stoi(mat[stoi(id) - 1][2]) - quantidade);
            carrinho[sigma][2] = to_string(quantidade);
           
            cout << "\n Carrinho: \n";
            for (int i = 0; i < carrinholoop; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << left << setw(15) << carrinho[i][j];
                }
                cout << "\n";
            }
            carrinholoop++;
            sigma++;
            cout << "Continuar = 1\n";
            cout << "Sair = 0\n";
            cin >> escolha;
            
        }
    } while (escolha != 0);
    
}
void removerCarrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& carrinholoop)
{
    system("cls");
    int valorid;
    char escolha1;


    cout << "Carrinho \n";
    for (int i = 0; i < carrinholoop; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << carrinho[i][j];
        }
        cout << "\n";
    }
    cout << " Qual id do produto que deseja remover: \n";
    cin >> valorid;

    for (int i = 0; i < contador; i++)
    {
        if (carrinho[i][0] == to_string(valorid))
        {
            cout << "ID: " << carrinho[i][0]
                << " | Nome: " << carrinho[i][1]
                << " | Quantidade: " << carrinho[i][2]
                << " | Preço: " << carrinho[i][3] << "\n";

            cout << "Deseja remover mesmo o produto? (S/N) \n";
            cin >> escolha1;

            if (escolha1 == 's' || escolha1 == 'S')
            {
                for (int j = 0; j < contador; j++)
                {
                    if (mat[j][0] == carrinho[i][0])
                    {
                        mat[j][2] = to_string(stoi(mat[j][2]) + stoi(carrinho[i][2]));
                        break;
                    }
                }


                for (int j = i; j < contador - 1; j++)
                {
                    carrinho[j][0] = carrinho[j + 1][0];
                    carrinho[j][1] = carrinho[j + 1][1];
                    carrinho[j][2] = carrinho[j + 1][2];
                    carrinho[j][3] = carrinho[j + 1][3];
                }
                carrinho[contador - 1][0] = "";
                carrinho[contador - 1][1] = "";
                carrinho[contador - 1][2] = "";
                carrinho[contador - 1][3] = "";
                contador--;


                contador--;
                cout << "\nProduto removido com sucesso!\n";
                return;
            }
            else
            {
                cout << "\nRemoção cancelada!\n";
                return;
            }
        }
    }

    cout << "\nID não existe!\n";

}
void impressaoFatura(int& numerocliente,int& numerofatura, int& valorpago, int& valorpagariva, int& carrinholoop, string** carrinho, int& numerovencedor, int& sigma, string** mat, string& id)
{
    int troco;
    cout << "Produtos comprados: \n";
    for (int i = 0; i < carrinholoop; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << carrinho[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "Fatura: " << numerofatura<< "\n";
    cout << "Nº Cliente: " << numerocliente << "\n";
    if(numerocliente == numerovencedor)
    {
        cout << "\t ~Parabens, ganhou a lotaria e esta isento de custo~\n";
        cout << "Valor a pagar: 0€\n";
        cout << "Troco: " << valorpago << "€";
        tempo();
        for (int i = sigma; i < carrinholoop; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                carrinho[i][j] = mat[stoi(id) - 1][j];//acrescentar a matriz do carrinho o produto da matriz com o stock
            }
        }
    }else
    {
        cout << "\t Pena nao ganhou a lotaria, irá pagar o valor total\n";
        cout << "Numero do vencedor: " << numerovencedor;
        cout << "Valor a pagar com iva: " << valorpagariva << "€" << "\n";
        cout << "Valor a pagar sem iva: " << valorpagariva * 0.77 << "€" << "\n";
        cout << "Iva: " << valorpagariva * 0.23 << "€" << "\n";
        cout << "Troco: " << valorpago - valorpagariva << "€";
        tempo();
        for (int i = sigma; i < carrinholoop; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                carrinho[i][j] = mat[stoi(id) - 1][j];//acrescentar a matriz do carrinho o produto da matriz com o stock
            }
        }
    }
    
    
}
void Sale(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& carrinholoop, int& numerovencedor, int& sigma)
{
    system("cls");
    char gooning;
    /*listar produtos
    data
    cliente aleatorio que nao paga
    aleatorito numero do cliente
    numero fatura
    troco
    iva 23%
    total sem e com iva
    valor pago*
    Fatura*/
    do {
        cout << "\t Carrinho \t";
        for (int i = 0; i < carrinholoop; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << left << setw(15) << carrinho[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "Deseja continuar para a compra: \n S/N";
        cin >> gooning;
        if (gooning == 'S' || gooning == 's')
        {
            int valorpago;
            int valorpagariva = 0;
            int numerocliente = gerarNumero();
            int numerofatura = faturanumero();
            for (int i = 0; i < carrinholoop; i++)
            {
                valorpagariva += (stoi(carrinho[i][3])*stoi(carrinho[i][2]));
            }
            cout << "O valora pagar é: " << valorpagariva << "\n" << "Introduza o valor que deseja pagar: \n";
            cin >> valorpago;
            if (valorpago<valorpagariva)
            {
                cout << "Falta dinheiro, tente novamente. \n";
            }else
            {
                impressaoFatura(numerocliente, numerofatura, valorpago, valorpagariva, carrinholoop, carrinho, numerovencedor,sigma, mat, id);
            }
        }
        else if (gooning == 'N' || gooning == 'n') {}
        else
        {
            cout << "Tente novamente deixe de ser estrubilho";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (gooning == 'N' || gooning == 'n');
}
void Carrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& numerovencedor)
{
    system("cls");
    /*adicionar item ao carrinho, adicionar quantidade de item
     remover item do carrinho, remover quantidade do item
     venda.
     sair.
     */
    int sigma = 0;
    int carrinholoop = 1;
    int escolha;
    do {
        if(carrinholoop==1)
        {
            cout << "Carrinho vazio";
        }else
        {
            for (int i = 0; i < carrinholoop; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << left << setw(15) << carrinho[i][j] << "\t";
                }
                cout << "\n";
            }
        }
        
        cout << "\n \tCarrinho \n" << "1-Adicionar ao carrinho \n" << "2-Remover do carrinho\n" << "3-Venda\n" << "4-Sair\n";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            adicionarCarrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho, carrinholoop, sigma);
            return;
        case 2:
            removerCarrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho, carrinholoop);
            return;
        case 3:
            Sale(qtd, id, mat, nome, preco, quantidade, contador, carrinho, carrinholoop, numerovencedor, sigma);
            return;
        case 4:
            cout << "Sair \n";
            return;
        default:
            cin.clear();//apaga a entrada invalida seja numero ou outro input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// ignora o input para nao dar o erro de loop constante 
            cout << "Escolha outra opçãp.\n";
            break;
        }

    } while (escolha != 3);
}
int main()
{
    system("cls");
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
    int numerovencedor = gerarNumero();
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
            Carrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho, numerovencedor); //Chamar função para o carrinho que vai permitir fazer vendas
            break;
        case 3:
            cout << "Sair \n";
        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Escolha outra opção.\n";
            break;
        }
        
    } while (choice != 3);
}