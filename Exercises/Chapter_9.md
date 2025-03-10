# Chapter 9 Exercises
#### 9.1 Under what circumstances do page faults occur? Describe the actions taken by the operating system when a page fault occurs.

Page fault occur when page of process is not in memory for CPU to access. 

Operation system do:
1. Check an internal table (usually kept with the process control block) for this process to determine whether the reference was a valid or an invalid memory access.
2. If the reference was invalid, we terminate the process. If it was valid but we have not yet brought in that page, we now page it in.
3. We find a free frame (by taking one from the free-frame list, for example).
4. We schedule a disk operation to read the desired page into the newly allocated frame.
5. When the disk read is complete, we modify the internal table kept with the process and the page table to indicate that the page is now in memory.
6. We restart the instruction that was interrupted by the trap. The process can now access the page as though it had always been in memory.
#### 9.2 Assume that you have a page-reference string for a process with m frames (initially all empty). The page-reference string has length p, and n distinct page numbers occur in it. Answer these questions for any page-replacement algorithms:
- What is a lower bound on the number of page faults?
    - Lower bound is number of page faults occur when init, each distinct page will create page fault.
    - `n` if `n` < `m`
    - `m` if `n` > `m`

- What is an upper bound on the number of page faults?

#### 9.3 Consider the page table shown in Figure 9.30 for a system with 12-bit virtual and physical addresses and with 256-byte pages. The list of free page frames is D, E, F (that is, D is at the head of the list, E is second, and F is last).
Convert the following virtual addresses to their equivalent physical addresses in hexadecimal. All numbers are given in hexadecimal. (A dash for a page frame indicates that the page is not in memory.)
- 9EF
- 111
- 700
- 0FF

#### 9.4
#### 9.5
#### 9.6
#### 9.7
#### 9.8
#### 9.9
#### 9.10
#### 9.11
#### 9.12
#### 9.13
#### 9.14
#### 9.15
#### 9.16
#### 9.17
#### 9.18
#### 9.19
#### 9.20
#### 9.21
#### 9.22
#### 9.23
#### 9.24
#### 9.25
#### 9.26
#### 9.27
#### 9.28
#### 9.29
#### 9.30
#### 9.31
#### 9.32
#### 9.33
#### 9.34
#### 9.35
#### 9.36 A system provides support for user-level and kernel-level threads. The mapping in this system is one to one (there is a corresponding kernel thread for each user thread). Does a multithreaded process consist of (a) a working set for the entire process or (b) a working set for each thread? Explain

#### 9.37 The slab-allocation algorithm uses a separate cache for each different object type. Assuming there is one cache per object type, explain why this scheme doesn’t scale well with multiple CPUs. What could be done to address this scalability issue?

---

#### 9.38 Consider a system that allocates pages of different sizes to its processes. What are the advantages of such a paging scheme? What modifications to the virtual memory system provide this functionality?
- Reduced Page Table Size
- Minmize the internal fragmentation.
- Large page reduce I/O operation -> Improve performent.

---
#### 9.39

[Code](../Code/Chapter_9/9.39/main.cpp)

---
#### 9.40
