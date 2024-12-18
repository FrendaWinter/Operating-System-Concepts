# Chapter 1 exercises

## Practice Exercise

#### 1.1. What are the three main purposes of an operating system?

The three main purposes of an operating system are:
- Managing Hardware Resources
- Providing a User Interface and Application Platform
- Ensuring System Security and Stability

---

#### 1.2. We have stressed the need for an operating system to make efficient use of the computing hardware. When is it appropriate for the operating system to forsake this principle and to “waste” resources? Why is such a system not really wasteful?

- **Enhance reliability and security:** Duplicating data and using more computing power for security purposes may seems resources heavy but this is crucial for the GOV systems or infrastructure systems

- **Support virtualization:** Virtual machines and containerized environment use additional resources to emulate hardware or isolate processes, but provide flexibility, and isolation for specific purposes, like testing or malware analysis

--- 

#### 1.3. What is the main difficulty that a programmer must overcome in writing an operating system for a real-time environment?

A real-time system has well-defined, fixed time constraints. Processing must be done within the defined constraints, or the system will fail

---

#### 1.4. Keeping in mind the various definitions of operating system, consider whether the operating system should include applications such as web browsers and mail programs. Argue both that it should and that it should not, and support your answers.

---

#### 1.5. How does the distinction between kernel mode and user mode function as a rudimentary form of protection (security)?

---

#### 1.6. Which of the following instructions should be privileged?
    - Set value of timer.
    - Read the clock.
    - Clear memory.
    - Issue a trap instruction.
    - Turn off interrupts.
    - Modify entries in device-status table.
    - Switch from user to kernel mode.
    - Access I/O device.

**Privileged Instructions:**

- Set value of timer
  - Privileged: The timer is crucial for process scheduling and enforcing time slices. Allowing user processes to modify the timer could result in resource monopolization or denial of service.

- Clear memory
  - Privileged: Clearing memory could interfere with other processes or the operating system. Only the kernel should perform such operations to maintain system stability.

Turn off interrupts
  - Privileged: Disabling interrupts could prevent the CPU from responding to important events (e.g., I/O, timer), potentially freezing the system. This must be restricted to ensure system responsiveness.

Modify entries in device-status table
  - Privileged: The device-status table is used to track the state of hardware devices. Allowing user processes to modify it could lead to inconsistent or invalid device states.

Switch from user to kernel mode
  - Privileged: Transitioning to kernel mode must be tightly controlled to prevent unauthorized access to privileged resources or system calls.

Access I/O device
  - Privileged: Direct I/O access could allow processes to interfere with devices or other processes. The kernel mediates I/O operations to ensure fairness and correctness.

**Non-Privileged Instructions:**

- Read the clock
  - Non Privileged: Reading the current time is a safe operation that does not affect system integrity. This can be allowed in user mode.

- Issue a trap instruction
  - Non Privileged: A trap instruction is a mechanism for transferring control to the kernel (e.g., for system calls). It is an essential feature for user processes and does not compromise system security.

--- 

#### 1.6. Some early computers protected the operating system by placing it in a memory partition that could not be modified by either the user job or the operating system itself. Describe two difficulties that you think could arise with such a scheme.

---

#### 1.7. Some CPUs provide for more than two modes of operation. What are two possible uses of these multiple modes?

**Why need more than two mode:**

- Flexibility in Operations: Multiple modes indeed provide flexibility for the operating system to assign specific permissions and control over different types of operations.
- Enhanced Security: Multiple modes contribute to improved security by allowing finer-grained control over access rights and privileges, limiting the scope of potential vulnerability    

**Example of Protection**:
Rings (Intel Processors):
- Ring 0 (kernel mode) has the highest privileges and can execute all instructions.
- Ring 3 (user mode) is restricted and typically used for applications. Rings 1 and 2 can be used for intermediate privilege levels, though they are rarely utilized in modern OSes.

ARMv8 Modes:
- ARMv8 provides modes like EL0 (user applications), EL1 (OS kernel), EL2 (hypervisor), and EL3 (secure monitor). This architecture supports features like trusted execution environments (e.g., ARM TrustZone) to isolate sensitive operations.

