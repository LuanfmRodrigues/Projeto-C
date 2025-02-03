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
    cout << "Date and time: "
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
        cout << "ID: " << mat[i][0]
            << "  Name: " << mat[i][1]
            << "  Amount: " << mat[i][2]
            << "  Price: " << mat[i][3] << "\n";
    }

    

}
void adicionarEx(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador)
{
    system("cls");
    if (contador >= 1)
    {
        int valorid;
        int acrescento;
        cout << "Product ID you wish to add: ";
        cin >> valorid;
        while (!(cin))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input." << endl;
            cout << "Product ID: ";
            cin >> valorid;
        }
        if (valorid > contador || valorid < 0)
        {
            cout << "\nID doesnt exist";
        }
        else
        {
            valorid = valorid - 1;
            for (int i = 0; i < 4; i++)
            {
                cout << "ID: " << mat[i][0]
                    << "  Name: " << mat[i][1]
                    << "  Amount: " << mat[i][2]
                    << "  Price: " << mat[i][3] << "\n";
            }
            cout << "\nAmount you wish to add: ";
            cin >> acrescento;
            mat[valorid][2] = to_string(stoi(mat[valorid][2]) + acrescento);
            cout << "\nNew amount: " << mat[valorid][2];
        }
    }
    else{}
}
void adicionarNovo(int &qtd, string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");
    int aox;
    //int contadorinterno = 0;//para quando se refizer a ação nao mostrar os itens todos que foram adicionados
    char choice4;
    do{  
        // o contador interno nao tava deixando atualizar, tive que retirar e acrescentar o contador +1
        mat[contador][0]=to_string(contador +1);
        cout << "Name: ";
        cin >> mat[contador][1];
         cout << "Amount: ";
         cin >> aox;
         while (!(cin))
         {
             cin.clear();
             cin.ignore(INT_MAX, '\n');
             cout << "Invalid input." << endl;
             cout << "Amount: ";
             cin >> aox;
         }
         mat[contador][2]=to_string(aox);
         if(stoi(mat[contador][2])<=0)
         {
             cout << "Invalid value do you wish to try again? (y/n)\n";
             cin >> choice4;
         }
         else{
             cout << "Price: ";
             cin >> aox;
             while (!(cin))
             {
                 cin.clear();
                 cin.ignore(INT_MAX, '\n');
                 cout << "Invalid input." << endl;
                 cout << "Amount: ";
                 cin >> aox;
             }
             mat[contador][3] = to_string(aox);
             if (stoi(mat[contador][3]) <= 0) 
             {
                 cout << "Invalid value do you wish to try again? (y/n)\n";
                 cin >> choice4;
             }
             else
             {
                 contador++;//para depois representar o numero de itens totais no inventario
                 if (contador > qtd)
                 {
                     qtd++;
                 }
                 cout << "Do you wish to add more products?.. (y/n)\n";
                 cin >> choice4;
             }
             
         }
         
    }while (choice4 == 'y' || choice4 == 'Y');
    for (int i = 0; i < contador; i++)
    {
        cout << "ID: " << mat[i][0]
            << "  Name: " << mat[i][1]
            << "  Amount: " << mat[i][2]
            << "  Price: " << mat[i][3] << "\n";
    }
}

int gerarNumero() 
{
    //para gerar numero vencedor e do cliente
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> distrib(1000000, 9999999);
    long long numero;
    do {
        numero = distrib(gen);
    } while (numero <= 0);
    return (numero < 0) ? -numero : numero;
}
int faturanumero()
{
    //gera numero da fatura
    random_device rd;
    mt19937 ger(rd());
    uniform_int_distribution<long long> distrib(10000000, 99999999);
    long long numero;
    do {
        numero = distrib(ger);
    } while (numero <= 0);
    return (numero < 0) ? -numero : numero;//operador ternario usado para no caso de ser negativo retornar sempre positivo
}
void remover(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");
    for (int i = 0; i < contador; i++)
    {
        cout << "ID: " << mat[i][0]
            << "  Name: " << mat[i][1]
            << "  Amount: " << mat[i][2]
            << "  Price: " << mat[i][3] << "\n";
    }
    int valorid;
    char choice5;
    
    cout << "\tProduct ID: \n";
    cin >> valorid;
    while (!(cin))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input." << endl;
        cout << "Product ID: ";
        cin >> valorid;
    }
    
    //validação se existe o id do produto.
    if( valorid < 1 || valorid > contador)
    {
        cout << "\nId doesnt exist!!!\n";
    }

    valorid = valorid -1;

    cout << "\tName: " << mat[valorid][1]<< "\n";
    cout << "\tAmount: " << mat[valorid][2]<< "\n";
    cout << "\tPrice: " << mat[valorid][3]<< endl<< "\n";

    cout << " Do you wish to remove the product, (y/n)";
    cin >> choice5;

   if(choice5 == 'y' || choice5 == 'Y')
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

    cout << "\nProduct removed!\n";
   }else{
    cout << "\nRemoval cancelled\n";
   }
}   


