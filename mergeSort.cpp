class Solution {
public:

    void merge( vector<int>& nums, int s, int e ){

        int mid = s + (e-s)/2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *pehla = new int[len1];
        int *dusra = new int[len2];

        int k = s;
        for(int i=0; i<len1; i++){
            pehla[i] = nums[k++];
        }

        k = mid + 1;
        for(int i=0; i<len2; i++){
            dusra[i] = nums[k++];
        }

        int idx1 = 0;
        int idx2 = 0;
        k = s;

        while( idx1 < len1 && idx2 < len2 ){
            if( pehla[idx1] < dusra[idx2] ){
                nums[k++] = pehla[idx1++];
            }
            else{
                nums[k++] = dusra[idx2++];
            }
        }

        while( idx1 < len1 ){
            nums[k++] = pehla[idx1++];
        }

        while( idx2 < len2 ){
            nums[k++] = dusra[idx2++];
        }
    }

    void mergeSort( vector<int>& nums, int s, int e ){

        if( s>=e ){
            return;
        }

        int mid = s + (e-s)/2;

        mergeSort( nums, s, mid );
        mergeSort( nums, mid+1, e );

        merge( nums, s, e );

    }

    vector<int> sortArray(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size() - 1;

        mergeSort( nums, s, e );

        return nums;

    }
};
