//防卫式声明
#ifndef __COMPLEX__
#define __COMPLEX__

//前置声明

template<typename T> //

//类声明 class declarations;
class complex  //class head
{ //class body
public:
    complex(T r=0, T i=0)
    :re(r), im(i) //初值话
    {}  //构造函数 创建对象无法被调用 默认值为0，0；如果写成{re=r, im=i},但是属于赋值阶段，程序运行效率会下降
    complex& operator += (const complex&);
    T real() const {return re;}
    T imag() const {return im;}

private:
    T re, im; 
    friend complex& __doapl (complex*, const complex&);

};

//类定义


#endif