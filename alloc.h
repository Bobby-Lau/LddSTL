#pragma once
#include<iostream>
#include<cstdlib>
#include<new>
#include<new.h>
#include<list>

//ģ��gunc2.9��Ĭ�ϵ�allocator��alloc��
//����������������Ĭ�ϵ�malloc�Լ��̳߳�free list

#ifdef _USE_MALLOC
using malloc_alloc = _malloc_alloc_template<0>;
using alloc = malloc_alloc;
#else 
//using alloc = 
#endif // _USE_MALLOC

namespace ldd
{
	//�ڴ治��ʱ�Ĵ�����������ѡ�����쳣
	void noMemoryFunc()
	{
		std::cout << "out of memory!\n";
		abort();
	}

	//auto x = _gnu_cxx::__pool_alloc<>;
	//�������������Ľӿڰ�װ��ʹ��ӿڷ���STL�淶
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

	//��һ������������malloc�Լ�free�ļ򵥰�װ
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

	//�ڶ�����������ά��һ��freelist������memory pool
	
}