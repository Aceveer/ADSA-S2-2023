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
    // cout << "------------------------------------------------------------------" << endl;
    // cout << "Num1 : " << num1 << endl;
    // cout << "Num2 : " << num2 << endl;
    // cout << "K: " << k << endl;
    string a1 = num1.substr(0,k);
    string a0 = num1.substr(k);
    string b1 = num2.substr(0,k);
    string b0 = num2.substr(k);
    
    // cout << "a1: " << a1 << endl;
    // cout << "a0: " << a0 << endl;
    // cout << "b1: " << b1 << endl;
    // cout << "b0: " << b0<< endl;

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
    // cout << "P2: " << p2 << endl;
    // cout << "P1: " << p1 << endl;
    // cout << "P0: " << p0 << endl;
    string term1 = p2 + zero2;
    // cout << "Term1: " << term1 << endl;
    string term2 = subtractNumbers(p1,addNumbers(p2,p0,base),base) + zero1;
    // cout << "Term2: " << term2 << endl;
    string term3 = p0;
    // cout << "Term3: " << term3 << endl;
    string sum1 = addNumbers(term2,term3,base);
    // cout << "Term2 + Term3: " << sum1 << endl;
    string sum2 = addNumbers(term1,sum1,base);
    // cout << "Term 1 + Term2 + Term3: " << sum2 << endl;
    return sum2;
}

