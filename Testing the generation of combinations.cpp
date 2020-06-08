#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void combinationUtil(vector<int>arr1, vector<string>arr2, int n, int r, int index, 
                     int data1[], string data2[], int i) 
{ 
   
    if (index == r) { 
        for (int j = 0; j < r; j++) 
            cout<<data2[j]<<", "<<data1[j];
        printf("\n"); 
        return; 
    } 
  
 
    if (i >= n) 
        return; 
  
     
    data1[index] = arr1[i];
	data2[index] =arr2[i];
    combinationUtil(arr1, arr2, n, r, index + 1, data1, data2, i + 1); 
  
    combinationUtil(arr1, arr2, n, r, index, data1, data2, i + 1); 
} 

void printCombination(vector<int>arr1, vector<string>arr2, int r) 
{ 

     int n=arr1.size();

  
     int data1[r];
     string  data2[r];
    combinationUtil(arr1, arr2, n, r, 0, data1, data2, 0); 
}



int main()
{
	vector<string>arr;
	vector<int>arr1;
	int temp=0;
	string s1;
	for(int i=0;i<3;i++)
	{
		cin>>s1;
		cin>>temp;
		arr.push_back(s1);
		arr1.push_back(temp);
		
	}
	
	printCombination(arr1, arr, 2);
}
