# Chapter 6 exercises

#### 6.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.
The number of different possible schedules for nn processes on a single processor is equivalent to the number of ways to arrange nn distinct processes in a sequence.

Total Schedules = `n!`

where: `n!=n×(n−1)×(n−2)×⋯×2×1`

If we have 3 process we have 6 orders, 4 is 24 order.

#### 6.2 Explain the difference between preemptive and nonpreemptive scheduling.

- In preemptive scheduling, the operating system can interrupt a running process and forcibly switch the CPU to another process. This is typically done to ensure fairness or to prioritize higher-priority tasks.
- In nonpreemptive scheduling, once a process has been assigned the CPU, it runs until it voluntarily releases the CPU (e.g., by completing its execution or entering a waiting state).

#### 6.3 Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.

| Process | Arrival Time | Burst Time |
| ------- | ------------ | ---------- |
| P1      | 0.0          | 8          |
| P2      | 0.4          | 4          |
| P3      | 1.0          | 1          |

TAT = CT (Completion Times) − Arrival Time

- What is the average turnaround time for these processes with the FCFS scheduling algorithm?
    - For P1, it take 8 time unit (from 0) to finish 
    - For p2, it take 12 time unit (from 0) to finish, minus 0.4 arrival time, so p2 take 11.6 time unit (in queue and execute)
    - Similar, p3 take 12 time unit.
    - In average, turnarounf time is 10.53

- What is the average turnaround time for these processes with the SJF scheduling algorithm?
    - At time 0.0, P1 is the only available process, so it starts execution. -> TT (Turnaround Times) of P1 = 8.0
    - At time 8.0, both P2 and P3 have arrived. SJF selects the shortest burst time, so P3 (1 unit) executes next. -> TT of P3 = 8.0
    - At time 9.0, P2 (4 units) executes. -> TT of P2 = 12.6
    - Average TAT = 9.53

- The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be called future-knowledge scheduling.
    - If CPU idea in the first time unit, TT of P3 = 1
    - TT of P2 = 5.6
    - TT of P1 = 14
    - Average TAT = 6.86

---
#### 6.4 What advantage is there in having different time-quantum sizes at different levels of a multilevel queueing system?

Each queue and priority need a different time-quantum, Process that high priority and require more CPU time will need longer time-quantum.

Other lower process maybe not need long time-quantum, that make lower priority process take more CPU time.

So have different time-quantum help system more flexiable, more effient when choosing what process to run, create fairness and balance on scheduling.

---
#### 6.5 Many CPU-scheduling algorithms are parameterized. For example, the `RR` algorithm requires a parameter to indicate the time slice. Multilevel feedback queues require parameters to define the number of queues, the scheduling algorithm for each queue, the criteria used to move processes between queues, and so on.
These algorithms are thus really sets of algorithms (for example, the set of RR algorithms for all time slices, and so on). One set of algorithms may include another (for example, the `FCFS` algorithm is the RR algorithm with an infinite time quantum). What (if any) relation holds between the following pairs of algorithm sets?
- Priority and SJF
    - In the same priority level, SJF will be use to choose between process.
- Multilevel feedback queues and FCFS
    - In the same queue, same time-quantum, FCFS maybe use to choose between process.
- Priority and FCFS
    - In the same priority level, FCFS maybe use to choose between process.
- RR and SJF
    - In RR with infinite time-quantum, FCFS maybe use to choose between process.

---

#### 6.6 Suppose that a scheduling algorithm (at the level of short-term CPU scheduling) favors those processes that have used the least processor time in the recent past. Why will this algorithm favor I/O-bound programs and yet not permanently starve CPU-bound programs?

---
#### 6.7 Distinguish between PCS and SCS scheduling.

Feature	| PCS (Process Contention Scope) |SCS (System Contention Scope)
--|--|--
Managed by | User-level thread library | OS kernel
Competes with | Other threads within the same process | Threads from all processes
Example model | Many-to-One, Many-to-Many | One-to-One
Thread switching | Faster (user-space) | Slower (involves kernel)
OS Awareness |OS is unaware of PCS threads | OS fully manages scheduling

---

#### 6.8 Assume that an operating system maps user-level threads to the kernel using the many-to-many model and that the mapping is done through the use of LWPs. Furthermore, the system allows program developers to create real-time threads. Is it necessary to bind a real-time thread to an LWP?

---

#### 6.9 The traditional UNIX scheduler enforces an inverse relationship between priority numbers and priorities: the higher the number, the lower the priority. The scheduler recalculates process priorities once per second using the following function:
`Priority = (recent CPU usage / 2) + base`

where base = 60 and recent CPU usage refers to a value indicating how often a process has used the CPU since priorities were last recalculated. Assume that recent CPU usage is 40 for process P1 , 18 for process P2 , and 10 for process P3 . What will be the new priorities for these three processes when priorities are recalculated? Based on this information, does the traditional UNIX scheduler raise or lower the relative priority of a CPU-bound process?

