// http://www.spoj.com/problems/BLOPER/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    
    string output;
    
    int sequenceTotal = (N * (N + 1)) / 2;
    int sumToZero = sequenceTotal - S;
    
    if(sumToZero < 0 || (sumToZero % 2) != 0) {
        output = "Impossible";
    } else {
        int negatedTotal = sumToZero / 2;
        
        stack<int> stk;
        for(int i = N; i > 1; i--) {
            if(negatedTotal == 0) {
                break;
            }
            if(i == negatedTotal || i < (negatedTotal - 1)) {
                stk.push(i);
                negatedTotal -= i;
            }
        }
        
        if(negatedTotal == 0) {
            output = "";
            for(int i = 1; i < N; i++) {
                if(!stk.empty()) {
                    if(i+1 == stk.top()) {
                        output += to_string(i) + "-";
                        stk.pop();
                        continue;
                    }
                }
                output += to_string(i) + "+";
            }
            output += to_string(N);
        } else {
            output = "Impossible";
        }
    }
    
    cout << output;
    return 0;
}
