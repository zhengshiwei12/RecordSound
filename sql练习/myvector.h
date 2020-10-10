#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<memory>
#include<iostream>
#include<algorithm>

template<class T,class Alloc=std::allocator<T>>
class myVector{
public:
    typedef T valueType;
    typedef valueType* iterator;
    typedef const valueType* const_iterator; 
    typedef valueType& reference;
    typedef valueType* pointer;
    typedef size_t size_type;
     //表示两个迭代器之间的距离 ,c++内置定义 typedef int ptrdiff_t
    typedef ptrdiff_t difference_type;

protected:
    std::allocator<valueType> _alloc;//空间分配器
    iterator _start;//数组的首元素
    iterator _end;//已使用空间的尾
    iterator _end_of_storage;//可用空间的尾

public:
    myVector():_start(0),_end(0),_end_of_storage(0){}
    myVector(size_type n,const T& value);
    myVector(size_type n);
    myVector(iterator first,iterator end);
    myVector(const myVector& v);
    myVector& operator=(const myVector& rhs);
    ~myVector(){_destroy();}

    iterator begin(){return _start;}
    iterator end(){return _end;}
    const_iterator cbegin(){return _start;}
    const_iterator cend(){return _end;}

    size_type size(){return size_type(end()-begin());}
    size_type capacity(){return size_type(_end_of_storage()-begin());
    bool empty(){return begin()==end();}
    void swap(myVector& other);

    reference front(){return *begin();}
    reference back(){return *(end()-1);}
    reference operator[](size_type n){return *(begin()+n);}


    //一个插入辅助的函数，在向量为满的时候用到
    void insert_aux(iterator position,const T& x);
    void push_back(const T& x);
    void pop_back();
    void insert(iterator position,size_type n,const T& x);

    iterator erase(iterator position);
    iterator erase(iterator first,iterator last);
    void clear(){earse(begin(),end());}

private:
    void _destroy();
};

template<class T,class Alloc=std::allocator<T>>
myVector<T,Alloc>::myVector(size_type n,const T& value)
{
    //申请n*sizeof(T)的东东
    _start=_alloc.allocator(n);
    std::uninitialized_fill(_start,_start+n,value);
    _end=_end_of_storage=_start+n;
}

template<class T,class Alloc=std::allocator<T>>
myVector<T,Alloc>::myVector(size_type n)
{
    _start=_alloc.allocator(n);
    std::uninitialized_fill(_start,_start+n,0);
    _end=_end_of_storage=_start+n;
}

template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(iterator first, iterator last) {
	_start=_alloc.allocate(last - first);  //分配空间
	_end=_end_of_storage=std::uninitialized_copy(first, last, _start);
}

template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(const myVector& v) {
	size_type n= v.cend() - v.cbegin();
	_start=_alloc.allocate(n);    //分配空间
	_end = _end_of_storage = std::uninitialized_copy(v.cbegin(), v.cend(), _start);
}

template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::swap(myVector &other){
    std::swap(_start,other._start);
    std::swap(_end,other._end);
    std::swap(_end_of_storage,other._end_of_storage);
}
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc> &myVector<T, Alloc>::operator=(const myVector &rhs){

    if(this==&rhs)
    {
        return *this;
    }
    //？之前的不用释放吗？*************************
    size_type n=rhs.cend()-rhs.cbegin();
    destroy();
    _start=_alloc.allocate(n);
    _end = _end_of_storage = std::uninitialized_copy(rhs.cbegin(), rhs.cend(), _start);
}

template<class T,class Alloc=std::allocator<T>>
void myVector<T,Alloc>::insert(iterator positon,size_type n,const T& x)
{
    //插入数量大于0
    if(n>0)
    {
        if(_end_of_storage-_end>=n)//剩余空间够
        {
            T x_copy=x;
            const size_type element_after=_end-position;//插入点后元素的个数
            iterator old_end=_end;
            if(element_after>n)
            {
                uninitailized_copy(_end-n,_end,_end);
                _end=_end+n;
                copy_backword(position,old_end-n,old_end);
                fill(position, position + n, x_copy);
            }else{
                uninitialized_fill_n(_end, n - elem_after, x_copy);
				_end += n - elem_after;
				uninitialized_copy(position, old_end, _end);
				_end += elem_after;
				fill(position, old_end, x_copy);
            }
        }else{
            const size_type old_size=size();
            const size_type len=old_size+max(old_size,n);
            iterator new_start=_alloc.allocate(len);
            iterator new_end=new_start;
            new_end =uninitialized_copy(_start, position , new_start);   //将position之前的元素复制到新容器
			new_end=uninitialized_fill_n(new_end, n, x);    //插入元素
			new_end=uninitialized_copy(position, _end, new_end);
            _destroy(); 
            _start = new_start;
			_end = new_end;
			_end_of_storage = new_start + len;
        }
    }
}

template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::_destroy(){
    if(_start)
    {
        iterator it(_end);
        while(it!=start)
        {
            _alloc.destroy(--it);//调用T类型的析构函数
        }
    }
    _alloc.deallocate(_start,_end_of_storage-_start);
    _start=_end_of_storage=_end=nullptr;
}
template<class T,class Alloc=std::allocator<T>>
void myVector<T,Alloc>::insert_aux(iterator position,const T& x)
{
    if(_end!=_end_of_storage)
    {

    }else{
        const size_type old_size = size();                    //需要注意，如果开始长度为0
		const size_type len = old_size ? 2 * old_size : 1;    //则配置长度1，否则，加倍
		iterator new_start = _alloc.allocate(len);            //重新分配空间
		iterator new_end = new_start;

		new_end = uninitialized_copy(_start, positon, new_start);   //对于push_back来说position=_end,将其拷贝出来
	    _alloc.construct(new_end, x);                     //插入元素
		++new_end;
		new_end = uninitialized_copy(positon, _end, new_end);     //将插入点后的元素也拷贝过来

		_destroy();                    //执行自定义函数
		//调整迭代器，指向新的指针

		//重新调整迭代器，使其指向新的位置
		_start = new_start;
		_end = new_end;
		_end_of_storage = new_start + len;

    }
}
template <class T, class Alloc = std::allocator<T>>
typename myVector<T, Alloc>::iterator myVector<T, Alloc>::erase(iterator position)
{
    if(position+1!=end())
    {
        copy(position+1,end(),position);
    }
    --_end;
    _alloc.destroy(_end);
    return position;
}
#endif