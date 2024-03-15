#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << "Здравствуйте! Это лайт-версия службы заказов пиццерии Arseny's Pizza\n\n";



	int margarita = 5, amountOfMargarita = 0, priceOfMargarita;
	int peperoni = 6,  amountOfPeperoni = 0,  priceOfPeperoni;
	int greek = 4,     amountOfGreek = 0,     priceOfGreek;
	int cheese = 7,    amountOfCheese = 0,    priceOfCheese;

	int cola = 4,      amountOfCola = 0,      priceOfCola;
	int sok = 1,       amountOfSok = 0,       priceOfSok;
	int cacao = 3,     amountOfCacao = 0,     priceOfCacao;


	bool wasMargarita = false;
	bool wasPeperoni = false;
	bool wasGreek = false;
	bool wasCheese = false;

	bool wasCola = false;
	bool wasSok = false;
	bool wasCacao = false;


	int choicePizzas, choiceDrinks;
	int amountOfPizzas, amountOfDrinks;
	int morePizzas_Yes_No, moreDrinks_Yes_No;
	int allPizzas = 0, allDrinks = 0;

	int priceOfColaAndCacao = 0;

	int TOTAL = 0;

	std::cout << "\t-----------------МЕНЮ-----------------\n\n";
	std::cout << "\tПицца:\t\t\t  Напитки:\n\n";
	std::cout << "\t1) Маргарита   -  5$\t  1) Кола  -  4$\n";
	std::cout << "\t2) Пеперони    -  6$\t  2) Сок   -  1$\n";
	std::cout << "\t3) Греческая   -  4$\t  3) Какао -  7$\n";
	std::cout << "\t4) Четыре Сыра -  7$\n\n";


	//Пиццы
		
	for (int i = 0; i <= 4; i++)
	{
		std::cout << "Какую пиццу вы хотели бы заказать? (Введите номер):\n";
		std::cin >> choicePizzas;

		if (choicePizzas > 4)
		{
			std::cerr << "\nВведите номер продукта\n";
			continue;
		}

		std::cout << "Сколько?\n";
		std::cin >> amountOfPizzas;
			
		if (choicePizzas == 1)
		{
			amountOfMargarita += amountOfPizzas;
			priceOfMargarita = margarita * amountOfPizzas;
			TOTAL += priceOfMargarita;
			wasMargarita = true;
		}

		else if (choicePizzas == 2)
		{
			amountOfPeperoni += amountOfPizzas;
			priceOfPeperoni = peperoni * amountOfPizzas;
			TOTAL += priceOfPeperoni;
			wasPeperoni = true;
		}

		else if (choicePizzas == 3)
		{
			amountOfGreek += amountOfPizzas;
			priceOfGreek = greek * amountOfPizzas;
			TOTAL += priceOfGreek;
			wasGreek = true;
		}

		else if (choicePizzas == 4)
		{
			amountOfCheese += amountOfPizzas;
			priceOfCheese = cheese * amountOfPizzas;
			TOTAL += priceOfCheese;
			wasCheese = true;
		}

		allPizzas += amountOfPizzas;

		if (i < 4)
			{
			std::cout << "Ещё другую пиццу?\n\n    1) Да   2) Нет\n";
			std::cin >> morePizzas_Yes_No;

			if (morePizzas_Yes_No == 2)
			{
				break;
			}

			else if (morePizzas_Yes_No > 2)
			{
				std::cerr << "\nВведите номер ответа\n";
			}
		}
	}


	//Напитки


	for (int i = 0; i <= 3; i++)
	{
		std::cout << "Какой напиток вы хотели бы заказать? (Введите номер):\n";
		std::cin >> choiceDrinks;

		if (choiceDrinks > 3)
		{
			std::cerr << "\nВведите номер продукта\n";
			continue;
		}

		std::cout << "Сколько?\n";
		std::cin >> amountOfDrinks;

		if (choiceDrinks == 1)
		{
			amountOfCola += amountOfDrinks;
			priceOfCola = cola * amountOfDrinks;
			TOTAL += priceOfCola;
			priceOfColaAndCacao += cola * amountOfCola;
			wasCola = true;
		}

		else if (choiceDrinks == 2)
		{
			amountOfSok += amountOfDrinks;
			priceOfSok = sok * amountOfDrinks;
			TOTAL += priceOfSok;
			wasSok = true;
		}

		else if (choiceDrinks == 3)
		{
			amountOfCacao += amountOfDrinks;
			priceOfCacao = cacao * amountOfDrinks;
			TOTAL += priceOfCacao;
			priceOfColaAndCacao += cacao * amountOfCacao;
			wasCacao = true;
		}

		allDrinks += amountOfDrinks;

		if (i < 3)
		{
			std::cout << "Ещё другой напиток?\n\n    1) Да   2) Нет\n";
			std::cin >> moreDrinks_Yes_No;

			if (moreDrinks_Yes_No == 2)
			{
				break;
			}

			else if (moreDrinks_Yes_No > 2)
			{
				std::cerr << "\nВведите номер ответа\n";
			}
		}
	}




	//СКИДКИ

	if (TOTAL > 50)
	{
		std::cout << "\nУра! Вы получили скидку 20%!\n";
		TOTAL -= (TOTAL / 100 * 20);
	}

	if (allPizzas >= 4)
	{
		std::cout << "\nУра! Вам полагается пицца в подарок!\n";
	}

	if (amountOfCola + amountOfCacao > 3)
	{
		std::cout << "\nУра! Вы получили скидку 15% на напитки!\n";
		priceOfColaAndCacao -= (priceOfColaAndCacao / 100 * 15);
	}
		
	//ЧЕК

	std::cout << "\n_________Чек к оплате_________\n\n";
	std::cout << "Пицца:\t\tКоличество:\tЦена:\n\n";

	if (wasMargarita)
	{
		std::cout << "Маргарита_______" << amountOfMargarita << "_______________" << priceOfMargarita << "$\n";
	}

	if (wasPeperoni)
	{
		std::cout << "Пеперони________" << amountOfPeperoni << "_______________" << priceOfPeperoni << "$\n";
	}

	if (wasGreek)
	{
		std::cout << "Греческая_______" << amountOfGreek << "_______________" << priceOfGreek << "$\n";
	}

	if (wasCheese)
	{
		std::cout << "Четыре Сыра_____" << amountOfCheese << "_______________" << priceOfCheese << "$\n";
	}

	std::cout << "\n\nНапитки:\tКоличество:\tЦена:\n\n";

	if (wasCola)
	{
		std::cout << "Кола____________" << amountOfCola << "_______________" << priceOfCola << "$\n";
	}

	if (wasSok)
	{
		std::cout << "Сок_____________" << amountOfSok << "_______________" << priceOfSok << "$\n";
	}

	if (wasCacao)
	{
		std::cout << "Какао___________" << amountOfCacao << "_______________" << priceOfCacao << "$\n";
	}

	std::cout << "\n\nИТОГО:   " << TOTAL << "$\n\n";



	return 0;
}