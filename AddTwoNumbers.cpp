/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* sumList = new ListNode(0);
    ListNode* currIt = sumList;

    ListNode* it1 = l1;
    ListNode* it2 = l2;

    bool list1Done = false;
    bool list2Done = false;

    int mov1 = 0;
    int mov2 = 0;
    bool overflow = false;

    while (!(list1Done && list2Done))
    {
      //overflow = false;

      if (!list1Done)
        currIt->val += it1->val;
      if (!list2Done)
        currIt->val += it2->val;

      if (currIt->val > 9)
      {
        overflow = true;
        currIt->val -= 10;
      }
      else
      {
        overflow = false;
      }

      if (overflow)
      {
        currIt->next = new ListNode(1);
        currIt = currIt->next;
      }

      if (it1->next != nullptr)
      {
        ++mov1;
        it1 = it1->next;
      }        
      else
        list1Done = true;

      if (it2->next != nullptr)
      {
        ++mov2;
        it2 = it2->next;
      }
      else
        list2Done = true;

      if(!overflow && !(list1Done && list2Done))
      {
        currIt->next = new ListNode(0);
        currIt = currIt->next;
      }
    }

    return sumList;
}
