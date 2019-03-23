# include "Automata.h"

Automata::Automata() :cash(0), state(STATES::printMenu), menu(nullptr), prices(nullptr)
{
	this->menu = new std::string[10];
	this->prices = new int[10];

	FILE* input = fopen("input.txt", "r");
	
	if (input == NULL)
	{
		std::cout << "Input file not found!" << std::endl;
		return;
	}
	
	for (int i = 0; i < 10; i++)
	{
		char* temp_string = new char[50];
		fscanf(input, "%s %d/n", temp_string, &this->prices[i]);
		this->menu[i] = temp_string;
		delete [] temp_string;
	}
	fclose(input);
	this->printMenu();

}
Automata::~Automata()
{
	delete [] this->menu;
	delete [] this->prices;
}


void Automata::printMenu()
{
	this->state = STATES::printMenu;

		for (int i = 0; i < 10; i++)
		{
			std::cout <<i<<": " << this->menu[i] << " " << this->prices[i] << std::endl;
		}	
		choice();
}

void Automata::choice()
{
	this->state = STATES::choice;

	int cost_drink;
	int button = (getch())-48;
	switch (button)
	{
	case 0:
		cost_drink = this->prices[0];
		std::cout << "You choice is  -\t  " << this->menu[0] << std::endl;
		coin(cost_drink);
	break;

	case 1:
		cost_drink = this->prices[1];
		std::cout << " You choice is -\t  " << this->menu[1] << std::endl;
		coin(cost_drink);
	break;
	
	case 2:
		cost_drink = this->prices[2];
		std::cout << "You choice is -\t  " << this->menu[2] << std::endl;
		coin(cost_drink);
	break;
	
	case 3:
		cost_drink = this->prices[3];
		std::cout << "You choice is  -\t  " << this->menu[3] << std::endl;
		coin(cost_drink);
	break;
	
	case 4:
		cost_drink = this->prices[4];
		std::cout << "You choice is  -\t  " << this->menu[4] << std::endl;
		coin(cost_drink);
	break;
	
	case 5:
		cost_drink = this->prices[5];
		std::cout << "You choice is  -\t  " << this->menu[5] << std::endl;
		coin(cost_drink);
	break;
	
	case 6:
		cost_drink = this->prices[6];
		std::cout << "You choice is  -\t  " << this->menu[6] << std::endl;
		coin(cost_drink);
	break;
	
	case 7:
		cost_drink = this->prices[7];
		std::cout << "You choice is  -\t  " << this->menu[7] << std::endl;
		coin(cost_drink);
	break;
	
	case 8:
		cost_drink = this->prices[8];
		std::cout << "You choice is  -\t  " << this->menu[8] << std::endl;
		coin(cost_drink);
	break;
	
	case 9:
		cost_drink = this->prices[9];
		std::cout << "You choice is  -\t  " << this->menu[9] << std::endl;
		coin(cost_drink);
	break;
	
	default:
		choice();
	}
}

void Automata::coin(int cost_drink)
{
	this->state = STATES::coin;
	char buttom = getch();
	
	switch (buttom)
	{
	case 'q': // cancel
		cancel(cost_drink);
		break;
	case 'x':
		this->cash =this->cash + 10;
		check(cost_drink);
		break;
	case 'v':
		this->cash = this->cash + 5;
		check(cost_drink);
		break;
	case 'l':
		this->cash = this->cash+50;
		check(cost_drink);
		break;
	case 'c':  
		this->cash =this->cash+ 100;
		check(cost_drink);
		break;
	default:
		std::cout << "No money." << std::endl;
		coin(cost_drink);
	}

}

void Automata::cancel(int cost_drink)
{
	this->state = STATES::cancel;
	std::cout<< "Your delivery =" << this->cash << std::endl;
	this->cash = 0;
	// system("pause");
	// system("cls");
	this->printMenu();
	this->choice();
}

void Automata::check( int cost_drink)
{
	this->state = STATES::check;
	std::cout << "Your cash =" << this->cash <<std::endl;
	if (this->cash == cost_drink)
	{
		cook();
		finish(cost_drink);
	}
	
	if (this->cash > cost_drink)
	{
		cook();
		std::cout << "Your delivery =" << this->cash - cost_drink <<std::endl;
		finish(cost_drink);
	}
	
	if (this->cash < cost_drink)
	{
		int buttom = getch();
		
		if (buttom != 'q')
		{
			coin(cost_drink);
		}
		else
			cancel(cost_drink);
	}
}
void Automata::cook()
{
	this->state = STATES::cook;
	std::cout << "Ready!" << std::endl;
}
void Automata::finish(int cost_drink)
{
	this->state = STATES::finish;
	this->cash = 0;
	// system("pause");
	// system("cls");
	this->printMenu();
}