#include <iostream>


void elevator(int floor)
{
	if (floor == 0)
	{
		std::cout << "You're in basement" << std::endl; // exit case
		return;
	}
	std::cout << "Yo're on " << floor << " floor" << std::endl;
	elevator(floor-1);
	std::cout << "Yo're on " << floor << " floor" << std::endl;

}



int main()
{
	int floor;

	std::cout << "Enter the floor number: "; std::cin >> floor;
	elevator(floor);
	return 0;
}