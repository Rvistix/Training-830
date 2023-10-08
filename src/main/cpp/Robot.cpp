// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

  namespace ModulePosition
  { 
    static const int FL = 0;
    static const int FR = 1;
    static const int BL  = 2;
    static const int BR  = 3; 
  };

void Robot::RobotInit() {
  // SwerveInit();
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */

void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() 
{
  
  AbsoluteEncoderConfig abs_config;

  abs_config.encoder = &fl_abs_enc;
  abs_config.is_inverted = FL_ABS_ENC_INVERTED;
  abs_config.zero_heading = FL_ZERO_HEADING;
  _abs_encoders[ModulePosition::FL].Configure(abs_config);

  abs_config.encoder = &fr_abs_enc;
  abs_config.is_inverted = FR_ABS_ENC_INVERTED;
  abs_config.zero_heading = FR_ZERO_HEADING;
  _abs_encoders[ModulePosition::FR].Configure(abs_config);

  abs_config.encoder = &bl_abs_enc;
  abs_config.is_inverted = BL_ABS_ENC_INVERTED;
  abs_config.zero_heading = BL_ZERO_HEADING;
  _abs_encoders[ModulePosition::BL].Configure(abs_config);

  abs_config.encoder = &br_abs_enc;
  abs_config.is_inverted = BR_ABS_ENC_INVERTED;
  abs_config.zero_heading = BR_ZERO_HEADING;
  _abs_encoders[ModulePosition::BR].Configure(abs_config);


  auto stuf = _abs_encoders[ModulePosition::FL].GetRawHeading().Degrees();

  std::cout << static_cast<double>(stuf);

  frc::SmartDashboard::PutNumber("Speed", 0.0);
  frc::SmartDashboard::PutNumber("ang", 0.0);
  
  

  // 
}

void Robot::TeleopPeriodic() 
{
  
  #include <iostream>


  std::cout << static_cast<double>(_abs_encoders[ModulePosition::FL].GetHeading().Degrees());

  // Task: Make a little game where you have to turn the wheel to a right position to score a point. 
  // Scenario: Console/SmartDashboard tell you to turn XX wheel XX way. 
  // Advanced people: add time limit, add menu screen with wheel turn as input, add noise suppression 
  // (cont.)make a calculator with the wheel(base four number system + four wheel as the operators. )
  // utilize gyro(all code are right there, read through it.),


  /*
  
  _____  ______  _____  ____  _    _ _____   _____ ______  _____ 
 |  __ \|  ____|/ ____|/ __ \| |  | |  __ \ / ____|  ____|/ ____|
 | |__) | |__  | (___ | |  | | |  | | |__) | |    | |__  | (___  
 |  _  /|  __|  \___ \| |  | | |  | |  _  /| |    |  __|  \___ \ 
 | | \ \| |____ ____) | |__| | |__| | | \ \| |____| |____ ____) |
 |_|  \_\______|_____/ \____/ \____/|_|  \_\\_____|______|_____/ 
                                                                 
                                                              


  */


  // How to initialize each wheel



  // //method of output s

  // //SmartDashboard (Prefered)
  // frc::SmartDashboard::PutNumber("TEST Number", 0.9);
  // frc::SmartDashboard::PutString("What to do next", "STRING HERE");

  // //std::cout (I mean, you could? )
  // #include <iostream>
  // //just remmeber to do the above thing when you do. 
  // std::cout << "You know how to do this. " << std::endl;

 /*
 
           _____  _____ _____ _______ _____ ____  _   _          _       
     /\   |  __ \|  __ \_   _|__   __|_   _/ __ \| \ | |   /\   | |      
    /  \  | |  | | |  | || |    | |    | || |  | |  \| |  /  \  | |      
   / /\ \ | |  | | |  | || |    | |    | || |  | | . ` | / /\ \ | |      
  / ____ \| |__| | |__| || |_   | |   _| || |__| | |\  |/ ____ \| |____  
 /_/___ \_\_____/|_____/_____|__|_|_ |_____\____/|_|_\_/_/__ _\_\______| 
 |_   _| \ | |  ____/ __ \|  __ \|  \/  |   /\|__   __|_   _/ __ \| \ | |
   | | |  \| | |__ | |  | | |__) | \  / |  /  \  | |    | || |  | |  \| |
   | | | . ` |  __|| |  | |  _  /| |\/| | / /\ \ | |    | || |  | | . ` |
  _| |_| |\  | |   | |__| | | \ \| |  | |/ ____ \| |   _| || |__| | |\  |
 |_____|_| \_|_|    \____/|_|  \_\_|  |_/_/    \_\_|  |_____\____/|_| \_|
                                                                         
                                                                        
 
 */
  //make sure all your code that you want to run repeatedly, like frames in a fps game that calcs your distance from enemy. 
  //are inside of THIS function. And that your init stuff are in teleopinit(the function before this one) and select teleop when you start the thing. 






}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
