/*
 * File:   Scheduling_Queue.cpp
 * Author: <preencher>
 *
 * Created on October 9, 2015, 9:34 PM
 */

#include "Scheduling_Queue.h"

Scheduling_Queue::Scheduling_Queue() {
    // CHANGE AS NECESSARY IF YOU CHOOSE ANOTHER QUEUE
    _queue = new std::priority_queue<Thread*>();
}

Scheduling_Queue::Scheduling_Queue(const Scheduling_Queue& orig) {
}

Scheduling_Queue::~Scheduling_Queue() {
}

bool Scheduling_Queue::empty() {
    // CHANGE AS NECESSARY IF YOU CHOOSE ANOTHER QUEUE
    return _queue->empty();
}

void Scheduling_Queue::pop() {
    // CHANGE AS NECESSARY IF YOU CHOOSE ANOTHER QUEUE
    _queue->pop();
}

Thread* Scheduling_Queue::top() {
    // CHANGE AS NECESSARY IF YOU CHOOSE ANOTHER QUEUE
    return _queue->top();
}

void Scheduling_Queue::push(Thread* t) {
    // CHANGE AS NECESSARY IF YOU CHOOSE ANOTHER QUEUE
    _queue->push(t);
}
