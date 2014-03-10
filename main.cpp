#include "mat.h"
#include "vec.h"
#include <typeinfo>
#include <time.h>
using namespace std;

typedef complex<double> dcomp;

template <typename T>
void mat_timer(Mat<T> &M)
{
    double tstart, tstop, ttime;
    tstart=(double)clock()/CLOCKS_PER_SEC;
    //start point
    M.Trans();
    //stop point
    tstop=(double)clock()/CLOCKS_PER_SEC;
    ttime = tstop- tstart;
    cout<<"the cost time is "<<ttime<<"sec"<<endl;
}

int main()
{
    
    complex<double> e(1.0,2.0);
    complex<double> f(1.0,-2.0);
    dcomp g(3);
    dcomp h(5,6);
    Vec<dcomp> comVec(4);
    comVec[0]=e;
    comVec[1]=f;
    comVec[2]=g;
    comVec[3]=h;
    comVec.Print();
    comVec= comVec*5;
    comVec.Print();
    dcomp resCom = comVec.Norm();
    cout<<"the complex norm is"<<std::abs(resCom)<<endl;
    

    Mat<int> testMat, anotherMat;
    testMat.randMat(5,5);
    anotherMat.randMat(5,5);
    testMat.showMat();
    //anotherMat.showMat();
    anotherMat = 2*testMat;
    anotherMat.showMat();
    mat_timer<int>(testMat);
    //testMat.showMat();
    /*
    testMat(1,1)=0;
    testMat(1,2)=1;
    testMat(2,1)=2;
    testMat(2,2)=3;
    testMat.showMat();
    testMat.Trans(); 
    testMat.showMat();
    */
    return 0;
}
