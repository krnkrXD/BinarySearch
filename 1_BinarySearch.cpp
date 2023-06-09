#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// TC - O(log2N)

int search_recursion(vector<int>& nums, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low + high) / 2;
    if(nums[mid] == target) return mid;
    else if(nums[mid] < target) search_recursion(nums, mid + 1, high, target);
    else search_recursion(nums, low, mid - 1, target);
}
// TC - O(log2N)