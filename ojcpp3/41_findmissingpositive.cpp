#include <vector>
#include <unordered_set>

using namespace std;

/*


*/
class Solution0 {
public:
    // O(N) complexity, O(N) space
    // 常规办法：排序然后顺序查找
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> m;
        for (int i=0;i<nums.size();i++) {
            m.insert(nums[i]);
        }
        for (int i=1;i<=nums.size();i++) {
            if (!m.count(i)) {
                return i;
            }
        }
        return nums.size()+1;
    }
};

class Solution1 {
public:
    // O(N) complexity, O(1) space
    // [1,2,0]=>
    // 把原数组作为hashmap,

    
    // 第一次循环，先把负数和0全部设为INT_MAX，即不存在负数了
    // 第二次循环:
    // (1)如果自身是个INT_MAX,跳过
    // (2)如果自身是个负数，意味着是被别的位置元素修改的，自身改回i对应的正数，再把原先的负数的绝对值取出来，去修改该值对应的位置    
    // (3)如果自身是个正数，根据第二条去修改该值对应的位置
    // 例如[3,4,2,1] => [3,4,-2,1]=>[3,4,-2,-1]=>[]
    // 修改某个位置办法:
    // 对应位置为INT_MAX,则直接设成准确的数值
    // 对应位置是个正数，把它改为负数
    // 对应位置是个负数，意味着被别的元素修改过，允许,同上
    // 第三次循环
    // 找出第一个num[i]!=1+1的

    // 此算法有问题，[3,4,-1,1] 最后导致idx=0的3并没有改变,理论上idx[0]=>3处理后应该变化
    // [0] =>3,4,2147483647,1,
    // [1] =>3,4,3,1,
    // [2] =>3,4,3,-1,
    // [3] =>3,4,3,-1,


    int firstMissingPositive_bad(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            if (nums[i]<=0) nums[i]=INT_MAX;
        }

        for (int i=0;i<nums.size();i++) {
            if (nums[i]==INT_MAX) continue;
            int tmp = abs(nums[i])-1;
            if (nums[tmp]==tmp+1) continue;
            if (nums[i]<0) {
                nums[i]=i+1;
            }

            if (nums[tmp]==INT_MAX) {
                nums[tmp] = tmp+1;
            } else {
                nums[tmp] = -nums[tmp];
            }
        }

        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=i+1) return (i+1);
        }
        return nums.size()+1;
    }
    // ====================================================
    // 所以我们需要另想一种解法，既然不能建立新的数组，那么我们只能覆盖原有数组，我们的思路是把1放在数组第一个位置nums[0]，
    //  2放在第二个位置nums[1]，即需要把nums[i]放在nums[nums[i] - 1]上，
    //  那么我们遍历整个数组，如果nums[i] != i + 1, 而nums[i]为整数且不大于n，另外nums[i]不等于nums[nums[i] - 1]的话，
    //  我们将两者位置调换，如果不满足上述条件直接跳过，最后我们再遍历一遍数组，如果对应位置上的数不正确则返回正确的数，
    // ==>有问题....
    //  如果不能用hashmap,必须找一个方法来保存找出的数字，题目描述比较简单，所以解法可能很巧妙。
    //  上面的调换显得过于复杂，原题没有说不能修改原数组，只需要保证，将每个数值对应的index上的数字设置一个flag,然后在遍历中识别出这个flag即可。

    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= 0){
                nums[i] = INT_MAX;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            int tmp = abs(nums[i])-1;
            if(tmp < nums.size())
                if(nums[tmp] > 0)
                    nums[tmp] = -nums[tmp];

        }

        int ret = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] >= 0){
                return i+1;
            }
        }
        return nums.size()+1;
    }

 
};