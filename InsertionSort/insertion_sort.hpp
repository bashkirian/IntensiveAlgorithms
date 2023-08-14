#pragma once

// https://leetcode.com/problems/insertion-sort-list/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *insertionSortList(ListNode *head) {
    ListNode *newHead = NULL;
    // итерируемся по начальному листу
    while (head) {
      // создаем новую ноду из текущей ноды
      ListNode *temp = head;
      head = head->next;
      temp->next = NULL;

      // задаем начальную ноду
      if (newHead == NULL)
        newHead = temp;
      // если больше, то просто добавляем в конец
      else if (newHead->val >= temp->val) {
        temp->next = newHead;
        newHead = temp;
      }
      // иначе итерируемся пока не найдем, куда вставить
      else {
        ListNode *root = newHead;
        {
          while (root->next) {
            if (temp->val > root->val and temp->val <= root->next->val) {
              temp->next = root->next;
              root->next = temp;
              break;
            }
            root = root->next;
          }
          if (root->next == NULL)
            root->next = temp;
        }
      }
    }
    return newHead;
  }
};
