#include <iostream>
#include "MemoryManager.h"

using namespace std;

int main() {
    MemoryManager manager;

    manager.addBlock(64);
    manager.addBlock(56);
    manager.addBlock(48);
    manager.addBlock(32);
    manager.addBlock(16);

    int choice, size;

    while (true) {
        cout << "\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Merge Free Memory\n5. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter process size: ";
            cin >> size;
        }

        switch (choice) {
        case 1: manager.firstFit(size); break;
        case 2: manager.bestFit(size); break;
        case 3: manager.worstFit(size); break;
        case 4: manager.mergeFreeMemory(); break;
        case 5: manager.display(); break;
        default: cout << "Invalid choice\n";
        }
    }
    return 0;
}
