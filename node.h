#include <stdio.h>

class Element
{
	private:
		int data;
		Element *next;
		Element *prev;

		friend class LinkedList;
};

class LinkedList
{
	private:
		Element *head;
		Element *tail;

	public:
		LinkedList();
		~LinkedList();

		bool empty();
		bool is_first(Element* Element);
		bool is_last(Element* Element);

		void insert_left(int v);
		void insert_right(int v);
		Element* get_first();
		Element* get_last();
		int get_value(Element* Element);
		Element* next_left(Element* Element);
		Element* next_right(Element* Element);
		void print_list();
		void print_Element(Element *n);
		void remove_left();
		void remove_right();


	protected:
		void add(Element *v, int d);
		void remove(Element *v);

	friend class LongInt;
};


class LongInt
{
	private:
		bool sign;
		LinkedList *l;
	public:
		LongInt();
		~LongInt();
		void initialize(std::string s);
		char getsign();
		void setsign(char sign);
		void print();

		bool greaterthan(LongInt *&q);
		bool lessthan(LongInt *&q);
		bool equalto(LongInt *&q);

		int digit(int t);
		int getdigitcount();
		int over_flow(int t);

};
