#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

struct MemoryBlock {
    int size;
    bool allocated;
    MemoryBlock* prev;
    MemoryBlock* next;

    MemoryBlock(int s) {
        size = s;
        allocated = false;
        prev = nullptr;
        next = nullptr;
    }
};

#endif
