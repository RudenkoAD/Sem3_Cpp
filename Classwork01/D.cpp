#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    cout<<left;
    int width = 15;
    cout <<setw(width)<<"Name"<<setw(width)<<"size"<<setw(width)<<"max value"<<setw(width)<<"min value"<<endl;
    cout <<setw(width)<<"char"<<setw(width)<<sizeof(char)<<setw(width)<<int(numeric_limits<char>::max())<<setw(width)<<int(numeric_limits<char>::min())<<endl;
    cout <<setw(width)<<"short int"<<setw(width)<<sizeof(short int)<<setw(width)<<numeric_limits<short int>::max()<<setw(width)<<numeric_limits<short int>::min()<<endl;
    cout <<setw(width)<<"int"<<setw(width)<<sizeof(int)<<setw(width)<<numeric_limits<int>::max()<<setw(width)<<numeric_limits<int>::min()<<endl;
    cout <<setw(width)<<"long int"<<setw(width)<<sizeof(long long int)<<setw(width)<<numeric_limits<long long int>::max()<<setw(width)<<numeric_limits<long long int>::min()<<endl;
    cout <<setw(width)<<"float"<<setw(width)<<sizeof(float)<<setw(width)<<numeric_limits<float>::max()<<setw(width)<<numeric_limits<float>::min()<<endl;
    cout <<setw(width)<<"double"<<setw(width)<<sizeof(double)<<setw(width)<<numeric_limits<double>::max()<<setw(width)<<numeric_limits<double>::min()<<endl;
}
