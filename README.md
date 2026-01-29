🧠 Memory Allocation Simulator (C++)
====================================

📌 Description
--------------

This project is a Memory Allocation Simulator developed in C++, designed to demonstrate how an Operating System allocates and manages memory using different contiguous memory allocation strategies.

The simulator helps in understanding core OS concepts such as:

-   Memory blocks
-   Allocation strategies
-   Fragmentation
-   Memory compaction (merge)

It uses a linked list--based memory model to closely simulate real-world memory behavior in operating systems.
* * * * *

🚀 Features
-----------

-   Simulation of contiguous memory allocation
-   Supports multiple allocation strategies:
    -   First Fit
    -   Next Fit
    -   Best Fit
    -   Worst Fit
-   Demonstrates:
    -   Internal & External Fragmentation
    -   Memory Splitting
    -   Memory Compaction (Merging free blocks)
-   Modular and extendable project structure
-   Beginner-friendly yet internship‑level system design
* * * * *
🛠️ Technologies Used
---------------------

-   Language: C++
-   Core Concepts:
    -   Operating Systems
    -   Memory Management
    -   Linked Lists
    -   Dynamic Memory Allocation
    -   Modular Programming (Multi-file project)
* * * * *
🧩 Design Approach
------------------
The project follows a separation of concerns approach to improve readability and scalability.

### 🔹 Key Design Decisions
-   Memory Block
    -   Represents a single chunk of memory
    -   Stores size and allocation status
-   Allocation Strategy
    -   Allocation logic is strategy-based (First Fit, Best Fit, etc.)
    -   Same memory structure, different policies
-   Memory Manager
    -   Acts as a controller
    -   Handles allocation, merging, and visualization
-   Visualization
    -   Text-based output for easy understanding
    -   Clearly shows allocated vs free memory
* * * * *
📊 Output Visualization
----------------------
### Legend
-   `+` → Allocated Memory
-   `-` → Free Memory
### Example Output
|++++++| 6 (allocated)

|----|   4 (free)  

This visualization helps in:
-   Observing fragmentation
-   Understanding allocation decisions
-   Seeing the effect of memory compaction
* * * * *
⚙️ How to Compile and Run
-------------------------
### Step 1: Navigate to the Project Directory
`cd memory_allocation `
### Step 2: Compile the Program
`g++ main.cpp MemoryManager.cpp -o memory `
### Step 3: Run the Executable
#### Windows
`memory `
#### Linux / macOS
`./memory`



🔮 Future Scope
---------------
-   Paging and segmentation simulation
-   Memory deallocation by process ID
-   GUI-based visualization
-   Performance metrics (memory utilization, wastage)
-   Policy-based strategy design (Strategy Pattern)
* * * * *
📬 Contact
----------

Author: Nainsi Raja Parmar\
Purpose:Learning Project\
Domain: Operating Systems & System Programming
## Documentation

[Documentation](https://linktodocumentation)

