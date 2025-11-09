#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESkillCheckCustomType.h"
#include "SkillCheckResponse.h"
#include "SkillCheckDefinition.h"
#include "SkillCheck.generated.h"

class ADBDPlayer;
class UChargeableInteractionDefinition;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API USkillCheck : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	ADBDPlayer* _owner;

	UPROPERTY(Transient, Export)
	UChargeableInteractionDefinition* _currentInteraction;

public:
	UFUNCTION(BlueprintCallable)
	bool ShouldShowWarning();

	UFUNCTION(Server, Reliable)
	void Server_OnSkillCheckSuccess(FSkillCheckResponse skillCheckResponse);

	UFUNCTION(Server, Reliable)
	void Server_OnSkillCheckFailure(FSkillCheckResponse skillCheckResponse);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_DeactivateSkillCheck();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_ActivateSkillCheck(UChargeableInteractionDefinition* interaction, ESkillCheckCustomType skillCheckCustomType, FSkillCheckDefinition definition);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SkillCheckResponse(FSkillCheckResponse skillCheckResponse);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void Multicast_OnTriggerSkillCheck(UChargeableInteractionDefinition* currentInteraction, ESkillCheckCustomType skillCheckCustomType, const FString& id, const FString& salt, const float warningSoundDelay);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void Multicast_OnTriggerCustomSkillCheck(UChargeableInteractionDefinition* currentInteraction, ESkillCheckCustomType skillCheckCustomType, const FString& id, const FString& salt, const FSkillCheckDefinition& definition);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void Multicast_OnTriggerContinuousCustomSkillCheck(UChargeableInteractionDefinition* currentInteraction, ESkillCheckCustomType skillCheckCustomType, const FSkillCheckDefinition& definition);

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void Multicast_DeactivateSkillCheck();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
	void Multicast_ActivateSkillCheck(UChargeableInteractionDefinition* interaction, ESkillCheckCustomType skillCheckCustomType, FSkillCheckDefinition definition);

	UFUNCTION(BlueprintCallable)
	void Local_OnSkillCheckSuccessTrigger(const bool bonus, const bool insane, ESkillCheckCustomType skillCheckCustomType, const bool failedCountedAsGood);

	UFUNCTION(BlueprintCallable)
	void Local_OnSkillCheckFailureTrigger(const bool hadInput, const bool insane, ESkillCheckCustomType skillCheckCustomType);

	UFUNCTION(BlueprintPure)
	bool IsOffCenterSkillCheck() const;

	UFUNCTION(BlueprintPure)
	bool IsHexSkillCheck(ADBDPlayer* dbdPlayer) const;

	UFUNCTION(BlueprintPure)
	bool IsDisplayed() const;

	UFUNCTION(BlueprintPure)
	static bool CanSkillCheckTypeGrantScore(ESkillCheckCustomType type);

	UFUNCTION()
	void Authority_OnSkillCheckTimeout();

public:
	USkillCheck();
};

FORCEINLINE uint32 GetTypeHash(const USkillCheck) { return 0; }
