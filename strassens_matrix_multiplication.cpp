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
void input_matrix(int**, int*, int*);
void print_matrix(int **, int, int);
int power(int n);
int strassen_matrix_multiplication(int **A, int **B, int **C, int m, int n);
int main()
{
    int n1 = 0, n2 = 0, n3 = 0, n, m;


    //--------------------getting value of rows nad columns-------------------------
    while (n1 == 0)
    {
        cout << "Rows of mat1: ";
        cin >> n1;
    }
    while (n2 == 0)
    {
        cout << "Columns of mat1: ";
        cin >> n2;
    }
    while (n3 == 0)
    {
        cout << "Columns of mat2: ";
        cin >> n3;
    }
    //-------------------------------------------------------------------------------
    //--------------------initializing matrices-----------------------
    int **A = new int*[n1];
    int **B = new int*[n2];

    for(int i=0; i<n1; i++)
        *(A+i) = new int[n2];
    for(int i=0; i<n2; i++)
        *(B+i) = new int[n3];
    //-------------------------------------------------------------------------------
    //--------------------getting input for matrices-----------------------
    cout<<"Matrix1 --"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"\n";
        for (int j = 0; j < n2; j++)
        {
            cin>>*(*(A+i)+j);
        }
    }

    cout<<"Matrix2 --"<<endl;
    for (int i = 0; i < n2; i++)
    {
        cout<<"\n";
        for (int j = 0; j < n3; j++)
        {
            cin>>*(*(B+i)+j);
        }
    }
    //-------------------------------------------------------------------------------
    /*Creating square matrix of order 2^n for all and initializing all elements to 0 except prefixed*/
    if(n1>=n2 && n1>=n3)
        n=n1;
    else if(n2>=n1 && n2>=n3)
        n=n2;
    else
        n=n3;

    m=1;
    while(n>power(m))
        m=m+1;
    int o=power(m);
    //---------------------------------------
    //initializing square matrices
    int **a = new int*[o];
    int **b = new int*[o];
    int **result = new int*[o];

    for(int i=0; i<o; i++)
        *(a+i) = new int[o];
    for(int i=0; i<o; i++)
        *(b+i) = new int[o];
    for(int i=0; i<o; i++)
        *(result+i) = new int[o];
    //-------------------------------------------------------------------------------
    //filling up with 0 
    for (int i = 0; i < o; i++)
    {
        cout<<"\n";
        for (int j = 0; j < o; j++)
        {
            *(*(a+i)+j) = 0;
            *(*(b+i)+j) = 0;
            *(*(result+i)+j) = 0;
        }
    }
    //-------------------------------------------------------------------------------
    //filling up with previous values a
    for (int i = 0; i < n1; i++)
    {
        cout<<"\n";
        for (int j = 0; j < n2; j++)
        {
            *(*(a+i)+j) = *(*(A+i)+j);
        }
    }
    //filling up with previous values b
    for (int i = 0; i < n2; i++)
    {
        cout<<"\n";
        for (int j = 0; j < n3; j++)
        {
            *(*(b+i)+j) = *(*(B+i)+j);
        }
    }
    //-------------------------------------------------------------------------------


    print_matrix(A, n1, n2);
    print_matrix(B, n2, n3);
    print_matrix(a, o, o);
    print_matrix(b, o, o);
    print_matrix(result, o, o);

    strassen_matrix_multiplication(a,b,result,m,m);    //Calling the function.
    print_matrix(result, o, o);

    return 0;
}

int power(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
        p = 2 * p;
    return p;
}

void print_matrix(int **arr, int row, int col)
{ //square matrix
    cout<<"\n";
    for (int i = 0; i < row; i++)
    {
        cout<<"\n";
        for (int j = 0; j < col; j++)
            cout << "\t" <<  *(*(arr+i)+j);
        //printf("\t%d", *((arr + i * col) + j));
    }
}

int strassen_matrix_multiplication(int **A, int **B, int **C, int m, int n){
    if(m==2){
        // int P=(*A+*(A+n+1))*(*B+*(B+n+1));  //P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1])
        // int Q=(*(A+n)+*(A+n+1))*(*B);   //Q=(A[1][0]+A[1][1])*B[0][0]
        // int R=(*A)*(*(B+1)-*(B+n+1));   //R=A[0][0]*(B[0][1]-B[1][1])
        // int S=(*(A+n+1))*(*(B+n)-*B);   //S=A[1][1]*(B[1][0]-B[0][0])
        // int T=(*A+*(A+1))*(*(B+n+1));   //T=(A[0][0]+A[0][1])*B[1][1]
        // int U=(*(A+n)-*A)*(*B+*(B+1));  //U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1])
        // int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));  //V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

        // *C=*C+P+S-T+V;  //C[0][0]=P+S-T+V
        // *(C+1)=*(C+1)+R+T;  //C[0][1]=R+T
        // *(C+n)=*(C+n)+Q+S;  //C[1][0]=Q+S
        // *(C+n+1)=*(C+n+1)+P+R-Q+U;  //C[1][1]=P+R-Q+U

        int P=(A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
        int Q=(A[1][0]+A[1][1])*B[0][0];
        int R=A[0][0]*(B[0][1]-B[1][1]);
        int S=A[1][1]*(B[1][0]-B[0][0]);
        int T=(A[0][0]+A[0][1])*B[1][1];
        int U=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
        int V=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);

        C[0][0]=P+S-T+V;
        C[0][1]=R+T;
        C[1][0]=Q+S;
        C[1][1]=P+R-Q+U;
    }
    else{
        m=m/2;
        strassen_matrix_multiplication(A,B,C,m,n);
        strassen_matrix_multiplication(A,B+m,C+m,m,n);
        strassen_matrix_multiplication(A+m,B+m*n,C,m,n);
        strassen_matrix_multiplication(A+m,B+m*(n+1),C+m,m,n);
        strassen_matrix_multiplication(A+m*n,B,C+m*n,m,n);
        strassen_matrix_multiplication(A+m*n,B+m,C+m*(n+1),m,n);
        strassen_matrix_multiplication(A+m*(n+1),B+m*n,C+m*n,m,n);
        strassen_matrix_multiplication(A+m*(n+1),B+m*(n+1),C+m*(n+1),m,n);
    }
}