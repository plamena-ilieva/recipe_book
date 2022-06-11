#include "ColdMeal.h"
#include <iostream>
//const double EPS = 1e-10; // Needed to accurately compare numbers of type float and double
ColdMeal::ColdMeal(const MyString& name, const size_t& preparationTime, const MyString& instructions, const double& storingTemperature)
	: Recipe(name, preparationTime, instructions)
{
	setStoringTemperature(storingTemperature);
}

void ColdMeal::print() const
{
	Recipe::print();
	std::cout << "Storing temperature: " << storingTemperature << " degrees Celsius" << std::endl;
}

Recipe* ColdMeal::clone() const
{
	return new ColdMeal(*this);
}

void ColdMeal::setStoringTemperature(const double& storingTemperature)
{
	if (storingTemperature > -18 && storingTemperature < 4)
	{
		this->storingTemperature = storingTemperature;
		return;
	}
	this->storingTemperature = 3.99; // setting default refrigerator temperature value
}

const double ColdMeal::getStoringTemperature() const
{
	return storingTemperature;
}
