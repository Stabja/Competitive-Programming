#include<iostream>
#include<string>
using namespace std;

template<class T>
T square(T x, T y){
    T result;
    result = x * y;
    return(result);
}
template<>
string square<string>(string s1, string s2){
    return(s1 + s2);
}

int main(){
    int n1 = 3;
    float n2 = 3.6;
    double n3 = 5.763951;
    std::cout<<square<int>(n1, n1)<<"\n";
    std::cout<<square<float>(n2, n2)<<"\n";
    std::cout<<square<double>(n3, n3)<<"\n";
    std::cout<<square<string>("Hello", "World")<<"\n";
    return 0;
}
