// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseKGroup(ListNode* head, int k)
{
  if (head == nullptr)
    return head;

  if (k == 1)
    return head;

  ListNode* pHead = head;
  ListNode* pNext = nullptr;

  ListNode* pLeft = head;
  ListNode* pRight = pLeft->next;

  ListNode* pRegionEnd = nullptr;

  int length = 1;
  ListNode* pTrueHead = head;

  while (pTrueHead->next != nullptr)
  {
    pTrueHead = pTrueHead->next;
    ++length;
  }

  if (k > length)
    return head;

  pTrueHead = head;

  for (int x = 0; x < length / k; ++x)
  {
    for (int i = 0; i < k - 1; ++i)
    {
      pNext = pRight->next;
      pRight->next = pHead;
      pLeft->next = pNext;
      pHead = pRight;

      pRight = pLeft->next;
    }

    if (x == 0)
      pTrueHead = pHead;
    else
    {
      pRegionEnd->next = pHead;
    }

    pRegionEnd = pLeft;
    pLeft->next = pRight;
    pLeft = pHead = pRight;
    if (pRight != nullptr)
      pRight = pRight->next;
  }

  return pTrueHead;
}
