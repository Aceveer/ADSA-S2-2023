#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

string addNumbers(string num1, string num2, int base){
    int l1 = num1.length();
    int l2 = num2.length();
    int maxLength = l1>l2 ? l1 : l2;
    int sum = 0;
    int carry = 0;
    string result = "";
    //Padding 0s
    while(num1.length() < maxLength){
        num1 = "0" + num1;
    }
    while(num2.length() < maxLength){
        num2 = "0" + num2;
    }
    
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    
    //Code for addition
    for (int i = 0; i<maxLength;i++){
        int temp1 = int(num1[i]) - 48;
        int temp2 = int(num2[i]) - 48;
        sum = temp1 + temp2 + carry;
        int rem = sum % base;
        result = to_string(rem) + result;
        if(sum >= base){
            sum = sum/base;
            carry = 1;
        }
        else {
            carry = 0;
        }
    }
    if(carry > 0){
        result = to_string(carry) + result;
    }
    return result;
}

string subtractNumbers(string num1, string num2, int base){
    int l1 = num1.length();
    int l2 = num2.length();
    int maxLength = l1>l2 ? l1 : l2;
    while(num1.length() < maxLength){
        num1 = "0" + num1 ;
    }
    while(num2.length() < maxLength){
        num2 = "0" + num2 ;
    }
    int maxNumber = num1.compare(num2);
    //If num1 < num2, then swap.
    if(maxNumber < 0){
        string tempNum = num1;
        num1 = num2;
        num2 = tempNum;
    }
    int diff = 0;
    int borrow = 0;
    string result = "";

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Code for subtraction
    for (int i = 0; i < maxLength; i++) {
        int temp1 = int(num1[i]) - 48;
        int temp2 = int(num2[i]) - 48;
        diff = temp1 - temp2 - borrow;
        if (diff < 0) {
            diff = diff + base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }
    return result;
}

string karatsubaMultiply(string num1, string num2, int base) {
    int l1 = num1.length();
    int l2 = num2.length();
    int maxLength = l1>l2 ? l1 : l2;

    if(maxLength == 1){
        int temp1 = num1[0] - 48;
        int temp2 = num2[0] - 48;
        int product = temp1 * temp2;
        if(product >= base){
            int quotient = product/base;
            int remainder = product%base;
            string result = to_string(quotient) + to_string(remainder);
            return result;
        }
        return to_string(temp1 * temp2);
    }
    //Padding 0s
    while (num1.length() < maxLength) {
        num1 = "0" + num1;
    }
    while (num2.length() < maxLength) {
        num2 = "0" + num2;
    }
    int k;
    int addingZeroVariable = maxLength/2;
    if(maxLength%2 == 1) {
        k = (maxLength+1)/2;
    } else {
        k = maxLength/2;
    }
    string a1 = num1.substr(0,k);
    string a0 = num1.substr(k);
    string b1 = num2.substr(0,k);
    string b0 = num2.substr(k);

    string p2 = karatsubaMultiply(a1,b1,base);
    string p1 = karatsubaMultiply(addNumbers(a1,a0,base),addNumbers(b1,b0,base),base);
    string p0 = karatsubaMultiply(a0,b0,base);

    string zero2 = "";
    string zero1 = "";
    string zero0 = "";
    for(int i =0; i< addingZeroVariable;i++){
        zero2.insert(0,"00");
        zero1.insert(0,"0");
    
    }
    string term1 = p2 + zero2;
    string term2 = subtractNumbers(p1,addNumbers(p2,p0,base),base) + zero1;
    string term3 = p0;
    string sum1 = addNumbers(term2,term3,base);
    string sum2 = addNumbers(term1,sum1,base);
    return sum2;
}

bool isNumber1BiggerThanNumber2(string num1, string num2){

    int l1 = num1.length();
    int l2 = num2.length();
    int maxLength = l1>l2 ? l1 : l2;
    if(l1 > l2){
        return true; // we can divide
    }

    if(l1 == l2){
        for(int i =0; i< maxLength;i++){
            int temp1 = num1[i] - 48;
            int temp2 = num2[i] - 48;
            if(temp1 > temp2){
                return true; //num1 is bigger
            }
            if(temp1 < temp2){
                return false;
            }
        }
    }

    if(l1 < l2){
        return false;
    }
    return true;
}

string divideNumbers(string num1, string num2, int base){
    int l1 = num1.length();
    int l2 = num2.length();
    string tempNumber = "";
    int tempNumberIndex = 0;
    int totalIndexesTraversedInNum1 = 0;
    string finalAnswer = "";

    //Default condition for num2 being greater than num1
    if(l2>l1){
        return "0";
    }
    //Step 1 -> Take l2 or l2+1 digits by comparing.
    
    string divisor = num2;
    totalIndexesTraversedInNum1 = 0;
    tempNumber = num1[totalIndexesTraversedInNum1];
    while(totalIndexesTraversedInNum1 <= l1)
    {        
        divisor = num2;
        string quotient = "0";

        //Step 1
        //Getting num1 to be bigger than num2
        while(!isNumber1BiggerThanNumber2(tempNumber,divisor)){
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
        }
        //Getting the quotient, product and remainder
        while(isNumber1BiggerThanNumber2(tempNumber,divisor)){
            divisor = addNumbers(divisor,num2,base);
            quotient = addNumbers(quotient,"1",base);
        }
        finalAnswer = finalAnswer + quotient;
        divisor = subtractNumbers (divisor,num2,base);
        string remainder = subtractNumbers(tempNumber,divisor,base);

        //Getting a new number using remainder + next digit of num1
        string zeros = "";
        while(zeros.length() != remainder.length()){
            zeros.insert(0,"0");
        }  


        if(remainder.compare(zeros) == 0){
            
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = num1[totalIndexesTraversedInNum1];
            while(tempNumber == "0"){
                totalIndexesTraversedInNum1++;
                if(totalIndexesTraversedInNum1 >= l1){
                return finalAnswer + "0";
                }
                finalAnswer = finalAnswer + "0";
                tempNumber = num1[totalIndexesTraversedInNum1];
            }
        }
        else {  
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = remainder + num1[totalIndexesTraversedInNum1];
            tempNumber.erase(0, min(tempNumber.find_first_not_of('0'), tempNumber.size() - 1));
        }

        while(!isNumber1BiggerThanNumber2(tempNumber,num2)){
            if(!isNumber1BiggerThanNumber2(tempNumber,num2)){   
            finalAnswer = finalAnswer + "0";
            }
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                return finalAnswer;
            }
            tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
        }
    }
    return finalAnswer;
}


int main() {
    string num1, num2;
    int base;
    cin >> num1 >> num2 >> base;
    string sum = addNumbers(num1, num2, base);
    string prod = karatsubaMultiply(num1, num2, base);
    //Removing preceeding 0s
    prod.erase(0, min(prod.find_first_not_of('0'), prod.size() - 1));
    string divide = divideNumbers(num1, num2, base);
    cout << sum << " " << prod << " " << divide << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    return 0;
}

