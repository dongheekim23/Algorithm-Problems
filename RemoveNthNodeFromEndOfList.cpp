// Given a linked list, remove the n-th node from the end of list and return its head.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  if (head == nullptr)
    return head;

  ListNode* right = head;

  int listLength = 1;

  while (right->next != nullptr)
  {
    right = right->next;
    ++listLength;
  }

  if (n == listLength)
  {
    ListNode* temp = head;
    head = head->next;
    delete temp;

    return head;
  }
  else if (n > listLength)
    return head;

  ListNode* left = head;

  for (int i = 0; i < listLength - n - 1; ++i)
  {
    left = left->next;
  }

  ListNode* temp = left->next;
  right = temp->next;
  delete temp;
  left->next = right;

  return head;
}
