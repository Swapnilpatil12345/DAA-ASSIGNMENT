#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    vector<int> temp;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
        k++;
    }
    while(i<=mid){    
        temp.push_back(arr[i]);
        i++;
        k++;
    }
    while(j<=high){    
        temp.push_back(arr[j]);
        j++;
        k++;
    }
    
    int l=0;
    for(int z=low; z<=high; z++){
        arr[z]=temp[z-low];
    }
    // copy to original array
}
void mergeSort(vector<int>& arr,int low,int high){
    if(low==high)return;
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge( arr,low,mid,high);
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

    mergeSort(arr,0,size-1);

    cout<<endl;
    for(int i=0; i<size ;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}