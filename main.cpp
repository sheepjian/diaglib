#include "mat.h"
#include "vec.h"
#include <typeinfo>
#include <time.h>
using namespace std;

typedef complex<double> dcomp;

int main()
{
    double tstart, tstop, ttime;
    /*
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
    dcomp resCom = comVec.Norm();
    cout<<"the complex norm is"<<std::abs(resCom)<<endl;
    */

    Mat<int> testMat;
    testMat.randMat(2000,2000);
    //testMat.showMat();
    tstart=(double)clock()/CLOCKS_PER_SEC;
    testMat.Trans();
    tstop=(double)clock()/CLOCKS_PER_SEC;
    ttime = tstop- tstart;
    cout<<"the cost time is "<<ttime<<"sec"<<endl;
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
