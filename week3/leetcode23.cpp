/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size() - 1);
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        if (left == right) {
            return lists[left];
        }
        int mid = (left + right) / 2;
        // 分治
        ListNode *list1 = mergeLists(lists, left, mid);
        ListNode *list2 = mergeLists(lists, mid + 1, right);
        ListNode dummyHead = ListNode();
        ListNode *rear = &dummyHead;
        // 合并两个子问题的链表
        while (list1 != nullptr || list2 != nullptr) {
            if (list2 == nullptr || (list1 != nullptr && list1->val <= list2->val)) {
                rear->next = list1;
                list1 = list1->next;
                rear = rear->next;
            } else {
                rear->next = list2;
                list2 = list2->next;
                rear = rear->next;
            }
        }

        return dummyHead.next;
    }
};