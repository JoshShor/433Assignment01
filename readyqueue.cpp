#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     pcb_arry = new pcb[50];

     // use heapify and max heap here or write another function --JTS
 }

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    //TODO: add your code here
    pcb_arry[size] = *pcbPtr;
    int size = pcb_arry.size();
    int i = size - 1;
    for(int j = 0; j < size; j++){
        heapify(pcb_arry, size, i);
    }
    state = READY;
    return *pcbPtr;
    // When adding a PCB to the queue, you must change its state to READY.
}

void heapify(pcb* pcb_arry[], int size, int i){
    int size = pcb_arry.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < pcb_arry.size() && pcb_arry[left] > pcb_arry[largest]){
        largest = left;
    }
    if(right < pcb_arry.size() && pcb_arry[right] > pcb_arry[largest]){
        largest = right;
    }
    if(largest != i){
        swap(pcb_arry[i], pcb_arry[largest]);
        heapify(pcb* pcb_arry[], int size, largest);
    }
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here

    state = RUNNING;
    // When removing a PCB from the queue, you must change its state to RUNNING.
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //TODO: add your code here
    return sizeof(pcb_arry);
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {

    for (int i = 0, i < pcb_arry.size(); i++) {
        cout << pcb_arry[i] << " ";
    }
    cout << endl;
}