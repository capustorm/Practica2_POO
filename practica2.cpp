// Michael Arturo Contreras Gilpin - 23310174 - 2P

#include <iostream>
#include <string>

using namespace std;

// Se crea la clase Usuario
class User {
    protected:
    
    string name;
    string cellphone;
    string password;
    string new_password;
    int age;
    bool valid = false;

    public:

    User(string _name, string _cellphone, int _age, string _password) {
        this->name = _name;
        this->cellphone = _cellphone;
        this->age = _age;
        this->password = _password;
    } // Constructor de la clase

    void login(string username, string password) {
        if (username == this->name && password == this-> password)
        {
            cout << "\nLogging succesful." << endl;
            valid = true;

        } else if (username != this->name) {
            cout << "\nUsername doesn't match." << endl;
        } else if (password != this->password) {
            cout << "\nWrong password. Try again." << endl;
        } else {
            cout << "Login failed." << endl;
        }
    } // Función que permite "entrar" al programa (puesto a que son dos como tal)

    void logout() {
        valid = false;
    } // Funcion que permite "salir" del programa

    bool is_valid() const {
        return valid;
    } // Función que retorna la validación del log in

    string get_password() const {
        return password;
    } // Función destinada a comprobar que la contraseña ingresada, sea la misma del objeto

    void change_password(string password, string new_password) {
        password = this->password;
        new_password = this->new_password;

        new_password = password;
    } // Función que permite cambiar la contraseña
};

// Subclase de usuario, Cliente
class Client : public User {

    public:

    Client(string _name, string _cellphone, int _age, string _password) : 
    User(_name, _cellphone, _age, _password) {} // Constructor de subclase

    void buy() {
        string product;
        cout << "\nWhat do you want to buy?" << endl;
        cin >> product;
        cout << "\nWe'll send you suggestions of (" << product << ") to your phone " << this->cellphone << endl;
    } // Función que permite comprar un producto

    void complaint() {
        string complaint;
        cout << "\nDescribe your problem:" << endl;
        cin >> complaint;
        cin.ignore();
        getline(cin, complaint);
        cout << "\nYour complaint was sent correctly. We'll send you a message to " << this->cellphone << endl;
    } // Función destinada a quejas

    void Return() {
        bool i = true; // Booleano que mantiene el ciclo while
        string devolution, seller;
        float amount;
        char correct_info;

        while (i == true) {
            cout << "\nWhat product will you return?" << endl;
            cin >> devolution;
            cout << "How mutch it cost?" << endl;
            cin >> amount;
            cout << "Please, introduce the seller username:" << endl;
            cin >> seller;
            cout << "\nIs that information correct? Y/N" << endl;
            cin >> correct_info;
            if (correct_info == 'Y' || correct_info == 'y')
            {
                i = false;
            } else {
                i = true;
            }
        }

        cout << "We'll send you details of the devolution of (" << devolution << ", $" << amount;
        cout << "USD) of @" << seller << " at your " << this->cellphone << endl;
    }
}; // Función de devoluciones

// Subclase de usuario, Vendedor
class Seller : public User {
    public:

    Seller(string _name, string _cellphone, int _age, string _password) : 
    User(_name, _cellphone, _age, _password) {} // Constructor de subclase

    void sell() {
        string product, client;
        int quantity;
        char choice_sell;

        while (true)
        {
            cout << "\nYou'll sell: "; cin >> product;
            cout << "To username: @"; cin >> client;
            cout << "Quantity: "; cin >> quantity;
            cout << "Are you sure? Y/N: "; cin >> choice_sell;

            if (choice_sell == 'Y' || choice_sell == 'y') {
                break;
            } else {
                cout << "\nPut again the specifications." << endl;
            }
        }

        cout << "\nYou'll sell to @" << client << " a product (" << product << ", " << quantity << ")." << endl;
        cout << "Details sent to " << this->cellphone << endl;
    } // Función destinada a la venta a usuarios

