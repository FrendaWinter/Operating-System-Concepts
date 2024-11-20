# Operating-System-Concepts
About the Operating System Concepts book

Ref https://github.com/gg-daddy/ebooks/blob/master/Operating%20System%20Concepts%2C%209th%20Edition.pdf

Author: Abraham Silberschatz, Peter Baer Galvin, Greg Gagne

# Concept:

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