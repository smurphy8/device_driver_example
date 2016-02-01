/* Device driver tutorial 
http://tldp.org/LDP/lkmpg/2.6/html/lkmpg.html#AEN181
*/

/*  
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h> /* Needed for the Macros */
#include <linux/moduleparam.h> /* command line args */
#include <linux/stat.h>

#define DRIVER_AUTHOR "Scott Murphy <scott.murphy@plowtech.net>" 
#define DRIVER_DESC "A sample driver"


/*  
 *  You can use strings, like this:
 */

/* 
 * Get rid of taint message by declaring code as GPL. 
 */
MODULE_LICENSE("GPL");

/*
 * Or with defines, like this:
 */
MODULE_AUTHOR(DRIVER_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */

/*  
 *  This module uses /dev/testdevice.  The MODULE_SUPPORTED_DEVICE macro might
 *  be used in the future to help automatic configuration of modules, but is 
 *  currently unused other than for documentation purposes.
 */
MODULE_SUPPORTED_DEVICE("testdevice");



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

