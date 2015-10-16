/*
 * File:   Traits.h
 * Author: cancian
 *
 * Created on September 27, 2015, 4:16 PM
 */

#ifndef TRAITS_H
#define	TRAITS_H

#include "Debug.h"
#include "CPU.h"
#include "Thread.h"
#include "Model.h"
#include "Scheduler.h"

template<typename T>
struct Traits {
    static const bool enabled = true;
    static const bool debugged = true;
};

template<> struct Traits<Debug> { // CHANGE THE DEBUG LEVEL HERE SETTING THE LEVELS YOU WANT TO SHOW
    static const bool error = true;
    static const bool warning = true;
    static const bool trace = false;
    static const bool info = false;
    static const bool fine = false;
};

template<> struct Traits<CPU> {
    static constexpr double context_switch_overhead = 1.0; // time units
    static constexpr double timer_interrupt_period = 100.0; // time units
};

template<> struct Traits<Thread> {
    static constexpr double cpuBurst = 500.0; // time units
};

template<> struct Traits<Model> {
    static constexpr double simulationLength = 3600.0; // time units
    static constexpr double firstCreation = 550.0; // time units
};

template<> struct Traits<Scheduler> {
    static constexpr double timeSlice = 200.0; // time units
};
#endif	/* TRAITS_H */

