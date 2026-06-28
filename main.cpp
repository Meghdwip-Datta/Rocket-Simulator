#include<iostream>
#include<math.h>
#include<thread>
#include<chrono>
using namespace std;


class rocket{
public:
    int time;
    double accelaration;
    double fuel;
    double altitude;
    double velocity;
    double payload;
    string vehicle;
    double target_height;

    void rocket_choice(int payload){
        if(payload<50){
            vehicle = "Falcon 9";
        }
        else if(payload>25 && payload<75){
            vehicle = "Falcon Heavy";
        }
        else{
            vehicle = "Starship";
        }
    }
    
    void launch(int time){
        if(fuel<=0){
            cout << endl << "Fuel Over" << endl << "CRAAAAAASH!!!!" << endl;
            
        }
        velocity += accelaration*time;
        altitude = 0.5*accelaration*pow(velocity,2);
        cout << endl << "Time: " << time << endl;
        cout << "Fuel Left: " << fuel << endl;
        cout << "Altitude: " << altitude << endl;
        cout << "Velocity: " << velocity << endl;
        fuel -= 10;

    }
};



int main(){
    int choice;
    rocket user1;
    cout << "Wellcome to Space Exploration Technologies Ltd." << endl ;
    cout << "Press 1 to start" << endl;
    cin >> choice;
    user1.fuel = 1000;
    
    cout << "Enter your payload in tonnes(25 to 100 tonnes): ";
    cin >> user1.payload;

    if(user1.payload>100){
        cout << "Payload is too high!!" << endl << "Mission terminated";
        return 0;
    }
    user1.rocket_choice(user1.payload);
    cout << "The vehicle of choice for you mission is: " << user1.vehicle;

    cout << endl;

    cout << "Enter your target altitude: ";
    cin >> user1.target_height;
    string line1;
    line1 = "Preparing your rocket for Launch!!!";
    int n = line1.size();

    for(int i = 0; i < n; i++)
    {
        cout << line1[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(70));
    }

    cout << endl;

    cout << "Starting Engine";

    for(int i = 0; i < 3; i++)
    {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << endl;

    string line2;
    line2 = "3..2..1..GO!";
    int n2 = line2.size();
    for(int i = 0; i < n2; i++)
    {
        cout << line2[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    user1.time=0;
    user1.accelaration = 2;
    user1.velocity=0;
    

    for(user1.time=0; user1.altitude<user1.target_height; user1.time+=10)
    {
        user1.launch(user1.time);
        cout << endl << flush;
        this_thread::sleep_for(chrono::milliseconds(1500));
    }
    
    cout << "CONGRATS!!!" << endl;
    cout << "Destination reached" << endl;
    return 0;
}