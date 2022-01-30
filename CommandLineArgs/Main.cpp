#include <iostream>


// argc- (arguments count) количество аргументов командной строки - размер массива
// argv- (argument values) значения аргументо командной строки, массив из строк
// Нулевой элемент массива argv[] это всегда полное имя исполняемого файла программы ( включая путь к исполняемому файлу)

int main(int argc, char* argv[])
{

	// cerr<<

	for (int i = 0; i < argc; ++i)
	{
		std::cout <<"argv["<<i<<"]\t"<< argv[i]<< std::endl;
	}

		return 0;
}