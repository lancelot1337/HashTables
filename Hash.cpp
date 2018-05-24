//------------------------\\
//ONLY REMOVE ITEM IS LEFT\\
//------------------------\\
//         \\/\//         \\

#include <iostream>
#include <string>

using namespace std;

class Hash{

private:
    static const int tableSize = 50;
    struct item{
        string name;
        string drink;
        item* next;
    };
    item* HashTable[tableSize];

public:
    Hash();
    int retHash(string Key);
    void addItem(string name, string drink);
    int numberOfItems(int index);
    void printTable();
    void printItemsInIndex(int index);
    void findDrink(string name);
};

Hash::Hash(){
    //tableSize = 100;
    cout << "Constructing the object" << endl;

    for(int i = 0; i < tableSize; ++i){
        HashTable[i] = new item();
        HashTable[i] -> name = "NULL";
        HashTable[i] -> drink = "NULL";
        HashTable[i] -> next = NULL;
    }
}

int Hash::retHash(string Key){
    int Hash = 0;

    for(int i = 0; i < Key.length(); ++i){
//        Hash = Hash + (int)Key[i];
        Hash = (Hash + (int)Key[i]) * 17;
//        cout << "Hash: " << Hash << endl;
    }
    int index = Hash % tableSize;
    return index;
}

void Hash::addItem(string name, string drink){
    int index = retHash(name);
    if(HashTable[index] -> name == "NULL"){
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }
    else{
        item* Ptr = HashTable[index];
        item* i = new item();
        i -> name = name;
        i -> drink = drink;
        i -> next = NULL;
        while(Ptr -> next != NULL){
            Ptr = Ptr -> next;
        }
        Ptr -> next = i;
    }
}

int Hash::numberOfItems(int index){
    int Ctr = 0;
    if(HashTable[index] -> name == "NULL");
    else{
        ++Ctr;
        item* Ptr = HashTable[index];
        while(Ptr -> next != NULL){
            Ptr = Ptr -> next;
            ++Ctr;
        }
    }
    return Ctr;
}

void Hash::printTable(){
    int num;
    for(int i = 0; i < tableSize; ++i){
        num = numberOfItems(i);
        cout << "---------------" << endl;
        cout << "At index: " << i << endl;
        cout << "Name: " << HashTable[i] -> name << endl;
        cout << "Drink: " << HashTable[i] -> drink << endl;
        cout << "Number of items in index " << i << " are " << num << endl;
        cout << "---------------" << endl;
    }
}

void Hash::printItemsInIndex(int index){
    if(HashTable[index] -> name == "NULL"){
        cout << "No data at index " << index << " in the HastTable!!" << endl;
        return;
    }
    else{
        item* Ptr = HashTable[index];
        while(Ptr != NULL){
            cout << "---------------" << endl;
            cout << "At index: " << index << endl;
            cout << "Name: " << HashTable[index] -> name << endl;
            cout << "Drink: " << HashTable[index] -> drink << endl;
            cout << "---------------" << endl;
        	Ptr = Ptr -> next;
        }
    }
}

void Hash::findDrink(string name){
    int index = retHash(name);
    string Drink;
    bool found = false;
    item* Ptr = HashTable[index];
    while(Ptr != NULL){
        if(Ptr -> name == name){
            found = true;
            Drink = Ptr -> drink;
            break;
        }
        Ptr = Ptr -> next;
    }
    if(found == true){
        cout << "Drink is found! \n";
    }
    else{
        cout << "Drink is not found! \n";
    }
    if(found == true){
        cout << "Drink of " << name << " is: " << Drink << endl;
    }
}

int main(){
    Hash hashObj;
    hashObj.addItem("Metallica","Mocha");
	hashObj.addItem("Metallica","Mocha");
	hashObj.addItem("Pantera","Latte");
	hashObj.addItem("Megadeth","Dopio Latte");
	hashObj.addItem("A7X","Coke");
	hashObj.addItem("Gojira","Pepsi");
	hashObj.addItem("Slipknot","Tea");
	hashObj.addItem("SOAD","Apple Juice");
	hashObj.addItem("DT","Orange Guice");
	hashObj.addItem("Earth, Wind and Fire","Wine");
	hashObj.addItem("Kool and the Gang","Beer");
	hashObj.addItem("Billie Eilish","Whisky");
    hashObj.printTable();
    cout << "\n\n\n" << "Items at given locations are: \n";
    hashObj.printItemsInIndex(0);
    hashObj.printItemsInIndex(1);
    hashObj.printItemsInIndex(2);
    hashObj.printItemsInIndex(3);
    hashObj.printItemsInIndex(4);
    hashObj.printItemsInIndex(5);
    hashObj.printItemsInIndex(6);
    hashObj.printItemsInIndex(7);
    hashObj.printItemsInIndex(8);
    hashObj.printItemsInIndex(9);
    cout << "-----SEARCH!-----\n";
    string NAME = "";
    while(NAME != "EXIT"){
        cout << "Enter the name to be searched: ";
        cin >> NAME;
        hashObj.findDrink(NAME);
    }
    return 0;
}
