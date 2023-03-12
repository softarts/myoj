function combinationSum(candidates: number[], target: number): number[][] {
    var candidates: number[] = candidates.sort((n1,n2) => n1 - n2);
    let ans = []
    let memo: number[] = []
    helper(0, target, candidates, memo, ans)
    return ans
};

function helper(start: number, target: number, arr: number[], memo: number[], ans: number[][]) {
    if (target === 0) {
        ans.push([...memo]) // must expand, not memo itself
        return
    }

    for (let i=start;i< arr.length&&target>=arr[i];i++) {
        memo.push(arr[i])
        helper(i, target-arr[i],arr,memo,ans)
        memo.pop()
    }
}
