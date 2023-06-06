#include<bits/stdc++.h>
using namespace std;
// we know one thing either left part[low...mid-1] is sorted
// or right part [mid+1...high] is sorted
// identify the sorted part and search the k
int search(vector<int>& arr, int n, int k){
    // Return the position of K in ARR else return -1.
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            return mid;
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
