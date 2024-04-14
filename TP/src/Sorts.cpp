#include "Sorts.h"

void merge(PontoAngulo vetor[], int inicio, int divisao, int fim) {
  
    // Cria os vetores L ← vetor[inicio, ... divisao] e M ← vetor [divisao + 1, ... fim]
    int n1 = divisao - inicio + 1;
    int n2 = fim - divisao;
    PontoAngulo L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++)
        M[j] = vetor[divisao + 1 + j];

    // Índices
    int i, j, k;
    i = 0;
    j = 0;
    k = inicio;

    // Nessa adaptação, a comparação é feita em relação ao ângulo armazenado no TAD PontoAngulo
    while (i < n1 && j < n2) {
        if (L[i].angulo <= M[j].angulo) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(PontoAngulo vetor[], int inicio, int fim) {

    // Recursivamente, divide o array em subarrays, os ordena e os junta (merge)
    if (inicio < fim) {
        // Ponto de divisão
        int divisao = inicio + (fim - inicio) / 2;

        // Fase de divisão
        mergeSort(vetor, inicio, divisao);
        mergeSort(vetor, divisao + 1, fim);

        // Fase de conquista
        merge(vetor, inicio, divisao, fim);
    }
}

void Insercao(PontoAngulo vetor[], int tam) {

    int i,j;
    PontoAngulo aux;
    for (i = 1; i < tam; i++) {
        aux = vetor[i];
        j = i - 1;
        // A comparação é feita em relação ao ângulo armazenado no TAD PontoAngulo
        while (( j >= 0 ) && (aux.angulo < vetor[j].angulo)) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}

void bucketSort(PontoAngulo vetor[], int tam) {
    // Pela forma que eu formulei os algoritmos que calculam os fechos convexos, o ângulo percente ao intervalo [0°, 180°).
    // Diante disso, divido em 9 baldes, ou seja, dividindo os pontos de acordo com seus ângulos, de 20° em 20°.
    const int numBaldes = 9;

    // Cria os baldes e seus respectivos tamanhos
    PontoAngulo baldes[numBaldes][tam];
    int tamanhosbaldes[numBaldes] = {0};

    for(int i = 0; i < tam; i++) {
        int indiceBalde = (int)(vetor[i].angulo / 20.0f); // Para que cada balde armazene os pontos no intervalo adequado
        baldes[indiceBalde][tamanhosbaldes[indiceBalde]] = vetor[i];
        tamanhosbaldes[indiceBalde]++; // Aumentando o tamanho do balde indiceBalde
    }

    // Ordenando cada balde por meio da ordenação por inserção, já implementada
    for(int i = 0; i < numBaldes; i++) {
        Insercao(baldes[i], tamanhosbaldes[i]);
    }

    // Concatenando esses baldes no vetor final
    int idx = 0;
    for(int i = 0; i < numBaldes; i++) {
        for(int j = 0; j < tamanhosbaldes[i]; j++) {
            vetor[idx] = baldes[i][j];
            idx++;
        }
    }
}
