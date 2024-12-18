# Chapter 5 exercises

## Practice Exercises
#### 5.1 In Section 5.4, we mentioned that disabling interrupts frequently can affect the system’s clock. Explain why this can occur and how such effects can be minimized.

---

#### 5.2 Explain why Windows, Linux, and Solaris implement multiple locking mechanisms. Describe the circumstances under which they use spin- locks, mutex locks, semaphores, adaptive mutex locks, and condition variables. In each case, explain why the mechanism is needed.

---


#### 5.3 What is the meaning of the term busy waiting? What other kinds of waiting are there in an operating system? Can busy waiting be avoided altogether? Explain your answer.

---

#### 5.4 Explain why spinlocks are not appropriate for single-processor systems yet are often used in multiprocessor systems.

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

####  5.10 Explain why implementing synchronization primitives by disabling interrupts is not appropriate in a single-processor system if the synchronization primitives are to be used in user-level programs.