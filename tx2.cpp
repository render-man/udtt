#include<bits/stdc++.h>

#define nl cout<<endl;
#define sw setw

using namespace std;

struct CanRuou
{
	char nhanHieu[50];
	int dungTich;
	long giaTri;
};

void out(CanRuou r)
{
	cout<<sw(20)<<r.nhanHieu<<sw(20)<<r.dungTich<<sw(20)<<r.giaTri;nl;
}

void header()
{
	cout<<sw(20)<<"Nhan hieu"<<sw(20)<<"Dung tich"<<sw(20)<<"Gia tri";nl;
}

struct Result
{
	int count;
	int index;
	CanRuou ruou[20];
};

//----------------------------------A1
Result a(CanRuou rs[], int n, int m)
{
	Result r = {};
	int i = 0;
	while(i < n && m > 0)
	{
		int c = m / rs[i].giaTri;
		m %= rs[i].giaTri;
		if(c > 0)
		{
			r.count += c;
			r.ruou[r.index++] = rs[i];
		}
		i++;
	}
	
	return r;
}

struct Answer
{
	int count;
	CanRuou ruou[20];
};

//-----------------------------A2
Answer a2(CanRuou rs[], int n, int m)
{
	Answer ans = {};
	int i = 0;
	while(i < n && rs[i].giaTri <= m)
	{
		m -= rs[i].giaTri;
		ans.ruou[ans.count++] = rs[i];
		i++;
	}
	
	return ans;
}

//--------------------QHD
Answer b(CanRuou d[], int n, int s)
{
	int f[n + 1][s + 1] = {};
	for(int j = 0; j <= s; j++)
		f[0][j] = 0;
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			f[i][j] = f[i - 1][j];
			
			if(d[i - 1].dungTich <= j)
			{
				int temp = f[i - 1][j - d[i - 1].dungTich] + d[i - 1].giaTri;
				if(f[i][j] < temp)
					f[i][j] = temp;
			}
		}
	}
	
	//retrace
	//cout<<f[n][s];
	Answer ans = {};
	int i = n;
	int j = s;
	while(i != 0)
	{
		if(f[i][j] != f[i - 1][j])
		{
			ans.ruou[ans.count++] = d[i - 1];
			j -= d[i - 1].dungTich;
		}
		i--;
	}
	
	return ans;
}

//------Boyer
int lastIndexOf(const char c, const char* s)
{
	int len = strlen(s);
	for(int i = len - 1; i >= 0; i--)
	{
		if(c == s[i])
			return i;
	}
	return -1;
}

int boyer(const char* p, const char* t)
{
	int lenP = strlen(p);
	int lenT = strlen(t);
	int i = lenP - 1;
	while(i < lenT)
	{
		int k = lenP - 1;
		int j = i;
		while(k >= 0 && p[k] == t[j])
		{
			j--;
			k--;
		}
		
		if(k < 0)
			return j + 1;
		
		int next = lastIndexOf(t[j], p);

		if(next < 0)
			i += lenP;
		else
			i += lenP - next -1 ;
	}
	
	return -1;
}

int main()
{
	cout<<"vtri: ";
	cout<<boyer("tao bi ngu", "tao ko bbi ngu ma tao bi ngu");
	nl;
	
	int n = 6;
	int m = 80000;
	CanRuou d[6] = 
	{
		{"ruou vang italy", 18, 20000},
		{"ruou vang phap", 19, 50000},
		{"ruou trang", 16, 80000},
		{"ruou do", 17, 100000},
		{"ruou nhan sam", 26, 110000},
		{"ruou tay", 22, 150000},
	};
	
	Result r = a(d, n, m);
	
	if(r.count == 0)
	{
		cout<<"ko mua duoc can ruou nao!";
	}
	else
	{
		cout<<"co the mua duoc "<<r.count<<" can ruou, gom: ";nl;
		
		header();
		for(int i = 0; i < r.index; i++)
		{
			out(r.ruou[i]);
		}
	}
	nl;
	// test a2
	Answer a = a2(d, n, m);
	cout<<"co the mua duoc "<<a.count<<" can ruou, gom: ";nl;
	header();
	for(int i = 0; i < a.count; i++)
	{
		out(a.ruou[i]);
	}
	
	
	//cau2
	int s = 100;
	Answer ans = b(d, n, s);
	if(ans.count == 0)
	{
		cout<<"ko mua duoc can ruou nao";
	}
	else
	{
		cout<<"mua duoc nhung can ruou sau de dung tich ko vuot qua "<<s<<" :";nl;
		header();
		for(int i = 0; i < ans.count; i++)
		{
			out(ans.ruou[i]);
		}
		
		cout<<"tong la mua duoc: "<<ans.count<<" can ruou";
	}
	
	
	return 0;
}
