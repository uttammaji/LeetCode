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



    

