//
//  main.cpp
//  cppRpnCalc
//
//  Created by Jinwook Lee on 2016-01-26.
//  Copyright (c) 2016 Jinwook Lee. All rights reserved.
//
#include <stack>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(const string& str){
    string ops[] = {"-","+","*","/"};
    for(int i = 0; i< 4; i++) {
        if(str == ops[i]) {
            return true;
        }
    }
    return false;
}

void performOp(const string& input, stack<double>& calcStack){
    double lVal, rVal, result;
    
    rVal = calcStack.top();
    calcStack.pop();
    
    lVal = calcStack.top();
    calcStack.pop();
    
    if(input == "-"){
        result = rVal-lVal;
    }
    else if(input == "+"){
        result = lVal+rVal;
    }
    else if(input == "/"){
        result = lVal / rVal;
    }
    else if(input == "*"){
        result = lVal*rVal;
    }
    
    cout << result << endl;
    
    calcStack.push(result);
    
}


int main() {
    
    cout << "Welcome to RPN calculator simulation\n";
    
    stack<double> calcStack;
    string input;
    
    while (true){
        //display prompt
        cout << ">>";
        
        //get input
        cin >> input;
        
        //check for numeric value
        double num;
        if(istringstream(input) >> num){
            calcStack.push(num);
        }
        
        
        //check for operator
        else if(isOperator(input)) {
            performOp(input, calcStack);
        }
        
        //check for quit
        else if(input == "q") {
            return 0;
        }
        
        //invalid handler
        else {
            cout << "Invalid input\n";
        }
    }
    
    
    return 0;
}
