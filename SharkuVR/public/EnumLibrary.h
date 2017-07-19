#pragma once

/**
자주 사용되는 사용자 지정 열거형들을 모아두는 헤더 파일입니다.
*
*/

UENUM(BlueprintType)
enum class EItemType : uint8
{
	IT_EQUIP		UMETA(DisplayName = "Equip"),
	IT_INSTRUMENT	UMETA(DisplayName = "Instrument"),
	IT_ENHANCER		UMETA(DisplayName = "Enhancer"),
	IT_MISC			UMETA(DisplayName = "Miscellaneous"),
	IT_MAX			UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EHandMotionState : uint8
{
	/// bCanMotion이 켜져있어야 작동
	HS_GRAB			UMETA(DisplayName = "Grab"),
	HS_THUMBUP		UMETA(DisplayName = "ThumbUp"),
	HS_HANDGUN		UMETA(DisplayName = "HandGun"),
	HS_POINTING		UMETA(DisplayName = "Point"),
	HS_PRAY			UMETA(DisplayName = "Pray"),
	HS_FUCK			UMETA(DisplayName = "Fuck"),
	HS_SCISSOR		UMETA(DisplayName = "Scissors"),
	/// bCanMotion이 켜져있지 않아야 작동
	HS_OPEN			UMETA(DisplayName = "Open"),
	HS_CANGRAB		UMETA(DisplayName = "CanGrab"),
	HS_HALFGRIP		UMETA(DisplayName = "HalfGrip"),
	HS_FULLGRIP		UMETA(DisplayName = "FullGrip"),
	HS_TILTGRIP		UMETA(DisplayName = "TiltGrip"),
	HS_MAX			UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EGrabType : uint8
{
	// Attach to hand mesh - No simulate physics.
	GT_ATTACH		UMETA(DisplayName = "Attach"),
	// Grab to Physic handle - Simulate physics.
	GT_HANDLE		UMETA(DisplayName = "Handle"),
	// Restrictive physics handle - for door or drawer.
	GT_DRAWER		UMETA(DisplayName = "Drawer"),
	// Count for max enum.
	GT_MAX			UMETA(Hidden)
};

UENUM(BlueprintType, meta = (Bitflags))
enum class EMissionType : uint8
{
	// 고정형
	MT_STATIC		UMETA(DisplayName = "Static"),
	// 이동형
	MT_MOVABLE		UMETA(DisplayName = "Movavle"),
	// 체력 재생형
	MT_REGEN		UMETA(DisplayName = "Regenerative"),
	// 시야 제한형
	MT_DARK			UMETA(DisplayName = "Dark"),
	// 투명형
	MT_TRANS		UMETA(DisplayName = "Transparency"),
	// 돌진형
	MT_CHARGE		UMETA(DisplayName = "Charge"),
	// 최대 갯수
	MT_MAX			UMETA(Hidden)
};

/**
* 사용할 수 있을 만큼의 에너지가 있는지 여부
*/
UENUM(BlueprintType)
enum class EEnergyConsumeResult : uint8
{
	Success	UMETA(DisplayName = "Success"),
	Fail	UMETA(DisplayName = "Fail")
};

/**
* scalar 값에 수치를 더하거나 빼 줄 경우 결과값이 정상 범위 내인지(0) 외부인지(1,2) 여부
*/
UENUM(BlueprintType)
enum class ECheckFlowResult : uint8
{
	Pass		UMETA(DisplayName = "Pass"),
	Underflow	UMETA(DisplayName = "Underflow"),
	Overflow	UMETA(DisplayName = "Overflow")
};