    void new_inventory() {
        string product_name;
        int quantity;
        float cost;
        char choice_inventory;

        while (true) 
        {
            cout << "\nProduct name: "; cin >> product_name;
            cout << "Cost: "; cin >> cost;
            cout << "Quantity: "; cin >> quantity;
            cout << "Are you sure? Y/N: "; cin >> choice_inventory;  
     
            if (choice_inventory == 'Y' || choice_inventory == 'y') {
                break;
            } else {
                cout << "\nPut again the specifications." << endl;
            }
        }

        cout << "The product (" << product_name << ") whit a cost of $" << cost;
        cout << "USD has been added to the inventory " << quantity << " times. Details sent to " << this->cellphone << endl;
    } // Función para añadir productos al stock
};

int main() {

    // Primer objeto
    Client user_1 = Client("CharleSSS", "2123426786", 23, "cucuman0_");

    while (!user_1.is_valid()) {
        string username_c, password_c;
        cout << "Enter username (CharleSSS): "; cin >> username_c;
        cout << "Enter password (cucuman0_): "; cin >> password_c;
        user_1.login(username_c, password_c);
    } // Ciclo de validación de log in
    
    int choice_1;
    string prev_pass, new_pass;
    while (user_1.is_valid())
    {
        cout << "\nChoose one action: " << endl;
        cout << "1. I want to buy something." << endl;
        cout << "2. I want to make a complaint." << endl;
        cout << "3. I want to do a devolution." << endl;
        cout << "4. I want to change my password." << endl;
        cout << "5. Logout." << endl;
        cin >> choice_1;

        switch (choice_1) { // Switch que llama las funciones respectivas
            case 1:
                user_1.buy();
                break;
            case 2:
                user_1.complaint();
                break;
            case 3:
                user_1.Return();
                break;
            case 4:
                while(true)
                {
                    cout << "\nIntroduce your previous password (write 'out', to get out):";
                    cin >> prev_pass;
                    string current_password = user_1.get_password();

                    if (prev_pass == current_password) {
                        cout << "Introduce the new password: ";
                        cin >> new_pass;
                        user_1.change_password(prev_pass, new_pass);
                        cout << "\nYou changed your password succesfuly." << endl;
                        break;
                    } else if (prev_pass == "out") {
                        break;
                    } else {
                        cout << "\nThe password is incorrect, try again." << endl;
                    }
                }
                break;
            case 5:
                user_1.logout();
                user_1.is_valid();
                break;
            default:
                cout << "\nThe choice doesn't match with an option." << endl;
                break;
        }
    } // Ciclo que reproduce un menú de selección para el primer objeto

    // Segundo objeto
    Seller user_2 = Seller("CoconutDealer", "2125463565", 32, "coconut_yea");
    
    while (!user_2.is_valid()) {
        string username_c, password_c;
        cout << "\nEnter username (CoconutDealer): "; cin >> username_c;
        cout << "Enter password (coconut_yea): "; cin >> password_c;
        user_2.login(username_c, password_c);
    } // Ciclo de validación de log in

    int choice_2;
    string prev_pass2, new_pass2;
    while (user_2.is_valid())
    {
        cout << "\nChoose one action: " << endl;
        cout << "1. I want to sell something." << endl;
        cout << "2. I want to publish new inventory." << endl;
        cout << "3. I want to change my password." << endl;
        cout << "4. Logout." << endl;
        cin >> choice_2;

        switch (choice_2) { // Switch que llama las funciones respectivas
            case 1:
                user_2.sell();
                break;
            case 2:
                user_2.new_inventory();
                break;
            case 3:
                while(true)
                {
                    cout << "\nIntroduce your previous password (write 'out', to get out):";
                    cin >> prev_pass2;
                    string current_password = user_2.get_password();

                    if (prev_pass2 == current_password) {
                        cout << "Introduce the new password: ";
                        cin >> new_pass2;
                        user_2.change_password(prev_pass2, new_pass2);
                        cout << "\nYou changed your password succesfuly." << endl;
                        break;
                    } else if (prev_pass2 == "out") {
                        break;
                    } else {
                        cout << "\nThe password is incorrect, try again." << endl;
                    }
                }
                break;
            case 4:
                user_2.logout();
                user_2.is_valid();
                break;
            default:
                cout << "\nThe choice doesn't match with an option." << endl;
                break;
        }
    } // Ciclo que reproduce un menú de selección para el segundo objeto

    return 0;
}