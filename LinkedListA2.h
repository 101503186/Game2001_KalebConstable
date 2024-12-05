#pragma once
#include <cassert>

template <class T> class LinkIterator;
template <class T> class LinkedList;

template <class T>
class LinkNode
{
public:
	// Give access to the private member variables
	friend class LinkIterator<T>;
	friend class LinkedList<T>;
private:
	T m_data;
	LinkNode* m_next;	// pointer referencing itself
};

// Define an iterator
template <class T>
class LinkIterator
{
public:
	LinkIterator()
	{
		m_node = nullptr;
	}
	~LinkIterator() {}
	//sets the iterator to point to a node
	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}
	//reads the data stored on the node being pointed too
	T& operator*()
	{
		assert(m_node != nullptr);
		return m_node->m_data;
	}
	//moves the iterator to the next node
	void operator++()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	void operator++(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}
	//checks whether the node we are pointing too is equal to a node that we are passing in
	bool operator!=(LinkNode<T>* node)
	{
		return (m_node != node);
	}
	bool operator==(LinkNode<T>* node)
	{
		return (m_node == node);
	}

private:
	LinkNode<T>* m_node;	// pointer to a node in the linked list
};

template <class T>
class LinkedList
{
public:
	
	LinkedList() : m_size(0), m_root(nullptr), m_lastNode(nullptr) {}
	~LinkedList()
	{
		while (m_root)
		{
			
		}
	}
	LinkNode<T>* Begin()
	{
		assert(m_root != nullptr);
		return m_root;
	}
	LinkNode<T>* End()
	{
		return nullptr;
	}
	LinkNode<T>* Last()
	{
		assert(m_lastNode != nullptr);
		return m_lastNode;
	}
	void Push(T newData)
	{
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		node->m_data = newData;
		node->m_next = nullptr;

		// adds the new LinkNode to the existing LinkedList
		if (m_lastNode != nullptr)
		{
			m_lastNode->m_next = node;
			m_lastNode = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}

		m_size++;
	}
	void Pop()
	{
		assert(m_root != nullptr);

		// checks if there is only 1 node (aka just a root)
		if (m_root->m_next == nullptr)
		{
			delete m_root;
			m_root = nullptr;
			m_lastNode = nullptr;
		}
		else
		{
			LinkNode<T>* prevNode = m_root;

			// traverses the linked list until we reach the end
			while (prevNode->m_next != nullptr && prevNode->m_next != m_lastNode)
			{
				prevNode = prevNode->m_next;
			}

			//previous loop positions the poinster to the 2nd last node
			delete m_lastNode;
			prevNode->m_next = nullptr;
			m_lastNode = prevNode;

			prevNode = nullptr;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}
	int GetSize()
	{
		return m_size;
	}

	T Front() const {
		assert(m_root != nullptr);
		return m_root->m_data;
	}

private:
	int m_size;					// holds the size of the linked list
	LinkNode<T>* m_root;		// point to the root of the linked list
	LinkNode<T>* m_lastNode;	// point to the last node of the linked list
};
