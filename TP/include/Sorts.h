#ifndef SORTS_H
#define SORTS_H

#include "Ponto-e-Fecho.h"

// Funções que, conjuntamente, executam o Mergesort
void merge(PontoAngulo vetor[], int inicio, int divisao, int fim);
void mergeSort(PontoAngulo vetor[], int inicio, int fim);

// Função que executa o InsertionSort
void Insercao(PontoAngulo vetor[], int n);

// Função que realiza o Bucketsort
void bucketSort(PontoAngulo vetor[], int tam);

#endif