#include <fstream>
#include <cmath>

#include "FechoConvexo.h"
#include "PilhaEncadeada.h"
#include "Sorts.h"

int IndicePontoMaisEmbaixoEsquerda(Fecho pontos) {
    int ymin = pontos.fecho[0].y; // inicializamos um valor para a coordenada y mínima
    int indice = 0;

    for(int i = 1; i < pontos.tam; i++) {
        int y = pontos.fecho[i].y;
        if((y < ymin) || (ymin == y && pontos.fecho[i].x < pontos.fecho[indice].x)) {
            // Em caso de empate na coordenada y, desempatamos escolhendo o ponto mais à esquerda
            ymin = pontos.fecho[i].y;
            indice = i;
        }
    }

    return indice;

}

int orientacao(Ponto p1, Ponto p2, Ponto p3) {
    // Calcula o produto vetorial para descobrir a rotação feita
    long long int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if(val > 0) return 1; // horário
    else if (val < 0) return 2; // anti-horário
    
    return 0; // colinear
}

long long int dist(Ponto p1, Ponto p2) {
    // Utiliza do Teorema de Pitágoras para encontrar a distância ao quadrado entre dois pontos
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double calculaAngulo(Ponto p, Ponto central) {
    // A função atan2 calcula o arco tangente de um valor
    return std::atan2(p.y - central.y, p.x - central.x);
}

PontoAngulo* VetorAngulos(Fecho pontos, Ponto central) {
    PontoAngulo* angulos = new PontoAngulo[pontos.tam];
    
    for(int i = 0; i < pontos.tam; i++) {
        double ang = calculaAngulo(pontos.fecho[i], central);
        angulos[i].angulo = ang; // o ângulo é o formado utilizando o ponto mais embaixo a esquerda de referência
        angulos[i].p = pontos.fecho[i]; // guarda o ponto relativo à esse ângulo
    }

    return angulos; // retorna um vetor de PontoAngulo
}

void printFecho(Fecho PontosFecho) {
    // Imprime o fecho convexo com base nas especificações do TP
    std::cout << "FECHO CONVEXO:" << std::endl;
    for(int i = 0; i < PontosFecho.tam; i++) {
        std::cout << PontosFecho.fecho[i].x << " " << PontosFecho.fecho[i].y << std::endl;
    }
}


Fecho MarchaDeJarvis(Fecho pontos) {
    // Encontra o ponto mais embaixo e mais à esquerda e o marca como ponto inicial
    int p0 = IndicePontoMaisEmbaixoEsquerda(pontos);
    int paux;
    Fecho PontosFecho;

    do {
        // Adiciona o ponto atual ao fecho convexo
        PontosFecho.Insere(pontos.fecho[p0]);

        // Encontra o próximo ponto que faz uma rotação relativa no sentido anti-horário
        paux = (p0 + 1) % pontos.tam; // garante que paux esteja dentro do range
        for(int i = 0; i < pontos.tam; i++) {
            int orient = orientacao(pontos.fecho[p0], pontos.fecho[i], pontos.fecho[paux]);
            if (orient == 2 || (orient == 0 && dist(pontos.fecho[p0], pontos.fecho[i]) > dist(pontos.fecho[p0], pontos.fecho[paux]))) {
                // Para casos de pontos colineares, pega apenas as extremidades
                paux = i;
            }
        }

        p0 = paux;

    } while(p0 != IndicePontoMaisEmbaixoEsquerda(pontos)); // enquanto não contornarmos todo o fecho convexo

    return PontosFecho;
}


Fecho ScanDeGraham(Fecho pontos, std::string sort) {
    // Encontra o ponto mais embaixo e mais à esquerda e o marca como ponto inicial
    int p0 = IndicePontoMaisEmbaixoEsquerda(pontos);

    // Troca o ponto 0 guardado com esse ponto inicial, para evitar problemas na ordenação
    Ponto aux = pontos.fecho[0];
    pontos.fecho[0] = pontos.fecho[p0];
    pontos.fecho[p0] = aux;

    // Cria um vetor de PontoAngulo, para conseguirmos ordenar os pontos em relação ao ângulo que eles formam com o inicial
    PontoAngulo* angulos = VetorAngulos(pontos, pontos.fecho[0]);

    // Ordenação
    if(sort == "insert") {
        // Faz o Insertion Sort
        Insercao(angulos, pontos.tam);

    }
    else if(sort == "merge") {
        // Faz o Merge Sort
        mergeSort(angulos, 0, pontos.tam - 1);

    }
    else if(sort == "bucket") {
        // Faz o Bucket Sort
        bucketSort(angulos, pontos.tam);
    }
    
    PilhaEncadeada pilha;
    // Empilha o ponto inicial
    pilha.Empilha_Item(angulos[0]);
    // Empilha o ponto que faz o menor ângulo com o ponto inicial
    pilha.Empilha_Item(angulos[1]);

    for (int i = 2; i < pontos.tam; i++) {
        while (orientacao(pilha.AbaixoDoTopo().p, pilha.GetTopo().p, angulos[i].p) == 1) {
            // Enquanto formar uma rotação no sentido horário, desempilha
            pilha.Desempilha();
        }

        pilha.Empilha_Item(angulos[i]);

        // Tratamento dos casos de pontos colineares, para que selecionemos as extremidades
        int orient = orientacao(angulos[0].p, pilha.AbaixoDoTopo().p, angulos[i].p);
        if(orient == 0 && (dist(angulos[0].p, pilha.AbaixoDoTopo().p) > dist(angulos[0].p, angulos[i].p)))
            pilha.Desempilha();
    }

    Fecho PontosFecho = pilha.ObterFecho(); // Pegamos o que ficou armazenado na pilha (o fecho convexo)

    delete[] angulos; // Liberamos a memória alocada

    return PontosFecho;
}