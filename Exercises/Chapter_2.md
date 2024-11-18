# Chapter 2 exercises

#### 2.1 What is the purpose of system calls?

Provide a communication protocol for application to commute with OS

---

#### 2.2 What are the five major activities of an operating system with regard to process management?

---

#### 2.3 What are the three major activities of an operating system with regard to memory management?
#### 2.4 What are the three major activities of an operating system with regard to secondary-storage management?
#### 2.5 What is the purpose of the command interpreter? Why is it usually separate from the kernel?

#### 2.6 What system calls have to be executed by a command interpreter or shell in order to start a new process?
#### 2.7 What is the purpose of system programs?
#### 2.8 What is the main advantage of the layered approach to system design? What are the disadvantages of the layered approach?
#### 2.9 List five services provided by an operating system, and explain how each creates convenience for users. In which cases would it be impossible for user-level programs to provide these services? Explain your answer.
#### 2.10 Why do some systems store the operating system in firmware, while others store it on disk?
#### 2.11 How could a system be designed to allow a choice of operating systems from which to boot? What would the bootstrap program need to do?

#### 2.12 The services and functions provided by an operating system can be divided into two main categories. Briefly describe the two categories, and discuss how they differ.
#### 2.13 Describe three general methods for passing parameters to the operating
system.
#### 2.14 Describe how you could obtain a statistical profile of the amount of time spent by a program executing different sections of its code. Discuss the importance of obtaining such a statistical profile.
#### 2.15 What are the five major activities of an operating system with regard to file management?
#### 2.16 What are the advantages and disadvantages of using the same system-call interface for manipulating both files and devices?
#### 2.17 Would it be possible for the user to develop a new command interpreter using the system-call interface provided by the operating system?
#### 2.18 What are the two models of inter-process communication? What are the strengths and weaknesses of the two approaches?
#### 2.19 Why is the separation of mechanism and policy desirable?
#### 2.20 It is sometimes difficult to achieve a layered approach if two components of the operating system are dependent on each other. Identify a scenario in which it is unclear how to layer two system components that require tight coupling of their functionalities.
#### 2.21 What is the main advantage of the microkernel approach to system design? How do user programs and system services interact in a micro-kernel architecture? What are the disadvantages of using the micro-kernel approach?

#### 2.22 What are the advantages of using loadable kernel modules?

Part II Assignment
In the module entry point, create a linked list containing five struct birthday elements. Traverse the linked list and output its contents to the kernel log buffer.
Invoke the dmesg command to ensure the list is properly constructed once the kernel module has been loaded.
In the module exit point, delete the elements from the linked list and return the free memory back to the kernel. Again, invoke the dmesg command to check that the list has been removed once the kernel module has been unloaded