#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ALPHABET_COUNT 26

int totalComparisons=0;
void printList(string input[], int n){
    
    for(int i=0; i<n; i++)
        cout<<input[i]<<" ";
    cout<<endl;
}
int findMaxLength(string input[], int n)
{
    int maxlen = input[0].length();
    for (int i = 1; i < n; i++) {
        if(input[i].length() > maxlen)
            maxlen = input[i].length();
    }
    return maxlen;
}
bool compare(string A, string B, int index){
    char ach = 'a' ,bch = 'a';
    // totalComparisons++;
    if(A.length() > index && B.length() > index){
        totalComparisons++;
        return A[index]<=B[index];
    }else if(B.length() < A.length()){
        return false;
    }
    return true;
}
void merge(string input[],int index,int l, int mid, int r){
    int i, j, k, nl, nr;

    //size of left and right sub-arrays
    nl = mid-l+1; nr = r-mid;
    string larr[nl], rarr[nr];
    
    //fill left and right sub-arrays
    for(i = 0; i<nl; i++)
        larr[i] = input[l+i];
    for(j = 0; j<nr; j++)
        rarr[j] = input[mid+1+j];
    i = 0; j = 0; k = l;
    
    //marge temp arrays to real array
    while(i < nl && j<nr) {
        // totalComparisons++;
        if(compare(larr[i] , rarr[j], index)) {
            input[k] = larr[i];
            i++;
        }else{
            input[k] = rarr[j];
            j++;
        }
        k++;
    }
    
    while(i<nl) {       //extra element in left array
        input[k] = larr[i];
        i++; k++;
    }
    
    while(j<nr) {     //extra element in right array
        input[k] = rarr[j];
        j++; k++;
    }
}
void mergeSort(string input[], int index, int l, int r){
    int mid;                                
    if(l<r){
        mid=(l+r)/2;
        mergeSort(input, index, l, mid);
        mergeSort(input, index, mid+1, r);
        merge(input, index, l, mid, r);
    }
}

void radixSortString(string input[], int n)
{
    int maxlen = findMaxLength(input, n);
    for(int i=0; i<maxlen; i++){
        mergeSort(input, i, 0, n-1);
        // cout<<"Index:"<<i<<endl;
        // printList(input,n);
    }

}
void readFile(string filePath){
    fstream newFile;
    newFile.open("input/"+filePath,ios::in); 

    if(newFile.is_open()){   
        string tempText;
        getline(newFile, tempText);

        int n = stoi(tempText);
        string input[n];
        
        for(int i=0; i<n; i++){
            getline(newFile, input[i]); 
        }
        high_resolution_clock::time_point startTime = high_resolution_clock::now();

        radixSortString(input, n);
        // printArray(input, n);
 

        newFile.close(); 

        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
    
        duration<double, milli> time_span = stopTime - startTime;
    
        // cout << "[RADIX MERGE SORT]["<< filePath<<"] Duration>> " << time_span.count() << " milliseconds.\n";
        cout << "[RADIX MERGE SORT][n="<< n <<"] Total Comparisons>> " << totalComparisons <<"\n";
        
    }
}
int main(int argc,char *argv[]){
    // int n, k; cin >> n; k=n;
    // string input[n];
    // while(k--){
    //     cin >> input[n-1-k];
    // }

    // // high_resolution_clock::time_point startTime = high_resolution_clock::now();
    // radixSortString(input, n);


    // high_resolution_clock::time_point stopTime = high_resolution_clock::now();
 
    // duration<double, milli> time_span = stopTime - startTime;
 
    // cout << "[RADIX SORT] Duration>> " << time_span.count() << " milliseconds.\n";

    // string BASE_PATH = "";

    readFile(argv[1]);
}