#ifndef MAT_CPP
#define MAT_CPP

template <typename Type>
const Mat<Type> operator *(Type coeff, const Mat<Type>& rhs)
{
    Mat<Type> temp;
    temp = rhs;
    temp.showMat();
    temp*=coeff;
    return temp;
}

#endif
