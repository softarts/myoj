//
// Created by rui.zhou on 5/6/2019.
//

// 从1到整数N中 1出现的次数
// n=10,出现1，10 两次
// n=100,出现1,10,11,12...19,21,31,41,...91, 9+9=18 次
//LC 233 hard
// N=12-> 1,10,11,12 = 5次
#include <codech/codech_def.h>
using namespace std;

// 一般做法,直接循环计算,
namespace {
    class Solution0 {
    public:
        int numberof1(int n) {
            auto number1 = [](int x) {
                int count =0;
                while (x) {
                    if (x%10==1) {
                        count++;
                    }
                    x=x/10;
                }
                return count;
            };
            int ans = 0;
            for (int i=1;i<=n;i++) {
                ans += number1(i);
            }
            return ans;
        }
    };

    // 分析规律
    //https://www.cnblogs.com/grandyang/p/4629032.html
    /*
     * 这道题让我们比给定数小的所有数中1出现的个数，之前有道类似的题Number of 1 Bits 位1的个数，那道题是求转为二进数后1的个数，我开始以为这道题也是要用那题的方法，其实不是的，这题实际上相当于一道找规律的题。那么为了找出规律，我们就先来列举下所有含1的数字，并每10个统计下个数，如下所示：

1的个数          含1的数字                                                                        数字范围

1                   1                                                                                     [1, 9]

11                 10  11  12  13  14  15  16  17  18  19                              [10, 19]

1                   21                                                                                   [20, 29]

1                   31                                                                                   [30, 39]

1                   41                                                                                   [40, 49]

1                   51                                                                                   [50, 59]

1                   61                                                                                   [60, 69]

1                   71                                                                                   [70, 79]

1                   81                                                                                   [80, 89]

1                   91                                                                                   [90, 99]

11                 100  101  102  103  104  105  106  107  108  109          [100, 109]

21                 110  111  112  113  114  115  116  117  118  119             [110, 119]

11                 120  121  122  123  124  125  126  127  128  129          [120, 129]

...                  ...                                                                                  ...



通过上面的列举我们可以发现，100以内的数字，除了10-19之间有11个‘1’之外，其余都只有1个。
     如果我们不考虑[10, 19]区间上那多出来的10个‘1’的话，那么我们在对任意一个两位数，十位数上的数字(加1)就代表1出现的个数，
     这时候我们再把多出的10个加上即可。比如56就有(5+1)+10=16个。如何知道是否要加上多出的10个呢，我们就要看十位上的数字是否大于等于2，
     是的话就要加上多余的10个'1'。那么我们就可以用(x+8)/10来判断一个数是否大于等于2。对于三位数区间 [100, 199] 内的数也是一样，
     除了[110, 119]之间多出的10个数之外，共21个‘1’，其余的每10个数的区间都只有11个‘1’，所以 [100, 199] 内共有21 + 11 * 9 = 120个‘1’。
     那么现在想想[0, 999]区间内‘1’的个数怎么求？根据前面的结果，[0, 99] 内共有20个，[100, 199] 内共有120个，
     而其他每100个数内‘1’的个数也应该符合之前的规律，即也是20个，那么总共就有 120 + 20 * 9 = 300 个‘1’。那么还是可以用相同的方法来判断并累加1的个数，
     参见代码如下：
     */
    class Solution1 {
    public:
        int numberof1(int n) {
            int res = 0, a = 1, b = 1;
            while (n > 0) {
                res += (n + 8) / 10 * a + (n % 10 == 1) * b;
                b += n % 10 * a;
                a *= 10;
                n /= 10;
            }
            return res;
        }
    };

    //http://www.coin163.com/it/7440743705269299666/leetcode-
    /*
     * 考虑将n的十进制的每一位单独拿出讨论，每一位的值记为weight。

1) 个位
从1到n，每增加1，weight就会加1，当weight加到9时，再加1又会回到0重新开始。那么weight从0-9的这种周期会出现多少次呢？这取决于n的高位是多少，看图：
这里写图片描述
以534为例，在从1增长到n的过程中，534的个位从0-9变化了53次，记为round。每一轮变化中，1在个位出现一次，所以一共出现了53次。
再来看weight的值。weight为4，大于0，说明第54轮变化是从0-4，1又出现了1次。我们记1出现的次数为count，所以：
count = round+1 = 53 + 1 = 54
如果此时weight为0（n=530），说明第54轮到0就停止了，那么：
count = round = 53
2) 十位
对于10位来说，其0-9周期的出现次数与个位的统计方式是相同的，见图：
这里写图片描述
不同点在于：从1到n，每增加10，十位的weight才会增加1，所以，一轮0-9周期内，1会出现10次。即rount*10。
再来看weight的值。当此时weight为3，大于1，说明第6轮出现了10次1，则：
count = round*10+10 = 5*10+10 = 60
如果此时weight的值等于0（n=504），说明第6轮到0就停止了，所以：
count = round*10+10 = 5*10 = 50
如果此时weight的值等于1（n=514），那么第6轮中1出现了多少次呢？很明显，这与 个位数的值有关，个位数为k，第6轮中1就出现了k+1次(0-k)。我们记个位数为former，则：
count = round*10+former +1= 5*10+4 = 55
3) 更高位
更高位的计算方式其实与十位是一致的，不再阐述。

4) 总结
将n的各个位分为两类：个位与其它位。
对个位来说：

若个位大于0，1出现的次数为round*1+1
若个位等于0，1出现的次数为round*1
对其它位来说，记每一位的权值为base，位值为weight，该位之前的数是former，举例如图：
这里写图片描述
则：
若weight为0，则1出现次数为round*base
若weight为1，则1出现次数为round*base+former+1
若weight大于1，则1出现次数为rount*base+base
比如：

534 = （个位1出现次数）+（十位1出现次数）+（百位1出现次数）=（53*1+1）+（5*10+10）+（0*100+100）= 214
530 = （53*1）+（5*10+10）+（0*100+100） = 213
504 = （50*1+1）+（5*10）+（0*100+100） = 201
514 = （51*1+1）+（5*10+4+1）+（0*100+100） = 207
10 = (1*1)+(0*10+0+1) = 2

     public int count(int n){
    if(n<1)
        return 0;
    int count = 0;
    int base = 1;
    int round = n;
    while(round>0){
        int weight = round%10;
        round/=10;
        count += round*base;
        if(weight==1)
            count+=(n%base)+1;
        else if(weight>1)
            count+=base;
        base*=10;
    }
    return count;
}
     */
    // 每一个位数 1的次数，等于比它高的位数 * 所在的位，例如 456, 个位数的1的个数，等45 * 1，再加上个位数是否>=1，
    // 原因, 每10个数进一位，(0-9),如果该位>1，表明还有多一轮
    // 对于10位数／百位数，同理等于高位数的值*所在位，例如10位= 4*10, 5>1的话，和个位数的做法一样，
    // 如果是等于1，那要看比它低位数的值，例如, 416,那么就有10,11,12...16一共7个，等于低位数k+1次
    // round - weigh - former
    class Solution {
    public:
        int numberof1(int n) {
            int ans = 0;
            int base=1;
            int round = n;
            while (round>0) {
                int w = round%10;
                round=round/10;
                ans += round*base;

                if (w>1) {
                    ans += base;
                } else if (w==1) {
                    ans += n%base+1;
                } else {
                }
                base *= 10;

            }
            return ans;
        }
    };
}



DEFINE_CODE_TEST(hht_032_number1)
{
    Solution obj;
    {
        VERIFY_CASE(obj.numberof1(12),5);
        VERIFY_CASE(obj.numberof1(1999),1600);


    }

}