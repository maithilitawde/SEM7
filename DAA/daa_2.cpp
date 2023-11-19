#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode* left , *right;
    MinHeapNode(char data , int freq)     //remember to put data type
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

void printcodes(MinHeapNode* root , string str)
{
    if(root == nullptr)
    {
        return;
    }
    if(root->data != '$')
    {
        cout<<root->data<<" : "<<str<<endl;
    }
    printcodes(root->left , str+'0');
    printcodes(root->right , str+'1');
}

struct compare{
    bool operator()(MinHeapNode* a , MinHeapNode* b)
    {
        return(a->freq > b->freq);
    }

};

void Huffman(char data[] , int freq[] , int size)
{
    struct MinHeapNode* left , *right , *temp;   //remember struct
    priority_queue<MinHeapNode* , vector<MinHeapNode*> , compare>MinHeap;

    for(int i = 0 ;i<size; i++)
    {
        MinHeap.push(new MinHeapNode(data[i],freq[i]));
    }

    while(MinHeap.size() != 1)
    {
        left = MinHeap.top();
        MinHeap.pop();
        right = MinHeap.top();
        MinHeap.pop();
        temp = new MinHeapNode('$' , left->freq+right->freq);
        temp->left = left;
        temp->right = right;
        MinHeap.push(temp);
    }
    printcodes(MinHeap.top() , "");



}

int main()
{
    cout << "Enter the size of the character array : ";
    int size;
    try
    {
        cin >> size;
        if (cin.fail())
        {
            throw runtime_error("Invalid input");
        }
        if (size > 10)
        {
            throw out_of_range("Limit is till 10");
        }
    }
    catch (const exception &e)
    {
        cout << "An exception occurred " << e.what() << endl;
        return 1;
    }

    char data[size];
    int freq[size];
    cout << "Enter the character and their respective frequencies : ";
    for (int i = 0; i < size; i++)
    {
        try
        {
            cin >> data[i];
            if (cin.fail())
            {
                throw runtime_error("Invalid input");
            }
        }
        catch (const exception &e)
        {
            cout << "An exception occurred " << e.what() << endl;
            return 1;
        }
        try
        {
            cin >> freq[i];
            if (cin.fail())
            {
                throw runtime_error("Invalid input");
            }
            if (freq[i] > 100)
            {
                throw out_of_range("Limit is till 10");
            }
        }
        catch (const exception &e)
        {
            cout << "An exception occurred " << e.what() << endl;
            return 1;
        }
    }
    Huffman(data , freq, size);
}