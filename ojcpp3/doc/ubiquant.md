bool isValid(vector<vector<int>> &m) {
    
}


bool isRowValid(vector<vector<int>> &m, int row) {
    int data[10] = {0};
    vector<int> &mrow = m[row];
    for (int i=0;i<9;i++) {
        int num = mrow[i];
        if (num!=0 && data[num]==0) {
            data[num]++;
        } else {
            return false;
        }
    }
}

bool isColValid(vector<vector<int>> &m, int col) {
    int data[10] = {0};
    for (int i=0;i<9;i++) {        
        int num = m[i][col];
        if (num!=0 && data[num]==0) {
            data[num]++;
        } else {
            return false;
        }
    }
}


1. 使用IPC， 进程间通信， 比如socket, mmap, fifo, pipe
2. 本题选择使用socket + protobuf 来作为进程间通信的方式 (**Q1**)
     (a) 定义两个消息类型:  A-startup  和 A-datain
     (b) A 作为socket server - producer, B 作为socket client - consumer.
3. A的设计（**Q3**）
     (a) 使用一个内部消息队列用于保存所有消息， 例如 startup,  data-1,data-2... 并且可以持久化到硬盘的文件上。(例如定期batch flush)
     (b) A启动后:将持久化文件恢复到内存队列=>将计算数据写入队列=>建立socket server listener=>初始化结束
     (c) (**Q3**) 此时A的内部队列将会用于维持数据的一致性​
4. B<->A通信(**Q2**)
     (a) B启动后: 连接到socket server(A)=> A将会顺序取出内部队列的消息，回传到B
     (b) B将会由socket 收到的数据来驱动，例如reactor 模式 ; 如果B无法连接到A,或者A中队列没有任何数据, 则不会有任何动作，阻塞等待。（**Q2** 规避A晚启动，启动失败，计算失败等问题）
5. 另外设计一个daemon/脚本定期监控A/B， 在进程崩溃时将两者重启


// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

// online compiler
int maxsum(vector<int> &nums) {
    if (nums.empty()) return -1;
    if (nums.size()==1) return nums[0];
    
    int f1=0;
    int f2=nums[0];
    int ans=f2;
    for (int i=1;i<nums.size();i++) {
        ans = max(f2,f1+nums[i]);
        f1=f2;
        f2=ans;
    }
    return ans;
}


int main() {
    {
        vector<int> arr = {2,4,6,2,5};
        cout << maxsum(arr)<< endl;    
    }
    
    {
        vector<int> arr = {5,1,1,5};
        cout << maxsum(arr)<< endl;    
    }
    
    {
        vector<int> arr = {5,9,6,6,100};
        cout << maxsum(arr)<< endl;    
    }
    
    {
        vector<int> arr = {5,9,1,6,100};
        cout << maxsum(arr)<< endl;    
    }

    return 0;
}
