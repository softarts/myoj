
// https://app.codesignal.com/interview-practice/question/oJXTWuwEZiC6FTw3A/description

/*
You are climbing a staircase that has n steps. You can take the steps either 1 or 2 at a time. Calculate how many distinct ways you can climb to the top of the staircase.
相当于 f-1 => 1种, f-2 另一种； 所以sum=f1+f2
*/

int solution(int n) {    
    int f1=1;
    int f2=1;
    int ans;
    if (n==1) return 1;        
    for (int i=2;i<=n;i++) {
        ans = f1+f2;
        f2=f1;
        f1=ans;
    }
    return ans;
}
