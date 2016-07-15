#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

class Permutation {
  private :
    void myOrd();
  public :
    int* vector;
    int size;
    int ord;
    Permutation(int n, int ordem);
    ~Permutation();
    void generate();
    bool next();
    bool checkOrdem();
    void print();
};
