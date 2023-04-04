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