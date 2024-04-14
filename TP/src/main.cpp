#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>

#include "Sorts.h"
#include "Ponto-e-Fecho.h"
#include "FechoConvexo.h"
#include "Excecoes.h"

// Constrói o fecho convexo e calcula o tempo de execução
void exe_fecho(Fecho pl, std::string flag, double tempo[4]);


int main(int argc, char* argv[]) { // Passa o nome do arquivo na linha de compilação

    if(argc < 2) {
        // Caso não tenha passado o nome do arquivo
        std::cout << "ERRO: NÃO PASSOU O NOME DO ARQUIVO" << std::endl;
        return 1;
    }

    std::fstream arquivo;
    std::string nome_do_arquivo = argv[1];
    arquivo.open(nome_do_arquivo, std::ios::in);

    if (!arquivo.is_open()) {
        // Caso o arquivo não tenha sido aberto adequadamente
        // ATENÇÃO: O arquivo DEVE estar no diretório ./TP
        std::cout << "ERRO: O ARQUIVO NÃO ABRIU" << std::endl;
        return 1;
    }

    std::string linha;
    Fecho pl;

    int nrolinha = 1;

    try {
        while(std::getline(arquivo, linha)) {
            // Armazena os pontos fornecidos no arquivo no TAD Fecho
            std::istringstream pontos(linha);
            std::string auxx, auxy;
            pontos >> auxx;
            pontos >> auxy;

            for(char c : auxx) {
                if(!std::isdigit(c)) {
                    ENTRADA_INVALIDA e;
                    e.entrada_errada = auxx;
                    e.linha_do_erro = nrolinha;
                    throw e; // coordenada x da linha nrolinha inválida
                }
            }

            for(char c : auxy) {
                if(!std::isdigit(c)) {
                    ENTRADA_INVALIDA e;
                    e.entrada_errada = auxy;
                    e.linha_do_erro = nrolinha;
                    throw e; // coordenada x da linha nrolinha inválida
                }
            }

            int x = std::stoi(auxx);
            int y = std::stoi(auxy);

            Ponto pt(x, y);
            pl.Insere(pt);
            nrolinha++;
        } 
    } catch(ENTRADA_INVALIDA e) {
        // Tratamento do caso onde o usuário coloca valores inválidos no arquivo de entrada
        std::cout << "ERRO: O valor" << " '" << e.entrada_errada << "' " << "da linha " << e.linha_do_erro << " do arquivo de entrada não é inteiro" << std::endl;
        return 1;
    } 

    if(pl.tam < 3) { 
        // Caso o usuário tenha colocado menos de três pontos no arquivo de entrada
        std::cout << "ERRO: A entrada fornecida não possui tamanho mínimo, que é 3" << std::endl;
        return 1;
    }

    // Armazena os tempos de execução pra cada algoritmo
    double tempo[4];
    
    // Executa cada algoritmo
    exe_fecho(pl, "graham+merge", tempo);
    exe_fecho(pl, "graham+insert", tempo);
    exe_fecho(pl, "graham+bucket", tempo);
    exe_fecho(pl, "jarvis", tempo);

    std::cout << std::endl << "GRAHAM+MERGESORT: " << std::fixed << std::setprecision(3) << tempo[0] << 's' << std::endl; 
    std::cout << "GRAHAM+INSERTIONSORT: " << std::fixed << std::setprecision(3) << tempo[1] << 's' << std::endl;
    std::cout << "GRAHAM+LINEAR: " << std::fixed << std::setprecision(3) << tempo[2] << 's' << std::endl;
    std::cout << "JARVIS: " << std::fixed << std::setprecision(3) << tempo[3] << 's' << std::endl;

    return 0;

}

void exe_fecho(Fecho pl, std::string flag, double tempo[4]) {

    // Estruturas para armazenar o tempo de execução do algoritmo
    struct timespec start, end;
    double elapsed_time;

    if(flag == "graham+merge") {
        // Executa o Scan de Graham com o Mergesort
        clock_gettime(CLOCK_MONOTONIC, &start);
        Fecho Fecho = ScanDeGraham(pl, "merge");
        clock_gettime(CLOCK_MONOTONIC, &end);

        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        tempo[0] = elapsed_time;

    } else if(flag == "graham+insert") {
        // Executa o Scan de Graham com o InsertionSort
        clock_gettime(CLOCK_MONOTONIC, &start);
        Fecho Fecho = ScanDeGraham(pl, "insert");
        clock_gettime(CLOCK_MONOTONIC, &end);

        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        tempo[1] = elapsed_time;

    } else if(flag == "graham+bucket") {
        // Executa o Scan de Graham com o BucketSort
        clock_gettime(CLOCK_MONOTONIC, &start);
        Fecho Fecho = ScanDeGraham(pl, "bucket");
        clock_gettime(CLOCK_MONOTONIC, &end);

        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        tempo[2] = elapsed_time;

    } else if(flag == "jarvis") {
        // Executa a Marcha de Jarvis
        clock_gettime(CLOCK_MONOTONIC, &start);
        Fecho Fecho = MarchaDeJarvis(pl);
        clock_gettime(CLOCK_MONOTONIC, &end);

        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        tempo[3] = elapsed_time;

        printFecho(Fecho);

    }

}