// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [jack]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2017/03/02 jack]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i=2; i<=data.size(); i++) {
        int x=data[i-1];
        int j=i-1;
        while (x<data[j-1]&&j>0) {
            data[j]=data[j-1];
            data[j-1]=x;
            j-=1;
        }
        
    }
    
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    SortSubVector(data, 1, data.size());
}

// Sort subvector
void SortTool::SortSubVector(vector<int>& data, int low, int high) {
    // Function : Sort subvector
    // TODO : Please complete SortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    if (high>low) {
        int middle1=(high+low)/2;
        int middle2=middle1+1;
        SortSubVector(data, low, middle1);
        SortSubVector(data, middle2, high);
        Merge(data, low, middle1, middle2, high);
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    int n1=middle1-low+1;
    int n2=high-middle2+1;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    for (int i=1; i<=n1; i++) {
        L[i-1]=data[low+i-2];
    }
    for (int j=1; j<=n2; j++) {
        R[j-1]=data[middle2+j-2];
    }
    L[n1]=9999999;
    R[n2]=9999999;
    int i=1;
    int j=1;
    for (int k=low; k<=high; k++) {
        if (L[i-1]<R[j-1]) {
            data[k-1]=L[i-1];
            i=i+1;
        }else{
            data[k-1]=R[j-1];
            j=j+1;
        }
    }
    
    
    
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    Build_Max_Heap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size(); i > 1; i--) {
        swap(data[0],data[i-1]);
        heapSize--;
        Max_Heapify(data,1);
    }
}

//Max heapify
void SortTool::Max_Heapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    int l=root*2;
    int r=root*2+1;
    int largest;
    if (l<=heapSize&&data[l-1]>data[root-1]) {
        largest=l;
    }else{
        largest=root;
    }if (r<=heapSize&&data[r-1]>data[largest-1]) {
        largest=r;
    }if (largest!=root) {
        swap(data[largest-1],data[root-1]);
        Max_Heapify(data, largest);
    }
}

//Build max heap
void SortTool::Build_Max_Heap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete Build_Max_Heap code here
    for (int i=heapSize/2; i>=1; i--) {
        Max_Heapify(data,i);
    }
}
