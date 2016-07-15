#include <iostream>
#include <string>

using namespace std;

class Board {
  private :
    //Tabuleiro
    char** b;

    //Tamanho do tabuleiro (size*size)
    int size;

    //Número de Rainhas inseridas
    int count;

    void setPath(int lin, int col);
    void setPathDiagonal(int dir, int lin, int col);

  public :  
    Board(int n);
    ~Board();

    bool setQueen(int lin, int col);
    bool setQueens(int *vector);
    bool save(const char* filename);

    int getSize() { return size; }
    int getQueens() { return count; }
    string getBoard();
};
