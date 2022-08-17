/*
 * lkm_oper.c - The simplest kernel module.
 */

#include <linux/kernel.h>      /* for pr_info() */
#include <linux/module.h>      /* all modules */
#include <linux/init.h>        /* macros */
#include <linux/moduleparam.h> /* using params */
#include <linux/stat.h>

/*
 * The static variables using by program
 *
 */
static int a = 12;
static int b = 13;


/*
 * module_param(param_name, param_type, param_permissions bits)
 * @param_name : is the parameters name.
 * @param_type is its data type.
 * @param_permissions : is the permissions bits,
 *
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */
module_param(a, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(b, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

MODULE_PARM_DESC(a, "An integer");
MODULE_PARM_DESC(b, "An integer");

/*
 * 
 *
 */
static void begin(void)
{
    pr_info("Begin run program \n");
}

/*
 * 
 *
 */
static void end(void)
{
    pr_info("End run program \n");
}

/*
 * 
 *
 */
static int sum(int a, int b)
{
    return a+b;
}

/*
 * 
 *
 */
static int prod(int a, int b)
{
    return a*b;
}

int init_module(void)
{
    begin();
    pr_info("Sum of %d and %d equals : %d \n",a, b, sum(a, b));
    pr_info("Prod of %d per %d equals : %d \n",a, b,prod(a, b));
    end();
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

void cleanup_module(void)
{
    pr_info("Exiting programm successfully \n");
}

MODULE_LICENSE("GPL");
