# Chapter 7 Exercises

#### 7.1 List three examples of deadlocks that are not related to a computer-system environment.

Ex1: Two car in single lane.

---

#### 7.2 Suppose that a system is in an unsafe state. Show that it is possible for the processes to complete their execution without entering a deadlocked state.

Safe and unsafe state is pre-calculation for possible of deadlock happen. So it may not occur deadlock all the time when system in unsafe state.

The process can be release the resource before request new one. And the unexpected resource will be able to make the system be safe from deadlock.

---

#### 7.3 Consider the following snapshot of a system: 

**Allocation Matrix**  

| Process | A | B | C | D |
|---------|---|---|---|---|
| P0      | 0 | 0 | 1 | 2 |
| P1      | 1 | 0 | 0 | 0 |
| P2      | 1 | 3 | 5 | 4 |
| P3      | 0 | 6 | 3 | 2 |
| P4      | 0 | 0 | 1 | 4 |

**Maximum Demand Matrix**

| Process | A | B | C | D |
|---------|---|---|---|---|
| P0      | 0 | 0 | 1 | 2 |
| P1      | 1 | 7 | 5 | 0 |
| P2      | 2 | 3 | 5 | 6 |
| P3      | 0 | 6 | 5 | 2 |
| P4      | 0 | 6 | 5 | 6 |

**Available Resources**

| A | B | C | D |
|---|---|---|---|
| 1 | 5 | 2 | 0 |

Answer the following questions using the banker’s algorithm:
1. What is the content of the matrix Need?

    `Need[i][j] = Max[i][j] - Available[i][j]`

    | Process | A | B | C | D |
    |---------|---|---|---|---|
    | P0      | 0 | 0 | 0 | 0 |
    | P1      | 0 | 7 | 5 | 0 |
    | P2      | 1 | 0 | 0 | 2 |
    | P3      | 0 | 0 | 2 | 0 |
    | P4      | 0 | 6 | 4 | 2 |

2. Is the system in a safe state?

    - After release resource P0 [0, 0, 1, 2]: -> Available resource: [1, 5, 3, 2] 
    - After release resource P2 [1, 3, 5, 4]: -> Available resource: [2, 8, 8, 6] 
    - After release resource P1 [1, 0, 0, 0]: -> Available resource: [3, 8, 8, 6] 
    - After release resource p3 [0, 6, 3, 2]: -> Available resource: [3, 14, 11, 8]
    - And we can release the resource from last process P4 -> System in the safe state.

3. If a request from process P1 arrives for (0,4,2,0), can the request be granted immediately?

    Yes, we can grant the resource immediately, the available now is [1, 1, 0, 0]. Now the processes release in order p0 -> p2 -> P3 -> p1 -> p4

#### 7.4 A possible method for preventing deadlocks is to have a single, higher-order resource that must be requested before any other resource. For example, if multiple threads attempt to access the synchronization objects A · · · E, deadlock is possible. (Such synchronization objects may include mutexes, semaphores, condition variables, and the like.) We can prevent the deadlock by adding a sixth object F . Whenever a thread wants to acquire the synchronization lock for any object A · · · E, it must first acquire the lock for object F . This solution is known as containment: the locks for objects A · · · E are contained within the lock for object F . Compare this scheme with the circular-wait scheme of Section 7.4.4.

Containment Approach: Introduces a single higher-order lock (F) that must be acquired before any of the other resources (A–E). Prevents deadlocks by ensuring that no two threads can simultaneously attempt to acquire multiple resources in a conflicting order.

Pros:
- Simple to implement.
- Guarantees deadlock prevention.

Cons:
- Reduces parallelism since all threads must acquire F first, even if they don’t need overlapping resources.
- Can lead to unnecessary blocking and performance bottlenecks.

#### 7.5 Prove that the safety algorithm presented in Section 7.5.3 requires an order of m × n^2 operations.



#### 7.6 Consider a computer system that runs 5,000 jobs per month and has no deadlock-prevention or deadlock-avoidance scheme. Deadlocks occur about twice per month, and the operator must terminate and rerun about ten jobs per deadlock. Each job is worth about two dollars (in CPU time), and the jobs terminated tend to be about half done when they are aborted.

A systems programmer has estimated that a deadlock-avoidance algorithm (like the banker’s algorithm) could be installed in the system with an increase of about 10 percent in the average execution time per job. Since the machine currently has 30 percent idle time, all 5,000 jobsper month could still be run, although turnaround time would increase by about 20 percent on average.

1. What are the arguments for installing the deadlock-avoidance algorithm?

    Pros: Don't have to manually deal with deadlock. 

    Cons: Cost more 1000 dollars (in CPU time) ~ 10%. CPU running more.

2. What are the arguments against installing the deadlock-avoidance algorithm?

    If we keep the original system:

    Pros: No money needed. No downtime when upgrade system. Everything is the same.

    Cons: Cost 20 dollars (in CPU times) each month. Have to manually maintain and re-run the task.


#### 7.7 Can a system detect that some of its processes are starving? If you answer “yes,” explain how it can. If you answer “no,” explain how the system can deal with the starvation problem.

The system are technically cannot detect what process is starving, but the process that have number of being victim of termination is high are probably starving. To deal with that, the most common solution is to include the number of rollbacks in the cost factor.

#### 7.8 Is it possible to have a deadlock involving only one single-threaded process? Explain your answer.