class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        vector<int> hash(n,0);
        int l=0,r=0,len=0,maxlen=0;
        int count=0;
        while(r<n) {
            if(hash[fruits[r]]==0) {
                count++;
            }
            hash[fruits[r]]++;
            if(count<=2) {
                len=r-l+1;
                maxlen=max(maxlen,len);
            }
            if(count>2) {
                --hash[fruits[l]];
                if(hash[fruits[l]]==0)
                count--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};