# Chapter 8 exercies
#### 8.1 Name two differences between logical and physical addresses.

Logical address is adress generate by CPU
Physical address is real address on memory

#### 8.2 Consider a system in which a program can be separated into two parts: code and data. The CPU knows whether it wants an instruction (instruction fetch) or data (data fetch or store). Therefore, two base– limit register pairs are provided: one for instructions and one for data. The instruction base–limit register pair is automatically read-only, so programs can be shared among different users. Discuss the advantages and disadvantages of this scheme.

#### 8.3 Why are page sizes always powers of 2?

Because it represent fixed block of memory. Since memory always powers of 2 in size, so page size also need to be power of 2

#### 8.4 Consider a logical address space of 64 pages of 1,024 words each, mapped onto a physical memory of 32 frames.
1. How many bits are there in the logical address?
2. How many bits are there in the physical address?

#### 8.5 What is the effect of allowing two entries in a page table to point to the same page frame in memory? Explain how this effect could be used to decrease the amount of time needed to copy a large amount of memory from one place to another. What effect would updating some byte on the one page have on the other page?
#### 8.6 Describe a mechanism by which one segment could belong to the address space of two different processes.
#### 8.7 Sharing segments among processes without requiring that they have the same segment number is possible in a dynamically linked segmentation system.
1. Define a system that allows static linking and sharing of segments without requiring that the segment numbers be the same.
2. Describe a paging scheme that allows pages to be shared without requiring that the page numbers be the same.