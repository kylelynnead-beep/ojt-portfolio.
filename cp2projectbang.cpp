#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(string n, double p) {
        name = n;
        price = p;
    }

    string getName() { return name; }
    double getPrice() { return price; }
};

class CartItem {
public:
    MenuItem item;
    int quantity;

    CartItem(MenuItem i, int q) : item(i), quantity(q) {}

    double getTotal() {
        return item.getPrice() * quantity;
    }
};

    void displayMenu(vector<MenuItem> menu) {
    cout << "\n--- MENU ---\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].getName()
             << " - PHP " << menu[i].getPrice() << endl;
    }
}

    void viewCart(vector<CartItem> cart) {
    double subtotal = 0;
    cout << "\n--- YOUR CART ---\n";

    if (cart.empty()) {
        cout << "Cart is empty.\n";
        return;
    }

    for (int i = 0; i < cart.size(); i++) {
        double total = cart[i].getTotal();
        subtotal += total;

        cout << cart[i].item.getName()
             << " x" << cart[i].quantity
             << " = PHP " << total << endl;
    }

    cout << "Subtotal: PHP " << subtotal << endl;
}

    void checkout(vector<CartItem> cart) {
    double total = 0;

    if (cart.empty()) {
        cout << "Cart is empty.\n";
        return;
    }

    cout << "\n--- CHECKOUT ---\n";

    for (int i = 0; i < cart.size(); i++) {
        total += cart[i].getTotal();
    }

    cout << "Grand Total: PHP " << total << endl;

    double payment;
    do {
        cout << "Enter payment: ";
        cin >> payment;

        if (payment < total) {
            cout << "Insufficient Funds. Try again.\n";
        }

    } while (payment < total);

    cout << "Change: PHP " << payment - total << endl;
    cout << "Thank you for ordering at McDo!\n";
}

