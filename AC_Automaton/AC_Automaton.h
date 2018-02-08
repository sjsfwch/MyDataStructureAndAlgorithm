#pragma once
#include<string>
#include<iostream>
#include<queue>
#define size 26
using namespace std;

//定义Trie节点
struct TrieNode{
	TrieNode* fail;
	TrieNode* next[26];
	int count;
	TrieNode() :fail(NULL), count(0) {
		memset(next, NULL, sizeof(next));
	}
};


//建立Trie树
void insert(TrieNode* root,string s) {
	//if (s.empty()) return;
	TrieNode* p = root;
	for (auto c : s) {
		int index = c - 'a';
		if (p->next[index] == NULL) 
			p->next[index] = new TrieNode();
		p = p->next[index];
	}
	p->count++;
}


//建立fail指针
void buildfail(TrieNode* root) {
	queue<TrieNode*> q;
	root->fail = NULL;
	q.push(root);
	while (!q.empty()) {
		TrieNode* temp = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (temp->next[i] != NULL) {
				if (temp == root) {
					temp->next[i]->fail = root;
				}
				else {
					TrieNode* p = temp->fail;
					while (p != NULL) {
						if (p->next[i] != NULL) {
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if (p == NULL)
						temp->next[i]->fail = root;
				}
				q.push(temp->next[i]);
			}
		}
	}
}

//AC自动机匹配
bool Automaton(TrieNode* root, string str) {
	TrieNode* p = root;
	int res = 0;
	for (auto c : str) {
		int index = c - 'a';
		while (p->next[index] == NULL&&p != root)
			p = p->fail;
		p = p->next[index];
		p = p == NULL ? root : p;
		TrieNode* temp = p;
		while (temp != root) {
			if (temp->count > 0) {
				res += temp->count;
				temp->count = -1;
			}
			else
				break;
			temp = temp->fail;
		}
	}
	return res;
}
