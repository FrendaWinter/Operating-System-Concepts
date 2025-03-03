# Operating-System-Concepts
About the Operating System Concepts book

Ref https://github.com/gg-daddy/ebooks/blob/master/Operating%20System%20Concepts%2C%209th%20Edition.pdf

Author: Abraham Silberschatz, Peter Baer Galvin, Greg Gagne

- [Operating-System-Concepts](#operating-system-concepts)
- [Chapter 1](#chapter-1)
- [Chapter 2](#chapter-2)
    - [System Programs](#system-programs)
    - [Design Goals](#design-goals)
  - [Operating-System Structure](#operating-system-structure)
      - [Layered Approach:](#layered-approach)
      - [Microkernels:](#microkernels)
      - [Modules:](#modules)
      - [Hybrid Systems](#hybrid-systems)
    - [Operating-System Debugging](#operating-system-debugging)
- [Chapter 3](#chapter-3)
    - [Process State](#process-state)
    - [Threads](#threads)
    - [Process Scheduling](#process-scheduling)
    - [Schedulers](#schedulers)
      - [Context Switch](#context-switch)
    - [Process Creation](#process-creation)
    - [Process Termination](#process-termination)
    - [Inter-process Communication](#inter-process-communication)
      - [Shared-Memory Systems](#shared-memory-systems)
      - [Message-Passing Systems](#message-passing-systems)
    - [Examples of IPC Systems](#examples-of-ipc-systems)
      - [POSIX Shared Memory](#posix-shared-memory)
      - [Mach](#mach)
      - [Windows](#windows)
    - [Communication in Client–Server Systems](#communication-in-clientserver-systems)
      - [Sockets](#sockets)
    - [Remote Procedure Call (RPC)](#remote-procedure-call-rpc)
- [Chapter 4 - Threads](#chapter-4---threads)
    - [**AMDAHL’S LAW**](#amdahls-law)
      - [Parallelism and concurrency](#parallelism-and-concurrency)
      - [User and kernel level thread](#user-and-kernel-level-thread)
    - [Thread Libraries](#thread-libraries)
      - [Pthreads](#pthreads)
      - [Windows 32 API](#windows-32-api)
      - [Java Threads](#java-threads)
    - [Implicit Threading](#implicit-threading)
      - [Thread Pools](#thread-pools)
      - [OpenMP](#openmp)
      - [Grand Central Dispatch](#grand-central-dispatch)
      - [Other Approaches](#other-approaches)
    - [Threading Issues](#threading-issues)
      - [Thread canceling](#thread-canceling)
      - [Thread-Local Storage](#thread-local-storage)
      - [Scheduler Activations](#scheduler-activations)
    - [Operating-System Examples](#operating-system-examples)
      - [Windows Threads](#windows-threads)
      - [Linux Threads](#linux-threads)
- [Chapter 5](#chapter-5)
  - [The Critical-Section Problem](#the-critical-section-problem)
  - [Peterson’s Solution](#petersons-solution)
  - [Synchronization Hardware](#synchronization-hardware)
    - [Mutex Locks](#mutex-locks)
    - [Semaphores](#semaphores)
      - [Semaphore Usage](#semaphore-usage)
      - [Semaphore Implementation](#semaphore-implementation)
      - [Deadlocks and Starvation](#deadlocks-and-starvation)
      - [Priority Inversion](#priority-inversion)
  - [Classic Problems of Synchronization](#classic-problems-of-synchronization)
    - [The Bounded-Buffer Problem](#the-bounded-buffer-problem)
    - [The Readers – Writers Problem](#the-readers--writers-problem)
    - [The Dining-Philosophers Problem](#the-dining-philosophers-problem)
  - [Monitors](#monitors)
  - [Synchronization Examples](#synchronization-examples)
  - [Alternative Approaches](#alternative-approaches)
- [Chapter 6](#chapter-6)
  - [Basic Concepts](#basic-concepts)
    - [CPU– I/O Burst Cycle](#cpu-io-burst-cycle)
    - [CPU Schedule](#cpu-schedule)
    - [Preemptive Scheduling](#preemptive-scheduling)
    - [Dispatcher](#dispatcher)
  - [Scheduling Criteria](#scheduling-criteria)
  - [Scheduling Algorithms](#scheduling-algorithms)
  - [Thread Scheduling](#thread-scheduling)
  - [Multiple-Processor Scheduling](#multiple-processor-scheduling)
  - [Real-Time CPU Scheduling](#real-time-cpu-scheduling)
  - [Operating-System Examples](#operating-system-examples-1)
    - [Linux](#linux)
    - [Windows](#windows-1)
    - [Solaris](#solaris)
  - [Algorithm Evaluation](#algorithm-evaluation)
    - [Deterministic Modeling](#deterministic-modeling)
    - [Queueing Models](#queueing-models)
    - [Simulation](#simulation)
    - [Implementation](#implementation)
- [Chapter 7 Deadlocks](#chapter-7-deadlocks)
  - [System model](#system-model)
  - [Deadlock Characterization](#deadlock-characterization)
  - [Deadlock prevention](#deadlock-prevention)
  - [Deadlock prevention](#deadlock-prevention-1)
    - [**Safe state**:](#safe-state)
    - [**Resource-Allocation-Graph Algorithm**:](#resource-allocation-graph-algorithm)
    - [**Banker's Algorithm**:](#bankers-algorithm)
      - [Safety algorithm](#safety-algorithm)
      - [Resource-Request Algorithm](#resource-request-algorithm)
  - [Deadlock detection.](#deadlock-detection)
    - [**Detection-Algorithm Usage**:](#detection-algorithm-usage)
  - [Recovery from deadlock](#recovery-from-deadlock)
- [Chapter 8](#chapter-8)
  - [Main memory](#main-memory)
    - [Address binding.](#address-binding)
    - [Logical Versus Physical Address Space](#logical-versus-physical-address-space)
    - [Dynamic loading](#dynamic-loading)
    - [Dynamic Linking and Shared Libraries.](#dynamic-linking-and-shared-libraries)
  - [Swapping](#swapping)
  - [Contiguous memory allocation](#contiguous-memory-allocation)
    - [**Memory allocation**:](#memory-allocation)
  - [Segmentation](#segmentation)
  - [Paging](#paging)
  - [Structure of page table](#structure-of-page-table)
  - [Example](#example)
- [Chapter 9](#chapter-9)
  - [Demand paging](#demand-paging)
  - [Copy on write](#copy-on-write)
  - [Page replacement](#page-replacement)
    - [Basic page replacement](#basic-page-replacement)
      - [FIFO](#fifo)
      - [Optimal Page Replacement (OPT)](#optimal-page-replacement-opt)
      - [LRU (Least Recently Used)](#lru-least-recently-used)

# Chapter 1

`Operating systems` exist because they offer a reasonable way to solve the problem of creating a usable computing system. 
The fundamental goal of computer systems is to execute programs and to make solving user problems easier. Computer hardware is constructed toward this goal. Since bare hardware alone is not particularly easy to use, application programs are developed. These programs require certain common operations, such as those controlling the I/O devices. The common functions of controlling and allocating resources are then brought together into one piece of software: the operating system.

- System bus:
  - Address bus: to determine where it should be sent or read from
  - Control bus: to determine its operation
  - Data bus: to carry information

![System bus](./Assets/image_1.png)

- **Interrupts:** An interrupt is a signal emitted by a device attached to a computer or from a program within the computer. It requires the operating system (OS) to stop and figure out what to do next. An interrupt temporarily stops or terminates a service or a current process.
  - Example: You press a key on keyboard, it send a signal to CPU that CPU need to read the key that being press.
  -  Each computer design has its own interrupt mechanism, but several functions are common

The form of interrupt-driven I/O  is fine for moving small amounts of data but can produce high overhead when used for bulk data movement such as NVS I/O. To solve this problem, `direct memory access (DMA)` is used. 
- After setting up buffers, pointers, and counters for the I/O device, the device controller transfers an entire block of data directly to or from the device and main memory, with no intervention by the CPU. 
- Only one interrupt is generated per block, to tell the device driver that the operation has completed, rather than the one interrupt per byte generated for low-speed devices. 
- While the device controller is performing these operations, the CPU is available to accomplish other work.

**DEFINITIONS OF COMPUTER SYSTEM COMPONENTS**
- `CPU` — The hardware that executes instructions.
- `Processor` — A physical chip that contains one or more CPUs.
- `Core` — The basic computation unit of the CPU.
- `Multicore` — Including multiple computing cores on the same CPU.
- `Multiprocessor` — Including multiple processors.

![NUMA multiprocessing architecture.](./Assets/image_2.png)

![General structure of a clustered system](./Assets/image_3.png)

Operating-System Operations

Powered up or rebooted -> bootstrap program run -> the bootstrap program must locate the operating-system kernel and load it into memory -> the kernel is loaded and executing -> Some services are provided outside of the kernel by system programs that are loaded into memory at boot time to become `system daemons`, which run the entire time the kernel is running. -> the system is fully booted, and the system waits for some event to occur.


`System call` - is a mechanism that allows a user program to request a service from the operating system. ~  system call may generate a special kind of interrupt to switch from user mode to kernel mode

In a multiprogramming system, a program in execution is termed a process.
Multitasking is a logical extension of multiprogramming. In multitasking systems, the CPU executes multiple processes by switching among them, but the switches occur frequently, providing the user with a fast response time.

The operating system keeps several processes in memory simultaneously
![memory management](./Assets/image_4.png)

In addition, if several processes are ready to run at the same time, the system must choose which process will run next. Making this decision is `CPU scheduling`

In order to ensure the proper execution of the system, we must be able to distinguish between the execution of operating-system code and user-defined code
- user mode
- kernel mode (also called supervisor mode, system mode, or privileged mode)

A bit, called the `mode bit`, is added to the hardware of the computer to indicate the current mode: kernel (0) or user (1)

![Transition from user to kernel mode](./Assets/image_5.png)

There can be more than 2 modes:
- Intel processors have four separate protection rings
- ARMv8 systems have seven modes
- CPUs that support virtualization frequently have a separate mode to indicate when the virtual machine manager (VMM) is in control of the system.

The operating system is responsible for the following activities in connection with process management:
- Creating and deleting both user and system processes
- Scheduling processes and threads on the CPUs
- Suspending and resuming processes
- Providing mechanisms for process synchronization
- Providing mechanisms for process communication

The operating system is responsible for the following activities in connection with memory management:
- Keeping track of which parts of memory are currently being used and which process is using them
- Allocating and de-allocating memory space as needed
- Deciding which processes (or parts of processes) and data to move into and out of memory

The operating system is responsible for the following activities in connection with file management:
- Creating and deleting files
- Creating and deleting directories to organize files
- Supporting primitives for manipulating files and directories
- Mapping files onto mass storage
- Backing up files on stable (nonvolatile) storage media

The operating system is responsible for the following activities in connection with secondary storage management:
- Mounting and unmounting
- Free-space management
- Storage allocation
- Disk scheduling
- Partitioning
- Protection

Cache management

Information, As it is used, it is copied into a faster storage system, from disk to memory to cache. 
- Then when the information change, it must update back from cache -> memory -> disk.

In a computing environment where only one process executes at a time, this arrangement poses no difficulties, 
-  However, in a multitasking environment, where the CPU is switched back and forth among various processes, extreme care must be taken to ensure that, if several processes wish to access A, then each of these processes will obtain the most recently updated value of A.
-  The situation becomes more complicated in a multiprocessor environment where, in addition to maintaining internal registers, each of the CPUs also contains a local cache. In such an environment, a copy of A may exist simultaneously in several caches.
   -  Cache Coherency
-  In a distributed environment, the situation becomes even more complex. In this environment, several copies (or replicas) of the same file can be kept on different computers


The I/O subsystem consists of several components:
- A memory-management component that includes buffering, caching, and
spooling
- A general device-driver interface
- Drivers for specific hardware devices

A device driver is a specialized software program that allows the operating system (OS) and applications to interact with hardware devices, such as printers, graphics cards, storage devices, network interfaces, and more.
- `driverquery` list all driver on Windows


`Protection`, then, is any mechanism for controlling the access of processes
or users to the resources defined by a computer system.

It is the job of `security` to defend a system from external and internal attacks. 
- Prevention of some of these attacks is considered an operating-system function on some systems, while other systems leave it to policy or additional software.

`Protection and security` require the system to be able to distinguish among all its users. Most operating systems maintain a list of user names and associated user identifiers (user IDs)
- group identifiers
- escalate privileges

Kernel Data Structures

Lists, Stacks, and Queues:
- In a singly linked list, each item points to its successor
![singly linked list](./Assets/image_8.png)

- In a doubly linked list, a given item can refer either to its predecessor orto its successor
![doubly linked list](./Assets/image_9.png)

- In a circularly linked list, the last element in the list refers to the first element, rather than to null.
![circularly linked list](./Assets/image_10.png)

A stack is a sequentially ordered data structure that uses the last in, first
out ( LIFO) principle for adding and removing items, meaning that the last item
placed onto a stack is the first item removed

A queue, in contrast, is a sequentially ordered data structure that uses the
first in, first out (FIFO) principle: items are removed from a queue in the order
in which they were inserted.

Trees:
- general tree
- binary tree
- binary search tree

Hash Functions and Maps

Bitmaps

Computing Environments
- Traditional Computing
- Mobile Computing
- Distributed Systems
- Client – Server Computing
- Peer-to-Peer Computing
- Virtualized Computing
- Cloud Computing
- Real-Time Embedded Systems

Virtualization: Virtualization is a technology that allows operating systems to run as applications within other operating systems.

- `Public cloud` —a cloud available via the Internet to anyone willing to pay
for the services
- `Private cloud` —a cloud run by a company for that company’s own use
- `Hybrid cloud` —a cloud that includes both public and private cloud
components
- Software as a service (`SaaS`)—one or more applications (such as word
processors or spreadsheets) available via the Internet
- Platform as a service (`PaaS`)—a software stack ready for application use
via the Internet (for example, a database server)
- Infrastructure as a service (`IaaS`)—servers or storage available over the
Internet (for example, storage available for making backup copies of
production data)

# Chapter 2

![Basic OS](./Assets/image_11.png)

**User-Oriented Services:**

User Interface (UI): Provides ways to interact with the system:
    - Command-Line Interface (CLI): Text-based commands.
    - Batch Interface: Commands stored in files for execution.
    - Graphical User Interface (GUI): Visual interface with windows, menus, and input devices.

Program Execution:
    - Loads programs into memory, runs them, and manages normal or abnormal termination.

I/O Operations:
    - Handles input and output through files or devices, ensuring efficient and protected operations.

File-System Manipulation:
    - Provides functions to read, write, create, delete, and manage files and directories, including permissions and support for various file systems.

Communication:
    - Facilitates data exchange between processes using shared memory or message passing, either locally or over a network.

Error Detection:
    - Identifies and manages errors in hardware, devices, or software, taking actions like process termination or error reporting to maintain consistency.

**System-Oriented Services:**

Resource Allocation:
  - Distributes CPU, memory, storage, and I/O devices among multiple users or processes for efficient operation.

Accounting:
  - Tracks resource usage for billing, system optimization, and statistical analysis.

Protection and Security:
  - Controls access to system resources and safeguards against interference or unauthorized access through authentication and security mechanisms.

System calls can be grouped roughly into six major categories: 
- Process control
- File manipulation 
- Device manipulation 
- Information maintenance
- Communications 
- Protection.

Process control
- end, abort
- load, execute
- create process, terminate process
- get process attributes, set process attributes
- wait for time
- wait event, signal event
- allocate and free memory

File management
- create file, delete file
- open, close
- read, write, reposition
- get file attributes, set file attributes

Device management
- request device, release device
- read, write, reposition
- get device attributes, set device attributes
- logically attach or detach devices

Information maintenance
- get time or date, set time or date
- get system data, set system data
- get process, file, or device attributes
- set process, file, or device attributes

Communications
- create, delete communication connection
- send, receive messages
- transfer status information
- attach or detach remote devices


Communication
- message-passing model
- shared-memory model

**Message-passing model:**
- First, processes establish the connection
  - Each process identify by host name, process name 
  - OS provide system call for this, like: `get hostid()` `get processid()` `open connection()` ` close connection()` `wait for connection()`
- The source of the communication, known as the `client`, and the receiving daemon, known as a `server`
- Exchange messages by using `read_message()` and `write_message()` system calls
- The `close_connection()` call terminates the communication.

**Shared-memory model:** 
- The processes use `shared_memory_create()` and `shared_memory_attach()` system calls to create and gain access to regions of memory owned by other processes
- Shared memory requires that two or more processes agree to remove restriction '
    - The operating system usually tries to prevent one process from accessing another process’s memory

Message passing is useful for exchanging smaller amounts of data, because no conflicts need be avoided. It is also easier to implement than is shared memory for inter-computer communication. Shared memory allows maximum speed and convenience of communication, since it can be done at memory transfer speeds when it takes place within a computer.

### System Programs

Categories:
- File management.
- Status information.
- File modification.
- Programming-language support.
- Program loading and execution.
- Communications.
- Background services.

Along with system programs, most operating systems are supplied with programs that are useful in solving common problems or performing common operations. Such application programs include Web browsers, word processors and text formatters, spreadsheets, database systems, compilers, plotting and statistical-analysis packages, and games.

### Design Goals

user goals
system goals

Mechanisms and Policies

One important principle is the separation of policy from mechanism. 
Mechanisms determine how to do something; policies determine what will be done.

For example, the timer construct is a mechanism for ensuring CPU protection, 
but deciding how long the timer is to be set for a particular user is a policy decision.

## Operating-System Structure

#### Layered Approach: 

Which the operating system is broken into a number of layers (levels). The bottom layer (layer 0) is the hardware; the highest (layer N) is the user interface.

**Advantages:**
- Simplicity of construction and debugging.

**Disadvantages:**
- Because a layer can use only lower-level layers, careful planning is necessary.
- They tend to be less efficient than other types. For instance, when a user program executes an I/O operation, it executes a system call that is trapped to the I/O layer, which calls the memory-management layer, which in turn calls the CPU-scheduling layer, which is then passed to the hardware. At each layer, the parameters may be modified, data may need to be passed, and so on. Each layer adds overhead to the system call.

#### Microkernels: 

#### Modules: 

Loadable kernel modules. Here, the kernel has a set of core components and links in additional services via modules

![Solaris loadable modules](./Assets/image_12.png)


#### Hybrid Systems

In practice, very few operating systems adopt a single, strictly defined structure. Instead, they combine different structure.

### Operating-System Debugging

![Kernighan’s Law](./Assets/image_13.png)


# Chapter 3

A `process` is the unit of work in a modern time-sharing system.

A system therefore consists of a collection of processes: 
- Operating-system processes executing system code
- User processes executing user code.

By switching the CPU between processes, the operating system can make the computer more productive.

A process:
- The program code ~ sometimes known as the `text section`
  - 
- Process `stack` ~ which contains temporary data (such as function parameters, return addresses, and local variables)
- `data section` ~  which contains global variables
- `heap` ~ which is memory that is dynamically allocated during process run time.

A program is a **passive** entity
A process is an **active** entity

- Two or more processes may be associated with the same program.
- It is also common to have a process that spawns many processes as it runs
  - Java runs the `JVM` as an ordinary process, which in turns executes the Java program Program in the Java virtual machine.

![Process in memory.](./Assets/image_14.png)

### Process State

- `New`. The process is being created.
- `Running`. Instructions are being executed.
- `Waiting`. The process is waiting for some event to occur (such as an I/O completion or reception of a signal).
- `Ready`. The process is waiting to be assigned to a processor.
- `Terminated`. The process has finished execution

These names are arbitrary, and they vary across operating systems.

![Diagram of process state.](./Assets/image_15.png)

Each process is represented in the operating system by a process control block `PCB` —also called a `task control block`. In brief, the PCB simply serves as the repository for any information that may vary from process to process. `PCB` include:

- `Process state`
- `Program counter`. The counter indicates the address of the next instruction to be executed for this process.
- `CPU registers`. The registers vary in number and type, depending on the computer architecture. All info be save to allow the process to be continued correctly afterward (After interrupt).
- `CPU-scheduling` information. This information includes a process priority, pointers to scheduling queues, and any other scheduling parameters.
- `Memory-management information`. More details [Chapter 8](#chapter_8)
- `Accounting information`. This information includes the amount of CPU
and real time used, time limits, account numbers, job or process numbers,
and so on.
- `I/O status information`. This information includes the list of I/O devices
allocated to the process, a list of open files, and so on.

![Diagram showing CPU switch from process to process.](./Assets/image_16.png)

### Threads

Most modern operating systems have extended the process concept to allow a process to have multiple threads of execution and thus to perform more than one task at a time.

More details at [Chapter 4](#chapter_4)

### Process Scheduling

![The ready queue and various I/O device queues.](./Assets/image_17.png)

As processes enter the system -> put into a `job queue` -> Load to main memory and are ready and waiting to execute `ready queue`

The list of processes waiting for a particular I/O device is called a `device queue` 

![Queueing-diagram representation of process scheduling.](./Assets/image_18.png)

- The process could issue an I/O request and then be placed in an I/O queue.
- The process could create a new child process and wait for the child’s
termination.
- The process could be removed forcibly from the CPU, as a result of an
interrupt, and be put back in the ready queue.

### Schedulers

- The `long-term scheduler`, or `job scheduler`
-  The `short-term scheduler`, or `CPU scheduler` -> Select new process for the `CPU`
-  The primary distinction between these two schedulers lies in frequency of execution 
   - The `short-term scheduler` must be fast, quick, can't wait time much to choose process, it make `CPU` less efficiency.
   - The `long-term scheduler` may need to be invoked only when a process leaves the system. Because of the longer interval between executions, it can afford to take more time to decide which process should be selected for execution.


It is important that the `long-term scheduler` make a careful selection, these are two type of process can be consider:
- An `I/O -bound process` is one that spends more of its time doing I/O than
it spends doing computations.
- A `CPU-bound process`, in contrast, generates I/O requests infrequently, using more of its time doing computations.

Some operating systems, such as time-sharing systems, may introduce an intermediate level of scheduling. The key idea behind a `medium-term scheduler` is that sometimes it can be advantageous to remove a process from memory
- This scheme is called swapping. The process is swapped out, and is later swapped in, in the memory.

![Addition of medium-term scheduling to the queueing diagram.](./Assets/image_19.png)

#### Context Switch

When an interrupt occurs, the system needs to save the current context of the process running on the CPU so that it can restore that context when its processing is done, essentially suspending the process and then resuming it.

- `state save` save the current state of the CPU, be it in kernel or user mode
- `state restore` to resume operations.
- `context switch` save the current state of the process and load the state of the next process to be executed.
  - `context` is the set of all the CPU registers, memory, and other data structures that define the state of a process. It save on the process PCB.

Context-switch times are highly dependent on hardware support.

### Process Creation

**Tree of processes: **
- The parent process creates a child process.
- Each of these new processes may in turn create other processes.

Most operating systems (including UNIX , Linux, and Windows) identify processes according to a unique process identifier (or `pid`)

The init process (which always has a pid of 1) serves as the root parent process for all user processes.

When a process creates a child process, that child process will need certain resources
- Obtain its resources directly from the operating system,
- Subset of the resources of the parent process
  - Restricting a child process to a subset is good because prevents any process from overloading the system by creating too many child processes.

When a process creates a new process, two possibilities for execution exist:
1. The parent continues to execute concurrently with its children.
2. The parent waits until some or all of its children have terminated.

There are also two address-space possibilities for the new process:
1. The child process is a duplicate of the parent process (it has the same program and data as the parent).
2. The child process has a new program loaded into it.

UNIX operating system:
- A new process is created by the `fork()` system call.
  - The new process consists of a copy of the address space of the original process

![Process creation using the fork() system call.](./Assets/image_20.png)

### Process Termination

When a process terminates, it releases all the resources it has allocated, including memory, I/O devices, and files.

The `exit()` system call is used to terminate a process.

The `wait()` system call is used to wait for a child process to terminate.

A parent may terminate the execution of one of its children for a variety of reasons, such as these:
- The child has exceeded its usage of some of the resources that it has been allocated. (To determine whether this has occurred, the parent must have a mechanism to inspect the state of its children.)
- The task assigned to the child is no longer required.
- The parent is exiting, and the operating system does not allow a child to continue if its parent terminates.

When a process terminates, its resources are deallocated by the OS.
- However, its entry in the process table must remain there until the parent calls `wait()`, because the process table contains the process’s exit status.
- A process that has terminated, but whose parent has not yet called wait() -> `zombie process` 
- A process that has terminated, parent has not called `wait()` and it terminated -> `orphans process`
-  Linux and UNIX deal with `orphans process` by assigning the `init` process as the new parent. The `init` process periodically invokes `wait()` allow releasing resources.

### Inter-process Communication

- Any process that does not share data with any other process is independent.
- Any process that shares data with other processes is a cooperating process.

There are several reasons for providing an environment that allows process cooperation:
- Information sharing. 
- Computation speedup.
- Modularity.
- Convenience.

Cooperating processes require an inter-process communication (`IPC`):
- Shared memory.
- Message passing.

![Communications models.](./Assets/image_20.png)

Shared memory suffers from cache coherency issues -> message passing become more preferred mechanism for IPC.

#### Shared-Memory Systems

- The process creating the shared-memory segment. Typically, in the address space of that process.
- Other processes that wish to communicate using this shared-memory segment must attach it to their address space
- Normally, the OS tries to prevent one process from accessing another process’s
memory -> So the processes must agree to remove this restriction.

The `producer–consumer` approach:
- Have available a buffer of items that can be filled by the producer and emptied by the consumer.
- A `producer` can produce one item while the `consumer` is consuming another item
- The `producer` and `consumer` must be synchronized, so that the `consumer` does not try to consume an item that has not yet been produced.
  - `Unbounded buffer` - no limit on the size of the buffer - the producer can always produce new items.
  - `Bounded buffer` - limited - the `consumer` must wait if the buffer is empty, and the `producer` must wait if the buffer is full.

#### Message-Passing Systems

A message-passing facility provides at least two operations:
- `send` (message) 
- `receive` (message)

For 2 process can be communicate, a `communication link` must exist between them.

Here are several methods for logically implementing a link and the `send()`/`receive()` operations:
- Direct or indirect communication
- Synchronous or asynchronous communication
- Automatic or explicit buffering

**Naming**

Under direct communication, there are 2 schemes:
- Symmetric: 2 processes must know each other identities.
- Asymmetric: Just sender need to know the recipient identities

With indirect communication:
- The messages are sent to and received from mailboxes, or ports.
  - Sender send a messages to a mailbox (owned either by a process or by the operating system)
  - The recipient receive a message from mailbox.
    - Depend on the polices of the mailbox, one or more recipient can receive the messages
  - When a process that owns a mailbox terminates, the mailbox disappears. Any process that subsequently sends a message to this mailbox must be notified that the mailbox no longer exists.

**Synchronization** Message passing may be either blocking or nonblocking—
also known as synchronous and asynchronous

- `Blocking send.` The sending process is blocked until the message is
received by the receiving process or by the mailbox.
- `Nonblocking send.` The sending process sends the message and resumes
operation.
- `Blocking receive.` The receiver blocks until a message is available.
- `Nonblocking receive.` The receiver retrieves either a valid message or a null.

**Buffering** messages exchanged by communicating processes reside in a temporary queue.

- `Zero capacity.` The queue has a maximum length of zero; thus, the link
cannot have any messages waiting in it. In this case, the sender must block
until the recipient receives the message.
- `Bounded capacity.` The queue has finite length n; and the sender can continue execution without waiting. The link’s capacity is finite, however. If the link is full, the sender must block until space is available in the queue.
- `Unbounded capacity.` The queue’s length is potentially infinite; thus, any
number of messages can wait in it. The sender never blocks.

### Examples of IPC Systems

#### POSIX Shared Memory

POSIX shared memory is organized using memory-mapped files, which associate the region of shared memory with a file.

- Create a shared-memory object using the `shm_open()` system call
- Once the object is established, the `ftruncate()` function is used to configure the size of the object in bytes.
- Finally, the `mmap()` function establishes a memory-mapped file containing the shared-memory object. -> returns a pointer to the memory-mapped file that is used for accessing the shared-memory object.

#### Mach

#### Windows

Windows provides support for multiple operating environments, or `subsystems`
- The application programs can be considered `clients` of a subsystem `server`.

The message-passing facility in Windows is called the advanced local procedure call (`ALPC`)

Windows uses two types of ports: 
- Connection ports
- Communication ports.

When an `ALPC` channel is created, one of three message-passing techniques is chosen:
- For small messages (up to 256 bytes), the port’s message queue is used as intermediate storage, and the messages are copied from one process to the other.
- Larger messages must be passed through a section object, which is a region of shared memory associated with the channel.
- When the amount of data is too large to fit into a section object, an API is available that allows server processes to read and write directly into the address space of a client.

![Advanced local procedure calls in Windows.](/Assets/image_22.png)

### Communication in Client–Server Systems

The client–server communication: sockets, remote procedure calls (RPCs), and pipes. These are similar technic with shared memory and message passing

#### Sockets

1. **Definition**:
   - A socket is an endpoint for communication in a network, identified by an IP address and port number.

2. **Client-Server Architecture**:
   - The **server** listens on a specific port, waiting for client requests.
   - The **client** initiates a connection using an arbitrary port (greater than 1024).

3. **Well-Known Ports**:
   - Ports below 1024 are reserved for standard services:
     - Telnet: Port 23
     - FTP: Port 21
     - HTTP: Port 80

4. **Connection Example**:
   - A client at IP `146.86.5.20` with port `1625` connects to a web server at IP `161.25.19.8` on port `80`.
   - The connection is defined by the unique socket pair: `(146.86.5.20:1625)` and `(161.25.19.8:80)`.

5. **Unique Connections**:
   - Each connection must have a unique socket pair.
   - If another client process connects to the same server, it will use a different port number (greater than 1024) to ensure uniqueness.

### Remote Procedure Call (RPC)

1. **Definition**:
   - RPC abstracts the procedure-call mechanism for use between systems over a network.
   - Built on message-based communication, enabling processes on separate systems to interact.

2. **Structure**:
   - RPC messages are well-structured, containing:
     - An identifier specifying the function to execute.
     - Parameters for the function.
   - Addressed to an RPC daemon listening on a specific port.

3. **Ports**:
   - Systems use ports to differentiate network services.
   - Example: A server providing a list of current users may attach this RPC service to port 3027.

4. **Stubs and Parameter Marshalling**:
   - **Stub**:
     - A client-side stub hides communication details, locates the server port, and packages parameters.
     - The server-side stub receives the message, unmarshals the data, and invokes the procedure.
   - **Parameter Marshalling**:
     - Converts machine-dependent data into a machine-independent representation (e.g., XDR) for transmission.

5. **Data Representation**:
   - Differences in data representation (e.g., big-endian vs. little-endian) are resolved using a machine-independent format like XDR.

6. **Reliability**:
   - **"At Most Once" Semantics**:
     - Ensures duplicate messages are ignored using timestamps.
   - **"Exactly Once" Semantics**:
     - Uses acknowledgments (ACKs) to confirm message receipt and execution, resending calls if needed.

7. **Binding**:
   - Binding between client and server may occur at link, load, or execution time to establish communication.

# Chapter 4 - Threads

![Single-threaded and multithreaded processes.](./Assets/image_23.png)

**Benefits:**
- **Responsiveness:** Multithreading an interactive application may allow a program to continue running even if part of it is blocked or is performing a lengthy operation, thereby increasing responsiveness to the user.
- **Resource sharing:** threads share the memory and the resources of the process to which they belong by default. The benefit of sharing code and data is that it allows an application to have several different threads of activity within the same address space
- **Economy:** Allocating memory and resources for `process` creation is costly. The threads share the resources of the process to which they belong, it is more economical to create and context-switch threads.
- **Scalability:** The threads may be running in parallel on different processing cores. A single-threaded process can run on only one processor, regardless how many are available. 

![Single-threaded and multithreaded processes.](./Assets/image_24.png)

### **AMDAHL’S LAW**

Amdahl's Law is a principle in computer science that quantifies the performance improvement in a system when parts of it are optimized, particularly in parallel computing. It demonstrates how the speedup of a program using multiple processors is limited by the portion of the program that cannot be parallelized.

**Formula:**
\[
S = \frac{1}{(1 - P) + \frac{P}{N}}
\]

**Where:**
- **S**: The overall speedup of the program.
- **P**: The proportion of the program that can be parallelized.
- **(1 - P)**: The proportion of the program that is sequential (cannot be parallelized).
- **N**: The number of processors or parallel units.

**Key Insights:**
1. **Sequential Limitation**: No matter how many processors are added, the speedup is constrained by the sequential portion of the program.
2. **Diminishing Returns**: As **N** (the number of processors) increases, the incremental speedup decreases due to the dominance of the sequential portion.

**Practical Implications:**
- `Amdahl's Law` emphasizes minimizing the sequential part of a program to maximize performance gains in parallel computing.
- It highlights that even with infinite processors, the maximum speedup is \(\frac{1}{1-P}\).

**Example:**
If 70% (\(P = 0.7\)) of a program can be parallelized, and there are 4 processors (\(N = 4\)):

\[
S = \frac{1}{(1 - 0.7) + \frac{0.7}{4}} = \frac{1}{0.3 + 0.175} = 2.5
\]

The speedup is 2.5 times the original performance.

**Conclusion:**
`Amdahl's Law` is critical for understanding the scalability limits of parallel processing systems and underscores the importance of reducing the sequential components of a program to achieve better performance.


#### Parallelism and concurrency 

- A system is parallel if it can perform more than one task simultaneously.
- A concurrent system supports more than one task by allowing all
the tasks to make progress

**Types of Parallelism:**
- Data parallelism
- Task parallelism

#### User and kernel level thread 
- User threads: Supported above the kernel and are managed without kernel support
- Kernel threads: Supported and managed directly by the operating system.

Ref: https://stackoverflow.com/questions/10386815/stdthreads-are-managed-in-user-or-kernel-space


A user level thread's scheduling is maintained by the user himself (via the interface provided by a library) and the kernel ends up allotting just a single kernel thread to the whole process. Kernel would treat the process as a single threaded and any blocking call by one of the threads would end up blocking all the threads of that process. Refer to http://www.personal.kent.edu/~rmuhamma/OpSystems/Myos/threads.htm

**Multithreading Models:**
- Many-to-One Model
- One-to-One Model
- Many-to-Many Model

### Thread Libraries

**Popular:**
- POSIX Pthreads
- Windows
- Java

**Note:**
- For POSIX and Windows threading, any data declared globally -> shared among all threads belonging to the same process. 
- Because Java has no notion of global data, access to shared data must be explicitly arranged between threads. Data declared local to a function are typically stored on the stack. Since each thread has its own stack, each thread has its own copy of local data.

**Asynchronous threading and synchronous threading:**

- With `asynchronous threading`, once the parent creates a child thread, the parent resumes its execution, so that the parent and child execute concurrently. Each thread runs independently of every other thread, and the parent thread need not know when its child terminates. Because the threads are independent, there is typically little data sharing between threads.

- `Synchronous threading` occurs when the parent thread creates one or more children and then must wait for all of its children to terminate before it resumes the so-called `fork`-`join` strategy. Here, the threads created by the parent perform work concurrently, but the parent cannot continue until this work has been completed. Once each thread has finished its work, it terminates and joins with its parent. Only after all of the children have joined can the parent resume execution. Typically, synchronous threading involves significant data sharing among threads. 

#### Pthreads

Provided as either a user-level or a kernel-level library. 


#### Windows 32 API

Windows thread library is a kernel-level library

#### Java Threads

### Implicit Threading 

Transfer the creation and management of threading from application developers to compilers and run-time libraries.

#### Thread Pools

- Create a number of threads at process startup and place them into a pool.
- Thread wait for work.
- When a server receives a request, it awakens a thread from this pool
  - If one is available -> passes it the request for service.
  - Once the thread completes its service, it returns to the pool and awaits more work.

Thread pools offer these benefits:
1. Servicing a request with an existing thread is faster than waiting to create a thread.
2. A thread pool limits the number of threads that exist at any one point.
  - This is particularly important on systems that cannot support a large number of concurrent threads.
3. Separating the task to be performed from the mechanics of creating the task allows us to use different strategies for running the task.

#### OpenMP

OpenMP is a set of compiler directives as well as an API for programs written in C, C++, or FORTRAN that provides support for parallel programming in shared-memory environments.

Open MP identifies parallel regions as blocks of code that may run in parallel.

Application developers insert compiler directives into their code at parallel regions, and these directives instruct the OpenMP run-time library to execute the region in parallel.

#### Grand Central Dispatch

Just like OpenMP, but Apple develop for IOS and MacOS

[Example](./Code/Chapter_4/Example/omp.c)

#### Other Approaches
- Intel threading block
- Other java API
- Other Windows API

### Threading Issues

`fork()` and `exec()`

- `fork()` can have 2 mode 
    - Duplicate all process
    - Only duplicate the process that call `fork()`
- `exec()` also have 2 mode
    - Replace all thread
    - Replace the thread that call `exec()`, other thread will not be replace

**Signal handing:**

Signal handling pattern:
- A Signal is generated by the occurrence of paiticular event.
- The signal is delivered to a process
- Once delivered, the signal must be handled.

A signal may be handle by one of two possible handle:
- A default signal handler
- A user-defined signal handler

Options to deliver signal:
- Deliver the signal to the thread that signal apply
- Deliver the signal to all thread in the process
- Deliver the signal to certain thread in the process
- Assign the specific thread that handle the signal

Windows does not explicitly provide support for signals, it allows us to emulate them using `asynchronous procedure calls (APC s)`

#### Thread canceling

- Asynchronous cancellation: One thread immediately terminates the target thread
- Deferred cancellation: The target thread periodically checks whether it should terminate, allow it have opportunity to terminates itself in an orderly way.


The difficulty with cancellation occurs in situations where resources have been allocated to a canceled thread or where a thread is canceled while in the midst of updating data it is sharing with other threads.
  - In some case, canceling a thread asynchronously may not free a necessary system-wide resource.


Pthreads supports three cancellation modes.

| Mode         | State    | Type         |
| ------------ | -------- | ------------ |
| Off          | Disabled | –            |
| Deferred     | Enabled  | Deferred     |
| Asynchronous | Enabled  | Asynchronous |

`Pthreads` allows threads to `disable` or `enable` cancellation
  - A thread cannot be canceled if cancellation is disabled.
  - The default cancellation type is deferred cancellation. Here, cancellation occurs only when a thread reaches a `cancellation point`.

#### Thread-Local Storage

`thread-local storage ` The thread's own copy of certain data.

#### Scheduler Activations

![Lightweight process (LWP).](./Assets/image_25.png)

To the `user-thread` library, the LWP appears to be a virtual processor on which the application can schedule a user thread to run. Each LWP is attached to a kernel thread, and it is kernel threads that the operating system schedules to run on physical processors.

One scheme for communication between the user-thread library and the kernel is known as `scheduler activation`. It manage the schedule for user threads onto an available virtual processor. This communication procedure is known as an `upcall`. `Upcalls` are handled by the thread library with an `upcall handler`.

### Operating-System Examples

#### Windows Threads

The general components of a thread include:
- A thread ID uniquely identifying the thread
- A register set representing the status of the processor
- A user stack, employed when the thread is running in user mode, and a kernel stack, employed when the thread is running in kernel mode.
- A private storage area used by various run-time libraries and dynamic link libraries (DLLs).

![Data structures of a Windows thread.](./Assets/image_26.png)

#### Linux Threads

Linux does not distinguish between `processes` and `threads`. In fact, Linux uses the term task rather than `process` or `thread`.

Linux also provides the ability to create threads using the `clone()` system call.

When `clone()` is invoked, it is passed a set of flags that determine how much sharing is to take place between the `parent` and `child` tasks.

![The flags passed when clone() is invoked](./Assets/image_27.png)

If none of these flags is set when `clone()` is invoked, no sharing takes place, resulting in functionality similar to that provided by the `fork()` system call.

- When `fork()` is invoked, a new task is created, along with a copy of all the associated data structures of the parent process.

- When `clone()` is invoked,  rather than copying all data structures, the new task **points** to the data structures of the parent task, depending on the set of flags passed to `clone()`

# Chapter 5

Process Synchronization: Discuss various mechanisms to ensure the orderly execution of cooperating processes that share a logical address space, so that data consistency is maintained

A `cooperating process` is one that can affect or be affected by other processes executing in the system.

`Race condition` ~ several processes access and manipulate the same data concurrently

## The Critical-Section Problem

The `Critical section` ~ when one process is executing in its critical section, no other process is allowed to execute in its critical section.

![Critical section](./Assets/image_28.png)

It have:
- `Entry section` ~ request permission to enter its critical section.
- `Exit section` ~ Notify the process leave the critical section
- `Remainder section` ~ The remaining code. 

A solution to the critical-section problem must satisfy the following three requirements:
1. **Mutual exclusion.** If process `Pi` is executing in its critical section, then no other processes can be executing in their critical sections.
2. **Progress.** If no process is executing in its critical section and some processes wish to enter their critical sections, then only those processes that are not executing in their remainder sections can participate in deciding which will enter its critical section next, and this selection cannot be postponed indefinitely.
3. **Bounded waiting.** There exists a bound, or limit, on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted.

Two general approaches are used to handle critical sections in operating systems: 
- `Preemptive kernels`: A preemptive kernel allows a process to be preempted while it is running in kernel mode.
- `Non-preemptive kernels`: A non preemptive kernel does not allow a process running in kernel mode to be preempted; a kernel-mode process will run until it exits kernel mode, blocks, or voluntarily yields control of the CPU.
  - A non preemptive kernel is essentially free from race conditions on kernel data structures, as only one process is active in the kernel at a time.

## Peterson’s Solution

A classic software-based solution to the critical-section problem.
  - Peterson’s are not guaranteed to work on modern computer architectures.

![Peterson's solution](./Assets/image_29.png)

Peterson’s solution requires the two processes to share two data items:
- `int turn;` ~ The variable turn indicates whose turn it is to enter its critical section.
- `boolean flag[2];` ~ The `flag` array is used to indicate if a process is ready to enter its critical section.

[Code Example](./Code/Chapter_5/5.8/main.c)

With the code, the condition `while (flag[j] && turn == j);` make sure only one thread that execute critical section at the same time. `turn` only be `i` or `j`, can't be both.

## Synchronization Hardware

`Locking` that is, protecting critical regions through the use of locks

### Mutex Locks

A `mutex lock` has a boolean variable available whose value indicates if the lock is available or not.

One process or thread `release()` then the other process `acquire()`

![Mutex locks](./Assets/image_30.png)

The main disadvantage of the implementation given here is that it requires `busy waiting` 
  - It mean While a process is in its critical section, any other process that tries to enter its critical section must loop continuously in the call to `acquire()` ~ `spinlock`

### Semaphores

A semaphore `S` is an integer variable that, apart from initialization, is accessed only through two standard atomic operations: `wait()` and `signal()`.

```c
wait(S) {
  while (S <= 0)
  ; // busy wait
  S--;
}
```

```c
signal(S) {
  S++;
}
```

#### Semaphore Usage

- `Counting semaphore` ~  range over an unrestricted domain.

- `Binary semaphore` ~ range only between 0 and 1 ~ similarly to mutex locks

Counting semaphores can be used to control access to a given resource consisting of a finite number of instances.
  - When a process releases a resource -> `signal()` ~ incrementing the count.
  - When the count for the semaphore goes to `0`, all resources are being used.
  - Other process will block until the count becomes greater than `0` again.

We can make process execute in order with the process that need to execute first call `signal()`, the second process call `wait()`

#### Semaphore Implementation

To avoid **busy waiting**, When a process executes the `wait()` operation and finds that the `semaphore` value is not positivethe process can block itself.
  - The `block` operation places a process into a waiting queue associated with the semaphore, and the state of the process is switched to the `waiting` state
  - The process is restarted by a `wakeup()` operation, which changes the process from the `waiting` state to the `ready` state.
```c
typedef struct {
  int value;
  struct process *list;
} semaphore;
```

```c
wait(semaphore *S) {
  S->value--;
  if (S->value < 0) {
    add this process to S->list;
    block();
  }
}
```

```c
signal(semaphore *S) {
  S->value++;
  if (S->value <= 0) {
    remove a process P from S->list;
    wakeup(P);
  }
}
```

The list of waiting processes can be easily implemented by a link field in each `process control block (PCB)`

It is critical that semaphore operations be executed atomically
  - Can't `wait()` and `signal()` operations on the same semaphore at the same time. 

#### Deadlocks and Starvation

`deadlocked` ~ two or more processes are waiting indefinitely for an event that can be caused only by one of the waiting processes

`starvation` or `indefinite blocking` ~ processes wait indefinitely within the semaphore. Indefinite blocking may occur if we remove processes from the list associated with a semaphore in LIFO (last-in, first-out) order.

#### Priority Inversion

`Priority Inversion` problem is indirectly, a process with a lower priority has affected how long process with higher priority have to wait for resource.

Typically these systems solve the problem by implementing a `priority-inheritance protocol`
  - All processes that are accessing resources
needed by a higher-priority process inherit the higher priority until they are finished with the resources in question.
  - When they are finished, their priorities
revert to their original values.

## Classic Problems of Synchronization

### The Bounded-Buffer Problem

Ref: https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem

The Bounded-Buffer Problem is a classical synchronization problem that arises in systems where multiple processes share a fixed-size buffer, typically for producer-consumer scenarios. It is also known as the Producer-Consumer Problem.

- **Buffer Overflow:** A producer must not add data to the buffer if it is already full.
- **Buffer Underflow:** A consumer must not remove data from the buffer if it is empty.
- **Race Conditions:** Simultaneous access to the buffer by producers and consumers must be synchronized to avoid inconsistencies (e.g., overwriting or corrupting data).

### The Readers – Writers Problem

We require that the writers have exclusive access to the shared database while writing to the database.

- No reader be kept waiting unless a writer has already obtained
permission to use the shared object. In other words, no reader should wait for other readers to finish simply because a writer is waiting.
- Once a writer is ready, that writer perform its write as soon as possible. In other words, if a writer is waiting to access the object, no new readers may start reading.

### The Dining-Philosophers Problem

Ref: https://en.wikipedia.org/wiki/Dining_philosophers_problem

Monitors are a high-level synchronization construct.

The monitor construct ensures that only one process at a time is active within the monitor.

## Monitors

An abstract data type

![A monitor to allocate a single resource.](./Assets/image_31.png)

**Key Features of Monitors**

1. **Encapsulation**:
   - A monitor encapsulates shared variables, data structures, and methods to manipulate them.
   - Only the monitor's methods can access the shared variables, ensuring controlled access.

2. **Mutual Exclusion**:
   - At most, one thread can execute a monitor method at any time. This prevents race conditions.

3. **Condition Variables**:
   - Monitors use condition variables to allow threads to wait or signal each other about specific conditions.
   - Condition variables are associated with two operations:
     - **Wait**: A thread waits for a condition to be true.
     - **Signal**: A thread notifies one or more waiting threads that a condition is now true.

**How Monitors Work**
1. **Thread Entry**:
   - Only one thread can execute a monitor's method at a time. If another thread tries to enter while the monitor is occupied, it is blocked until the monitor becomes available.
   
2. **Condition Variables**:
   - Threads inside a monitor can release the monitor temporarily and wait for a condition using the `wait()` operation.
   - Other threads can signal the waiting threads when the condition becomes true, using the `signal()` operation.

3. **Synchronization**:
   - Monitors use an implicit lock (or mutex) to ensure mutual exclusion.
   - Condition variables allow threads to synchronize by waiting for and signaling changes in shared resource states.

## Synchronization Examples

**Windows:**

For kernel:
- On a single-processor system,  it temporarily masks interrupts for all interrupt handlers that may also access the global resource.
- On a multiprocessor system, Windows protects access to global resources
using spinlocks. The kernel ensures that a thread will never be preempted while holding a spinlock.

For hread synchronization outside the kernel
- Dispatcher objects.
- A critical-section object 


**Solaris:**
- An adaptive mutex
- turnstile

**P_thread:**
- `pthread_mutex_t`
- `#include <semaphore.h>` -> `sem_t sem;`


## Alternative Approaches

**Transactional Memory:**

Ref: https://stackoverflow.com/questions/11255640/what-is-transactional-memory

Transactional memory instead lets you designate sections of code as transactions. The transactional memory system (which can be implemented in hardware, software, or both) then attempts to give you the guarantee that any run of a program in which multiple threads execute transactions in parallel will be equivalent to a different run of the program in which the transactions all executed one after another, never at the same time.

**OpenMP:**

[OpenMP critical section protection](image.png)

Still identify possible race conditions and adequately protect shared data using the this.

**Functional Programming Languages:**
- The fundamental difference between imperative and functional languages is that functional languages do not maintain state. That is, once a variable has been defined and assigned a value, its value is `immutable`, it cannot change. Because functional languages disallow mutable state, they need not be concerned with issues such as race conditions and deadlocks

Ref - Erlang: https://www.erlang.org/doc/system/conc_prog.html

# Chapter 6

## Basic Concepts

### CPU– I/O Burst Cycle

The process execution consists of a cycle of CPU execution and I/O wait.

CPU burst <--> I/O burst.

- An I/O-bound program typically has many short CPU bursts. 
- A CPU-bound program might have a few long CPU bursts. 

This distribution can be important in the selection of an appropriate CPU-scheduling algorithm

### CPU Schedule

Short-term Scheduler

### Preemptive Scheduling

CPU-scheduling decisions may take place under the following four circumstances
1. When a process switches from the `running` state to the `waiting` state (for example, as the result of an I/O request or an invocation of wait() for the termination of a child process)
2. When a process switches from the `running` state to the `ready` state (for example, when an interrupt occurs)
3. When a process switches from the `waiting` state to the `ready` state (for example, at completion of I/O)
4. When a process terminates

`1` and `4` A new process (if one exists in the ready queue) always be selected for execution ~ `nonpreemptive`

However, in `2` and `3`, we can scheduling ~ `preemptive` ->  `race conditions`

### Dispatcher

A component in the CPU-scheduling function. It in charge:
- Switching context
- Switching to user mode
- Jumping to the proper location in the user program to restart that program

The time it takes for the dispatcher to stop one process and start another running is known as the `dispatch latency`

## Scheduling Criteria

To comparing CPU-scheduling algorithms. We have some important criteria:
- `CPU utilization`. We want to keep the CPU as busy as possible. Conceptually, CPU utilization can range from 0 to 100 percent. In a real system, it should range from 40 percent (for a lightly loaded system) to 90 percent (for a heavily loaded system).
- `Throughput`. If the CPU is busy executing processes, then work is being done. One measure of work is the number of processes that are completed per time unit, called throughput. For long processes, this rate may be one process per hour; for short transactions, it may be ten processes per second.
- `Turnaround time`. From the point of view of a particular process, the important criterion is how long it takes to execute that process. The interval from the time of submission of a process to the time of completion is the turnaround time. Turnaround time is the sum of the periods spent waiting to get into memory, waiting in the ready queue, executing on the CPU, and doing I/O.
- `Waiting time`. The CPU-scheduling algorithm does not affect the amount of time during which a process executes or does I/O. It affects only the amount of time that a process spends waiting in the ready queue. Waiting time is the sum of the periods spent waiting in the ready queue.
- `Response time`. In an interactive system, turnaround time may not be the best criterion. Often, a process can produce some output fairly early and can continue computing new results while previous results are being output to the user. Thus, another measure is the time from the submission of a request until the first response is produced. This measure, called response time, is the time it takes to start responding, not the time it takes to output the response. The turnaround time is generally limited by the speed of the output device

## Scheduling Algorithms

**First-Come, First-Served Scheduling**

- The average waiting time under the `FCFS` policy is often quite long.
- One more problem for `FCFS` is we have CPU-bound process and I/O-bound processes:
  - CPU-bound process will get and hold the CPU.
  - I/O-bound process will have to wait for CPU and the I/O devices are idle.

**Shortest-Job-First Scheduling**

When the CPU is available, it is assigned to the process that has the smallest next CPU burst. If the next CPU bursts of two processes are the same, `FCFS` scheduling is used to break the tie.

**Priority Scheduling**

The CPU is allocated to the process with the highest priority. Equal-priority processes are scheduled in `FCFS` order.

A major problem with priority scheduling algorithms is `indefinite blocking`, or `starvation`.

**Round-Robin Scheduling**

It is similar to FCFS scheduling, but preemption is added to enable the system to switch between processes

**Multilevel Queue Scheduling** 

A multilevel queue scheduling algorithm partitions the ready queue into several separate queues. Each queue has **absolute** priority over lower-priority queues.

![Multilevel queue scheduling.](./Assets/image_33.png)

**Multilevel Feedback Queue Scheduling**

Like `Multilevel Queue Scheduling` but allows a process to move between queues.

In general, a multilevel feedback queue scheduler is defined by the
following parameters:
- The number of queues
- The scheduling algorithm for each queue
- The method used to determine when to upgrade a process to a higher-priority queue
- The method used to determine when to demote a process to a lower-priority queue
- The method used to determine which queue a process will enter when that process needs service

## Thread Scheduling

**Contention Scope**
- Process-contention scope (`PCS`)
  - The thread library schedules user-level threads to run on an available `LWP`.
  - `PCS` is done according to priority—the scheduler selects the runnable thread with the highest priority to run.
- System-contention scope (`SCS`)

**Pthread Scheduling**

The POSIX Pthread API allows specifying PCS or SCS during thread creation
- `PTHREAD_SCOPE_PROCESS` schedules threads using PCS scheduling.
- `PTHREAD_SCOPE_SYSTEM` schedules threads using SCS scheduling.

## Multiple-Processor Scheduling

**Approaches to Multiple-Processor Scheduling**

We can use a single processor ~ the master server to scheduling decisions, I/O processing, and other system activities
  - This `asymmetric multiprocessing` is simple because only one processor accesses the system data structures, reducing the need for data sharing.

A second approach uses `symmetric multiprocessing` (`SMP`) ~ where each
processor is self-scheduling

**Processor Affinity**

Because of the high cost of **invalidating** and **repopulating caches**, most `SMP` systems try to avoid migration of processes from one processor to another and instead attempt to keep a process running on the same processor. This is known as `processor affinity`

Processor affinity takes several forms:
- `soft affinity` ~ not guaranteeing to keep a process running on the same processor
- `hard affinity` ~ allowing a process to specify a subset of processors on which it may run.

**Load Balancing**

On `SMP` systems, it is important to keep the workload balanced among all processors to fully utilize the benefits of having more than one processor.

There are two general approaches to load balancing: 
- `push migration` ~ a specific task periodically checks the load on each processor and push processes from overloaded to idle or less-busy
processors
- `pull migration` ~ when an idle processor pulls a waiting task
from a busy processor

**Multicore Processors**

Multicore processor: multiple processor cores on the same physical chip.

`memory stall` when a processor accesses memory, it spends a significant amount of time waiting for the data to become available.

Many recent hardware designs have implemented multithreaded processor cores in which two (or more) hardware threads are assigned to each core
- That way, if one thread stalls while waiting for memory, the core can switch to another thread.

In general, there are two ways to multithread a processing core: 
- Coarse-grained: a thread executes on a processor until a long-latency event such as a `memory stall` occur.
- Fine-grained multithreading: switches between threads at a much finer level of granularity, typically at the boundary of an instruction cycle.

## Real-Time CPU Scheduling

CPU scheduling for real-time operating systems
- `Soft real-time systems`
  - No guarantee as to when a critical real-time process will be scheduled.
  - Guarantee only that the process will be given preference over noncritical processes.
- `Hard real-time systems` ~ stricter requirements
  - A task must be serviced by its deadline;
  - Service after the deadline has expired is the same as no service at all.

**Minimizing Latency**

Two types of latencies affect the performance of real-time systems:
1. Interrupt latency ~ the period of time that services the changing interrupt
2. Dispatch latency ~ The amount of time required for the scheduling dispatcher to stop one process and start another
   1. The most effective technique for keeping dispatch latency low is to provide preemptive kernels.

![Interrupt latency.](./Assets/image_34.png)
![Dispatch latency.](./Assets/image_35.png)

**Priority-Based Scheduling**

The scheduler for a real-time operating system must support a priority-based algorithm with preemption. Because it require CPU respond immediately when real-time process need CPU.

Some characteristics of the processes need to know:
- `periodic` ~ They require the CPU at constant intervals (periods).
- `rate` ~ The rate of a periodic task.

**Rate-Monotonic Scheduling**

A scheduling algorithm schedules periodic tasks using a static priority policy with preemption

**Earliest-Deadline-First Scheduling**
Scheduling dynamically assigns priorities according to deadline. 
- The earlier the deadline, the higher the priority.
- The later the deadline, the lower the priority.

**Proportional Share Scheduling**

Proportional share schedulers operate by allocating T shares among all applications. An application can receive N shares of time, thus ensuring that the application will have `N/T` of the total processor time

- A is assigned 50 shares ~ A will have 50 percent of total processor time
- B is assigned 15 shares ~ B will have 15 percent
- C is assigned 20 shares ~ C will have 20 percent


**POSIX Real-Time Scheduling**

The POSIX standard provides extensions for real-time computing
- `SCHED_FIFO` ~ schedules threads according to a first-come, first-served policy
- `SCHED_RR` ~ Round-robin policy

[Example](./Code/Chapter_6/posixScheduleTest.c)

## Operating-System Examples

### Linux

[Example](./Code/Chapter_6/posixRealTimeSche.c)

Scheduling in the Linux system is based on **scheduling classes**. 
- Each class is assigned a specific priority. 
- By using different scheduling classes, the kernel can accommodate different scheduling algorithms based on the needs of the system and its processes.

### Windows

Windows schedules threads using a **priority-based**, preemptive scheduling algorithm. The Windows scheduler ensures that the highest-priority thread will always run

The **dispatcher** is handle scheduling 

A thread selected to run by the dispatcher will run:
- Until it is preempted by a higher-priority thread.
- Until it terminates, until its time quantum ends.
- Until it calls a blocking system call, such as for I/O.

The dispatcher uses a `32-level` priority scheme to determine the order of thread execution. Priorities are divided into two classes. 
- The **variable class** contains threads having priorities from 1 to 15
- The **real-time class** contains threads with priorities ranging from 16 to 31.
- A thread running at priority 0 that is used for memory management

The dispatcher uses a queue for each scheduling priority and traverses the set of queues from highest to lowest until it finds a thread that is ready to run. 
- If no ready thread is found, the dispatcher will execute a special thread called the **idle thread**.

The Windows API identifies the following six priority classes and their equivalent priorities:

- IDLE PRIORITY CLASS - IDLE, LOWEST
- BELOW NORMAL PRIORITY CLASS - BELOW NORMAL
- NORMAL PRIORITY CLASS - NORMAL
- ABOVE NORMAL PRIORITY CLASS - ABOVE NORMAL
- HIGH PRIORITY CLASS - HIGHEST
- REALTIME PRIORITY CLASS - TIME CRITICAL

Windows 7 introduced `user-mode scheduling (UMS)`, which allows applications to create and manage threads independently of the kernel
- We can use `Concurrency Runtime ( ConcRT )`, a concurrent programming framework for C++ that is designed for task-based parallelism

### Solaris

Solaris uses priority-based thread scheduling. Each thread belongs to one of six classes:
1. Time sharing (TS)
2. Interactive (IA)
3. Real time ( RT )
4. System (SYS)
5. Fair share (FSS)
6. Fixed priority (FP)

## Algorithm Evaluation

How we select a CPU-scheduling algorithm for a particular system.

### Deterministic Modeling

**Analytic evaluation** uses the given algorithm and the system workload to produce a formula or number to evaluate the performance of the algorithm for that workload.

**Deterministic modeling** is one type of analytic evaluation. 
- This method takes a particular predetermined workload and defines the performance of each algorithm for that workload.

### Queueing Models

The computer system is described as a network of servers. Each server has
a queue of waiting processes. The CPU is a server with its ready queue, as is the I/O system with its device queues. Knowing arrival rates and service rates, we can compute utilization, average queue length, average wait time, and so on. This area of study is called queueing-network analysis.

### Simulation

![Simulation](./Assets/image_36.png)

Simulations can be expensive. A more detailed simulation provides more accurate results, but it also takes more computer time. 

### Implementation

The only completely accurate way to evaluate a scheduling algorithm is to code it up, put it in the operating system, and see how it works. This approach puts the actual algorithm in the real system for evaluation under real operating conditions.

# Chapter 7 Deadlocks

Perhaps the best illustration of a deadlock can be drawn from a law passed by the Kansas legislature early in the 20th century. It said, in part: “When two trains approach each other at a crossing, both shall come to a full stop and neither shall start up again until the other has gone.”

## System model
A system consists of a finite number of resources to be distributed among a number of competing processes.
- CPU cycles, files, and I/O devices (such as printers and DVD drives) are examples of resource types.
- Each resource types consisting of some number of identical instances. If a system has two CPUs, then the resource type CPU has two instances.

## Deadlock Characterization

A deadlock situation can arise if the following four conditions hold simultaneously in a system:
1. **Mutual exclusion**. At least one resource must be held in a nonsharable mode; that is, only one process at a time can use the resource. If another process requests that resource, the requesting process must be delayed until the resource has been released.
2. **Hold and wait**. A process must be holding at least one resource and waiting to acquire additional resources that are currently being held by other processes.
3. **No preemption**. Resources cannot be preempted; that is, a resource can be released only voluntarily by the process holding it, after that process has completed its task.
4. **Circular wait.** A set {P0 , P1 , ..., Pn} of waiting processes must exist such that P0 is waiting for a resource held by P1 , P1 is waiting for a resource held by P2 , ..., Pn−1 is waiting for a resource held by Pn, and Pn is waiting for a resource held by P0 .

**Graph**

P = {P1 , P2 , ..., Pn}, the set consisting of all the active processes in the system, and R = {R1 , R2 , ..., Rm}, the set consisting of all resource types in the system.
Dots represent a instant of the resource type.

The arrow indicate the relationship between process and resource:
- Process hell instant of resource (R -> P)
- Process waiting for instant of resource (P -> R)

![Graph](./Assets/image_37.png)

Generally speaking, we can deal with the deadlock problem in one of three ways:
- We can use a protocol to prevent or avoid deadlocks, ensuring that the system will never enter a deadlocked state.
- We can allow the system to enter a deadlocked state, detect it, and recover.
- We can ignore the problem altogether and pretend that deadlocks never occur in the system.

## Deadlock prevention

Scenerio:
- **Mutex Exclusion**
  - Provide share resource but mutex lock cannot be simultlaneously shared by several process
- **Hold and wait**
  - Whenever a process requests a resource, it does not hold any other resources
    - One protocol that we can use requires each process to request and be allocated all its resources before it begins execution
    - An alternative protocol allows a process to request resources only when it has none.
- **No premetive**
  - If a process is holding some resources and requests another resource that cannot be immediately allocated to it (that is, the process must wait), then all resources the process is currently holding are preempted. In other words, these resources are implicitly released. 
- **Circular wait**
  - Impose a total ordering of all resource types and to require that each process requests resources in an increasing order of enumeration.

## Deadlock prevention

### **Safe state**: 

A state is safe if the system can allocate resources to each process (up to its maximum) in some order and still avoid a deadlock
- A safe sequence is an order in which processes can execute safely, meaning each process can get the resources it needs and complete.
- If a process doesn’t immediately get what it needs, it can wait until other processes finish and release resources.
- If there is no safe sequence, the system is unsafe, meaning a deadlock might happen (but not always).

**Example:**`

Imagine three processes (P1, P2, P3) and some available resources.

- P1 needs 3 more units but has 2.
- P2 needs 2 more but has 1.
- P3 needs 1 more but has 1.

If the system has only 1 available unit, we can complete P3 first since it only needs 1.

- P3 finishes, releases its resources → System has more resources.
- Now P2 can get what it needs, finish, and release resources.
- Finally, P1 gets what it needs and completes.

Since we found a way to complete all processes, the system is in a **safe state**. But if no such order exists, it’s unsafe and could lead to deadlock

### **Resource-Allocation-Graph Algorithm**:

We use graph to visualize the relationship between process and resources.
- A claim edge Pi → Rj indicates that process Pi may request resource Rj at some time in the future.

![Claim edge](./Assets/image_38.png)

We check for safety by using a cycle-detection algorithm. An algorithm for detecting a cycle in this graph requires an order of n^2 operations, where n is the number of processes in the system.
- If no cycle exists, then the allocation of the resource in a safe state.
- If a cycle is found, then the allocation will put the system in an unsafe state.

The resource-allocation-graph algorithm is not applicable to a resource allocation system with multiple instances of each resource type

### **Banker's Algorithm**:

When a new process enters the system, it must declare the maximum number of instances of each resource type that it may need.

This number may not exceed the total number of resources in the system. When a user requests a set of resources, the system must determine whether the allocation of these resources will leave the system in a safe state.
- If it will, the resources are allocated; otherwise, the process must wait until some other process releases enough resources.


**Data structures for the banker’s algorithm.**
- **Available**. A vector of length m indicates the number of available resources of each type. If Available[j] equals k, then k instances of resource type Rj are available.
- **Max**. An `n × m` matrix defines the maximum demand of each process. If `Max[i][j]` equals k, then process Pi may request at most k instances of resource type Rj.
- **Allocation**. An `n × m` matrix defines the number of resources of each type currently allocated to each process. If Allocation[i][j] equals k, then process `Pi` is currently allocated k instances of resource type Rj.
- **Need.** An `n × m` matrix indicates the remaining resource need of each process. If `Need[i][j]` equals `k`, then process Pi may need k more instances of resource type Rj to complete its task. Note that `Need[i][j]` equals `Max[i][j]` − `Allocation[i][j]`.

#### Safety algorithm

The algorithm for finding out whether or not a system is in a safe state. 
- Let `Work` and `Finish` be vectors of length m and n, respectively. Initialize `Work` = `Available` and `Finish[i]` = *false* for i = 0, 1, ..., n − 1.
- Find an index i such that both
  - `Finish[i]` == *false*
  - `Need[i]` ≤ `Work`
  - If no such i exists, go to step 4.
3. `Work` = `Work` + `Allocation[i]`
  - `Finish[i]` = true
  - Go to step 2.
4. If `Finish[i]` == **true** for all i, then the system is in a safe state.

#### Resource-Request Algorithm

The **Resource-Request Algorithm** determines whether a request for resources can be safely granted. It follows these steps:

1. **Check Maximum Claim:**  
   - If `Request[i] ≤ Need[i]`, proceed to step 2.  
   - Otherwise, raise an error because the process exceeds its maximum claim.

2. **Check Availability:**  
   - If `Request[i] ≤ Available`, proceed to step 3.  
   - Otherwise, process `Pi` must wait since resources are unavailable.

3. **Simulate Allocation:**  
   - Temporarily allocate resources by updating:  
     ```
     Available = Available - Requesti
     Allocationi = Allocationi + Requesti
     Needi = Needi - Requesti
     ```
   - Check if the new resource allocation state is **safe**:
     - If **safe**, grant the request and complete the transaction.  
     - If **unsafe**, process `Pi` must wait, and the previous state is restored.

## Deadlock detection.

**Single Instance of Each Resource Type**:
A deadlock exists in this system if and only if the graph contains a cycle. To detect deadlocks, the system needs to maintain the graph and periodically invoke an algorithm that searches for a cycle in the graph.


**Several Instances of a Resource Type**:
- Let `Work` and `Finish` be vectors of length m and n, respectively. Initialize `Work` = `Available`. For i = 0, 1, ..., n–1, if `Allocation[i]` != 0, then `Finish[i]` = *false*. Otherwise, `Finish[i]` = *true*.
- Find an index i such that both
  - Finish[i] == false
  - Request[i] ≤ Work
  - If no such i exists, go to step 4.
- Work = Work + Allocation[i]
  - Finish[i] = true
  - Go to step 2.
- If `Finish[i]` == false for some i, 0 ≤ i < n, then the system is in a deadlocked state. Moreover, if `Finish[i]` == *false*, then process Pi is deadlocked.

### **Detection-Algorithm Usage**:
When should we invoke the detection algorithm? The answer depends on two factors:
1. How often is a deadlock likely to occur?
2. How many processes will be affected by deadlock when it happens?

## Recovery from deadlock

**Process Termination**:
- Abort all deadlocked processes.
- Abort one process at a time until the deadlock cycle is eliminated.

**Resource Preemption**: we preempt some resources from processes and give these resources to other processes until the deadlock cycle is broken.

There are three issues need to be addressed before the preemption:
- **Select the victim**: We need to choose process that minimize the cost.
- **Roll back**: When we preempt the resource, process cannot continue with its normal execution; it is missing some needed resource.
  - We must roll back the process to some safe state and restart it from that state.
- **Starvation**: May happen that the same process is always picked as a victim (Follow on cost factor for exam), so the process will never complete the task.
  - So we picked as a victim only a (small) finite number of times. The most common solution is to include the number of rollbacks in the cost factor.

# Chapter 8

## Main memory

Any instructions in execution, and any data being used by the instructions, must be in one of these direct-access storage devices. If the data are not in memory, they must be moved there before the CPU can operate on them.

Most CPUs can decode instructions and perform simple operations on register contents at the rate of **one** or more operations per clock tick. 

The same cannot be said of main memory, which is accessed via a transaction on the memory bus.
  - In such cases, the processor normally needs to **stall** (The CPU pauses execution until the data is available)

We also must ensure correct operation:
- Protect OS from access of user process.
- From another user on the same system

One example for possible the protection's implement: Consider each process has a separate memory space
- We can provide protection by using two registers, usually a `base` and a `limit`.

![Base and limit register](./Assets/image_39.png)

Protection of memory space is accomplished by having the CPU hardware compare every address generated in user mode with the registers.
- If it not in range, treat as fatal error.
- Since only the OS executes in kernel mode, only the operating system can load the `base` and `limit` registers.

### Address binding.

Addresses may be represented in different ways during these steps. Addresses in the source program are generally symbolic (such as the variable count). 

A compiler typically binds these symbolic addresses to relocatable addresses (such as “14 bytes from the beginning of this module”). The linkage editor or loader in turn binds the relocatable addresses to absolute addresses (such as 74014). 

Each **binding** is a mapping from one address space to another. The binding of instructions and data to memory addresses can be done at any step along the way:

![Steps maybe invoke binding](/Assets/image_42.png)

### Logical Versus Physical Address Space

- An address generated by the CPU is commonly referred to as a `logical address` or `virtual address`
- Whereas an address seen by the memory unit that is, the one loaded into the memory-address register of the memory ~ `physical address.`

![Logical and physical memory](./Assets/image_40.png)

The run-time mapping from virtual to physical addresses is done by hardware device called the `memory-management unit (MMU)`.

One simple mapping method: The base register is now called a `relocation register`. The value in the `relocation register` is added to every address generated by a user process at the time the address is sent to memory (Picture above). (14000 + 346)

### Dynamic loading

The process need to be in physical memory before execute -> Limit the size of process to be load is the capable of memory -> For better memory-space utilization, we can use **dynamic loading**.

With dynamic loading, a routine is not loaded until it is called.
- All routines are kept on disk in a relocatable load format. 
- The main program is loaded into memory and is executed. 
- When a routine needs to call another routine
  - The calling routine first checks to see whether the other routine has been loaded. 
  - If it has not, the relocatable linking loader is called to load the desired routine into memory and to update the program’s address tables to reflect this change.
  - Then control is passed to the newly loaded routine.

-> So only part of program being load when it needed.

Dynamic loading does not require special support from the operating system. It is the responsibility of the users to design their programs to take advantage of such a method.

### Dynamic Linking and Shared Libraries.

Dynamically linked libraries are system libraries that are linked to user programs when the programs are run.

With dynamic linking, a `stub` is included in the image for each library routine reference. The `stub` is a small piece of code that indicates how to locate the appropriate memory-resident library routine or how to load the library if the routine is not already present.

## Swapping

A process must be in memory to be executed. A process, however, can be **swapped** temporarily out of memory to a backing store and then brought back into memory for continued execution.

**Standard Swapping**:

The system maintains a `ready queue` consisting of all processes whose memory images are on the backing store or in memory and are ready to run.

![Swapping](./Assets/image_43.png)

- Swapping more memory take more time.
- If we want to swap a process, we must be sure that it is completely idle.
  - Assume P1 is wait for I/O and we swap in process P2, the I/O operation might then attempt to use memory that now belongs to process P2.
  - Never swap a process with pending I/O.
  - Execute I/O operations only into operating-system buffers.

**Standard swapping is not used in modern operating systems.** -> Modified versions of swapping, however, are found on many systems, including UNIX , Linux, and Windows.
  - **Swapping** is normally disabled but will start if the amount of free memory falls below a threshold amount.

**Swapping on mobile system**:
**IOS:** Instead of using swapping, when free memory falls below a certain threshold -> IOS asks applications to voluntarily relinquish allocated memory. 
  - Read-only data (such as code) are removed from the system and later reloaded from flash memory if necessary. 
  - Data that have been modified (such as the stack) are never removed. 
  - However, any applications that fail to free up sufficient memory may be terminated by the operating system.

**Android** does not support swapping and adopts a strategy similar to that used by IOS. 
  - It may terminate a process if insufficient free memory is available.
  - However, before terminating a process, Android writes its application state to flash memory so that it can be quickly restarted.


## Contiguous memory allocation
The memory is usually divided into two partitions: 
 - One for the resident  operating system
 - One for the user processes.

In contiguous memory allocation, each process is contained in a single section of memory that is contiguous to the section containing the next process.

**Memory protection for contiguous memory allocation**
We using a **relocation register** together with a **limit register**

![Relocation register](./Assets/image_44.png)

Some code and data is not commonly used, so it can load and reload from memory as needed -> Such code is sometimes called **transient** operating-system code -> It change the size of OS during execution.

### **Memory allocation**:

One simple way to allocate the memory is divide into several fixed-sized partitions 
  - Each partition contain one process.
  - Process in waiting queue will be load into free partition.
  - When process execution done, partition become free again.

Another way is **variable-partition** scheme:
- The operating system keeps a table indicating which parts of memory are available and which is occupied.
- Large block of available memory is call a **hole**
- Memory contains a set of holes of variours sizes.

How it work:
- Memory allocated process until the memory required for the next process cannot be satisfied.
- It can wait until have a hole large enough to hold a process.
- Or it can skip down to smaller process to fit available hole.
- If a hole is too large, it can split into two parts. One for process. One return to the set of holes.

This procedure is a particular instance of the general **Dynamic storage-allocation problem**

The first-fit, best-fit, and worst-fit strategies are the ones most commonly used to select a free hole from the set of available holes.
- First-fit: Allocate the first hole that is big enough.
- Best-fit: Allocate the smallest hole that is big enough.
- Worst-fit: Allocate the largest hole. 

**Fragment**: Memory allocation suffer from external fragmentation, External fragmentation exists when there is enough total memory space to satisfy a request but the available spaces are not contiguous: storage is fragmented into a large number of small holes.

- One solution is **compaction**. The goal is to shuffle the memory contents so as to place all free memory together in one large block.
- Another possible solution is to permit the logical address space of the processes to be noncontiguous, thus allowing a process to be allocated physical memory wherever such memory is available.

## Segmentation

Segmentation is a memory-management scheme that supports programmer view of memory. A logical address space is a collection of segments.
- The process is represent as one logical address space

![Segment](/Assets/image_46.png)

A logical address consists of two parts:
- A segment number, s, and an offset into that segment, d.
- The segment number is used as an index to the segment table.
- The offset d of the logical address must be between 0 and the segment limit. 
- If it is not, we trap to the operating system (logical addressing attempt beyond end of segment).
- When an offset is legal, it is added to the segment base to produce the address in physical memory of the desired byte. 
- The segment table is thus essentially an array of base–limit register pairs.

Segmentation permits the physical address space of a process to be non-contiguous.

## Paging

Another schema for memory-managemet. The basic method for implementing paging involves breaking physical memory into fixed-sized blocks called **frames** and breaking logical memory into blocks of the same size called **pages**

![Paging](./Assets/image_47.png)

Every address generated by the CPU is divided into two parts: 
- A page number (p) - The page number is used as an index into a page table
- A page offset (d)

![Frames](./Assets/image_48.png)

The page size (like the frame size) is defined by the hardware.

On a Linux system, the page size varies according to architecture, and there are several ways of obtaining the page size. 
- One approach is to use the getpagesize() system call. 
- Another strategy is command line: `getconf PAGESIZE`

Every logical address is bound by the paging hardware to some physical address. Using paging is similar to using a table of base (or relocation) registers, one for each frame of memory.

**Protection**

![Bit protection](./Assets/image_54.png)


**Page sharing**  

An advantage of paging is the possibility of sharing common code.

Example: If we have 8 users, all run the same editor, we not need 8 instance of code in the memory

## Structure of page table 

**Hierarchical Paging**

The page table itself can becomes excessively large. ->  One way is to use a two-level paging algorithm, in which the page table itself is also paged.

![Hierarchical page](./Assets/image_50.png)

**Hashed Page Tables**

A common approach for handling address spaces larger than 32 bits is to use a hashed page table

The virtual page number in the virtual address is hashed into the hash table. 

The virtual page number is compared with field 1 in the first element in the linked list. 
- If there is a match, the corresponding page frame (field 2) is used to form the desired physical address.
- If there is no match, subsequent entries in the linked list are searched for a matching virtual page number. 

![Hash page table](./Assets/image_51.png)

**Inverted Page Tables**

![Inverted page table](./Assets/image_49.png)

**Oracle SPARC Solaris**

There are two hash tables—one for the kernel and one for all user processes. Each maps memory addresses from virtual to physical memory. Each hash-table entry represents a contiguous area of mapped virtual memory, which is more efficient than having a separate hash-table entry for each page. Each entry has a base address and a span indicating the number of pages the entry represents

## Example

# Chapter 9

Virtual memory is a technique that allows the execution of processes that are not completely in memory

**Background**:
- Some part of programs almost never exectued. Like error handling or certain options
- Arrays, lists, and tables are often allocated more memory than they actually need.

Even in those cases where the entire program is needed, it may not all be needed at the same time.

The ability to execute a program that is only partially in memory would confer many benefits

Virtual memory involves the separation of logical memory as perceived by users from physical memory. This separation allows an extremely large virtual memory to be provided for programmers when only a smaller physical memory is available

![Virtual address space](./Assets/image_52.png)

## Demand paging 

With demand-paged virtual memory, pages are loaded only when they are demanded during program execution. Pages that are never accessed are thus never loaded into physical memory.

Rather than swapping the entire process into memory, though, we use a lazy swapper. A lazy swapper never swaps a page into memory unless that page will be needed. 

We call this swapper for page is **pager** for more technical correction.

**How?**

When a process is to be swapped in, the pager guesses which pages will be used before the process is swapped out again.
  - Instead of swapping in a whole process, the pager brings only those pages into memory.

![Page fault](./Assets/image_53.png)

1. We check an internal table (usually kept with the process control block) for this process to determine whether the reference was a valid or an invalid memory access.
2. If the reference was invalid, we terminate the process. If it was valid but we have not yet brought in that page, we now page it in.
3. We find a free frame (by taking one from the free-frame list, for example).
4. We schedule a disk operation to read the desired page into the newly allocated frame.
5. When the disk read is complete, we modify the internal table kept with the process and the page table to indicate that the page is now in memory.
6. We restart the instruction that was interrupted by the trap. The process can now access the page as though it had always been in memory.

**Pure demand paging**: Never bring a page into memory until it is require

The hardware to support demand paging is the same as the hardware for paging and swapping:
- **Page table.** This table has the ability to mark an entry invalid through a valid–invalid bit or a special value of protection bits.
- **Secondary memory.** This memory holds those pages that are not present in main memory. The secondary memory is usually a high-speed disk. It is known as the swap device, and the section of disk used for this purpose is known as swap space.

A crucial requirement for demand paging is the ability to restart any instruction after a page fault. We must be able to restart the process in exactly the same place and state, except that the desired page is now in memory and is accessible

**Performance**:

The page fault causes the following sequence to occur:
1. Trap to the operating system.
2. Save the user registers and process state.
3. Determine that the interrupt was a page fault.
4. Check that the page reference was legal and determine the location of the page on the disk.
5. Issue a read from the disk to a free frame:
    - Wait in a queue for this device until the read request is serviced.
    - Wait for the device seek and/or latency time.
    - Begin the transfer of the page to a free frame.
6. While waiting, allocate the CPU to some other user ( CPU scheduling, optional).
7. Receive an interrupt from the disk I/O subsystem (I/O completed).
8. Save the registers and process state for the other user (if step 6 is executed).
9. Determine that the interrupt was from the disk.
10. Correct the page table and other tables to show that the desired page is now in memory.
11. Wait for the CPU to be allocated to this process again.

## Copy on write

With `fork()`, child process being created by duplicate the parent process, for paging, copy whole paging of the parent process is not necessary.

Instead, we can use a technique known as **copy-on-write**, which works by allowing the parent and child processes initially to share the same pages. These shared pages are marked as copy-on-write pages, meaning that if either process writes to a shared page, a copy of the shared page is created.

![Copy on write](./Assets/image_55.png)

Several versions of UNIX (including Solaris and Linux) provide a variation of the `fork()` system call `vfork()` ~ virtual memory fork - Differnet with `fork()` on copy-on-write

With `vfork()`:
- Parent process is suspended
- Child process use address space of the parent
  - Any change make by child process will be reflect when the parent process resume
  - Use with caution.
- Because no copying of pages takes place, `vfork()` is an extremely efficient method of process creation

## Page replacement

Page Replacement in an operating system is the process of selecting which memory pages to swap out (remove) from RAM when a new page needs to be loaded but there is no free space available. It occurs in virtual memory systems where processes use more memory than physically available RAM, requiring pages to be swapped between RAM and disk.

Why is Page Replacement Needed?
- When a process requests a page that is not currently in RAM (a page fault occurs), the OS must load that page from disk.
- If RAM is full, the OS must decide which page to remove to make room for the new page.
- The goal is to minimize page faults and optimize system performance.

Key Performance Metrics
- Page Fault Rate: The lower, the better.
- Execution Time: Efficient algorithms minimize swapping delays.
- Overhead: The algorithm should not require excessive bookkeeping.

We must solve two major problems to implement demand paging:
- A frame-allocation algorithm 
- A page-replacement algorithm

How we can choose best page-replacement algorithm?

We evaluate an algorithm by running it on a particular string of memory references and computing the number of page faults. The string of memory references is called a reference string.

### Basic page replacement

If no frame is free, we find one that is not currently being used and free it.

We can use the `modify bit` to determines whether we need to write the page back to disk before removing it.

- If the modify bit is set (page is dirty)
  - The page has changed since it was loaded from disk.
  - Before replacing it, we must write it back to disk so that the changes are not lost
- If the modify bit is NOT set (page is clean)
  - The page in RAM is the same as the version on disk.
  - We can simply discard it and load a new page without writing it back, saving disk I/O.

**Belady’s anomaly:** for some page-replacement algorithms, the page-fault rate may increase as the number of allocated frames increases (Increase RAM)
#### FIFO

- FIFO (First-In-First-Out)
  - The oldest page in memory is replaced.
  - Simple but inefficient, as old pages might still be useful 

![FIFO](./Assets/image_56.png)

#### Optimal Page Replacement (OPT)
  - Replaces the page that will not be used for the longest time in the future.
  - Ideal but impractical, as future memory access patterns are unknown 

#### LRU (Least Recently Used)
  - The page that has not been used for the longest time is replaced.
  - More efficient than FIFO but requires tracking page usage 

**Counters**: In the simplest case, we associate with each page-table entry a time-of-use field and add to the CPU a logical clock or counter.
  - The clock is incremented for every memory reference.

**Stack**: Approach to implementing LRU replacement is to keep a stack of page numbers. 
- Whenever a page is referenced, it is removed from the stack and put on the top.
  - The most recently used page is always at the top of the stack
  - The least recently used page is always at the bottom

LRU-Approximation Page Replacement:
