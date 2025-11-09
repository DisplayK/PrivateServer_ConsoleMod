#pragma once

#include "CoreMinimal.h"
#include "ObjectStateProvider.h"
#include "SecondaryActionInputDelegate.h"
#include "EffectCameraTypeSettings.h"
#include "DamageTargetDelegate.h"
#include "PerkOwnerInterface.h"
#include "ScoreEventData.h"
#include "OnAttackedEvent.h"
#include "DynamicGrassEffectorInterface.h"
#include "OnRunningAndMovingChanged.h"
#include "Perception/AISightTargetInterface.h"
#include "PerkManagerOwnerInterface.h"
#include "DBDBasePlayer.h"
#include "AnimTagProvider.h"
#include "OnForwardInputLockedChanged.h"
#include "AnimNotifyDelegate_Pickup.h"
#include "GenericTeamAgentInterface.h"
#include "PushableInterface.h"
#include "Components/SkinnedMeshComponent.h"
#include "OnLocallyObservedChangedForPlayer.h"
#include "UObject/NoExportTypes.h"
#include "EStunType.h"
#include "OnSensedDelegate.h"
#include "OnFirstPersonModeChanged.h"
#include "AnimNotifyDelegate_Release.h"
#include "OnDreamworldComponentSet.h"
#include "Templates/SubclassOf.h"
#include "EAttackSubstate.h"
#include "ECamperState.h"
#include "MontagePlaybackDefinition.h"
#include "GameplayTagContainer.h"
#include "EDetectionZone.h"
#include "OnMovementCacheStruct.h"
#include "EInputInteractionType.h"
#include "EDBDScoreTypes.h"
#include "EAnimNotifyType.h"
#include "EquippedPlayerCustomization.h"
#include "AnimationMontageDescriptor.h"
#include "EPlayerTeam.h"
#include "Engine/EngineTypes.h"
#include "EPlayerRole.h"
#include "EInteractionAnimation.h"
#include "EPawnType.h"
#include "InteractionPlayerProperties.h"
#include "DBDPlayer.generated.h"

class USpringArmComponent;
class UAIPerceptionStimuliSourceComponent;
class UMontagePlayer;
class UPlayerPerspectiveComponent;
class UCameraHandlerComponent;
class UStateMachine;
class UActivatorComponent;
class ADBDPlayer;
class USceneComponent;
class UStatusEffect;
class UOtherCharactersVerticalCollisionsHandler;
class UCurveFloat;
class UPlayerGameRelevancyComponent;
class UMaterialHelper;
class UInteractionDefinition;
class UCharacterChaseVisualComponent;
class UCameraComponent;
class UAudioFXComponent;
class UZoneDetectorComponent;
class UReversibleActionSystemComponent;
class APlayerInteractable;
class UCharacterDreamworldComponent;
class UPrimitiveComponent;
class UCharacterInventoryComponent;
class UBoxOcclusionQueryComponent;
class UBoxComponent;
class USoundCue;
class ADBDPlayerController;
class UDBDPlayerData;
class UCharacterSightableComponent;
class UPerkManager;
class UPlayerInteractionHandler;
class UCharacterSightComponent;
class UChargeableComponent;
class AActor;
class UChaseComponent;
class UGameplayTagContainerComponent;
class UBlindableComponent;
class ADBDPlayerCameraManager;
class UPollableEventListener;
class UInteractionDetectorComponent;
class UDynamicCapsuleResizerComponent;
class UAuthoritativeMovementComponent;
class UPrimitivesRegistererComponent;
class UClippableProviderComponent;
class UContextualQuestComponent;
class AController;
class UActorComponent;
class UChargeableProgressProviderComponent;
class ADBDPlayerState;
class UAnimInstance;
class ACollectable;
class UItemModifier;
class UAnimMontage;
class APawn;
class UItemAddon;
class AInteractable;
class APlayerState;
class UGameplayModifierContainer;
class UInteractor;

UCLASS(Abstract)
class DEADBYDAYLIGHT_API ADBDPlayer : public ADBDBasePlayer, public IPerkOwnerInterface, public IPerkManagerOwnerInterface, public IAnimTagProvider, public IObjectStateProvider, public IGenericTeamAgentInterface, public IAISightTargetInterface, public IPushableInterface, public IDynamicGrassEffectorInterface
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIsCrouchedChanged, bool, isCrouched);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowInterrupting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinFallHeight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsInterruptable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool AllowNavigationInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool AllowNavigationBackwardInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowTurningInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool AllowPitchInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool AllowStrafeInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsInInteractionUpdate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsInteractionChargeCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PitchLimitLower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PitchLimitUpper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector StrafingOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PelvisHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PelvisHeightForPounceOnStandingCamper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PelvisHeightForPounceOnCrouchingCamper;

	UPROPERTY(BlueprintAssignable)
	FOnAttackedEvent Authority_OnAttackedDelegate;

	UPROPERTY(BlueprintAssignable)
	FDamageTargetDelegate OnDamageTargetDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnSensedDelegate OnSensed;

	UPROPERTY(BlueprintAssignable)
	FAnimNotifyDelegate_Pickup OnAnimNotify_Pickup;

	UPROPERTY(BlueprintAssignable)
	FAnimNotifyDelegate_Release OnAnimNotify_Release;

	UPROPERTY(BlueprintAssignable)
	FSecondaryActionInputDelegate Authority_OnSecondaryActionInput;

	UPROPERTY(BlueprintAssignable)
	FOnFirstPersonModeChanged OnFirstPersonModeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDreamworldComponentSet OnDreamworldComponentSet;

	UPROPERTY()
	FOnForwardInputLockedChanged OnForwardInputLockedChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ForceSkillChecks;

	UPROPERTY(BlueprintReadWrite, Transient)
	FTransform IKLeftHandTransform;

	UPROPERTY(BlueprintReadWrite, Transient)
	FTransform IKRightHandTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CameraResetSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AverageSpeedBufferTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AlmostCurrentSpeedBufferTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* GamepadYawCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* GamepadPitchCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* GamepadSettingToYawRateCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* GamepadSettingToPitchRateCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* JoyconSettingToYawRateCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCurveFloat* JoyconSettingToPitchRateCurve;

	UPROPERTY(BlueprintAssignable)
	FOnIsCrouchedChanged OnIsCrouchedChanged;

	UPROPERTY(BlueprintAssignable)
	FOnRunningAndMovingChanged OnRunningAndMovingChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLocallyObservedChangedForPlayer OnLocallyObservedChangedForPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export)
	UMaterialHelper* MaterialHelper;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APlayerInteractable> Interactable;

