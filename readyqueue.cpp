#include <iostream>
#include "readyqueue.h"
#include <string>
using namespace std;


//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    int n = 100;
    capacity = n;
    arr_size = 0;
    arr = new PCB[capacity];
    std::cout << "initiatize ReadyQueue with size =" << arr << std::endl;
   
     //TODO: add your code here
 }

void ReadyQueue::swap(PCB arr[], int q, int i)
{
    PCB temp = arr[q];
    arr[q] = arr[i];
    arr[i] = temp;
}
// Returns the index of the parent for i.
int ReadyQueue::parent(int i)
{
    return (i-1)/2;
}
// Returns the index of i's left node.
int ReadyQueue::left(int i)
{
    return 2*i + 1;
}
// Returns the index of i's right node.
int ReadyQueue::right(int i)
{
    return 2*i + 2;
}

// Returns whether the node at i is a leaf node or not.
bool ReadyQueue::isLeaf(int i)
{
    return (i >= arr_size/2);
}
// Returns the max value of the heap.
PCB ReadyQueue::getMax()
{
    return arr[0];
}
 void  ReadyQueue::siftUp(int i)
{
    while(i > 0 && arr[parent(i)].priority < arr[i].priority)
    {
        swap(arr, i, parent(i));
        i = parent(i);
    }
}
// Sifts the node at i down until it is a leaf or larger than both the left
// and right nodes.
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


