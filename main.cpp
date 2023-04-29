#include <iostream>
#include <string>

class BranchFinances
{
private:
	const double percent = 0.07, rent = 50, salary = 35, limit = 270, service = 15;
	int income;
	double s, expenditure, rent_price;
public:
	BranchFinances() {};
	~BranchFinances() {};
	void set_income()
	{
		income = rand() % 251 + 250;
	}
	void set_rent_price()
	{
		set_income();
		if (income > limit)
		{
			s = income - limit;
		}
		else
		{
			s = 0;
		}
		rent_price = rent + s * percent;
	}
	void set_expenditure()
	{
		set_rent_price();
		expenditure = salary + rent_price + service;
	}
	void get_expenditure()
	{
		set_expenditure();
		std::cout << expenditure << '\n';
	}
	void get_profit()
	{
		std::cout << income - expenditure;
	}
};

class NewBranch : public BranchFinances
{
private:
	std::string branch_name;
public:
	NewBranch(std::string name)
	{
		branch_name = name;
	}
	~NewBranch() {};
};

int main()
{
	srand(time(0));
	NewBranch Branch("Top Branch");
	Branch.get_expenditure();
	Branch.get_profit();
	return 0;
}