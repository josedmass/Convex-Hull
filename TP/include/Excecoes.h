#ifndef EXCECOES_H
#define EXCECOES_H

#include <string>

// Caso o usuário coloque valores que não são inteiros no arquivo de entrada
struct ENTRADA_INVALIDA { 
    std::string entrada_errada;
    long int linha_do_erro;
};

#endif