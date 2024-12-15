#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

void setColor(int textColor ) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = textColor ;
    SetConsoleTextAttribute(hConsole, colorAttribute);
}
#define COLOR_YELLOW  6      
#define COLOR_RED 4          
#define COLOR_GREEN 2        
#define COLOR_BLUE 1         
#define COLOR_WHITE 15       
#define COLOR_PURPLE 5      
#define COLOR_CYAN 3       
#define COLOR_PINK 13      
#define COLOR_GRAY 8       
#define COLOR_ORANGE 6     
#define COLOR_GOLD 11      


const int MAX_ORDERS = 100;
const int MAX_INVENTORY = 50;


struct Order {
    int orderId;
    char customerName[50];
    char itemName[50];
    int quantity;
    float price;
    bool isCompleted;
};

struct InventoryItem {
    char itemName[50];
    int stockQuantity;
    float price;
};


Order orders[MAX_ORDERS];
int orderCount = 0;

InventoryItem inventory[MAX_INVENTORY];
int inventoryCount = 0;

float totalSales = 0.0;


void mainMenu();
void orderManagement();
void inventoryManagement();
void paymentProcessing();
void displayMenu();
void placeOrder();
void viewOrders();
void updateOrder();
void deleteOrder();
void completeOrder();
void viewInventory();
void addInventoryItem();
void updateInventory();
bool checkInventory(const char itemName[], int quantity);
void addSampleInventory();


void addSampleInventory() {
    if (inventoryCount >= MAX_INVENTORY) {
        cout << "Inventory full. Cannot add more items.\n";
        return;
    }

    struct { const char* itemName; int stockQuantity; float price; } sampleItems[] = {
        {"Coffee", 100, 2.5},
        {"Cake", 50, 5.0},
        {"Pizza", 100, 6.5},
        {"Ramen", 100, 4.5},
        {"Tea", 100, 1.5}
    };

    for (int i = 0; i < 5; i++) {
        strcpy(inventory[inventoryCount].itemName, sampleItems[i].itemName);
        inventory[inventoryCount].stockQuantity = sampleItems[i].stockQuantity;
        inventory[inventoryCount].price = sampleItems[i].price;
        inventoryCount++;
    }
}


