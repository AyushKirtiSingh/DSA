class Solution {
public:
    int merge(vector<int> &nums, int st, int end, int mid){
        vector<int> temp;
        int i=st, j=mid+1, invcount = 0;    //TC : O(nlogn)
        while(i<=mid && j<=end){
            if(nums[i]>2LL * nums[j]){
                invcount += mid-i+1;    //for checking reverse pairs putting it in diff while loop.
                j++;
            }           //this is the key step that makes this question different of using two while loop and deciding when i++ and when to do j++;
            else{
                i++;
            }
        }    

        i=st,j=mid+1;

        while(i<=mid && j<=end){   //after finding count using another while loop for merging sorted parts
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }


        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx=0;idx<temp.size();idx++){
            nums[idx+st] = temp[idx];
        }

        return invcount;
    }

    int mergesort(vector<int> &nums, int st, int end){
        if(st<end){
            long long mid = st + (end-st)/2;

            long long leftinvcount = mergesort(nums,st,mid);   //recursion is calculating the individual reverse pair count

            long long rightinvcount = mergesort(nums,mid+1,end);

            long long invcount = merge(nums,st,end,mid);

            return invcount + leftinvcount + rightinvcount;
        }

        return 0;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
        
    }
};