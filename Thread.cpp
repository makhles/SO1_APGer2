/*
 * File:   Thread.cpp
 * Author: <preencher>
 *
 * Created on September 27, 2015, 10:30 AM
 */

#include "Thread.h"
#include "Debug.h"
#include "System.h"
#include "Simulator.h"
#include "CPU.h"

Thread::Thread(Process* task, Thread::State state) {
    this->_id = Thread::getNewId();
    this->_process = task;
    this->_state = state;
    // INSERT YOUR CODE HERE
    // ...
}

Thread::Thread(const Thread& orig) {
}

Thread::~Thread() {
}

Thread* Thread::running() {
    return System::scheduler()->choosen();
}

Process* Thread::getProcess() {
    return _process;
}

void Thread::sleep(Queue * q) {
    Debug::cout(Debug::Level::trace, "Thread::sleep(" + std::to_string(reinterpret_cast<unsigned long> (q)) + ")");
    // INSERT YOUR CODE HERE
    // ...
}

void Thread::wakeup(Queue * q) {
    Debug::cout(Debug::Level::trace, "Thread::wakeup(" + std::to_string(reinterpret_cast<unsigned long> (q)) + ")");
    // INSERT YOUR CODE HERE
    // ...
}

/**
 * Threads podem decidir deixar a CPU invocando a chamada void Thread::yield(), que precisa ser implementada. A implementação
 * dessa chamada deve colocar a thread que está executando no estado READY, incluí-la na fila de threads prontas, chamar
 * o escalonador para escolher outra thread, invocando Thread* Scheduler::choose() e então o despachador para iniciar
 * a execução da thread escolhida pelo escalonador, invocando static void Thread::dispatch(Thread* previous, Thread* next).
 **/
void Thread::yield() {
    Debug::cout(Debug::Level::trace, "Thread::yield()");
    // INSERT YOUR CODE HERE
    // ...
}

/**
 * Threads aguardarão pelo término de outras threads quando for invocada a chamada void Thread::join(Thread* waitfor),
 * que precisa ser implementada. A implementação dessa chamada deve verificar se a thread waitfor passada como parâmetro
 * está no estado FINISHED ou não. Se estiver, então a thread que invocou a chamada simplesmente continua sua execução.
 * Se não estiver, então a thread chamada deve ser colocada no estado WAITING e colocada na fila de threads esperando
 * pela thread waitfor passada como parâmetro. Ainda nesse caso, deve-se chamar o escalonador para escolher outra thread,
 * invocando Thread* Scheduler::choose() e então o despachador para iniciar a execução da thread escolhida pelo escalonador,
 * invocando static void Thread::dispatch(Thread* previous, Thread* next).
 **/
int Thread::join() {
    Debug::cout(Debug::Level::trace, "Thread::join()");
    // INSERT YOUR CODE HERE
    // ...
}

/**
 * Threads serão finalizadas quando for invocada a chamada void Thread::exit(), que precisa ser implementada. A implementação
 * dessa chamada deve colocar a thread que está executando no estado FINISHED, verificar se há alguma thread na lista
 * de threads bloqueadas esperando por essa thread. Se houver, todas as threads na lista devem ser colocadas no estado
 * READY e colocadas na fila de threads pronas para executar. Em qualquer caso, deve-se ainda chamar o escalonador para
 * escolher outra thread, invocando Thread* Scheduler::choose() e então o despachador para iniciar a execução da thread
 * escolhida pelo escalonador, invocando static void Thread::dispatch(Thread* previous, Thread* next).
 **/
void Thread::exit(int status) {
    Debug::cout(Debug::Level::trace, "Thread::exit(" + std::to_string(status) + ")");
    // INSERT YOUR CODE HERE
    // ...
}

/**
 * Depois de obter a nova Thread escolhida pelo escalonador threads devem despachar a execução dessa nova thread, invocando
 * o método static void Thread::dispatch(Thread* previous, Thread* next), que já está implementada. A impementalçao desse
 * método deve inicialmente verificar se as threads  previous e next são diferentes. Se forem iguais então não há nada a
 * fazer. Se forem diferentes então deve-se colocar a thread next em estado RUNNING, verificar se a thread previous é nula
 * (caso da primeira thread a executar). Se for nula, apenas restaurar o contexto da próxima, inovcando o método
 * static void CPU::restore_context(Thread* next) , e  e se não nula deve-se mudar seu estado para READY, colocá-la na
 * fila de pronto, e fazer a troca de contexto, invocando o método
 * static void CPU::switch_context(Thread* previous, Thread* next).
 * **/
void Thread::dispatch(Thread* previous, Thread* next) {
    Debug::cout(Debug::Level::trace, "Thread::dispatch(" + std::to_string(reinterpret_cast<unsigned long> (previous)) + "," + std::to_string(reinterpret_cast<unsigned long> (next)) + ")");

    if (previous != next) {
    // INSERT YOUR CODE HERE
    // ...
    }
}

/**
 * Threads criarão novas threads quando for invocada a chamada static void Thread::thread_create(), que precisa ser
 * implementada. A implementação dessa chamada deve criar um objeto Thread, inicializar seus novos atributos, colocá-la na
 * lista de threads no sistema, inseri-la na fila de prontos inovando o método void Scheduler::insert(Thread* thread), chamar
 * o escalonador para escolher outra thread, invocando Thread* Scheduler::choose() e então o despachador para iniciar a
 * execução da thread escolhida pelo escalonador, invocando static void Thread::dispatch(Thread* previous, Thread* next).
 **/
void Thread::thread_create(Process* parent) {
    Debug::cout(Debug::Level::trace, "Thread::create(" + std::to_string(reinterpret_cast<unsigned long> (parent)) + ")");
    // INSERT YOUR CODE HERE
    // ...
}