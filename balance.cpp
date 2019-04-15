// Bijaya Shrestha
// Section:2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct PERSON{
    char Name[22];
    float Balance;
};

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records" << endl;
    cout << "2. Deposit funds" << endl;
    cout << "3. Find highest balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}

PERSON * readData(int & N){
	string fName;
	string lName;
	string fullName;


    ifstream data;
    data.open("data.txt");
    if(!data){
        cout << "Error, Data couldn't open" << endl;
        exit(0);
    }
    if(data){
        string line;
        while(getline(data, line)){
            N++;
        }
    }
    data.close();

    ifstream secData;
    secData.open("data.txt");
    PERSON * P;
    P = new PERSON[N];

    if(secData){
        for(int x = 0; x < N; x++){
            secData >> fName >> lName;
            secData>> P[x].Balance;

						fullName= fName.substr(0,8)+ "" + lName.substr(0,9);
            strcpy(P[x].Name, fullName.c_str());
        }
    }
    secData.close();
    return P;
}


void findRichest(PERSON *array, int N)
{
	int i;
	float richest = 0.0;
	for ( i = 0; i < N; i++)
	{
		if (richest < array[i].Balance)
			richest = array[i].Balance;

	}
	cout << "Highest balance: " << array[i].Name<< endl;
}

void newCopy(PERSON * arr, int N){
    ofstream file;
    file.open("data.txt");
    cout << "Updating..." << endl;
    cout << "Press any key" << endl;
    for (int x = 0; x < N; x++){
        file <<arr[x].Name << " " << arr[x].Balance << endl;
        cin >> ws;
    }
    cout << "File updated" << endl;
    file.close();
}

void Deposit(PERSON * arr, int & N, string custName, float amount){
    for(int x = 0; x < N; x++){
        if (arr[x].Name == custName){
            arr[x].Balance += amount;
            cout << "New Balance: " << arr[x].Balance << endl << endl;
            return;
        }
        else
            cout << " Record not found\n";
        }
    return ;
}

void display(PERSON * arr, int &N){
    for(int x = 0; x < N; x++){
        cout << arr[x].Name << " " << arr[x].Balance << endl;
    }
}

int main() {
    PERSON * personPtr = NULL;
    int size = 0;
    personPtr = readData(size);
    int choice;
    do{
        string customerName;
        float amount = 0;
        printmenu();
        cin >> choice;
        switch(choice){
            case 1:
                // Act on display
                cout << endl;
                display(personPtr, size);
								cout << endl;
                break;

            case 2:
                // Act on deposit

                cout << "Enter your full name";
                getline(cin, customerName);
                cout << customerName << "Deposite amount, Please ";
                cin >> amount;
                Deposit(personPtr, size, customerName, amount);
								cout << endl;
                break;

            case 3:
                // Act highest Balance

                findRichest(personPtr,size);
								cout << endl;
                break;

            case 4:
                // Act on update records

                newCopy(personPtr, size);
								cout << endl;
                break;
            case 5:
                //Calls update records before closing program
              newCopy(personPtr, size);
                break;
            default:
                //Invalid entry returns to the top of DO
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
    }
    while(choice != 5);
		// delete[] P;
		// P = NULL;
    return 0;
}
