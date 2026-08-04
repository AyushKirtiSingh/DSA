class Solution {
public:
    void merge(vector<int> &arr,int st,int end,int mid){   //TIME COMPLEXITY : O(n)
    vector<int> temp;
    int i=st, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){     //for descending arr[i]>=arr[j] only this small change
            temp.push_back(arr[i]);
            i++;              //comparing and putting smaller values in temp and updating i and j
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);    //if any left side elements are not covered
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);    //if any right side elemnets are not covered
        j++;
    }

    for(int idx = 0;idx<temp.size();idx++){
        arr[idx + st] = temp[idx];         //copying sorted elements from temp to original array
    }
}

void mergesort(vector<int> &arr, int st, int end){   //TIME COMPLEXITY : O(nlogn) 
    if(st<end){                                      //SPACE COMPLEXITY : O(n)
        int mid = st + (end-st)/2;
        mergesort(arr,st,mid);   //left

        mergesort(arr,mid+1,end);  //right

        merge(arr,st,end,mid);   //calling of the function for the merging into sorted array
    }
}

    vector<int> sortArray(vector<int>& arr) {
        mergesort(arr,0,arr.size()-1);

        return arr;
        
    }
};