#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};

class LinkList
{
private:
	Node* head;
	Node* tail;
public:
	LinkList()
	{
		head = NULL;
		tail = NULL;
	}
	void add_node(int n)
	{
		Node* tmp = new Node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	void add_after(Node* b, int n)
	{
		Node* tmp = new Node;
		tmp->data = n;
		tmp->next = NULL;

		if (b == tail)
		{
			tail->next = tmp;
			tail = tmp;
		}
		else
		{
			tmp->next = b->next;
			b->next = tmp;
		}
	}
	void add_before(Node* b, int n)
	{
		Node* tmp = new Node;
		tmp->data = n;
		tmp->next = NULL;

		if (b == head)
		{
			tmp->next = head;
			head = tmp;
		}
		else
		{
			Node* t = head;
			while (t->next != b)
			{
				t = t->next;
			}
			t->next = tmp;
			tmp->next = b;
		}
	}
	void display()
	{
		int count = 0;
		Node* tmp = head;
		while (tmp != NULL)
		{
			cout << tmp->data << "  ";
			count++;
			tmp = tmp->next;
		}
		cout  << endl<<"Number of Node is " << count << endl<<endl;
	}
	int delete_node(Node* ptr)
	{
		Node* tmp = head;
		Node* del = ptr;
		int d = ptr->data;
		if (head == NULL)
		{
			cout << "Nothing to delete" << endl;
			return -1;
		}
		else if (ptr == head)
		{
			head = ptr->next;
		}
		else if (ptr == tail)
		{
			while (tmp->next->next != NULL)
			{
				tmp = tmp->next;
			}
			tail = tmp;
			tmp->next = NULL;
		}
		else
		{
			while (tmp->next != ptr)
			{
				tmp = tmp->next;
			}
			tmp->next = ptr->next;
		}
		delete del;
		return d;
	}
	Node* get_head()
	{
		return head;
	}
	Node* get_tail()
	{
		return tail;
	}
	void delete_head()
	{
		Node* tmp = head;
		head = tmp->next;
		delete tmp;
		tmp = NULL;
	}
	void delete_tail()
	{
		Node* tmp = head;
		while (tmp->next->next != NULL)
		{
			tmp = tmp->next;
		}
		tail = tmp;
		tail->next = NULL;
		delete tmp->next;
		tmp->next = NULL;
	}
	void search(int key)
	{
		int count = 1;
		bool c = true;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				cout << key << " Found at Node Number " << count << endl;
				c = false;
				break;
			}
			temp = temp->next;
			count++;
		}
		if (c == true)
			cout << key << " Not Found in the link List" << endl;
	}
};
int main()
{
	LinkList L;
	L.add_node(10);
	L.add_node(20);
	L.add_node(30);
	L.add_node(40);
	L.add_node(50);
	L.add_node(60);
	L.add_node(70);
	cout << "Link List L is" << endl;
	L.display();
	cout << "Searching 60..." << endl;
	L.search(60);
	cout << "\nAfter deleting 3rd Node" << endl;
	Node* p = L.get_head();
	p = p->next->next;
	L.delete_node(p);
	cout << "Link List L is" << endl;
	L.display();
	cout << "\nDeleting the tail" << endl;
	L.delete_tail();
	cout << "Link List L is" << endl;
	L.display();
}