class Solution {
public:
    string reorganizeString(string s) {
        int f[26]={0}, n=s.size();
        for(char c:s) f[c-'a']++;
        
        int mx=0;
        for(int x:f) mx=max(mx,x);
        if(mx>(n+1)/2) return "";

        vector<pair<int,char>> v;
        for(int i=0;i<26;i++) if(f[i]) v.push_back({f[i],char('a'+i)});
        sort(v.rbegin(),v.rend());

        string r(n,' ');
        int i=0;
        for(auto &[cnt,c]:v)
            while(cnt--){
                r[i]=c;
                i+=2;
                if(i>=n) i=1;
            }
        return r;
    }
};
