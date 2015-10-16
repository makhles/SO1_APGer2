/*
 * File:   Queue.h
 * Author: Makhles R. Lange
 *
 * Created on September 27, 2015, 11:28 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H

/**
 * Used by Thread as waiting queues for threads that uses void Thread::sleep(Queue* e) and void Thread::wakeup(Queue q)
 **/
class Queue {
public: // constructors
    Queue();
    Queue(const Queue& orig);
    virtual ~Queue();
private: // user defined
    // INSERT YOUR CODE HERE
    // ...
};

#endif	/* QUEUE_H */
