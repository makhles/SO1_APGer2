/*
 * File:   Process.h
 * Author: Makhles R. Lange
 *
 * Created on August 31, 2015, 7:49 AM
 */

#ifndef PROCESS_H
#define	PROCESS_H

#include <list>
#include <queue>

#include "MemorySegment.h"
#include "Entity.h"

class Process {
    friend class Thread;

    // scructs for grouping process' attributes

    struct IdentificationInformation {
        unsigned int _processId;
        unsigned int _parentId;
    };

    struct MemoryInformation {
        unsigned int _beginAllocatedMemory;
        unsigned int _endAllocatedMemory;
        std::list<MemorySegment*>* _segments;
    };


public: // constrs
    Process(unsigned int parentId);
    Process(const Process& orig);
    virtual ~Process();
public: // id info
    unsigned int getParentId() const;
    unsigned int getId() const;
    Entity* getEntity() const;
    void setEndMemory(unsigned int _endMemory);
    unsigned int getEndMemory() const;
    void setBeginMemory(unsigned int _beginMemory);
    unsigned int getBeginMemory() const;
    std::list<MemorySegment*>* getSegments();
public: // statics

    static unsigned int getNewId() {
        static unsigned int _lastId = 0;
        return ++_lastId;
    }

    static std::queue<Process*>* getTasksList() {
        static std::queue<Process*>* _tasksList = new std::queue<Process*>();
        return _tasksList;
    }

    static void exec();
    static void exit(int status = 0);
private:// for simulation
    IdentificationInformation _idInfo;
    MemoryInformation _memInfo;
public: // For simulation

    Entity* getEntity() {
        return _entity;
    }

private: // for simulator use only
    Entity* _entity; //used only by the simulator
public: // USER DEFINED
    // INSERT YOUR CODE HERE

private: // USER DEFINED
    // INSERT YOUR CODE HERE
};

#endif	/* PROCESS_H */
