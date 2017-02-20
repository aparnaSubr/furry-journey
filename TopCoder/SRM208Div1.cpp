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
#include <string>

using namespace std;


class TallPeople {
public:

    int findMin(vector<int> numbers) {
        int min = 1001;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] < min) {
                min = numbers[i];
            }
        }
        
        return min;
    }
    
    
    int findMax(vector<int> numbers) {
        int max = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] > max) {
                max = numbers[i];
            }
        }
        
        return max;
    }
    
    vector <int> getPeople(vector <string> people) {
    
        vector<int> solution;
        int rows = people.size();
        
        vector<vector<int>> ppl(rows, vector<int>());
        
        string num = "";
        vector<int> small;
                
        for(int i = 0; i < rows; i++) {
            int j = 0;
            num = "";
            while(j < people[i].size()) {
                if(people[i][j] == ' ') {
                    int number = stoi(num);
                    ppl[i].push_back(number);
                    num = "";
                } else {
                    num += people[i][j];
                }
                j++;
            }
            
            ppl[i].push_back(stoi(num));
            small.push_back(findMin(ppl[i]));
        }
        
        solution.push_back(findMax(small));
        
        int cols = ppl[0].size();
        vector<int> tall;
        
        for(int i = 0; i < cols; i++) {
            int max = 0;
            for(int j = 0; j < rows; j++) {
                if(ppl[j][i] > max) {
                    max = ppl[j][i];
                }
            }
            tall.push_back(max);
        }
        
        solution.push_back(findMin(tall));
        return solution;
    }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
