#include <iostream>
#include <bits/stdc++.h> // #include <vector>

using namespace std;

void print()
{
    cout << "Hello World" << endl;
}

int main()
{
    print();
}

// pairs
void explainPairs()
{
    pair<int, string> p = {1, "Hello"};
    cout << p.first << " " << p.second << endl;
    
    //store more variable

    pair<int, pair<int,int>> o={1,{2,3}};
    cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;

    pair<int, string> p2(2, "World");
    cout << p2.first << " " << p2.second << endl;

    //make array using pair
    pair<int,int> arr[]={{1,2},{2,3,{3,4}}};
    cout<<arr[1].second;


    // make_pair
    auto p3 = make_pair(3, "C++");
    cout << p3.first << " " << p3.second << endl;
}

// Vector

void explainVector()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);//to put another value we need to emplace_back

    vector<pair<int, int>> vec;

    // v.push_back({1, 2});
    v.emplace_back(1, 2);

    vector<int> v(5,100);
    vector<int> v(5);

    vector<int> v1(5,20);
    vector<int> v2(v1);

    //to acsess value we need iterator

    vector<int>::iterator it=v.begin();//here v.begin() give the memory location to print the we need *(v.begin());
    
    it++;
    cout<<*(it)<<" ";

    it=it+2;
    cout<<*(it)<<" ";

    vector<int>::iterator it=v.end();// after value of the last element of array

    vector<int>::iterator it=v.rend();// reverse the array element 
    vector<int>::iterator it=v.rbegin();

    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<" ";

    for(vector<int>::iterator it=v.begin(); it!=v.end();it++){
        cout<<*(it)<<" ";

    }

    for(auto it=v.begin(); it!=v.end();it++){// auto automatically define and assume the datatype 
        cout<<*(it)<<" ";
    }
    
    for(auto it : v){
        cout<<it<," ";
    }

    //Delete value in vector
    //{10,20,30,40}
    v.erase(v.begin()+1); //delete the value 20

    //{10;20,12,23,35}
    v.erase(v.begin()+2,v.begin()+4);//{10,20,35}[start,end]


    //Insert Function

    vector<int> v(2,100); //{100,100}
    v.insert(v.begin(),300);//{300,100,100}
    v.insert(v.begin()+1,2,10);//{300,10,10,100,100}

    vector<int> copy(2,50);//{50,50}
    v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}

    //{10,20}
    cout<<v.size();//2

    // {10,20}
    v.pop_back();//{10}

    //v1->{10,20}
    //v2->{30,40}
    v1.swap(v2); //v1->{30,40}  v2->{10,20}

    v.clear();//erases the entire vector

    cout<<v.empty();
}


void explainList(){
    list<int> ls;
    ls.push_back(2);//{2}
    ls.emplace_back(4);//{2,4}

    ls.push_front(5); //{5,2,4}

    ls.emplace_front();//{2,4}

    //rest functions same as  vector 
    //begin , end. rbegin, ren,  clear, insert, size, swap
}

void explainDeque() {
    deque<int> dq;

    dq.push_back(1);     // [1]
    dq.push_back(2);     // [1, 2]

    dq.push_front(4);    // [4, 1, 2]
    dq.push_front(3);    // [3, 4, 1, 2]

    dq.pop_back();       // [3, 4, 1]
    dq.pop_front();      // [4, 1]

    cout << dq.back();   // 1
    cout << dq.front();  // 4

    // Other functions are similar to vector:
    // begin(), end(), rbegin(), rend()
    // clear(), insert(), size(), swap()
}



void explainStack() {
    stack<int> st;

    st.push(1);    // {1}
    st.push(2);    // {2, 1}
    st.push(3);    // {3, 2, 1}
    st.push(4);    // {4, 3, 2, 1}
    st.emplace(5); // {5, 4, 3, 2, 1}

    cout << st.top(); // prints 5
    // st[2] is invalid

    st.pop(); // st looks like {4, 3, 2, 1}

    cout << st.top();  // 4
    cout << st.size(); // 4
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;

    q.push(1);    // {1}
    q.push(2);    // {1, 2}
    q.push(3);    // {1, 2, 3}
    q.push(4);    // {1, 2, 3, 4}
    q.emplace(5); // {1, 2, 3, 4, 5}

    cout << q.front(); // prints 1
    // q[2] is invalid

    q.pop(); // q looks like {2, 3, 4, 5}

    cout << q.front(); // 2
    cout << q.back();  // 5
    cout << q.size();  // 4
    cout << q.empty(); // 0

    queue<int> q1, q2;
    q1.swap(q2);
}



void explainPriorityQueue() {
    priority_queue<int> pq;

    pq.push(1);    // {1}
    pq.push(2);    // {2, 1}
    pq.push(3);    // {3, 1, 2}
    pq.push(4);    // {4, 3, 2, 1}
    pq.emplace(5); // {5, 4, 3, 2, 1}

    cout << pq.top(); // prints 5
    // pq[2] is invalid

    pq.pop(); // removes 5

    cout << pq.top();  // 4
    cout << pq.size(); // 4
    cout << pq.empty(); // 0

    priority_queue<int> pq1, pq2;
    pq1.swap(pq2);
}


void explainMinHeap() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(1);    // {1}
    pq.push(2);    // {1, 2}
    pq.push(3);    // {1, 2, 3}
    pq.push(4);    // {1, 2, 3, 4}
    pq.emplace(5); // {1, 2, 3, 4, 5}

    cout << pq.top(); // prints 1

    pq.pop(); // removes 1

    cout << pq.top();   // 2
    cout << pq.size();  // 4
    cout << pq.empty(); // 0

    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    pq1.swap(pq2);
}


    

