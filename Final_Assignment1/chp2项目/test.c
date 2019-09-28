 #include <linux/string.h>
 #include <linux/kernel.h> /*Needed by all modules*/
 #include <linux/module.h> /*Needed for KERN_* */
 #include <linux/init.h> /* Needed for the macros */
 #include <linux/slab.h>
 #include <linux/gfp.h>
 struct person 
 { 
     int day; 
     int month;
     int year;
     struct list_head list; 
 };
struct person *pperson; 
struct person person_head; 
struct list_head *pos, *next;
int main(int argc, char* argv[]) 
{ 
    printk("Loading module\n"); 
    int i;
    // 初始化双链表的表头 
    INIT_LIST_HEAD(&person_head.list); 
    // 添加节点
    for (i=0; i<5; i++)
    {
        pperson = kmalloc(sizeof(*pperson), GFP_KERNEL);
        pperson->day = (i+1)*3;
        pperson->month = (i+1)*2;
        pperson->year = i+1;
        // 将节点链接到链表的末尾 
        // 如果想把节点链接到链表的表头后面，则使用 list_add
        list_add_tail(&(pperson->list), &(person_head.list));
    }

    // 遍历链表
    printk("==== iterator d-link ====\n"); 
    list_for_each(pos, &person_head.list) 
    { 
        pperson = list_entry(pos, struct person, list); 
        printk("year:%d,month:%d age:%d\n", pperson->year, pperson->month, pperson->day); 
    } 

}
 
static void test_exit(void)
{
	printk("Removing Module\n");
	// 释放资源
	list_for_each_safe(pos, next, &person_head.list)
    {
        pperson = list_entry(pos, struct person, list); 
        list_del_init(pos); 
        kfree(pperson); 
    }    
	return 0;  
}

module_init(main);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("test Module");
MODULE_AUTHOR("2017171222黎卓武");
