#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class OneDimensionalRobotEasy {
public:
    int finalPosition(string commands, int A, int B) {
        int leftEdge = -A;
        int rightEdge = B;
        
        int pos = 0;
        
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == 'R' && pos < rightEdge) {
                pos++;
            }
            if(commands[i] == 'L' && pos > leftEdge) {
                pos--;
            }
        }
        
        return pos;
    }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
