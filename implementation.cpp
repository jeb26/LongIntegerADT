#include "classes.h"
using namespace std;

ListADT :: ListADT()
{
	head  = new Node;
	tail = new Node;

	head->forward = tail;
	tail->back = head;

}

void ListADT :: push_Node(Node *v, int d)
{
	Node *u = new Node;
	u->val = d;
	u->forward = v;
	u->back = v->back;
	v->back->forward = u;
	v->back = u;
}

void ListADT :: insert_left(int v)
{
	// if (head == NULL)
	// {
	// 	Node *n = new Node;
	// 	n->val = v;
	// 	n->forward = NULL;
	// 	head = n;
	// }
	// else
	// {
	// 	push_Node(head->forward, v);
	// }
	if (!head)
	{
		head = new Node(v);
		tail = head;
	}
	else
	{
		head->back = new Node(v, head, NULL);
		head = head->back;
	}	
}

void ListADT :: insert_right(int v) { //push_Node(tail,v); 
	if (!head)
	{
		head = new Node(v);
		tail = head;
	}
	else
	{
		tail->forward = new Node(v, NULL, tail);
		tail = tail->forward;
	}	
}

bool ListADT :: empty() { return (head->forward == tail); }

void ListADT :: print_Node(Node *n)
{
	Node *tmp = n;
	cout << tmp->val << endl;
}

Node* ListADT :: get_first() { return head; }

Node* ListADT :: get_last() { return tail; }

Node* ListADT :: next_left(Node* Node) { return Node->back; }

Node* ListADT :: next_right(Node* Node) { return Node->forward; }

bool ListADT :: is_first(Node* Node)
{
	if(Node == this->head) { return true; }
	else { return false; }
}

bool ListADT :: is_last(Node* Node)
{
	if(Node == tail) { return true; }
	else { return false; }
}

int ListADT :: get_value(Node* Node) { return Node->val; }

LongInt :: LongInt()
{
	sign = true;

	l = new ListADT;
}

void LongInt :: initialize(std::string s)
{
	char sign = s.at(0);
	if(sign == '-')
	{
		s.erase(s.begin());
		this->sign = false;
	}

	if (s.length() <= 4)
	{
		// std::cout << "inserting into first node, str: " << str; 
		int num = atoi(s.c_str());
		// std::cout << " and converted to num: " << num << std::endl; 
		l->insert_left(num);
	}
	else
	{
		
		int pos = s.length() - 4;
		// std::cout << "inserting into NON-first node, str: " << str.substr(pos, MAX_DIGITS);
		int num = atoi((s.substr(pos, 4)).c_str());
		// std::cout << " and converted to num: " << num << std::endl;
		l->insert_left(num);
		s.erase(pos, 4);
		initialize(s);
	}
}

char LongInt :: getsign()
{
	if(this->sign == true) { return '+'; }
	else if(this->sign == false) { return '-'; }
}

void LongInt :: setsign(char sign)
{
	if(sign == '+') { this->sign = true; }
	else if(sign == '-') { this->sign = false; }
}

int LongInt :: digit(int t)
{
	int num = t;
	int digits = 0;

	while(num)
	{
		num /= 10;
		digits++;
	}
	return digits;
}

int LongInt :: over_flow(int *t)
{
	int num = *t;
	int digits = this->digit(num);

	if(digits <= 4)
	{
		return 0;
	}
	else
	{
		int permitted = *t % 10000;
		int overflow = *t / 10000;
		*t = permitted;
		return overflow;
	}
}

int LongInt :: getdigitcount()
{
	Node* temp = l->get_first();
	int digits = 0;

	temp = l->next_right(temp);
	while(!l->is_last(temp))
	{
		digits += this->digit(l->get_value(temp));
		temp = l->next_right(temp);
	}
	return digits;
}

void LongInt :: print()
{
	Node* temp = l->get_first();

	if(this->getsign() == '-')
	{
		printf("-");
	}
	//temp = l->next_right(temp);
	while(!l->is_last(temp))
	{
		//if(l->is_first(temp))
		//{
		//	temp = l->next_right(temp);
		//	continue;
		//}
		printf("%d", l->get_value(temp));
		temp = l->next_right(temp);
	}
	printf("\n");
}

bool LongInt :: equalto(LongInt *&q)
{
	bool equal = true;

	if(q->getsign() != this->getsign())
	{
		equal = false;
	}
	else if(q->getdigitcount() != this->getdigitcount())
	{
		equal = false;
	}
	else
	{
		Node* local = l->get_first();
		Node* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value != foreign_value)
			{
				equal = false;
			}

			//advance local and foreign pointers
			local = l->next_right(local);
			foreign = q->l->next_right(foreign);
		}
	}

	return equal;
}

