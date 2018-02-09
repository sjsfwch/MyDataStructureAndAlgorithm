#pragma once
#include<string>
#include<iostream>
#include<queue>
#define size 26
using namespace std;

//定义Trie节点
struct TrieNode{
	TrieNode* fail;            //失配指针
	TrieNode* next[26];             //对应26个英文字母
	int count;                       //标记单词出现的次数
	TrieNode() :fail(NULL), count(0) {
		memset(next, NULL, sizeof(next));    //初始化next数组
	}
};


//建立Trie树
void insert(TrieNode* root,string s) {
	if (s.empty()) return;
	TrieNode* p = root;
	for (auto c : s) {
		int index = c - 'a';
		if (p->next[index] == NULL)       //不存在就添加一个节点
			p->next[index] = new TrieNode();
		p = p->next[index];
	}
	p->count++;        //单词出现次数加1
}


//建立fail指针
void buildfail(TrieNode* root) {
	queue<TrieNode*> q;                      //用队列来做
	root->fail = NULL;
	q.push(root);
	while (!q.empty()) {
		TrieNode* temp = q.front();
		q.pop();
		for (int i = 0; i < 26; ++i) {
			if (temp->next[i] != NULL) {      //实际存在的节点
				if (temp == root) {        //如果是根节点的孩子，fail指向根节点
					temp->next[i]->fail = root;
				}
				else {
					TrieNode* p = temp->fail;    //否则找到当前节点的失配指针指向节点
					while (p != NULL) {
						if (p->next[i] != NULL) {    //找到第一个有i孩子的节点，失败指针指向它
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;      //否则继续回溯
					}
					if (p == NULL)                //若不存在，失配指针指向根节点
						temp->next[i]->fail = root;
				}
				q.push(temp->next[i]);       //入队
			}
		}
	}
}

//AC自动机匹配
int Automaton(TrieNode* root, string str) {
	TrieNode* p = root;
	int res = 0;
	for (auto c : str) {
		int index = c - 'a';
		while (p->next[index] == NULL&&p != root)   //由失败指针回溯查找，判断c是否存在于Trie树
			p = p->fail;
		p = p->next[index];                    //找到后指针p指向该节点
		p = p == NULL ? root : p;               //若p为空，则说明没有与之匹配的字符，返回根节点查找下一个字符
		TrieNode* temp = p;
		while (temp != root) {                 //若有匹配的字符，进行查找
			if (temp->count > 0) {               //未被访问过
				res += temp->count;       //出现次数
				temp->count = -1;     //标记未访问，若不加可以统计出现的总次数
			}
			else
				break;
			temp = temp->fail;   //寻找下一个满足的节点
		}
	}
	return res;
}
