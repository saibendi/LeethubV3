class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0; int j = nums.size();
        while (i < j) {
            int mid = i + (j-i)/ 2;
            if (target <= nums[mid]) {
                j = mid; 
            }
            else {
                i = mid + 1;
            }
        }
        return i < nums.size() && nums[i] == target ? i : -1;
    }
};