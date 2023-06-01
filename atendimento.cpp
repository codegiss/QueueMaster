#include <iostream>
using namespace std;

struct No
{
    float dado;
    struct No *prox;
};

struct Fila
{
    No *ini;
    No *fim;
};

Fila *init()
{
    Fila *f = new Fila();
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmpty(Fila *f)
{
    return (f->ini == NULL);
}

int count(Fila *f)
{
    int qtd = 0;
    No *no;
    no = f->ini;
    while (no != NULL)
    {
        qtd++;
        no = no->prox;
    }
    return qtd;
}

void enfileirar(Fila *f, float v)
{
    No *no = new No();
    no->dado = v + 1;
    no->prox = NULL;
    if (isEmpty(f))
    {
        f->ini = no;
    }
    else
    {
        f->fim->prox = no;
    }
    f->fim = no;
}

float desenfileirar(Fila *f)
{
    float ret;
    if (isEmpty(f))
    {
        ret = -1;
    }
    else
    {
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
    }
    return ret;
}

int main(int argc, char **argv)
{
    Fila *senha;
    senha = init();

    int op = -1;
    int ultimaGerada = 0;
    int qtdAtendidas = 0;

    do
    {
        do
        {
            cout << "Senhas aguardando atendimento: " << (ultimaGerada - qtdAtendidas) << endl;
            cout << "Escolha uma opcao:" << endl;
            cout << "0. Sair" << endl;
            cout << "1. Gerar senha" << endl;
            cout << "2. Realizar atendimento" << endl;
            cout << "Opcao escolhida: ";
            cin >> op;
        } while (op != 0 && op != 1 && op != 2);

        if (op == 0 && ultimaGerada != qtdAtendidas)
        {
            cout << "Atenda todas as senhas antes de sair.";
            op = -1;
        }
        else
        {
            switch (op)
            {
            case 1:
                enfileirar(senha, ultimaGerada);
                ultimaGerada++;
                cout << "Senha gerada: " << ultimaGerada << endl;
                cout << endl;
                break;
            case 2:
                if (isEmpty(senha))
                {
                    cout << "Nao ha senhas aguardando atendimento." << endl;
                    cout << endl;
                }
                else
                {
                    cout << "Senha atendida: " << desenfileirar(senha) << endl;
                    qtdAtendidas++;
                    cout << endl;
                }
                break;
            default:
                break;
            }
        }

    } while (op != 0);

    cout << "Total de senhas atendidas: " << qtdAtendidas << endl;

    return 0;
}