#include <stdio.h>
#include <stdlib.h>

void printNodes();
void push(int x);
int pop();

typedef struct nodo {
    int info;
    struct nodo *sig; // apuntador hacia el siguiente nodo
} nodo;

nodo *raiz = NULL;

void main()
{
    printf("--Pilas dinamicas--\n");
    int opt;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Mostrar\n0. Finalizar\n");
        printf(">> ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Numero a ingresar: ");
            scanf("%d", &opt);
            push(opt);
            opt = -1;
            break;
        case 2:
            printf("Numero que sale de la pila: %d\n", pop());
            break;
        case 3:
            printf("La pila se ve asi:\n");
            printNodes();
            break;
        case 0:
            printf("...");
            break;
        default:
            printf("No se vale\n");
            break;
        }
    } while (opt != 0);
}

void printNodes()
{
    if (raiz == NULL)
    {
        printf("--La pila esta vacia\n");
    }
    else
    {
        nodo *elemento = raiz;
        while (elemento != NULL)
        {
            printf(" %d", elemento -> info);
            elemento = elemento -> sig;
        }
    }

    printf("\n");
}

void push(int x)
{
    nodo *nuevo = malloc(sizeof(nodo));
    nuevo -> info = x;
    nuevo -> sig = NULL;

    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        nodo *elem = raiz;
        while (elem -> sig != NULL)
            elem = elem -> sig;

        elem -> sig = nuevo;
    }
}

int pop()
{
    if (raiz == NULL)
    {
        printf("--UNDERFLOW--\n");
        return -1;
    }

    nodo *elem = raiz, *prev = NULL;

    while (elem -> sig != NULL)
    {
        prev = elem;
        elem = elem -> sig;
    }

    int valor = elem -> info;

    if (prev == NULL)  // Solo un nodo
        raiz = NULL;
    else
        prev -> sig = NULL;

    free(elem);

    return valor;
}