
#include <linux/linkage.h>
#include <linux/export.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/init.h>       /* Contains macros such as __init and __exit. */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/slab.h>
#include <linux/semaphore.h>
#include <linux/moduleparam.h>
#include <linux/miscdevice.h>
#include <linux/rtc.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");

static struct semaphore read;
static struct semaphore write;
static struct semaphore empty;
static struct semaphore full;
static int open;
int * pipe_buffer;
static int size_of_buffer;
static int buffer_index;
static int read_index = 0;
static int write_index = 0;

module_param(size_of_buffer, int, 0000);


static int char_open(struct inode *inode, struct file *file ) {

  printk(KERN_NOTICE "my_chardevice module opened\n");
  open = open + 1;
  return 0;
}




static ssize_t char_read(struct file* file_name, char* buff, ssize_t size, loff\
_t * ind){
  printk(KERN_NOTICE "Opened CHAR_READ kernel func \n");
  if(read_index > size_of_buffer) {
    return ENOMEM;
  }

  down_interruptible(&read);
  down_interruptible(&full);
  read_index %= size_of_buffer;
  if(copy_to_user(buff, pipe_buffer, sizeof(int)) != 0) {
    printk(KERN_ERR "Cannot copy to user space fully\n");
    return ENOMEM;
  }
  else {
    printk(KERN_NOTICE "Successfully wrote to user space!\n");
  }
  read_index = read_index +1;
  // printk(KERN_NOTICE "Printing read_index: %ld" read_index);                 
  buffer_index = buffer_index + 1;
  up(&read);
  up(&empty);
  return size;
}






static ssize_t char_write(struct file *file_name, const char __user *buff, size\
_t size, loff_t *ind) {
  printk(KERN_NOTICE "Accessing char_write() \n");
  if(write_index > size_of_buffer) {
    printk(KERN_ERR "Out of boundaries \n");
    return ENOMEM;
  }
  down_interruptible(&write);
  down_interruptible(&empty);
  write_index %= size_of_buffer;
  if(copy_from_user(pipe_buffer, buff, sizeof(int)) != 0) {
  printk(KERN_ERR "Copy to user func failed in char_write() \n");
  return ENOBUFS;
 }
  else {
   printk(KERN_NOTICE "Copy to user func worked in char_write() \n");
 }
write_index++;

buffer_index = buffer_index - 1;
up(&full);
up(&write);
return size;
}








static int char_close(struct inode* node, struct file* fileName ) {
  printk("Closing my_chardevice \n");
  open = open -1;
  return 0;
}




static const  struct file_operations my_device_rw = {
  .open = char_open,
  .read = char_read,
  .write = char_write,
  .release = char_close,
  .owner = THIS_MODULE
};


struct miscdevice numpipe =
{
  .name = "numpipe",
  .minor = MISC_DYNAMIC_MINOR,
  .fops = &my_device_rw
    };

static int __init misc_init(void) {
  int error = misc_register(&numpipe);
  if(error != 0) {
    printk(KERN_ERR "Cannot register device \n");
    return error;
  }
  printk("Iniitializing buffer/semaphores \n");
  sema_init(&empty, size_of_buffer);
  sema_init(&full, 0);
  sema_init(&read, 1);
  sema_init(&write, 1);
  pipe_buffer = kmalloc(sizeof(int) * size_of_buffer, GFP_KERNEL);
  buffer_index = size_of_buffer;
  open = 0;
  return open;
}

static void __exit misc_exit(void) {
  printk("Freeing my_chardevice data and deregistering\n");
  kfree(pipe_buffer);
  misc_deregister(&numpipe);
}

module_init(misc_init);
module_exit(misc_exit);

  printk("Iniitializing buffer/semaphores \n");
  sema_init(&empty, size_of_buffer);
  sema_init(&full, 0);
  sema_init(&read, 1);
  sema_init(&write, 1);
  pipe_buffer = kmalloc(sizeof(int) * size_of_buffer, GFP_KERNEL);
  buffer_index = size_of_buffer;
  open = 0;
  return open;
}

static void __exit misc_exit(void) {
  printk("Freeing my_chardevice data and deregistering\n");
  kfree(pipe_buffer);
  misc_deregister(&numpipe);
}

module_init(misc_init);
module_exit(misc_exit);
