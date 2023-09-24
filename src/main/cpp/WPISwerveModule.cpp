#include "WPISwerveModule.h"

void WPISwerveModule::Configure(SwerveModuleConfig &config)
{
    m_driveMotor = config.driveMotor;
    m_turnMotor = config.turnMotor;
    SetIdleMode(config.idleMode);

};

void WPISwerveModule::SetState(frc::SwerveModuleState state)
{
    frc::SwerveModuleState::Optimize(state, m_turnMotor->GetRotation());
    m_turnMotor->SetRotation(state.angle);
    m_driveMotor->SetVelocity(state.speed);
};

frc::SwerveModuleState WPISwerveModule::GetState() 
{
    frc::Rotation2d angle = m_turnMotor->GetRotation();
    double speed = m_driveMotor->GetVelocity();
    //
    frc::SwerveModuleState state{units::meters_per_second_t(units::feet_per_second_t(speed)),angle};
    return state;
};

void WPISwerveModule::SetIdleMode(bool idleMode)
{
    m_idleMode = idleMode;
    m_driveMotor->SetIdleMode(idleMode);
};

bool WPISwerveModule::GetIdleMode()
{
    return m_driveMotor->GetIdleMode();
};
