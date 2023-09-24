#pragma once

#include <frc/AnalogEncoder.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/geometry/Translation2d.h>
// #include <AHRS.h>

#include "rev/CANSparkMax.h"

// ###########################################################
// #                  Front Left Module                      #
// ###########################################################
// --------------------Absolute Encoder-----------------------
const int FL_ABS_ENC_PORT = 1;
const bool FL_ABS_ENC_INVERTED = false;
const frc::Rotation2d FL_ZERO_HEADING{units::degree_t{41.7f}};

frc::AnalogEncoder fl_abs_enc{FL_ABS_ENC_PORT};

// -----------------------Turn Motor--------------------------
const int FL_TURN_MTR_ID = 2;
const bool FL_TURN_MTR_INVERTED = true;

rev::CANSparkMax fl_turn_mtr{FL_TURN_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder fl_turn_enc = fl_turn_mtr.GetEncoder();
rev::SparkMaxPIDController fl_turn_pid = fl_turn_mtr.GetPIDController();

// -----------------------Drive Motor-------------------------
const int FL_DRIVE_MTR_ID = 6;

rev::CANSparkMax fl_drive_mtr{FL_DRIVE_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder fl_drive_enc = fl_drive_mtr.GetEncoder();
rev::SparkMaxPIDController fl_drive_pid = fl_drive_mtr.GetPIDController();


// ###########################################################
// #                  Front Right Module                     #
// ###########################################################
// --------------------Absolute Encoder-----------------------
const int FR_ABS_ENC_PORT = 0;
const bool FR_ABS_ENC_INVERTED = false;
const frc::Rotation2d FR_ZERO_HEADING{units::degree_t{209.9f}};

frc::AnalogEncoder fr_abs_enc{FR_ABS_ENC_PORT};

// -----------------------Turn Motor--------------------------
const int FR_TURN_MTR_ID = 1;
const bool FR_TURN_MTR_INVERTED = true;

rev::CANSparkMax fr_turn_mtr{FR_TURN_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder fr_turn_enc = fr_turn_mtr.GetEncoder();
rev::SparkMaxPIDController fr_turn_pid = fr_turn_mtr.GetPIDController();

// -----------------------Drive Motor-------------------------
const int FR_DRIVE_MTR_ID = 5;

rev::CANSparkMax fr_drive_mtr{FR_DRIVE_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder fr_drive_enc = fr_drive_mtr.GetEncoder();
rev::SparkMaxPIDController fr_drive_pid = fr_drive_mtr.GetPIDController(); 


// ###########################################################
// #                  Back Left Module                       #
// ###########################################################
// --------------------Absolute Encoder-----------------------
const int BL_ABS_ENC_PORT = 2;
const bool BL_ABS_ENC_INVERTED = false;
const frc::Rotation2d BL_ZERO_HEADING{units::degree_t{301.1f}};

frc::AnalogEncoder bl_abs_enc{BL_ABS_ENC_PORT};


// -----------------------Turn Motor--------------------------
const int BL_TURN_MTR_ID = 4;
const bool BL_TURN_MTR_INVERTED = true;

rev::CANSparkMax bl_turn_mtr{BL_TURN_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder bl_turn_enc = bl_turn_mtr.GetEncoder();
rev::SparkMaxPIDController bl_turn_pid = bl_turn_mtr.GetPIDController();

// -----------------------Drive Motor-------------------------
const int BL_DRIVE_MTR_ID = 8;

rev::CANSparkMax bl_drive_mtr{BL_DRIVE_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder bl_drive_enc = bl_drive_mtr.GetEncoder();
rev::SparkMaxPIDController bl_drive_pid = bl_drive_mtr.GetPIDController();


// ###########################################################
// #                  Back Right Module                      #
// ###########################################################
// --------------------Absolute Encoder-----------------------
const int BR_ABS_ENC_PORT = 3;
const bool BR_ABS_ENC_INVERTED = false;
const frc::Rotation2d BR_ZERO_HEADING{units::degree_t{75.5f}};

frc::AnalogEncoder br_abs_enc{BR_ABS_ENC_PORT};

// -----------------------Turn Motor--------------------------
const int BR_TURN_MTR_ID = 3;
const bool BR_TURN_MTR_INVERTED = true;

rev::CANSparkMax br_turn_mtr{BR_TURN_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder br_turn_enc = br_turn_mtr.GetEncoder();
rev::SparkMaxPIDController br_turn_pid = br_turn_mtr.GetPIDController();

// -----------------------Drive Motor-------------------------
const int BR_DRIVE_MTR_ID = 7;

rev::CANSparkMax br_drive_mtr{BR_DRIVE_MTR_ID, rev::CANSparkMax::MotorType::kBrushless};
rev::SparkMaxRelativeEncoder br_drive_enc = br_drive_mtr.GetEncoder();
rev::SparkMaxPIDController br_drive_pid = br_drive_mtr.GetPIDController(); 


// ###########################################################
// #                     Swerve Drive                        #
// ###########################################################
const double ROBOT_WIDTH_M = 0.63;
const double ROBOT_LENGTH_M = 0.63;

const frc::Translation2d fl_position(units::meter_t{ROBOT_LENGTH_M / 2.0}, units::meter_t{ROBOT_WIDTH_M / 2.0});
const frc::Translation2d fr_position(units::meter_t{ROBOT_LENGTH_M / 2.0}, units::meter_t{-ROBOT_WIDTH_M / 2.0});
const frc::Translation2d bl_position(units::meter_t{-ROBOT_LENGTH_M / 2.0}, units::meter_t{ROBOT_WIDTH_M / 2.0});
const frc::Translation2d br_position(units::meter_t{-ROBOT_LENGTH_M / 2.0}, units::meter_t{-ROBOT_WIDTH_M / 2.0});

// ------------------------Turn Motor-------------------------
const double TURN_GEAR_RATIO = 10.2857;
const double MOTOR_ROT_TO_DEG = 360.0 / TURN_GEAR_RATIO;

const double TURN_P = 0.045;
const double TURN_I = 0.0;
const double TURN_D = 0.003;
const double TURN_FF = 0.0;

// ------------------------Drive Motor------------------------
const double DRIVE_GEAR_RATIO = 5.5;
const double WHEEL_DIAMETER_FT = 0.333; // 4 inches
const double MOTOR_ROT_TO_FT = (WHEEL_DIAMETER_FT * 3.14159) / DRIVE_GEAR_RATIO;

const double DRIVE_P = 0.08;
const double DRIVE_I = 0.0;
const double DRIVE_D = 0.1;
const double DRIVE_FF = 0.0;

// --------------------------Gyro-----------------------------
const bool GYRO_INVERTED = false;
const frc::Rotation2d GYRO_ZERO_HEADING{units::degree_t{0.0f}};

// AHRS robot_gyro{frc::SPI::Port::kMXP};

// --------------------------Swerve---------------------------
const double MAX_DRIVE_SPEED_MPS = 15.0;
const double MAX_ANGULAR_VELOCITY_DEGPS = 60.0;

const bool IS_DRIVE_IN_COAST = false;
const bool IS_ROBOT_ORIENTED_DRIVE = false;