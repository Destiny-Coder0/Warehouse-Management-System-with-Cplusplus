#include <iostream>
#include <string>
using namespace std;

const int maxProducts = 100;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
    string origin;
};

class Warehouse {
private:
    Product products[maxProducts]; //array to store products
    int productCount = 0;

public:
    void addProduct() {
        if (productCount >= maxProducts) {
            cout << "Warehouse is full. Cannot add more products." << endl;
            return;
        }

        Product newProduct;

        cout << "Enter product ID: ";
        cin >> newProduct.id;

        for (int i = 0; i < productCount; i++) {
            if (products[i].id == newProduct.id) {
                cout << "Product with ID " << newProduct.id << " already exists. Please enter a different ID." << endl;
                return;
            }
        }

        cout << "Enter product name: ";
        cin >> newProduct.name;

        cout << "Enter product quantity: ";
        cin >> newProduct.quantity;

        cout << "Enter product price: ";
        cin >> newProduct.price;

        cout << "Enter product origin: ";
        cin >> newProduct.origin;

        products[productCount++] = newProduct;
        cout << "Product added successfully!" << endl;
    }

    void updateProductQuantity(int id, int quantityChange) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                products[i].quantity += quantityChange;
                if (quantityChange > 0)
                    cout << "Quantity of product with ID " << id << " increased by " << quantityChange << " successfully!" << endl;
                else if (quantityChange < 0)
                    cout << "Quantity of product with ID " << id << " decreased by " << quantityChange << " successfully!" << endl;
                else
                    cout << "Quantity of product with ID " << id << " remains unchanged." << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void updateProductPrice(int id, double newPrice) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                products[i].price = newPrice;
                cout << "Price of product with ID " << id << " updated successfully!" << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void removeProduct(int id) {
        for (int i = 0; i <productCount; i++) {
            if (products[i].id == id) {
                for (int j = i; j < productCount - 1; j++) {
                    products[j] = products[j + 1];
                }
                productCount = productCount - 1;
                cout << "Product removed successfully!" << endl;
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayProducts() {
        cout << "Product ID\tProduct Name\tQuantity\tPrice\tOrigin" << endl;
        for (int i = 0; i < productCount; i++) {
            cout << products[i].id << "\t\t" << products[i].name << "\t\t"
                 << products[i].quantity << "\t\t" << products[i].price << "\t"
                 << products[i].origin << endl;
        }
    }

    double calculateTotalValue() {
        double totalValue = 0;
        for (int i = 0; i < productCount; i++) {
            totalValue += products[i].quantity * products[i].price;
        }
        return totalValue;
    }

    double calculateProductValue(int id) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == id) {
                return products[i].quantity * products[i].price;
            }
        }
        return 0; 
    }
};

int main() {
    Warehouse warehouse;
    char choice;

    do {
        cout << "\n1. Add Product\n2. Update Product Quantity\n3. Update Product Price\n4. Remove Product\n5. Display Products\n6. Calculate Total Value\n7. Calculate Product Value\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                warehouse.addProduct();
                break;
            }
            case '2': {
                int id, quantityChange;
                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter quantity change (- for decrease, + for increase): ";
                cin >> quantityChange;
                warehouse.updateProductQuantity(id, quantityChange);
                break;
            }
            case '3': {
                int id;
                double newPrice;
                cout << "Enter product ID to update price: ";
                cin >> id;
                cout << "Enter new price: ";
                cin >> newPrice;
                warehouse.updateProductPrice(id, newPrice);
                break;
            }
            case '4': {
                int id;
                cout << "Enter product ID to remove: ";
                cin >> id;
                warehouse.removeProduct(id);
                break;
            }
            case '5':
                warehouse.displayProducts();
                break;
            case '6':
                cout << "Total value of products in the warehouse: " << warehouse.calculateTotalValue() << " TL" << endl;
                break;
            case '7': {
                int id;
                cout << "Enter product ID to calculate value: ";
                cin >> id;
                double productValue = warehouse.calculateProductValue(id);
                if (productValue != 0) {
                    cout << "Total value of product with ID " << id << ": " << productValue << " TL" << endl;
                } else {
                    cout << "Product with ID " << id << " not found." << endl;
                }
                break;
            }
            case '8':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice.\n";
                break;
        }
    } while (choice != '8');

    return 0;
}
