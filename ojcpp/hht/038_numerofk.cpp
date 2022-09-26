//
// Created by rui zhou on 07/05/19.
//

//有序 {1,2,3,3,3,3,4,5},找出3的个数
// 优于O(N)的解法, 二分
// 对条件判断还不够熟练，多练习

#include <codech/codech_def.h>

using namespace std;

namespace {
    class Solution {
    public:
        int getNumberOfK(vector<int> arr, int target) {
            auto getFirst = [](int start, int end, vector<int> &arr,int target) {
                while (start<=end) {
                    int mid = (start+end)/2;
                    if (arr[mid]>target) {
                        end=mid-1;
                    } else if (arr[mid]<target) {
                        start=mid+1;
                    } else {
                        if ((mid>0 && arr[mid-1]!=target) || mid==0) {
                            return mid;
                        } else {
                            end=mid-1;
                        }
                    }
                }
                return -1;
            };

            auto getLast = [](int start, int end, vector<int> &arr,int target) {
                while (start<=end) {
                    int mid = (start+end)/2;
                    if (arr[mid]>target) {
                        end=mid-1;
                    } else if (arr[mid]<target) {
                        start=mid+1;
                    } else {
                        if ((mid+1<arr.size() && arr[mid+1]!=target) || mid==arr.size()-1) {
                            return mid;
                        } else {
                            start=mid+1;
                        }
                    }
                }
                return -1;
            };


            int first=getFirst(0,arr.size()-1,arr,target);
            int last=getLast(0,arr.size()-1,arr,target);
            return (first!=-1?(last-first+1):0);
        }
    };
}


DEFINE_CODE_TEST(038_numberofk)
{
    Solution obj;
    {
        VERIFY_CASE(obj.getNumberOfK({3,3,3,3,3,3,3},3),7);
        VERIFY_CASE(obj.getNumberOfK({1,2,3,3,3,3,4,5},3),4);
        VERIFY_CASE(obj.getNumberOfK({5, 7, 7, 8, 8, 10},3),0);

    }
}