
#include "subsystems/Drivetrain.hpp"
#include "controllers/ControllerBase.hpp"

Drivetrain::Drivetrain() {
    m_leftEncoder.SetDistancePerPulse(
      wpi::math::pi * frc3512::Constants::kWheelDiameter.to<double>() / frc3512::Constants::kCountsPerRevolution);
    m_rightEncoder.SetDistancePerPulse(
      wpi::math::pi * frc3512::Constants::kWheelDiameter.to<double>() / frc3512::Constants::kCountsPerRevolution);
}

void Drivetrain::Drive(units::meter_t setpoint) {
    while (GetAverageDistance() < setpoint) {
        m_drive.ArcadeDrive(1.0, 0.0, false);
    }
    m_drive.ArcadeDrive(0.0, 0.0, false);
}

void Drivetrain::Turn(units::radian_t turnDegree) {}

units::meter_t Drivetrain::GetAverageDistance() {
    return (units::meter_t{m_leftEncoder.GetDistance()} + units::meter_t{m_rightEncoder.GetDistance()}) / 2.0;
}

void Drivetrain::Reset() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}