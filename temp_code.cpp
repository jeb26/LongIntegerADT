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
		int num = atoi(s.c_str());
		l->insert_left(num);
	}
	else
	{
		int pos = s.length() - 4;
		int num = atoi((s.substr(pos, 4)).c_str());
		l->insert_left(num);
		s.erase(pos, 4);
		initialize(s);
	}
}

LongInt* LongInt :: subtract(LongInt *&q)
{
	int borrow = 0;
	int temp = 0;

	Node *n1, *n2;

	n1 = this->l->get_last();
	n2 = q->l->get_last();

	n1 = this->l->next_left(n1);
	n2 = q->l->next_left(n2);

	LongInt *result = new LongInt();

	if(this->l->get_value(n1) < q->l->get_value(n2) || this->l->get_value(n1) == q->l->get_value(n2) && borrow != 0)
	{
		temp = this->l->get_value(n1) - 10000 - q->l->get_value(n2);
	}
	else
	{
		temp = this->l->get_value(n1) - q->l->get_value(n2);
	}

	result->l->insert_left(temp);

	while(!q->l->is_first(n2))
	{
		n1 = this->l->next_left(n1);
		n2 = q->l->next_left(n2);

		if(this->l->get_value(n1) < q->l->get_value(n2) || this->l->get_value(n1) == q->l->get_value(n2) && borrow != 0)
		{
			temp = this->l->get_value(n1) - 10000 - q->l->get_value(n2);
			borrow = 1;
		}
		else
		{
			temp = this->l->get_value(n1) - q->l->get_value(n2);
			borrow = 0;
		}
	}

	while(!this->l->is_first(n1))
	{
		n1 = this->l->next_left(n1);
		temp = this->l->get_value(n1) - borrow;
		borrow = 0;

		result->l->insert_left(temp);
	}

	return result;
}