/*  
lower_bound 返回最小的满足 nums[i] >= target 的下标 i
如果数组为空，或者所有数都 < target，则返回 nums.size()
要求 nums 是非递减的，即 nums[i] <= nums[i + 1] 
*/
    
    //闭区间[left, right]
    int lower_bound_1(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1; 
        while (left <= right) { // 区间不为空
            // 循环不变量：nums[left-1] < target; nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) right = mid - 1; // 范围缩小到 [left, mid-1]
            else left = mid + 1; // 范围缩小到 [mid+1, right]
        }
        // 循环结束后 left = right+1
        // 此时 nums[left-1] < target 而 nums[left] = nums[right+1] >= target
        // 所以 left 就是第一个 >= target 的元素下标
        return left;//or right + 1;
    }

    //左闭右开[left,right)
    int lower_bound_2(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            //循环不变量：nums[left - 1] < target; nums[right] >= target
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        //循环结束后 left = right
        //此时,nums[left - 1] < target; nums[left] = nums[right] >= target
        return left; //or right
    }

    //左开右开（left, right）
    int lower_bound_3(vector<int>& nums, int target){
        int left = -1, right = nums.size();
        while(left + 1 < right){
            //循环不变量：nums[left] < target; nums[right] >= target
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) right = mid;
            else left = mid;
        }
        //循环结束后 left + 1 = right
        //此时,nums[left] < target; nums[left + 1] = nums[right] >= target
        return right; //or left + 1;
    } 
