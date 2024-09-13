#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Customer {
    int customerID;
    string name;
    string email;
};

class Product {
    string productID;
    string name;
    float price;
    string description;

public:
    Product(string id, string nm, float pr, string desc) {
        productID = id;
        name = nm;
        price = pr;
        description = desc;
    }

    string getProductID() {
        return productID;
    }

    string getName() {
        return name;
    }

    float getPrice() {
        return price;
    }

    void displayProduct() {
        cout << left << setw(10) << productID
             << setw(20) << name
             << setw(10) << price
             << setw(40) << description << endl;
    }
};

// Class to represent an order
class Order {
    int orderID;
    vector<Product> orderedItems;
    vector<int> quantities;
    float totalAmount;

public:
    Order(int id, vector<Product> items, vector<int> qty, float total)
            : orderID(id), orderedItems(items), quantities(qty), totalAmount(total) {}

    void displayOrder() {
        cout << "Order ID: " << orderID << endl;
        cout << "Order Details:" << endl;
        cout << left << setw(10) << "ID"
             << setw(20) << "Item"
             << setw(10) << "Price"
             << setw(10) << "Qty"
             << setw(10) << "Amount" << endl;
        cout << "-----------------------------------------------" << endl;

        for (size_t i = 0; i < orderedItems.size(); ++i) {
            float amount = orderedItems[i].getPrice() * quantities[i];
            cout << left << setw(10) << orderedItems[i].getProductID()
                 << setw(20) << orderedItems[i].getName()
                 << setw(10) << orderedItems[i].getPrice()
                 << setw(10) << quantities[i]
                 << setw(10) << amount << endl;
        }

        cout << "-----------------------------------------------" << endl;
        cout << "Total: " << totalAmount << endl;
    }

    int getOrderID() {
        return orderID;
    }
};

// Class to represent the shopping cart
class ShoppingCart {
    vector<Product> cartItems;
    vector<int> quantities;
    vector<Order> orders;
    static int orderCounter; // To track the order ID

public:
    void addToCart(Product p, int qty) {
        cartItems.push_back(p);
        quantities.push_back(qty);
    }

    void viewCart() {
        if (cartItems.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }

        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Qty" << endl;
        cout << "----------------------------------------------------------" << endl;

        for (size_t i = 0; i < cartItems.size(); ++i) {
            cout << left << setw(10) << cartItems[i].getProductID()
                 << setw(20) << cartItems[i].getName()
                 << setw(10) << cartItems[i].getPrice()
                 << setw(10) << quantities[i] << endl;
        }

        char choice;
        cout << "\nDo you want to check out all the products? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            checkout();
        }
    }

    void checkout() {
        float totalAmount = 0;
        cout << "\nCheckout Details:" << endl;
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(10) << "Qty"
             << setw(10) << "Amount" << endl;
        cout << "--------------------------------------------------------------" << endl;

        for (size_t i = 0; i < cartItems.size(); ++i) {
            float amount = cartItems[i].getPrice() * quantities[i];
            totalAmount += amount;
            cout << left << setw(10) << cartItems[i].getProductID()
                 << setw(20) << cartItems[i].getName()
                 << setw(10) << cartItems[i].getPrice()
                 << setw(10) << quantities[i]
                 << setw(10) << amount << endl;
        }

        cout << "--------------------------------------------------------------" << endl;
        cout << "Total Amount: " << totalAmount << endl;
        cout << "You have successfully checked out the products!" << endl;

        // Create an order and store it in the orders vector
        orders.push_back(Order(++orderCounter, cartItems, quantities, totalAmount));

        // Clear the cart after checkout
        cartItems.clear();
        quantities.clear();
    }

    void viewOrders() {
        if (orders.empty()) {
            cout << "No orders have been placed yet." << endl;
            return;
        }

        // Display each order
        for (size_t i = 0; i < orders.size(); ++i) {
            orders[i].displayOrder();
        }
    }
};

// Initialize the order counter
int ShoppingCart::orderCounter = 0;

void welcomeMessage() {
    int width = 40;
    string greeting = "Welcome to COFFEEFFEE";
    string message = "Shop Easy, Shop Breezy";
    int greetingLength = greeting.length();
    int greetingSpace = (width - greetingLength) / 2;
    int messageLength = message.length();
    int messageSpace = (width - messageLength) / 2;

    for (int i = 0; i < greetingSpace; i++) {
        cout << " ";
    }
    cout << greeting << endl;
    for (int i = 0; i < messageSpace; i++) {
        cout << " ";
    }
    cout << message << endl << endl;
}

void menu() {
    cout << "MAIN MENU" << endl;
    cout << "1. View Products" << endl;
    cout << "2. View Cart" << endl;
    cout << "3. View Orders" << endl;
    cout << "4. Exit" << endl;
}

// Function to display products in a table format and allow adding to the cart
void viewProducts(Product p1, Product p2, Product p3, Product p4, ShoppingCart &cart) {
    char addMore;

    do {
        // Display table header
        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(40) << "Description" << endl;
        cout << "--------------------------------------------------------------" << endl;

        // Display each product's details
        p1.displayProduct();
        p2.displayProduct();
        p3.displayProduct();
        p4.displayProduct();

        string productID;
        int qty;
        cout << endl << "Enter Product ID to add to cart: ";
        cin >> productID;

        // Add product based on ID and quantity
        if (productID == "AAA") {
            cout << "Enter quantity: ";
            cin >> qty;
            cart.addToCart(p1, qty);
            cout << "Product added successfully!" << endl;
        } else if (productID == "BBB") {
            cout << "Enter quantity: ";
            cin >> qty;
            cart.addToCart(p2, qty);
            cout << "Product added successfully!" << endl;
        } else if (productID == "CCC") {
            cout << "Enter quantity: ";
            cin >> qty;
            cart.addToCart(p3, qty);
            cout << "Product added successfully!" << endl;
        } else if (productID == "DDD") {
            cout << "Enter quantity: ";
            cin >> qty;
            cart.addToCart(p4, qty);
            cout << "Product added successfully!" << endl;
        } else {
            cout << "INVALID ID" << endl;
        }

        // Ask user if they want to add another product
        do {
            cout << "Add another product? [Y/N]: ";
            cin >> addMore;
            if (addMore != 'Y' && addMore != 'y' && addMore != 'N' && addMore != 'n') {
                cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
            }
        } while (addMore != 'Y' && addMore != 'y' && addMore != 'N' && addMore != 'n');

    } while (addMore == 'Y' || addMore == 'y');  // Continue adding products if 'Y'

    // Return to main menu after adding products
}

int main() {
    welcomeMessage();
    ShoppingCart cart;
    Product p1("AAA", "Americano", 110, "Bold espresso with hot water");
    Product p2("BBB", "Spanish Latte", 130, "Sweet latte with condensed milk");
    Product p3("CCC", "Cappuccino", 145, "Espresso with frothy milk");
    Product p4("DDD", "Cold Brew", 140, "Chilled smooth coffee brew");

    string choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            viewProducts(p1, p2, p3, p4, cart);
        } else if (choice == "2") {
            cart.viewCart();
        } else if (choice == "3") {
            cart.viewOrders();
        } else if (choice == "4") {
            cout << "Thank you for shopping at COFFEEFFEE!" << endl;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != "4");

    return 0;
}
