#include "board.h"

Board :: Board(int n) {
  size = n;
  count = 0;
  b = new char*[size];
  for (int i = 0; i < size; i++) {
    b[i] = new char[size];
    for (int j = 0; j < size; j++) {
      b[i][j] = '\0';
    }
  }
}

Board :: ~Board() {
  for (int i = 0; i < size; i++) {
    free(b[i]);
  }
  free(b);
}

bool Board :: setQueen(int lin, int col) {
  if (b[lin][col] == '\0') {
    b[lin][col] = 'R';
    count++;
    setPath(lin, col);
    return true;
  }
  return false;
}

void Board :: setPath(int lin, int col) {
  for (int i = 0; i < size; i++) {
    //Marca a linha
    if (b[lin][i] == '\0') {
      b[lin][i] = 'X';
    }
    //Marca a coluna
    if (b[i][col] == '\0') {
      b[i][col] = 'X';
    }
  }
  //Marca as diagonais
  for (int dir = 0; dir < 4; dir++) {
    setPathDiagonal(dir, lin, col);
  }
}

void Board :: setPathDiagonal(int dir, int lin, int col) {
  int set = 0;
  switch(dir) {
    case 0:
      if ((lin < size-1) && (col < size-1)) {
        set++;
        lin++;
        col++;
      }
      break;
    case 1:
      if ((lin > 0) && (col > 0)) {
        set++;
        lin--;
        col--;
      }
      break;
    case 2:
      if ((lin < size-1) && (col > 0)) {
        set++;
        lin++;
        col--;
      }
      break;
    case 3:
      if ((lin > 0) && (col < size-1)) {
        set++;
        lin--;
        col++;
      }
  }

  if (set) {
    if (b[lin][col] == '\0')
      b[lin][col] = 'X';
    setPathDiagonal(dir, lin, col);
  }
}

bool Board :: setQueens(int* vector) {
  for (int i = 0; i < size; i++) {
    if (!setQueen(i, vector[i])) {
      return false;
    }    
  }
  return true;
}

string Board :: getBoard() {
  string result = "";
  string tluser = "";
  for (int i = 0; i < size; i++) {
    for (int j = 0, k = size-1; (j < size) && (k >= 0); j++, k--) {
      if (b[i][j] == '\0') {
        result += "_";
      } else {
        result += b[i][j];
      }

      if (b[i][k] == '\0') {
        tluser += "_";
      } else {
        tluser += b[i][k];
      }

      if (j != size-1) {
        result += " ";
        tluser += " ";
      }
    }
    result += "\n";
    tluser += "\n";
  }
  result += "\n";
  tluser += "\n";
  if (size > 1)
    result += tluser;
  return result;
}

bool Board :: save(const char* filename) {
  FILE *fp;
  if ((fp = fopen(filename, "a")) != NULL) {
    fprintf(fp, "%s", getBoard().c_str());
    fclose(fp);
    return true;
  }
  return false;
}
