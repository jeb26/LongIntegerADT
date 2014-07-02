class Node
{
	private:
		int data;
		Node *next;
		Node *prev;
		friend class LinkedList;

	//public:
		//void print_list();
		//void print_data();
};

class LinkedList
{
	private:
		Node *head;
		Node *tail;

	public:
		LinkedList :: LinkedList()
		{
			head  = new Node;
			tail = new Node;

			head->next = tail;
			tail->prev = head;
		}
		LinkedList :: ~LinkedList()
		{
			while(!empty())
			{
				removeFront();
			}
			delete head;
			delete tail;
		}

		bool LinkedList :: empty()
		{
			return (head->next == tail);
		}
		void insert_left(int v);
		void LinkedList :: addFront(int v)
		{
			add(head->next, v);
		}
		void addBack(int v);
		void insert_right(int v);

	protected:
		void LinkedList :: add(Node *v, int d)
		{
			Node u = new Node;
			u->data = d;
			u->next = v;
			u->prev = v->prev;
			v->prev->next = v->prev = u;
		}
		void remove(Node *v);
};