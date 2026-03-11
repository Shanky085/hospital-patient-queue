# Hospital Patient Priority Queue Management System

A robust, console-based C application that simulates an emergency room patient queue. The system prioritizes patients based on their condition severity, ensuring those with life-threatening needs are treated first using a dynamically sorted Linked List.

## 🏥 Project Overview
In a busy hospital, patients arrive continuously but must be treated based on medical urgency rather than a "first-come, first-served" basis. This project builds a **Priority Queue** to manage patient intake, prioritize critical cases, and provide an organized interface for hospital staff to manage incoming flow.

---

## 🏗 Data Structure
This program implements a **Singly Linked List** where each node serves as a patient record. The linked list is kept sorted based on the condition's priority rating, guaranteeing the `O(n)` insertion maintains the most critical patient at the `head` of the queue.

```c
struct patient
{
    int id;                // Unique patient identifier
    char name[50];         // Patient's full name
    int age;               // Patient age
    int priority;          // Medical severity (1 = Highest Priority)
    struct patient *next;  // Pointer to the next prioritized patient
};
```

---

## ✨ Features
1. **Insert Patient**: Append patients to the queue with automatic sorting based on severity (Emergency, Critical, Normal, General). Also prevents duplicate patient IDs.
2. **Display Queue**: View the real-time queue hierarchy of who is next.
3. **Treat First Patient**: Dequeues the highest priority patient from the front (`head`) for treatment.
4. **Delete By ID**: Remove a patient who left or cancelled from anywhere in the queue.
5. **Search Patient**: Look up a specific patient's details using their unique ID.
6. **Reverse Queue**: Inverts the Linked List order.
7. **Find Middle**: Locates the patient exactly in the middle of the queue using the "Tortoise and Hare" fast/slow pointer technique.
8. **Show Statistics**: Displays a breakdown of total patients and a summary of how many belong to each medical priority level.
9. **Update Patient**: Safely modify an existing patient's details and resort their priority standing.
10. **Persistent Storage**: Save the queue to a `patients.txt` file and load it automatically upon restarting the application!

---

## 💻 How to Compile and Run

### On Windows (using GCC/MinGW)
1. Open your Command Prompt or PowerShell in the project directory.
2. Compile the source code:
   ```cmd
   gcc hospital.c -o hospital.exe
   ```
3. Run the executable:
   ```cmd
   hospital.exe
   ```

### On Linux (using GCC)
1. Open your terminal in the project directory.
2. Compile the source code:
   ```bash
   gcc hospital.c -o hospital
   ```
3. Run the compiled output:
   ```bash
   ./hospital
   ```

---

## 📸 Sample Output Placeholder

![Sample Program Output placeholder](https://via.placeholder.com/800x400.png?text=Hospital+Management+Console+Output+Screenshot+Placeholder)

---
*Built as a Data Structures and Algorithms (DSA) practical implementation project.*
