struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode print;
    struct ListNode* printk = &print;
    while(list1 && list2){
        if(list1 -> val < list2 -> val){
            printk -> next = list1;
            list1 = list1 -> next;
        }else{
            printk -> next = list2;
            list2 = list2 -> next;
        }
        printk = printk -> next;
    }
    printk -> next = list1 ? list1:list2;
    return print.next;
}