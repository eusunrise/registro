#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

struct Conta {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[20];
    float saldo;
};

int buscarConta(struct Conta contas[], int qtd, int numero) {
    if (qtd == 0) return -1;
    for (int i = 0; i < qtd; i++) {
        if (contas[i].numero == numero) return i;
    }
    return -2;
}

void cadastrarConta(struct Conta contas[], int *qtd, int numero) {
    int pos = buscarConta(contas, *qtd, numero);
    if (pos >= 0) {
        printf("Número de conta já existe.\n");
        return;
    }

    contas[*qtd].numero = numero;
    printf("Nome: ");
    scanf(" %[^\n]", contas[*qtd].nome);
    printf("CPF: ");
    scanf(" %[^\n]", contas[*qtd].cpf);
    printf("Telefone: ");
    scanf(" %[^\n]", contas[*qtd].telefone);
    contas[*qtd].saldo = 0.0;
    (*qtd)++;
}

void consultarSaldo(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos >= 0) {
        printf("Saldo: R$ %.2f\n", contas[pos].saldo);
    } else {
        printf("Conta não encontrada.\n");
    }
}

void depositar(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor do depósito: ");
        scanf("%f", &valor);
        contas[pos].saldo += valor;
    } else {
        printf("Conta não encontrada.\n");
    }
}

void sacar(struct Conta contas[], int qtd, int numero) {
    int pos = buscarConta(contas, qtd, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor do saque: ");
        scanf("%f", &valor);
        if (contas[pos].saldo >= valor) {
            contas[pos].saldo -= valor;
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else {
        printf("Conta não encontrada.\n");
    }
}

void listarContas(struct Conta contas[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Conta: %d | Nome: %s | Telefone: %s\n", contas[i].numero, contas[i].nome, contas[i].telefone);
    }
}
