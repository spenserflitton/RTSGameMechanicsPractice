#pragma once

enum class EUnitState : uint8
{
	EUS_Idle UMETA(DisplayName="Idle"),
	EUS_Move UMETA(DisplayName="Movement"),
	EUS_Mine UMETA(DisplayName="Mine"),
	EUS_Attack UMETA(DisplayName="Attack")
};
