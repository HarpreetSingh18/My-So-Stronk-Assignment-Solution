//including standard header files that are used in program
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;

//using short names for long name data types
typedef long long int lli;
typedef  long double lld;


//Decleration of two Global vector arrays that will be used in program
vector<string>arr12;
vector<string>arr13;

//Decleration of global vector with pair as a element. This vector array is usefull to 
//sort the output according to quality of matches
vector<pair<string,lld> >vec;

//third parameter of function sortByVal to sort the output according to quality of matches
bool sortByVal(const pair<string, lld> &a, 
               const pair<string, lld> &b) 
{ 
    return (a.second < b.second); 
}


//storing the various m by m combinations
void combinationUtil(vector<lli>arr1, vector<string>arr2, lli n, lli r, lli index, 
                     lli data1[], string data2[], lli i) 
{ 
   
    if (index == r) { 
    lli sum=0;
    
    
       string s1="";
        for (lli j = 0; j < r; j++) 
        {
        	//storing all combinations in single array for further use in main() fucntion
            arr12.push_back(data2[j]);
            arr13.push_back(data2[j]); 
            sum=sum+data1[j];
            
        
        }
      
		lld avg=(lld)sum/r;
        return; 
    } 

  
 
    if (i >= n) 
        return; 
  
     
    data1[index] = arr1[i];
	data2[index] =arr2[i];
	
	//recursively getting all the combination of size m 
    combinationUtil(arr1, arr2, n, r, index + 1, data1, data2, i + 1); 
    combinationUtil(arr1, arr2, n, r, index, data1, data2, i + 1); 
} 



//A main function to set the subset or combination of playeres of size m
void printCombination(vector<lli>arr1, vector<string>arr2, lli r) 
{ 

     lli n=arr1.size();
     lli data1[r];
     string  data2[r];
     //This function gets the combinations of size m recursively
    combinationUtil(arr1, arr2, n, r, 0, data1, data2, 0); 
}



int main()
{
	//taking the size of a team or value of m
	lli m;
	cin>>m;
	
	//declaring the string and int vector array for storing the name and score of players
	vector<string>arr;
	vector<lli>arr1;
	
	
	lli temp=0;
	string s1;
	
	//the input also stored in map because this map is used in a program
	map<string, lli>m1;
	
	for(lli i=0;i<8;i++)
	{
		cin>>s1;
		cin>>temp;
		//storing players name and score 
		arr.push_back(s1);
		arr1.push_back(temp);
		
		//also storing names and score for further usw
		m1.insert(make_pair(s1,temp));
		
	}
	
	//passing both the array to the below function to get the combinations of size m
	printCombination(arr1, arr, m);
	
	
	
	// Here is the logic to get the m by m combinations
	
	for(lli i=0;i<arr13.size()/2;i++)
	{
	arr13[i]="";
	}
	lli p=m;
	for(lli i=0;i<arr12.size()-1;i=i+p)
	{
		for(lli j=0;j<arr13.size()-1;j=j+p)
		{
			lli k=i;
			lli l=j;
			lli count=0;
			int flag=1;
			
			   for(lli x=i;x<i+p;x++)
			   {
			   	for(lli y=j;y<j+p;y++)
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
				lli sum=0;
				string s2="";
				
			while(count<p)
			{
			   s2=s2+arr12[k]+" ";
			   sum=sum+m1[arr12[k]];
				count++;
				k++;
			}
			
			lld avg1=(lld)sum/p;
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
			lld avg2=(lld)sum/p;
		
		    stringstream ss1;
			ss1<<avg2;
			string sz;
			ss1>>sz;
		
			s2=s2+"("+sz+")";
			
		    //storing whole string and match quality in global vector
			vec.push_back(make_pair(s2, fabs(avg1-avg2)));
			}
				 
		flag=1;
		}
	}
	
	//Here comes the sorting m by m matches according to match quality
	sort(vec.begin(),vec.end(), sortByVal);
	
	//Printing the output which is sorted by match quality
	for (lli i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first<<endl;
	}
	cout<<endl;	

	
}
