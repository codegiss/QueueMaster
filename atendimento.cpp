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

struct Guiche
{
    int id;
    Fila *senhasAtendidas;
    Guiche *prox;
};

struct FilaGuiche
{
    Guiche *ini;
    Guiche *fim;
};

Fila *init()
{
    Fila *f = new Fila();
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

FilaGuiche *initGuiche() {
    FilaGuiche *g = new FilaGuiche();
    g->ini = NULL;
    g->fim = NULL;
    return g;
}

int isEmpty(Fila *f)
{
    return (f->ini == NULL);
}

int isEmptyGuiche(FilaGuiche *f)
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

void enfileirarGuiches(FilaGuiche *g, int i) {
    Guiche *guiche = new Guiche();
    guiche->id = i+1;
    guiche->prox = NULL;

    if (isEmptyGuiche(g))
    {
        g->ini = guiche;
    }
    else
    {
        g->fim->prox = guiche;
    }
    g->fim = guiche;
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
    Fila *senhasGeradas;
    senhasGeradas = init();

    FilaGuiche *guiches;
    guiches = initGuiche();

    int op = -1;
    int idAtendimento;
    int ultimoIdGuiche = 0;
    int ultimaGerada = 0;
    int ultimaAtendida;
    int qtdAtendidas = 0;

    do
    {
        do
        {
            cout << "Senhas aguardando atendimento: " << (ultimaGerada - qtdAtendidas) << endl;
            cout << "Escolha uma opcao:" << endl;
            cout << "0. Sair" << endl;
            cout << "1. Gerar senha" << endl;
            cout << "2. Abrir guiche" << endl;
            cout << "3. Realizar atendimento" << endl;
            cout << "4. Listar senhas atendidas" << endl;
            cout << "Opcao escolhida: ";
            cin >> op;
        } while (op != 0 && op != 1 && op != 2 && op != 3 && op != 4);

        if (op == 0 && !isEmpty(senhasGeradas))
        {
            cout << "Atenda todas as senhas antes de sair.";
            op = -1;
        }
        else
        {
            switch (op)
            {
            case 1:
                enfileirar(senhasGeradas, ultimaGerada);
                ultimaGerada++;
                cout << "Senha gerada: " << ultimaGerada << endl;
                cout << endl;
                break;
            case 2:
                // adicionar numa lista um struct com id do guiche
                // e fila pra armazenar as senhas que atendeu
                enfileirarGuiches(guiches, ultimoIdGuiche);
                ultimoIdGuiche++;
                cout << "Guiche gerado com id: " << ultimoIdGuiche << endl;
                cout << endl;
                break;
            case 3:
                if(ultimoIdGuiche==0) {
                    cout << "Nenhum guiche foi criado. Crie um para iniciar o atendimento." << endl;
                    cout << endl;
                }
                else {
                    // solicitar id do guiche que vai atender
                    cout << "Digite o id do guiche: ";
                    cin >> idAtendimento;

                    if (idAtendimento > ultimoIdGuiche)
                    {
                        cout << "O id digitado nao pertence a nenhum guiche." << endl;
                        cout << endl;
                    }
                    else
                    {
                        if (isEmpty(senhasGeradas))
                        {
                            cout << "Nao ha senhas aguardando atendimento." << endl;
                            cout << endl;
                        }
                        else
                        {
                            // enfileirar a senha atendida na fila desse guiche
                            ultimaAtendida = desenfileirar(senhasGeradas);
                            cout << "Senha atendida: " << ultimaAtendida << endl;
                            qtdAtendidas++;
                            cout << endl;
                        }
                    }
                }
                break;
            case 4:
                // pedir o id do guiche e mostrar as senhas atendidas
                cout << "Digite o id do guiche: ";
                cin >> idAtendimento;

                if (idAtendimento > ultimoIdGuiche)
                {

                }
                else {
                    cout << "O id digitado nao pertence a nenhum guiche." << endl;
                    cout << endl;
                }
                break;
            }
        }
    } while (op != 0);

    cout << "Total de senhas atendidas: " << qtdAtendidas << endl;

    return 0;
}