/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#include <frc/WPILib.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/Phoenix.h>

// Pnuematic Hatch Panel
#define EXTEND 1
#define RETRACT 0

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  double deadBand(double);

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  frc::DoubleSolenoid hatchPanel{0,1};
  frc::XboxController m_Xbox{0};
  WPI_TalonSRX frontLeft{1}; // Should be 1
  WPI_TalonSRX rearLeft{5};  // Should be 5
  WPI_TalonSRX frontRight{2}; 
  WPI_TalonSRX rearRight{4}; 
  TalonSRX ballMotor{6};
  TalonSRX hingeMotor{7};
  frc::MecanumDrive m_robotDrive{frontLeft, rearLeft, frontRight, rearRight};
};
