#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "board.h"
#include "permutation.h"
#include "timer.h"

using namespace std;

#define FILENAME "saida.txt"

int solutions = 0;

mutex mtx; 

void iThread(int n, int ordem);

int nQueens_threads(int n);

int nQueens_sequencial(int n);

double desvio_padrao(vector<double> temps);

void testes(int n);
