#ifndef PONTOEFECHO_H
#define PONTOEFECHO_H

class Ponto {
    public:
        // Construtores
        Ponto(long long int a, long long int b);
        Ponto();

        // Armazenam as coordenadas x e y do ponto, respectivamente
        long long int x; 
        long long int y;

};

class Fecho {
    public:
        // Construtor
        Fecho();
        // Destrutor
        ~Fecho();
        // Sobrecarga da atribuição de dois Fechos
        Fecho(const Fecho& other);
        Fecho& operator=(const Fecho& other);
        // Sobrecarga da comparação de dois Fechos
        bool operator==(const Fecho& other) const;
        // Função que insere pontos no fecho
        void Insere(Ponto p);

        // Vetor de pontos do fecho
        Ponto* fecho;
        // Tamanho do fecho
        int tam;
};

class PontoAngulo {
    public:
        // Construtor
        PontoAngulo();

        // Ponto
        Ponto p;
        // Ângulo formado entre p e o ângulo inicial (mais embaixo e mais à esquerda do fecho)
        double angulo;
};

#endif