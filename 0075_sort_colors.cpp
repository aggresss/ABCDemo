/**
* Given an array with n objects colored red, white or blue, 
* sort them in-place so that objects of the same color are adjacent, 
* with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* Note: You are not suppose to use the library's sort function for this problem.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = partition(nums, low, high);
            quickSort(nums, low, mid - 1);
            quickSort(nums, mid + 1, high);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high], i = low, j;
        for (j = low; j < high; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[high], nums[i]);
        return i;
    }
};
