#include <linux/init.h>
#include <linux/module.h>
#include <hello1.h>

MODULE_DESCRIPTION("AK-2 LabWork7");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Denys Trishchuk IV-81");

static uint count = 1;
module_param(count, uint, S_IRUGO);

static int initter(void)
{
	return print_hello(count);
}

static void exitter(void)
{
	printk(KERN_ALERT "Goodbye, cruel world!\n");
}

module_init(initter);
module_exit(exitter);
