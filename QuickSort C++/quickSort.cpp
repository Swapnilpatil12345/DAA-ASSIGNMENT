// Quick sort

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
        int pivot = arr[low];
        int i= low;
        int j= high;
    while(i<j){
        
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        // swap logic; 
        if(i<j){
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j] = temp;
        }
        
    }
    int temp1 = arr[low];
    arr[low]=arr[j];
    arr[j]=temp1;
    return j;
}
void quicksort(vector<int>& arr, int low, int high){
    if(low<high){
        int pivotInd = partition(arr,low,high);
        quicksort(arr,low,pivotInd-1);
        quicksort(arr,pivotInd+1,high);
    }
}
int main(){
    int size;
    cin>>size;
     
    vector<int> arr(size);

    for(int i=0; i<size ;i++){
        cin>>arr[i];
    }
    for(int i=0; i<size ;i++){
        cout<<arr[i]<<" ";
    }

    quicksort(arr,0,size-1);

    cout<<endl;
    for(int i=0; i<size ;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}