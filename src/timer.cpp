#include "timer.h"

void Timer :: play() {
  gettimeofday(&start, 0);
}

void Timer :: stop() {
  gettimeofday(&end, 0);
}

int Timer :: microseconds() {
  return (int) ((1000000 * (end.tv_sec - start.tv_sec)) + (end.tv_usec - start.tv_usec));
}

int Timer :: milliseconds() {
  return (int) microseconds() / 1000;
}

int Timer :: seconds() {
  return (int) milliseconds() / 1000;
}
