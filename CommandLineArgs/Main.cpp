#include <iostream>


// argc- (arguments count) ���������� ���������� ��������� ������ - ������ �������
// argv- (argument values) �������� ��������� ��������� ������, ������ �� �����
// ������� ������� ������� argv[] ��� ������ ������ ��� ������������ ����� ��������� ( ������� ���� � ������������ �����)

int main(int argc, char* argv[])
{

	// cerr<<

	for (int i = 0; i < argc; ++i)
	{
		std::cout <<"argv["<<i<<"]\t"<< argv[i]<< std::endl;
	}

		return 0;
}