## Exercises

#### 6.10 Why is it important for the scheduler to distinguish I/O-bound programs from CPU-bound programs?

I/O-bound programs spend more time waiting for I/O operations (e.g., reading from disk, network communication) than performing computations. They require less CPU time and are better served by scheduling them frequently in short bursts.

- Avoid CPU idle time.
- Improve efficient of operating system.

---

#### 6.11 Discuss how the following pairs of scheduling criteria conflict in certain settings.
- CPU utilization and response time
- Average turnaround time and maximum waiting time
- I/O device utilization and CPU utilization

Criteria 1 | Criteria 2	| Conflict Explanation
--|--|--
CPU Utilization | Response Time | Maximizing CPU usage may delay interactive tasks, increasing response time.
Avg Turnaround Time | Max Waiting Time | Reducing turnaround time (e.g., SJF) can lead to starvation for long jobs.
I/O Utilization | CPU Utilization | Prioritizing one can lead to the other being underutilized.
---

#### 6.12 One technique for implementing lottery scheduling works by assigning processes lottery tickets, which are used for allocating CPU time. Whenever a scheduling decision has to be made, a lottery ticket is chosen at random, and the process holding that ticket gets the CPU. The BTV operating system implements lottery scheduling by holding a lottery 50 times each second, with each lottery winner getting 20 milliseconds of CPU time (20 milliseconds × 50 = 1 second). Describe how the BTV scheduler can ensure that higher-priority threads receive more attention from the CPU than lower-priority threads.

---
#### 6.13 In Chapter 5, we discussed possible race conditions on various kernel data structures. Most scheduling algorithms maintain a run queue, which lists processes eligible to run on a processor. On multicore systems, there are two general options: (1) each processing core has its own run queue, or (2) a single run queue is shared by all processing cores. What are the advantages and disadvantages of each of these approaches?

**Per-Core Run Queues:**
- No need for synchronization between cores when accessing the queue.
    - Process likely to run on same core, less context switch, better performance.
- Some cores may be overloaded while others remain idle. -> System need Complex Load Balancing Mechanism to make sure fairness

**Global Run Queue:**
- Better balancing.
- Many core access same queue -> Race condition.
    - Process may need to run on different core, more context switch

---
#### 6.14 Consider the exponential average formula used to predict the length of the next CPU burst. What are the implications of assigning the following values to the parameters used by the algorithm?
---
#### 6.15 A variation of the round-robin scheduler is the regressive round-robin scheduler. This scheduler assigns each process a time quantum and a priority. The initial value of a time quantum is 50 milliseconds. However, every time a process has been allocated the CPU and uses its entire time quantum (does not block for I/O), 10 milliseconds is added to its time quantum, and its priority level is boosted. (The time quantum for a process can be increased to a maximum of 100 milliseconds.) When a process blocks before using its entire time quantum, its time quantum is reduced by 5 milliseconds, but its priority remains the same. What type of process (CPU-bound or I/O-bound) does the regressive round-robin scheduler favor? Explain.
---
#### 6.16 Consider the following set of processes, with the length of the CPU burst given in milliseconds:

| Process | Burst Time | Priority |
| ------- | ---------- | -------- |
| P1      | 2          | 2        |
| P2      | 1          | 1        |
| P3      | 8          | 4        |
| P4      | 4          | 2        |
| P5      | 5          | 3        |

The processes are assumed to have arrived in the order P1 , P2 , P3 , P4 , P5 , all at time 0.
- Draw four Gantt charts that illustrate the execution of these processes using the following scheduling algorithms: FCFS, SJF, nonpreemptive priority (a larger priority number implies a higher priority), and RR (quantum = 2).
- What is the turnaround time of each process for each of the scheduling algorithms in part a?
- What is the waiting time of each process for each of these scheduling algorithms?
- Which of the algorithms results in the minimum average waiting time (over all processes)?

---

#### 6.17 The following processes are being scheduled using a preemptive, round-robin scheduling algorithm. Each process is assigned a numerical priority, with a higher number indicating a higher relative priority. In addition to the processes listed below, the system also has an idle task (which consumes no CPU resources and is identified as Pidle ). This task has priority 0 and is scheduled whenever the system has no other available processes to run. The length of a time quantum is 10 units. If a process is preempted by a higher-priority process, the preempted process is placed at the end of the queue.

- Show the scheduling order of the processes using a Gantt chart.
- What is the turnaround time for each process?
- What is the waiting time for each process?
- What is the CPU utilization rate?

#### 6.18 The nice command is used to set the nice value of a process on Linux, as well as on other UNIX systems. Explain why some systems may allow any user to assign a process a nice value >= 0 yet allow only the root user to assign nice values < 0.

---

