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
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~List()
	{
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

int main()
{
	int n;
	std::cout << "Enter number of elements: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; ++i)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	return 0;
}