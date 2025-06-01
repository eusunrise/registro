#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 26

struct Estado {
    char nome[30];
    int veiculos;
    int acidentes;
};

void coletarDados(struct Estado estados[]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Nome do estado %d: ", i + 1);
        scanf(" %[^\n]", estados[i].nome);
        printf("Número de veículos em %s: ", estados[i].nome);
        scanf("%d", &estados[i].veiculos);
        printf("Número de acidentes em %s: ", estados[i].nome);
        scanf("%d", &estados[i].acidentes);
    }
}

void maiorEMenorAcidentes(struct Estado estados[], int *indiceMaior, int *indiceMenor) {
    int maior = estados[0].acidentes;
    int menor = estados[0].acidentes;
    *indiceMaior = 0;
    *indiceMenor = 0;

    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].acidentes > maior) {
            maior = estados[i].acidentes;
            *indiceMaior = i;
        }
        if (estados[i].acidentes < menor) {
            menor = estados[i].acidentes;
            *indiceMenor = i;
        }
    }
}

float percentualVeiculosEmAcidentes(struct Estado estados[], int indice) {
    return ((float)estados[indice].acidentes / estados[indice].veiculos) * 100;
}

float mediaAcidentes(struct Estado estados[]) {
    int total = 0;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        total += estados[i].acidentes;
    }
    return (float)total / NUM_ESTADOS;
}

void estadosAcimaDaMedia(struct Estado estados[], float media) {
    printf("Estados acima da média de acidentes:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf("%s\n", estados[i].nome);
        }
    }
}
