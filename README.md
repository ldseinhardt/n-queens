# nQueens - Trabalho de Sistemas Operacionais - UFPEL

#### Nome: Luan Einhardt

#### Relatório

No trabalho foi utilizado apenas mutex como mecanismo de sincronização, afim de evitar que mais de uma thread tente escrever o arquivo de saida ao mesmo tempo.

#### Configuração do computador testado

 - Processador: AMD FX(tm)-8350 Eight-Core Processor × 8
 - Memória: 8 GiB

#### Dados estatísticos

Foram realizados testes com estradas N de 1 até 12, uma vez que a entrada N = 13 multithread levou 22 minutos e a sequencial não retornou resposta em 30 minutos.

#### Entrada N = 1

* Sequencial:
* Tempo médio = 0.8 microseconds
* Threads:
* [1] = 171 microseconds
* [2] = 47 microseconds
* [3] = 23 microseconds
* [4] = 23 microseconds
* [5] = 23 microseconds
* Tempo médio   = 57.4 microseconds
* Desvio padrão = 57.5555 microseconds
* Speedup       = 0.0139373
* Eficiência    = 0.0139373

#### Entrada N = 2

* Sequencial:
* Tempo médio = 0.4 microseconds
* Threads:
* [1] = 24 microseconds
* [2] = 23 microseconds
* [3] = 20 microseconds
* [4] = 20 microseconds
* [5] = 21 microseconds
* Tempo médio   = 21.6 microseconds
* Desvio padrão = 1.62481 microseconds
* Speedup       = 0.0185185
* Eficiência    = 0.00925926

#### Entrada N = 3

* Sequencial:
* Tempo médio = 2.2 microseconds
* Threads:
* [1] = 116 microseconds
* [2] = 33 microseconds
* [3] = 31 microseconds
* [4] = 31 microseconds
* [5] = 31 microseconds
* Tempo médio   = 48.4 microseconds
* Desvio padrão = 33.8089 microseconds
* Speedup       = 0.0454545
* Eficiência    = 0.0151515

#### Entrada N = 4

* Sequencial:
* Tempo médio = 8.4 microseconds
* Threads:
* [1] = 35 microseconds
* [2] = 34 microseconds
* [3] = 35 microseconds
* [4] = 32 microseconds
* [5] = 33 microseconds
* Tempo médio   = 33.8 microseconds
* Desvio padrão = 1.16619 microseconds
* Speedup       = 0.248521
* Eficiência    = 0.0621302

#### Entrada N = 5

* Sequencial:
* Tempo médio = 47.2 microseconds
* Threads:
* [1] = 159 microseconds
* [2] = 96 microseconds
* [3] = 151 microseconds
* [4] = 89 microseconds
* [5] = 87 microseconds
* Tempo médio   = 116.4 microseconds
* Desvio padrão = 31.7591 microseconds
* Speedup       = 0.405498
* Eficiência    = 0.0810997

#### Entrada N = 6

* Sequencial:
* Tempo médio = 964.8 microseconds
* Threads:
* [1] = 538 microseconds
* [2] = 402 microseconds
* [3] = 394 microseconds
* [4] = 414 microseconds
* [5] = 395 microseconds
* Tempo médio   = 428.6 microseconds
* Desvio padrão = 55.1638 microseconds
* Speedup       = 2.25105
* Eficiência    = 0.375175

#### Entrada N = 7

* Sequencial:
* Tempo médio = 4842.8 microseconds
* Threads:
* [1] = 3261 microseconds
* [2] = 3160 microseconds
* [3] = 3009 microseconds
* [4] = 2448 microseconds
* [5] = 2411 microseconds
* Tempo médio   = 2857.8 microseconds
* Desvio padrão = 358.977 microseconds
* Speedup       = 1.69459
* Eficiência    = 0.242084

#### Entrada N = 8

* Sequencial:
* Tempo médio = 25813 microseconds
* Threads:
* [1] = 10710 microseconds
* [2] = 6441 microseconds
* [3] = 6397 microseconds
* [4] = 6539 microseconds
* [5] = 6484 microseconds
* Tempo médio   = 7314.2 microseconds
* Desvio padrão = 1698.55 microseconds
* Speedup       = 3.52916
* Eficiência    = 0.441145

#### Entrada N = 9

* Sequencial:
* Tempo médio = 248868 microseconds
* Threads:
* [1] = 88444 microseconds
* [2] = 62560 microseconds
* [3] = 77971 microseconds
* [4] = 73176 microseconds
* [5] = 79026 microseconds
* Tempo médio   = 76235.4 microseconds
* Desvio padrão = 8440.69 microseconds
* Speedup       = 3.26447
* Eficiência    = 0.362719

#### Entrada N = 10

* Sequencial:
* Tempo médio = 2864620 microseconds
* Threads:
* [1] = 716537 microseconds
* [2] = 697608 microseconds
* [3] = 699190 microseconds
* [4] = 704957 microseconds
* [5] = 716905 microseconds
* Tempo médio   = 707039 microseconds
* Desvio padrão = 8275.69 microseconds
* Speedup       = 4.05156
* Eficiência    = 0.405156

#### Entrada N = 11

* Sequencial:
* Tempo médio = 36037200 microseconds
* Threads:
* [1] = 7730067 microseconds
* [2] = 7744924 microseconds
* [3] = 7737729 microseconds
* [4] = 7711821 microseconds
* [5] = 8019265 microseconds
* Tempo médio   = 7788760 microseconds
* Desvio padrão = 115778 microseconds
* Speedup       = 4.62682
* Eficiência    = 0.42062

#### Entrada N = 12

* Sequencial:
* Tempo médio = 464135000 microseconds
* Threads:
* [1] = 97028530 microseconds
* [2] = 98591703 microseconds
* [3] = 98549408 microseconds
* [4] = 98493186 microseconds
* [5] = 97077982 microseconds
* Tempo médio   = 97948200 microseconds
* Desvio padrão = 731523 microseconds
* Speedup       = 4.73858
* Eficiência    = 0.394881
