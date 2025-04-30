// Time Complexity : O(nlog n)
// Space Complexity : O(n)  
// Did this code successfully run on Leetcode : Yes


// Your code here along with comments explaining your approach:
// 1. Create a max heap and add all elements.
// 2. Pop elements k times.

class Solution {
public:
    void heapify(vector<int>& nums,int i){
        int n=nums.size();
        if((2*i+1)>=n){
            return;
        }
        else{
            if((2*i+2)>=n){
                if(nums[2*i+1]>nums[i]){
                    int t=nums[2*i+1];nums[2*i+1]=nums[i];nums[i]=t;
                }
            }
            else{
                if(nums[2*i+1]>nums[i] && nums[2*i+1]>=nums[2*i+2]){
                    int t=nums[2*i+1];nums[2*i+1]=nums[i];nums[i]=t;
                    heapify(nums,2*i+1);
                }else if(nums[2*i+2]>nums[i] && nums[2*i+2]>=nums[2*i+1]){
                    int t=nums[2*i+2];nums[2*i+2]=nums[i];nums[i]=t;
                    heapify(nums,2*i+2);
                }
            }
        }
    }
    void buildheap(vector<int>& nums){
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            heapify(nums,i);
        }
    }
    int getMax(vector<int>& nums){
        int n=nums.size();
        int t=nums[0];
        nums[0]=nums[n-1];
        nums.pop_back();
        cout<<' '<<nums.size();
        heapify(nums,0);
        return t;
    }
    int findKthLargest(vector<int>& nums, int k) {
        //buildheap(nums);
        int n=nums.size();
        int ans;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k){
            ans=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
