#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
int add_word(trie_node * vertex, string word, int wlen, int n)
{
	//cout << wlen << n << endl;
	if(wlen == n) //means our word has been successfully added in the trie
	{
		vertex->words++;
		return 1;
	}
	else
	{
		vertex->prefixes++;
		//printf("Here %d\n",word[n]-'0');
		if(vertex->edges[word[n]-'0'] == NULL) //there are no edges with current character, so create one
		{
			//printf("--------Went Inside---------\n");
			trie_node *new_node = new trie_node;
			vertex->edges[word[n]-'0'] = new_node; //creating a new trie_node
			//cout << vertex->edges[word[n]-'0'] << endl;
		}
		else if(vertex->edges[word[n]-'0']->words != 0)
		{
			return 0;
		}
		/*else
		{
			cout << vertex->edges[word[n]-'0'] << endl;
		}*/
		//printf("Beyond\n");
		return add_word(vertex->edges[word[n]-'0'], word, wlen, n+1);
	}
}
int count_words(trie_node * vertex, string word, int wlen, int n)
{
	if(wlen == n)
	{
		return vertex->words;
	}
	else if(vertex->edges[word[n]-'0'] == NULL)
	{
		return 0;
	}
	else
	{
		count_words(vertex->edges[word[n]-'0'], word, wlen, n+1);
	}
}
int count_prefixes(trie_node * vertex, string prefix, int plen, int n)
{
	if(plen == n)
	{
		//cout << "Final-- " << vertex->prefixes << endl;
		return vertex->prefixes;
	}
	else if(vertex->edges[prefix[n]-'0'] == NULL)
	{
		return 0;
	}
	else
	{
		//cout << vertex->prefixes << endl;
		return count_prefixes(vertex->edges[prefix[n]-'0'], prefix, plen, n+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		trie_node *first_node = new trie_node;
		int n;
		vector <string> v;
		scanf(" %d",&n);
		char word[11];
		for(int i=0;i<n;i++)
		{
			//cin >> word;
			scanf(" %s",word);
			v.push_back(word);
			//add_word(first_node, word, word.length(), 0);
		}
		sort(v.begin(),v.end());
		int flag = 1;
		for(int i=0;i<n;i++)
		{
			flag = add_word(first_node, v[i], v[i].length(), 0);
			if(flag == 0)
			{
				break;
			}
		}

		//cout << first_node->words << endl;
		//cout << first_node->prefixes << endl;
		/*for(int i=0;i<10;i++)
		{
			if(first_node->edges[i] == NULL)
			{
				cout << "NULL" << endl;
			}
			else
			{
				cout << first_node->edges[i] << endl;
			}
		}*/
		/*for(int i=0;i<n;i++)
		{
			//cout << v[i] << v[i].length() << endl;
			int tmp = count_prefixes(first_node, v[i], v[i].length(),0);
			//cout << tmp << endl;
			if(tmp >= 1)
			{
				flag = 0;
				break;
			}
		}*/
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
