#include <iostream>
#include <climits>
#include "MemoryManager.h"

using namespace std;

MemoryManager::MemoryManager() {
    head = nullptr;
}

MemoryManager::~MemoryManager() {
    MemoryBlock* curr = head;
    while (curr) {
        MemoryBlock* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void MemoryManager::addBlock(int size) {
    MemoryBlock* block = new MemoryBlock(size);
    block->next = head;
    if (head) head->prev = block;
    head = block;
}

void MemoryManager::display() {
    cout << "\nMemory Layout:\n";
    MemoryBlock* curr = head;
    while (curr) {
        cout << "|"
             << string(curr->size, curr->allocated ? '+' : '-')
             << "| "
             << curr->size
             << (curr->allocated ? " (allocated)" : " (free)") << endl;
        curr = curr->next;
    }
    cout << endl;
}

void MemoryManager::firstFit(int size) {
    cout << "First Fit Allocation: " << size << endl;
    MemoryBlock* curr = head;

    while (curr) {
        if (!curr->allocated && curr->size >= size) {
            curr->allocated = true;

            if (curr->size > size) {
                MemoryBlock* rem = new MemoryBlock(curr->size - size);
                rem->next = curr->next;
                if (curr->next) curr->next->prev = rem;
                curr->next = rem;
                rem->prev = curr;
                curr->size = size;
            }

            cout << "Memory Allocated!\n";
            return;
        }
        curr = curr->next;
    }

    cout << "Allocation failed.\n";
}

void MemoryManager::bestFit(int size) {
    cout << "Best Fit Allocation: " << size << endl;

    MemoryBlock* best = nullptr;
    int minSize = INT_MAX;

    for (MemoryBlock* curr = head; curr; curr = curr->next) {
        if (!curr->allocated && curr->size >= size && curr->size < minSize) {
            best = curr;
            minSize = curr->size;
        }
    }

    if (!best) {
        cout << "Allocation failed.\n";
        return;
    }

    best->allocated = true;
    if (best->size > size) {
        MemoryBlock* rem = new MemoryBlock(best->size - size);
        rem->next = best->next;
        if (best->next) best->next->prev = rem;
        best->next = rem;
        rem->prev = best;
        best->size = size;
    }

    cout << "Memory Allocated!\n";
}

void MemoryManager::worstFit(int size) {
    cout << "Worst Fit Allocation: " << size << endl;

    MemoryBlock* worst = nullptr;
    int maxSize = -1;

    for (MemoryBlock* curr = head; curr; curr = curr->next) {
        if (!curr->allocated && curr->size >= size && curr->size > maxSize) {
            worst = curr;
            maxSize = curr->size;
        }
    }

    if (!worst) {
        cout << "Allocation failed.\n";
        return;
    }

    worst->allocated = true;
    if (worst->size > size) {
        MemoryBlock* rem = new MemoryBlock(worst->size - size);
        rem->next = worst->next;
        if (worst->next) worst->next->prev = rem;
        worst->next = rem;
        rem->prev = worst;
        worst->size = size;
    }

    cout << "Memory Allocated!\n";
}

void MemoryManager::mergeFreeMemory() {
    cout << "Merging free memory...\n";

    MemoryBlock* curr = head;
    int totalFree = 0;

    while (curr) {
        MemoryBlock* next = curr->next;
        if (!curr->allocated) {
            totalFree += curr->size;

            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;

            delete curr;
        }
        curr = next;
    }

    if (totalFree > 0) {
        addBlock(totalFree);
    }
}
