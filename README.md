# Hospital Patient Priority Queue

A console-based Hospital Queue Management System using Priority-based Singly Linked Lists in C.

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)

## Overview
This project simulates an emergency hospital triage system. Instead of treating patients strictly on a first-come, first-served basis, patients are managed in a priority queue backed by an actively sorting singly linked list. When a new patient arrives, they are inserted dynamically according to the severity of their condition. The hospital staff can then treat "the next critical patient," assuring those with life-threatening needs are always placed at the front (`head`) of the queue.

---

## Features
- **Insert patient with priority**: Append records in automatically sorted order (`1` Emergency, `2` Critical, `3` Normal, `4` General).
- **Display all patients sorted by priority**: View the entire queue to see who is next.
- **Treat highest priority patient first**: Removes the patient at the head of the list.
- **Delete patient by ID**: Remove anyone who cancels or leaves triage early.
- **Search patient by ID**: Find details using a unique identifier.
- **Reverse the queue**: Invert the sorting order of the list.
- **Find middle patient using Floyd's algorithm**: Uses the fast/slow (hare & tortoise) pointer technique.
- **Show statistics**: Detailed counters for total patients and breakdown by specific status (Emergency, Critical, Normal, General count).
- **Save and load from file (data persistence)**: Patient queue logic automatically stores and remembers existing records from a localized `patients.txt` file across program restarts!

---

## Data Structure
The core of this system relies on a **Singly Linked List** configured for prioritized insertion. 

Each time a new patient structure is created, the system begins scanning at the `head`. The traversal continues only as long as existing nodes have a higher priority (lower numeric value) than the new patient. The new node is then spliced exactly in front of the first recorded patient with a lesser condition severity, keeping it sorted dynamically without running complete array sorts `O(n log n)`.

```c
struct patient
{
    int id;                
    char name[50];         
    int age;               
    int priority;          
    struct patient *next;  
};
```

---

## Time Complexity Table
A breakdown of the algorithm efficiencies handling the list interactions:

| Operation    | Time Complexity | Description |
| -------- | ------- |------- |
| **Insert** | `O(n)` | Must traverse the list sequentially to find the correct priority gap |
| **Delete** | `O(n)` | Sequential search needed to reach the target ID before deletion |
| **Search** | `O(n)` | Must touch each node in the worst-case scenario (item at the tail) |
| **Display** | `O(n)` | Will iterate through the entire linked list to print each node |
| **Find Middle** | `O(n)` | Floyd's algorithm uses pointers skipping 2 nodes, but still proportional to list size |

---

## How to Compile and Run
You need a `gcc` compiler on your path to run this program. 

**Windows:**
```cmd
gcc hospital.c -o hospital.exe && hospital.exe
```

**Linux:**
```bash
gcc hospital.c -o hospital && ./hospital
```

---

## Sample Output
Below is an example detailing patient entry sorting by strict priority values:

### Console Output
```text
1 Insert Patient
2 Display Queue
3 Treat First Patient
4 Delete By ID
5 Search Patient
6 Reverse Queue
7 Find Middle
8 Show Statistics
9 Save and Exit
10 Update Patient
Enter choice: 1
Enter ID: 101
Enter Name: John Doe
Enter Age: 45
Select Priority
1 Emergency
2 Critical
3 Normal
4 General
3
```
**(Assume entering IDs 102 as General and 103 as Critical)...**

```text
Enter choice: 2

ID   Name         Age   Priority
---------------------------------
103   Jane Smith   29   Critical
101   John Doe     45   Normal
102   Bob Ross     52   General
```

```text
Enter choice: 8
Total Patients: 3
Emergency Patients: 0
Critical Patients: 1
Normal Patients: 1
General Patients: 1
```

---

## Project Structure
```text
DSA project/
├── hospital.c        # Main source code logic & data structures implementation
├── patients.txt      # Data persistence flat-file database
├── .gitignore        # Ignores compilation outputs (.exe, .o) and database
└── README.md         # Project documentation (You are here!)
```

---
**Author:** Shanky Pal — 1st Year B.Tech CSE Student  
**GitHub:** [Shanky085](https://github.com/Shanky085)
