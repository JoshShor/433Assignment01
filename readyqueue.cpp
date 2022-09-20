#include <iostream>
#include "readyqueue.h"
#include <string>
using namespace std;

/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.cpp
 * @author Tam Nguyen, Josh Shor
 * @brief This is the implementation file for the PCBTable class.
 */


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    int n = 100;
    capacity = n;
    arr_size = 0;
    arr = new PCB[capacity];
    std::cout << "initiatize ReadyQueue with size =" << arr << std::endl;
   
 }
/**
 * @brief swap 
 * 
 * @param arr 
 * @param q 
 * @param i 
 */
void ReadyQueue::swap(PCB arr[], int q, int i)
{
    PCB temp = arr[q];
    arr[q] = arr[i];
    arr[i] = temp;
}
/**
 * @brief return parent
 * 
 * @param i 
 * @return int 
 */
int ReadyQueue::parent(int i)
{
    return (i-1)/2;
}
/**
 * @brief return left
 * 
 * @param i 
 * @return int 
 */
int ReadyQueue::left(int i)
{
    return 2*i + 1;
}
/**
 * @brief return right
 * 
 * @param i 
 * @return int 
 */
int ReadyQueue::right(int i)
{
    return 2*i + 2;
}

/**
 * @brief return isLeaf
 * 
 * @param i 
 * @return true 
 * @return false 
 */
bool ReadyQueue::isLeaf(int i)
{
    return (i >= arr_size/2);
}
/**
 * @brief return getMax
 * 
 * @return PCB 
 */
PCB ReadyQueue::getMax()
{
    return arr[0];
}
/**
 * @brief sends upwards 
 * 
 * @param i 
 */
 void  ReadyQueue::siftUp(int i)
{
    while(i > 0 && arr[parent(i)].priority < arr[i].priority)
    {
        swap(arr, i, parent(i));
        i = parent(i);
    }
}
/**
 * @brief sifts downwards
 * 
 * @param i 
 * @return * Sifts 
 */
void  ReadyQueue::siftDown(int i)
{
    while(!isLeaf(i))
    {
        int l = left(i);
        int r = right(i);
        int larger = l;
        if(r < arr_size)
            larger = (arr[l].priority > arr[r].priority) ? l : r;
        if(arr[i].priority >= arr[larger].priority)
            break;
        swap(arr, i, larger);
        i = larger;
    }
}


/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
      pcbPtr->setState(ProcState::READY);

      if(arr_size <= capacity){
             int i = arr_size;
             arr[i] = *pcbPtr;
             siftUp(i);
             arr_size++;
      }
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.
      PCB res;
      if(arr_size >= 0) {
            if(arr_size == 1) {
                res = arr[--arr_size];
                 res.setState(ProcState::RUNNING);
                return &res;
            }
            res = arr[0];
            arr[0] = arr[--arr_size];
            siftDown(0);
            res.setState(ProcState::RUNNING);   
            return &res;
    }
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    return arr_size;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    std::cout <<  "Display Processes in ReadyQueue:"<< std::endl;
    for(int i = 0; i < arr_size; i++){
        arr[i].display();
          
    }
}


