#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "MemoryBlock.h"

class MemoryManager {
private:
    MemoryBlock* head;

public:
    MemoryManager();
    ~MemoryManager();

    void addBlock(int size);
    void display();

    void firstFit(int size);
    void bestFit(int size);
    void worstFit(int size);

    void mergeFreeMemory();
};

#endif
