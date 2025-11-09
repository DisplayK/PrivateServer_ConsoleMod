#pragma once

#include "CoreMinimal.h"
#include "BlinkPowerSetupParams.h"
#include "EBlinkPowerState.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "TunableStat.h"
#include "EAttackType.h"
#include "BlinkPowerPlayerComponent.generated.h"

class UTimerObject;
class UCurveFloat;
class AActor;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class THENURSE_API UBlinkPowerPlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _maxBlinkCharges;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _rechargeDuration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _chainBlinkDuration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTagContainer _allowedInteractionSemancticsDuringChainBlink;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _fatigueDuration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _fatigueChainBlinkPenalty;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTunableStat _fatigueAttackPenalty;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameplayTag _fatigueAttackMissPenaltyModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* _fatigueSpeedCurve;

	UPROPERTY(BlueprintReadWrite, EditAnywhere,ReplicatedUsing=OnRep_BlinkState)
	EBlinkPowerState _powerState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BlinkCharges)
	int32 _blinkCharges;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
	bool _wasCurrentChargeSetByRecharge;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Export)
	UTimerObject* _chainBlinkTimer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Export)
	UTimerObject* _cooldownTimer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Export)
	UTimerObject* _rechargeTimer;

	UFUNCTION(BlueprintCallable)
	void Setup(const FBlinkPowerSetupParams& params);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_TriggerCooldown(float duration);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_TriggerChainBlink(int32 remainingBlinkCharges);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_SetState(EBlinkPowerState state);

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_InterruptDuringChainBlink(AActor* interruptedPlayer);

	UFUNCTION()
	void OnRep_BlinkState(EBlinkPowerState oldState);

	UFUNCTION()
	void OnRep_BlinkCharges();

	UFUNCTION()
	void OnLevelReadyToPlay();

	UFUNCTION()
	void OnAttackStarted(const EAttackType attackType);

	UFUNCTION()
	void OnAttackFinished(const EAttackType attackType);

	UFUNCTION(BlueprintPure)
	bool IsChargingBlink() const;

	UFUNCTION(BlueprintPure)
	bool IsChargeFull() const;

	UFUNCTION(BlueprintPure)
	bool IsBlinking() const;

	UFUNCTION(BlueprintPure)
	float GetRechargeProgressPercent() const;

	UFUNCTION(BlueprintPure)
	EBlinkPowerState GetPowerState() const;

	UFUNCTION(BlueprintPure)
	float GetCooldownTimerDuration() const;

	UFUNCTION(BlueprintPure)
	float GetCooldownRemainingTime() const;

	UFUNCTION(BlueprintPure)
	float GetCooldownProgressPercent() const;

	UFUNCTION(BlueprintPure)
	float GetChainBlinkTimerDuration() const;

	UFUNCTION(BlueprintPure)
	float GetChainBlinkRemainingTime() const;

	UFUNCTION(BlueprintPure)
	float GetChainBlinkProgressPercent() const;

	UFUNCTION(BlueprintPure)
	int32 GetBlinkCharges() const;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UBlinkPowerPlayerComponent();
};

FORCEINLINE uint32 GetTypeHash(const UBlinkPowerPlayerComponent) { return 0; }
