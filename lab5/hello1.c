#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/types.h>
MODULE_DESCRIPTION("AK-2 LabWork5");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Denys Trishchuk IV-81");

EXPORT_SYMBOL(print_hello);

static int print_hello(uint count)
{
    int i;
    if (count == 0) {
        pr_warn("Warning!\nValue is 0.\n");
    }
    
    else if (count >= 5 && count <= 10) {
        pr_warn("Warning!\nValue is from 5 to 10.\n");
    }
    
    else if (count > 10) {
        pr_err("Error!\nValue greater 10.");
        
        return -EINVAL;
    }
    
    for (i = 0; i < count; i++) {
    pr_info("Hello, world!\n");
    }
    
    return 0;
}

static int __init initter(void) {
    pr_info("hello1 init");
    
    return 0;
}

static void __exit exitter(void) {
    pr_info("hello1 exit");
}

module_init(initter);
module_exit(exitter);
