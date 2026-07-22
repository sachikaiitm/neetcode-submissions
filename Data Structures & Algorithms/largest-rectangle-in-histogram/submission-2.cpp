class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stack;
        vector<int> right(n , n);
        vector<int> left(n , -1);

        for(int i = n - 1; i >= 0; i--){
            if(!stack.empty() && heights[stack.top()] >= heights[i]){
                while(!stack.empty() && heights[stack.top()] >= heights[i]){
                    stack.pop();
                }
            }
            if(!stack.empty()){
                right[i] = stack.top();
            }
            stack.push(i);
        }

        while(!stack.empty()) stack.pop();

        for(int i = 0; i < n; i++){
            if(!stack.empty() && heights[stack.top()] >= heights[i]){
                while(!stack.empty() && heights[stack.top()] >= heights[i]){
                    stack.pop();
                }
            }
            if(!stack.empty()){
                left[i] = stack.top();
            }
            stack.push(i);
        }


        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        return maxArea;
    }

};