int main() {

    vector<MenuItem> regularChickenMeals = {
    MenuItem("1-pc Chicken McDo w/ Rice & Drink", 109),
    MenuItem("2-pc Chicken McDo w/ Rice & Drink", 229),
    MenuItem("1-pc Chicken McDo w/ Fries & Drink", 176),
    MenuItem("2-pc Chicken McDo w/ Fries & Drink", 281),
    MenuItem("1-pc Chicken McDo w/ McSpaghetti & Drink", 195),
    MenuItem("1-pc Chicken McDo w/ McSpaghetti & Fries Meal", 251)
};

    vector<MenuItem> spicyChickenMeals = {
    MenuItem("1-pc Spicy Chicken McDo w/ Rice & Drink", 115),
    MenuItem("2-pc Spicy Chicken McDo w/ Rice & Drink", 241),
    MenuItem("1-pc Spicy Chicken McDo w/ Fries & Drink", 182),
    MenuItem("2-pc Spicy Chicken McDo w/ Fries & Drink", 293),
    MenuItem("1-pc Spicy Chicken McDo w/ McSpaghetti & Drink", 201),
    MenuItem("1-pc Spicy Chicken McDo w/ McSpaghetti & Fries Meal", 257)
};

    vector<MenuItem> crispyChickenFillet = {
    MenuItem("McCrispy Chicken Fillet w/ Rice & Drink", 108),
    MenuItem("McCrispy Chicken Fillet w/ Fries & Drink", 156),
    MenuItem("McCrispy Chicken Fillet Ala King w/ Rice & Drink", 115),
    MenuItem("McCrispy Chicken Fillet Ala King w/ Fries & Drink", 163)
    };

    vector<MenuItem> chickenMcNuggets = {
    MenuItem("6-pc Chicken McNuggets w/ Rice & Drink", 182),
    MenuItem("6-pc Chicken McNuggets w/ Fries & Drink", 203),
    MenuItem("10-pc Chicken McNuggets", 189),
    MenuItem("20-pc Chicken McNuggets", 375)
};

    vector<MenuItem> burgerMeals = {
    MenuItem("Burger McDo w/ Fries & Drink", 143),
    MenuItem("Cheesy Burger McDo w/ Fries & Drink", 160),
    MenuItem("Cheeseburger w/ Fries & Drink", 129),
    MenuItem("Double Cheeseburger w/ Fries & Drink", 227),
    MenuItem("Triple Cheeseburger w/ Fries & Drink", 273)
};

    vector<MenuItem> premiumBurgerMeals = {
    MenuItem("Big Mac w/ Fries & Drink", 271),
    MenuItem("Double Big Mac w/ Fries & Drink", 331),
    MenuItem("Quarter Pounder w/ Cheese w/ Fries & Drink", 271),
    MenuItem("Double Quarter Pounder w/ Cheese w/ Fries & Drink", 327)
    };

    vector<MenuItem> desserts = {
    MenuItem("McFlurry with Oreo", 66),
    MenuItem("Hot Fudge Sundae", 55),
    MenuItem("Apple Pie", 33)
};

    vector<MenuItem> juices = {
    MenuItem("Orange Juice", 82),
    MenuItem("Pineapple Juice", 82)
};

    vector<MenuItem> floats = {
    MenuItem("Coke McFloat", 77),
    MenuItem("Royal McFloat", 84)
};

    vector<MenuItem> softdrinks = {
    MenuItem("Coke (Medium)", 75),
    MenuItem("Sprite (Medium)", 75)
};

    vector<MenuItem> mcCafe = {
    MenuItem("McCafé Iced Coffee", 61),
    MenuItem("McCafé Coffee Float", 82)
};

    vector<MenuItem> mcMuffins = {
    MenuItem("Egg McMuffin", 95),
    MenuItem("Sausage McMuffin", 95),
    MenuItem("Sausage McMuffin with Egg", 105),
    MenuItem("Longganisa McMuffin with Egg", 115),
    MenuItem("Cheesy Eggdesal", 75)
};

    vector<MenuItem> riceMeals = {
    MenuItem("Longganisa w/ Egg & Rice", 138),
    MenuItem("Sausage w/ Egg & Rice", 123),
    MenuItem("McCrispy Chicken Fillet w/ Egg", 130),
    MenuItem("McCrispy Chicken Fillet Ala King w/ Egg", 133),
    MenuItem("1-pc Chicken McDo w/ Egg", 136),
    MenuItem("2-pc Chicken McDo w/ Egg", 204)
};

    vector<MenuItem> hotcakes = {
    MenuItem("2-pc Hotcakes", 89),
    MenuItem("2-pc Hotcakes with Sausage", 119),
    MenuItem("Big Breakfast", 165),
    MenuItem("Big Breakfast w/ Drink", 185),
    MenuItem("Sausage Platter w/ Rice", 135)
};

    vector<CartItem> cart;

int choice;

do {
    cout << "\n===== McDonald's Ordering System =====\n";
    cout << "= 1. Chicken & Platters              =\n";
    cout << "= 2. Burgers & Fries                 =\n";
    cout << "= 3. Drinks & Desserts               =\n";
    cout << "= 4. Breakfast                       =\n";
    cout << "= 5. View Cart                       =\n";
    cout << "= 6. Checkout & Pay                  =\n";
    cout << "= 7. Exit                            =\n";
    cout << "======================================" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    vector<MenuItem> selectedMenu;

    if (choice == 1) {
        int subChoice;

        cout << "\n=== Chicken & Platters ===\n";
        cout << "1. Regular Chicken\n";
        cout << "2. Spicy Chicken\n";
        cout << "3. Crispy Chicken Fillet\n";
        cout << "4. Chicken McNuggets\n";
        cout << "5. Back\n";
         cout << "==========================" << endl;
        cout << "Enter choice: ";
        cin >> subChoice;

        if (subChoice == 1) selectedMenu = regularChickenMeals;
        else if (subChoice == 2) selectedMenu = spicyChickenMeals;
        else if (subChoice == 3) selectedMenu = crispyChickenFillet;
        else if (subChoice == 4) selectedMenu = chickenMcNuggets;
        else if (subChoice == 5) continue;
        else {
            cout << "Invalid choice.\n";
            continue;
        }

    }
    else if (choice == 2) {
        int subChoice;

        cout << "\n=== Burgers ===\n";
        cout << "1. Burger Meal\n";
        cout << "2. Premium Burger Meal\n";
        cout << "3. McChicken Meal\n";
        cout << "4. Back\n";
        cout << "===============" << endl;
        cout << "Enter choice: ";
        cin >> subChoice;

        if (subChoice == 1) selectedMenu = desserts;
        else if (subChoice == 2) selectedMenu = juices;
        else if (subChoice == 3) selectedMenu = floats;
        else if (subChoice == 4) continue;
        else {
            cout << "Invalid choice.\n";
            continue;
        }



    }
    else if (choice == 3) {
        int subChoice;

        cout << "\n=== DESSERTS & DRINKS ===\n";
        cout << "1. Desserts\n";
        cout << "2. Juices\n";
        cout << "3. Floats\n";
        cout << "4. Soft Drinks\n";
        cout << "5. Back\n";
        cout << "=========================" << endl;
        cout << "Enter choice: ";
        cin >> subChoice;

        if (subChoice == 1) selectedMenu = desserts;
        else if (subChoice == 2) selectedMenu = juices;
        else if (subChoice == 3) selectedMenu = floats;
        else if (subChoice == 4) selectedMenu = softdrinks;
        else if (subChoice == 5) continue;
        else {
            cout << "Invalid choice.\n";
            continue;
        }
    }

    else if (choice == 4) {
    int subChoice;

    cout << "\n=== BREAKFAST ===\n";
    cout << "1. McMuffins\n";
    cout << "2. Rice Meals\n";
    cout << "3. Hotcakes\n";
    cout << "4. McCafe\n";
    cout << "5. Back\n";
    cout << "=================" << endl;
    cout << "Enter choice: ";
    cin >> subChoice;

    if (subChoice == 1) selectedMenu = mcMuffins;
    else if (subChoice == 2) selectedMenu = riceMeals;
    else if (subChoice == 3) selectedMenu = hotcakes;
    else if (subChoice == 4) selectedMenu = mcCafe;
    else if (subChoice == 5) continue;
    else {
        cout << "Invalid choice.\n";
        continue;
    }
}

    else if (choice == 5) {
    int cartChoice;

    do {
        viewCart(cart);

        cout << "\n1. Back to Main Menu\n";
        cout << "2. Checkout\n";
        cout << "Enter choice: ";
        cin >> cartChoice;

        if (cartChoice == 2) {
            checkout(cart);
            return 0; // exit after payment
        }

    } while (cartChoice != 1);

    continue;
}

    else if (choice == 6) {
        checkout(cart);
        break;
    }

    else if (choice == 7) {
        break;
    }

    else {
        cout << "Invalid choice.\n";
        continue;
    }

    displayMenu(selectedMenu);

    int itemChoice, qty;
    cout << endl;
    cout << "Enter item number: ";
    cin >> itemChoice;

    cout << "Enter quantity: ";
    cin >> qty;
    cout<< endl;
    if (itemChoice > 0 && itemChoice <= selectedMenu.size()) {
        cart.push_back(CartItem(selectedMenu[itemChoice - 1], qty));
        cout << "=== Item was added to cart! ===\n";
        cout << endl;
    } else {
        cout << "--- Invalid item. ---\n";
        cout << endl;
    }

} while (true);

cout << "Program exited.\n";
    return 0;
}
