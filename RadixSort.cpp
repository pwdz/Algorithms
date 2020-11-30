#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ALPHABET_COUNT 26

int totalComparisons=0;
int findMaxLength(vector<string> input)
{
    int maxlen = input[0].length();
    for (int i = 1; i < input.size(); i++) {
        if(input[i].length() > maxlen)
            maxlen = input[i].length();
    }
    return maxlen;
}
int key(char key){
    return (int)(key - 'a') + 1;
}
vector<string> countSort(vector<string> input, int index){
    int count[ALPHABET_COUNT + 1] = {0};
    size_t countSize = sizeof(count)/sizeof(int);

    vector<string> temp(input.size(), "");

    for(string s: input){
        totalComparisons++;
        if(s.length() > index){
            count[key(s[index])]++;
        }else{
            count[0]++;
        }
    }
    
    for(int i=1; i<countSize; i++)
        count[i] += count[i-1];

    for(int i=input.size()-1 ; i>=0 ; i--){
        int countKey;
        
        totalComparisons++;
        if(input[i].length() > index)
            countKey = key(input[i][index]);
        else
            countKey = 0;
        
        temp[--count[countKey]] = input[i];
    }
    return temp;

} 
void printList(vector<string> input){
    for(string s: input)
        cout<<s<<" ";
    cout<<endl;
}
void radixSortString(vector<string> input)
{
    int maxlen = findMaxLength(input);
    for(int i=0; i<maxlen; i++){
        input = countSort(input, i);
        // printList(input);
    }

}
void readFile(string filePath){
    fstream newFile;
    newFile.open("input/"+filePath,ios::in); 

    if(newFile.is_open()){   
        string tempText;
        getline(newFile, tempText);

        int n = stoi(tempText);
        vector<string> input(n,"");
        
        for(int i=0; i<n; i++){
            getline(newFile, input[i]); 
        }

        high_resolution_clock::time_point startTime = high_resolution_clock::now();

        radixSortString(input);
        // printArray(input, n);
 

        newFile.close(); 

        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
    
        duration<double, milli> time_span = stopTime - startTime;
    
        cout << "[RADIX SORT]["<< filePath<<"] Duration>> " << time_span.count() << " milliseconds.\n";
        
    }
}
int main(int argc,char *argv[]){
    // int n, k; cin >> n; k=n;
    // vector<string> input(n, "");
    // while(k--){
    //     cin >> input[n-1-k];
    // }

    // high_resolution_clock::time_point startTime = high_resolution_clock::now();
    // radixSortString(input);


    // high_resolution_clock::time_point stopTime = high_resolution_clock::now();
 
    // duration<double, milli> time_span = stopTime - startTime;
 
    // cout << "[RADIX SORT] Duration>> " << time_span.count() << " milliseconds.\n";

    string BASE_PATH = "";

    readFile(BASE_PATH + argv[1]);
}