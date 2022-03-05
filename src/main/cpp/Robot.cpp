
#include "Robot.h"

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/SmallString.h>
#include <iostream>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
    drivetrain.Reset();
  
}

void Robot::AutonomousInit() {
    m_autoSelected = m_chooser.GetSelected();
    drivetrain.Reset();

    std::cout << "Auto selected: " << m_autoSelected << std::endl;

    if (m_autoSelected == kAutoNameCustom) {
      
    } else {

    }
}

void Robot::AutonomousPeriodic() {
    
   if (m_autoSelected == kAutoNameCustom) {
    drivetrain.Drive(units::meter_t{100});
  } else {

  }
}



void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {
  drivetrain.Reset();
}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif