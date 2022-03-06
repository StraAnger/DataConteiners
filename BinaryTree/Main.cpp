#include <iostream>

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft=nullptr, Element* pRight=nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;

		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}

		bool isLeaf() const
		{
			return pLeft == pRight; // оба nullptr
		}


		friend class Tree;
		friend class UniqueTree;

	}* Root; // это то же что и Element* Root;


public:

	Element* getRoot()const
	{
		return Root;
	}


	Tree()
	{
		this->Root = nullptr;
		std::cout << "TConstructor:\t" << this << std::endl;
	}

	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			insert(*it, Root);
		}
	
	}

	Tree(const Tree& other): Tree()
	{
		copy(other.Root);
		std::cout << "CopyCOnstructor:\t" << this << std::endl;
	}

	~Tree()
	{
		clear();
		std::cout << "TDenstructor:\t" << this << std::endl;
	}

	void insert(int Data)
	{
		insert(Data, Root);
	}

	void erase(int Data)
	{
		erase(Data,Root);
	}



	void clear()
	{
		clear(Root);
		Root = nullptr;
	}




	int MinValue()const
	{
return MinValue(Root);
	}

	int MaxValue()const
	{
		return MaxValue(Root);
	}

	int Size()const
	{
		return Size(Root);
	}

	int sum()const
	{
		return sum(Root);
	}

	int avg()const
	{
		return (double)sum(Root)/Size(Root);
	}


	void print() const
	{
		print(Root);
		std::cout << std::endl;
	}

	
private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr) Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr) return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->isLeaf())
			{
				delete Root;
				Root = nullptr;
			}
		}
		else
		{
			if(Size(Root->pLeft)>Size(Root->pRight))
			{
				Root->Data = MaxValue(Root -> pLeft);
				erase(MaxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				Root->Data = MinValue(Root->pRight);
				erase(MinValue(Root->pRight), Root->pRight);
			}
		}
	}



	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete(Root);
	}

	void copy(Element* Root)
	{
		if (Root == nullptr) return;
		insert(Root->Data,this->Root);
		copy(Root->pLeft);
		copy(Root->pRight);

	}

	
	int MinValue(Element* Root) const
	{
		if (Root == nullptr) return 0;
		/*if (Root->pLeft == nullptr) return Root->Data;
		else return MinValue(Root->pLeft);*/

		//return Root->pLeft == nullptr ? Root->Data : MinValue(Root->pLeft);

		return Root->pLeft ? MinValue(Root->pLeft) : Root->Data;
	}


	int MaxValue(Element* Root) const
	{
		if (Root == nullptr) return 0;
		//if (Root->pRight == nullptr) return Root->Data;
		//else return MaxValue(Root->pRight);

		//return Root->pRight == nullptr ? Root->Data : MaxValue(Root->pRight);

		return Root->pRight ? MaxValue(Root->pRight) : Root->Data;
	}

	int Size(Element* Root)const
	{
		return Root == nullptr ? 0 : Size(Root->pLeft) + Size(Root->pRight) + 1;
	}

	int sum(Element* Root)const
	{
		return !Root ? 0 : sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}

	void print(Element* Root)const
	{
		if (Root == nullptr) return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
	}


};

class UniqueTree : public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr) Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data>Root->Data)
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

public:
	void insert(int Data)
	{
		insert(Data,this->Root);
	}
};

//#define BASE_CHECK

int main()
{
#ifdef BASE_CHECK

	std::cout << typeid(nullptr).name() << std::endl;
	int n;

	std::cout << "Enter tree size: "; std::cin >> n;

	UniqueTree tree;

	for (int i = 0; i < n; ++i)
	{
		tree.insert(rand() % 100);
	}
	//tree.clear();
	tree.print();
	std::cout << std::endl;
	std::cout << "Min value: " << tree.MinValue() << std::endl;
	std::cout << "Max value: " << tree.MaxValue() << std::endl;
	std::cout << std::endl;
	std::cout << "Size: " << tree.Size() << std::endl;
	std::cout << "Sum of tree elements: " << tree.sum() << std::endl;
	std::cout << "Avarage of tree elements: " << tree.avg() << std::endl;

	return 0;
#endif // BASE_CHECK

	Tree tree = { 50,25,27,35,75,16,32,65,80 };
	tree.print();
	/*Tree tree2 = tree;
	tree2.print();*/
	int value;
	std::cout << "Enter the element to delete: "; std::cin >> value;
	tree.erase(value);
	tree.print();


}