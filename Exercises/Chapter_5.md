# Chapter 5 exercises

## Practice Exercises

#### 5.1 In Section 5.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized.

Disabling interrupts on a multiprocessor can be time consuming, since
the message is passed to all the processors. This message passing delays entry into each critical section, and system efficiency decreases. Also consider the effect on a system’s clock if the clock is kept updated by interrupts.

---

#### 5.2 Explain why Windows, Linux, and Solaris implement multiple locking mechanisms. Describe the circumstances under which they use spin-locks, mutex locks, semaphores, adaptive mutex locks, and condition variables. In each case, explain why the mechanism is needed.

Why?
- Diverse Use Cases
- Performance Optimization
- Fairness and Priority Handling
- Backward Compatibility and Legacy Support

---

#### 5.3 What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer.

Busy waiting -> Process is on a continuously loop to wait for order ~ Spin lock

---

#### 5.4 Explain why spinlocks are not appropriate for single-processor systems yet are often used in multiprocessor systems.

Spinlocks are not appropriate for single-processor systems because they rely on a busy-waiting mechanism where the thread continuously checks (or "spins") for a lock to become available. On a single-processor system, only one thread or process can run at a time. If a thread is holding a lock, the waiting thread will keep spinning, consuming CPU cycles unnecessarily, instead of allowing the processor to switch to the thread holding the lock so it can finish its work and release the lock. This results in a waste of system resources and makes progress impossible until the spinning thread is preempted.

In contrast, spinlocks are often used in multiprocessor systems because they are lightweight and efficient in scenarios where the waiting time for the lock is expected to be very short. Since multiple processors can run threads concurrently, a thread spinning on one processor does not block the thread holding the lock from running on another processor and releasing the lock. This eliminates the overhead of context switching, making spinlocks ideal for quick lock acquisitions in multiprocessor systems.

---

#### 5.5 Show that, if the wait() and signal() semaphore operations are not executed atomically, then mutual exclusion may be violated.

---

#### 5.6 Illustrate how a binary semaphore can be used to implement mutual exclusion among n processes.

## Exercises

#### 5.7 Race conditions are possible in many computer systems. Consider a banking system that maintains an account balance with two functions: deposit(amount) and withdraw(amount). These two functions are passed the amount that is to be deposited or withdrawn from the bank account balance. Assume that a husband and wife share a bank account. Concurrently, the husband calls the withdraw() function and the wife calls deposit(). Describe how a race condition is possible and what might be done to prevent the race condition from occurring.

---

#### 5.8 The first known correct software solution to the critical-section problem for two processes was developed by Dekker. The two processes, P0 and P1 , share the following variables:

```c
    boolean flag[2]; /* initially false */
    int turn;
```

The structure of process Pi `(i == 0 or 1)` is shown in `Figure 5.21`. The
other process is Pj `(j == 1 or 0)`. Prove that the algorithm satisfies all three requirements for the critical-section problem.

1. Mutual exclusion is preserved.
2. The progress requirement is satisfied.
3. The bounded-waiting requirement is met.

[Code](../Code/Chapter_5/5.8/main.c)

---

#### 5.9 The first known correct software solution to the critical-section problem for n processes with a lower bound on waiting of `n − 1` turns was presented by Eisenberg and McGuire. The processes share the following variables:

```c
enum pstate {idle, want in, in cs};
pstate flag[n];
int turn;
```
All the elements of flag are initially idle. The initial value of turn is immaterial (between 0 and n-1). The structure of process Pi is shown in `Figure 5.22`. Prove that the algorithm satisfies all three requirements for the critical-section problem.

---

#### 5.10 Explain why implementing synchronization primitives by disabling interrupts is not appropriate in a single-processor system if the synchronization primitives are to be used in user-level programs.

---

#### 5.11 Explain why interrupts are not appropriate for implementing synchronization primitives in multiprocessor systems.

Disabling interrupts on a multiprocessor can be time consuming, since
the message is passed to all the processors. This message passing delays entry into each critical section, and system efficiency decreases. Also consider the effect on a system’s clock if the clock is kept updated by interrupts.

---

#### 5.12 The Linux kernel has a policy that a process cannot hold a spinlock while attempting to acquire a semaphore. Explain why this policy is in place.

---

#### 5.13 Describe two kernel data structures in which race conditions are possible. Be sure to include a description of how a race condition can occur.

1. **Stacks**
   - **How a Race Condition Can Occur**:
     If two processes attempt to push or pop elements from a shared stack simultaneously, race conditions can arise. For example:
     - Two processes attempt to `pop` from the stack at the same time. Both may read the same top element before the stack pointer is updated, leading to duplicate data being accessed.
     - Similarly, during `push`, two processes could overwrite the stack pointer simultaneously, leading to data corruption or loss.

