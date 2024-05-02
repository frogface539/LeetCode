class Solution {
public:
    int firstBadVersion(int n) {
        long long l=0,h=n,ans=0;
        while(l<=h){
            long long  mid=(h+l)/2;
            if(isBadVersion(mid)) {
                ans=mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};
