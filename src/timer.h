#include <sys/time.h>

class Timer {
  private :
    struct timeval start, end;
  public :
    void play();
    void stop();
    int microseconds();
    int milliseconds();
    int seconds();
};
