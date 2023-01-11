#include<bits/stdc++>
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *anshead = ans;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *newnode = new ListNode(sum);
            ans->next = newnode;
            ans = ans->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return anshead->next;
    }
};
