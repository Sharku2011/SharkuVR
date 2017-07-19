#pragma once

/**
���� ���Ǵ� ����� ���� ���������� ��Ƶδ� ��� �����Դϴ�.
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
	/// bCanMotion�� �����־�� �۵�
	HS_GRAB			UMETA(DisplayName = "Grab"),
	HS_THUMBUP		UMETA(DisplayName = "ThumbUp"),
	HS_HANDGUN		UMETA(DisplayName = "HandGun"),
	HS_POINTING		UMETA(DisplayName = "Point"),
	HS_PRAY			UMETA(DisplayName = "Pray"),
	HS_FUCK			UMETA(DisplayName = "Fuck"),
	HS_SCISSOR		UMETA(DisplayName = "Scissors"),
	/// bCanMotion�� �������� �ʾƾ� �۵�
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
	// ������
	MT_STATIC		UMETA(DisplayName = "Static"),
	// �̵���
	MT_MOVABLE		UMETA(DisplayName = "Movavle"),
	// ü�� �����
	MT_REGEN		UMETA(DisplayName = "Regenerative"),
	// �þ� ������
	MT_DARK			UMETA(DisplayName = "Dark"),
	// ������
	MT_TRANS		UMETA(DisplayName = "Transparency"),
	// ������
	MT_CHARGE		UMETA(DisplayName = "Charge"),
	// �ִ� ����
	MT_MAX			UMETA(Hidden)
};

/**
* ����� �� ���� ��ŭ�� �������� �ִ��� ����
*/
UENUM(BlueprintType)
enum class EEnergyConsumeResult : uint8
{
	Success	UMETA(DisplayName = "Success"),
	Fail	UMETA(DisplayName = "Fail")
};

/**
* scalar ���� ��ġ�� ���ϰų� �� �� ��� ������� ���� ���� ������(0) �ܺ�����(1,2) ����
*/
UENUM(BlueprintType)
enum class ECheckFlowResult : uint8
{
	Pass		UMETA(DisplayName = "Pass"),
	Underflow	UMETA(DisplayName = "Underflow"),
	Overflow	UMETA(DisplayName = "Overflow")
};