#include <iostream>
using namespace std;
class trie_node
{
public:
	int words;
	int prefixes;
	trie_node *edges[26];
};
void initialize(trie_node vertex)
{
	vertex.words = 0;
	vertex.prefixes = 0;
	for(int i=0;i<26;i++)
	{
		vertex.edges[i] = NULL;
	}
}
void add_word(trie_node vertex, string word, int wlen, int n)
{
	if(wlen == n) //means our word has been successfully added in the trie
	{
		vertex.words++;
	}
	else
	{
		vertex.prefixes++;
		if(vertex.edges[word[n]-'a'] == NULL) //there are no edges with current character, so create one
		{
			trie_node new_node;
			initialize(new_node);
			vertex.edges[word[n]-'a'] = &new_node; //creating a new trie_node
		}
		add_word(*vertex.edges[word[n]-'a'], word, wlen, n+1);
	}
}
int count_words(trie_node vertex, string word, int wlen, int n)
{
	if(wlen == n)
	{
		return vertex.words;
	}
	else if(vertex.edges[word[n]-'a'] == NULL)
	{
		return 0;
	}
	else
	{
		count_words(*vertex.edges[word[n]-'a'], word, wlen, n+1);
	}
}
int main()
{
	return 0;
}
