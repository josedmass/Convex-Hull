#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include "Ponto-e-Fecho.h"

class Celula {
    public:
        // Construtores
        Celula();
    private:
        // Variáveis do Célula (item e apontador para a próxima célula)
        PontoAngulo item;
        Celula *prox;
        friend class PilhaEncadeada;
};

class PilhaEncadeada {
    public:
        // Construtor
        PilhaEncadeada();
        // Sobrecarga da atribuição de duas pilhas
        PilhaEncadeada(const PilhaEncadeada& other);
        PilhaEncadeada& operator=(const PilhaEncadeada& other);
        // Destrutor
        ~PilhaEncadeada();
        // Funções auxiliares que retornam, respectivamente, o topo da pilha e o seu tamanho
        PontoAngulo GetTopo();
        int GetTamanho();
        // Função auxiliar para dizer quem está abaixo do topo da pilha
        PontoAngulo AbaixoDoTopo();
        // Função que empilha elementos na pilha
        void Empilha_Item(PontoAngulo p);
        // Função para desempilhar elementos da pilha
        void Desempilha();
        // Função que retorna o que está armazenado na pilha na forma do TAD Fecho
        Fecho ObterFecho();
        // Função para limpar a pilha
        void Limpa();
    private:
        // Tamanho da pilha
        int tamanho;
        // Topo da pilha
        Celula* topo;
};

#endif