protected:
	UPROPERTY(Transient, meta=(BindWidgetOptional))
	UCharacterInventoryComponent* _characterInventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CarryJointName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float _pitchOffsetForInteractionPriority;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UBoxOcclusionQueryComponent* _renderedPixelCounter;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UBoxComponent* _standingOcclusionBox;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UBoxComponent* _crouchingOcclusionBox;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UActivatorComponent* _activator;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsInteracting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _aiCanBeSeenTestCrouchScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _aiCanBeSeenTestRightOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _aiCanBeSeenTestHighOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float _aiCanBeSeenTestLowOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ClearPathTestRadiusMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ClearPathTestHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float LocationClearTestRadiusMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float LocationClearTestHeightMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ClearPathTestStepHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseTurnSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseLookUpSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly)
	USoundCue* DeathSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECamperState CurrentCamperState;

	UPROPERTY(EditDefaultsOnly)
	FName CollectableAttachPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UStateMachine* _stateMachine;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UPlayerInteractionHandler* _interactionHandler;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UMontagePlayer* _montagePlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UPerkManager* _perkManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UDBDPlayerData* _playerData;

	UPROPERTY(ReplicatedUsing=OnRep_Interactable, Transient)
	APlayerInteractable* _interactable;

	UPROPERTY(Transient)
	ADBDPlayer* _guidingPlayer;

	UPROPERTY(Transient)
	ADBDPlayer* _interactingPlayer;

	UPROPERTY(Transient)
	EAttackSubstate _nextAttackSubstate;

	UPROPERTY(Transient)
	TArray<ADBDPlayer*> _hitTargets;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_DreamworldComponent, meta=(BindWidgetOptional))
	UCharacterDreamworldComponent* _dreamworldComponent;

	UPROPERTY(EditAnywhere, Transient, meta=(BindWidgetOptional))
	UCharacterChaseVisualComponent* _characterChaseVisualComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, meta=(BindWidgetOptional))
	UCameraHandlerComponent* _cameraHandlerComponent;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UReversibleActionSystemComponent* _reversibleActionSystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(BindWidgetOptional))
	USceneComponent* _itemDropOffPosition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(BindWidgetOptional))
	UAIPerceptionStimuliSourceComponent* _perceptionStimuliComponent;

	UPROPERTY(Transient)
	TArray<AActor*> _ignoreActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<FEffectCameraTypeSettings> EffectCameraTypeSettings;

	UPROPERTY(Transient)
	TMap<USceneComponent*, bool> _detectionZoneEnabledMap;

	UPROPERTY(meta=(BindWidgetOptional))
	UChargeableComponent* _blindingChargeableComponent;

	UPROPERTY(EditDefaultsOnly)
	bool _shouldUpdateStateMachineDriverOnPossessed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(BindWidgetOptional))
	UBlindableComponent* _blindableComponent;

private:
	UPROPERTY(Transient)
	float _tutorialChargeableInteractionMultiplier;

	UPROPERTY(Transient, Export)
	UPollableEventListener* _eventListener;

	UPROPERTY(VisibleAnywhere, Export)
	UChaseComponent* _chaseComponent;

	UPROPERTY(Transient, Export)
	UZoneDetectorComponent* _meatHookZoneDetector;

	UPROPERTY(Transient, Export)
	UZoneDetectorComponent* _basementZoneDetector;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _animGameplayTags;

	UPROPERTY(Transient, Export)
	UInteractionDefinition* _bookmarkedInteraction;

	UPROPERTY(Transient, Export)
	TMap<EDetectionZone, UPrimitiveComponent*> _detectionZoneMap;

	UPROPERTY(Transient, Export)
	UAuthoritativeMovementComponent* _authoritativeMovementComponent;

	UPROPERTY(Replicated)
	float _screenAspectRatio;

	UPROPERTY(Export)
	UGameplayTagContainerComponent* _objectState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, meta=(AllowPrivateAccess=true))
	UAudioFXComponent* _audioFXComponent;

	UPROPERTY(Export)
	UPlayerPerspectiveComponent* _playerPerspectiveComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, meta=(AllowPrivateAccess=true))
	UCharacterSightComponent* _characterSightComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, meta=(AllowPrivateAccess=true))
	UCharacterSightableComponent* _characterSightableComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, meta=(AllowPrivateAccess=true))
	UInteractionDetectorComponent* _interactionDetectorComponent;

	UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
	UPrimitivesRegistererComponent* _clippablePrimitivesRegistererComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, meta=(AllowPrivateAccess=true))
	UClippableProviderComponent* _clippableProviderComponent;

	UPROPERTY(VisibleAnywhere, Export)
	UDynamicCapsuleResizerComponent* _dynCapsuleResizer;

	UPROPERTY(Export)
	UPlayerGameRelevancyComponent* _playerGameRelevancyComponent;

	UPROPERTY(Transient, Export)
	UContextualQuestComponent* _contextualQuestComponent;

	UPROPERTY(Export)
	UActorComponent* _questEventHandler;

	UPROPERTY(Transient, Export)
	UChargeableProgressProviderComponent* _presentationChargeableProgressComponent;

	UPROPERTY(Transient)
	UCurveFloat* _currentGamepadYawCurve;

	UPROPERTY(Transient)
	UCurveFloat* _currentGamepadPitchCurve;

	UPROPERTY(Transient)
	ADBDPlayerState* _associatedPlayerStateCache;

	UPROPERTY(Transient)
	FOnMovementCacheStruct _onMovementCacheStruct;

	UPROPERTY(Transient, Export)
	UOtherCharactersVerticalCollisionsHandler* _otherCharactersVerticalCollisionsHandler;

public:
	UFUNCTION()
	void UpdateLoadoutFromInventory();

	UFUNCTION(BlueprintCallable)
	bool TryInteractionType(EInputInteractionType interactionInputType, ADBDPlayer* requester, bool usingInputPersistence, bool force);

	UFUNCTION(BlueprintCallable)
	bool TryInteraction(UInteractionDefinition* interaction, ADBDPlayer* requester, bool force, bool usingInputPersistence);

	UFUNCTION(BlueprintCallable)
	bool TryFireScoreEvent(EDBDScoreTypes scoreType, float percentToAward);

	UFUNCTION(BlueprintCallable)
	void TriggerAnimNotify(EAnimNotifyType animNotifyType);

	UFUNCTION(BlueprintCallable)
	void StopMontage();

	UFUNCTION(BlueprintCallable)
	void SnapCharacter(bool snapPosition, FVector position, float stopSnapDistance, bool snapRotation, FRotator rotation, float time, bool useZCoord, bool sweepOnFinalSnap, bool snapRoll);

	UFUNCTION(BlueprintPure)
	bool ShouldPlayCarryAnim() const;

	UFUNCTION(BlueprintPure)
	bool ShouldFall() const;

	UFUNCTION(BlueprintCallable)
	void SetShouldPlayCarryAnim(bool shouldPlayCarryAnim);

	UFUNCTION(BlueprintCallable)
	void SetReverseMontage(bool reverse);

	UFUNCTION(BlueprintCallable)
	void SetQuestEventHandlerComponent(UActorComponent* component);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetItemUseAsToggle(bool value);

protected:
	UFUNCTION(BlueprintCallable)
	void SetIsCloaked(bool isCloaked, bool forced);

public:
	UFUNCTION(BlueprintCallable)
	void SetForceDisableSkillChecks(bool isEnabled);

	UFUNCTION(BlueprintCallable)
	void SetFirstPersonVfxsVisibility(bool isFirstPerson);

	UFUNCTION(BlueprintCallable)
	void SetFirstPersonModelEnabled(bool enabled, bool force);

	UFUNCTION(BlueprintCallable)
	void SetFeetOnGround(bool feetOnGround);

	UFUNCTION(BlueprintCallable)
	void SetDetectionZoneEnabled(EDetectionZone detectionZoneID, bool enabled);

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetAnimationCrouchState(bool crouched);

public:
	UFUNCTION(BlueprintCallable)
	void SetAllowNavigation(bool enable);

	UFUNCTION(BlueprintCallable)
	void SetAllDetectionZonesEnabled(bool enabled);

private:
	UFUNCTION(Server, Reliable)
	void Server_UpdateScreenAspectRatio(const float value);

	UFUNCTION(Server, Reliable)
	void Server_SendSecondaryActionPressed(bool fromCancelRequest);

protected:
	UFUNCTION(Server, Reliable)
	void Server_SendItemUseInput(bool pressed, bool requestItemUse);

	UFUNCTION(Server, Reliable)
	void Server_SendItemDropInput(bool pressed);

public:
	UFUNCTION(Server, Reliable)
	void Server_SendInteractionInput(bool pressed);

	UFUNCTION(Server, Reliable)
	void Server_SendFastInteractionInput(bool pressed);

	UFUNCTION(Server, Reliable)
	void Server_SendAbilityTwoInput(bool pressed);

	UFUNCTION(Server, Reliable)
	void Server_SendAbilityInput(bool pressed);

	UFUNCTION(Server, Reliable)
	void Server_PlayerReady();

protected:
	UFUNCTION(Server, Reliable)
	void Server_GameTimeSync();

public:
	UFUNCTION(Server, Reliable)
	void Server_Drop(ACollectable* item, const FVector& location, const FRotator& rotation, bool onDeath);

	UFUNCTION(BlueprintCallable)
	void Server_SetCustomization(TArray<FName> customizationParts, TArray<FCharmIdSlot> customizationCharms);

protected:
	UFUNCTION(Server, Reliable)
	void Server_Broadcast_DebugPlayMontage(FAnimationMontageDescriptor animMontageID, float playRate);

public:
	UFUNCTION(BlueprintCallable)
	void ResetPitchScale(float adjustTime);

	UFUNCTION(BlueprintCallable)
	void ResetCamera();

	UFUNCTION(BlueprintCallable)
	void RemoveStatusEffect(UStatusEffect* statusEffect);

	UFUNCTION(BlueprintCallable)
	UAnimMontage* PlayMontage(FAnimationMontageDescriptor animMontageID, float playRate, bool isFollower);

protected:
	UFUNCTION()
	void OnRep_Interactable();

	UFUNCTION()
	void OnRep_DreamworldComponent();

private:
	UFUNCTION()
	void OnPostProcessInput();

public:
	UFUNCTION(BlueprintCallable)
	void OnPickupStart(ADBDPlayer* target);

	UFUNCTION(BlueprintCallable)
	void OnPickupEnd(ADBDPlayer* target);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocallyObservedChanged();

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnLevelReadyToPlay();

protected:
	UFUNCTION()
	void OnIntroCompletedNative();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIntroCompleted();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInterruptedStart();

	UFUNCTION()
	void OnHudVisibilityChangedNative(const bool isVisible);

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHudVisibilityChanged(const bool isVisible);

	UFUNCTION(BlueprintNativeEvent)
	FString OnGetCharacterName() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEscapeDoorActivated();

private:
	UFUNCTION()
	void OnCurrentMontageComplete(UAnimMontage* MontageAsset, bool interrupted);

	UFUNCTION()
	void OnCurrentMontageBlendingOut(UAnimMontage* MontageAsset, bool interrupted);

	UFUNCTION()
	void OnControllerChanged(APawn* pawn, AController* oldController, AController* newController);

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnClientRestart();

protected:
	UFUNCTION()
	void OnBlindChargeEmptied();

private:
	UFUNCTION()
	void OnAnimInstanceChanged();

