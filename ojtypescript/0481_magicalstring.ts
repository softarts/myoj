//122
function magicalString(n: number): number {
    if (n<=3) return 1;
    let arr:number[]=[1,2,2]
    let idx = 2;
    let ans = 1;
    while (idx<n) {
        const cur = arr[idx]
        const last = arr[arr.length-1]
        if (cur===2) {
            if (last===2) {
                arr.push(...[1,1])
            } else {
                arr.push(...[2,2])
            }
        } else {
            if (last===2) {
                arr.push(1)
            } else {
                arr.push(2)
            }
            ans++
        }
        idx++
    }
    return ans
};