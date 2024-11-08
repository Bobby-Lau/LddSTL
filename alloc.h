#pragma once
#include<iostream>
#include<cstdlib>
#include<new>
#include<new.h>
#include<list>

//模仿gunc2.9中默认的allocator：alloc。
//采用两级配置器，默认的malloc以及线程池free list

#ifdef _USE_MALLOC
using malloc_alloc = _malloc_alloc_template<0>;
using alloc = malloc_alloc;
#else 
//using alloc = 
#endif // _USE_MALLOC

namespace ldd
{
	//内存不足时的处理函数，这里选择抛异常
	void noMemoryFunc()
	{
		std::cout << "out of memory!\n";
		abort();
	}

	//auto x = _gnu_cxx::__pool_alloc<>;
	//对两级配置器的接口包装，使其接口符合STL规范
	template<typename T, typename Alloc>
	class simple_alloc
	{
	public:
		static T* allocate(size_t n)
		{
			return 0 == n ? nullptr : static_cast<T*>(Alloc::allocate(n));
		}

		static void deallocate(T* p)
		{
			return Alloc::deallocate(p);
		}
	};

	//第一级配置器，对malloc以及free的简单包装
	template <int un_use> 
	class _malloc_alloc_template
	{
	public:
		static void* allocate(size_t n)
		{
			set_new_handler(noMemoryFunc);
			return ::operator new(n);
		}

		static void deallocate(void* p)
		{
			::operator delete(p);
		}

		staric void reallocate(void* p, size_t new_sz)
		{
			//deallocate(p);
		}
	};

	//第二级配置器，维护一个freelist来管理memory pool
	
}