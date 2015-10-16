/*
 * File:   Process.cpp
 * Author: Makhles R. Lange
 *
 * Created on August 31, 2015, 7:49 AM
 */

#include "Debug.h"
#include "Process.h"
#include "Thread.h"
#include "System.h"
#include "Simulator.h"

Process::Process(unsigned int parentId) {
    this->_entity = Simulator::getInstance()->getEntity();
    this->_idInfo._processId = Process::getNewId();
    this->_idInfo._parentId = parentId;
    this->_memInfo._segments = new std::list<MemorySegment*>();
    // INSERT YOUR CODE HERE
    // ...
}

Process::Process(const Process& orig) {
}

Process::~Process() {
}

void Process::setEndMemory(unsigned int _endMemory) {
    this->_memInfo._endAllocatedMemory = _endMemory;
}

unsigned int Process::getEndMemory() const {
    return _memInfo._endAllocatedMemory;
}

void Process::setBeginMemory(unsigned int _beginMemory) {
    this->_memInfo._beginAllocatedMemory = _beginMemory;
}

unsigned int Process::getBeginMemory() const {
    return _memInfo._beginAllocatedMemory;
}

std::list<MemorySegment*>* Process::getSegments() {
    return _memInfo._segments;
}

unsigned int Process::getParentId() const {
    return _idInfo._parentId;
}

unsigned int Process::getId() const {
    return _idInfo._processId;
}

/**
 * Processos chegarão ao sistema quando for invocada a chamada static void Process::exec(Segment* segments), que precisa
 * ser implementada. A implementação dessa chamada de sistema deve criar um Process, alocar memória para ele invocando
 * a chamada de sistema void MemoryManagement::alloc(Process* process), inicializar seus atributos, colocá-lo na lista
 * de processos no sistema e criar uma thread (correspondente a "main") para esse processo invocando a chamada
 * static void Thread::thread_create().
 **/
void Process::exec() { /*static*/
    Debug::cout(Debug::Level::trace, "Process::exec()");

    // Create a new process whose parent has id = 0
    Process* newProcess = new Process(0);

    // Allocate memory for this process
    System::memoryManager()->alloc(newProcess);

    // Initialize its attributes
    // TODO

    // Add it to the system's task list
    Process::getTasksList()->push(newProcess);

    // Create the process main thread
    Thread::thread_create(newProcess);
}

/**
 * Processos serão finalizados quando for invocada a chamada static void Process::exit(int status = 0), que precisa ser
 * implementada. A implementação dessa chamada deve desalocar a memória do processo invocando
 * void MemoryManagement::desalloc(Process* process), excluir todas as threads desse processo, excluir o processo (destruir
 * o objeto Process), invocar o escalonador para escolher outra thread, invocando Thread* Scheduler::choose() e então
 * o despachador para iniciar a execução da thread escolhida pelo escalonador, invocando
 * void Dispatcher::dispatch(Thread* previous, Thread* next).
 **/
void Process::exit(int status) { /*static*/
    Debug::cout(Debug::Level::trace, "Process::exit(" + std::to_string(status) + ")");
    // INSERT YOUR CODE HERE (Now it's up to you...)
    // ...
}
