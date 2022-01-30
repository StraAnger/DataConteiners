#include <iostream>

// ForwardList

#define tab "\t"

class Element
{
	int Data; // �������� ��������
	Element* pNext; //����� ���������� ��������

public:


	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};


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
	}


};



int main()
{
	int n;

	std::cout << "Enter the list size: "; std::cin >> n;
	ForwardList List;

	for (int i = 0; i < n; ++i)
	{
		List.push_front(rand() % 100);
	}
	List.print();

	return 0;
}