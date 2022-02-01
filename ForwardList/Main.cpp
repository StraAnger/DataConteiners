#include <iostream>

// ForwardList

#define tab "\t"

class Element
{
	int Data; // значение элемента
	Element* pNext; //адрес следующего элемента
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

class ForwardList  // Односвязный ( однонаправленный) список
{
	Element* Head;  // Голова списка- указывает на начальный элемент списка
public:

	ForwardList()
	{
		Head = nullptr; // Если голова указывает на 0, то список пуст.
		std::cout << "LConstructor:\t" << this << std::endl;
	}

	ForwardList(const ForwardList& other) {

		this->Head = other.Head;
		std::cout << "CopyLConstructor" << this << std::endl;

	}

	ForwardList(ForwardList&& other)noexcept
	{
		this->Head = other.Head;
		other.Head = nullptr;
		std::cout << "MoveLConstructor\t" << this << std::endl;
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


	void push_back(int Data)
	{
		// 0) Проверяем является ли список пустым

		if (Head == nullptr) return push_front(Data);

		// 1) Создаём новый элемент

		Element* New = new Element(Data);

		// 2) Доходим до конца списка

		Element* Temp = Head;
		while (Temp->pNext) // Пока, pNext текущего элемента НЕ ноль,
			Temp = Temp->pNext; // переходим на след элемент

		// Теперь мы находимся в последнем элементе. Т.е Temp->pNext == nullptr

		// 3) Присоединяем новый элемент к последнему:


		Temp->pNext = New;


	}

	void insert(int index, int Data)
	{
		if (index == 0 || Head == nullptr)return push_front(Data);
		if (index > Head->count) return;

		Element* New = new Element(Data);
		//1) Доходим до нужного элемента;
		Element* Temp = Head;
		for (int i = 0; i < index - 1; ++i) Temp = Temp->pNext;
		//2) Включаем новый элемент в список
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
		// 1) Запоминаем адрес удаляемого элемента:
		Element* Erased = Head;
		// 2) Исключаем удаляемый элемент из списка:
		Head = Erased->pNext;
		// 3) Удаляем элемент из памяти:
		delete Erased;



	}

	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		// 1) Доходим до предпоследнего элемента:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		// 2) Удаляем элемент из памяти:
		delete Temp->pNext;
		// 3) Затираем адресудалённого элемента нулём:
		Temp->pNext = nullptr;
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

		std::cout << "Number of elements in list: " << Head->count << std::endl;
	}

	//Operators

	ForwardList& operator = (const ForwardList& other)
	{
		if (this == &other)
			return *this;

		this->Head = other.Head;
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	ForwardList& operator =(ForwardList&& other)
	{

		if (this == &other)
			return *this;

		delete this->Head;
		this->Head = other.Head;

		other.Head = nullptr;
		std::cout << "MoveAssignment:\t" << this << std::endl;
		return  *this;
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
	std::cout << "Enter index of element to insert: "; std::cin >> index;
	std::cout << "Enter value of element to insert: "; std::cin >> value;

	List.insert(index, value);
	List.print();

	index = 0;

	std::cout << "Enter index of element to erese: "; std::cin >> index;
	
	List.erase(index);
	List.print();

	ForwardList List1;
	List1 = List;

	std::cout << "CopyAsignment: " << std::endl;

	List1.print();


	ForwardList List2=List;

	std::cout << "CopyConstructor: " << std::endl;

	List2.print();


	return 0;
}