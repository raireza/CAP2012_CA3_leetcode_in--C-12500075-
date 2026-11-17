class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        // Put all values into the min heap
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        // Create the merged linked list
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            curr->next = new ListNode(pq.top());
            pq.pop();

            curr = curr->next;
        }

        return dummy.next;
    }
};
