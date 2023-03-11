function twoSum(nums: number[], target: number): number[] {
    const map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let diff = target - nums[i];
        if (map.has(diff)) {
            return [map.get(diff), i]
        }
        map.set(nums[i], i)
    }
    return [-1]
};

// test here
let result = twoSum([2,7,11,15], 9)
console.log(result.toString()==[0,1].toString())
