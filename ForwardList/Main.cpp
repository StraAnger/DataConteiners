#include <iostream>

// ForwardList

#define tab "\t"

class Element
{
	int Data; // значение элемента
	Element* pNext; //адрес следующего элемента

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


class ForwardList  // Односвязный ( однонаправленный) список
{
	Element* Head;  // Голова списка- указывает на начальный элемент списка
public:

	ForwardList()
	{
		Head = nullptr; // Если голова указывает на 0, то список пуст.
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	// Adding elements

	void push_front(int Data)
	{
		Element* New = new Element(Data); // Создаём новый элемент и помещаем в него значение Data
		New->pNext = Head; // ПРивязываем новый элемент к началу списка
		Head = New; // Переводим Голову на новый элемент

	}

	// Methods

	void print() const
	{
		Element* Temp = Head; // Temp - это итератор.

		// Итератор- указатель, при помощи которого можно получить доступ к элементам структуры данных



		while (Temp) // Пока Итератор содержит ненулевой адрес.
		{
			std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
			Temp = Temp->pNext; // Переход на следующий элемент
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