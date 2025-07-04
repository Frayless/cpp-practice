class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int left = 0, right = length - 1;
        int h = 0, maxwater = 0;
        bool flag = true;
        while(left < right){
            if(height[left] >= height[right]) {
                h = height[right];
                flag = true;
            }
            else{
                h = height[left];
                flag = false;
            } 
            int curwater = (right - left) * h;
            if(curwater > maxwater) maxwater = curwater;
            if(flag) right -= 1;
            else left += 1;
        }
        return maxwater;
        
    }
};