string subtractNumbersForDivisionOnly(string num1, string num2, int base){
    int l1 = num1.length();
    int l2 = num2.length();
    int maxLength = l1>l2 ? l1 : l2;
    while(num1.length() < maxLength){
        num1 = "0" + num1 ;
    }
    while(num2.length() < maxLength){
        num2 = "0" + num2 ;
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
        
        cout << "Temp1: " << temp1 << endl;
        cout << "Temp2: " << temp2 << endl;
        if(i == maxLength -1){
            cout << "---------------" << endl;
        }
        cout << "Diff= " << diff << endl;
        if(i==maxLength-1 && diff < 0){
            return "-1";
        }

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
        // cout << "Step1" << endl;
        while(!isNumber1BiggerThanNumber2(tempNumber,divisor)){
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
        }
        // cout << "Outside Step 1 " << endl;
        // cout << "Step2" << endl;
        //Getting the quotient, product and remainder
        while(isNumber1BiggerThanNumber2(tempNumber,divisor)){
            divisor = addNumbers(divisor,num2,base);
            quotient = addNumbers(quotient,"1",base);
        }
        finalAnswer = finalAnswer + quotient;
        divisor = subtractNumbers (divisor,num2,base);
        string remainder = subtractNumbers(tempNumber,divisor,base);

        // cout << "Step3" << endl;
        //Getting a new number using remainder + next digit of num1
        string zeros = "";
        while(zeros.length() != remainder.length()){
            zeros.insert(0,"0");
        }  

        // cout << "--------------------------------------------------------" << endl;
        // cout << "TempNumber Before : " << tempNumber << endl;
        // cout << "divisor: " << divisor << endl;
        // cout << "remainder: " << remainder << endl;
        // cout << "quotient: " << quotient << endl;


        // cout << "zeros " << zeros << endl;
        // cout << "Compare " << remainder.compare(zeros) << endl;

        if(remainder.compare(zeros) == 0){
            // cout << "Inside 0 == 0" << endl;
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = num1[totalIndexesTraversedInNum1];
            while(tempNumber == "0"){
                // cout << "I'm inside once" << endl;
                totalIndexesTraversedInNum1++;
                if(totalIndexesTraversedInNum1 >= l1){
                return finalAnswer + "0";
                }
                finalAnswer = finalAnswer + "0";
                tempNumber = num1[totalIndexesTraversedInNum1];
            }
            // cout << "tempNumber " << tempNumber << endl;
            // cout << "divisor " << divisor << endl;
            // cout << "num2 " << num2 << endl;
            // cout << "quotient " << quotient << endl;
            // cout << "remainder " << remainder << endl;
            // cout << "finalAnswer " << finalAnswer << endl;
            // cout << "totalIndexesTraversedInNum1 " << totalIndexesTraversedInNum1 << endl;
            // cout << "------------------------------------------------------------ " << endl;
        }
        else {  
            // cout << "Inside 0 != 0" << endl;
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                break;
            }
            tempNumber = remainder + num1[totalIndexesTraversedInNum1];
            tempNumber.erase(0, min(tempNumber.find_first_not_of('0'), tempNumber.size() - 1));
            // cout << "tempNumber " << tempNumber << endl;
            // cout << "divisor " << divisor << endl;
            // cout << "num2 " << num2 << endl;
            // cout << "quotient " << quotient << endl;
            // cout << "remainder " << remainder << endl;
            // cout << "finalAnswer " << finalAnswer << endl;
            // cout << "totalIndexesTraversedInNum1 " << totalIndexesTraversedInNum1 << endl;
            // cout << "------------------------------------------------------------ " << endl;
        }

        while(!isNumber1BiggerThanNumber2(tempNumber,num2)){
            if(!isNumber1BiggerThanNumber2(tempNumber,num2)){   
            finalAnswer = finalAnswer + "0";
            // cout << "Final 0 for while loop and if condition " << endl;
            }
            // cout << "I'm inside twice" << endl;
            totalIndexesTraversedInNum1++;
            if(totalIndexesTraversedInNum1 >= l1){
                return finalAnswer;
            }
            tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
            // cout << "tempNumber " << tempNumber << endl;
            // cout << "divisor " << divisor << endl;
            // cout << "num2 " << num2 << endl;
            // cout << "quotient " << quotient << endl;
            // cout << "remainder " << remainder << endl;
            // cout << "finalAnswer " << finalAnswer << endl;
            // cout << "totalIndexesTraversedInNum1 " << totalIndexesTraversedInNum1 << endl;
            // cout << "------------------------------------------------------------ " << endl;
        }
        //Checking The Remainder and then adding it
        // if(remainder.compare(zeros) == 0){
        //     totalIndexesTraversedInNum1++;
        //     cout << "Im inside zero = remainder" << endl;
        //     cout << "totalIndexesTraversedInNum1 zero = remainder: " <<totalIndexesTraversedInNum1 << endl;
        //     if(totalIndexesTraversedInNum1 >= l1){
        //         break;
        //         // return finalAnswer + "0";
        //     }

        //     //This is the default number being added without appending 0s to Final Answer
        //     tempNumber = num1[totalIndexesTraversedInNum1];
        //     cout << "tempNumber zero = remainder: " <<tempNumber << endl;
        //     //If tempNumber is still 0 after that, we have to keep adding 0s until we get a legitimate number
        //     while(tempNumber == "0"){
        //         cout << "Im inside the new tempNumber == 0 condition : " << endl;
        //         cout << "finalAnswer zero = remainder Inside: " << finalAnswer << endl;
        //         finalAnswer = finalAnswer + "0";
        //         totalIndexesTraversedInNum1++;
        //         if(totalIndexesTraversedInNum1 >= l1){
        //         break;
        //         // return finalAnswer + "0";
        //     }
        //         tempNumber = num1[totalIndexesTraversedInNum1];
        //     }
        //     cout << "tempNumber zero = remainder AFTER: " <<tempNumber << endl;
        //     cout << "finalAnswer zero = remainder AFTER: " <<finalAnswer << endl;

        //     while(!isNumber1BiggerThanNumber2(tempNumber,divisor)){
        //     totalIndexesTraversedInNum1++;
        //     finalAnswer = finalAnswer + "0";
        //     if(totalIndexesTraversedInNum1 >= l1){
        //         // cout << "tempNumber Inside : " <<tempNumber << endl;
        //         // cout << "divisor Inside : " <<divisor << endl;
        //         break;
        //         return finalAnswer + "0";
        //     }
        //     tempNumber = num1[totalIndexesTraversedInNum1];
        // }

        // } 
        // else {
        //     totalIndexesTraversedInNum1++;
        //     if(totalIndexesTraversedInNum1 >= l1){
        //         break;
        //         // return finalAnswer + "0";
        //     }
        //     tempNumber = remainder + num1[totalIndexesTraversedInNum1];
        //     tempNumber.erase(0, min(tempNumber.find_first_not_of('0'), tempNumber.size() - 1));
        //     cout << "TempNumber Inside ELSE " << tempNumber << endl;
        //     while(!isNumber1BiggerThanNumber2(tempNumber,num2)){
        //     cout << "TempNumber Inside ELSE Inside isNumber1BiggerThanNumber2 " << tempNumber << endl;
        //     cout << "divisor Inside ELSE Inside isNumber1BiggerThanNumber2 " << divisor << endl;
        //     totalIndexesTraversedInNum1++;
        //     finalAnswer = finalAnswer + "0";
        //     if(totalIndexesTraversedInNum1 >= l1){
        //         // cout << "tempNumber Inside : " <<tempNumber << endl;
        //         // cout << "divisor Inside : " <<divisor << endl;
        //         break;
        //         return finalAnswer + "0";
        //     }
        //     tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
        // }
        // }

    
        //totalIndexesTraversedInNum1++;
        // cout << "totalIndexesTraversedInNum1: " <<totalIndexesTraversedInNum1 << endl;
        // cout << "TempNumber After: " << tempNumber << endl;
        // cout << "finalAnswer: " << finalAnswer << endl;
        // cout <<"TempNumber Length: " << tempNumber.length() << endl;
        // cout <<"divisor Length: " << divisor.length() << endl;
        // cout <<"isNumber1BiggerThanNumber2(tempNumber,divisor): " << isNumber1BiggerThanNumber2(tempNumber,divisor) << endl;
    
        // if(divisor.length() == tempNumber.length() && !isNumber1BiggerThanNumber2(tempNumber,divisor)){
        //     finalAnswer = finalAnswer + "0";
        //     totalIndexesTraversedInNum1++;
        //     tempNumber = tempNumber + num1[totalIndexesTraversedInNum1];
        // }
    }
        // cout << "-__________________________________________________________-____________________________________________-" << endl;
        // cout << "This is the final values: " << endl;
        // cout << "totalIndexesTraversedInNum1 Outside: " <<totalIndexesTraversedInNum1 << endl;
        // cout << "TempNumber Outside: " << tempNumber << endl;
        // cout << "divisor Outside: " << divisor << endl;
        // cout << "finalAnswer Outside: " << finalAnswer << endl;
        // cout << "--------------------------------------------------------" << endl;
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

//379885274822250903692223338005105093852925997454397881826691398948009981484988895883993
//34708219924404677150152813854828790670175466783902728901220527119
//10
// Correct Output 10945109707430977608545

//10100001010010010110000001101100000111001000110001100100100000100010000100011000110111100 
//111110111011111101110010101110100100111001011011011101000110000010000100101101010010101 
//2
// Correct Output 10