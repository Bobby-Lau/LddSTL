#pragma once
namespace ldd
{
	//ԭģ��
	template<typename... Values>
	class Tuple;

	//���һ��ģ�壬Ҳ���ô�����
	template<>
	class Tuple<>;

	//ʹ�õݹ�̳�ʵ��tuple��һ��tuple����ж��ֲ�ͬ����
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