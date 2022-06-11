#include "HotMeal.h"
#include <iostream>
const double SIZE_T_LIMIT = 1e3;
HotMeal::HotMeal(const MyString& name, const size_t& preparationTime, const MyString& instructions, const size_t& cookingTemperature, const size_t& cookingTime)
	: Recipe(name, preparationTime, instructions)
{
	setCookingTemperature(cookingTemperature);
	setCookingTime(cookingTime);
	inputAppliances();
	//setAppliances(appliances);
}

void HotMeal::print() const
{
	Recipe::print();
	std::cout << "Cooking time: " << cookingTime << " minutes" << std::endl;
	std::cout << "Cooking temperature " << cookingTemperature << " degrees Celsius" << std::endl;
	std::cout << "Necessary appliances: " << std::endl;
	for (size_t i = 0; i < appliances.getSize(); ++i)
		std::cout << appliances[i] << std::endl;
}

Recipe* HotMeal::clone() const
{
	return new HotMeal(*this);
}

void HotMeal::setCookingTemperature(const size_t& cookingTemperature)
{
	if (cookingTemperature >= 90 && cookingTemperature <= 260)
	{
		this->cookingTemperature = cookingTemperature;
		return;
	}
	this->cookingTemperature = 100;
	std::cout << "Invalid cooking temperature (must range from 90 to 260 Celsius). Cooking temperature set to 100 by default.";
}

void HotMeal::setCookingTime(const size_t& cookingTime)
{
	if (cookingTime < SIZE_T_LIMIT)
	{
		if (cookingTime > getPreparationTime())
		{
			this->cookingTime = size_t(getPreparationTime() / 2);
			std::cout << "Cooking time cannot exceed preparation time. Cooking time set to 50% of preparation time by default" << std::endl;
			return;
		}
		this->cookingTime = cookingTime;
		return;
	}			
	this->cookingTime = size_t(getPreparationTime() / 2);
	std::cout << "Cooking time cannot exceed preparation time. Cooking time set to 50 % of preparation time by default" << std::endl;
}

void HotMeal::setAppliances(const Vector<MyString> appliances)
{
	if (appliances.getSize() > 0 && appliances.getSize() < SIZE_T_LIMIT)
	{
		this->appliances = appliances;
		return;
	}
	this->appliances.push_back("No appliances");
}

const size_t HotMeal::getCookingTemperature() const
{
	return cookingTemperature;
}

const size_t HotMeal::getCookingTime() const
{
	return cookingTime;
}

const Vector<MyString> HotMeal::getAppliances() const
{
	return appliances;
}

void HotMeal::inputAppliances()
{
	size_t num = 0;
	std::cout << "Please, type the number of appliances: ";
	while (true)
	{
		std::cin >> num;
		if (num > 0 && num < 10) // 10 is the limit
			break;
		else
			std::cout << "Invalid number of appliances. Please try again..." << std::endl;
	}
		
	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Appliance: ";
		MyString temp;
		std::cin.ignore();
		std::cin >> temp;
		appliances.push_back(temp);
	}
}
