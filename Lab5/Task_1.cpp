#include <iostream>
#include <stdexcept>
#include <climits> // For INT_MIN and INT_MAX

using namespace std;

class Int
{
private:
    int value;

public:
    Int(int value) : value(value)
    {
    }

    Int operator+(const Int& other) const
    {
        long long result = static_cast<long long>(value) + static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator-(const Int& other) const
    {
        long long result = static_cast<long long>(value) - static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator*(const Int& other) const
    {
        long long result = static_cast<long long>(value) * static_cast<long long>(other.value);
        if (result > INT_MAX || result < INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator/(const Int& other) const
    {
        if (other.value == 0)
        {
            throw invalid_argument("Division by zero");
        }
        return Int(value / other.value);
    }

    // Unary operators
    Int operator-() const
    {
        long long result = -static_cast<long long>(value);
        if (result > INT_MAX || result < INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        return Int(static_cast<int>(result));
    }

    Int operator++()
    {
        // Prefix ++
        if (value == INT_MAX)
        {
            throw overflow_error("Overflow occurred");
        }
        ++value;
        return *this;
    }

    Int operator++(int)
    {
        // Postfix ++
        Int temp = *this;
        if (value == INT_MAX)
        {
            throw overflow_error("Overflow occurred");
        }
        ++value;
        return temp;
    }

    Int operator--()
    {
        // Prefix --
        if (value == INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        --value;
        return *this;
    }

    Int operator--(int)
    {
        // Postfix --
        Int temp = *this;
        if (value == INT_MIN)
        {
            throw overflow_error("Overflow occurred");
        }
        --value;
        return temp;
    }


    friend ostream& operator<<(ostream& os, const Int& obj)
    {
        return os << obj.value;
    }
};

int runTask1()
{
    while (true)
    {
        int taskChoice;
        cout << "Choose a task:" << endl;
        cout << "1. Binary operators (+, -, *, /)" << endl;
        cout << "2. Unary operators (-, ++, --)" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> taskChoice;

        switch (taskChoice)
        {
        case 1:
            try
            {
                int choice;
                int x, y;

                cout << "Choose an operation:" << endl;
                cout << "1. +" << endl;
                cout << "2. -" << endl;
                cout << "3. *" << endl;
                cout << "4. /" << endl;
                cout << "0. Exit" << endl;
                cout << "Your choice: ";
                cin >> choice;

                if (choice == 0)
                {
                    cout << "Exiting program" << endl;
                    break;
                }

                cout << "Enter two integers: ";
                cin >> x >> y;

                Int a(x);
                Int b(y);
                Int result(0);

                switch (choice)
                {
                case 1: // +
                    result = a + b;
                    cout << "Sum: " << result << endl;
                    break;
                case 2: // - 
                    result = a - b;
                    cout << "Difference: " << result << endl;
                    break;
                case 3: // * 
                    result = a * b;
                    cout << "Product: " << result << endl;
                    break;
                case 4: // "/"
                    result = a / b;
                    cout << "Quotient: " << result << endl;
                    break;
                default:
                    cout << "Invalid operation choice" << endl;
                }
            }
            catch (const overflow_error& e)
            {
                cout << "Overflow error: " << e.what() << endl;
            }
            catch (const invalid_argument& e)
            {
                cout << "error: " << e.what() << endl;
            }
            break;
        case 2:
            try
            {
                int choice;
                int x;

                cout << "Choose an operation:" << endl;
                cout << "1. Unary -" << endl;
                cout << "2. Unary ++ (Prefix)" << endl;
                cout << "3. Unary -- (Prefix)" << endl;
                cout << "4. Unary ++ (Postfix)" << endl;
                cout << "5. Unary -- (Postfix)" << endl;
                cout << "0. Exit" << endl;
                cout << "Your choice: ";
                cin >> choice;

                if (choice == 0)
                {
                    cout << "Exiting program" << endl;
                    break;
                }

                cout << "Enter an integer: ";
                cin >> x;

                Int a(x);
                Int result(0);

                switch (choice)
                {
                case 1: // Unary -
                    result = -a;
                    cout << "Unary -: " << result << endl;
                    break;
                case 2: // Unary ++ (Prefix)
                    result = ++a;
                    cout << "Unary ++ (Prefix): " << result << endl;
                    break;
                case 3: // Unary -- (Prefix)
                    result = --a;
                    cout << "Unary -- (Prefix): " << result << endl;
                    break;
                case 4: // Unary ++ (Postfix)
                    result = a++;
                    cout << "Unary ++ (Postfix): " << result << endl;
                    break;
                case 5: // Unary -- (Postfix)
                    result = a--;
                    cout << "Unary -- (Postfix): " << result << endl;
                    break;
                default:
                    cout << "Invalid operation choice" << endl;
                }
            }
            catch (const overflow_error& e)
            {
                cout << "Overflow error: " << e.what() << endl;
            }
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid task choice" << endl;
        }

        break;
    }

    return 0;
}
