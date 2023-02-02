// Problem link: https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
#include <bits/stdc++.h>

using namespace std;

struct minHeapNode {
	char data;
	unsigned freq;
	minHeapNode *left, *right;
	        
	minHeapNode(char data, unsigned freq) {
	    this->data = data;
	    this->freq = freq;
	    left = right = NULL;
	}
};

struct compare {
	bool operator()(minHeapNode *l, minHeapNode *r)
	{
	    return (l->freq > r->freq);
	}
};
	    
void getCodes(minHeapNode *root, map<char, string> &charToBinary, string str)
{
    if(root == NULL)
        return;

	if(root->data != '#')
	{
	    charToBinary[root->data] = str;
        // return;
	}
	        
	getCodes(root->left, charToBinary, str + "0");
	getCodes(root->right, charToBinary, str + "1");
	        
}
	    
map<char, string> huffmanCodes(string S, vector<int> f, int N)
{
	// Code here
	minHeapNode *l, *r, *top;
		    
	priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;
		    
	for(int i = 0; i < N; i++)
		minHeap.push(new minHeapNode(S[i], f[i]));
		    
	while(minHeap.size() > 1)
	{
		l = minHeap.top();
		minHeap.pop();
		        
		r = minHeap.top();
		minHeap.pop();
		        
		top = new minHeapNode('#', l->freq + r-> freq);
		top->left = l;
		top->right = r;
		        
		minHeap.push(top);
	}
		    
	map<char, string> code;
    getCodes(minHeap.top(), code, "");
	return code;
}


int main() {
    string S;
    cin >> S;
    int N = S.length();
    string S1 = "";
    vector<int> f;
    for(int i = 0; i < N; i++)
    {
        int flag = 0;
        for(int j = 0; j < S1.length(); j++)
        {
            if(S[i] == S1[j])
            {
                f[j] += 1;
                // cout << S[i] <<": " << f[j] << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            S1 = S1 + S[i];
            f.push_back(1);
            // cout << S[i] << ": " << f[S1.length() - 1] << endl;
        }
    }
    cout << S1 << endl;
    for(int i = 0; i < S1.length(); i++)
        cout << f[i] << " ";

    cout << endl;
    map<char, string> codes = huffmanCodes(S1, f, S1.length());
    for(auto i: S)
    {
        cout << codes[i] << " ";
    }
    
    cout << endl;
    return 0;
}