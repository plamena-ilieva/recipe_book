#include "Recipe.h"

const double SIZE_T_LIMIT = 1e3; 
// limit for size_t validation (when the user input is a negative number,
// it might transform into a large positive number, because its type is size_t (unsigned long long)...)
// we don't need numbers bigger than 1000 in our project anyway, that's why we put such boundary

Recipe::Recipe(const MyString& name, const size_t& preparationTime, const MyString& instructions)
{
	setName(name);
	//setIngredients(ingredients);
	inputIngredients();
	setPreparationTime(preparationTime);
	setInstructions(instructions);
	setRandomID();
	setInitialRatingState();
}

void Recipe::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Number: " << ID << std::endl;
	std::cout << "Rating: " << averageRating << std::endl;
	std::cout << "Ingredients: " << std::endl;
	for (size_t i = 0; i < ingredients.getSize(); ++i)
		std::cout << ingredients[i].getFirst() << ", " << ingredients[i].getSecond() << std::endl;
	std::cout << "Preparation time: " << preparationTime << " minutes" << std::endl;
	std::cout << "Cooking instructions: " << std::endl;
	std::cout << instructions << std::endl;
}

void Recipe::setName(const MyString& name)
{
	if (name.c_str() != nullptr && name.getSize() > 0)
	{
		this->name = name;
		if (this->name[0] < 'A' || this->name[0] > 'Z' && this->name[0] >= 'a' && this->name[0] <= 'z')
			this->name[0] -= 32;
		return;
	}
	this->name = "Unknown";
}

void Recipe::setIngredients(const IngredientList& ingredients)
{
	if (ingredients.getSize() > 0)
	{
		this->ingredients = ingredients;
		return;
	}
	Pair<MyString, size_t> temp("Unknown ingredients", 0);
	this->ingredients.push_back(temp);
}

void Recipe::setPreparationTime(const size_t& preparationTime)
{
	if (preparationTime < SIZE_T_LIMIT && preparationTime > 0)
	{
		this->preparationTime = preparationTime;
		return;
	}
	this->preparationTime = 30;
	std::cout << "Invalid preparation time data! Preparation time set to 30 minutes by default." << std::endl;
}

void Recipe::setInstructions(const MyString& instructions)
{
	if (instructions.c_str() != nullptr && instructions.getSize() > 0)
	{
		this->instructions = instructions;
		return;
	}
	this->instructions = "No instructions";
}

void Recipe::setRandomID()
{
	srand(time(NULL));
	ID = (rand() % 999) + 1;
}

void Recipe::setInitialRatingState()
{
	averageRating = 0;
}

void Recipe::addRating(const size_t& rating)
{
	if (rating > 5)
		return;

	ratings.push_back(rating);
	
	size_t count = 0;
	double sum = 0.0;
	while (count < ratings.getSize())
	{
		sum += ratings[count];
		++count;
	}

	averageRating = sum / count;
}

const MyString Recipe::getName() const
{
	return name;
}

const IngredientList Recipe::getIngredients() const
{
	return ingredients;
}

const size_t Recipe::getPreparationTime() const
{
	return preparationTime;
}

const MyString Recipe::getInstructions() const
{
	return instructions;
}

const int Recipe::getID() const
{
	return ID;
}

const double Recipe::getRating() const
{
	return averageRating;
}

void Recipe::inputIngredients()
{
	size_t num = 0;
	std::cout << "Please, type the number of ingredients: ";
	while (true)
	{
		std::cin >> num;
		if (num > 0 && num < 50) // 50 is the limit
			break;
		else
			std::cout << "Invalid number of products. Please try again..." << std::endl;
	}
	
	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Ingredient: ";
		std::cin.ignore();
		MyString product;
		std::cin >> product;
		std::cout <<  "Number of ingredients of this type: ";
		size_t number;
		std::cin >> number;
		std::cout << std::endl;
		Pair<MyString, size_t> temp(product, number);
		ingredients.push_back(temp);
	}
}
