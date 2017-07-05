#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class trie_node
{
public:
	int words;
	int prefixes;
	trie_node *edges[10];
	trie_node();
};
trie_node::trie_node(void)
{
	words = 0;
	prefixes = 0;
	for(int i=0;i<10;i++)
	{
		edges[i] = NULL;
	}
}
void add_word(trie_node vertex, string word, int wlen, int n)
{
	//cout << wlen << n << endl;
	if(wlen == n) //means our word has been successfully added in the trie
	{
		vertex.words++;
	}
	else
	{
		vertex.prefixes++;
		//printf("Here\n");
		if(vertex.edges[word[n]-'0'] == NULL) //there are no edges with current character, so create one
		{
			trie_node new_node;
			vertex.edges[word[n]-'0'] = &new_node; //creating a new trie_node
		}
		//printf("Beyond\n");
		add_word(*vertex.edges[word[n]-'0'], word, wlen, n+1);
	}
	return;
}
int count_words(trie_node vertex, string word, int wlen, int n)
{
	if(wlen == n)
	{
		return vertex.words;
	}
	else if(vertex.edges[word[n]-'0'] == NULL)
	{
		return 0;
	}
	else
	{
		count_words(*vertex.edges[word[n]-'0'], word, wlen, n+1);
	}
}
int count_prefixes(trie_node vertex, string prefix, int plen, int n)
{
	if(plen == n)
	{
		return vertex.prefixes;
	}
	else if(vertex.edges[prefix[n]-'0'] == NULL)
	{
		return 0;
	}
	else
	{
		count_prefixes(*vertex.edges[prefix[n]-'0'], prefix, plen, n+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		trie_node first_node;
		int n;
		vector <string> v;
		scanf(" %d",&n);
		string word;
		for(int i=0;i<n;i++)
		{
			cin >> word;
			v.push_back(word);
			add_word(first_node, word, word.length(), 0);
		}
		int flag = 1;
		cout << first_node.words << endl;
		cout << first_node.prefixes << endl;
		for(int i=0;i<10;i++)
		{
			if(first_node.edges[i] == NULL)
			{
				cout << "NULL" << endl;
			}
			else
			{
				cout << first_node.edges[i] << endl;
			}
		}
		for(int i=0;i<n;i++)
		{
			cout << v[i] << endl;
			int tmp = count_prefixes(first_node, v[i], v[i].length(),0);
			cout << tmp << endl;
			if(tmp > 1)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
