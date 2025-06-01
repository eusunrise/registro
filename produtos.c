#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40

struct Produto {
    int codigo;
    char descricao[50];
    float valorUnitario;
    int estoque;
};

void cadastrarProduto(struct Produto produtos[], int *quantidade) {
    if (*quantidade < MAX_PRODUTOS) {
        printf("Código: ");
        scanf("%d", &produtos[*quantidade].codigo);
        printf("Descrição: ");
        scanf(" %[^\n]", produtos[*quantidade].descricao);
        printf("Valor unitário: ");
        scanf("%f", &produtos[*quantidade].valorUnitario);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[*quantidade].estoque);
        (*quantidade)++;
    } else {
        printf("Limite atingido.\n");
    }
}

void alterarValorUnitario(struct Produto produtos[], int quantidade, int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Novo valor unitário: ");
            scanf("%f", &produtos[i].valorUnitario);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

float obterValorUnitario(struct Produto produtos[], int quantidade, int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].valorUnitario;
        }
    }
    return -1;
}

int obterEstoque(struct Produto produtos[], int quantidade, int codigo) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].estoque;
        }
    }
    return -1;
}

void realizarVenda(struct Produto produtos[], int quantidade, int codigo, int qtdDesejada) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            if (produtos[i].estoque == 0) {
                printf("Sem estoque.\n");
                return;
            }
            if (produtos[i].estoque >= qtdDesejada) {
                produtos[i].estoque -= qtdDesejada;
                printf("Total: R$ %.2f\n", produtos[i].valorUnitario * qtdDesejada);
                return;
            } else {
                printf("Estoque insuficiente. Deseja comprar o restante (%d)? (1-Sim / 0-Não): ", produtos[i].estoque);
                int opcao;
                scanf("%d", &opcao);
                if (opcao == 1) {
                    printf("Total: R$ %.2f\n", produtos[i].valorUnitario * produtos[i].estoque);
                    produtos[i].estoque = 0;
                }
                return;
            }
        }
    }
    printf("Produto não encontrado.\n");
}

void atualizarEstoque(struct Produto produtos[], int quantidade, int codigo, int novaQtd) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigo) {
            produtos[i].estoque = novaQtd;
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void listarProdutos(struct Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

void listarProdutosSemEstoque(struct Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].estoque == 0) {
            printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
        }
    }
}
