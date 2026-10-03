class Solution {
public:
    // Brute
    // int climbStairs(int n) {
    //     if(n==0 ||n==1)
    //     return 1;
    //     int left=climbStairs(n-1);
    //     int right=climbStairs(n-2);
    //     return left+right;
    // }
    int climbStairs(int n) {
        int prev2=1;
        int prev=1;
        for(int i=0;i<n-1;i++) {
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};