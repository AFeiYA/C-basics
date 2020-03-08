//防卫式声明
#ifndef __COMPLEX__
#define __COMPLEX__

//前置声明
#include <iostream>
class complex;

//类声明 class declarations;
class complex  //class head
{ //class body
public:
    complex(double r=0, double i=0)
    :re(r), im(i) //初值化
    {}  //构造函数 创建对象无法被调用 默认值为0，0；如果写成{re=r, im=i},但是属于赋值阶段，程序运行效率会下降
    complex& operator += (const complex&); //返回值complex&  
    double real() const {return re;} //对于只是拿数据，不会改变数据，必须加上const
    double imag() const {return im;}  //否则 用户定义 const complex c1（2，1） 有可能更改c1的值

private:
    double re, im; 
    friend complex& __doapl (complex* ths, const complex& r) ;//firend友元  __doapl可以拿
    //friend可以直接拿数据。 也可以通过函数拿，速度会慢一些，在封装和效率中寻找平衡点

};
inline complex& 
complex::operator += (const complex& r) //成员函数
{
    return __doapl(this, r);
}
inline double
imag (const complex& x)
{
  return x.imag ();
}
inline double
real (const complex& x)
{
  return x.real ();
}

inline complex& 
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}


inline complex 
operator+(const complex& x, const complex& y)
{
    return complex (real(x)+real(y), imag(x)+imag(y));
}

std::ostream& 
operator << (std::ostream& os, const complex& x )
{
    return  os<< '(' << real(x) << ','<<imag(x)<<')';
}


//类定义
#endif