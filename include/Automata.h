#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<conio.h>
enum STATES
{
	cancel,
	printMenu,
	choice,
	coin,
	check,
	cook,
	finish
};
class Automata
{
public:
	Automata();
	~Automata();
	void printMenu();
	void choice();
	void coin(int cost_drink);
	void check(int cost_drink);
	void cancel(int cost_drink);
	void cook();
	void finish(int cost_drink);
	void effect(STATES state);
private:
	std::string* menu;
	int* prices;
	int cash;
	STATES state;
	
};

