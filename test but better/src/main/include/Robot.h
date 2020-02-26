/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "rev/CANSparkMax.h"
#include <frc/Spark.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
};

// motor definitions 

  frc::Spark frontRight{1};
  frc::Spark backRight{3};
  frc::Spark frontLeft{0};
  frc::Spark backLeft{2};
  rev::CANSparkMax leftTestMotor{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax rightTestMotor{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder leftTestEncoder = leftTestMotor.GetEncoder();
  rev::CANEncoder rightTestEncoder = rightTestMotor.GetEncoder();

  
    double lEncoder;
    double rEncoder;
    double rightY;
    double leftY;
    double rSpeed = 0.9;
    double lSpeed = -0.9;
    bool trigger;
    bool shoot = false;
    bool leftFaster = false;
    int waiter = 0;
    

  
  
  
//joystick definition
  frc::Joystick testStick{0};
