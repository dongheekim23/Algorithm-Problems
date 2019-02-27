// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
  if (l1 == nullptr && l2 == nullptr)
    return nullptr;
  else if (l1 == nullptr && l2 != nullptr)
    return l2;
  else if (l1 != nullptr && l2 == nullptr)
    return l1;

  ListNode* p1 = l1;
  ListNode* p2 = l2;

  bool biggerl1 = true;
  p1->val > p2->val ? true : false;

  ListNode* newList = new ListNode(biggerl1 == true ? p2->val : p1->val);
  ListNode* pCurr = newList;

  biggerl1 == true ? p2 = p2->next : p1 = p1->next;

  while (p1 || p2)
  {
    if (p1 && p2)
    {
      if (p1->val > p2->val)
      {
        pCurr->next = new ListNode(p2->val);
        pCurr = pCurr->next;
        p2 = p2->next;
      }
      else
      {
        pCurr->next = new ListNode(p1->val);
        pCurr = pCurr->next;
        p1 = p1->next;
      }
    }
    else
    {
      if (p1)
      {
        pCurr->next = new ListNode(p1->val);
        pCurr = pCurr->next;
        p1 = p1->next;
      }
      else
      {
        pCurr->next = new ListNode(p2->val);
        pCurr = pCurr->next;
        p2 = p2->next;
      }
    }
  }

  return newList;
}
