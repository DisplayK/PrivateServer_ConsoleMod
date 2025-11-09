#pragma once

#include "CoreMinimal.h"
#include "SkillCheckDefinition.generated.h"

USTRUCT(BlueprintType)
struct FSkillCheckDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient)
	float SuccessZoneStart;

	UPROPERTY(BlueprintReadWrite, Transient)
	float SuccessZoneEnd;

	UPROPERTY(BlueprintReadWrite, Transient)
	float BonusZoneLength;

	UPROPERTY(BlueprintReadWrite, Transient)
	float BonusZoneStart;

	UPROPERTY(BlueprintReadWrite, Transient)
	float ProgressRate;

	UPROPERTY(BlueprintReadWrite, Transient)
	float StartingTickerPosition;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsDeactivatedAfterResponse;

	UPROPERTY(BlueprintReadWrite, Transient)
	float WarningSoundDelay;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsAudioMuted;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsJittering;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsSuccessZoneMirrorred;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsInsane;

	UPROPERTY(BlueprintReadWrite, Transient)
	bool IsLocallyPredicted;

public:
	DEADBYDAYLIGHT_API FSkillCheckDefinition();
};

FORCEINLINE uint32 GetTypeHash(const FSkillCheckDefinition) { return 0; }