void mainMenu() {
    int choice;

    do {
        setColor(COLOR_RED );
        cout << "\n======= Cafeteria Order Management System =======\n";
        setColor(COLOR_CYAN); 
        cout << "1. Order Management\n";
        cout << "2. Inventory Management\n";
        cout << "3. Payment Processing\n";
        cout << "4. Exit\n";
        setColor(COLOR_RED); 
        cout << "=================================================\n";
        setColor(COLOR_GRAY); 
        cout << "Enter your choice: ";
        setColor(COLOR_PINK); 
        cin >> choice;

        switch (choice) {
            case 1: orderManagement(); break;
            case 2: inventoryManagement(); break;
            case 3: paymentProcessing(); break;
            case 4: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

// ========================== Order Management ==========================
void orderManagement() {
    int choice;

    do {
        setColor(COLOR_ORANGE);
        cout << "\n===== Order Management =====\n";
        setColor(COLOR_GREEN); 
        cout << "1. Display Menu\n";
        cout << "2. Place Order\n";
        cout << "3. View All Orders\n";
        cout << "4. Update Order\n";
        cout << "5. Delete Order\n";
        cout << "6. Mark Order as Completed\n";
        cout << "7. Back to Main Menu\n";
        setColor(COLOR_ORANGE); 
        cout << "=============================\n";
        setColor(COLOR_GRAY); 
        cout << "Enter your choice: ";
        setColor(COLOR_PINK); 
        cin >> choice;

        switch (choice) {
            case 1: displayMenu(); break;
            case 2: placeOrder(); break;
            case 3: viewOrders(); break;
            case 4: updateOrder(); break;
            case 5: deleteOrder(); break;
            case 6: completeOrder(); break;
            setColor(COLOR_GRAY);
            case 7: cout << "Returning to Main Menu...\n"; break;
             setColor(COLOR_GRAY);
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
}


void displayMenu() {
	 setColor(COLOR_WHITE);
    cout << "\n===== Menu =====\n";
    for (int i = 0; i < inventoryCount; i++) {
        cout << i + 1 << ". " << inventory[i].itemName << " $" << inventory[i].price << "\n";
    }
    cout << "================\n";
}


void placeOrder() {
    if (orderCount >= MAX_ORDERS) {
    	 setColor(COLOR_CYAN);
        cout << "Order list is full. Cannot place more orders.\n";
        return;
    }

    Order newOrder;
    newOrder.orderId = orderCount + 1;

    cin.ignore(); 
     setColor(COLOR_GRAY);
    cout << "Enter Customer Name: ";
    setColor(COLOR_PINK); 
    cin.getline(newOrder.customerName, 50);

    setColor(COLOR_GRAY); 
    cout << "Enter Item Name: ";
     setColor(COLOR_PINK);
    cin.getline(newOrder.itemName, 50);

  setColor(COLOR_GRAY); 
    cout << "Enter Quantity: ";
     setColor(COLOR_PINK);
    cin >> newOrder.quantity;

    
    if (!checkInventory(newOrder.itemName, newOrder.quantity)) {
    	 setColor(COLOR_PURPLE);
        cout << "Error: Item not available or insufficient stock.\n";
        return;
    }

    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(newOrder.itemName, inventory[i].itemName) == 0) {
            newOrder.price = inventory[i].price * newOrder.quantity;
            inventory[i].stockQuantity -= newOrder.quantity; 
        }
    }

    newOrder.isCompleted = false;
    orders[orderCount++] = newOrder;
 setColor(COLOR_PURPLE);
    cout << "Order placed successfully! Order ID: " << newOrder.orderId << "\n";
}


void viewOrders() {
    if (orderCount == 0) {
    	 setColor(COLOR_PURPLE);
        cout << "No orders available.\n";
        return;
    }
 setColor(COLOR_GOLD);
    cout << "\nID\tCustomer\tItem\t\tQuantity\tPrice\tStatus\n";
    cout << "--------------------------------------------------------------------------\n";
    for (int i = 0; i < orderCount; i++) {
        cout << orders[i].orderId << "\t" << orders[i].customerName << "\t\t"
             << orders[i].itemName << "\t\t" << orders[i].quantity << "\t\t"
             << orders[i].price << "\t" << (orders[i].isCompleted ? "Completed" : "Pending") << "\n";
    }
}


void updateOrder() {
    int id;
    setColor(COLOR_GRAY);
    cout << "Enter Order ID to update: ";
    setColor(COLOR_PINK);
    cin >> id;

    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == id) {
            cin.ignore();
            setColor(COLOR_GRAY);
            cout << "Enter new Customer Name: ";
            setColor(COLOR_PINK);
            cin.getline(orders[i].customerName, 50);
setColor(COLOR_GRAY);
            cout << "Enter new Item Name: ";
            setColor(COLOR_PINK);
            cin.getline(orders[i].itemName, 50);
setColor(COLOR_GRAY);
            cout << "Enter new Quantity: ";
            setColor(COLOR_PINK);
            cin >> orders[i].quantity;
setColor(COLOR_PURPLE);
            cout << "Order updated successfully.\n";
            return;
        }
    }setColor(COLOR_PURPLE);
    cout << "Order ID not found.\n";
}


void deleteOrder() {
    int id;
    setColor(COLOR_GRAY);
    cout << "Enter Order ID to delete: ";
    setColor(COLOR_PINK);
    cin >> id;

    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == id) {
            for (int j = i; j < orderCount - 1; j++) {
                orders[j] = orders[j + 1];
            }
            orderCount--;
            setColor(COLOR_PURPLE);
            cout << "Order deleted successfully!\n";
            return;
        }
    }
    setColor(COLOR_PURPLE);
    cout << "Order ID not found.\n";
}


void completeOrder() {
    int id;
    setColor(COLOR_GRAY);
    cout << "Enter Order ID to mark as completed: ";
    setColor(COLOR_PINK);
    cin >> id;

    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == id) {
            orders[i].isCompleted = true;
            totalSales += orders[i].price;
            setColor(COLOR_PURPLE);
            cout << "Order marked as completed!\n";
            return;
        }
    }
    setColor(COLOR_PURPLE);
    cout << "Order ID not found.\n";
}