bool LongInt :: lessthan(LongInt *&q)
{
	bool lessthan;

	if( this->getsign() == '+' && q->getsign() == '-') return lessthan = false;
	if( this->getsign() == '-' && q->getsign() == '+') return lessthan = true;
	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') ) return lessthan = false;
	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') ) return lessthan = true;
	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') ) return lessthan = true;
	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') ) return lessthan = false;

	if(this->getdigitcount() == q->getdigitcount())
	{
		Node* local = l->get_first();
		Node* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value > foreign_value) { return lessthan = false; }
			if(local_value < foreign_value) { return lessthan = true; }

			//advance local and foreign pointers
			local = l->next_right(local);
			foreign = q->l->next_right(foreign);
		}
		return lessthan = false;
	}
}

bool LongInt :: greaterthan(LongInt *&q)
{
	bool greaterthan;

	if( this->getsign() == '+' && q->getsign() == '-') return greaterthan = true;
	if( this->getsign() == '-' && q->getsign() == '+') return greaterthan = false;
	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') ) return greaterthan = true;
	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') ) return greaterthan = false;
	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') ) return greaterthan = false;
	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') ) return greaterthan = true;
	
	if(this->getdigitcount() == q->getdigitcount())
	{
		Node* local = l->get_first();
		Node* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value > foreign_value) { return greaterthan = true; }
			if(local_value < foreign_value) { return greaterthan = false; }

			//advance local and foreign pointers
			local = l->next_right(local);
			foreign = q->l->next_right(foreign);
		}
		return greaterthan = true;
	}
}

bool LongInt :: abs(LongInt *&q)
{
	bool res;

	if(this->getdigitcount() > q->getdigitcount())
	{
		return res = true;
	}
	else if(this->getdigitcount() < q->getdigitcount())
	{
		return res = false;
	}
	else if(this->getdigitcount() == q->getdigitcount())
	{
		Node* local = l->get_first();
		Node* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value > foreign_value) { return res = true; }
			if(local_value < foreign_value) { return res = false; }

			//advance local and foreign pointers
			local = l->next_right(local);
			foreign = q->l->next_right(foreign);
		}
		return res = true;
	}
}

LongInt* LongInt :: add(LongInt *&q)
{
	Node *n1, *n2;

	n1 = this->l->get_last();
	n2 = q->l->get_last();

	LongInt *result = new LongInt();

	int addValue = this->l->get_value(n1) + q->l->get_value(n2);
	int carry = this->over_flow(&addValue);

	result->l->insert_left(addValue);

	while(!this->l->is_first(n1) && !q->l->is_first(n2))
	//while(n1 != this->l->head && n2 != q->l->head)
	{
		n1 = this->l->next_left(n1);
		n2 = q->l->next_left(n2);

		addValue = this->l->get_value(n1) + q->l->get_value(n2) + carry;
		carry = over_flow(&addValue);

		result->l->insert_left(addValue);
	}
	
	//check if val of n1 is 0 otherwise continue more additions this is a bug fix
	bool complete = false;
	while(!complete)
	{
		int value = this->l->get_value(n1);
		if(value == 0)
		{
			complete = true;
		}
		else
		{
			n1 = this->l->next_left(n1);
			//addValue = this->l->get_value(n1) + q->l->get_value(n2) + carry;
			addValue = this->l->get_value(n1) + q->l->get_value(n2);
			//carry = over_flow(&addValue);

			result->l->insert_left(addValue);
		}
	}

	//check if val of n2 is v otherwise continue more additions this is a bug fix
	bool done = false;
	while(!done)
	{
		int value = q->l->get_value(n2);
		//cout << "q l value: " << value << endl;
		if(value == 0)
		{
			done = true;
		}
		else
		{
			n2 = q->l->next_left(n2);
			//addValue = this->l->get_value(n1) + q->l->get_value(n2) + carry;
			addValue = this->l->get_value(n1) + q->l->get_value(n2);
			//carry = over_flow(&addValue);

			result->l->insert_left(addValue);
		}
	}

	/**
	//bool isFirst = q->l->is_first(n2);

	//n1 = this->l->next_left(n1);
	//bool isFirst = this->l->is_first(n2);
	
	n2 = q->l->next_left(n2);
	addValue = this->l->get_value(n1) + q->l->get_value(n2) + carry;
	carry = over_flow(&addValue);
	result->l->insert_left(addValue);

	//bool n1IsFirst = this->l->is_first(n2);
	//n1 = this->l->next_left(n1);
	//bool isFirst = this->l->is_first(n2);
	//n2 = q->l->next_left(n2);
	//addValue = this->l->get_value(n1) + q->l->get_value(n2) + carry;
	//result->l->insert_left(addValue);

	//q->l->print_Node(n2);
	//cout << "n2 is first: " << isFirst << endl;
	//cout << "n1 is: " << this->l->get_value(n1) << " n2 is: " << q->l->get_value(n2) << endl;
	//cout << "carry is: " << carry << endl;
	//cout << "n1 is: " << this->l->get_value(n1) << endl;
	//cout << "n2 is: " << q->l->get_value(n2) << endl;
	//cout << "addValue is: " << addValue << " carry is: " << carry << endl;
	**/

	return result;
}

LongInt* LongInt :: subtract(LongInt *&q)
{
	LongInt *result = new LongInt();
	int temp = 0;

	Node *n1, *n2;
	n1 = this->l->get_last();
	n2 = q->l->get_last();

	ListADT *local = new ListADT;
	ListADT *foreign = new ListADT;
	if(this->abs(q) == 0)
	{
		//foreign has greate absolute value then this so swap them and set the sign
		local = q->l;
		foreign = this->l;
		n1 = local->get_last();
		n2 = foreign->get_last();

		result->setsign('-');
		//cout << "this is less than foreign" << endl;
	}
	else
	{
		local = this->l;
		foreign = q->l;

		n1 = local->get_last();
		n2 = foreign->get_last();
	}

	while(!local->is_first(n1) && !foreign->is_first(n2))
	{
		int borrow = 0;
		int temp = 0;
		int carry = 0;
		int top = 0;
		int bottom = 0;
		
		if(!local->is_first(n1))
		{
			n1 = local->next_left(n1);
			top = local->get_value(n1);
		}
		else
		{
			top = 0;
		}
		
		if(!foreign->is_first(n2))
		{
			n2 = foreign->next_left(n2);
			bottom = foreign->get_value(n2);
		}
		else
		{
			bottom = 0;
		}

		temp = (top - bottom - carry);

		if(temp < 0)
		{
			carry = 1;
			temp += 10000;
		}
		else
		{
			carry = 0;
		}

		result->l->insert_left(temp);
	}

	bool complete = false;
	while(!complete)
	{
		int value = local->get_value(n1);
		if(value == 0)
		{
			complete = true;
		}
		else
		{
			n1 = local->next_left(n1);

			result->l->insert_left(value);
		}
	}

	return result;
}

LongInt* LongInt :: multiply(LongInt *&foreign)
{
	LongInt *result = new LongInt();
	LongInt *temp = new LongInt();

	int tmp_result = 0;
	int carry = 0;
	int place = 0;
	int top = 0;
	int bottom = 0;

	Node *n1, *n2;
	n1 = this->l->get_last();
	n2 = foreign->l->get_last();

	//ListADT *local = new ListADT;
	//ListADT *foreign = new ListADT;
/*	if(this->abs(q) == 0)
	{
		//foreign has greate absolute value then this so swap them and set the sign
		local = q->l;
		foreign = this->l;
		n1 = local->get_last();
		n2 = foreign->get_last();
		n2 = foreign->next_left(n2);
	}
	else
	{
		local = this->l;
		foreign = q->l;

		n1 = local->get_last();
		n2 = foreign->get_last();
		n2 = foreign->next_left(n2);
	}*/

	top = this->l->get_value(n1);
	bottom = foreign->l->get_value(n2);
	tmp_result = top * bottom;
	carry = over_flow(&tmp_result);

	temp->l->insert_left(tmp_result);

	while(!this->l->is_first(n1))
	{
		n1 = this->l->next_left(n1);
		top = this->l->get_value(n1);
		bottom = foreign->l->get_value(n2);

		//cout << "top is: " << top << endl;
		//cout << "bottom is: " << bottom << endl;

		tmp_result = bottom * top + carry;
		carry = over_flow(&tmp_result);

		temp->l->insert_left(tmp_result);
	}
	if(carry != 0) temp->l->insert_left(carry); 

	LongInt *empty = new LongInt();
	result = temp;
	
	while(!foreign->l->is_first(n2))
	{

		n2 = foreign->l->next_left(n2);
		n1 = this->l->get_last();
		bottom = foreign->l->get_value(n2);
		place = place + 1;

		temp = empty;
		while(place != 0)
		{
			empty->l->insert_left(0);
			place = place - 1;
		}

		while(!this->l->is_first(n1))
		{
			top = this->l->get_value(n1);

			tmp_result = bottom * top + carry;
			carry = over_flow(&tmp_result);

			temp->l->insert_left(tmp_result);

			n1 = this->l->next_left(n1);
		}

		result = result->add(temp);
		temp = empty;
	}

	if(carry != 0) result->l->insert_left(carry);

	return result;
}

LongInt* LongInt :: power(LongInt *&foreign)
{
	//code for power
}

LongInt* LongInt :: divide(LongInt *&foreign)
{
	//code for divide
}