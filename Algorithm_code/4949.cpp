#include <iostream>
#include <string>
#include <stack>

using namespace std;

//³¯ÄÚµù 
int main() {
	
    while(1) {
    	
        string str;
        stack<char> s;
        bool chk = true;
        getline(cin, str);
        
        if((str.size() == 1) && (str[0] == '.')) {
            break;
            
        } else {
        	
            for(int i = 0; i < str.length(); i++) {
                if(str[i] == '(') {
                    s.push('(');
                } else if(str[i] == '[') {
                    s.push('[');
                } else if(str[i] == ')') {
                    if(s.empty()) {
                        chk = false;
                        break;
                    }
                    else if(s.top() == '(') {
                        s.pop();
                    }
                    
                    else {
                        chk = false;
                        break;
                    }
                } else if(str[i] == ']') {
                    if(s.empty()) {
                        chk = false;
                        break;
                    }
                    else if(s.top() == '[') {
                        s.pop();
                    }
                    
                    else {
                        chk = false;
                        break;
                    }
                }
            }
        }
        if(s.empty() && chk) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
}
