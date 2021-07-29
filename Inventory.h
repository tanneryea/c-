#pragma once

class Inventory 
{
private:
	int itemNumber;
	int quantity;
	double cost;
	double totalCost;
public:
	Inventory();
	Inventory(int, double, int);
	void setItemNumber(int);
	void setQuantity(int);
	void setCost(double);
	void setTotalCost();
	
	//Inline functions for ease of use
	int getItemNumber() const
	{
		return itemNumber;
	}
	int getQuantity() const
	{
		return quantity;
	}
	double getCost() const
	{
		return cost;
	}
	double getTotalCost() const
	{
		return totalCost;
	}



};