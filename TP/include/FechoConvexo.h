#ifndef FECHO_H
#define FECHO_H

#include <string>
#include "Ponto-e-Fecho.h"

// Função que retorna o índice do vetor de onde está o ponto mais embaixo e mais à esquerda
int IndicePontoMaisEmbaixoEsquerda(Fecho pontos);

// Função para determinar a orientação das curvas
int orientacao(Ponto p1, Ponto p2, Ponto p3);

// Função que retorna a distância ao quadrado entre dois pontos
long long int dist(Ponto p1, Ponto p2);

// Função que retorna o ângulo formado entre o ponto p e o ponto central de referência
double calculaAngulo(Ponto p, Ponto centro);

// Função que retorna um vetor para representar os ângulos formados entre o ponto inicial e os demais pontos
PontoAngulo* VetorAngulos(Fecho pontos, Ponto central);

// Função para imprimir os pontos contidos no Fecho
void printFecho(Fecho PontosFecho);

// Função que executa a Marcha de Jarvis
Fecho MarchaDeJarvis(Fecho pontos);

// Função que executa o Scan de Graham, com alguma das ordenações (merge, insert, bucket)
Fecho ScanDeGraham(Fecho pontos, std::string sort);

#endif