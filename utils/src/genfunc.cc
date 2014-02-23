
#include <genfunc.hh>

template <typename T>
void swap(T& left, T& right)
{
    T tmp(left);
    left = right;
    right = tmp;
}


int main()
{
    int a = 2;
    int b = 3;

    swap(a, b);

    return (a == 3) && (b == 2);
}
