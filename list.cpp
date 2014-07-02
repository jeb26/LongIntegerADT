#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.h"
using namespace std;

LinkedList :: LinkedList()
{
	head  = new Element;
	tail = new Element;

	head->next = tail;
	tail->prev = head;

}

LinkedList :: ~LinkedList()
{
	while(!empty())
	{
		remove_left();
	}
	delete head;
	delete tail;
}

void LinkedList :: add(Element *v, int d)
{
	Element *u = new Element;
	u->data = d;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = v->prev = u;
}

void LinkedList :: insert_left(int v)
{
	if (head == NULL)
	{
		Element *n = new Element;
		n->data = v;
		n->next = NULL;
		head = n;
	}
	else
	{
		add(head->next, v);
	}
}

void LinkedList :: insert_right(int v)
{
	 add(tail,v);
}

void LinkedList :: remove(Element *v)
{
	Element *u = v->prev;
	Element *w = v->next;

	u->next = w;
	w->prev = u;

	delete v;
}

void LinkedList :: remove_left()
{
	remove(head->next);
}

void LinkedList :: remove_right()
{
	remove(tail->prev);
}

bool LinkedList :: empty()
{
	return (head->next == tail);
}

void LinkedList :: print_list()
{
	Element *tmp = head;
	while(tmp != NULL)
	{
		if(tmp->data == 0)
		{
			tmp = tmp->next;
		}
		else
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
}

void LinkedList :: print_Element(Element *n)
{
	Element *tmp = n;
	cout << tmp->data << endl;
}

Element* LinkedList :: get_first()
{
	return head;
}

Element* LinkedList :: get_last()
{
	return tail;
}

Element* LinkedList :: next_left(Element* Element)
{
	return Element->prev;
}

Element* LinkedList :: next_right(Element* Element)
{
	return Element->next;
}

bool LinkedList :: is_first(Element* Element)
{
	if(Element == head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool LinkedList :: is_last(Element* Element)
{
	if(Element == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList :: get_value(Element* Element)
{
	return Element->data;
}

LongInt :: LongInt()
{
	sign = true;

	l = new LinkedList;
}

void LongInt :: initialize(std::string s)
{
	char sign = s.at(0);
	if(sign == '-')
	{
		s.erase(s.begin());
		this->sign = false;
	}

	while(true)
	{
		if(s.length() <= 4)
		{
			l->insert_left(atoi(s.c_str()));
			break;
		}
		else
		{
			int place = (s.length() - 4);
			l->insert_left(atoi(s.substr(place, 4).c_str()));
			s.erase(place, 4);
		}
	}
}

char LongInt :: getsign()
{
	if(this->sign == true)
	{
		return '+';
	}
	else if(this->sign == false)
	{
		return '-';
	}
}

void LongInt :: setsign(char sign)
{
	if(sign == '+')
	{
		this->sign = true;
	}
	else if(sign == '-')
	{
		this->sign = false;
	}
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

int LongInt :: over_flow(int t)
{
	int digits = this->digit(t);

	if(digits <= 4)
	{
		return 0;
	}
	else
	{
		int permitted = t % 10000;
		int overflow = t / 10000;
		return overflow;
	}
}

int LongInt :: getdigitcount()
{
	Element* temp = l->get_first();
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
	Element* temp = l->get_first();

	if(this->getsign() == '-')
	{
		printf("-");
	}
	temp = l->next_right(temp);
	while(!l->is_last(temp))
	{
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
		Element* local = l->get_first();
		Element* foreign = q->l->get_first();

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

	if( this->getsign() == '+' && q->getsign() == '-')
	{
		return lessthan = false;
	}

	if( this->getsign() == '-' && q->getsign() == '+')
	{
		return lessthan = true;
	}

	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') )
	{
		return lessthan = false;
	}

	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') )
	{
		return lessthan = true;
	}

	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') )
	{
		return lessthan = true;
	}

	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') )
	{
		return lessthan = false;
	}

	if(this->getdigitcount() == q->getdigitcount())
	{
		Element* local = l->get_first();
		Element* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value > foreign_value)
			{
				return lessthan = false;
			}
			if(local_value < foreign_value)
			{
				return lessthan = true;
			}

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

	if( this->getsign() == '+' && q->getsign() == '-')
	{
		return greaterthan = true;
	}

	if( this->getsign() == '-' && q->getsign() == '+')
	{
		return greaterthan = false;
	}

	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') )
	{
		return greaterthan = true;
	}

	if( (this->getdigitcount() > q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') )
	{
		return greaterthan = false;
	}

	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '+' && q->getsign() == '+') )
	{
		return greaterthan = false;
	}

	if( (this->getdigitcount() < q->getdigitcount()) && (this->getsign() == '-' && q->getsign() == '-') )
	{
		return greaterthan = true;
	}

	if(this->getdigitcount() == q->getdigitcount())
	{
		//char sign = this->getsign();

		Element* local = l->get_first();
		Element* foreign = q->l->get_first();

		while(!l->is_last(local))
		{
			int local_value = l->get_value(local);
			int foreign_value = q->l->get_value(foreign);

			if(local_value > foreign_value)
			{
				return greaterthan = true;
			}
			if(local_value < foreign_value)
			{
				return greaterthan = false;
			}

			//advance local and foreign pointers
			local = l->next_right(local);
			foreign = q->l->next_right(foreign);
		}
		return greaterthan = true;
	}
}