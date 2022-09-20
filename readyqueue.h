/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author Tam Nguyen, Josh Shor
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */

#pragma once
#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */
class ReadyQueue
{
private:
    int arr_size;
    int capacity;
    PCB *arr;
    // choose a data structure for the ReadyQueue. No STL class is allowed.

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue();

    /**
     * @brief Destructor
     */
    ~ReadyQueue() {}

    // You may add additional member functions, but don't change the definitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
    void addPCB(PCB *pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
    PCB *removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
    int size();

    /**
     * @brief Display the PCBs in the queue.
     */
    void displayAll();
    /**
     * @brief support queue
     */
    void siftDown(int i);
    /**
     * @brief support queue
     */
    void siftUp(int i);
    /**
     * @brief support queue
     */
    PCB getMax();
    /**
     * @brief support queue
     */
    bool isLeaf(int i);
    /**
     * @brief support queue
     */
    int right(int i);
    /**
     * @brief support queue
     */
    int left(int i);
    /**
     * @brief support queue
     */
    int parent(int i);
    /**
     * @brief support queue
     */
    void swap(PCB arr[], int q, int i);
};
