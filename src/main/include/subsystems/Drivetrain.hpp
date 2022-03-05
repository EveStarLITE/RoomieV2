
#pragma once

#include <vector>

#include <frc/CounterBase.h>
#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/SmallString.h>
#include <iostream>
#include <frc/BuiltInAccelerometer.h>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <Eigen/Core>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Translation2d.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/simulation/DifferentialDrivetrainSim.h>
#include <frc/simulation/EncoderSim.h>
#include <frc/smartdashboard/Field2d.h>
#include <frc/system/plant/LinearSystemId.h>
#include <frc/trajectory/TrajectoryConfig.h>
#include <frc/trajectory/TrapezoidProfile.h>
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/current.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>

#include "Constants.hpp"

class Drivetrain {
    public:
        Drivetrain();

        void Drive(units::meter_t setpoint);

        void Turn(units::radian_t trunDegree);

        units::meter_t GetAverageDistance();

        frc::Pose2d GetReferencePose() const;

        frc::Pose2d GetPose() const;

        void Reset();

    private:
        frc::Spark m_leftMotor{0};
        frc::Spark m_rightMotor{1};

        frc::Encoder m_leftEncoder{4, 5};
        frc::Encoder m_rightEncoder{6, 7};

        frc::DifferentialDrive m_drive{m_leftMotor, m_rightMotor};
        
        frc::BuiltInAccelerometer m_accelerometer;
};