#include <iostream>
using namespace std;

char position[4];
bool flags[4];

void A1(char g[], char* n[], int count, int curr, int& num)
{
	for(int i = 0; i < count; i++)
	{
		if(!flags[i])
		{
			//std::cout<<curr;
			position[curr] = g[i];
			
			if(curr == count - 1)
			{
				for(int j = 0; j < 4; j++)
					cout<< position[j] << " ";
				cout<<endl;
				num++;
			}
			else
			{
				
				flags[i] = true;
				A1(g, n, count, curr + 1, num);
				flags[i] = false;
			}
		}
	}	
}

int main()
{
	char G[] = {'A', 'B', 'C', 'D'};
	char* N[] = {"Tung", "Cuc", "Truc", "Mai"};
	int count = 4;
	int num = 0;
	A1(G, N, count, 0, num);
	std::cout<<num;
	return 0;
}
