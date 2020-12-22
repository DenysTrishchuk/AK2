#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/slab.h>
#define DEBUG

MODULE_DESCRIPTION("AK-2 LabWork7");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Denys Trishchuk IV-81");

static struct head_list *head;

void clear_list(void)
{
	struct head_list *temp1;
	struct head_list *temp2;

	temp1 = head;

	while (temp1 != NULL) {
		temp2 = temp1->next;
		kfree(temp1);
		temp1 = temp2;
	}
}

int print_hello(uint count)
{
	int i;
	struct head_list *temp1;
	struct head_list *temp2;

	BUG_ON(count > 10);
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
		if (i == 7)
			temp1 = NULL;

		if (ZERO_OR_NULL_PTR(temp1))
			goto error;

		temp1->time = ktime_get();
		pr_info("Hello, world!\n");
		temp1->end_time = ktime_get();
		temp2 = temp1;
		temp1 = temp1->next;
	}
	kfree(temp2->next);
	temp2->next = NULL;
	return 0;

error:
	pr_err("Out of memory\n");
	clear_list();
	return -ENOMEM;
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

	pr_debug("Print list is started");
	while (temp_first != NULL) {
		pr_info("Time spent %lld", temp_first->end_time - temp_first->time);
		temp_second = temp_first;
		temp_first = temp_second->next;
		kfree(temp_second);
	}
	pr_debug("Print list is finished");
	pr_info("hello1 exit");
}

module_init(initter);
module_exit(exitter);
