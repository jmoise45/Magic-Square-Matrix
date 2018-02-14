#include <iostream>
#include <cstdlib>
#include <cmath>
#include "pa1.h"

//Returns a vector that contains the sums of rows in a matrix
vector<int> rowSum(int n, vector<vector<int> > p)
{

    vector<int> vec;

    int sum = 0;

    int row = 0;

    for(int i = 0; i != n; i++)
    {

        if (i != row)
        {

            vec.push_back(sum);

            row = i;

            sum = 0;
        }

        for(int j = 0; j != n; j++)
        {

            sum += p[i][j];

        }

        vec.push_back(sum);
    }

    return vec;
}

//Returns a vector that contains the sums of columns in a matrix
vector<int> columnSum(int n, vector<vector<int> > p)
{

    vector<int> vec;

    int sum = 0;

    int row = 0;

    for(int i = 0; i != n; i++)
    {

        if (i != row)
        {

            vec.push_back(sum);

            row = i;

            sum = 0;
        }

        for(int j = 0; j != n; j++)
        {

            sum += p[j][i];

        }

        vec.push_back(sum);
    }

    return vec;
}

//Returns a vector that contains the sums of the two main diagonals in a matrix
vector<int> diagonalSum(int n, vector<vector<int> > p)
{

    vector<int> vec;

    int sum = 0;

    for(int i = 0; i != n; i ++)
    {

        sum += p[i][i];
    }

    vec.push_back(sum);

    sum = 0;

    for(int i = 0; i != n; i++)
    {

        sum += p[i][n-(i+1)];
    }

    vec.push_back(sum);

    return vec;
}

//Rotates a given matrix by switching its rows with its columns
vector<vector<int> > matrixRotation(vector<vector<int> > m, int n)
{

    vector<vector<int> > g(n, vector<int>(n));

    for(int i = 0; i != n; i++)
    {

        for(int j = 0; j != n; j++)
        {

            g[j][i] = m[i][j];
        }
    }

    return g;
}

//Rotates a given matrix by switching entries in its first row with the corresponding entries in its last row
vector<vector<int> > matrixRotation2(vector<vector<int> > m, int n)
{

    for (int i = 0; i != n; i++)
    {

        int temp = 0;

        temp = m[0][i];

        m[0][i] = m[n-1][i];

        m[n-1][i] = temp;
    }

    return m;

}

//Rotates a given matrix by switching entries in its first column with the corresponding entries in its last column
vector<vector<int> > matrixRotation3(vector<vector<int> > m, int n)
{

    for (int i = 0; i != n; i++)
    {

        int temp = 0;

        temp = m[i][0];

        m[i][0] = m[i][n-1];

        m[i][n-1] = temp;
    }

    return m;
}

int main()
{
    cout << "Enter the size of a magic square: ";

    int n = 0;

    //Assigns input value to n
    cin >> n;

    cout << endl;

    if (n < 3 || n > 15 || (n % 2 == 0))
    {

        //Error message is displayed if input n does not meet the conditions
        cerr << "The size nxn of a magic square must be an odd number between 3 and 15, inclusive" << endl;

        return 0;
    }

    else
    {

        //Create a vector that contains vectors and holds the values for a magic matrix
        vector<vector<int> > magic(n, vector<int>(n));

        /*The algorithm created by de la Loubère was used to construct a magic square of odd order*/


        int k = floor(n/2);

        int u = n-1;

        //The value 1 is always located in either the middle row or the middle column at the edge of a matrix
        magic[k][u] = 1;

        //For each iteration, the location of the next value is found (starting from 2 to n^2)
        for(int i = 2; i < n*n+1; i++)
        {
            //To find the location of the next value, move up one row and then move down one column (right)
            u = u+1;
            k = k-1;

            /*If moving up and right in a matrix to find the location of the next value leads you out of bounds past the top right
            value (0,n-1), then the location of that next value will be placed to the left of the start point (the location of the
            previous value)*/
            if(k == -1 && u == n)
            {

                k = 0;

                u = (n-1)-1;
            }

            else
            {
                /*If the location of the next value is past the last column (n-1), then the location will be changed to the
                the first column in the same row k (assuming that k is less than n)*/
                if(u == n)
                {

                    u = 0;
                }

                /*If the location of the next value is above the first row of the matrix, then the location will be changed to the
                last row in the same column u (assuming that u is less than n)*/
                if(k<0)
                {

                    k = n-1;
                }
            }

            /*If the given location of the next value already has a value (that is greater than 0), then the location will be changed
            to be to the left of the start point (the location of the previous value)*/
            if(magic[k][u] > 0)
            {

                k = k+1;

                u = u-2;

                magic[k][u] = i;
            }

            else
            {

                magic[k][u] = i;
            }

        }

        //Create a for loop to list four different nxn magic squares
        for(int i = 0; i != 4; i++)
        {

            if(i == 1)
            {
                //The magic square is rotated with the method matrixRotation()
                magic = matrixRotation(magic, n);
            }

            else if (i == 2)
            {

                //The magic square is rotated with the method matrixRotation2()
                magic = matrixRotation2(magic, n);
            }

            else if (i == 3)
            {

                //The magic square is rotated with the method matrixRotation3()
                magic = matrixRotation3(magic, n);
            }

            vector<int> r = rowSum(n, magic);

            vector<int> c = columnSum(n, magic);

            vector<int> d = diagonalSum(n, magic);

            int z = 0;

            cout << "Magic Square #" << i+1 << " is:" << endl;

            cout << "" << endl;

            //Make a for loop to display each row of the magic square
            for(int i = 0; i != n; i++)
            {

                //This indicates that one row has been displayed, and the line is ended to display the next row
                if (z != i)
                {

                    cout << endl;
                }

                for(int j = 0; j != n; j++)
                {

                    cout << magic[i][j] << " ";

                    z++;
                }
            }

            cout << endl;

            cout << "" << endl;

            cout << "Checking the sums of every row:   " << "   ";

            //The for loop displays the sum of each row within a magic square (from row 0 to row n-1)
            for(int i = 0; i != n; i++)
            {

                cout << r[i] << " ";
            }

            cout << endl;

            cout << "Checking the sums of every column:" << "   ";

            //The for loop displays the sum of each column within a magic square (from column 0 to column n-1)
            for(int i = 0; i != n; i++)
            {

                cout << c[i] << " ";
            }

            cout << endl;

            cout << "Checking the sums of every diagonal:" << " ";

            //The for loop displays the sum of each main diagonal within a magic square
            for(unsigned int i = 0; i != d.size(); i++)
            {

                cout << d[i] << " ";
            }

            cout << "\n" << endl;
        }
    }
    return 0;
}
