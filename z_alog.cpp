#include<bits/stdc++.h>
using namespace std;
#define nl cout<<endl

// count p in t
int zalog(const char* t, const char* p)
{
	int p_size = strlen(p);
	int t_size = strlen(t);
	char s[p_size + t_size + 2];
	
	strcpy(s,p);
	strcat(s,"$");
	strcat(s,t);
	int n = strlen(s);
	int z[n]={0};
	int count=0;
	
	int left = 0;
	int right = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(i > right) 
		{
			left = right= i;
			while(right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left; right--;
		}
		else if (z[i - left] < right - i + 1)
		{
			z[i] = z[i - left];
		}
		else
		{ 
			left = i;
			while(right < n && s[right - left] == s[right])
				right++;
			z[i] = right - left; right--;
		}
		//contains
		//if(z[i] == p_size)
		//	return 1;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(z[i] == p_size)
			count++;
	}
	
	return count;
}

int main()
{
	cout<<zalog("hahaha toi bi ngu haha", " haha");
	return 0;
}
