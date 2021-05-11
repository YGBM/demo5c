#include <iostream>
#include "vector.h"
#include <math.h>
#include <fstream>
#include <ctime>

using namespace std;


void createData(string fileName,int number){

    // 以写模式打开文件
    //创造数据
    ofstream outfile;
    outfile.open("/Users/burtedward/Downloads/test/demo05c/data/"+fileName);

    // 再次向文件写入用户输入的数据
    for (int i = 0; i < number; ++i) {
        outfile << rand() << endl;
    }

    // 关闭打开的文件
    outfile.close();
}

/*
 * read data from file and insert into vector
 */
Vector<int> initVector(string fileName,int readNumber) {
    Vector<int> vector;
    clock_t start = clock();      //获取当前系统时间
    cout << "start read file .... " << endl;
    int data;
    ifstream infile;
    infile.open("/Users/burtedward/Downloads/test/demo05c/data/"+fileName);

    if(!infile.good()) return vector;

    for (int i = 0; i < readNumber && !infile.eof(); ++i) {
        infile >> data;
        vector.insert(data);
    }
    infile.close();

    clock_t end  = clock();
    double programTimes = ((double) end -start) / CLOCKS_PER_SEC;
    cout << "initial vector finished ... cost time is : "<< programTimes << endl;
    return vector;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// Vector<int> data = initVector("afile2.dat", 50000000);
//    start read file ....
//    initial vector finished ... cost time is : 17.6108
//    the vector size is : 50000000
//    start mergeSort ...
//    vector sort ... cost time is : 16.2655

//    start read file ....
//    initial vector finished ... cost time is : 0.231087
//    the vector size is : 500000
//    start mergeSort ...
//    vector sort ... cost time is : 0.227725
//
//
//    start read file ....
//    initial vector finished ... cost time is : 17.2985
//    the vector size is : 50000000
//    start quickSort ...
//    vector sort ... cost time is : 10.49
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main() {


    Vector<int> data = initVector("hundred.dat", 100);
//    Vector<int> data = initVector("afile2.dat", 50000000);

    cout << "the vector size is : " << data.size() <<endl;


    data.sort();

    data.traverse();


    return 0;
}