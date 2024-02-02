// #include<iostream>
// #include<iomanip>
// using namespace std;
//
// class Flight
// {
// public:
//     short int FlightNumber;
//     string DeparturePoint; 
//     string DestinationPoint; 
//     string ArrivalTime; 
//     string DepartureTime; 
//     int RegistrationNumber; 
//
//     void setFlightInfo(short int number, string departurePoint, string destinationPoint,
//         string arrivalTime, string departureTime, int regNumber)
//     {
//         FlightNumber = number;
//         DeparturePoint = departurePoint;
//         DestinationPoint = destinationPoint;
//         ArrivalTime = arrivalTime;
//         DepartureTime = departureTime;
//         RegistrationNumber = regNumber;
//     }
//
//     void showFlightInfo()
//     {
//         cout << left << setw(15) << FlightNumber
//             << left << setw(20) << DeparturePoint
//             << left << setw(20) << DestinationPoint
//             << left << setw(15) << ArrivalTime
//             << left << setw(15) << DepartureTime
//             << left << setw(15) << RegistrationNumber << endl;
//     }
// };
//
// int main()
// {
//     int numberOfFlights;
//     
//     cout << "Enter the number of flights: ";
//     cin >> numberOfFlights;
//
//     Flight* flights = new Flight[numberOfFlights];
//
//     for (int i = 0; i < numberOfFlights; ++i)
//     {
//         cout << "Enter information for flight #" << i + 1 << endl;
//         cout << "Flight number: ";
//         cin >> flights[i].FlightNumber;
//         cout << "Departure point: ";
//         cin >> flights[i].DeparturePoint;
//         cout << "Destination point: ";
//         cin >> flights[i].DestinationPoint;
//         cout << "Arrival time: ";
//         cin >> flights[i].ArrivalTime;
//         cout << "Departure time: ";
//         cin >> flights[i].DepartureTime;
//         cout << "Registration number: ";
//         cin >> flights[i].RegistrationNumber;
//     }
//
//     for (int i = 0; i < numberOfFlights - 1; ++i)
//     {
//         for (int j = i + 1; j < numberOfFlights; ++j)
//         {
//             if (flights[i].DestinationPoint > flights[j].DestinationPoint)
//             {
//                 swap(flights[i], flights[j]);
//             }
//         }
//     }
//
//     cout << left << setw(15) << "Flight number "
//         << left << setw(20) << "Departure point "
//         << left << setw(20) << "Destination point "
//         << left << setw(15) << "Arrival time "
//         << left << setw(15) << "Departure time "
//         << left << setw(15) << "Registration number" << endl;
//
//     for (int i = 0; i < numberOfFlights; ++i)
//     {
//         flights[i].showFlightInfo();
//     }
//
//     delete[] flights;
//
//     return 0;
// }
