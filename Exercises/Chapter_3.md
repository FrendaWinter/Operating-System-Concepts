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

---

#### 3.6 Consider the “exactly once” semantic with respect to the RPC mechanism. Does the algorithm for implementing this semantic execute correctly even if the ACK message sent back to the client is lost due to a network problem? Describe the sequence of messages, and discuss whether “exactly once” is still preserved.

---

#### 3.7 Assume that a distributed system is susceptible to server failure. What mechanisms would be required to guarantee the “exactly once” semantic for execution of RPC s?