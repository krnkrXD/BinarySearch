#include<bits/stdc++.h>
using namespace std;
// [1,2,3,4,4,5]
// [5,4,4,1,2,3]
// arr[low] == arr[mid] == arr[high], our conditions fails

bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[low] == arr[mid] && arr[mid] == arr[high]){ //all 3 are eql
            low++;
            high--;
        }
        else if(arr[low] <= arr[mid]){ // left part is sorted
            if(arr[low] <= k && k <= arr[mid]){ // [arr[low]... k .. arr[mid]]
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{   // right part is sorted
            if(arr[mid] <= k && k <= arr[high]){ // [arr[mid]... k ... arr[high]]
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

