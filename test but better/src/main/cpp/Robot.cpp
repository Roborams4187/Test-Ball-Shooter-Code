/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

void Robot::RobotInit() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

    rightY = testStick.GetRawAxis(1);
    leftY = testStick.GetRawAxis(5);
    
    /*frontRight.Set(-rightY);
    backRight.Set(-rightY);
    frontLeft.Set(leftY);
    backLeft.Set(leftY); */

    if(not shoot){
        trigger = testStick.GetRawButton(1);
    }
    
    if(trigger){
        shoot = true;
        trigger = false;
        leftTestMotor.Set(lSpeed);
        rightTestMotor.Set(rSpeed);
            //waiter++
            //if (waiter > 5000){
            //  
        lEncoder = leftTestEncoder.GetVelocity();
        rEncoder = rightTestEncoder.GetVelocity();

        leftFaster = lEncoder > rEncoder;
    }

    if(shoot){
        if(leftFaster){
            lSpeed = (rEncoder/lEncoder)*lSpeed;
        }else{
            rSpeed = (lEncoder/rEncoder)*rSpeed;
        }          
        leftTestMotor.Set(lSpeed);
        rightTestMotor.Set(rSpeed); 
        lEncoder = leftTestEncoder.GetVelocity();
        rEncoder = rightTestEncoder.GetVelocity();
    }

    if(testStick.GetRawButton(2)){
        shoot = false;
        leftTestMotor.Set(0.0);
        rightTestMotor.Set(0.0);
        leftFaster = false;
        lSpeed = -0.9;
        rSpeed = 0.9;

         }
   
   
       std::cout <<"L="<<lEncoder<<" R="<<rEncoder<<std::endl;
    
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
