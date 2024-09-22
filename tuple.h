#pragma once

namespace ldd
{
	template<typename Head, typename... Tail>
	class Tuple;

	template<typename Head, typename... Tail>
	class Tuple<Head, Tail...> : Tuple<Tail...>
	{
		typedef Tuple<Tail...> tail_tup;
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