#pragma once
#include<tuple>

namespace ldd
{
	//原模版
	template<typename... Values>
	class Tuple;
	//最后一个模板，也不用传类型
	template<>
	class Tuple<> {};

	//使用递归继承实验tuple，一个tuple里可有多种不同类型
	template<typename Head, typename... Tail>
	class Tuple<Head, Tail...> : Tuple<Tail...>
	{
		using tail_tup = Tuple<Tail...>;

	public:
		Tuple() {}
		Tuple(Head h, Tail... t) : head(h), tail_tup(t...){}
		~Tuple() = default;
		
		Head getHead() { return head; }
		tile_tup& getTail() { return *this; }
	private:
		Head head;
	};
}