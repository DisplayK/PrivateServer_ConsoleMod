#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ChargeableInteractionDefinition.h"
#include "DBDTunableRowHandle.h"
#include "Unhook.generated.h"

class UStatusEffect;
class USceneComponent;
class ADBDPlayer;
class ACamperPlayer;

UCLASS(EditInlineNew, meta=(BlueprintSpawnableComponent))
class UUnhook : public UChargeableInteractionDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Export)
	TArray<USceneComponent*> _snapPoints;

public:
	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _unhookLoudNoiseRange;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _enduranceEffectDuration;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _movementSpeedBonusDuration;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _enduranceEffectClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _movementSpeedBonusEffectClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UStatusEffect> _survivorRecentlyUnhookedEffectClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
	ADBDPlayer* _unhookingPlayer;

	UPROPERTY(EditDefaultsOnly)
	float _hookedCharacterSnapTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
	ACamperPlayer* _playerBeingUnhooked;

public:
	UUnhook();
};

FORCEINLINE uint32 GetTypeHash(const UUnhook) { return 0; }
