/*
 * File:   Thread.h
 * Author: preencher>
 *
 * Created on September 27, 2015, 10:30 AM
 */

#ifndef THREAD_H
#define	THREAD_H

#include "Queue.h"
#include "Process.h"
#include "TimerMediator.h"
#include "ModuleInvoke_ThreadExec.h"

class Thread {
    friend class ModuleInvoke_ThreadExec; // simulator use only
    friend class TimerMediator;

    enum State {
        RUNNING,
        READY,
        WAITING,
        FINISHING
    };

    enum Criterion {
        HIGH,
        NORMAL,
        LOW,
        MAIN,
        IDLE
    };

    /**
     *  struct for grouping threads' attributes
     **/
    struct AccountInformation {
        double _arrivalTime;
        double _cpuBurstTime;
        double _cpuTime;
        double _waitingTime;
        // add here another information you need
        // INSERT YOUR CODE HERE
        // ...
    };

public: // constructors
    Thread(Process* task, Thread::State state = Thread::State::READY);
    Thread(const Thread& orig);
    virtual ~Thread();
public: // statics
    static void sleep(Queue * q);
    static void wakeup(Queue * q);
    static void thread_create(Process* parent);

    static std::list<Thread*>* getThreadsList() {
        static std::list<Thread*>* _threadsList = new std::list<Thread*>();
        return _threadsList;
    }
protected: // statics
    static void yield();
    static void exit(int status = 0);
    static Thread* running();
    static void dispatch(Thread* previous, Thread* next);

    static unsigned int getNewId() {
        static unsigned int _lastId = 0;
        return ++_lastId;
    }
public: //
    int join();
    Process* getProcess();
protected:
    Process * _process;  
    volatile State _state;
    unsigned int _id;
    AccountInformation _accountInfo;

public: // USER DEFINED
    // INSERT YOUR CODE HERE
    // ... 
private: // USER DEFINED    
    // INSERT YOUR CODE HERE
    // ...
};

#endif	/* THREAD_H */