// ========================== Inventory Management ==========================
void inventoryManagement() {
    int choice;
    do {
        setColor(COLOR_ORANGE);
        cout << "\n===== Inventory Management =====\n";
        setColor(COLOR_GREEN);
        cout << "1. View Inventory\n";
        cout << "2. Add Inventory Item\n";
        cout << "3. Update Inventory\n";
        cout << "4. Back to Main Menu\n";
        setColor(COLOR_ORANGE);
        cout << "=================================\n";
        setColor(COLOR_GRAY);
        cout << "Enter your choice: ";
        setColor(COLOR_PINK);
        cin >> choice;

        switch (choice) {
            case 1: viewInventory(); break;
            case 2: addInventoryItem(); break;
            case 3: updateInventory(); break;
            case 4: return;
            setColor(COLOR_PURPLE);
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
}


void viewInventory() {
	setColor(COLOR_WHITE);
    cout << "\nItem\t\tStock Quantity\t\tPrice\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < inventoryCount; i++) {
        cout << inventory[i].itemName << "\t\t" << inventory[i].stockQuantity
             << "\t\t" << inventory[i].price << "\n";
    }
}


void addInventoryItem() {
    if (inventoryCount >= MAX_INVENTORY) {
    	setColor(COLOR_PURPLE);
        cout << "Inventory is full. Cannot add more items.\n";
        return;
    }

    InventoryItem newItem;
    setColor(COLOR_GRAY);
    cout << "Enter Item Name: ";
    setColor(COLOR_PINK);
    cin.ignore();
    cin.getline(newItem.itemName, 50);

    
    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].itemName, newItem.itemName) == 0) {
        	setColor(COLOR_PURPLE);
            cout << "Item already exists in inventory.\n";
            return;
        }
    }
    setColor(COLOR_GRAY);
    cout << "Enter Stock Quantity: ";
    setColor(COLOR_PINK);
    cin >> newItem.stockQuantity;

    setColor(COLOR_GRAY);
    cout << "Enter Price: ";
    setColor(COLOR_PINK);
    cin >> newItem.price;

    inventory[inventoryCount++] = newItem;
    
    setColor(COLOR_PURPLE);
    cout << "Item added to inventory successfully!\n";
}


void updateInventory() {
    char itemName[50];
    setColor(COLOR_GRAY);
    cout << "Enter Item Name to update: ";
    setColor(COLOR_PINK);
    cin.ignore();
    cin.getline(itemName, 50);

    bool found = false;
    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].itemName, itemName) == 0) {
            found = true;
            setColor(COLOR_GRAY);
            cout << "Enter new Stock Quantity: ";
            setColor(COLOR_PINK);
            cin >> inventory[i].stockQuantity;
 
            setColor(COLOR_GRAY);
            cout << "Enter new Price: ";
            setColor(COLOR_PINK);
            cin >> inventory[i].price;

            setColor(COLOR_PURPLE);
            cout << "Inventory item updated successfully!\n";
            break;
        }
    }
    if (!found) {
    	setColor(COLOR_PURPLE);
        cout << "Item not found in inventory.\n";
    }
}

// ========================== Payment Processing ==========================


void paymentProcessing() {
    if (orderCount == 0) {
        setColor(COLOR_PURPLE);
        cout << "No orders to process payment.\n";
        return;
    }

    int orderId;
    setColor(COLOR_GRAY);
    cout << "Enter Order ID to process payment: ";
    setColor(COLOR_PINK);
    cin >> orderId;

    for (int i = 0; i < orderCount; i++) {
        if (orders[i].orderId == orderId) {
            if (!orders[i].isCompleted) {
                setColor(COLOR_CYAN);
                cout << "Processing payment for Order ID: " << orderId << endl;
                cout << "Total Amount: $" << orders[i].price << endl;
                setColor(COLOR_GREEN);
                cout << "Payment successful! Receipt generated.\n";
                orders[i].isCompleted = true;  
                totalSales += orders[i].price; 
                return;
            } else {
                setColor(COLOR_PURPLE);
                cout << "Order ID: " << orderId << " is already completed.\n";
                return;
            }
        }
    }

    setColor(COLOR_RED);
    cout << "Order ID not found.\n";
}

bool checkInventory(const char itemName[], int quantity) {
    for (int i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].itemName, itemName) == 0 && inventory[i].stockQuantity >= quantity) {
        	setColor(COLOR_YELLOW);
            return true;
        }
    }
    return false;
}

int main() {
    addSampleInventory(); 
    mainMenu();
    return 0;
}
