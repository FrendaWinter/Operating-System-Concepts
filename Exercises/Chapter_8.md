# Chapter 8 exercies
#### 8.1 Name two differences between logical and physical addresses.

- Logical address is adress generate by CPU, programming are refer to this address
- Physical address is real address on memory, does not directly access it, they are used internally to fetch/store data.

#### 8.2 Consider a system in which a program can be separated into two parts: code and data. The CPU knows whether it wants an instruction (instruction fetch) or data (data fetch or store). Therefore, two base–limit register pairs are provided: one for instructions and one for data. The instruction base–limit register pair is automatically read-only, so programs can be shared among different users. Discuss the advantages and disadvantages of this scheme.

#### 8.3 Why are page sizes always powers of 2?

Because it represent fixed block of memory. Since memory always powers of 2 in size, so page size also need to be power of 2

#### 8.4 Consider a logical address space of 64 pages of 1,024 words each, mapped onto a physical memory of 32 frames.
1. How many bits are there in the logical address?
2. How many bits are there in the physical address?

#### 8.5 What is the effect of allowing two entries in a page table to point to the same page frame in memory? Explain how this effect could be used to decrease the amount of time needed to copy a large amount of memory from one place to another. What effect would updating some byte on the one page have on the other page?
- We achieve memory sharing.
- When two process need to read on the same data, if the page table not allow point to the same frame entry, the data must have 2 copy to serve 2 process. While in other hand, we just need one copy of it.
- Updating some byte on one page  will be visable to the other. So be careful with data changing. Make sure data integrity
    - Copy-on-write maybe use to ensure data integrity.

#### 8.6 Describe a mechanism by which one segment could belong to the address space of two different processes.
#### 8.7 Sharing segments among processes without requiring that they have the same segment number is possible in a dynamically linked segmentation system.
1. Define a system that allows static linking and sharing of segments without requiring that the segment numbers be the same.
2. Describe a paging scheme that allows pages to be shared without requiring that the page numbers be the same.
#### 8.8 In the IBM/370 , memory protection is provided through the use of keys.
A key is a 4-bit quantity. Each 2-K block of memory has a key (the
storage key) associated with it. The CPU also has a key (the protectionkey) associated with it. A store operation is allowed only if both keys are equal or if either is 0. Which of the following memory-management schemes could be used successfully with this hardware?
-  Bare machine
-  Single-user system
-  Multiprogramming with a fixed number of processes
-  Multiprogramming with a variable number of processes
-  Paging
-  Segmentation
#### 8.9 Explain the difference between internal and external fragmentation.
#### 8.10 Consider the following process for generating binaries. A compiler is used to generate the object code for individual modules, and a linkage editor is used to combine multiple object modules into a single program binary. How does the linkage editor change the binding of instructions and data to memory addresses? What information needs to be passed from the compiler to the linkage editor to facilitate the memory-binding tasks of the linkage editor?
#### 8.11 Given six memory partitions of 300 KB, 600 KB, 350 KB, 200 KB, 750 KB, and 125 KB (in order), how would the first-fit, best-fit, and worst-fit algorithms place processes of size 115 KB, 500 KB, 358 KB, 200 KB, and 375 KB (in order)? Rank the algorithms in terms of how efficiently they use memory.
#### 8.12 Most systems allow a program to allocate more memory to its address space during execution. Allocation of data in the heap segments of programs is an example of such allocated memory. What is required to support dynamic memory allocation in the following schemes?
- Contiguous memory allocation
- Pure segmentation
- Pure paging

#### 8.13 Compare the memory organization schemes of contiguous memory allocation, pure segmentation, and pure paging with respect to the following issues:
-  External fragmentation
-  Internal fragmentation
-  Ability to share code across processes
#### 8.14 On a system with paging, a process cannot access memory that it does not own. Why? How could the operating system allow access to other memory? Why should it or should it not?

#### 8.15 Explain why mobile operating systems such as i OS and Android do not support swapping.
#### 8.16 Although Android does not support swapping on its boot disk, it is possible to set up a swap space using a separate SD nonvolatile memory card. Why would Android disallow swapping on its boot disk yet allow it on a secondary disk?
#### 8.17 Compare paging with segmentation with respect to how much memory the address translation structures require to convert virtual addresses to physical addresses.
#### 8.18 Explain why address space identifiers ( ASID s) are used.

#### 8.19 Program binaries in many systems are typically structured as follows. Code is stored starting with a small, fixed virtual address, such as 0. The code segment is followed by the data segment that is used for storing the program variables. When the program starts executing, the stack is allocated at the other end of the virtual address space and is allowed to grow toward lower virtual addresses. What is the significance of this structure for the following schemes?
- Contiguous memory allocation
- Pure segmentation
- Pure paging
#### 8.20 Assuming a 1- KB page size, what are the page numbers and offsets for the following address references (provided as decimal numbers):
- 3085
- 42095
- 215201
- 650000
- 2000001

#### 8.21 The BTV operating system has a 21-bit virtual address, yet on certain embedded devices, it has only a 16-bit physical address. It also has a 2-KB page size. How many entries are there in each of the following? a. A conventional, single-level page table
b. An inverted page table
#### 8.22 What is the maximum amount of physical memory?
#### 8.23 Consider a logical address space of 256 pages with a 4- KB page size, mapped onto a physical memory of 64 frames.
- How many bits are required in the logical address?
- How many bits are required in the physical address?

#### 8.24 Consider a computer system with a 32-bit logical address and 4-KB page size. The system supports up to 512 MB of physical memory. How many entries are there in each of the following?
#### 8.25 Consider a paging system with the page table stored in memory.
- If a memory reference takes 50 nanoseconds, how long does a paged memory reference take?
- If we add TLBs, and 75 percent of all page-table references are found in the TLBs, what is the effective memory reference time? (Assume that finding a page-table entry in the TLBs takes 2 nanoseconds, if the entry is present.)
#### 8.26 Why are segmentation and paging sometimes combined into one scheme? 
#### 8.27 Explain why sharing a reentrant module is easier when segmentation is used than when pure paging is used.
#### 8.28 Consider the following segment table:
|Segment |Base |Length|
|--|--|--|
0 | 219 |600
1 | 2300| 14
2 | 90 |100
3 | 1327| 580
4 | 1952| 96
What are the physical addresses for the following logical addresses?
- 0,430
- 1,10
- 2,500
- 3,400
- 4,112

#### 8.29 What is the purpose of paging the page tables?
#### 8.30 Consider the hierarchical paging scheme used by the VAX architecture. How many memory operations are performed when a user program executes a memory-load operation?
#### 8.31 Compare the segmented paging scheme with the hashed page table scheme for handling large address spaces. Under what circumstances is one scheme preferable to the other?
#### 8.32 Consider the Intel address-translation scheme shown in Figure 8.22.
-  Describe all the steps taken by the Intel Pentium in translating a logical address into a physical address.
-  What are the advantages to the operating system of hardware that provides such complicated memory translation?
-  Are there any disadvantages to this address-translation system? If so, what are they? If not, why is this scheme not used by every manufacturer?

#### 8.33 Assume that a system has a 32-bit virtual address with a 4-KB page size. Write a C program that is passed a virtual address (in decimal) on the command line and have it output the page number and offset for the given address. As an example, your program would run as follows:
`./a.out 19986`

Your program would output:
```bash
The address 19986 contains:
page number = 4
offset = 3602
```
Writing this program will require using the appropriate data type to store 32 bits. We encourage you to use unsigned data types as well.