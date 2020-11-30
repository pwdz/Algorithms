#include <iostream>
#include<vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

int totalComparisons = 0;
void swap(string *s1, string *s2)  
{  
    string temp = *s1;  
    *s1 = *s2;  
    *s2 = temp;  
} 
bool isPivotGreater(string pivot, string s){
    // totalComparisons++;
    if(pivot.length() > s.length())
        return true;
    // totalComparisons++;
    if(pivot.length() == s.length()){
        int len = pivot.length();
        while(len--){
            if(pivot[len] > s[len])
                return true;
            else if(pivot[len] < s[len])
                return false;

            // totalComparisons++;
        }
    }else
        return false;
} 
int partition (string input[], int low, int high)  
{  
    string pivot = input[high]; 
    int i = (low - 1); 
  
    for (int j = low; j < high ; j++)  
    {  
        totalComparisons++;
        if(isPivotGreater(pivot, input[j])){  
            i++; 
            swap(&input[i], &input[j]);  
        }  
    }  

    swap(&input[i + 1], &input[high]);  

    return (i + 1);  
}  
  
void quickSortString(string input[], int low, int high)  
{  
    if (low < high){  
        // totalComparisons++;
        int partitionIndex = partition(input, low, high);  
  
        quickSortString(input, low, partitionIndex - 1);  
        quickSortString(input, partitionIndex + 1, high);  
    }  
}  
void printArray(string input[], int n){  
    for(int i=0; i<n; i++)
        cout<< input[i] << "\n";
} 
void readConsole(){
    int n,k; cin >> n; k = n;
    string input[n];
    while(k--){
        cin >> input[n-1-k];
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

        quickSortString(input, 0, n-1);
        // printArray(input, n);
 

        newFile.close(); 

        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
    
        duration<double, milli> time_span = stopTime - startTime;
    
        cout << "[QUICK SORT]["<< filePath<<"] Duration>> " << time_span.count() << " milliseconds.\n";
        // cout << "[QUICK SORT][n="<< n <<"] Total Comparisons>> " << totalComparisons <<"\n";
        
    }
} 
int main(int argc,char *argv[]){
    
    int n, k; 
    string BASE_PATH = "";
    // readConsole(&n, input);
    readFile(BASE_PATH + argv[1]);

    
    // quickSortString(input, 0, n-1);
    // printArray(input, n);
 

}