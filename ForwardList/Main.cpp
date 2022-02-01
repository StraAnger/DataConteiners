#include <iostream>

// ForwardList

#define tab "\t"

class Element
{
	int Data; // �������� ��������
	Element* pNext; //����� ���������� ��������
	static int count;

public:


	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		++count;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		--count;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList  // ����������� ( ����������������) ������
{
	Element* Head;  // ������ ������- ��������� �� ��������� ������� ������
public:

	ForwardList()
	{
		Head = nullptr; // ���� ������ ��������� �� 0, �� ������ ����.
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	// Adding elements


	void push_front(int Data)
	{
		Element* New = new Element(Data); // ������ ����� ������� � �������� � ���� �������� Data
		New->pNext = Head; // ����������� ����� ������� � ������ ������
		Head = New; // ��������� ������ �� ����� �������

	}


	void push_back(int Data)
	{
		// 0) ��������� �������� �� ������ ������

		if (Head == nullptr) return push_front(Data);

		// 1) ������ ����� �������

		Element* New = new Element(Data);

		// 2) ������� �� ����� ������

		Element* Temp = Head;
		while (Temp->pNext) // ����, pNext �������� �������� �� ����,
			Temp = Temp->pNext; // ��������� �� ���� �������

		// ������ �� ��������� � ��������� ��������. �.� Temp->pNext == nullptr

		// 3) ������������ ����� ������� � ����������:


		Temp->pNext = New;


	}

	void insert(int index, int Data)
	{
		if (index == 0 || Head == nullptr)return push_front(Data);
		if (index > Head->count) return;

		Element* New = new Element(Data);
		//1) ������� �� ������� ��������;
		Element* Temp = Head;
		for (int i = 0; i < index - 1; ++i) Temp = Temp->pNext;
		//2) �������� ����� ������� � ������
		New->pNext = Temp->pNext;
		Temp->pNext = New;

	}

	// Removing elements:

	void erase(int index)
	{
		if (index == 0 || Head == nullptr) return;
		if (index > Head->count) return;

		Element* Temp = Head;
		for (int i = 0; i < index - 1; ++i) Temp = Temp->pNext;
		
		Element* Erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete Erased;

	}

	void pop_front()
	{
		if (Head == nullptr) return;
		// 1) ���������� ����� ���������� ��������:
		Element* Erased = Head;
		// 2) ��������� ��������� ������� �� ������:
		Head = Erased->pNext;
		// 3) ������� ������� �� ������:
		delete Erased;



	}

	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		// 1) ������� �� �������������� ��������:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		// 2) ������� ������� �� ������:
		delete Temp->pNext;
		// 3) �������� �������������� �������� ����:
		Temp->pNext = nullptr;
	}



	// Methods

	void print() const
	{
		Element* Temp = Head; // Temp - ��� ��������.

		// ��������- ���������, ��� ������ �������� ����� �������� ������ � ��������� ��������� ������



		while (Temp) // ���� �������� �������� ��������� �����.
		{
			std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
			Temp = Temp->pNext; // ������� �� ��������� �������
		}

		std::cout << "Number of elements in list: " << Head->count << std::endl;
	}


};



int main()
{
	int n;

	std::cout << "Enter the list size: "; std::cin >> n;
	ForwardList List;
	List.pop_front();
	for (int i = 0; i < n; ++i)
	{
		// List.push_front(rand() % 100);
		List.push_back(rand() % 100);
	}
	List.print();
	//List.push_back(123);
	//List.pop_front();
	//List.pop_back();
	//List.print();

	int index;
	int value;
	std::cout << "Enter index of element: "; std::cin >> index;
	std::cout << "Enter value of element: "; std::cin >> value;


	List.insert(index, value);
	List.print();

	return 0;
}