//Lembrar que tem que declarar os ponteiros nos parametros para poder pecorre entre funcoes.  
void adicionar(int &qtd,string &id, string **mat, string &nome, double &preco, int &quantidade, int &contador)
{
    system("cls");

    int choice3;
    do
    {
        cout << "\n \tChoose: \n" << "1- Add existing\n" << "2- Add new\n" << "3- Exit\n";
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
            cout << "\nChoose another option.\n";
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
        cout << " 1-Add \n" << " 2-Remove \n" << " 3- Products \n" << " 4-exit \n";
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
            cout << "\nChoose another option.\n";
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
            cout << "ID: " << mat[i][0]
                << "  Name: " << mat[i][1]
                << "  Amount: " << mat[i][2]
                << "  Price: " << mat[i][3] << "\n";
        }
        cout << "Product ID: \n";
        cin >> id;
        while (!(cin))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input." << endl;
            cout << "Product ID: ";
            cin >> id;
        }
        cout << "Amount: \n";
        cin >> quantidade;
        while (!(cin))
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input." << endl;
            cout << "Amount: ";
            cin >> quantidade;
        }
        if (quantidade > stoi(mat[stoi(id) - 1][2]))
        {
            cout << "\nNot enough Stock\n";
            carrinho[carrinholoop - 1][0] = "";
            carrinho[carrinholoop - 1][1] = "";
            carrinho[carrinholoop - 1][2] = "";
            
        }
        else
        {
            for (int i = sigma; i < carrinholoop; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    carrinho[i][j] = mat[stoi(id) - 1][j];//acrescentar a matriz do carrinho o produto da matriz com o stock
                }
            }
            mat[stoi(id) - 1][2] = to_string(stoi(mat[stoi(id) - 1][2]) - quantidade);
            carrinho[sigma][2] = to_string(quantidade);
            carrinho[sigma][3] = mat[sigma][3];

           
            cout << "\n Carrinho: \n";
            for (int i = 0; i < carrinholoop; i++)
            {
                cout << "ID: " << carrinho[i][0]
                    << "  Name: " << carrinho[i][1]
                    << "  Amount: " << carrinho[i][2]
                    << "  Price: " << carrinho[i][3] << "\n";
            }
            carrinholoop++;
            sigma++;
            cout << "Continue: 1\n";
            cout << "Exit: 0\n";
            cin >> escolha;
            
        }
    } while (escolha != 0);
    
}
void removerCarrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& carrinholoop)
{
    system("cls");
    int valorid;
    char escolha1;


    cout << "Cart \n";
    for (int i = 0; i < carrinholoop; i++)
    {
        cout << "ID: " << carrinho[i][0]
            << "  Name: " << carrinho[i][1]
            << "  Amount: " << carrinho[i][2]
            << "  Price: " << carrinho[i][3] << "\n";
    }
  
    cout << " Product Id which you want to remove: \n";
    cin >> valorid;
    while (!(cin))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input." << endl;
        cout << "Product ID: ";
        cin >> valorid;
    }

    for (int i = 0; i < contador; i++)
    {
        if (carrinho[i][0] == to_string(valorid))
        {
            cout << "ID: " << carrinho[i][0]
                << "  Name: " << carrinho[i][1]
                << "  Amount: " << carrinho[i][2]
                << "  Price: " << carrinho[i][3] << "\n";

            cout << "Do you wish to remove the product? (Y/N) \n";
            cin >> escolha1;

            if (escolha1 == 'y' || escolha1 == 'Y')
            {
                for (int j = 0; j < contador; j++)
                {
                    if (mat[j][0] == carrinho[i][0])
                    {
                        mat[j][2] = to_string(stoi(mat[j][2]) + stoi(carrinho[i][2]));
                        break;
                    }
                }


                for (int j = i; j < carrinholoop - 1; j++)
                {
                    carrinho[j][0] = carrinho[j + 1][0];
                    carrinho[j][1] = carrinho[j + 1][1];
                    carrinho[j][2] = carrinho[j + 1][2];
                    carrinho[j][3] = carrinho[j + 1][3];
                }
                carrinho[carrinholoop - 1][0] = "";
                carrinho[carrinholoop - 1][1] = "";
                carrinho[carrinholoop - 1][2] = "";
                carrinho[carrinholoop - 1][3] = "";
                carrinholoop--;
                cout << "\nProduct removed successfully!\n";
                return;
            }
            else
            {
                cout << "\nRemoval cancelled!\n";
                return;
            }
        }
    }

    cout << "\nInvalid ID!\n";

}
void impressaoFatura(long long& numerocliente,long long& numerofatura, float& valorpago, float& valorpagariva, int& carrinholoop, string** carrinho, int& numerovencedor, int& sigma, string** mat, string& id)
{
    int troco;
    cout << "Products bought: \n";
    for (int i = 0; i < carrinholoop-1; i++)
    {
        cout << "ID: " << carrinho[i][0]
            << "  Name: " << carrinho[i][1]
            << "  Amount: " << carrinho[i][2]
            << "  Price: " << carrinho[i][3] << "\n";
    }
    cout << "Invoice: " << numerofatura<< "\n";
    cout << "Client number: " << numerocliente << "\n";
    if(numerocliente == numerovencedor)
    {
        cout << "\t Congrats you won the lottery\n";
        cout << "Price to pay: 0$\n";
        cout << "Change: " << valorpago << "$\n";
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
        cout << "\t You did not win the lottery\n";
        cout << "Winner: " << numerovencedor<<"\n";
        cout << "Price with VAT: " << valorpagariva *1.3 << "$" << "\n";
        cout << "Price without VAT: " << valorpagariva  << "$" << "\n";
        cout << "VAT: " << valorpagariva * 0.30 << "$" << "\n";
        cout << "Change: " << valorpago - (valorpagariva*1.3) << "$\n";
        tempo();
        for (int i = sigma; i < carrinholoop; i++)
        {
            for (int j = 0; j < 4; j++)
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
   
    
        cout << "\t Cart \n";
        if (carrinholoop>1)
        {
            for (int i = 0; i < carrinholoop-1; i++)
            {
                cout << "ID: " << carrinho[i][0]
                    << "  Name: " << carrinho[i][1]
                    << "  Amount: " << carrinho[i][2]
                    << "  Price: " << carrinho[i][3] << "\n";
            }
            cout << "Go to checkout: \n Y/N\n";
            cin >> gooning;
            if (gooning == 'Y' || gooning == 'y')
            {
                float valorpago;
                float valorpagariva = 0;
                long long numerocliente = gerarNumero();
                long long numerofatura = faturanumero();
                for (int i = 1; i < carrinholoop; i++)
                {
                    valorpagariva += stof(carrinho[i - 1][2]) * stof(carrinho[i - 1][3]);
                }
                cout << "Price to pay: " << valorpagariva * 1.3 << "\n" << "Introduce the amount of money to pay: \n";
                cin >> valorpago;
                while (!(cin))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input." << endl;
                    cout << "Amount: ";
                    cin >> valorpago;
                }
                if (valorpago < valorpagariva * 1.3)
                {
                    cout << "Not enough money try again. " << (valorpagariva * 1.3) + valorpago;
                    Sale(qtd, id, mat, nome, preco, quantidade, contador, carrinho, carrinholoop, numerovencedor, sigma);
                }
                else
                {
                    impressaoFatura(numerocliente, numerofatura, valorpago, valorpagariva, carrinholoop, carrinho, numerovencedor, sigma, mat, id);
                }
            }
            else if (gooning == 'N' || gooning == 'n')
            {

            }
            else
            {
                cout << "Try again";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }else{}
}
void Carrinho(int& qtd, string& id, string** mat, string& nome, double& preco, int& quantidade, int& contador, string** carrinho, int& numerovencedor, int& carrinholoop)
{
    system("cls");
    /*adicionar item ao carrinho, adicionar quantidade de item
     remover item do carrinho, remover quantidade do item
     venda.
     sair.
     */
    int sigma = 0;
    int escolha;
    do {
        if(carrinholoop==1)
        {
            cout << "\tEmpty Cart\t";
        }else
        {
            for (int i = 0; i < carrinholoop-1; i++)
            {
                cout << "ID: " << carrinho[i][0]
                    << "  Name: " << carrinho[i][1]
                    << "  Amount: " << carrinho[i][2]
                    << "  Price: " << carrinho[i][3] << "\n";
                cout << "\n";
            }
        }
        
        cout << "\n \tCarrinho \n" << "1-Add to Cart \n" << "2-Remove from Cart\n" << "3-Sale\n" << "4-Exit\n";
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
            cout << "Exit \n";
            return;
        default:
            cin.clear();//apaga a entrada invalida seja numero ou outro input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// ignora o input para nao dar o erro de loop constante 
            cout << "Choose another option.\n";
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
    int carrinholoop = 1;
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
    
    int choice;
    do {
        cout << "\n \tMain menu \n" << "1-Stock \n" << "2-Cart\n" << "3-Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Stock(qtd, id, mat, nome, preco, quantidade, contador);    //Chamar função para entrar no stock, onde se localiza tudo em rela��o a adicionar remover e visualizar stock
            break;
        case 2:
            Carrinho(qtd, id, mat, nome, preco, quantidade, contador, carrinho, numerovencedor, carrinholoop); //Chamar função para o carrinho que vai permitir fazer vendas
            break;
        case 3:
            cout << "Exit \n";
        default:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Choose another option.\n";
            break;
        }
        
    } while (choice != 3);
}