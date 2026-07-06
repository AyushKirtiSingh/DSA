class Solution {
public:
    vector <int> newnums;
    int minMaxGame(vector<int>& nums) {
        
        if(nums.size()==1){
                return nums[0];
        }
        
        
        while(nums.size()>1){
            
            newnums.resize(nums.size()/2) ;
            for(int i=0;i<newnums.size();i++){
                if(i%2==0){
                newnums[i]=min(nums[2*i], nums[2 * i +1]);
            }
                else if(i%2!=0){
                newnums[i] = max(nums[2*i],nums[2*i+1]);
            }
            
            }
            nums = newnums;
            
                        

        }
        return newnums[0];
        
        
        
        
        

        
    }
};