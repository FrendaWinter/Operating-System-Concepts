# Chapter 1 exercises

## Practice Exercise

#### 1. What are the three main purposes of an operating system?

The three main purposes of an operating system are:
- Managing Hardware Resources
- Providing a User Interface and Application Platform
- Ensuring System Security and Stability

#### 2. We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to “waste” resources? Why is such a system not really wasteful?
#### 3. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?
#### 4. Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.
#### 5. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?
#### 6. Which of the following instructions should be privileged?
    - Set value of timer.
    - Read the clock.
    - Clear memory.
    - Issue a trap instruction.
    - Turn off interrupts.
    - Modify entries in device-status table.
    - Switch from user to kernel mode.
    - Access I/O device.
6. Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.
7. Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?
8.  Timers could be used to compute the current time. Provide a short description of how this could be accomplished.
9.  Give two reasons why caches are useful. What problems do they solve?
    - What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk).
    - Why not make it that large and eliminate the device?
10. Distinguish between the client–server and peer-to-peer models of distributed systems.



#### 1.12 How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?
#### 1.13 Consider a computing cluster consisting of two nodes running a database. Describe two ways in which the cluster software can manage access to the data on the disk. Discuss the benefits and disadvantages of each.

#### 1.14 What is the purpose of interrupts? How does an interrupt differ from a trap? Can traps be generated intentionally by a user program? If so, for what purpose?
- notify the CPU that an immediate action or response is needed for an event, either from hardware (such as a keyboard or mouse input) or from software (such as a system call from a running program). When an interrupt occurs, it signals the CPU to temporarily pause its current tasks and execute a special function (an interrupt handler or service routine) to address the event.

1.15 Explain how the Linux kernel variables HZ and jiffies can be used to
determine the number of seconds the system has been running since it
was booted.
1.16 Direct memory access is used for high-speed I/O devices in order to
avoid increasing the CPU’s execution load.
a. How does the CPU interface with the device to coordinate the
transfer?
b. How does the CPU know when the memory operations are com-
plete?
c. The CPU is allowed to execute other programs while the DMA
controller is transferring data. Does this process interfere with
the execution of the user programs? If so, describe what forms of
interference are caused.
EX-1
1.17 Some computer systems do not provide a privileged mode of operation
in hardware. Is it possible to construct a secure operating system for
these computer systems? Give arguments both that it is and that it is
not possible.
1.18 Many SMP systems have different levels of caches; one level is local to
each processing core, and another level is shared among all processing
cores. Why are caching systems designed this way?
1.19 Rank the following storage systems from slowest to fastest:
a. Hard-disk drives
b. Registers
c. Optical disk
d. Main memory
e. Nonvolatile memory
f. Magnetic tapes
g. Cache

1.20 Consider an SMP system similar to the one shown in Figure 1.8. Illustrate
with an example how data residing in memory could in fact have a
different value in each of the local caches.
1.21 Discuss, with examples, how the problem of maintaining coherence of
cached data manifests itself in the following processing environments:
a. Single-processor systems
b. Multiprocessor systems
c. Distributed systems
1.22 Describe a mechanism for enforcing memory protection in order to
prevent a program from modifying the memory associated with other
programs.
1.23 Which network configuration— LAN or WAN —would best suit the fol-
lowing environments?
a. A campus student union
b. Several campus locations across a statewide university system
c. A neighborhood
1.24 Describe some of the challenges of designing operating systems for
mobile devices compared with designing operating systems for tradi-
tional PC s.
1.25 What are some advantages of peer-to-peer systems over client–server
systems?
1.26 Describe some distributed applications that would be appropriate for a
peer-to-peer system.
EX-2
1.27 Identify several advantages and several disadvantages of open-source
operating systems. Identify the types of people who would find each
aspect to be an advantage or a disadvantage.

