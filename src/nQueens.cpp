#include "nQueens.h"

int main(int argc, char *argv[]) {
  int n = 0;
  if (argc > 1) {
    n = atoi(argv[1]);
  } else {
    while (n < 1) {
      cout << "Digite um valor para n (n > 0): " << endl;
      cin >> n;
    }
  }

  remove(FILENAME);
  solutions = 0;
  int t = nQueens_threads(n);
  cout << "Entrada (n): " << n << endl;
  cout << "Soluções Encontradas: " << solutions << endl;
  cout << "Arquivo com Soluções: /" << FILENAME << endl;
  cout << "Tempo de Execução: " << t << " (microseconds)" << endl;
  //testes(n);
  return 0;
}

void iThread(int n, int ordem) {
  int c = 0;
  Permutation permute(n, ordem);
  permute.generate();
  do {
    Board board(n);
     //Dispara a tentativa de encontrar a solução com a instancia da permutação
     //Se encontrar uma solução pega a solução espelhada também
    if (board.setQueens(permute.vector)) {
      c++;
      if (n > 1)
        c++;
      mtx.lock();
      board.save(FILENAME);
      mtx.unlock();
    }
  } while (permute.next() && permute.checkOrdem());
  solutions += c;
}

int nQueens_threads(int n) {
  int max = (n / 2) + (n % 2);

  Timer* clock = new Timer();
  clock->play();

  vector<thread*> threads;
  //cria n/2 + n%2 threads
  for (int i = 0; i < max; i++) {
    thread* t = new thread(iThread, n, i);
    threads.push_back(t);
  }
  //encerra as threads
  while (!threads.empty()) {
    threads.back()->join();
    threads.pop_back();
  }

  clock->stop();
  int r = clock->microseconds();
  delete clock;
  return r;
}

int nQueens_sequencial(int n) {
  int max = (n / 2) + (n % 2);

  Timer* clock = new Timer();
  clock->play();

  for (int i = 0; i < max; i++) {
    iThread(n, i);
  }

  clock->stop();
  int r = clock->microseconds();
  delete clock;
  return r;
}

double desvio_padrao(vector<double> temps) {
  double media = 0;
  for (size_t i = 0; i < temps.size(); i++) {
    media += temps[i];
  }
  media /= temps.size();

  double variancia = 0;
  for (size_t i = 0; i < temps.size(); i++) {
    temps[i] -= media;
    temps[i] *= temps[i];
    variancia += temps[i];
  }
  variancia /= temps.size();
  return sqrt(variancia);
}

void testes(int n) {
  for (int i = 1; i <= n; i++) {
    cout << "Entrada N = " << i << endl;
    //sequencial
    cout << "Sequencial:" << endl;
    solutions = 0;
    long double media_sequencial = 0;
    for (int j = 1; j <= 5; j++) {
      int t  = nQueens_sequencial(i);
      media_sequencial += t;
    }
    media_sequencial /= 5;
    cout << "Tempo médio = " << media_sequencial << " microseconds" << endl;
    //threads
    cout << "Threads:" << endl;
    solutions = 0;
    long double media_threads = 0;
    vector<double> temps;
    for (int j = 1; j <= 5; j++) {
      int t = nQueens_threads(i);
      cout << "[" << j << "] = " << t << " microseconds" << endl;
      media_threads += t;
      temps.push_back(t);
    }
    media_threads /= 5;
    cout << "Tempo médio   = " << media_threads << " microseconds" << endl;
    cout << "Desvio padrão = " << desvio_padrao(temps) << " microseconds" << endl;
    double speedup = media_sequencial/media_threads;
    cout << "Speedup       = " << speedup << endl;
    cout << "Eficiência    = " << speedup/i << endl;
  }
}
