#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int** a,int row,int col,int element)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==element)
        {
            return false;
        }
    }
    
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==element)
        {
            return false;
        }
    }
    int x=row/3;
    int y=col/3;
    
    int startR=x*3;
    int startC=y*3;
    
    for(int i=startR;i<startR+3;i++)
    {
        for(int j=startC;j<startC+3;j++)
        {
            if(a[i][j]==element)
            {
                return false;
            }
        }
    }
    
    return true;    
    
}
bool sudoku(int **a,int row,int col)
{
    // cout<<row<<" "<<col<<endl;
    if(row==8&&col==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<a[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;
        return true;
    }
    if(col==9&&row<8)
    {
        // cout<<"hello";
        bool answer=sudoku(a,row+1,0);
        return answer;
    }
    if(a[row][col]==0)
    {
        
        bool b=false;
        for(int i=1;i<=9;i++)
        {
            // cout<<"hello"<<endl;
            if(check(a,row,col,i)==true)
            {
                a[row][col]=i;
                bool answer1=sudoku(a,row,col+1);
                b=b||answer1;
                a[row][col]=0;
            }
            if(b==true)
            {
                return b;
            }
        }
        return b;
    }
    else
    {
        bool answer1=sudoku(a,row,col+1);
        return answer1;
    }
}
    
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // int** x=grid;
        int **x=new int*[N];
        for(int i=0;i<N;i++)
        {
            x[i]=new int[N];
            for(int j=0;j<N;j++)
            {
                x[i][j]=grid[i][j];
            }
        }
        bool answer=sudoku(x,0,0);
        for(int i=0;i<N;i++)
        {
            // x[i]=new int[N];
            for(int j=0;j<N;j++)
            {
                grid[i][j]=x[i][j];
            }
        }
        return answer;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
