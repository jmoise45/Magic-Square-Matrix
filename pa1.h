//James Moise UFID: 5441-9893
//Section: 19F2
//Programming Assignment #1

using namespace std;
#include <vector>
#ifndef PA1_H_INCLUDED
#define PA1_H_INCLUDED

//Returns a vector that contains the sums of rows in a matrix
vector<int> rowSum(int n, vector<vector<int> > p);

//Returns a vector that contains the sums of columns in a matrix
vector<int> columnSum(int n, vector<vector<int> > p);

//Returns a vector that contains the sums of the two main diagonals in a matrix
vector<int> diagonalSum(int n, vector<vector<int> > p);

//Rotates a given matrix by switching its rows with its columns
vector<vector<int> > matrixRotation(vector<vector<int> > m, int n);

//Rotates a given matrix by switching entries in its first row with the corresponding entries in its last row
vector<vector<int> > matrixRotation2(vector<vector<int> > m, int n);

//Rotates a given matrix by switching entries in its first column with the corresponding entries in its last column
vector<vector<int> > matrixRotation3(vector<vector<int> > m, int n);

#endif // PA1_H_INCLUDED
