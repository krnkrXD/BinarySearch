#include<bits/stdc++.h>
using namespace std;

// either left or right part is sorted
// min element is always at the unsorted part.
// if left is sorted, take the min of left part which is arr[low], and move to the right.
// else right is sorted, take the min of right which is arr[mid], and move to the left.
int findMin(vector<int>& arr){
    int n = arr.size();
    int low = 0, high = n - 1, ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){ // left part is sorted
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{   // right part is sorted
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}