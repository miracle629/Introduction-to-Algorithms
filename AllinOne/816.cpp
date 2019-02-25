#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

//----------------------------817-------------------------------
int linkedListComponents(vector<int>& G, ListNode* head)
{
	int res = 0;
	unordered_set<int> nodeSet(G.begin(), G.end());
	while (head)
	{
		if (!nodeSet.count(head->val))
		{
			head = head->next;
			continue;
		}
		++res;
		if (head && nodeSet.count(head->val))
			head = head->next;
	}
	return res;
}

int linkedListComponents_1(vector<int>& G, ListNode* head)
{
	int res = 0;
	unordered_set<int> nodeSet(G.begin(), G.end());
	while (head)
	{
		if (nodeSet.count(head->val) && (!head->next || !nodeSet.count(head->next->val)))
			++res;
		head = head->next;
	}
	return res;
}


//----------------816----------------------------------------
vector<string> findAll(string S)
{
	int n = S.size();
	if (n == 0 || (n > 1 && S[0] == '0' && S[n - 1] == '0'))
		return{};
	if (n > 1 && S[0] == '0')
		return{ "0." + S.substr(1) };
	if (S[n - 1] == '0')
		return{ S };
	vector<string> res;
	for (int i = 0;i < n;++i)
	{
		res.push_back(S.substr(0, i) + "." + S.substr(i));
	}
	return res;

}

vector<string> ambiguousCoordinates(string S)
{
	vector<string> res;
	int n = S.size();
	for (int i = 1;i < n - 2;++i)
	{
		vector<string> A = findAll(S.substr(1, i)), B = findAll(S.substr(i + 1, n - 2 - i));
		for (auto &a : A)
		{
			for (auto &b : B)
			{
				res.push_back("(" + a + "," + b + ")");
			}
		}
	}
}

//-------------------------------812-----------------------------
double largestTriangleArea(vector<vector<int>>& points)
{
	double res = 0;
	int n = points.size();
	for (int i = 0;i < n;++i)
	{
		for (int j = i + 1;j < n;++j)
		{
			for (int k = j + 1;k < n;++k)
			{
				int x1 = points[i][0];
				int x2 = points[i][1];
				int y1 = points[j][0];
				int y2 = points[j][1];
				int z1 = points[k][0];
				int z2 = points[k][1];
				double area = abs(0.5*(x1*y2 + y1*z2 + z1*x2 - x2*y1 - y2*z2 - z2*x1));
				res = max(res, area);
			}
		}
	}
	return res;
}

//-------------------------------811-----------------------------
vector<string> subdomainVisits(vector<string>& cpdomains)
{
	vector<string> res;
	unordered_map<string, int> subdomainCnt;
	for (string cpdomain : cpdomains)
	{
		int spaceIdx = cpdomain.find(" ");
		int cnt = stoi(cpdomain.substr(0, spaceIdx));
		string rem = cpdomain.substr(spaceIdx + 1);
		for (int i = 0;i < rem.size();++i)
		{
			if (rem[i] == '.')
			{
				subdomainCnt[rem.substr(i + 1)] += cnt;
			}
		}
		subdomainCnt[rem] += cnt;
	}
	for (auto a : subdomainCnt)
	{
		res.push_back(to_string(a.second) + " " + a.first);
	}
	return res;
}

//-------------------------------809-----------------------------
int expressiveWord(string S, vector<string>& words)
{
	int res = 0;
	for (string word : words)
	{
		int i = 0,j = 0;
		for (;i < S.size();++i)
		{
			if (j < word.size() && S[i] == word[j]) ++j;//若是最后一位都是单个相同的呢?
			else if (i > 0 && S[i] == S[i - 1] && i + 1 < S.size() && S[i] == S[i + 1]) ++i;
			else if (!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2])) break;
		}
		if (i == S.size() && j == word.size()) ++res;
	}
	return res;
}

//-------------------------------807------------------------------
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
	int res = 0;
	int N = grid.size();
	unordered_map<int, int> height;
	unordered_map<int, int> width;
	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;j++)
		{
			height[i] = max(height[i], grid[i][j]);
			width[j] = max(width[j], grid[i][j]);
		}
	}
	for (int i = 0;i < N;++i)
	{
		for (int j = 0;j < N;j++)
		{
			res += min(height[i]-grid[i][j], width[j]-grid[i][j]);
		}
	}
	return res;
}

//--------------------------------806-----------------------------
vector<int> numberOfLines(vector<int>& widths, string S)
{
	int lineNum = 1, cur = 0;
	for (char c : S)
	{
		int t = widths[c - 'a'];
		if (cur + t > 100) ++lineNum;
		cur = (cur + t > 100) ? t : cur + t;
	}
	return{ lineNum,cur };
}



//------------------------------804---------------------------------
int uniqueMorseRepresentations(vector<string>& words)
{
	vector<string> morse{ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
	unordered_set<string> s;
	for (string word : words)
	{
		string t = "";
		for (char c : word)
		{
			t += morse[c - 'a'];
		}
		s.insert(t);
	}
	return s.size();
}




int main()
{
	string S = "(123)";
	return 0;
}