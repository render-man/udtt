#include<iostream>
using namespace std;

#define out cout
#define el endl

char temp[7];
bool flags[7];

void pick(char s[], int sn, int curr)
{
	for(int i = 0; i < sn; i++)
	{
		if(flags[i])
			continue;
		
		temp[curr - 1] = s[i];
		if(curr == 6)
		{
			for(int j = 0; j < 7; j++)
				out<<temp[j];
			out<<el;
		}
		else
		{
			flags[i] = true;
			pick(s, sn, curr + 1);
			flags[i] = false;
		}
	}
}

int main()
{
	char S[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	
	pick(S, 7, 1);
}