#### 6.19 Which of the following scheduling algorithms could result in starvation?
- First-come, first-served
- Shortest job first
- Round robin
- Priority

The algorithm could result in starvataion is:
- The shortest job first: Because some job take more time than other job, if the scheduler just keep adding job that take shorter time, the longer time job can not be execute.
- Same with Priority, if the scheduler just keep adding job that have higher priority, the lower priority job can not be execute 

FCFS: Every job will eventually execute. Round-robin, every job gets a fair time slice, no job left starvation.

#### 6.20 Consider a variant of the RR scheduling algorithm in which the entries in the ready queue are pointers to the PCBs.
- What would be the effect of putting two pointers to the same process in the ready queue?
- What would be two major advantages and two disadvantages of this scheme?
- How would you modify the basic RR algorithm to achieve the same effect without the duplicate pointers?

#### 6.21 Consider a system running ten I/O -bound tasks and one CPU-bound task. Assume that the I/O-bound tasks issue an I/O operation once for every millisecond of CPU computing and that each I/O operation takes 10 milliseconds to complete. Also assume that the context-switching overhead is 0.1 millisecond and that all processes are long-running tasks. Describe the CPU utilization for a round-robin scheduler when:
- The time quantum is 1 millisecond
- The time quantum is 10 milliseconds

#### 6.22 Consider a system implementing multilevel queue scheduling. What strategy can a computer user employ to maximize the amount of CPU time allocated to the user’s process?
#### 6.23 Consider a preemptive priority scheduling algorithm based on dynamically changing priorities. Larger priority numbers imply higher priority. When a process is waiting for the CPU (in the ready queue, but not running), its priority changes at a rate . When it is running, its priority changes at a rate . All processes are given a priority of 0 when they enter the ready queue. The parameters  and  can be set to give many different scheduling algorithms.
- What is the algorithm that results from  >  > 0?
- What is the algorithm that results from  <  < 0?

---

#### 6.24 Explain the differences in how much the following scheduling algorithms discriminate in favor of short processes:
- FCFS
- RR
- Multilevel feedback queues

**FCFS**: All processes are equal, first come, first serve. Short process maybe stuck in queue if previours process take long time.

**RR**: All processes get equal time slice. Maybe favourite short process a little bit because they not need to wait long process to finish, the long process will need more round to finish

**Multiple feedback queues**: Short process will able to level up priority and get more chance to finish, because the avg time-quantum will favourite short process more. 


---

#### 6.25 Using the Windows scheduling algorithm, determine the numeric priority of each of the following threads.
- A thread in the REALTIME PRIORITY CLASS with a relative priority of NORMAL
- A thread in the ABOVE NORMAL PRIORITY CLASS with a relative priority of HIGHEST
- A thread in the BELOW NORMAL PRIORITY CLASS with a relative priority of ABOVE NORMAL

--- 

#### 6.26 Assuming that no threads belong to the REALTIME PRIORITY CLASS and that none may be assigned a TIME CRITICAL priority, what combination of priority class and priority corresponds to the highest possible relative priority in Windows scheduling?
#### 6.27 Consider the scheduling algorithm in the Solaris operating system for time-sharing threads.
- What is the time quantum (in milliseconds) for a thread with priority 15? With priority 40?
- Assume that a thread with priority 50 has used its entire time quantum without blocking. What new priority will the scheduler assign this thread?
- Assume that a thread with priority 20 blocks for I/O before its time quantum has expired. What new priority will the scheduler assign this thread?

#### 6.28 Assume that two tasks A and B are running on a Linux system. The nice values of A and B are −5 and +5, respectively. Using the CFS scheduler as a guide, describe how the respective values of vruntime vary between the two processes given each of the following scenarios:
- Both A and B are CPU-bound.
- A is I/O-bound, and B is CPU-bound.
- A is CPU-bound, and B is I/O-bound.

---

#### 6.29 Discuss ways in which the priority inversion problem could be addressed in a real-time system. Also discuss whether the solutions could be implemented within the context of a proportional share scheduler.

---

#### 6.30 Under what circumstances is rate-monotonic scheduling inferior to earliest-deadline-first scheduling in meeting the deadlines associated with processes?

---

#### 6.31 Consider two processes, P1 and P2 , where p1 = 50, t1 = 25, p2 = 75, and t2 = 30.
- Can these two processes be scheduled using rate-monotonic scheduling? Illustrate your answer using a Gantt chart such as the ones in Figure 6.16–Figure 6.19. 
- Illustrate the scheduling of these two processes using earliest-deadline-first (EDF) scheduling.

---

#### 6.32 Explain why interrupt and dispatch latency times must be bounded in a hard real-time system.

Because the real-time system need to be response for real-time event quickly and predictably.
- Dispatch latency must be bound, high-priority task must be switch in quick and execute on time.
- If interrupt latency is too high, the system may miss critical deadlines, leading to failure.