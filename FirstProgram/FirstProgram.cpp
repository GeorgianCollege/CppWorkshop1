#include <iostream>
#include <string>

/**
 *
 * This function is used to get the valid input from the user.
 * 
 * @tparam T 
 * @param prompt {std::string}
 * @return 
 */
template <class T>
T GetValidInput(const std::string& prompt)
{
	T inputValue;
	auto inputNotValid = true;
	while (inputNotValid)
	{
		std::cout << prompt;

		std::cin >> inputValue;
		inputNotValid = std::cin.fail();
		if (inputNotValid)
		{
			std::cout << "Invalid input. Please enter a valid number." << '\n';
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	}
	return inputValue;
}


int main()
{
	auto playerScore = 10;

	auto firstname = GetValidInput<std::string>("Please enter your first name: ");
	auto scoreValue = GetValidInput<int>("Please enter the score to add: ");
	auto bonusFactor = GetValidInput<float>("Please enter the bonus factor: ");
	playerScore += static_cast<int>(static_cast<float>(scoreValue) * bonusFactor);

    std::cout << "The Final Player Score for " << firstname << " is: " + std::to_string(playerScore) << '\n';
}


