#ifndef INTQUEUE_H
#define INTQUEUE_H

#include <Arduino.h>

typedef enum
{
  INTQUEUE_SUCCESS,
  INTQUEUE_EMPTY,
  INTQUEUE_FULL,
  INTQUEUE_UNINITIALIZED
} intQueueRetType;

class intQueue
{
  public:
    intQueue();
    intQueue(int bufferSize);
    ~intQueue();
    int numElements();
    intQueueRetType put(int *element);
    intQueueRetType get(int *element);
    void print(char *);
  private:
    int *_buffer;
    int _bufferSize;
    int _readIndex;
    int _writeIndex;
    int _numElements;
    int _initialize(int bufSize);
};

#endif
