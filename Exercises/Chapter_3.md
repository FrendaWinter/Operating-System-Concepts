# Chapter 3 exercises

#### 3.1 Using the program shown in Figure 3.30, explain what the output will be at `LINE` A.

```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int value = 5;
int main()
{
    pid_t pid;
    pid = fork();
    if (pid == 0) { /* child process */
        value += 15;
        printf("CHILD: value = %d\n",value); /* LINE B */
        return 0;
    }
    else if (pid > 0) { /* parent process */
        wait(NULL);
        printf("PARENT: value = %d\n",value); /* LINE A */
        return 0;
    }
}
```

Output: `PARENT: value = 5`

- When `fork()` is called, the operating system creates a new process called the child process, which is a duplicate of the parent process.
- Both the parent and child processes have their own separate memory space, including their own copies of all variables.
- Any changes made to a variable in one process (parent or child) will not affect the variable in the other process.

So after `wait(NULL);` -> the child process finishes, the parent continues execution. -> `value` of parent process still equal to `5`

Try to print `value` of child process, it return `CHILD: value = 20`

#### 3.2 Including the initial parent process, how many processes are created by the program shown in Figure 3.31?


```c
#include <stdio.h>
#include <unistd.h>
int main()
{
    /* fork a child process */
    fork();
    /* fork another child process */
    fork();
    /* and fork another */
    fork();

    return 0;
}
```

8 process: 
- First `fork();` -> 1 -> 2
- Second `fork();` -> 2 -> 4
- Third `fork();` -> 4 -> 8

#### 3.3 Original versions of Apple’s mobile IOS operating system provided no means of concurrent processing. Discuss three major complications that concurrent processing adds to an operating system.
- Context Switching Overhead

---

#### 3.4 The Sun UltraSPARC processor has multiple register sets. Describe what happens when a context switch occurs if the new context is already loaded into one of the register sets. What happens if the new context is in memory rather than in a register set and all the register sets are in use?
A context switch here simply requires changing the pointer to the current register set.

---

#### 3.5 When a process creates a new process using the fork() operation, which of the following states is shared between the parent process and the child process?
- Stack
- Heap
- Shared memory segments

Each process have their own Stack and Heap. Copy init value from parent but not share.

Shared memory segments explicitly created using inter-process communication (`IPC`) mechanisms (e.g., `shmget`, `mmap` with `MAP_SHARED`) are shared between the parent and the child. Both processes can access and modify the same shared memory region.

---

#### 3.6 Consider the “exactly once” semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a network problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.

---

#### 3.7 Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPC s?

### 3.8 Describe the differences among short-term, medium-term, and long-term scheduling

**Short-Term Scheduling (CPU Scheduling):**

- Purpose: Determines which process in the ready queue will be executed by the CPU next.
- Speed: Operates very quickly, as decisions are made frequently (every few milliseconds).
- Functionality: Transfers the selected process from the ready state to the running state, ensuring efficient CPU utilization.
- Execution: Often involves loading process instructions and data from main memory or CPU cache into the CPU registers.

**Long-Term Scheduling (Job Scheduling):**

- Purpose: Determines which programs or processes are admitted into the system for processing.
- Speed: Operates at a slower pace compared to short-term scheduling, as it manages high-level decisions like admitting new jobs into the system.
- Functionality: Loads processes from secondary storage (e.g., disk) into main memory, deciding the mix of I/O-bound and CPU-bound processes to balance system performance.

**Medium-Term Scheduling (Swapping):**

- Purpose: Optimizes system performance by temporarily removing (`swapping out`) processes from main memory and reintroducing them later (`swapping in`).
- Speed: Operates slower than short-term but faster than long-term scheduling. It manages memory resources effectively.
- Functionality: Frees up main memory by moving processes to secondary storage (e.g., a swap file or partition) and brings them back when resources are available or when a process has higher priority.

#### 3.10 Construct a process tree similar to Figure 3.8. To obtain process information for the UNIX or Linux system, use the command `ps -ael`

Use the command `man ps` to get more information about the `ps` command. The task manager on Windows systems does not provide the parent process ID , but the process monitor tool, available from `technet.microsoft.com`, provides a process-tree tool

---

####  3.11 Explain the role of the init process on UNIX and Linux systems in regard to process termination.

- **Adopting Orphaned Processes:** When a parent process terminates before its child processes, the child processes become "orphaned."The init process (with PID 1) automatically adopts these orphaned processes, ensuring they remain managed by the system.

- **Reaping Zombie Processes:** When a process terminates, it enters a "zombie" state until its parent retrieves its exit status using system calls like wait() or waitpid(). If the parent process fails to perform this cleanup or has already terminated, init reaps the zombie processes. This prevents the accumulation of unused process table entries, which could otherwise lead to resource exhaustion.
- 
---

####  3.12 Including the initial parent process, how many processes are created by the program shown in Figure 3.32?

We have 4 `fork()` so 2^4 = 16

