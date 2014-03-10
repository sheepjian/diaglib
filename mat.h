#ifndef MAT_H
#define MAT_H

#include "vec.h"
#include <time.h>
#include <vector>
#include <algorithm>

template <typename Type>
class Mat{
private:
    int i_Row;
    int i_Col;
    Vec<Type> vec_M;

public:
    Mat();
    Mat(int r, int c);
    Mat(const Mat &rhs);
    Mat& operator = (const Mat &rhs);
    ~Mat(){}

    void randMat(int R, int C);
    void showMat();

    void Trans ();

    Type& operator() (int r, int c)
    {
        assert(r>0&&r<=i_Row&&c>0&&c<=i_Col);
        return vec_M[(c-1)*i_Row+(r-1)];
    }
    Type operator() (int r, int c) const
    {
        assert(r>0&&r<=i_Row&&c>0&&c<=i_Col);
        return vec_M[(c-1)*i_Row+(r-1)];
    }

    Mat& operator*=(Type v) 
    {
        this->vec_M*=v;
        return *this;
    }

    Mat operator*(Type v) const
    {
        Mat<Type> temp(this->vec_M*=v);
        return temp;
    }


};


template <typename Type>
Mat<Type>::Mat(const Mat &rhs)
{
    i_Row = rhs.i_Row;
    i_Col = rhs.i_Col;
    vec_M = rhs.vec_M;
}

template <typename Type>
Mat<Type>& Mat<Type>::operator = (const Mat &rhs)
{
    i_Row = rhs.i_Row;
    i_Col = rhs.i_Col;
    vec_M = rhs.vec_M;
    return *this;
}

template <typename Type>
Mat<Type>::Mat() :
i_Row(0), i_Col(0)
{
    Vec<Type> temp;
    vec_M = temp;
}

template <typename Type>Mat<Type>::Mat(int r, int c)
{
    i_Row = r;
    i_Col = c;
    Vec<Type> temp(r*c);
    vec_M = temp;
}

template <typename Type>
void Mat<Type>::showMat()
{
    if(i_Row>0&& i_Col>0)
    {
        std::cout<<i_Row<<"x"<<i_Col<<" Matrix"<<std::endl;
        for(int i=0; i<i_Row; i++)
        {
            for(int j=0; j<i_Col; j++)
            {
                std::cout<<std::setw(5)<<std::setprecision(3)<<(*this)(i+1,j+1);
            }
            std::cout<<std::endl;
        }
    }
}


template <typename Type>
void Mat<Type>::randMat(int R, int C)
{
    i_Row = R;
    i_Col = C;
    Vec<Type> temp(R*C);
    vec_M = temp;
    
    srand(time(NULL));
    for(int i=1; i<=C; i++)
    {
        for(int j=1;j<=R;j++)
        {
            vec_M[(i-1)*R+(j-1)]=(Type)(rand()%100000000)/10000000;
        }
    }
}

template <typename Type>
void Mat<Type>::Trans()
{
    Mat<Type> temp(i_Col,i_Row);
    for(int i=1; i<=i_Col; i++)
    {
        for(int j=1;j<=i_Row;j++)
        {
            //Type temp=(*this)(i,j);
            //(*this)(i,j)=(*this)(j,i);
            //(*this)(j,i)=temp;
            temp(i,j)=(*this)(j,i);
            //vec_M.swap(i*i_Row+j, j*i_Row+i);
        }
    }
    *this = temp;
}

#include "mat.cpp"
#endif

