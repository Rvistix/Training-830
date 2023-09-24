#pragma once
#include "Interfaces/SwerveDrive.h"
#include "Interfaces/SwerveModule.h"

#include <array>

struct SwerveConfig{
    bool idle_mode;
    bool ebrake;
    bool orientation;
    double maxDriveSpeed;
    double maxTurnSpeed;
    // Location of motors relative to the center of the robot
    frc::Translation2d frontLeftLocation;
    frc::Translation2d frontRightLocation;
    frc::Translation2d backLeftLocation;
    frc::Translation2d backRightLocation;
    //std::array<SwerveModule, 4>& modules;
};

class WPISwerveDrive : public SwerveDrive
{
    public:
        WPISwerveDrive() = default;
        virtual ~WPISwerveDrive() = default;
        virtual void Configure(SwerveConfig &config) override;
        virtual bool GetEbrake() override;
        virtual void SetEbrake(bool ebrake) override;
        virtual void Drive(double x_position, double y_position, double rotation);
        virtual void Drive(units::feet_per_second_t vx, units::feet_per_second_t vy, units::degrees_per_second_t omega) override;
        virtual void Drive(frc::ChassisSpeeds speed) override;
        virtual void Drive(std::vector<frc::SwerveModuleState> &state) override;
        virtual bool GetIdleMode() override;
        virtual void SetIdleMode(bool idle_mode) override;
        virtual void SetRobotOriented() override;
        virtual void SetFieldOriented() override;
        virtual bool GetOrientedMode() override; 

        inline std::array<SwerveModule*, 4>* GetModules()
        {
            return &m_modules;
        }

    private:
        frc::Translation2d m_frontLeftLocation;
        frc::Translation2d m_frontRightLocation;
        frc::Translation2d m_backLeftLocation;
        frc::Translation2d m_backRightLocation;

        frc::SwerveDriveKinematics<4>* m_kinematics;
        
        std::array<SwerveModule*, 4> m_modules;

        std::vector<frc::SwerveModuleState> m_states;
        
        double m_maxDriveSpeed;
        double m_maxTurnSpeed;
        bool m_ebrake = false;
        bool m_driveMotorIdleMode = false;
        // false is brake and true is coast
        bool m_orientation = false;
        // false is robot orientated, true is FieldOrientated. 
};