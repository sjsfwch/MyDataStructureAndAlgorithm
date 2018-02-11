#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//创建一个邻接矩阵表示的图
vector<vector<int>> CreatGraph(vector<vector<int>> edge, int vetex) {
	vector<vector<int>> graph(vetex, vector<int>(vetex, 0));
	for (int i = 0; i < edge.size(); ++i) {
		int x = edge[i][0], y = edge[i][1], dis = edge[i][2];
		graph[x][y] = graph[y][x] = dis;
	}
	return graph;
}	
