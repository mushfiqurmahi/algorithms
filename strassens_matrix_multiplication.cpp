/*
Aurthor: SM
*/
/*
    Volker Strassen, german mathematician.
    Formula for: 2n × 2n Matices 
    If the matrices A, B are not of type 2n × 2n we fill the missing rows and columns with zeros.
*/
#include <iostream>

using namespace std;
void input_matrix(int mat[][20], int* n1, int* n2);
int main()
{
    int n1=0, n2=0, n3=0, n, m;

    int A[20][20]; //for using larger matrices increase the value
    int B[20][20];

    input_matrix(A, &n1, &n2);
    input_matrix(B, &n2, &n3);


    return 0;
}

void input_matrix(int mat[][20], int* n1, int* n2){
    cout<<"Enter the order of the 1st Matrix :"<<endl;
    
    if(n1!=0){
        cout<<"Rows: ";
        cin>>*n1;
    }else
    {
        cout<<"Rows: "<<*n1;
    }
    
    cout<<"\nColumns: ";
    cin>>*n2;

    cout<<"\nNow enter the first matrix"<<endl;

    for (int i = 0; i < *n1; i++)
    {
        cout<<"\nEnter the elements of the <<i + 1<<-th row:"<<endl;
        for (int j = 0; j < *n2; j++)
            cin>>mat[i][j];
    }
}

int power(int n){
    int p=1;
    for(int i=1;i<=n;i++)
        p=2*p;
    return p;
}