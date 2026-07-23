class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                maxHeap.push({count[i], i});
            }
        }

        queue<pair<int, pair<int, int>>> coolDown;

        int time = 0;

        while(!maxHeap.empty() || !coolDown.empty()){
            time++;
            if(!maxHeap.empty()){
                pair<int, int> curr = maxHeap.top();
                curr.first--;
                maxHeap.pop();
                if(curr.first > 0){
                    coolDown.push({time + n, curr});
                }
            }
            if(!coolDown.empty()){
                if(coolDown.front().first <= time){
                    pair<int, int> curr = coolDown.front().second;
                    coolDown.pop();
                    if(curr.first > 0){
                        maxHeap.push(curr);
                    }
                }
            }
        }

        return max(int(tasks.size()), time);
    }
};