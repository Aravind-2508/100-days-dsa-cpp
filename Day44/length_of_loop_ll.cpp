int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }
