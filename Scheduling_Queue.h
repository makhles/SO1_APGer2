/*
 * File:   Scheduling_Queue.h
 * Author: <preencher>
 *
 * Created on October 9, 2015, 9:34 PM
 */

#ifndef SCHEDULING_QUEUE_H
#define	SCHEDULING_QUEUE_H

#include <queue>

#include "Thread.h"

/**
 * Used by Scheduler to store Threads in the RUNNING state. This is the class for the READY_QUEUE
 */
class Scheduling_Queue {
public:
    Scheduling_Queue();
    Scheduling_Queue(const Scheduling_Queue& orig);
    virtual ~Scheduling_Queue();
public:
    bool empty();
    void pop();
    Thread* top();
    void push(Thread* t);
private:
    std::priority_queue<Thread*>* _queue;
};

#endif	/* SCHEDULING_QUEUE_H */

