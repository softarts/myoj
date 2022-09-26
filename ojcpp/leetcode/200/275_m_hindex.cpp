#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int l=0,r=citations.size()-1;
            while (l<=r) {            
                int mid=(l+r)/2;
                int n=citations.size()-mid;
                if (l==r) {
                    if (citations[l]>=n)  return n;
                    else return 0;
                } 
                if (citations[mid]==n) {
                    return n;
                } else if (citations[mid]>n) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            // if (citations[l]>=(citations.size()-l)) {
            //     return citations.size()-l;
            // } else {
            //     return 0;    
            // }
            return 0;
        }
    };
}