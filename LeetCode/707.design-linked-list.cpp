/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};
class MyLinkedList
{
    Node *head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        Node *cur = head;
        while (cur && index > 0)
        {
            cur = cur->next;
            index--;
        }
        return index > 0 || cur == nullptr ? -1 : cur->val;
    }
    void addAtHead(int val)
    {
        Node *p = new Node(val);
        p->next = head;
        head = p;
        size++;
    }
    void addAtTail(int val)
    {
        Node *p = new Node(val);
        size++;
        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            Node *cur = head;
            while (cur && cur->next)
            {
                cur = cur->next;
            }
            cur->next = p;
        }
    }
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            size++;
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            size++;
            return;
        }
        Node *cur = head, *pre;
        while (cur && index > 0)
        {
            pre = cur;
            cur = cur->next;
            index--;
        }
        if (index == 0)
        {
            Node *p = new Node(val);
            pre->next = p;
            p->next = cur;
            size++;
        }
    }
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }
        else
        {
            Node *cur = head, *pre;
            while (cur && index > 0)
            {
                pre = cur;
                cur = cur->next;
                index--;
            }
            if (index == 0 && cur != nullptr)
            {
                Node *tmp = cur;
                pre->next = cur->next;
                delete tmp;
                size--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
