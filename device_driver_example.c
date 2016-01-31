/* Device driver tutorial 
http://tldp.org/LDP/lkmpg/2.6/html/lkmpg.html#AEN181
*/

/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h> /* Needed for the Macros */
#define DRIVER_AUTHOR "Scott Murphy <scott.murphy@plowtech.net>" 
#define Driver_DESC "A sample driver"

int hello_2_init(void)
{
	printk(KERN_INFO "Hello world 1.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void hello_2_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}



module_init(hello_2_init);
module_exit(hello_2_exit);