Virtualization-Specific Modes:
- Virtualization-capable CPUs introduce modes like VMX root mode (Intel) or EL2 (ARMv8) for the VMM, ensuring guest operating systems cannot directly access hardware without going through the VMM.

---

#### 1.8. Timers could be used to compute the current time. Provide a short description of how this could be accomplished.

---

#### 1.9.  Give two reasons why caches are useful. What problems do they solve?
  - What problems do they cause? If a cache can be made as large as the device for which it is caching (for instance, a cache as large as a disk).
  - Why not make it that large and eliminate the device?

---

#### 1.10. Distinguish between the client–server and peer-to-peer models of distributed systems.

---

#### 1.12 How do clustered systems differ from multiprocessor systems? What is required for two machines belonging to a cluster to cooperate to provide a highly available service?

---

#### 1.13 Consider a computing cluster consisting of two nodes running a database. Describe two ways in which the cluster software can manage access to the data on the disk. Discuss the benefits and disadvantages of each.

---

#### 1.14 What is the purpose of interrupts? How does an interrupt differ from a trap? Can traps be generated intentionally by a user program? If so, for what purpose?

Notify the CPU that an immediate action or response is needed for an event, either from hardware (such as a keyboard or mouse input) or from software (such as a system call from a running program). When an interrupt occurs, it signals the CPU to temporarily pause its current tasks and execute a special function (an interrupt handler or service routine) to address the event.

Traps is one type of interrupt ~ software-generated interrupt, triggered intentionally by a user program.

Yes, traps can be generated intentionally by a user programmer
- system call
- exception

Traps provide a controlled way for a user program to request OS services. 

---

#### 1.15 Explain how the Linux kernel variables HZ and jiffies can be used to determine the number of seconds the system has been running since it was booted.

---

#### 1.16 Direct memory access is used for high-speed I/O devices in order to avoid increasing the CPU execution load.
a. How does the CPU interface with the device to coordinate the
transfer?
b. How does the CPU know when the memory operations are complete?
c. The CPU is allowed to execute other programs while the DMA
controller is transferring data. Does this process interfere with
the execution of the user programs? If so, describe what forms of
interference are caused.

---

#### 1.17 Some computer systems do not provide a privileged mode of operation in hardware. Is it possible to construct a secure operating system for these computer systems? Give arguments both that it is and that it is not possible.

---

#### 1.18 Many SMP systems have different levels of caches; one level is local to

Each processing core, and another level is shared among all processing
cores. Why are caching systems designed this way?

---

#### 1.19 Rank the following storage systems from slowest to fastest:
a. Hard-disk drives
b. Registers
c. Optical disk
d. Main memory
e. Nonvolatile memory
f. Magnetic tapes
g. Cache

Magnetic tapes -> Optical disk -> Hard-disk drives -> Nonvolatile memory -> Main memory -> Cache -> Registers

---

#### 1.20 Consider an SMP system similar to the one shown in Figure 1.8. Illustrate with an example how data residing in memory could in fact have a different value in each of the local caches.

---

#### 1.21 Discuss, with examples, how the problem of maintaining coherence of cached data manifests itself in the following processing environments:
a. Single-processor systems
b. Multiprocessor systems
c. Distributed systems

---

#### 1.22 Describe a mechanism for enforcing memory protection in order to prevent a program from modifying the memory associated with other programs.

---

#### 1.23 Which network configuration— LAN or WAN —would best suit the following environments?
a. A campus student union
b. Several campus locations across a statewide university system
c. A neighborhood

LAN: a and c
WAN: b

---

#### 1.24 Describe some of the challenges of designing operating systems for mobile devices compared with designing operating systems for traditional PC s.

---

#### 1.25 What are some advantages of peer-to-peer systems over client–server systems?

- No bottleneck at server
- Scalability

---

#### 1.26 Describe some distributed applications that would be appropriate for a peer-to-peer system.

- Gnutella
- Napster

---

#### 1.27 Identify several advantages and several disadvantages of open-source operating systems. Identify the types of people who would find each aspect to be an advantage or a disadvantage.

open-source OS provide powerfull developing environment and free tools, suite for computer scienctist, programmer and technology lover

But the common user maybe not be an advantage for open-source OS, they need friendly user interface app, some office app and file systems that easy to use.

