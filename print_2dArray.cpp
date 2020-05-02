/*
Auth: sm
*/
#include <iostream>

using namespace std;

//3rd method
void print_matrix(int row, int col, int *arr)
{ //square matrix
    for (int i = 0; i < row; i++)
    {
        printf("\n");
        for (int j = 0; j < col; j++)
            printf("\t%d", *((arr + i * col) + j));
    }
}




int main()
{
    int arr[2][2] = {
        {1, 2},
        {5, 4}};
    //print_matrix(2,2,(int*)arr);

    int row, col;
    //* dynamic array alocation
    cout << "row :";
    cin >> row;
    cout << "col :";
    cin >> col;
    cout << endl;

    //dynamic memory allocation for 1d array
    int *arr_1d;
    arr_1d = new int[row];
    
    //dynamic memory allocation for 2d array
    int **arr_2d = new int *[row];
    for (int i = 0; i < row; i++)
    {
        *(arr_2d + i) = new int[col];
    }

    // entering value

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>*(*(arr_2d+i)+j);
        }
    }
    

    //getting value
    for (int i = 0; i < row; i++)
    {
        cout<<endl;
        for (int j = 0; j < col; j++)
        {
            cout<<"\t"<<*(*(arr_2d+i)+j);
        }
    }

    return 0;
}