#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/slab.h>

MODULE_DESCRIPTION("AK-2 LabWork6");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Denys Trishchuk IV-81");

static struct head_list *head;

int print_hello(uint count)
{
	int i;
	struct head_list *temp1;
	struct head_list *temp2;

	head = kmalloc(sizeof(struct head_list *), GFP_KERNEL);
	temp1 = head;
	if (count == 0) {
		pr_warn("Warning!\nValue is 0.\n");
	} else if (count >= 5 && count <= 10) {
		pr_warn("Warning!\nValue is from 5 to 10.\n");
	} else if (count > 10) {
		pr_err("Error!\nValue greater 10.");
		return -EINVAL;
	}

	for (i = 0; i < count; i++) {
		temp1->next = kmalloc(sizeof(struct head_list *), GFP_KERNEL);
		temp1->time = ktime_get();
		pr_info("Hello, world!\n");
		temp1->end_time = ktime_get();
		temp2 = temp1;
		temp1 = temp1->next;
	}
	kfree(temp2->next);
	temp2->next = NULL;
	return 0;
}
EXPORT_SYMBOL(print_hello);

static int __init initter(void)
{
	pr_info("hello1 init");
	return 0;
}

static void __exit exitter(void)
{
	struct head_list *temp_first = head;
	struct head_list *temp_second = temp_first;

	while (temp_first != NULL) {
		pr_info("Time spent %lld", temp_first->end_time - temp_first->time);
		temp_second = temp_first;
		temp_first = temp_second->next;
		kfree(temp_second);
	}
	pr_info("hello1 exit");
}

module_init(initter);
module_exit(exitter);
