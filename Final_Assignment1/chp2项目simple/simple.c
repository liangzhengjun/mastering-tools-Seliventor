#include <linux/kernel.h> /*Needed by all modules*/
#include <linux/module.h> /*Needed for KERN_* */
#include <linux/init.h> /* Needed for the macros */


static int simple_init(void)
{
  printk(KERN_INFO "Loading Module\n");
  return 0;
}


static void simple_exit(void)
{
  printk("Removing Module\n");
}

/* main module function*/
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("LZW");
