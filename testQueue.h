#ifndef _TEST_QUEUE_H_
#define _TEST_QUEUE_H_
#include "queue/queue.h"
using namespace queue;
void testQueue();
void testQueueWithList();
void testQueueWithArray();

void PrintQueue(LinkQueue Q);
void CreateQueue(LinkQueue &Q);

void PrintQueue(SqQueue Q);
void CreateQueue(SqQueue &Q);
#endif //_TEST_QUEUE_H_