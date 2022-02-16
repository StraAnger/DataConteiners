#include <iostream>
#define tab "\t"
class List
{
	class Element
	{
		int Data; // значение элемента
		Element* pNext; // Адрес следующего элемента
		Element* pPrev; // Адрес предыдущего элемента
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :
			Data(Data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List;
	} *Head, * Tail; // можно так
	size_t size;


	/*
	Element* Head;
	Elemetn* Tail;
	unsigned int size; */
public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) : Temp(Temp)
		{
			std::cout << "ITConstructor:\t" << this << std::endl;
		}

		Iterator& operator ++ ()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator& operator ++ (int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		Iterator& operator -- ()
		{
			Temp = Temp->pPrev;
			return *this;
		}

		Iterator& operator -- (int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}

		bool operator == (const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}

		bool operator != (const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}

		int& operator*()
		{
			return Temp->Data;
		}

		const int& operator*() const
		{
			return Temp->Data;
		}

	};


	Iterator begin()
	{
		return Head;
	}

	Iterator end()
	{
		return nullptr;
	}

	List()
	{
		Head = Tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}

	List(const std::initializer_list<int>& il) :List()
	{

		std::cout << typeid(il.begin()).name() << std::endl;
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}

	}

	~List()
	{
	//	while (Head) pop_front();
		while (Tail) pop_back();

		std::cout << "LDestructor:\t" << this << std::endl;
	}

	// Adding elements

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head=Tail= new Element(Data);
			++size;
			return;
		}

		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;

	//	Head = Head->pPrev = new Element(Data, Head);
				
	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			++size;
			return;
		}

		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;
	}

	void insert(int index, int Data)
	{
		if (index > size)return;
		if (index == 0) return push_front(Data);
		if (index == size) return push_back(Data);
		

		Element* Temp;
		if (index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < index; ++i) Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - 1 - index; ++i) Temp = Temp->pPrev;
		}
		
// не важно с какой стороны мы добрались до нужного элемента, процедура 
		//  добавления нового элемента будет идентичной
		Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;

		size++;

	}


	//					Removing elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr) return;
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		
		
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;

		size--;
	}

	void pop_back()
	{
		if (Tail == Head)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext; 
		Tail->pNext = nullptr;
		
		size--;
	}

	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)return pop_front();
		
		if (index <= size / 2)
		{
			Element* Temp = Head;
			for (int i = 0; i < index - 1; i++) Temp = Temp->pNext;
			Element* Erased = Temp->pNext;
			Temp->pNext = Erased->pNext;
			delete Erased;
		}
		if (index > size / 2)
		{
			Element* Temp = Tail;
			for (int i = 0; i < index - 1; i++) Temp = Temp->pPrev;
			Element* Erased = Temp->pPrev;
			Temp->pPrev = Erased->pPrev;
			delete Erased;
		}

		size--;
	}

	// Methods

	void print()const
	{

		Element* Temp = Head;	
		while (Temp)
		{
			std::cout << Temp << tab <<Temp->pPrev<<tab<< Temp->Data << tab << Temp->pNext << std::endl;
			Temp = Temp->pNext;
		}
		std::cout << "Number of elements: " << size << std::endl;
	}


	void reverse_print()const
	{

		Element* Temp = Tail;
		while (Temp)
		{
			std::cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << std::endl;
			Temp = Temp->pPrev;
		}
		std::cout << "Number of elements: " << size << std::endl;
	}

};

//define BASE_CHECK;

int main()
{
#ifdef BASE_CHECK
	int n;
	std::cout << "Enter number of elements: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; ++i)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	int index;
	int value;
	std::cout << "Enter index"; std::cin >> index;
	std::cout << "Enter value"; std::cin >> value;

	list.insert(index, value);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

	List list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		std::cout << i << tab;
	}


	return 0;
}