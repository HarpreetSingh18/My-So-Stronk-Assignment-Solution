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


//Generating and storing the various m by m combinations
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
		//	cout<<data2[j]<<" ";
            sum=sum+data1[j];
            
        
        }
       // cout<<sum;
        //cout<<endl;
		lld avg=(lld)sum/r;
        return; 
    } 

  
    //base condition
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
    //getting size of arr1
     lli n=arr1.size();
     
     //integer array to store the scores of every combination
     lli data1[r];
     //string array to store every combination of names 
     string  data2[r];
     //This function gets the combinations of size m recursively
    combinationUtil(arr1, arr2, n, r, 0, data1, data2, 0); 
}

//Recursive function which generates and stores m by m combinations
void ace(lli p ,map<string, lli>m1)
{
	//making half array elements as blank to remove redundant output
	for(lli i=0;i<arr13.size()/2;i++)
	{
	arr13[i]="";
	}	
	
    //iterating both the global arrays to get the m by m combinations
	for(lli i=0;i<arr12.size()-p;i=i+p)
	{
		for(lli j=0;j<arr13.size();j=j+p)
		{
			lli k=i;
			lli l=j;
			lli count=0;
			int flag=1;
			  
			  //checking m by m combination so that they must not contain duplicate players 
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
			
			//making and storing each m by m combination as a string and difference of averages of two teams
			count=0;
			if(flag==1)
			{
				lli sum=0;
				string s2="";
			//storing players name and their average of 1st team	
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
		      //storing m player name and their average of 2nd team
		    while(count<p)
			{
			   s2=s2+arr13[l]+" ";
			sum=sum+m1[arr13[l]];
              
				count++;
				l++;
			}
			lld avg2=(lld)sum/p;
		
		    stringstream ss1;
			ss1<<avg2;
			string sz;
			ss1>>sz;
		
		    //The final string which represents m by m combination
			s2=s2+"("+sz+")";
			//cout<<s2<<endl;
		    //storing whole string and match quality(difference of average of two teams) in global vector
			vec.push_back(make_pair(s2, fabs(avg1-avg2)));
			
			
			}
				 
		flag=1;
		}
		
		
		
	}
	
	   //erasing redundant elements and making these two global arrays to generate remaining m by m combinations
		lli a=arr12.size()/2;
		arr12.erase(arr12.begin()+a,arr12.end());
		
	
		arr13.erase(arr13.begin(),arr13.end());
		for(lli i=0;i<arr12.size();i++)
		{
			arr13.push_back(arr12[i]);
		}
	
		for(int i=0;i<arr13.size()/2;i++)
		{
			arr13[i]="";
		}
		
		
		//base condition of this recursive function
		if(p>a)
		return;
		else
		//recursively calling the function for remaing m by m combinations
		ace(p,m1);
		
		
			
		}




int main()
{
	//taking the size of a team or value of m
	lli m;
	
	cout<<"Enter the number of players on each side or Value of M : ";
	cin>>m;
	
	//declaring the string and int vector array for storing the name and score of players
	vector<string>arr;
	vector<lli>arr1;
	
	//declaring interger variable and string variable to take the input as player name and their score
	lli temp=0;
	string s1="";
	
	//the input also stored in map because this map is used in a program
	map<string, lli>m1;
	
	
	//taking the value of N or number of players
	cout<<"Enter the number of players or Value of N : ";
	lli r=0;
	cin>>r;
	if((m>r/2) )
	{
	cout<<"Numbers of players are not enough to create a team of m players. Please enter valid number of players...";
	return(0);}
	cout<<"Enter the player names with their score : ";
    for(lli i=0;i<r;i++)
	//while(cin>>s1 && cin>>temp)
	{
	   cin>>s1;
	   cin>>temp;
		//storing players name and score 
		arr.push_back(s1);
		arr1.push_back(temp);
		
		//also storing names and score for further usw
		m1.insert(make_pair(s1,temp));
		
	}
	
	/*cout<<endl;
	cout<<"All the combination of size M : ";
	cout<<endl;*/
	
	//passing both the array to the below function to get the combinations of size m
	printCombination(arr1, arr, m);
	
	/*
	cout<<endl;
	cout<<"printing all the M by M unique combinations : ";
    cout<<endl;
    */
    
    //calling ace() function to generarte and store m by m combinations
    ace(m, m1);

    //sorting the output according to quality of matches
	sort(vec.begin(),vec.end(), sortByVal);
	  
	cout<<endl;
	//Printing the output which is sorted by match quality
	cout<<"Sorted list of "<< m <<" by "<< m <<" players match according to quality of matches...";
	cout<<endl;
	//printing the output
	for (lli i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first<<endl;
	}	

}