2. **Trees**
   - **How a Race Condition Can Occur**:
     When two processes modify a shared tree simultaneously (e.g., inserting or removing nodes), race conditions can occur. For example:
     - If two processes attempt to **remove the same node** at the same time, they might both call `free()` on the same memory address, leading to undefined behavior or crashes.
     - If one process is **adding a node** while another is **traversing or removing a node**, the traversal may encounter invalid or partially updated data, leading to corruption or segmentation faults.

---

#### 5.14 Describe how the `compare_and_swap()` instruction can be used to provide mutual exclusion that satisfies the bounded-waiting requirement.

---

#### 5.15 Consider how to implement a mutex lock using an atomic hardware instruction. Assume that the following structure defining the mutex lock is available:

```c
typedef struct {
    int available;
} lock;
```
(available == 0) indicates that the lock is available, and a value of 1 indicates that the lock is unavailable. Using this struct, illustrate how the following functions can be implemented using the test and `set()` and `compare_and_swap()` instructions:

- `void acquire(lock *mutex)`
- `void release(lock *mutex)`

Be sure to include any initialization that may be necessary.

#### 5.16 The implementation of mutex locks provided in Section 5.5 suffers from busy waiting. Describe what changes would be necessary so that a process waiting to acquire a mutex lock would be blocked and placed into a waiting queue until the lock became available.
####  5.17 Assume that a system has multiple processing cores. For each of the following scenarios, describe which is a better locking mechanism a spinlock or a mutex lock where waiting processes sleep while waiting for the lock to become available:
- The lock is to be held for a short duration.
- The lock is to be held for a long duration.
- A thread may be put to sleep while holding the lock.

#### 5.22 Windows Vista provides a lightweight synchronization tool called slim reader–writer locks. Whereas most implementations of reader–writer locks favor either readers or writers, or perhaps order waiting threads using a FIFO policy, slim reader–writer locks favor neither readers nor writers, nor are waiting threads ordered in a FIFO queue. Explain the benefits of providing such a synchronization tool.
#### 5.23 Show how to implement the wait() and signal() semaphore operations in multiprocessor environments using the test_and_set() instruction. The solution should exhibit minimal busy waiting.
#### 5.24 Exercise 4.26 requires the parent thread to wait for the child thread to finish its execution before printing out the computed values. If we let the parent thread access the Fibonacci numbers as soon as they have been computed by the child thread—rather than waiting for the child thread to terminate—what changes would be necessary to the solution for this exercise? Implement your modified solution.
#### 5.25 Demonstrate that monitors and semaphores are equivalent insofar as they can be used to implement solutions to the same types of synchronization problems.
#### 5.26 Design an algorithm for a bounded-buffer monitor in which the buffers (portions) are embedded within the monitor itself.
#### 5.27 The strict mutual exclusion within a monitor makes the bounded-buffer monitor of Exercise 5.26 mainly suitable for small portions.
1. Explain why this is true.
2. Design a new scheme that is suitable for larger portions.
#### 5.28 Discuss the tradeoff between fairness and throughput of operations in the readers–writers problem. Propose a method for solving the readers–writers problem without causing starvation.

#### 5.29 How does the signal() operation associated with monitors differ from the corresponding operation defined for semaphores?
#### 5.30 Suppose the signal() statement can appear only as the last statement in a monitor function. Suggest how the implementation described in Section 5.8 can be simplified in this situation.
#### 5.31 Consider a system consisting of processes P1 , P2 , ..., Pn, each of which has a unique priority number. Write a monitor that allocates three identical printers to these processes, using the priority numbers for deciding the order of allocation.
#### 5.32 A file is to be shared among different processes, each of which has a unique number. The file can be accessed simultaneously by several processes, subject to the following constraint: the sum of all unique numbers associated with all the processes currently accessing the file must be less than n. Write a monitor to coordinate access to the file.

---

#### 5.33 When a signal is performed on a condition inside a monitor, the signaling process can either continue its execution or transfer control to the process that is signaled. How would the solution to the preceding exercise differ with these two different ways in which signaling can be performed?
#### 5.34 Suppose we replace the wait() and signal() operations of monitors with a single construct await(B), where B is a general Boolean expression that causes the process executing it to wait until B becomes true.
1. Write a monitor using this scheme to implement the readers–writers problem.
2. Explain why, in general, this construct cannot be implemented efficiently.
3. What restrictions need to be put on the await statement so that it can be implemented efficiently? (Hint: Restrict the generality of B; see [Kessels (1977)].)
#### 5.35 Design an algorithm for a monitor that implements an alarm clock that enables a calling program to delay itself for a specified number of time units (ticks). You may assume the existence of a real hardware clock that invokes a function tick() in your monitor at regular intervals.