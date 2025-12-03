#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int s, int e ){
    
        int pivot = arr[s];
        int count = 0;
        for(int i=s+1; i<=e; i++){
            if( arr[i] <= pivot )
                count++;
        }
        int pivot_idx = s+count;
        
        swap( arr[pivot_idx], arr[s] );
        
        int i=s;
        int j=e;
        while( i < pivot_idx && j > pivot_idx ){
            
            while( arr[i] <= pivot ){
                i++;
            }
            while( arr[j] > pivot ){
                j--;
            }
            if(i < pivot_idx && j > pivot_idx){
                swap( arr[i++], arr[j--] );
            }
            
        }
            

        
        return pivot_idx;
    
}

void quickSort( vector<int>&arr, int s, int e ){
    
    if( s>=e ){
        return ;
    }
    int p = partition( arr, s, e );
    quickSort( arr, s, p-1 );
    quickSort( arr, p+1, e );
    
}

int main() {
    
    vector<int>arr = {1,4,8,3,5,9,9};
    
    int s = 0;
    
    quickSort( arr, s, arr.size()-1 );
    
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
