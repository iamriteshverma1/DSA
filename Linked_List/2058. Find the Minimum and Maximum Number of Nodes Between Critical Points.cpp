class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr;
        ListNode* prev;
        if(head -> next == nullptr || (head -> next) -> next == nullptr)
            return {-1, -1};
        curr = head -> next;
        int i = 2;
        prev = head;
        vector<int> ans;
        while(curr -> next != nullptr){
            if(curr -> val < prev -> val && curr -> val < (curr -> next)-> val)
                ans.push_back(i);
            if(curr -> val > prev -> val && curr -> val > (curr -> next)-> val)
                ans.push_back(i);
            i++;
            prev = prev -> next;
            curr = curr -> next;
        }
        if(ans.size() < 2)
            return {-1, -1};
        int minDistance = ans[1] - ans[0];
        for(int i = 1; i < ans.size() - 1; i++){
            if(ans[i + 1] - ans[i] < minDistance )
                minDistance = ans[i + 1] - ans[i];
        }

        return {minDistance, (ans[ans.size() -1] - ans[0])};
        
    }
};
