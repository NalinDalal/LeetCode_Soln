/* 21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists. Return the head of the merged linked
list.


Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.*/

// traverse the list1 and list2 and compare the values
// if the value of list1 is less than value of list2, add it to new list
// else add list2 to new list
// repeat until both lists are empty

#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        temp->next = l1;
        l1 = l1->next;
      } else {
        temp->next = l2;
        l2 = l2->next;
      }
      temp = temp->next;
    }
    if (l1 != NULL) {
      temp->next = l1;
    } else {
      temp->next = l2;
    }
    return head->next;
  }
};

int main() {
  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  Solution s;
  ListNode* head = s.mergeTwoLists(l1, l2);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}

/* - Time complexity:O(max(m,n))
m,n size of both ll

- Space complexity:O(m+n)*/
