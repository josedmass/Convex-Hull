# Fecho-Convexo
Este projeto foi desenvolvido como Trabalho Prático 2 da disciplina de Estrutura de Dados da UFMG, realizado em 2023/01.

## Autor
- José Eduardo Duarte Massucato

## Descrição
O trabalho proposto tem por objetivo encontrar a envoltória convexa de um conjunto de pontos de entrada, cujas coordanadas são valores inteiros. Para tanto, foram utilizados o algoritmo Scan de Graham e o Marcha de Jarvis, implementados em C++.

## Funcionalidades
- Retorna a envoltória convexa para o conjunto de pontos.
- Retorna os tempos de execução para: 
    1. Scan de Graham + MergeSort
    2. Scan de Graham + InsertionSort
    3. Scan de Graham + BucketSort
    4. Marcha de Jarvis

OBS: Os detalhes da implementação, bem como as estruturas de dados utilizados e os métodos adotados, encontram-se em "Documentacao.pdf".

## Como usar
1. Navegue até a pasta TP no seu computador
```bash
cd /<caminho_para_a_pasta>/TP
```

2. Adicione o arquivo de entrada desejado em ./TP, seguindo a formatação apropriada, como a do exemplo.

3. Compile e execute o programa a partir do arquivo Makefile presente em ./TP
```bash
make fecho <file_name.txt>
```

4. A saída será direcionada para a saída padrão do sistema.

5. Ao final das execuções, utilize o Makefile para limpar os arquivos gerados
```bash
make clean
```

OBS: Um arquivo de entrada de exemplo, chamado "in.txt", foi adicionado em ./TP.