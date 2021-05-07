//
//  main.cpp
//  DMT-Einstein
//
//  Created by Jay Patel on 10/23/20.
//  Copyright © 2020 DarkMatter. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//~~~~~~~~~~~~~~~~~~SPEED~~~~~~~~~~~~~~~~



class Speed{
public:
    Speed(){}
    Speed(double& meters, double& seconds): meters(meters), seconds (seconds){speedCalc();}
    void speedCalc();
    void setMeters(const double& distance){ meters= distance;}
    void setSeconds(const double& time){ seconds= time;}
    double getMeters(){return meters;}
    double getSeconds(){return seconds;}
private:
    double meters, seconds;
    
};

void Speed::speedCalc(){
    cout<< "\tSpeed: "<< meters/seconds <<" m/s" <<endl;
}

//~~~~~~~~~~~~~~~~~~VELOCITY~~~~~~~~~~~~~~~~
class Velocity2D{
public:
    Velocity2D(){}
    Velocity2D(double& deltaDis, double& seconds): meters(deltaDis), seconds(seconds){velCalc();}
    void velCalc();
    void setMeters(const double& distance){ meters= distance;}
    void setSeconds(const double& time){ seconds= time;}
    void setVel(const double& vel){ velocity= vel;}
    double getMeters(){return meters;}
    double getSeconds(){return seconds;}
private:
    double meters, seconds, velocity;
    
};
void Velocity2D::velCalc(){
    velocity=meters/seconds;
    cout<< "\tVelocity: "<< meters/seconds<<" m/s" <<endl;
}

//~~~~~~~~~~~~~~~~~~ACCELERATION~~~~~~~~~~~~~~~~

class Acceleration{
public:
    Acceleration(){}
    Acceleration(double& deltaVel, double& seconds): velocity(deltaVel), seconds (seconds){accelCalc();}
    void accelCalc();
    void setVelocity(const double& velo){velocity=velo;}
    void setTime(const double& time){seconds=time;}
private:
    double velocity;
    double seconds;
    double accel;
};

void Acceleration::accelCalc(){
    accel=velocity/seconds;
    cout<<"\tAcceleration: "<<velocity/seconds<<" m/s^2" << endl;
    
}

//~~~~~~~~~~~~~~~~~~COMMANDER OF TOPIC~~~~~~~~~~~~~~~~
class Commander{
public:
    Commander(const int& action): command(action){topic(command);}
    double subtract( vector<double>& vec);
    void topic(int& command);
    
private:
    int command=0;
    Speed speedVal;
    Velocity2D velocityVal;
    Acceleration accelVal;
};
double Commander::subtract(vector<double>& vec){
    double total;
    total+=vec[vec.size()];
    for(int i = 0; i<vec.size()-1; i++){
        total-=vec[i-1];
    }
    
    return total;
}

void Commander::topic(int& action){
    double meters;
    double seconds;
    if (action==1){
//        double meters;
//        double seconds;
        cout<<"\t1)What is the distance in meters: ";
        cin>> meters;
        speedVal.setMeters(meters);
        cout<<"\t1)What is the time in seconds: ";
        cin>> seconds;
        speedVal.setSeconds(seconds);
        cout<<endl;
        Speed speedVal(meters,seconds);
        cout<<endl; 
    }
    if (action==2){
//        double meters;
//        double seconds;
        cout<<"\t2)What is the change in meters: ";
        cin>> meters;
        velocityVal.setMeters(meters);
        cout<<"\t2)What is the time in seconds: ";
        cin>> seconds;
        velocityVal.setSeconds(seconds);
        cout<<endl;
        Velocity2D velocityVal(meters,seconds);
        cout<<endl;
    }
  
    if (action==3){
        int repeat=1;
        vector<double> velStor;
        vector<double> timeStor;
        cout<<"\t\t How many velocity do you have?: ";
        cin>>repeat;
        for (int i = 0 ; i<repeat; i++){
            int tempV=0;
            cout<<"\t\tGive me velocity #"<<(i+1)<<": \n\t\t";
            cin>>tempV;
            velStor.push_back(tempV);
            cout<<velStor.size()<<"  This is vec size"<<endl;
        }
        for (int i = 0 ; i<repeat; i++){
            int tempT=0;
            cout<<"\t\tGive me time #"<<(i+1)<<": \n\t\t";
            cin>>tempT;
            velStor.push_back(tempT);
        }
        accelVal.setVelocity(subtract(velStor));
        accelVal.setTime(subtract(timeStor));
        accelVal.accelCalc();
//        for (int i = 0 ; i<repeat; i++){
//            cout<<"\t\tGive me velocity #"<<(i+1)<<": \n\t\t";
//            int tempV=0;
//            cin>>tempV;
//            velStor.push_back(tempV);
//            cout<<"\t\tGive me time #"<<(i+1)<<": \n\t\t";
//            int tempT=0;
//            cin>>tempT;
//            timeStor.push_back(tempT);
//            cout<<(tempT)<<"{{{{{{{{{{{{{{{";
//        }
    }
    
    
}


int main() {
    int order=0;
    cout<<"What would you like to do\n";
    cout<<"1) Calc Speed\n";
    cout<<"2) Velocity2D\n";
    cout<<"3) Acceleration\n";
    cin>>order;
    (Commander(order));
//    while (order!=0){
//        Speed speed1(2.0,1.5);
//        order=0;
//    }
    return 0;
}

//double Commander::subtract(vector<double>& info){
//    double res;
//    res=res+info[info.size()];
//    for (int i = 0; i<info.size()-2; i++){
//        res-=info[i];
//    }
//    return res;
//}
