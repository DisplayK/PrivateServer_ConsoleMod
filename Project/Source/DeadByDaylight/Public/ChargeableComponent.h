#pragma once

#include "CoreMinimal.h"
#include "ChargeableCompletionStateChangeDelegate.h"
#include "ChargeApplied.h"
#include "Components/ActorComponent.h"
#include "ChargeableEmptiedDelegate.h"
#include "DechargeBegin.h"
#include "ChargeableCompletionPercentChangeDelegate.h"
#include "ChargeableSkillCheckResponse.h"
#include "ChargeableCompletionPercentChangeCosmeticDelegate.h"
#include "DechargeEnd.h"
#include "SpeedBasedNetSyncedValue.h"
#include "DBDTimer.h"
#include "ChargeData.h"
#include "ChargeableComponent.generated.h"

class UChargeStrategy;
class AActor;

UCLASS(BlueprintType, EditInlineNew, meta=(BlueprintSpawnableComponent))
class DEADBYDAYLIGHT_API UChargeableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FChargeableEmptiedDelegate OnInteractionEmptiedEvent;

	UPROPERTY(BlueprintAssignable)
	FChargeableCompletionStateChangeDelegate OnInteractionCompletionStateChanged;

	UPROPERTY(BlueprintAssignable)
	FChargeableSkillCheckResponse SkillCheckResponseAestheticDelegate;

	UPROPERTY(BlueprintAssignable)
	FChargeableSkillCheckResponse SkillCheckResponseAuthorityDelegate;

	UPROPERTY(BlueprintAssignable, Transient)
	FChargeApplied ChargeAppliedAuthorityDelegate;

	UPROPERTY(BlueprintAssignable)
	FChargeableCompletionPercentChangeDelegate ChargeableCompletionPercentChangeAuthorityDelegate;

	UPROPERTY(BlueprintAssignable)
	FChargeableCompletionPercentChangeCosmeticDelegate ChargeableCompletionPercentChangeCosmeticDelegate;

	UPROPERTY(BlueprintAssignable)
	FDechargeBegin DechargeBeginDelegate;

	UPROPERTY(BlueprintAssignable)
	FDechargeEnd DechargeEndDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowSkillChecksAtFullCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChargeableComponentID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DechargeDelay;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentCharge)
	FSpeedBasedNetSyncedValue _currentCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDBDTimer _skillCheckFailurePenaltyTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDBDTimer _dechargeTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChargeData> _chargesThisFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FChargeData> _redirectedChargesThisFrame;

	UPROPERTY(Transient)
	TMap<uint32, UChargeStrategy*> _activeChargeStrategies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> _instigatorsSinceEmpty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, float> _tunableValueMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool _isCharging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> _playersWhoDidSkillCheck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float _startingChargePercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float _dechargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	bool _enableAddCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	bool _enableSkillCheckFailurePenalty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool _isDecharging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool _stopDechargingWhenComplete;

public:
	UFUNCTION(BlueprintCallable)
	void SetSecondsToCharge(float secondsToCharge);

	UFUNCTION(BlueprintCallable)
	void SetDechargeRate(float dechargeRate);

private:
	UFUNCTION()
	void OnRep_CurrentCharge();

	UFUNCTION()
	void OnCurrentChargeChanged(float value);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnEmptied() const;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnCompleteChanged(bool completed) const;

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsSkillCheckTimePenaltyActive() const;

	UFUNCTION(BlueprintPure)
	bool IsChargeComplete() const;

	UFUNCTION(BlueprintCallable)
	void IncreaseMaxChargeAdditive(float secondsToAdd);

	UFUNCTION(BlueprintCallable)
	void IncreaseMaxCharge(float percent);

	UFUNCTION(BlueprintPure)
	bool HasPlayerDoneSkillCheck(int32 playerID) const;

	UFUNCTION(BlueprintPure)
	float GetTunableValue(FName TunableValueID) const;

	UFUNCTION(BlueprintPure)
	float GetPlayerCountPenaltyModifier(int32 playerCount) const;

	UFUNCTION(BlueprintPure)
	float GetPercentComplete() const;

	UFUNCTION(BlueprintPure)
	float GetMaxCharge() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentCharge() const;

	UFUNCTION(BlueprintPure)
	float GetChargeRemaining() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_SetEnableSkillCheckFailurePenalty(const bool enable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_SetEnableAddCharge(const bool enable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_Reset();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_ApplyStartingCharge();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_AddChargePercent(float chargePercent, AActor* instigator, bool bypassSkillCheckFail, bool isOneTimeIncrease, bool isChargeWithItem);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_AddCharge(float chargeAmount, AActor* instigator, bool bypassSkillCheckFail, bool isOneTimeIncrease, bool isChargeWithItem);

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UChargeableComponent();
};

FORCEINLINE uint32 GetTypeHash(const UChargeableComponent) { return 0; }
