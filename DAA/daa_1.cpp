#include<bits/stdc++.h>
using namespace std;

//recursive
int rfib(int n)
{
    
    if(n<=1)
    {
        return n;
    }
    return rfib(n-1)+ rfib(n-2);
}
//non-recursive
int nrfib(int n)
{
    
    vector<int>fib;
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2 ; i<=n;i++)
    {
        fib.push_back(fib[i-1]+fib[i-2]);
    }

    cout<<"Fibonacci Series till nth index is : ";
    for(int i = 0 ; i<fib.size();i++)
    {
        cout<<fib[i]<<" ";
    }
    cout<<endl;
    cout<<"Fibonacci Number : ";
    return fib[n];
}
//non-recursive
int nrfib2(int n)
{
    int a  = 0  , b =1;
    int c;
    if(n ==0 || n==1)
    {
        return n;
    }
    vector<int>fib2;
    fib2.push_back(0);
    fib2.push_back(1);
    while(n>1)
    {
        c = a+b;
        fib2.push_back(c);
        a= b;
        b=c;
        n--;
    }
    cout<<"Fibonacci Series till nth index is : ";
    for(int i = 0 ; i<fib2.size();i++)
    {
        cout<<fib2[i]<<" ";
    }
    cout<<endl;
    cout<<"Fibonacci Number : ";
    return c;
}
int main()
{
    cout<<"Enter the index of the fibonacci number to be calculated : "<<endl;
    int n ; 
    try{
        cin>>n;
        if(cin.fail())
        {
            throw runtime_error("Invalid Input");
        }
        if(n<0)
        {
            throw out_of_range("Out of range");
        }
    }
    catch(const exception &e)
    {
        cout<<"An exception occurred :  "<<e.what()<<endl;
        return 1;
    }
    

    cout<<"Fibonacci Number (recursive) : "<<rfib(n)<<endl;
    cout<<"Fibonacci Number (non -recursive) : "<<nrfib2(n)<<endl;
    

}
/*
Recursive fibbonacci:
Time Complexity: O(2^n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(n)
*/