#include "permutation.h"

Permutation :: Permutation(int n, int ordem) {
  size = n;
  ord = ordem;
  vector = new int[size];
}

Permutation :: ~Permutation() {
  free(vector);
}

void Permutation :: generate() {
  for (int i = 0; i < size; i++) {
    vector[i] = i;
  }
  myOrd();
}

bool Permutation :: next() {
  return next_permutation(vector, vector + size);
}

bool Permutation :: checkOrdem() {
  int div;
  if ((size % 2 == 1) && (ord == (div = size / 2))) {
    return ((vector[0] == ord) && (vector[1] < div));
  }
  return (vector[0] == ord);
}

void Permutation :: print() {
  for (int i = 0; i < size; i++) {
    cout << vector[i] << " ";
  }
  cout << endl;
}

void Permutation ::  myOrd() {
  if ((ord > 0) && (ord < size)) {
    for (int i = ord; i > 0; i--) {
      int tmp = vector[i];
      vector[i] = vector[i-1];
      vector[i-1] = tmp;
    }
  }
}
