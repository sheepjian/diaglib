#ifndef VEC_DATA
#define VEC_DATA

#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
#include <limits>
#include <algorithm>
#include <complex>
#include <iomanip>
#define PINF std::numeric_limits<int>::max()
#define NINF std::numeric_limits<int>::min()

template <typename T>
class Vec
{
private:
    std::vector<T> v_Data;
    int i_Size;
public:
    Vec();
    Vec(unsigned int s);
    Vec(const Vec &rhs);
    ~Vec();

    Vec& operator() (int start, int end)
    {
        assert(start>=0&& start<=i_Size-1& start<=end && end<=i_Size-1);
        int length=end-start+1;
        Vec<T> temp(length);
        std::vector<T> v_temp(v_Data.begin()+start,v_Data.begin()+end+1);
        temp.v_Data=v_temp;
        return temp;
    }

    T &operator[](int i)
    {
        assert(i<i_Size);
        return v_Data.at(i);
    }

    const T &operator[](int i) const
    {
        assert(i<i_Size);
        return v_Data.at(i);
    }

    void swap(int i, int j)
    {
        assert(i<i_Size&&j<i_Size);
        T temp;
        temp = (*this)[i];
        (*this)[i]=(*this)[j];
        (*this)[j]=temp;
    }

    unsigned int Size() const 
    {
        return i_Size;
    }

    void Print() const;
    void Reset();
    //Vector Normalised() const;
    
    T Dot(const Vec<T> &rhs);
    Vec &operator=(const Vec &rhs);
    Vec operator+(const Vec &rhs) const;
    Vec operator-(const Vec &rhs) const;
    Vec operator+(T v) const;
    Vec operator-(T v) const;
    Vec operator*(T v) const;
    Vec operator/(T v) const;
    Vec &operator+=(const Vec &rhs);
    Vec &operator-=(const Vec &rhs);
    Vec &operator+=(T v);
    Vec &operator-=(T v);
    Vec &operator*=(T v);
    Vec &operator/=(T v);

    T Norm(int deg=2);
    
    void showVec(int width, int precise)
    {
        if(!i_Size)
            return;

        typename std::vector<T>::iterator it=v_Data.begin();
        while(it != v_Data.end())
        {
            std::cout<<std::setw(width)<<std::setprecision(precise)<<*it;
            it++;
        }
        std::cout<<std::endl;
    }
};

template <typename T>
static bool abs_compare(T a, T b)
{
    return (std::abs(a) < std::abs(b));
}

template <typename T>
T Vec<T>::Norm(int deg)
{
    assert(deg>0);

   if(i_Size==0)
        return 0;
    else
    {
        if(deg==PINF)
        {
            typename std::vector<T>::iterator result;
            result = std::max_element(v_Data.begin(),v_Data.end(), abs_compare<T>);
            return std::abs(*result);
        } else {
            double result=0;
            typename std::vector<T>::iterator it = v_Data.begin();
            for(;it!=v_Data.end();it++)
            {
                result += pow(std::abs(*it),deg);
            }
            return pow(result,1.0/deg);
        }
    }
}

template <typename T>
Vec<T>::Vec() :
i_Size(0)
{
    std::vector<T> temp;
    v_Data=temp;
}

template <typename T>
Vec<T>::Vec(unsigned int s) :
i_Size(s)
{
    std::vector<T> temp(s);
    v_Data=temp;
}

template <typename T>
Vec<T>::~Vec()
{}

//problem dealing with complex numbear
//when applying type transformation
template <typename T>
Vec<T>::Vec(const Vec &rhs)
{
    i_Size = rhs.i_Size;
    v_Data = rhs.v_Data;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
    i_Size = rhs.i_Size;
    v_Data = rhs.v_Data;
    return *this;
}


template <typename T>
void Vec<T>::Print() const
{
    for (int i=0; i<i_Size; i++)
    {
        std::cout<<v_Data.at(i)<<" ";
    }
    std::cout<<std::endl;
}

template <typename T>
void Vec<T>::Reset() 
{
    int s=0;
    T temp=0;
    //notice the error when input is not an integer
    std::cout<<"Input the size: ";
    std::cin>>s;
    if(s<=0)
        return;
    else
    {
        i_Size = s;
        v_Data.clear();
        v_Data.resize(s);
        for (int i=0; i<s; i++)
        {
            std::cout<<"Input the Vec["<<i+1<<"]: ";
            std::cin>>temp;
            v_Data.at(i)=temp;
        }
    }
}

template <typename T>
T Vec<T>::Dot(const Vec &rhs)
{
    assert(i_Size==rhs.i_Size);
    T acc = 0;
    for (int i=0; i<i_Size; i++)
    {
        acc += v_Data[i]*rhs[i];
    }
    return acc;
}

template <typename T>
Vec<T> Vec<T>::operator+(const Vec &rhs) const
{
    assert(i_Size==rhs.i_Size);

    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]+rhs[i];
    }
    return ret;

}

template <typename T>
Vec<T> Vec<T>::operator-(const Vec &rhs) const
{
    assert(i_Size==rhs.i_Size);

    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]-rhs[i];
    }
    return ret;

}

template <typename T>
Vec<T>& Vec<T>::operator+=(const Vec &rhs)
{
    assert(i_Size==rhs.i_Size);
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]+=rhs[i];
    }
    return *this;
}


template <typename T>
Vec<T>& Vec<T>::operator-=(const Vec &rhs)
{
    assert(i_Size==rhs.i_Size);
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]-=rhs[i];
    }
    return *this;
}


template <typename T>
Vec<T>& Vec<T>::operator+=(T v)
{
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]+=v;
    }
    return *this;
}

template <typename T>
Vec<T>& Vec<T>::operator-=(T v)
{
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]-=v;
    }
    return *this;
}


template <typename T>
Vec<T>& Vec<T>::operator*=(T v)
{
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]+=v;
    }
    return *this;
}


template <typename T>
Vec<T>& Vec<T>::operator/=(T v)
{
    assert(v!=0);
    for (int i=0; i< i_Size; i++)
    {
        (*this)[i]/=v;
    }
    return *this;
}

template <typename T>
Vec<T> Vec<T>::operator+(T v) const
{
    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]+v;
    }
    return ret;
}

template <typename T>
Vec<T> Vec<T>::operator-(T v) const
{
    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]-v;
    }
    return ret;
}

template <typename T>
Vec<T> Vec<T>::operator*(T v) const
{
    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]*v;
    }
    return ret;
}

template <typename T>
Vec<T> Vec<T>::operator/(T v) const
{
    assert(v!=0);
    Vec<T> ret(i_Size);
    for (int i=0; i< i_Size; i++)
    {
        ret[i]=(*this)[i]/v;
    }
    return ret;
}


#endif
