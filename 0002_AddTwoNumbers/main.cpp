
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode* next) : val(x), next(next)
    {
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode node;
        auto result = &node;

        int carry = 0;
        // Adding carry > 0 check here just in case some edge cases like:
        // l1 = [8], l2 = [4]
        while (l1 || l2 || carry)
        {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int sum      = v1 + v2 + carry;
            carry        = sum / 10;
            sum          = sum % 10;
            result->next = new ListNode(sum);
            result       = result->next;

            // both checks are checking if current node is valid or not, otherwise it will throw accessing null pointer error
            // for example: l1 = [1,2,3,4], l2 = [5,6]
            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        return node.next;
    }
};