// Given a linked list, swap every two adjacent nodes and return its head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* swapPairs(ListNode* head)
{
  if (head == nullptr)
    return head;

  ListNode* left = head;
  ListNode* right = left->next;
  ListNode* leftLeft = nullptr;

  int listLength = 1;

  while (left->next != nullptr)
  {
    left = left->next;
    ++listLength;
  }

  if (listLength == 1)
    return head;

  left = head;

  for (int i = 0; i < listLength / 2; ++i)
  {
    left->next = right->next;
    right->next = left;

    if (i == 0)
    {
      head = right;
    }
    else
    {
      leftLeft->next = right;
    }
    leftLeft = left;

    if (i < listLength / 2 - 1)
    {
      left = left->next;
      right = left->next;
    }
  }

  return head;
}
