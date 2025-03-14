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
      - [Counting-Based Page Replacement](#counting-based-page-replacement)
      - [Page-Buffering Algorithms](#page-buffering-algorithms)
      - [Applications and Page Replacement](#applications-and-page-replacement)
  - [Allocation of Frames](#allocation-of-frames)
  - [Thrashing](#thrashing)
  - [Memory-mapped file](#memory-mapped-file)
  - [Allocating kernel memory](#allocating-kernel-memory)

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

**There can be more than 2 modes:**
- Intel processors have four separate protection rings
- ARMv8 systems have seven modes
- CPUs that support virtualization frequently have a separate mode to indicate when the virtual machine manager (VMM) is in control of the system.

**The operating system is responsible for the following activities in connection with process management:**
- Creating and deleting both user and system processes
- Scheduling processes and threads on the CPUs
- Suspending and resuming processes
- Providing mechanisms for process synchronization
- Providing mechanisms for process communication

**The operating system is responsible for the following activities in connection with memory management:**
- Keeping track of which parts of memory are currently being used and which process is using them
- Allocating and de-allocating memory space as needed
- Deciding which processes (or parts of processes) and data to move into and out of memory

**The operating system is responsible for the following activities in connection with file management:**
- Creating and deleting files
- Creating and deleting directories to organize files
- Supporting primitives for manipulating files and directories
- Mapping files onto mass storage
- Backing up files on stable (nonvolatile) storage media

**The operating system is responsible for the following activities in connection with secondary storage management:**
- Mounting and unmounting
- Free-space management
- Storage allocation
- Disk scheduling
- Partitioning
- Protection

**Cache management**

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

A **device driver** is a specialized software program that allows the operating system (OS) and applications to interact with hardware devices, such as printers, graphics cards, storage devices, network interfaces, and more.
- `driverquery` list all driver on Windows


`Protection`, then, is any mechanism for controlling the access of processes
or users to the resources defined by a computer system.

It is the job of `security` to defend a system from external and internal attacks. 
- Prevention of some of these attacks is considered an operating-system function on some systems, while other systems leave it to policy or additional software.

`Protection and security` require the system to be able to distinguish among all its users. Most operating systems maintain a list of user names and associated user identifiers (user IDs)
- group identifiers
- escalate privileges

### Kernel Data Structures

- Lists:
  - In a singly linked list, each item points to its successor
  ![singly linked list](./Assets/image_8.png)

  - In a doubly linked list, a given item can refer either to its predecessor orto its successor
  ![doubly linked list](./Assets/image_9.png)

  - In a circularly linked list, the last element in the list refers to the first element, rather than to null.
  ![circularly linked list](./Assets/image_10.png)

- A stack is a sequentially ordered data structure that uses the last in, first out ( LIFO) principle for adding and removing items, meaning that the last item placed onto a stack is the first item removed

- A queue, in contrast, is a sequentially ordered data structure that uses the first in, first out (FIFO) principle: items are removed from a queue in the order in which they were inserted.

- Trees:
  - general tree
  - binary tree
  - binary search tree

- Hash Functions and Maps
- Bitmaps

### **Computing Environments**
- Traditional Computing
- Mobile Computing
- Distributed Systems
- Client – Server Computing
- Peer-to-Peer Computing
- Virtualized Computing
- Cloud Computing
- Real-Time Embedded Systems

**Virtualization:** Virtualization is a technology that allows operating systems to run as applications within other operating systems.

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
- User Interface (UI): Provides ways to interact with the system:
    - Command-Line Interface (CLI): Text-based commands.
    - Batch Interface: Commands stored in files for execution.
    - Graphical User Interface (GUI): Visual interface with windows, menus, and input devices.

- Program Execution:
    - Loads programs into memory, runs them, and manages normal or abnormal termination.

- I/O Operations:
    - Handles input and output through files or devices, ensuring efficient and protected operations.

- File-System Manipulation:
    - Provides functions to read, write, create, delete, and manage files and directories, including permissions and support for various file systems.

- Communication:
    - Facilitates data exchange between processes using shared memory or message passing, either locally or over a network.

- Error Detection:
    - Identifies and manages errors in hardware, devices, or software, taking actions like process termination or error reporting to maintain consistency.

**System-Oriented Services:**

Resource Allocation:
  - Distributes CPU, memory, storage, and I/O devices among multiple users or processes for efficient operation.

Accounting:
  - Tracks resource usage for billing, system optimization, and statistical analysis.

Protection and Security:
  - Controls access to system resources and safeguards against interference or unauthorized access through authentication and security mechanisms.

**System calls can be grouped roughly into six major categories:**
- Process control
- File manipulation 
- Device manipulation 
- Information maintenance
- Communications 
- Protection.

**Process control**
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
- user goals
- system goals

**Mechanisms and Policies:**

One important principle is the separation of policy from mechanism. 
- Mechanisms determine how to do something; policies determine what will be done.

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

**A process:**
- The program code ~ sometimes known as the `text section`
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
- An `I/O -bound process` is one that spends more of its time doing I/O than it spends doing computations.
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

**Tree of processes:**
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
- Normally, the OS tries to prevent one process from accessing another process’s memory -> So the processes must agree to remove this restriction in order to acess.

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

#### MacOS

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

**LRU-Approximation Page Replacement:**

Some system approach LRU with much simple solution (reduce the cost of complex structure)
- *Referent bit*: The referent bit for a page is set by the hardware whenever that page is referenced.
- Use referent bit is basic approach so we do not know the orders os use.

Some approach using LRU-Approximation:
- **Additional-Reference-Bits Algorithm:** We use more bit, up to 8-bit
  - The operating system shifts the reference bit for each page into the high-order bit of its 8-bit byte
  - The page with the lowest number is the LRU page, and it can be replaced.
  - If many page are equal, we use FIFO to choose among them.
- **Second-Chance Algorithm:** When a page has been selected, however, we inspect its reference bit.
  - If the value is 0, we proceed to replace this page
  - But if the reference bit is set to 1, we give the page a second chance and move on to select the next FIFO page. 
  - When a page gets a second chance, its reference bit is cleared, and its arrival time is reset to the current time -> Thus, a page that is given a second chance will not be replaced until all other pages have been replaced.
- **Enhanced second-chance**: We use **modify bit** + **referent bit**
  - `(0, 0)` neither recently used nor modified—best page to replace
  - `(0, 1)` not recently used but modified—not quite as good, because the page will need to be written out before replacement
  - `(1, 0)` recently used but clean—probably will be used again soon
  - `(1, 1)` recently used and modified—probably will be used again soon, and the page will be need to be written out to disk before it can be replaced

#### Counting-Based Page Replacement
#### Page-Buffering Algorithms
#### Applications and Page Replacement

## Allocation of Frames

We can keep a counter of the number of references that have been made to each page and develop the following two schemes.
- The least frequently used (LFU)
- The most frequently used (MFU)

## Thrashing

If process doesn't have enough frames it needs to support pages in active use, it will quickly page-fault. 

However, since all its pages are in active use, it must replace a page that will be needed again right away. Consequently, it quickly faults again, and again, and again, replacing pages that it must bring back in immediately

This high paging activity is called thrashing. A process is thrashing if it is spending more time paging than executing

## Memory-mapped file

When request for I/O acessing on file. We can use the virtual memory techniques to treat file I/O as routine memory accesses. This approach, known as memory mapping a file, allows a part of the virtual address space to be logically associated with the file. 

**How?**

1. We mapping disk block to a page in the memory. The inital access will result in page fault.
2. A page-sized portion of the file is read from the file system into a physical page 
3. Subsequent reads and writes to the file are handled as routine memory accesses
    - The file on disk maybe not change until OS decide to write back from memory to the disk.

Some OS provide memory mapping only through a specific system call and use the standard system calls to perform all other file I/O.

Multiple processes may be allowed to map the same file concurrently, to allow sharing of data. 


![File mapping](./Assets/image_57.png)

Multiple processes may be allowed to map the same file concurrently, to allow sharing of data. 
- Any change from process maybe seen from other process
- Or memory-mapping systems call can also support copy-on-write function, it make a copy of file when the process want to change it.

### Sharing memory in Windows API

- To establish a memory-mapped file, a process first opens the file to be mapped with the `CreateFile()` function -> Return HANDLE
- The process then creates a mapping of this file HANDLE using the `CreateFileMapping()` function
  - Create a **named shared-memory object** call **SharedObject**
- Once the file mapping is established, the process then establishes a view of the mapped file in its virtual address space with the `MapViewOfFile()` function.
- The consumer will be able to using this share-memory by create a mapping to the same named object.
- Finally, both processes remove the view of the mapped file with a call to **UnmapViewOfFile()**

### Memory mapping I/O

To allow more convenient access to I/O devices, many computer architectures provide **memory-mapped I/O**.
- In this case, ranges of memory addresses are set aside and are mapped to the device registers.
- Read and write will transfer that data to and from the device register.

## Allocating kernel memory

Allocation for kernel memory is quite diffent from allocation for user process.There are two primary reasons for this:
1. The kernel requests memory for data structures of varying sizes, some of which are less than a page in size. As a result, the kernel must use memory conservatively and attempt to minimize waste due to fragmentation. 
    - This is especially important because many operating systems do not subject kernel code or data to the paging system.
2. Pages allocated to user-mode processes do not necessarily have to be in contiguous physical memory. However, certain hardware devices interact directly with physical memory without the benefit of a virtual memory interface and consequently may require memory residing in physically contiguous pages.

**Buddy system**:

![Buddy system](./Assets/image_58.png)

Buddy system divide the memory until the smallest memory fit the memory that be requested. **power-of-2 allocator**

The obvious drawback to the buddy system is that rounding up to the next highest power of 2 is very likely to cause fragmentation within allocated segments

**Slab allocation**:

A **slab** is made up of one or more physically contiguous pages. 
- A cache consists of one or more slabs.
- There is a single cache for each unique kernel data structure
- Each cache is populated with objects that are instantiations of the kernel data structure the cache represents

![Slab](./Assets/image_59.png)

In Linux, a slab may be in one of three possible states:
1. Full. All objects in the slab are marked as used.
2. Empty. All objects in the slab are marked as free.
3. Partial. The slab consists of both used and free objects.

## Other considerations.

**Pre-paging**:

When the process started -> the large number of page fault will occurs.

Prepaging is an attempt to prevent this high level of initial paging. The strategy is to bring into memory at one time all the pages that will be needed.

**Page size**: What is the best page-size for the system, each system can apply many page-size, how to choose?

**TLB Reach**: The TLB reach refers to the amount of memory accessible from the TLB and is simply the number of entries multiplied by the page size.

**Inverted page tables**:

**Program structure**:

Careful selection of data structures and programming structures can increase locality and hence lower the page-fault rate and the number of pages in the working set. 

```c
int i, j;
int[128][128] data;
for (j = 0; j < 128; j++)
  for (i = 0; i < 128; i++)
    data[i][j] = 0;
```
This code above have 128 × 128 = 16,384 page faults.

```C
int i, j;
int[128][128] data;
for (i = 0; i < 128; i++)
  for (j = 0; j < 128; j++)
    data[i][j] = 0;
```
While this code only have 128 page faults.

**I/O Interlock and Page Locking**:
When demand paging is used, we sometimes need to allow some of the pages to be **locked** in memory

Scenerio:
- A process issues an I/O request -> put in a queue 
- The CPU is given to other processes
- Page fault -> New page replace the old page of waiting process

There are two common solution for this:
- One solution is never to execute I/O to user memory. Instead, data are always copied between system memory and user memory.
  - To write a block on tape, we first copy the block to system memory and then write it to tape. 
  - This extra copying may result in unacceptably high overhead.
- Another solution is to allow pages to be locked into memory. Here, a lock bit is associated with every frame. If the frame is locked, it cannot be selected for replacement
  - Note that this feature could be abused and could cause stress on the memory-management algorithms. 
  - Therefore, an application frequently requires special privileges to make such a request.

![I/O and buffer](./Assets/image_60.png)

## Example 

### Windows 

Windows implements virtual memory using demand paging with clustering.
- Clustering handles page faults by bringing in not only the faulting page but also several pages following the faulting page.

When process is first created: It assigned:
- **Working-set minimum**: minimum number of pages the process is guaranteed to have in memory
- **Working-set maximum**

When the amount of free memory falls below the threshold, the virtual
memory manager perform **automatic working-set trimming** to restore the value above the threshold.
- It Trim (removes) pages until the process reaches its working-set minimum.

## Solaris

- When a thread incurs a page fault, Solaris assigns a page from a free list maintained by the kernel.
- The **lotsfree** parameter (1/64 of physical memory) determines when paging should start.
- Every 250 milliseconds (4 times per second), the kernel checks if free memory falls below **lotsfree.** If so, the pageout process begins.
- The pageout process uses a two-handed clock algorithm:
  - **Front hand** sets reference bits to 0 as it scans pages.
  - **Back hand** checks reference bits; if still 0, the page is freed and written to disk if modified.
- Solaris maintains:
  - A cache list of recently freed pages (available for reuse if accessed soon).
  - A free list of pages with invalid contents.
- The scanrate (pages scanned per second) varies based on free memory:
  - Starts at **slowscan** (default: 100 pages/sec).
  - Increases towards fastscan as memory pressure rises.
  - **Fastscan** is set to (total physical pages)/2 pages per second, with a maximum of 8,192 pages/sec.
  - The handspread parameter determines the distance between the two hands of the clock algorithm. 
  - The time delay between clearing and checking a reference bit depends on scanrate and handspread:

    - Example: If scanrate = 100 pages/sec and handspread = 1,024, the delay is 10 seconds.
    - However, due to high memory demand, scanrates of several thousand pages/sec are common, reducing the delay to just a few seconds.

- The pageout process normally runs 4 times per second but increases to 100 times per second if free memory drops below desfree.
-  If desfree is not maintained for 30 seconds, the kernel starts swapping processes to free memory, prioritizing idle processes.
-  If free memory falls below minfree, the pageout process is triggered for every page request.
- Recent Solaris optimizations:
  - Shared library pages used by multiple processes are skipped during scanning, preventing unnecessary pageouts.
  - Priority paging (Chap 12.6.2)

# Chapter 10

We mainly use 2 type of disk:
- Magnetic Disks
- Solid-State Disks

**Magnetic Disks**

A read–write head “flies” just above each surface of every platter. The heads are attached to a **disk arm** that moves all the heads as a unit. 

![HDD](./Assets/image_61.png)

The **positioning time**, or **random-access time**, consists of two parts:
- The time necessary to move the disk arm to the desired cylinder, called the **seek time**
- The time necessary for the desired sector to rotate to the disk head, called the **rotational latency.**

The **transfer rate** is the rate at which data flow between the drive and the computer.

Data transfers on a bus are managed by **controllers**. The **host controller** is located at the computer end, while each disk drive has its own **disk controller**. 
- To perform disk I/O, the computer sends a command to the **host controller**, 
- Which forwards it to the **disk controller**. 
- The disk controller then operates the **disk hardware**. 
- Disk controllers typically include a **cache**, enabling fast data transfers between the **cache and disk surface**, as well as between the **cache and host controller** at electronic speeds. 

**SSD**

**SSDs** have the same characteristics as traditional hard disks but can be more reliable because they have no moving parts and faster because they have no **seek time** or **latency**.

Note: because **SSDs** have no disk head, **disk-scheduling algorithms** largely do not apply. **Throughput** and **formatting**, however, do apply.

## Disk structure

Modern magnetic disk drives are addressed as large one-dimensional arrays of **logical blocks**
- Where the logical block is the smallest unit of transfer. 
- The size of a logical block is usually 512 bytes

## Disk attachment
Computers access disk storage in two ways
- Via I/O ports (**host-attached storage**); this is common on small systems
- Via a remote host in a distributed file system; this is referred to as **network-attached storage** 

**Host-Attached Storage**

Host-attached storage is storage accessed through local I/O ports. These ports use several technologies.
- Typical: **IDE** or **ATA** (Support maximum of two drives per I/O bus.)
- A newer, similar protocol that has simplified cabling is **SATA**
- High-end workstations and servers use more sophisticated I/O architectures such as fibre channel (**FC**)


**Network-Attached Storage**

Clients access network-attached storage via a remote-procedure-call interface such as:
- **NFS** for UNIX systems  
- **CIFS** for Windows machines. 

![NAS](./Assets/image_63.png)

**iSCSI** is the latest network-attached storage protocol. In essence, it uses the IP network protocol to carry the SCSI protocol

**Storage-Area Network**

Same with NAS but on private network

- **FC** is the most common SAN interconnect,
- Although the simplicity of **iSCSI** is increasing its use. 
- Another SAN interconnect is **InfiniBand** — a special-purpose bus architecture that provides hardware and software support for high-speed interconnection networks for servers and storage units

![SAN](./Assets/image_62.png)

## Disk Scheduling

Whenever a process needs I/O to or from the disk, it issues a system call to the operating system. The request specifies several pieces of information:
- Whether this operation is input or output
- What the disk address for the transfer is
- What the memory address for the transfer is
- What the number of sectors to be transferred is

**FCFS scheduling**: First come first serve. 

**SSTF Scheduling**: Shortest-seek-time-first ( SSTF) algorithm.

**SCAN Scheduling**:
In the **SCAN** algorithm, the disk arm starts at one end of the disk and moves toward the other end, servicing requests as it reaches each cylinder, until it gets to the other end of the disk. 

At the other end, the direction of head movement is reversed, and servicing continues. The head continuously scans back and forth across the disk. 

The **SCAN** algorithm is sometimes called the *elevator* algorithm, since the disk arm behaves just like an elevator in a building, first servicing all the requests going up and then reversing to service requests the other way.

**C-SCAN Scheduling**

Circular SCAN (**C-SCAN**) scheduling is a variant of **SCAN** designed to provide a more uniform wait time. 
- Like SCAN, C-SCAN moves the head from one end of the disk to the other, servicing requests along the way. 
- When the head reaches the other end, however, it immediately returns to the beginning of the disk without servicing any requests on the return trip 

**LOOK Scheduling**

More commonly, the arm goes only as far as the final request in each direction. Then, it reverses direction immediately, without going all the way to the end of the disk.
- Versions of SCAN and C-SCAN that follow this pattern are called **LOOK** and **C-LOOK** scheduling, because they look for a request before continuing to move in a given direction

**Selection of a Disk-Scheduling Algorithm**

SSTF is common and has a natural appeal because it increases performance over FCFS.

SCAN and C-SCAN perform better for systems that place a heavy load on the disk, because they are less likely to cause a starvation problem.

With any scheduling algorithm, however, performance depends heavily on the number and types of requests.

## Disk Management

### Disk formating

Before a disk can store data, it must be divided into sectors that the disk controller can read and write. This process is called **low-level formatting**, or **physical formatting**.

**Low-level formatting** fills the disk with a special data structure for each sector. The data stucture typically consist:
- Header
- Data area (Usually 512 bytes)
- Trailer

The **header** and **trailer** contain information used by the disk controller, such as a sector number and an error-correcting code (ECC)
- When the sector is read, the **ECC** is recalculated and compared with the stored value. If the stored and calculated numbers are different, this mismatch indicates that the data area of the sector has become corrupted and that the disk sector may be bad

Before it can use a disk to hold files, **the operating system still needs to record its own data structures on the disk**. It does so in two steps: 
- The first step is to **partition**
- The second step is **logical formatting**, or creation of a file system.

Some operating systems give special programs the ability to use a disk partition as a large sequential array of logical blocks, without any file-system data structures. This array is sometimes called **the raw disk**, and I/O to this array is termed **raw I/O**.
- Raw I/O bypasses all the file-system services, such as the buffer cache, file locking, prefetching, space allocation, file names, and directories.
- We can make certain applications more efficient by allowing them to implement their own special-purpose storage services on a raw partition, but most applications perform better when they use the regular file-system services.

### Boot block

When the computer start, **bootstrap** programs run, one step when booting is:
- The bootstrap program finds the operating-system kernel on disk
- Loads that kernel into memory
- Jumps to an initial address to begin the operating-system execution.

A disk that has a boot partition is called a **boot disk** or **system disk**.

### Bad block

One strategy is to scan the disk to find bad blocks while the disk is being formatted. 
- Any bad blocks that are discovered are flagged as unusable so that the file system does not allocate them
-  If blocks go bad during normal operation, a special program (such as the Linux `badblocks` command) must be run manually to search for the bad blocks and to lock them away. 
    - Data that resided on the bad blocks usually are lost.

The controller maintains a list of bad blocks on the disk. The list is initialized during the low-level formatting at the factory and is updated over the life of the disk.
- The controller can be told to replace each bad sector logically with one of the spare sectors. This scheme is known as sector sparing or forwarding.

## Swap-space management

Swapping in that setting occurs when the amount of physical memory reaches a critically low point and processes are moved from memory to swap space to free available memory.

The main goal for the design and implementation of swap space is to provide the best throughput for the virtual memory system.

**Swap-space use**: 
- Swap space is used in various ways by different operating systems, depending on the memory-management algorithms in use. 
- The amount of swap space needed on a system can therefore vary from a few megabytes of disk space to gigabytes, depending on 
  - The amount of physical memory
  - The amount of virtual memory  it is backing
  - The way in which the virtual memory is used

**Swap-space locations**:

A swap space can reside in one of two places: 
- It can be carved out of the normal file system.
  - Easy but inefficient. Navigating the directory structure and the disk allocation data structures takes time and (possibly) extra disk accesses.
- Or it can be in a separate disk partition.
  -  This manager uses algorithms optimized for speed rather than for storage efficiency, because swap space is accessed much more frequently than file systems 

Some operating systems are flexible and can swap both in raw partitions and in file-system space. 

## RAID Structure

**Redundant arrays of independent disks** (RAID): Collection of mutiple disks, at which data can be read or written in parallel.

**Improvement of Reliability via Redundancy**:
- Because we use multiple disks, one disk fail not lead to system fail.
- The solution to the problem of reliability is to introduce **redundancy**
 - The simplest (but most expensive) approach to introducing redundancy is to duplicate every disk. This technique is called **mirroring**

**Improvement in Performance via Parallelism**:

With multiple disks, we can improve the transfer rate as well (or instead) by striping data across the disks 
- In its simplest form, **data striping** consists of splitting the bits of each byte across multiple disks; such striping is called **bit-level striping.** 


Parallelism in a disk system, as achieved through striping, has two main goals:
1. Increase the throughput of multiple small accesses (that is, page accesses) by load balancing.
2. Reduce the response time of large accesses.

**RAID levels**

**Mirroring**, **Stripping**, and other schemes to impove performance and reliability. These schemes have different cost–performance trade-offs and are classified according to levels called **RAID levels**. 

![RAID levels](./Assets/image_64.png)

- RAID level 0. RAID level 0 refers to disk arrays with striping at the level of blocks but without any redundancy (such as mirroring or parity bits).
- RAID level 1. RAID level 1 refers to disk mirroring.
- RAID level 2. RAID level 2 is also known as memory-style error-correcting-code (ECC ) organization.
- RAID level 3. RAID level 3, or bit-interleaved parity organization.
- RAID level 4. RAID level 4, or block-interleaved parity organization.
- RAID level 5. RAID level 5, or block-interleaved distributed parity, differs from level 4 in that it spreads data and parity among all N + 1 disks, rather than storing data in N disks and parity in one disk. 
- RAID level 6. RAID level 6, also called the `P + Q` redundancy scheme, is much like RAID level 5 but stores extra redundant information to guard against multiple disk failures.

Other features, such as snapshots and replication, can be implemented at each of these levels as well.
- A **snapshot** is a view of the file system before the last update took place. (Snapshots are covered more fully in Chapter 12.) 
- **Replication** involves the automatic duplication of writes between separate sites for redundancy and disaster recovery.

**Selecting a RAID Level**
- RAID level 0 is used in high-performance applications where data loss is not critical. 
- RAID level 1 is popular for applications that require high reliability with fast recovery.
- RAID 0 + 1 and 1 + 0 are used where both performance and reliability are important—for example, for small databases.
- RAID 5 is often preferred for storing large volumes of data. 
- Level 6 is not supported currently by many RAID implementations, but it should offer better reliability than level 5.

**Extensions** 

The concepts of RAID have been generalized to other storage devices, including arrays of tapes, and even to the broadcast of data over wireless systems. 

**Problems with RAID**

Unfortunately, RAID does not always assure that data are available for the operating system and its users.
- RAID protects against physical media errors, but not other hardware and software errors. 
- A pointer to a file could be wrong, and when recovery, some error can make the file be corrupted.

The **Solaris ZFS** file system takes an innovative approach to solving these problems through the use of **checksums**

Consider an **inode** — a data structure for storing file system metadata with pointers to its data.
- Within the *inode* is the checksum of each block of data.
  - If there is a problem with the data, the checksum will be incorrect, and the file system will know about it. 
  - If the data are mirrored, and there is a block with a correct checksum and one with an incorrect checksum, ZFS will automatically update the bad block with the good one.
- Same with directory.

Another issue with most RAID implementations is lack of flexibility.
  - When we divide Storage to equal volume and FS, some FS need more disk, some need less. But we can not change the structure dynamicly.

ZFS propose the disks, or partitions of disks, are gathered together via RAID sets into **pools** of storage. A **pool** can hold one or more ZFS file systems. The entire pool’s free space is available to all file systems within that pool.

![ZFS](./Assets/image_65.png)

## Stable-Storage Implementation

The information residing in stable storage is never lost. To implement such storage:
- Replicate the required information on multiple storage devices (usually disks) with independent failure modes.
- Coordinate the writing of updates in a way that guarantees that a failure during an update will not leave all the copies in a damaged state.
- When we are recovering from a failure, we can force all copies to a consistent and correct value, even if another failure occurs during the recovery.

**How?**

First, we need to understand a disk write results in one of three outcomes:
- Successful completion. The data were written correctly on disk.
- Partial failure. A failure occurred in the midst of transfer, so only some of the sectors were written with the new data, and the sector being written during the failure may have been corrupted.
- Total failure. The failure occurred before the disk write started, so the previous data values on the disk remain intact.

Steps to recover the failure, the system must maintain two physical blocks for each logical block.
- Write the information onto the first physical block.
- When the first write completes successfully, write the same information onto the second physical block.
- Declare the operation complete only after the second write completes successfully.

# Chapter 11

## File concept

From a user’s perspective, a file is the smallest allotment of logical secondary storage; that is, data cannot be written to secondary storage unless they are within a file

**File attributes:**

A file’s attributes vary from one operating system to another but typically consist of these:
- **Name.** The symbolic file name is the only information kept in human-readable form.
- **Identifier.** This unique tag, usually a number, identifies the file within the file system; it is the non-human-readable name for the file.
- **Type.** This information is needed for systems that support different types of files.
- **Location.** This information is a pointer to a device and to the location of the file on that device.
- **Size.** The current size of the file (in bytes, words, or blocks) and possibly the maximum allowed size are included in this attribute.
- **Protection.** Access-control information determines who can do reading, writing, executing, and so on.
- **Time, date, and user identification.** This information may be kept for creation, last modification, and last use. These data can be useful for protection, security, and usage monitoring.

**File Operations:**
- Create a file: Two steps are necessary to create a file.
  - First, space in the file system must be found for the file.
  - Second, an entry for the new file must be made in the directory.
- Writing a file: To write a file, we make a system call specifying both the name of the file and the information to be written to the file
  - The system must keep a **write pointer** to the location in the file where the next write is to take place. 
  - The **write pointer** must be updated whenever a write occurs.
- Reading a file: To read from a file, we use a system call that specifies the name of the file and where (in memory) the next block of the file should be put.
  - We alos keep **read pointer**, where the next read is to take place.
  - We can simplify as **current-file-position pointer**. Both the read and write operations use this same pointer, saving space and reducing system complexity.
- Repositioning within a file: Repositioning within a file need not involve any actual I/O . This file operation is also known as a file **seek**.
- Deleting a file: we release all file space, so that it can be reused by other files, and erase the directory entry.
- Truncating a file: The user may want to erase the contents of a file but keep its attributes. 
  - This function allows all attributes to remain unchanged—except for file length

Most of the file operations mentioned involve searching the directory for the entry associated with the named file. To avoid this constant searching, many systems require that an `open()` system call be made before a file is first used. The operating system keeps a table, called the **open-file table**

In summary, several pieces of information are associated with an open file.
- File pointer
- File-open count
- Disk location of the file
- Access rights

**File Types**

If an operating system recognizes the type of a file, it can then operate on the file in reasonable ways

A common technique for implementing file types is to include the type as part of the file name. The name is split into two parts:
- A name
- An file extension

![Common file types](./Assets/image_66.png)

The UNIX system uses a crude **magic number** stored at the beginning of some files to indicate roughly the type of the file, but not all file types have **magic number**

**File structure**

File types also can be used to indicate the internal structure of the file.

Further, certain files must conform to a required structure that is understood by the operating system.

This point brings us to one of the disadvantages of having the operating system support multiple file structures: the resulting size of the operating system is cumbersome

**Internal structure**

Disk systems typically have a well-defined block size determined by the size of a sector. All disk I/O is performed in units of one block (physical record), and all blocks are the same size

Because disk space is always allocated in blocks, some portion of the last block of each file is generally wasted. All file systems suffer from internal fragmentation; the larger the block size, the greater the internal fragmentation.

## Acess methods

**Sequential Access**: Information in the file is processed in order, one record after the other. 


**Direct Access:**  Here, a file is made up of fixed-length logical records that allow programs to read and write records rapidly in no particular order. 

**Direct-access** files are of great use for immediate access to large amounts of information. Databases are often of this type. When a query concerning a particular subject arrives, we compute which block contains the answer and then read that block directly to provide the desired information.

The block number provided by the user to the operating system is normally a **relative block number**. A relative block number is an index relative to the beginning of the file

Not all operating systems support both sequential and direct access for file

**Other Access Methods**: Other access methods can be built on top of a *direct-access method*. These methods generally involve the construction of an **index for the file**. The index, like an index in the back of a book, contains pointers to the various blocks. 

To find a record in the file, we first search the index and then use the pointer to access the file directly and to find the desired record.

For example, **IBM’s indexed sequential-access method (ISAM)**   uses a small master index that points to disk blocks of a secondary index. The secondary index blocks point to the actual file blocks. The file is kept sorted on a defined key.

![Index access](./Assets/image_67.png)

## Directory and disk Structure

Partitioning is useful for limiting the sizes of individual file systems, putting multiple file-system types on the same device, or leaving part of the device available for other uses.

A file system can be created on each of these parts of the disk. Any entity containing a file system is generally known as a **volume**. The volume may be a subset of a device, a whole device, or multiple devices linked together into a RAID set. 

![File system](./Assets/image_68.png)

The **device directory** (more commonly known simply as the **directory**) records information—such as name, location, size, and type—for all files on that volume. 

#### Storage Structure

### Directory Overview

The operations that are to be performed on a directory:
- Search for a file
- Create a file
- Delete a file
- List of directory
- Rename a file
- Traverse the file system: We may wish to access every directory and every file within a directory structure.

#### Single-Level Directory

All files are contained in the same directory. A single-level directory has significant limitations, when the number of files increases or when the system has more than one user. Since all files are in the same directory, they must have unique names.

![Single level directory](./Assets/image_70.png)

#### Two-Level Directory

In the two-level directory structure, each user has his own user file directory (UFD). 
- The **UFD** s have similar structures, but each lists only the files of a single user.
- When a user job starts or a user logs in, the **system’s master file directory (MFD)** is searched. The **MFD** is indexed by user name or account number, and each entry points to the **UFD** for that user 
  - To delete a file, the operating system confines its search to the local UFD; Thus, it cannot accidentally delete another user’s file that has the same name.

![Two level directory](./Assets/image_71.png)

This structure effectively isolates one user from another.
- Isolation is an advantage when the users are completely independent.
- Disadvantage when the users want to cooperate on some task and to access one another’s files

If access is to be permitted, one user must have the ability to control a file in another user’s directory.

#### Tree-Structured Directories

A directory (or subdirectory) contains a set of files or subdirectories. **A directory is simply another file**, but it is treated in **a special way**. 
- All directories have the same internal format. One bit in each directory entry defines the entry as a file (0) or as a subdirectory (1). Special system calls are used to create and delete directories.

![Tree directory](./Assets/image_72.png)

Path names can be of two types: **absolute** and **relative**. 
- An **absolute path** name begins at the root and follows a path down to the specified file, giving the directory names on the path. 
- A **relative path** name defines a path from the current directory.

With a tree-structured directory system, users can be allowed to access, in addition to their files, the files of other users.

#### Acyclic-Graph Directories

A tree structure prohibits the sharing of files or directories. **An acyclic graph** that is, A directory structure that allows shared files using links but ensures there are no cycles (i.e., no circular references).
- This is commonly implemented using **hard links** or **symbolic links.**
- Every file or directory can have multiple parents, but the structure remains a **Directed Acyclic Graph (DAG)**.
- A **link** is effectively a pointer to another file or subdirectory.

![Acyclic graph](./Assets/image_73.png)

An acyclic-graph directory structure is more flexible than a simple tree structure, but it is also more complex. Several problems must be considered carefully.
- A file may now have multiple absolute path names

#### General Graph Directory

A directory structure that allows arbitrary cycles, meaning a file or directory can reference itself indirectly or directly.
Uses hard links, symbolic links, or other references without cycle restrictions.

**Advantages:**
- Greater flexibility (no restrictions on linking).

**Disadvantages:**
- Can lead to infinite loops (e.g., if a program recursively scans directories).
- More complex file deletion and garbage collection mechanisms are required.
- Navigation and searches (like depth-first traversal) need cycle detection algorithms.

![General graph](./Assets/image_74.png)

## File-System Mounting

The directory structure may be built out of multiple volumes, which must be **mounted** to make them available within the file-system name space.

The **mount** procedure is straightforward. 
- The operating system is given the name of the device and the **mount point** the location within the file structure where the file system is to be attached.
- Next, the operating system verifies that the device contains a valid file system. 
  - It does so by asking the device driver to read the device directory and verifying that the directory has the expected format. 
- Finally, the operating system notes in its directory structure that a file system is mounted at the specified **mount point**.

![Mount volume](./Assets/image_69.png)

## File Sharing

**Multiple user**: To implement sharing and protection, the system must maintain more **file and directory attributes** than are needed on a single-user system. Typically, most system use these concept:
- File owner (or user): The owner is the user who can change attributes and grant access and who has the most control over the file.
- Group: Defines a subset of users who can share access to the file

### **Remote file system:**
- The first implemented method involves manually transferring files between machines via programs like **ftp**
- The second major method uses **a distributed file system (DFS)** in which remote directories are visible from a local machine.
- The third method, the **World Wide Web**, is a reversion to the first. 
  - A browser is needed to gain access to the remote files, and separate operations (essentially a wrapper for **ftp**) are used to transfer files
- The cloud computing is being used for file sharing as well.

**The client-server model**:

In this case, the machine containing the files is the **server**, and the machine seeking access to the files is the **client**.

**Distributed information systems:**

To make client–server systems easier to manage, **distributed information systems**, also known as **distributed naming services**, provide unified access to the information needed for remote computing

The industry is moving toward use of the **lightweight directory-access protocol (LDAP)** as a secure distributed naming mechanism. 

**Failure modes**:

Local file systems can fail due to disk failures, metadata corruption, hardware malfunctions, or human errors, often leading to system crashes that require manual recovery.

Remote file systems introduce additional failure modes due to network interruptions, server crashes, or poor hardware configurations. Unlike local file systems, remote file system failures require protocols that either terminate operations or delay them until the server is accessible again.

To handle failures, distributed file systems (DFS) may maintain state information on both the client and server to enable seamless recovery. 
- The Network File System (NFS) traditionally follows a stateless approach, assuming that each request contains all necessary information, making it simple and resilient but vulnerable to security risks like forged requests. 
- NFS Version 4 introduces a stateful design to enhance security, performance, and functionality.

## Consistency semantics

**Consistency semantics** represent an important criterion for evaluating any file system that supports file sharing. 
- These semantics specify how multiple users of a system are to access a shared file simultaneously.
  - In particular, they specify when modifications of data by one user will be observable by other users. 
- These semantics are typically implemented as code with the file system.

The series of accesses between the `open()` and `close()` operations makes up a **file session.**

**UNIX semantics**:
- Writes to an open file by a user are visible immediately to other users who have this file open.
- One mode of sharing allows users to share the pointer of current location into the file. Thus, the advancing of the pointer by one user affects all sharing users. Here, a file has a single image that interleaves all accesses, regardless of their origin.

**Session Semantics**:
- Writes to an open file by a user are not visible immediately to other users that have the same file open.
- Once a file is closed, the changes made to it are visible only in sessions starting later. Already open instances of the file do not reflect these changes.

**Immutable-Shared-Files Semantics**:
-  Once a file is declared as shared by its creator, it cannot be modified

## Protection

When information is stored in a computer system, we want to keep it safe from physical damage (the issue of reliability) and improper access (the issue of protection) 

Reliability is generally provided by duplicate copies of file

For improper access, we discuss in below

### Access control

The most general scheme to implement identity dependent access is to associate with each file and directory an **access-control list (ACL)** specifying user names and the types of access allowed for each user.

- **Owner**. The user who created the file is the owner.
- **Group**. A set of users who are sharing the file and need similar access is a group, or work group. 
- **Universe**. All other users in the system constitute the universe.
 
Windows users typically manage access-control lists via the GUI

**Other Protection Approaches**:

- Associate a password with each file.
- In a multilevel directory structure, we need to provide a mechanism for directory protection

# Chapter 12

## File system structure

Disks are the primary form of secondary storage for file systems due to their ability to rewrite data in place and access any block directly. I/O transfers between memory and disk occur in blocks, typically 512 bytes in size.

File systems are designed to store, locate, and retrieve data efficiently. They involve two key challenges: defining how files appear to users (including attributes, operations, and directory structures) and implementing algorithms to map logical files onto physical storage.

A **layered design** is commonly used, where each level builds on lower-level functions. The I/O control layer consists of device drivers and interrupt handlers that translate high-level commands into hardware-specific instructions. The basic file system layer interacts with device drivers to read and write disk blocks, identified by numeric disk addresses. It also manages memory buffers and caches to optimize performance.

![File system layer](./Assets/image_75.png)

The file-system structure consists of multiple layers to efficiently manage storage, retrieval, and metadata.

- **Buffering and Caching**: Buffers hold data during I/O transfers, while caches store frequently used metadata to enhance performance.
- **File-Organization Module**: This layer handles logical-to-physical block address translation and includes a free-space manager to track and allocate unoccupied blocks.
- **Logical File System**: It manages metadata (e.g., ownership, permissions, and locations), directory structures, and file control blocks (FCBs or inodes in UNIX). It also ensures file protection.

A layered structure reduces code duplication but may introduce performance overhead. Each OS supports multiple file systems:

- UNIX: UFS (based on Berkeley FFS)
- Windows: FAT, FAT32, NTFS, and CD/DVD formats
- Linux: Ext3, Ext4, and support for over 40 file systems
- Distributed File Systems allow network-based file access.

Research continues, with notable innovations such as Google’s proprietary file system for large-scale distributed storage and FUSE, which enables user-level file system development.

## File system implementation

A file system relies on both **on-disk** and **in-memory** structures to manage files efficiently.

**On-Disk Structures (Persistent Storage)**

These structures are stored on the disk itself and help maintain file organization and metadata across system reboots. These structure include:
- A **boot control block (per volume)** can contain information needed by thesystem to boot an operating system from that volume. (maybe empty if not contain OS)
  - In **UFS**, this call **boot block.**
  - In NTFS, it is the **partition boot sector.**
- A **volume control block** (per volume) contains volume (or partition) details, such as the number of blocks in the partition, the size of the blocks, a free-block count and free-block pointers, and a free-FCB count and FCB pointers.
- A **directory structure (per file system)** is used to organize the files.
  - In UFS, this includes file names and associated **inode** numbers.
  - In NTFS, it is stored in the **master file table**.
- A **per-file FCB** contains many details about the file. It has a unique identifier number to allow association with a directory entry.

**In-Memory Structures (Temporary Storage)**

These structures are maintained in RAM to improve file system performance by reducing disk access time. The data are loaded at mount time, updated during file-system operations, and discarded at dismount. Include:
- **An in-memory mount table** contains information about each mounted volume.
- An **in-memory directory-structure** cache holds the directory information of recently accessed directories.
- The **system-wide open-file table** contains a copy of the FCB of each open file, as well as other information.
- The **per-process open-file table** contains a pointer to the appropriate entry in the **system-wide open-file table**, as well as other information.
- **Buffers** hold file-system blocks when they are being read from disk or written to disk.


### **Summary of File System Operations**  

When a file is created, the **logical file system** allocates a **file control block (FCB)**, updates the directory, and writes the changes to disk. Different operating systems handle directories differently—**UNIX treats directories as files**, while **Windows separates files and directories**.  

To open a file, the system first checks the **system-wide open-file table** to determine if the file is already open. If so, a **per-process open-file table** entry is created, pointing to the existing entry. Otherwise, the directory is searched, the **FCB is loaded into memory**, and an entry is added to both tables. The **per-process table** includes:  
- A pointer to the system-wide table entry  
- The file's **current position** (for reading/writing)  
- The **access mode** (read, write, etc.)  

The `open()` call returns a reference to the per-process entry, which is used for all file operations. **UNIX calls this a file descriptor, while Windows calls it a file handle.**  

File sharing is managed through **open-file tables**. The system-wide table maintains an **open count** for each file, tracking how many processes are using it. When a process closes the file, the count is decremented. When it reaches zero, metadata updates are written back to disk, and the entry is removed.  

Some systems, such as **UFS**, use the file system to manage other system aspects like networking and device access. In these cases, the **system-wide open-file table** holds information for **both files and network connections**.  

**Caching plays a crucial role** in file system efficiency. Most systems keep file metadata in memory, reducing disk access. **BSD UNIX**, for example, achieves an **85% cache hit rate**, significantly improving performance.

![In memory file system](./Assets/image_76.png)

### Partitions and Mounting

Each partition can be either **“raw,”** containing no file system, or **“cooked,”** containing a file system

- The **bootloader (GRUB, Syslinux, etc.)** is responsible for locating and loading the OS kernel into memory.  
- Once the **kernel is loaded**, it initializes hardware and memory management.  
- The kernel then **mounts the root filesystem (root partition) in read-only mode** using the disk drivers and file system drivers.  
- After mounting the root partition, the kernel starts **init** 

The **root partition**, which contains the operating-system kernel and sometimes other system files, is mounted at boot time.
- **Windows** systems mount each volume in a separate name space, denoted by a letter and a colon. (like: `F:`)
- On **UNIX** , file systems can be mounted at any directory. **Mounting** is implemented by setting a **flag** in the in-memory copy of the inode for that directory
  - **flag** indicate directory is a **mount point**.
  - Directory point to **entry of monut table**
  - The **mount table entry** contains a pointer to the **superblock** of the file system on that device.

### Virtual file system

How does an operating system allow multiple types of file systems to be integrated into a directory structure?

## Directory implementation

**Linear List**:

**Hash Table**

## Allocation methods

**Contiguous Allocation**

**Linked Allocation**

**Indexed Allocation**

**Performance**

## Free space management

**Bit Vector**

**Linked List**

**Grouping**

**Counting**

**Space map**

## Efficiency and Performance

**Efficiency**

**Performance**

## Recovery

**Consistency Checking**

**Log-Structured File Systems**

**Other Solutions**

**Backup and Restore**

## NFS

**Overview**

**NFS** views a set of interconnected workstations as a set of independent machines with independent file systems

## Example: The WAFL File System
