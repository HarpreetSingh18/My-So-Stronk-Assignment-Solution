#include<bits/stdc++.h>
#include<sstream> 
using namespace std;
typedef long long int lli;

vector<string>arr12;
vector<string>arr13;
vector<pair<string,float> >vec;


bool sortByVal(const pair<string, float> &a, 
               const pair<string, float> &b) 
{ 
    return (a.second < b.second); 
}
void combinationUtil(vector<int>arr1, vector<string>arr2, int n, int r, int index, 
                     int data1[], string data2[], int i) 
{ 
   
    if (index == r) { 
    int sum=0;
    
    
       string s1="";
        for (int j = 0; j < r; j++) 
        {
        	
            arr12.push_back(data2[j]);
            arr13.push_back(data2[j]);
        	cout<<data2[j]<<" "; 
            sum=sum+data1[j];
            
        
        }
        cout<<s1;
		float avg=(float)sum/r;
		cout<<avg;
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
	map<string, int>m1;
	
	for(int i=0;i<4;i++)
	{
		cin>>s1;
		cin>>temp;
		arr.push_back(s1);
		arr1.push_back(temp);
		m1.insert(make_pair(s1,temp));
		
	}
	
	printCombination(arr1, arr, 2);
	
	cout<<"start"<<endl;
	
	for(int i=0;i<arr12.size();i++)
	{
		cout<<arr12[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<arr13.size()/2;i++)
	{
	arr13[i]="";
	}
	
	
	cout<<endl;
	int p=2;
	for(int i=0;i<arr12.size()-1;i=i+p)
	{
		for(int j=0;j<arr13.size()-1;j=j+p)
		{
			int k=i;
			int l=j;
			int count=0;
			int flag=1;
			
			   for(int x=i;x<i+p;x++)
			   {
			   	for(int y=j;y<j+p;y++)
			   	{
			   		
			   		if(arr12[x]==arr13[y] || arr13[y]=="")
			   		{
			   		flag=0;
			   		break;
			   	}
		
				   }
			}
			
			
			count=0;
		
			if(flag==1)
			{
				int sum=0;
				string s2="";
				cout<<s2<<" ";
			while(count<p)
			{
			   s2=s2+arr12[k]+" ";
			   sum=sum+m1[arr12[k]];
				count++;
				k++;
			}
			
			float avg1=(float)sum/p;
		    stringstream ss;
			ss<<avg1;
			string sy;
			ss>>sy;
			
			s2=s2+"("+sy+")"+" VS"+" " ; 
		     count=0;
		    
		      sum=0;
		    while(count<p)
			{
			   s2=s2+arr13[l]+" ";
			sum=sum+m1[arr13[l]];
               arr13[l]="";
				count++;
				l++;
			}
			float avg2=(float)sum/p;
		
		    stringstream ss1;
			ss1<<avg2;
			string sz;
			ss1>>sz;
		
			s2=s2+"("+sz+")";
		
			vec.push_back(make_pair(s2, fabs(avg1-avg2)));
			}
				 
		flag=1;
		}
	}
	
	sort(vec.begin(),vec.end(), sortByVal);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first <<" : "<<vec[i].second<<endl;
	}
	cout<<endl;	

	
}