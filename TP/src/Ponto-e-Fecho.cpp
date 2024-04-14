#include "Ponto-e-Fecho.h"

#include <stdio.h>

Ponto::Ponto(long long int a, long long int b) {
    // Constrói o ponto com as coordenadas (a, b)
    x = a;
    y = b;
}

// Esse construtor não faz nada. É compromisso de quem cria uma variável do tipo Ponto definir os valores de x e y
Ponto::Ponto() {}

Fecho::Fecho() {
    // Constrói um fecho vazio, isto é, com tamanho zero e vetor nulo
    fecho = NULL;
    tam = 0;
}

Fecho::Fecho(const Fecho& other) {
    // Faz com que o fecho *this fique igual à other
    tam = other.tam;
    fecho = new Ponto[tam];

    for (int i = 0; i < tam; i++) {
        fecho[i] = other.fecho[i];
    }
}

Fecho& Fecho::operator=(const Fecho& other) {
    // Faz com que o fecho *this fique igual à other
    if(this == &other) return *this; // Se está atribuindo dois fechos iguais

    delete[] fecho; // deleta o fecho *this
    tam = other.tam;
    fecho = new Ponto[tam];

    for(int i = 0; i < tam; i++) {
        fecho[i] = other.fecho[i]; // iguala os fechos
    }

    return *this;
}

bool Fecho::operator==(const Fecho& other) const {
    // Faz com que a operação de igualdade entre dois fechos seja feita adequadamente
    if (tam != other.tam) {
        return false; // se a quantidade de pontos armazenados nos fechos é diferente, então eles não são iguais
    }

    if ((fecho == NULL && other.fecho != NULL) || (fecho != NULL && other.fecho == NULL)) {
        return false; // se um fecho é vazio e o outro não, então eles não são iguais
    }

    for (int i = 0; i < tam; i++) {
        if ((fecho[i].x != other.fecho[i].x) || (fecho[i].y != other.fecho[i].y)) {
            return false; // se existe algum ponto diferente entre os dois fechos, então eles não são iguais. Note que
        }                 // até mesmo a ordem deve ser igual.
    }

    return true; // se nenhuma das restrições acima ocorreram, então os fechos são iguais
}


void Fecho::Insere(Ponto p) {
    // Insere um ponto no fecho
    Ponto* novoFecho = new Ponto[tam+1];

    for (int i = 0; i < tam; i++) {
        novoFecho[i] = fecho[i];
    }

    novoFecho[tam] = p;
    delete[] fecho; // apagamos o fecho que estava armazenado
    fecho = NULL; 

    fecho = novoFecho; // atribuímos o novoFecho ao fecho
    tam++;
}

Fecho::~Fecho() {
    // Destrói o fecho, apagando o que estava nele armazenado e deixando seu tamanho em 0
    delete[] fecho;
    fecho = NULL;
    tam = 0;
}

// Esse construtor não faz nada. É compromisso de quem cria uma variável do tipo PontoAngulo definir os valores de p e ângulo
PontoAngulo::PontoAngulo() {}