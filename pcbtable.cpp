/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Joshua Shor, Tam Nguyen
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"
#include <vector>
/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
    id = pid;
    priority = priority;
    state = state;
    vector<PCB> pcb_table_elem;
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
    
    delete pcb_table_elem;
    /*
   for(int i = 1; i<size; i++){
        delete pcb_table_elem(i);
   }
   */
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    return pcb_table_elem(idx);
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    pcb_table_elem.insert(idx, *pcb);
}