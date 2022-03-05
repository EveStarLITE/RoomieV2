
#pragma once

#include <wpi/math>
#include <units/length.h>
#include <units/angular_velocity.h>
#include <units/velocity.h>

namespace frc3512::Constants {
    constexpr double kCountsPerRevolution = 1440.0;
    constexpr double kWheelDiameterInch = 2.75;
    static constexpr units::meter_t kWheelDiameter = 70_mm;
    static constexpr units::meter_t kTrackWidth = 0.381_m * 2;
    static constexpr units::meters_per_second_t kMaxSpeed = 3.0_mps;  // 3 meters per second
    static constexpr units::radians_per_second_t kMaxAngularSpeed = units::radians_per_second_t{wpi::math::pi};  // 1/2 rotation per second
}
