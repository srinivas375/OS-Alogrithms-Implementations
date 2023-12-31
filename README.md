# OS Algorithms Implementations

This repository contains implementations of various Operating System (OS) algorithms using C and Python. The implementations cover a range of topics, including CPU scheduling, deadlock handling, disk scheduling, continuous memory allocation, page replacement, process synchronization, system calls, and some Unix commands.

## Implemented Algorithms

### CPU Scheduling

1. **First-Come, First-Served (FCFS):** [C Implementation](CPU%20scheduling/FCFS.c)
2. **Shortest Job First (SJF):** [C Implementation](CPU%20scheduling/SJF.c)
3. **Shortest Remaining Time First (SRTF):** [C Implementation](CPU%20scheduling/SRTF.c)
4. **Round Robin (RR):** [C Implementation](CPU%20scheduling/Round_Robin.c)
5. **Priority Scheduling (Non-preemptive):** [C Implementation](CPU%20scheduling/Priority_Non_Premptive.c)
6. **Priority Scheduling (Preemptive):** [C Implementation](CPU%20scheduling/priority_Premptive.c)

### Deadlock Handling

1. **Banker's Algorithm:** [C Implementation](deadlock/bankers.c)

### Disk Scheduling Algorithms

1. **First-Come, First-Served (FCFS):** [Python Implementation](disk%20scheduling%20algos/FCFS.py)
2. **Shortest Seek Time First (SSTF):** [Python Implementation](disk%20scheduling%20algos/SSTF.py)
3. **SCAN:** [Python Implementation](disk%20scheduling%20algos/SCAN.py)
4. **C-SCAN (Circular SCAN):** [Python Implementation](disk%20scheduling%20algos/CSCAN.py)
5. **LOOK:** [Python Implementation](disk%20scheduling%20algos/LOOK.py)
6. **C-LOOK (Circular LOOK):** [Python Implementation](disk%20scheduling%20algos/CLOOK.py)

### Continuous Memory Allocation

1. **First Fit:** [Python Implementation](memory%20allocation/first%20fit.py)
2. **Best Fit:** [Python Implementation](memory%20allocation/best%20fit.py)
3. **Worst Fit:** [Python Implementation](memory%20allocation/worst%20fit.py)

### Page Replacement Algorithms

1. **FIFO (First-In-First-Out):** [Python Implementation](page%20replacement/FIFO(OOP_implemetation).py)
2. **LRU (Least Recently Used):** [Python Implementation](page%20replacement/LRU(Least_Recently_Used).py)
3. **Optimal:** [Python Implementation](page%20replacement/Optimal.py)
4. **LFU (Least Frequently Used):** [Python Implementation](page%20replacement/LFU(Least_Freqently_Used).py)
5. **MFU (Most Frequently Used):** [Python Implementation](page%20replacement/MFU(Most_Frequently_Used).py)

### Process Synchronization

1. **Producer-Consumer Problem:** [Python Implementation](Process%20synchronisation/producer_consumer.py)
2. **Dining Philosophers:** [Python Implementation](Process%20synchronisation/Dinning_Philosophers.py)
3. **Reader-Writer Problem:** [Python Implementation](Process%20synchronisation/reader_writer.py)

### System Calls

1. **File Management System Calls:** [C Implementation](system%20calls/)
2. **Process Management System Calls:** [C Implementation](system%20calls/)
3. **Zombie Process:** [C Implementation](system%20calls/)

### Unix Commands

1. **List of Unix Commands:** [Python Implementation](unix/man.py)

## Usage

Clone the repository and explore the implementations for each algorithm. Compile C programs and run Python scripts as needed.

```bash
git clone https://github.com/srinivas375/OS-Algorithms-Implementations.git
cd OS-Algorithms-Implementations
# Compile and run C programs
# Execute Python scripts
