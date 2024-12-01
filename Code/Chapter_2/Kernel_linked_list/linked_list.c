// In the module entry point, create a linked list containing five struct birthday
// elements. Traverse the linked list and output its contents to the kernel log buffer.
// Invoke the dmesg command to ensure the list is properly constructed once the
// kernel module has been loaded.
// In the module exit point, delete the elements from the linked list and return
// the free memory back to the kernel. Again, invoke the dmesg command to check
// that the list has been removed once the kernel module has been unloaded.

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>

int simple_init(void);
void simple_exit(void);

struct birthday {
    int day;
    int month;
    int year;
    struct list_head list;
};

static LIST_HEAD(birthday_list);

// Function to create a new birthday and add it to the list
static void add_birthday(int day, int month, int year) {
    struct birthday *person;
    person = kmalloc(sizeof(*person), GFP_KERNEL); // Allocate memory
    if (!person) {
        printk(KERN_INFO "Failed to allocate memory for birthday struct\n");
        return;
    }

    person->day = day;
    person->month = month;
    person->year = year;
    INIT_LIST_HEAD(&person->list); // Initialize the list pointer

    list_add_tail(&person->list, &birthday_list); // Add to the tail of the list
    // printk(KERN_INFO "Added: %02d/%02d/%d\n", day, month, year);
}

// Function to delete all birthdays from the list
static void delete_birthdays(void) {
    struct birthday *ptr, *next

    list_for_each_entry_safe(person, tmp, &birthday_list, list) {
        printk(KERN_INFO "Deleting: %02d/%02d/%d\n", ptr->day, ptr->month, ptr->year);
        list_del(&ptr->list);
        kfree(ptr);           // Free allocated memory
    }
}

/* This function is called when the module is loaded. */
int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    // Add five birthdays to the list
    add_birthday(1, 1, 2000);
    add_birthday(14, 2, 1995);
    add_birthday(20, 10, 1980);
    add_birthday(31, 12, 1999);
    add_birthday(15, 7, 1975);

    // Traverse the list and print each birthday
    struct birthday *person;
    list_for_each_entry(person, &birthday_list, list) {
        printk(KERN_INFO "Added: %02d/%02d/%d\n", person->day, person->month, person->year);
    }
    return 0;
}
/* This function is called when the module is removed. */
void simple_exit(void)
{
    delete_birthdays(); // Clean up the list
    printk(KERN_INFO "Removing Module\n");
}
/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");