#include "PilhaEncadeada.h"

Celula::Celula() {
    // Constrói uma célula vazia
    prox = NULL;
}

PilhaEncadeada::PilhaEncadeada() {
    // Constrói uma pilha de tamanho zero e com topo nulo
    tamanho = 0;
    topo = NULL;
}

PilhaEncadeada::PilhaEncadeada(const PilhaEncadeada& other) {
    // Faz com que a pilha *this fique igual à other
    this->topo = NULL;
    this->tamanho = other.tamanho;

    if(other.topo == NULL) return;

    this->topo = new Celula();
    this->topo->item = other.topo->item;
    Celula* curr = topo;
    Celula* othercurr = topo->prox;

    while (othercurr != nullptr) {
        curr->prox = new Celula();
        curr->prox->item = othercurr->item;
        curr = curr->prox;
        othercurr = othercurr->prox;
    }

}

PilhaEncadeada& PilhaEncadeada::operator=(const PilhaEncadeada& other) {
    // Faz com que a pilha *this fique igual à other
    
    if(this == &other) return *this; // Se está atribuindo duas pilhas iguais

    this->Limpa(); // Limpo o que estava alocado
    
    if(other.topo == NULL) return *this; // Se está tentando atribuir à uma pilha vazia

    // Fazemos com que this->topo seja igual a other->topo
    this->topo = new Celula();
    this->topo->item = other.topo->item;
    tamanho++;

    // Variáveis auxiliares
    Celula* curr = this->topo;
    Celula* othercurr = other.topo->prox;

    while(othercurr != NULL) {
        // iterativamente, vou igualando, "de cima pra baixo", os elementos dessa pilha com
        // os da pilha other
        curr->prox = new Celula();
        curr->prox->item = othercurr->item;
        curr = curr->prox;
        othercurr = othercurr->prox;
        tamanho++;
    }

    return *this;
}

PontoAngulo PilhaEncadeada::GetTopo() {
    // Retorna o item que está no topo da pilha
    return topo->item;
}

int PilhaEncadeada::GetTamanho() {
    // Retorna o tamanho da pilha
    return tamanho;
}

PontoAngulo PilhaEncadeada::AbaixoDoTopo() {
    // Retorna o elemento que está abaixo do topo da pilha
    PontoAngulo p = this->GetTopo();
    this->Desempilha();
    PontoAngulo res = this->GetTopo();
    this->Empilha_Item(p);
    return res;
}

void PilhaEncadeada::Empilha_Item(PontoAngulo p) {
    // Empilhamos uma nova string no topo da pilha
    Celula* nova = new Celula();
    nova->item = p;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

void PilhaEncadeada::Desempilha() {
    // Desempilhamos um elemento do topo da pilha
    Celula *p;
    p = topo;
    topo = topo->prox; // alteramos o topo, e apagamos o antigo
    delete p;
    tamanho--; // diminuímos o tamanho e retornamos o elemento que estava a priori no topo
}

Fecho PilhaEncadeada::ObterFecho() {
    // Retorna o que está armazenado na pilha na forma do TAD Fecho
    Fecho pl;
    pl.tam = tamanho;
    pl.fecho = new Ponto[tamanho]; // alocamos espaço para o fecho

    Celula* atual = topo;
    int i = tamanho - 1;

    while (atual != nullptr) {
        // Preenchemos o fecho "de trás pra frente", para que os pontos fiquem na ordem anti-horária
        pl.fecho[i] = atual->item.p;
        atual = atual->prox;
        i--;
    }

    return pl;
}

void PilhaEncadeada::Limpa() {
    // Limpa iterativamente o que está armazenado na pilha encadeada
    Celula* p;
    while(tamanho != 0 && topo != NULL) {
        p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
    }
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada() {
    // Destrói a pilha, chamando a função Limpa()
    Limpa();
}