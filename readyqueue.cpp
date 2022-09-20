#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     //TODO: add your code here ##done
     q_size = 0; //initalizing size of q to 0
     for (int i = 0; i < 50; i++){
        rdy_queue[i] = NULL;
     }
 }

 void ReadyQueue::max_heapify(int s; int i){

    int largest = int id;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //left node
    if (left < s && rdy_queue[left] > rdy_queue[largest]){
        largest = left;
    }
    if(right < s && rdy_queue[right > rdy_queue[largest]]){
        largest = right;
    }
    if(largest != i){
        swap(i, largest)
        max_heapify(s, largest)
    }
 }

void ReadyQueue::swap(int p1, int p2){

    //PCB* temp = NULL;
    temp = rdy_queue[p1];
    rdy_queue[p1] = rdy_queue[p2];
    rdy_queue[p2] = temp;
}
/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    // When adding a PCB to the queue, you must change its state to READY.
    pcbPtr->setState(ProcState::READY);
    q_size = q_size + 1; //increment size of the heap

    rdy_queue[q_size-1] =  pcbPtr;

    //write heapify.....


}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.

    


}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {

    return q_size;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    //TODO: add your code here
    for (int i = 0; i < 50; i++){
        if(rdy_queue[i] = NULL){
            cout << i, queue[i] -> priority;
        }
    }
}