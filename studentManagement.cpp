#include <iostream>
#include <fstream>

class temp {
    std::string rollNum, name, fName, address, search;
    std::fstream file;
    public:
    void addStu();
    void viewStu();
    void searchStu();
}obj;

int main() {
    char choice;
    std::cout <<"-------------------------";
    std::cout <<"1-Add Student Record" << std::endl;
    std::cout <<"2- View All Student Record" << std::endl;
    std::cout <<"3- Search Student Record" << std::endl;
    std::cout <<"4- Exit" << std::endl;
    std::cout <<"-----------------------------";
    std::cin >> choice;

    switch(choice) {
        case '1':
            obj.addStu();
        break;
        case '2':
            obj.viewStu();
        break;
        case '3':
            obj.searchStu();
        break;
        case '4':
            return 0;
        break;
        default:
            std::cout <<"Invalid";
    }
}

void temp :: addStu() {
    using namespace std;
    std::cout << "Enter Student Roll Number :: ";
    getline(cin,rollNum);
    std::cout << "Enter Student Name :: ";
    getline(cin,name);
    std::cout << "Enter Student Father Name :: ";
    getline(cin,fName);
    std::cout << "Enter Student Address :: ";
    getline(cin,address);

    file.open("stuData.txt", ios :: out | ios :: app);
    file << rollNum << "*";
    file << name << "*";
    file << fName << "*";
    file << address << endl;
    file.close();
}

void temp :: viewStu() {
    using namespace std;
    file.open("stuData.txt", ios:: in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');
    while(!file.eof()) {
        cout << "\n";
        cout << "Student Roll Number :: " << rollNum;
        cout << "Student Name :: " << name;
        cout << "Student Father Name :: " << fName;
        cout << "Student Address :: " << address << endl;
    }
    file.close();

    cout << "Enter Student Roll Number :: ";
    getline(cin, search);

    file.open("stuData.txt", ios::in);
    getline(file, rollNum, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');
    while(!file.eof()) {
        if (rollNum == search ){
            cout << "Student Roll Number :: " << rollNum;
            cout << "Student Name ::" << name;
            cout << "Student Father Name :: " << fName;
            cout << "Student Address :: " << address << endl;
        }
        getline(file, rollNum, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    file.close();
}

void temp::searchStu() {
    
}