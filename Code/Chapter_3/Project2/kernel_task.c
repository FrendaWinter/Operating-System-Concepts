#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module to iterate through tasks");
MODULE_VERSION("1.0");

static int __init task_iterator_init(void)
{
    struct task_struct *task;

    pr_info("Starting task iterator module...\n");

    for_each_process(task)
    {
        pr_info("Task: %s, PID: %d\n",
                task->comm, task->pid);
    }

    return 0;
}

static void __exit task_iterator_exit(void)
{
    pr_info("Exiting task iterator module...\n");
}

module_init(task_iterator_init);
module_exit(task_iterator_exit);
