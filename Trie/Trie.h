/*
** 现在只实现了一些基本功能，插入，删除，查找等，拿来巩固相关原理
** 将来可以添加热搜功能，词汇预测功能等
** 还有对汉字的支持等
*/

#pragma once
#include<iostream>
#include<string>

using namespace std;

//TrieNode类
class TrieNode {
public:
	int count;        //该单词个数
	string word;     //表示的单词
	TrieNode* next[26];
	TrieNode() :word(""), count(0) {
		memset(next, NULL, sizeof(TrieNode*) * 26); //所有子节点初始化为NULL
	}
};

//Trie类
class Trie {
private:
	TrieNode* root;
	void Destroy(TrieNode* root);
	void Print(TrieNode* root);
public:
	Trie();
	~Trie();
	void Insert(string s);   //插入
	void Remove(string s);   //删除
	int  Search(string s);   //查找
	void PrintAll();         //输出所有单词
	void PrintPre(string s); //输出以给定串为前缀的所有单词
};


//实现
Trie::Trie() {
	root = new TrieNode();
}

//插入函数
Trie::~Trie() {
	Destroy(root);
}

void Trie::Insert(string s) {
	if(s.empty()) return;
	int index = -1;
	TrieNode* p = root;
	for (auto c : s) {
		if (!isalpha(c)) return;
		index = tolower(c) - 'a';
		if (p->next[index] == NULL) {      //不存在就创建一个新节点
			p->next[index] = new TrieNode();
		}
		p = p->next[index];
	}
	if (!p->word.empty()) {    //单词存在则出现次数加一
		p->count++;
		return;
	}
	p->word+=s;     //否则插入该单词且出现次数加一
	p->count++;
}

//删除函数
void Trie::Remove(string s) {
	if(s.empty()) return;
	int index = -1;
	TrieNode* p = root;
	for (auto c : s) {
		if (!isalpha(c)) return;
		index = tolower(c) - 'a';
		if (p->next[index] == NULL) return;    //说明不存在
		p = p->next[index];
	}
	if (!p->word.empty()) {     //若该单词存在，删除
		p->word = "";
		p->count = 0;
	}
}

//查找函数
int Trie::Search(string s) {
	if(s.empty()) return -1;  //空串
	int index = -1;
	TrieNode* p = root;
	for (auto c : s) {
		if (!isalpha(c)) return -1;     //不是单词，返回-1
		index = tolower(c) - 'a';
		if (p->next[index] == NULL) return 0;   //不存在，出现次数为0
		p = p->next[index];
	}
	if (!p->word.empty()) return p->count;   //存在，返回出现次数
}

//打印所有单词
void Trie::PrintAll() {
	Print(root);
}

//打印有给定前缀的所有单词
void Trie::PrintPre(string s) {
	if(s.empty()) return;
	int index = -1;
	TrieNode* p = root;
	for (auto c : s) {            //找到前缀所指的节点
		if (!isalpha(c)) return;
		index = tolower(c) - 'a';
		if (p->next[index] == NULL) return;
		p = p->next[index];
	}
	if (p!=NULL)
		Print(p);   //打印接下来的所有单词
}

//以字典顺序打印单词
void Trie::Print(TrieNode* root) {
	if (root == NULL) return;
	TrieNode* p = root;
	if (!p->word.empty())
		cout << p->word << " " << p->count << endl;   //不为空就打印
	for (int i = 0; i < 26; ++i) {     //递归打印所有
		Print(p->next[i]);
	}
}

//销毁前缀树
void Trie::Destroy(TrieNode* root) {     
	if (root == NULL) return;
	for (int i = 0; i < 26; ++i) {
		Destroy(root->next[i]);
	}
	root->word = "";
	free(root);
}