```c
#include <stdio.h>
#include <unistd.h>
int main()
{
    int i;
    for (i = 0; i < 4; i++)
    fork();
    return 0;
}
```
---

####  3.13 Explain the circumstances under which which the line of code marked printf("LINE J") in Figure 3.33 will be reached.
The line of code printf("LINE J"); in the child process section will be reached only if the execlp() function fails.
Explanation:

The `execlp()` Function:
- `execlp()` replaces the current process image with a new process image specified by the file path (in this case, `/bin/ls`).
- If `execlp()` is successful, the child process is replaced entirely by the ls program, and no subsequent lines in the child process will execute.
- If `execlp()` fails (e.g., because the file `/bin/ls` does not exist or there are insufficient permissions to execute it), the `execlp()` call returns -1, and the code following it (including `printf("LINE J");`) will be executed.

Key Conditions for `execlp()` Failure:
- The specified program (`/bin/ls`) does not exist at the given path.
- The program exists but the process lacks execute permissions.
- Other system-level errors (e.g., lack of memory or too many open files).

Parent Process Behavior:
- The parent process is unaffected by the `execlp()` call in the child process. It will wait for the child process to complete (successful or otherwise) and then print `Child Complete`.

---

####  3.14 Using the program in Figure 3.34, identify the values of pid at lines A, B, C, and D. (Assume that the actual pids of the parent and child are 2600 and 2603, respectively.)

[Code](../Code/Chapter_3/3_34.c)

Here is how the values of `pid` and `pid1` are determined at lines A, B, C, and D based on the behavior of the `fork()` system call:

1. **Behavior of `fork()`**:
   - When `fork()` is called, it creates a new child process.
   - In the **child process**, `fork()` returns `0`.
   - In the **parent process**, `fork()` returns the **PID of the child process**.

2. **Details of Variables**:
   - `pid`: Holds the return value of `fork()`.
   - `pid1`: Set using `getpid()`, which retrieves the PID of the current process.

### Values at Each Line
| Line  | Process | Explanation                                     | Value         |
| ----- | ------- | ----------------------------------------------- | ------------- |
| **A** | Child   | `fork()` returns `0` in the child process.      | `pid = 0`     |
| **B** | Child   | `getpid()` retrieves the child’s PID (`2603`).  | `pid1 = 2603` |
| **C** | Parent  | `fork()` returns the PID of the child (`2603`). | `pid = 2603`  |
| **D** | Parent  | `getpid()` retrieves the parent’s PID (`2600`). | `pid1 = 2600` |

---

####  3.15 Give an example of a situation in which ordinary pipes are more suitable than named pipes and an example of a situation in which named pipes are more suitable than ordinary pipes.

---

#### 3.16 Consider the RPC mechanism. Describe the undesirable consequences that could arise from not enforcing either the “at most once” or “exactly once” semantic. Describe possible uses for a mechanism that has neither of these guarantees.

---

#### 3.17 Using the program shown in Figure 3.35, explain what the output will be at lines X and Y.

![Output 3.35](../Assets/c3_3.35.png)

[Code](../Code/Chapter_3/3_35.c)

The child has its own separate memory space, meaning changes in the child's memory do not affect the parent's memory.

**Child Process (pid == 0):**

- Iterates through the nums array and modifies each element (nums[i] *= -i).
- Prints the modified array values at LINE X.

**Parent Process (pid > 0):**

- Waits for the child process to complete using wait(NULL).
- Prints its own version of the nums array at LINE Y, which remains unmodified.

---

#### 3.18 What are the benefits and the disadvantages of each of the following? Consider both the system level and the programmer level.
a. Synchronous and asynchronous communication
b. Automatic and explicit buffering
c. Send by copy and send by reference
d. Fixed-sized and variable-sized messages


#### 3.19

![3.19 result](../Assets/c3_3.19.png)

**PROCESS STATE CODES** `man ps`

- `D`    uninterruptible sleep (usually I/O)
- `I`    idle kernel thread
- `R`    running or runnable (on run queue)
- `S`    interruptive sleep (waiting for an event to complete)
- `T`    stopped by job control signal
- `t`    stopped by debugger during the tracing
- `W`    paging (not valid since Linux 2.6)
- `X`    dead (should never be seen)
- `Z`    defunct (“zombie”) process, terminated but not reaped by its parent

#### 3.20

[Code](../Code/Chapter_3/3.20.c)
---

#### 3.21

[Code](../Code/Chapter_3/3.21.c)

Ref: https://en.wikipedia.org/wiki/Collatz_conjecture


---

#### 3.22

[Code](../Code/Chapter_3/3.22.c)

#### 3.23

[Server Code](../Code/Chapter_3/3.22/Server.java)
[Client Code](../Code/Chapter_3/3.24/Client.java)

#### 3.24

[Server Code](../Code/Chapter_3/3.22/Server.java)
[Client Code](../Code/Chapter_3/3.24/Client.java)

---

#### 3.25

[Server Code](../Code/Chapter_3/3.22/Server.java)
[Client Code](../Code/Chapter_3/3.24/Client.java)

---

## Programming Projects