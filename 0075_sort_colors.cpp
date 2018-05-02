/**
* Given an array with n objects colored red, white or blue, 
* sort them in-place so that objects of the same color are adjacent, 
* with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* Note: You are not suppose to use the library's sort function for this problem.
*/

class Solution1 {
public:
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
    void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = partition(nums, low, high);
            quickSort(nums, low, mid - 1);
            quickSort(nums, mid + 1, high);
        }
    }
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int len = right - left + 1;
        int index = 0, i = left, j = mid + 1;
        vector<int> vec;
        while (i<= mid && j <= right) {
            vec.push_back(nums[i] <= nums[j] ? nums[i++] : nums[j++]);
        }
        while (i <= mid) {
            vec.push_back(nums[i++]);
        }
        while (j <= right) {
            vec.push_back(nums[j++]);
        }
        for (int k = 0; k < len; k++) {
            nums[left++] = vec[k];
        }
    }
    void mergeSortRecursion(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = (left + right)/2;
            mergeSortRecursion(nums, left, mid);
            mergeSortRecursion(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
        return;
    }
    void sortColors(vector<int>& nums) {
        mergeSortRecursion(nums, 0, nums.size()-1);
    }
};
