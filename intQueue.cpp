#include "intQueue.h"

#define DEFAULT_SIZE 5

intQueue::_initialize(int bufSize)
{

  _readIndex = 0;
  _writeIndex = 0;
  _numElements = 0;

  if (bufSize > 0)
  {
    _buffer = (int *) malloc(bufSize);
    if (_buffer)
    {
      _bufferSize = bufSize;
    }
    else
    {
      _bufferSize = 0;
    }
  }
  else
  {
    _bufferSize = 0;  
  }
}

intQueue::intQueue(void)
{
  _initialize(DEFAULT_SIZE);
}

intQueue::intQueue(int numElements)
{
  _initialize(numElements);
}

intQueue::~intQueue()
{
  if (_buffer)
  {
    free(_buffer);
  }
}

intQueueRetType intQueue::get(int *element)
{
  if ((_bufferSize == 0) || (_numElements==0))
  {
    return INTQUEUE_EMPTY;
  }
  else
  {
    *element = _buffer[_readIndex];
    _readIndex = (_readIndex + 1) % _bufferSize;
    _numElements--;
    return INTQUEUE_SUCCESS;
  }
}

intQueueRetType intQueue::put(int *element)
{
  if (_numElements ==_bufferSize)
  {
    return INTQUEUE_FULL;
  }
  else if (_buffer )
  {
    _buffer[_writeIndex] = *element;
    _writeIndex = (_writeIndex + 1) % _bufferSize;
    _numElements++;
    return INTQUEUE_SUCCESS;
  }
  else
  {
    return INTQUEUE_UNINITIALIZED;
  }
}

int intQueue::numElements( void )
{
  return _numElements;
}

void intQueue::print(char *headerStr )
{
  int i;

  if (headerStr)
  {
    Serial.print(headerStr);
  }
  Serial.print("*** read: ");
  Serial.print(_readIndex);
  Serial.print(" write: ");
  Serial.print(_writeIndex);
  Serial.print(" buffer: ");
  for (i=0; i< _bufferSize; i++)
  {
    Serial.print(_buffer[i]);
    Serial.print(" ");
  }
  Serial.print(" * NUM: ");
  Serial.print(_numElements);
  Serial.println();
}
