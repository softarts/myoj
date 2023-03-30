function longestStrChain(words: string[]): number {
    var words: string[] = words.sort((n1,n2) => (n1.length < n2.length)?-1:1);
    const map= new Map()
    words.forEach( item => {
        //console.log(item)
        map.set(item, 1)
    })
    var ans = 1
    words.forEach (item => {
        let n = item.length
        console.log(item+" ==> ")
        for (let i=0;i<n;i++) {
            let newstr = item.slice(0,i) + item.slice(i+1)
            console.log(newstr)
            if (map.has(newstr)) {
                map.set(item, Math.max(map.get(item), 1+map.get(newstr)))
            }
        }
        console.log(item+" ==> " + map.get(item))
        ans = Math.max(ans, map.get(item))
    })
    return ans;
};

// test here
let result = longestStrChain(["xbc","pcxbcf","xb","cxbc","pcxbc"])
console.log(result.toString())
/*
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string& b){
            return a.length()<b.length();
        });
        unordered_map<string,int> m;
        for (auto & it:words) {
            // cout<<it<<endl;
            m.insert(pair(it,1));
        }
        
        int ans=1;
        for (auto &s:words) {
            int n = s.length();           
            for (int i=0;i<n;i++) {                
                auto newStr = s.substr(0,i) + s.substr(i+1);
                // search if da, ba, bd is already in map            
                if (m.count(newStr)) {
                    // e.g ba is in the map, and ba=2                
                    // ba(1) =>b(1)=>found `b` in map, ba=>2, 
                    // ba(1) =>a(1)=>found `a` in map, ba=>2                    
                    m[s] = max(m[s], 1+m[newStr]);
                }
            }
            ans=max(ans,m[s]);
        }
        return ans;
    }
};
 */