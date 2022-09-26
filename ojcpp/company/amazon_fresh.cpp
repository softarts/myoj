//
// Created by rui.zhou on 2/24/2019.
//

#include <codech/codech_def.h>
#include <cmath>
using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
vector<pair<int, int> > ClosestXdestinations(int numDestinations,
                                             int** allLocations,
                                             int numDeliveries)
{
    // WRITE YOUR CODE HERE
    auto comp = [](vector<int>&a,vector<int> &b){
        return sqrt(a[0]*a[0]+a[1]*a[1]) < sqrt(b[0]*b[0]+b[1]*b[1]);
    };

    priority_queue<vector<int>, std::vector<vector<int>>, decltype(comp)>pq(comp);
    for (int i=0;i<numDestinations;i++) {
        //cout<<allLocations[i][0] << " "<< allLocations[i][1];
        vector<int> pt{allLocations[i][0],allLocations[i][1]};
        pq.push(pt);
        if (pq.size()>numDeliveries) {
            pq.pop();
        }
    }

    vector<pair<int,int>> ret;
    while (!pq.empty()) {
        auto &iter = pq.top();
        ret.emplace_back(make_pair(iter[0],iter[1]));
        pq.pop();
    }
    return ret;
}

DEFINE_CODE_TEST(amazon_fresh)
{
    int **arr = new int*[3];
    for (int i=0;i<5;i++) {
        arr[i]=new int[2];
    }
    arr[0][0]=1;
    arr[0][1]=2;
    arr[1][0]=3;
    arr[1][1]=4;
    arr[2][0]=1;
    arr[2][1]=-1;


    //int loc[3][2] = {{1,2},{3,4},{1,-1}};
    auto vec = ClosestXdestinations(3,arr,2);
    for (auto &iter:vec) {
        cout <<iter.first << " " << iter.second << endl;
    }
    //VERIFY_CASE(ClosestXdestinations(3,loc,2)),"-2 4 3 3");
    //vector<vector<int>> nums{{3,3},{5,-1},{-2,4}};

}
