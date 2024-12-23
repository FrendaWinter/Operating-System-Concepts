# Chapter 6 exercises

#### 6.1 A CPU-scheduling algorithm determines an order for the execution of its scheduled processes. Given n processes to be scheduled on one processor, how many different schedules are possible? Give a formula in terms of n.

#### 6.2 Explain the difference between preemptive and nonpreemptive scheduling.

- In preemptive scheduling, the operating system can interrupt a running process and forcibly switch the CPU to another process. This is typically done to ensure fairness or to prioritize higher-priority tasks.
- In nonpreemptive scheduling, once a process has been assigned the CPU, it runs until it voluntarily releases the CPU (e.g., by completing its execution or entering a waiting state).

#### 6.3 Suppose that the following processes arrive for execution at the times indicated. Each process will run for the amount of time listed. In answering the questions, use nonpreemptive scheduling, and base all decisions on the information you have at the time the decision must be made.

a. What is the average turnaround time for these processes with the FCFS scheduling algorithm?
b. What is the average turnaround time for these processes with the SJF scheduling algorithm?
c. The SJF algorithm is supposed to improve performance, but notice that we chose to run process P1 at time 0 because we did not know that two shorter processes would arrive soon. Compute what the average turnaround time will be if the CPU is left idle for the first 1 unit and then SJF scheduling is used. Remember that processes P1 and P2 are waiting during this idle time, so their waiting time may increase. This algorithm could be called future-knowledge scheduling.