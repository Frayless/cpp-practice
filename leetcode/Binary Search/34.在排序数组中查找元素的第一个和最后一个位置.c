class Solution {
    int lower_bound(vector<int>& nums, int target){//寻找最小端的数
        // [left, right]
        int left = 0, right = (int) nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid - 1;
            else left = mid + 1;
        }
        return left; //or right + 1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //时间复杂度：O(log n)
        //空间复杂度：O(1)
        int start = lower_bound(nums, target);
        //对于空数组{}，必须先判断start == nums.size(),用该条件捕获空数组或越界索引，如果先判断后一个条件，会由于数组越界而报错（Segmentation Fault）
        //短路行为：a || b, a true, 不判断b; a && b, a false, 不判断b;
        if(start == nums.size() || nums[start] != target) return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        
        return {start, end};
    }
};
