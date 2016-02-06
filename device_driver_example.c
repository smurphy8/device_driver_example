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



























static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;
/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");



/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");








int hello_init(void)
{
        

  /* 
   * A non 0 return means init_module failed; module can't be loaded. 
   */
  int i;
  printk(KERN_INFO "Hello,world 5 \n=====================================\n");
  printk(KERN_INFO "myshort is a short integer: %hd\n", myshort);
  printk(KERN_INFO "myint is an integer: %d\n", myint);
  printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
  printk(KERN_INFO "mystring is a string: %s\n", mystring);
  for (i = 0; i < (sizeof myintArray / sizeof (int)); i++)
    {
      printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);
    }
  printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
	
  return 0;
}

void hello_exit(void)
{
  printk(KERN_INFO "Goodbye world !.\n");
}



module_init(hello_init);
module_exit(hello_exit);

