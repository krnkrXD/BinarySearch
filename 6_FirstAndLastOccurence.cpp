#include <bits/stdc++.h>
using namespace std;
// first occurence - left part of array prefer
// last occurence - right part of array prefers

int firstPosition(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1;
    int pos = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            pos = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return pos;
}

int lastPosition(vector<int>& arr, int n, int k){
    int low = 0, high = n - 1, pos = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == k){
            pos = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return pos;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    int first = firstPosition(arr, n, k);
    if(first == -1){ // element not present in array.
        return {-1, -1};
    }
    int last = lastPosition(arr, n, k);
    return {first, last};
}
// TC - O(log2N)