#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <climits>


using namespace std;


class Item
{
    public:
        Item()
        {
            name = new char[20];
            float price;
            float quantity;
        }
        void add_data();
        void edit_data();
        void update_quanity(int);
        void display_data();
		float get_price();
		void set_quantity(int);
		int get_quantity();
        int is_match(char[]);

    private:
        char *name;
        float price;
        int quantity;
};


class Inventory
{
	public:
		void add_item();
		void remove_item(int);
		void sell_item();
		void sell_item(int);
		void find_item();
		void edit_item();
		void list_items();

	private:
		Item *items[20];
		float total_money = 0.0f;
		int item_count = 0;
		char item_to_check[20];
};


void Item::add_data()
{
	cin.ignore();
	cout << "\nEnter item name: "; cin.getline(name, 20);
    cout << "Enter quantity: "; cin >> quantity;
    cout << "Enter price: "; cin >> price;
}

void Item::edit_data()
{
	cout << "\nEnter new item name: "; cin.getline(name,20);
    cout << "Enter new quantity: "; cin >> quantity;
    cout << "Enter new price: "; cin >> price;
}

void Item::display_data()
{
	cout << "\nItem name: " << name;
    cout << "\nQuantity: " << quantity;
    cout << "\nPrice: " << price;
}

float Item::get_price()
{
	return price;
}

void Item::set_quantity(int new_quantity)
{
    quantity = new_quantity;
}

int Item::get_quantity()
{
	return quantity;
}

int Item::is_match(char object_to_buy[20])
{
    if (strcmp(object_to_buy, name) == 0)
	{
		return 1;
    }
    return 0;	
}

void Inventory::add_item()
{
	items[item_count] = new Item;
	items[item_count]->add_data();
	item_count++;
}

void Inventory::remove_item(int item_index)
{
	Item* item = items[item_index];
	int quantity = item->get_quantity();
	if (quantity == 0) {
		delete item;
		item_count--;
		cout << "\nItem Removed";
	}
}

void Inventory::sell_item()
{
	cin.ignore();
	cout<<"\nEnter item name: "; cin.getline(item_to_check, 20);

	for(int i=0; i<item_count; i++)
	{
		if (items[i]->is_match(item_to_check))
		{
			sell_item(i);
			remove_item(i);
		}
	}
	cout << "\nThis item is not in your Inventory";
}

void Inventory::sell_item(int item_index)
{
	int input_quantity;
	Item* item = items[item_index];
	cout << "\nEnter number of items to sell: "; cin >> input_quantity;

	int quantity = item->get_quantity();
	if (input_quantity <= quantity)
    {
		float price = item->get_price();
		float money_earned = price * input_quantity;
		item->set_quantity(quantity - input_quantity);
		cout << "\nItems sold sucessfully";
		cout << "\nMoney received: "<< money_earned;
		total_money += money_earned;

	}
	else
	{
		cout << "\nCannot sell more items than you have.";
	}
}

void Inventory::find_item()
{
	cin.ignore();
	cout << "\nEnter item name: ";
	cin.getline(item_to_check, 20);

	for (int i=0; i<item_count; i++)
	{
		if (items[i]->is_match(item_to_check))
		{
			cout << "\nItem found";
			items[i]->display_data();
			return;
		}
	}
	cout << "\nThis item is not in your Inventory";
}

void Inventory::edit_item()
{
	cin.ignore();
	cout << "\nEnter item name: ";
	cin.getline(item_to_check, 20);

	for (int i=0; i<item_count; i++)
	{
		if (items[i]->is_match(item_to_check))
		{
			cout << "\nItem found";
			items[i] -> edit_data();
			return;
		}
	}

	cout << "\nThis item is not in your Inventory";
}


void Inventory::list_items()
{
	if (item_count == 0)
	{
		cout << "\nInventory empty.";
		return;
	}

	for (int i=0; i<item_count; i++)
	{
		items[i]->display_data();
		cout << "\n";
	}
}

int main()
{
	int choice;
    Inventory inventory_system;

	while(1)
	{
		cout << "\n\nMENU"
		<< "\n1. Add new item"
		<< "\n2. Sell item"
		<< "\n3. Find item"
		<< "\n4. Edit item"
		<< "\n5. List items"
		<< "\n6. Exit"
		<< "\n\nEnter your choice: ";
		cin >> choice;
		
		switch(choice)	{
			case 1:
                inventory_system.add_item();
				break;

			case 2:
				inventory_system.sell_item();
                break;

			case 3:
				inventory_system.find_item();
                break;

			case 4:
                inventory_system.edit_item();
                break;

			case 5:
				inventory_system.list_items();
				break;

			case 6:
				exit(0);
				break;

			default:
				cout << "\nInvalid choice entered";
				cin.clear();
                cin.ignore(INT_MAX,'\n');	
				break;
		}
	}
	return 0;
}