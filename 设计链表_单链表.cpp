class MyLinkedList {
public:
    
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    ListNode *head;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if (index < 0 || head == NULL) return -1;
        
        int i = 0;
        ListNode *temp = head;
        
        while(i < index && temp->next != NULL)
        {
            temp = temp->next;
            i++;
            if (i == index) break;
        }
        
        if (i == index) return temp->val;
        else    return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        if (head == NULL)// 原链表没有结点 
        {
            head = new ListNode(val);
        }
        else // 原链表有结点
        {
            ListNode *temp = new ListNode(val);
            temp->next = head;
            head = temp;
        } 
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        ListNode *temp = head;
        
        if(temp == NULL) temp = new ListNode(val); // 原链表没有结点
        else
        {
            // 原链表有结点，先找到到链尾再添加
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new ListNode(val);
        }  
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if (index < 0) return;
        if (head == NULL)
        {
            if (index > 0)
            { 
                return;
            }
            else
            {
                head = new ListNode(val);
                return;
            }
        }

        int i = 0;
        ListNode *temp = head;
        ListNode *last = NULL;

        // 查找待插入结点及其上一个结点
        while(i < index && temp->next != NULL)
        {
            last = temp;
            temp = temp->next;
            i++;
            
            if (i == index) break;
        }
        
        if (i == index)    // 在待插入结点前插入
        {
            if (i == 0) // 在头结点后插入
            {
                temp = new ListNode(val);
                temp->next = head;
                head = temp;
            }
            else // 在其他位置插入
            { 
                last->next = new ListNode(val);
                last->next->next = temp;
            }
        } 
        else if (i == index - 1)    // 在链表尾插入
        {
            temp->next = new ListNode(val);
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if (index < 0 || head == NULL) return;
        
        int i = 0;
        ListNode *temp = head;
        ListNode *last = NULL;

        // 查找待删除结点及其上一个结点
        while(i < index && temp->next != NULL)
        {
            last = temp;
            temp = temp->next;
            i++;
            
            if (i == index) break;
        }
        
        if (i == index)    
        {
            if (i == 0) // 删除头结点
            {
                delete head;
                head = NULL;
            }
            else  // 删除其它结点
            {
                last->next = temp->next;
                delete temp;
            }
        } 
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */