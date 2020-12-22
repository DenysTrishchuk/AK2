#include <linux/ktime.h>
struct head_list {
    struct head_list *next;
    ktime_t time;
    ktime_t end_time;
};

int print_hello(uint count);
