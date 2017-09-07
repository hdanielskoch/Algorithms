//
//  main.cpp
//  SkiProblem
//
//  Created by Bo Bleckel on 11/7/16.
//  Copyright © 2016 edu.bowdoin.cs2505.bleckel. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>

int optCostRecursive(int i, int j);
int optCostDynamic(int i, int j);
void printTable(int n, int m);

using namespace std;

int **T;
//int *h;
int h[5] = {3,4,7,11,18};
//int *s;
int s[6] = {1,2,5,7,13,21};

int main(int argc, const char * argv[]) {
	int m;
	int n;
	if (argc == 3) {
		m = stoi(argv[1]);
		n = stoi(argv[2]);
		cout << "you entered: m=" << m << " n=" << n << endl;
		if (m > n) {
			cout << "m cannot be greater than n" << endl;
			exit(0);
		}
	} else {
		cout << "wrong usage" << endl;
		exit(0);
	}
	
//	h = new int[m];
//	s = new int[n];
//	unsigned long seed = time(0);
//	srand(int(seed));
//	
////	cout << "skier height array: ";
//	h[0] = rand() % 7;
////	cout << h[0] << " ";
//	for (int i = 1; i < m; i++) {
//		h[i] = rand() % 7 + h[i-1];
////		cout << h[i] << " ";
//	}
////	cout << endl;
//	
////	cout << "ski height array: ";
//	s[0] = rand() % 7;
////	cout << s[0] << " ";
//	for (int j = 1; j < n; j++) {
//		s[j] = rand() % 7 + s[j-1];
////		cout << s[j] << " ";
//	}
////	cout << endl;
	
	T = new int*[m];
	for (int i = 0; i < m; i++) {
		T[i] = new int[n];
		for (int j = 0; j < n; j++) {
			T[i][j] = -1;
		}
	}
	cout << "running optCostRecursive with m=" << m << ", n=" << n;
	float start = clock();
	int optimalCost = optCostRecursive(m-1, n-1);
	float end = clock();
	float totalTime = (end - start)/CLOCKS_PER_SEC*1000;
	cout <<": total time = " << totalTime << " optimal cost recursively: " << optimalCost << endl;
	
	cout << "running optCostDynamic with m=" << m << ", n=" << n;
	start = clock();
	optimalCost = optCostDynamic(m-1, n-1);
	end = clock();
	totalTime = (end - start)/CLOCKS_PER_SEC*1000;
	cout <<": total time = " << totalTime << " optimal cost dynamically: " << optimalCost << endl;
	
	cout << endl << endl;
	printTable(n, m);
}

int optCostRecursive(int i, int j) {
	if (i < 0) {
		return 0;
	}
	if (h[i] >= s[j]) {
		return abs(h[i] - s[j]) + optCostRecursive(i-1, j-1);
	}
//	while (s[j] >= h[i]) {
//		if (i == j) {
//			break;
//		}
//		j--;
//	}
	int dif1 = abs(s[j] - h[i]) + optCostRecursive(i-1, j-1);
	int dif2 = abs(s[j-1] - h[i]) + optCostRecursive(i-1, j-2);
	return min(dif1, dif2);
}

int optCostDynamic(int i, int j) {
	if (i < 0) {
		return 0;
	}
	if (T[i][j] != -1) {
		return T[i][j];
	}
	if (h[i] >= s[j]) {
		T[i][j] = abs(h[i] - s[j]) + optCostDynamic(i-1, j-1);
		return T[i][j];
	}
	int dif1 = abs(s[j] - h[i]) + optCostDynamic(i-1, j-1);
	int dif2 = abs(s[j-1] - h[i]) + optCostDynamic(i-1, j-2);
	T[i][j] = min(dif1, dif2);
	return min(dif1, dif2);
}

void printTable(int n, int m) {
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j++) {
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
}