public:
	UFUNCTION()
	void OnAllPlayerLoaded();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetRunVaultEnabled(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetReverseTraverseEnabled(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetInteractingPlayer(ADBDPlayer* interactingPlayer);

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetForceAuthoritativeMovement(bool value);

public:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetEnableCapsuleDynamicResize(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetDebugSnapPoint(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetDebugPrintAvailableInteractions(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetDebugCarry(bool enabled);

protected:
	UFUNCTION(BlueprintCallable)
	void Multicast_SetCustomization(TArray< FName> customizationParts, TArray< FCharmIdSlot> customizationCharms);

public:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetContinuousPrintDebug(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetAuthoritativeMovement(bool enabled);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ServerResetMeshRelativeOffSet();

protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ReplicateController(AController* newController);

public:
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void Multicast_LeaveGame(FGuid uniqueLeavingPlayerId);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Debug_SetMaxWalkSpeed(float maxWalkSpeed);

protected:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ConfirmItemDrop(bool pressed);

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Broadcast_DebugPlayMontage(FAnimationMontageDescriptor animMontageID, float playRate);

public:
	UFUNCTION(BlueprintNativeEvent)
	void Local_NotifyMatchEnded();

	UFUNCTION(BlueprintPure)
	bool Local_IsInteractionInputPressed(EInputInteractionType interactionType) const;

	UFUNCTION(BlueprintCallable)
	bool K2_SetActorLocationByBottomCapsule(FVector NewLocation, bool bSweep, FHitResult& SweepHitResult);

	UFUNCTION(BlueprintCallable)
	void ItemUseReleased();

	UFUNCTION(BlueprintCallable)
	void ItemUsePressed();

	UFUNCTION(BlueprintPure)
	bool IsRunning() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingMontage(FAnimationMontageDescriptor animMontageID) const;

	UFUNCTION(BlueprintPure)
	bool IsPlayingAnyMontage() const;

	UFUNCTION(BlueprintPure)
	bool IsMoving() const;

	UFUNCTION(BlueprintPure)
	bool IsLocallyObserved() const;

	UFUNCTION(BlueprintPure)
	bool IsInTerrorRadius() const;

	UFUNCTION(BlueprintPure)
	bool IsInteractionInputPressed(EInputInteractionType interactionType) const;

	UFUNCTION(BlueprintPure)
	bool IsInStalkMode() const;

	UFUNCTION(BlueprintPure)
	bool IsInsideCloset() const;

	UFUNCTION(BlueprintPure)
	bool IsInParadise() const;

	UFUNCTION(BlueprintPure)
	bool IsInMeathookZone() const;

	UFUNCTION(BlueprintPure)
	bool IsIncapacitated() const;

	UFUNCTION(BlueprintPure)
	bool IsHeadHidden() const;

	UFUNCTION(BlueprintPure)
	bool IsExhausted() const;

	UFUNCTION(BlueprintPure)
	bool IsCrouchPressed() const;

	UFUNCTION(BlueprintPure)
	bool IsCrouching() const;

	UFUNCTION(BlueprintPure)
	bool IsCloaked() const;

	UFUNCTION(BlueprintPure)
	bool IsBeingInterrupted() const;

	UFUNCTION(BlueprintPure)
	bool IsAllowedNavigation() const;

	UFUNCTION(BlueprintCallable)
	void InteractionInputReleased();

	UFUNCTION(BlueprintCallable)
	void InteractionInputPressed();

	UFUNCTION(BlueprintPure)
	bool HasMoveInput() const;

	UFUNCTION(BlueprintPure)
	bool HasDamageImmunity() const;

	UFUNCTION(BlueprintPure)
	bool HasClearPathToTargetWithIgnore(FVector targetPosition, const TArray<AActor*>& ignoreActors) const;

	UFUNCTION(BlueprintPure)
	bool HasClearPathToTarget(FVector targetPosition) const;

	UFUNCTION(BlueprintPure)
	float GetTunableValue(FName key, float defaultValue, bool warnIfRowMissing) const;

	UFUNCTION(BlueprintNativeEvent)
	ADBDPlayerController* GetSharedPlayerController() const;

	UFUNCTION(BlueprintPure)
	bool GetRunVaultEnabled() const;

	UFUNCTION(BlueprintPure)
	bool GetReverseTraverseEnabled() const;

	UFUNCTION(BlueprintPure)
	FRotator GetRepControlRotation() const;

	UFUNCTION(BlueprintPure)
	EPlayerTeam GetPlayerTeam() const;

	UFUNCTION(BlueprintPure)
	EPlayerRole GetPlayerRole() const;

	UFUNCTION(BlueprintPure)
	UPlayerInteractionHandler* GetPlayerInteractionHandler() const;

	UFUNCTION(BlueprintPure)
	FRotator GetPlayerDirection() const;

	UFUNCTION(BlueprintPure)
	ADBDPlayerController* GetPlayerController() const;

	UFUNCTION(BlueprintPure)
	UCameraComponent* GetPlayerCamera() const;

	UFUNCTION(BlueprintPure)
	UPerkManager* GetPerkManager() const;

	UFUNCTION(BlueprintPure)
	float GetPercentMovementSpeed() const;

	UFUNCTION(BlueprintPure)
	EPawnType GetPawnType() const;

	UFUNCTION(BlueprintPure)
	UOtherCharactersVerticalCollisionsHandler* GetOtherCharactersVerticalCollisionsHandler() const;

	UFUNCTION(BlueprintPure)
	UGameplayTagContainerComponent* GetObjectState() const;

	UFUNCTION(BlueprintPure)
	FString GetNameDebugString() const;

	UFUNCTION(BlueprintPure)
	UMontagePlayer* GetMontagePlayer() const;

	UFUNCTION(BlueprintPure)
	FMontagePlaybackDefinition GetMontagePlaybackDefinition(FAnimationMontageDescriptor animMontageID, float playRate, bool isFollower) const;

	UFUNCTION(BlueprintPure)
	float GetMontageLength(FAnimationMontageDescriptor animMontageID) const;

	UFUNCTION(BlueprintPure)
	UAnimMontage* GetMontage(FAnimationMontageDescriptor animMontageID) const;

	UFUNCTION(BlueprintPure)
	float GetMaxSpeed() const;

	UFUNCTION(BlueprintPure)
	float GetLuck() const;

	UFUNCTION(BlueprintPure)
	TArray<UItemModifier*> GetItemModifiers() const;

	UFUNCTION(BlueprintPure)
	TArray<UItemAddon*> GetItemAddons() const;

	UFUNCTION(BlueprintPure)
	bool GetIsInterrupting() const;

	UFUNCTION(BlueprintPure)
	bool GetIsInteracting() const;

	UFUNCTION(BlueprintPure)
	bool GetIsInFirstPerson() const;

	UFUNCTION(BlueprintCallable)
	FInteractionPlayerProperties GetInteractionPlayerProperties();

	UFUNCTION(BlueprintPure)
	UInteractionDetectorComponent* GetInteractionDetectorComponent() const;

	UFUNCTION(BlueprintPure)
	AInteractable* GetInteractable() const;

	UFUNCTION(BlueprintPure)
	ADBDPlayer* GetGuidingPlayer() const;

	UFUNCTION(BlueprintNativeEvent)
	float GetGrassEffectRadiusMultiplier() const;

	UFUNCTION(BlueprintPure)
	UActorComponent* GetFirstComponentByClass(TSubclassOf<UActorComponent> ComponentClass) const;

	UFUNCTION(BlueprintPure)
	FVector GetFeetPosition() const;

	UFUNCTION(BlueprintPure)
	UCharacterDreamworldComponent* GetDreamworldComponent() const;

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetDetectionZone(EDetectionZone detectionZoneID) const;

	UFUNCTION(BlueprintPure)
	ADBDPlayerState* GetDBDPlayerState() const;

	UFUNCTION(BlueprintPure)
	EInteractionAnimation GetCurrentInteractionAnimation() const;

	UFUNCTION(BlueprintPure)
	UInteractionDefinition* GetCurrentInteraction() const;

	UFUNCTION(BlueprintPure)
	UChaseComponent* GetChaseComponent() const;

	UFUNCTION(BlueprintPure)
	UCharacterInventoryComponent* GetCharacterInventoryComponent() const;

	UFUNCTION(BlueprintPure)
	ADBDPlayerCameraManager* GetCameraManager() const;

	UFUNCTION(BlueprintPure)
	FVector GetBoneLocation(FName name, TEnumAsByte<EBoneSpaces::Type> space) const;

	UFUNCTION(BlueprintPure)
	UBlindableComponent* GetBlindableComponent() const;

	UFUNCTION(BlueprintPure)
	FVector GetAverageVelocity() const;

	UFUNCTION(BlueprintPure)
	UAuthoritativeMovementComponent* GetAuthoritativeMovementComponent() const;

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	USceneComponent* GetAttachPoint(FName attachPointName) const;

	UFUNCTION(BlueprintNativeEvent)
	APlayerState* GetAssociatedPlayerState() const;

	UFUNCTION(BlueprintPure)
	void GetAnimTags(TArray<FName>& outTags) const;

	UFUNCTION(BlueprintPure)
	UAnimInstance* GetAnimInstance() const;

	UFUNCTION(BlueprintPure)
	FVector GetActorLocationFromFeetLocation(const FVector FeetLocation) const;

	UFUNCTION(BlueprintPure)
	ADBDPlayer* FindClosestSlashablePlayerInDetectionZone(EDetectionZone detectionZoneID) const;

	UFUNCTION(BlueprintCallable)
	void FastInteractionInputReleased();

	UFUNCTION(BlueprintCallable)
	void FastInteractionInputPressed();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Dissolve(bool dissolve);

	UFUNCTION(BlueprintCallable)
	void DetachInteractor();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DBDUnCrouch();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DBDCrouch();

private:
	UFUNCTION(Exec)
	void DBD_ToggleForceAuthoritativeMovement();

public:
	UFUNCTION(Exec)
	void DBD_ToggleDebugInteractionInZone();

protected:
	UFUNCTION(Exec)
	void DBD_SetMouseTurnSpeedMultiplier(float value);

	UFUNCTION(Exec)
	void DBD_SetMouseLookUpSpeedMultiplier(float value);

public:
	UFUNCTION(Exec)
	void DBD_DebugStartInteraction();

	UFUNCTION(Exec)
	void DBD_CancelInteraction();

	UFUNCTION(BlueprintCallable, Client, Reliable)
	void Client_TryInteractionType(EInputInteractionType interactionType, ADBDPlayer* requester);

	UFUNCTION(Client, Reliable)
	void Client_TryInteraction(UInteractionDefinition* interaction, ADBDPlayer* requester, bool force, bool usingInputPersistence);

	UFUNCTION(BlueprintCallable, Client, Reliable)
	void Client_SendCancelInteraction(const UInteractionDefinition* interactionDefinition);

private:
	UFUNCTION(Client, Reliable)
	void Client_Debug_PlayerStartSnapping(const FVector& location, const float duration);

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool CanInterrupt_BP() const;

public:
	UFUNCTION(BlueprintCallable)
	void CancelCarry(bool alsoCancelForOtherPlayer);

	UFUNCTION(BlueprintCallable)
	void CameraUpdated();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_SetDreamworldComponent(UCharacterDreamworldComponent* component);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_RequestStun(EStunType stunType, ADBDPlayer* stunner);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_RemoveStatusEffectByID(FName statusEffectId, bool bRemoveAllWithID);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UStatusEffect* Authority_ImposeStatusEffect_DEPRECATED(FName statusEffectID, ADBDPlayer* originatingPlayer, float customParam, UGameplayModifierContainer* originatingEffect, bool shouldDisplay, float lifetime);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UStatusEffect* Authority_ImposeDynamicStatusEffect_DEPRECATED(FName statusEffectID, ADBDPlayer* originatingPlayer, float customParam, UGameplayModifierContainer* originatingEffect);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Authority_HandleScoreEvent(FGameplayTag scoreTypeTag, FScoreEventData scoreEventData);

private:
	UFUNCTION()
	void Authority_EvaluateIfPlayerCanSee();

public:
	UFUNCTION(BlueprintCallable)
	void AttachInteractor(UInteractor* interactor);

	UFUNCTION(BlueprintCallable)
	void AddDetectionZone(EDetectionZone detectionZoneID, UPrimitiveComponent* zone);

	UFUNCTION(BlueprintCallable)
	void AbilityTwoInputReleased();

	UFUNCTION(BlueprintCallable)
	void AbilityTwoInputPressed();

	UFUNCTION(BlueprintCallable)
	void AbilityInputReleased();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	ADBDPlayer();
};

FORCEINLINE uint32 GetTypeHash(const ADBDPlayer) { return 0; }
