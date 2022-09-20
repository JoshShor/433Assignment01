
/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Tam Nguyen, Josh Shor
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */
#include<iostream>
#include "pcbtable.h"
#include <vector>
using namespace std;


/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
    //id = pid;
    priority = priority;
    state = state;
    pcb_table_elem = vector<PCB*>(size);
    std::cout << "initiatize vector with size ="<< pcb_table_elem.size() << std::endl;
   
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
     //delete pcb_table_elem;
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
      return  pcb_table_elem.at(idx);
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {

    std::cout << "addPCB = " << idx << std::endl;
    std::cout << "addPCB = " << pcb << std::endl;
    //this is giving a segmentation fault error?
    auto it = pcb_table_elem.begin() + idx;

    pcb_table_elem.insert(it, pcb);
    
    std::cout << "addPCB complete"<<  std::endl;
  
}
