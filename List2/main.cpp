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

	void insert(int index, int Data)
	{
		if (index == 0 || Head == nullptr ) return push_front(Data);
		if (index > size)return;
		if (index <= size / 2)
		{
			Element* Temp = Head;
			for (int i = 0; i < index - 1; i++) Temp = Temp->pNext;
			Temp->pNext = new Element(Data, Temp->pNext);
		}
		if (index > size / 2)
		{
			Element* Temp = Tail;
			for (int i = 0; i < index - 1; i++) Temp = Temp->pPrev;
			Temp->pPrev = new Element(Data, Temp->pPrev);
		}

		
		size++;
	}


	//					Removing elements:
	void pop_front()
	{
		if (Head == nullptr)return;
		//1) Запоминаем адрес удаляемого элемента:
		Element* ErasedHead = Head;
		//2) Исключаем удаляемый элемент из списка:
		Head = ErasedHead->pNext;
		Head->pPrev = nullptr;
		//3) Удаляем элемен из памяти:
		delete ErasedHead;

		size--;
	}

	void pop_back()
	{
		if (Tail == nullptr)return;
		//1) Запоминаем адрес удаляемого элемента:
		Element* ErasedTail = Tail;
		//2) Исключаем удаляемый элемент из списка:
		Tail = ErasedTail->pPrev;
		Tail->pNext = nullptr;
		//3) Удаляем элемен из памяти:
		delete ErasedTail;

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


	list.pop_front();
	list.pop_back();

	list.insert(2, 123);

	list.print();
	list.reverse_print();

	return 0;
}