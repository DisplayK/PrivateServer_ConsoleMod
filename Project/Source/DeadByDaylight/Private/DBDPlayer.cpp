#include "DBDPlayer.h"
#include "AuthoritativeMovementComponent.h"
#include "PerkManager.h"
#include "EAnimNotifyType.h"
#include "CharacterSightComponent.h"
#include "PlayerInteractionHandler.h"
#include "EInputInteractionType.h"
#include "UObject/NoExportTypes.h"
#include "PrimitivesRegistererComponent.h"
#include "EStunType.h"
#include "AnimationMontageDescriptor.h"
#include "EDBDScoreTypes.h"
#include "Components/SceneComponent.h"
#include "EDetectionZone.h"
#include "Templates/SubclassOf.h"
#include "EquippedPlayerCustomization.h"
#include "EPlayerTeam.h"
#include "DynamicCapsuleResizerComponent.h"
#include "MaterialHelper.h"
#include "Engine/EngineTypes.h"
#include "EPlayerRole.h"
#include "EInteractionAnimation.h"
#include "EPawnType.h"
#include "GameplayTagContainer.h"
#include "MontagePlaybackDefinition.h"
#include "InteractionPlayerProperties.h"
#include "Components/SkinnedMeshComponent.h"
#include "ScoreEventData.h"
#include "Net/UnrealNetwork.h"
#include "ActivatorComponent.h"
#include "CharacterInventoryComponent.h"
#include "PlayerGameRelevancyComponent.h"
#include "ChaseComponent.h"
#include "ReversibleActionSystemComponent.h"
#include "BoxOcclusionQueryComponent.h"
#include "Components/BoxComponent.h"
#include "MontagePlayer.h"
#include "CharacterChaseVisualComponent.h"
#include "CameraHandlerComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "ChargeableComponent.h"
#include "BlindableComponent.h"
#include "PollableEventListener.h"
#include "ZoneDetectorComponent.h"
#include "InteractionDetectorComponent.h"
#include "GameplayTagContainerComponent.h"
#include "AudioFXComponent.h"
#include "PlayerPerspectiveComponent.h"
#include "CharacterSightableComponent.h"
#include "ClippableProviderComponent.h"
#include "ContextualQuestComponent.h"
#include "ChargeableProgressProviderComponent.h"
#include "OtherCharactersVerticalCollisionsHandler.h"

class UStatusEffect;
class ADBDPlayer;
class UCharacterDreamworldComponent;
class UInteractionDefinition;
class AController;
class UActorComponent;
class UCameraComponent;
class APlayerState;
class UAnimInstance;
class ACollectable;
class UItemModifier;
class UAnimMontage;
class ADBDPlayerCameraManager;
class APawn;
class AActor;
class ADBDPlayerController;
class UPrimitiveComponent;
class UItemAddon;
class AInteractable;
class ADBDPlayerState;
class UGameplayModifierContainer;
class UInteractor;

void ADBDPlayer::UpdateLoadoutFromInventory()
{

}

bool ADBDPlayer::TryInteractionType(EInputInteractionType interactionInputType, ADBDPlayer* requester, bool usingInputPersistence, bool force)
{
	return false;
}

bool ADBDPlayer::TryInteraction(UInteractionDefinition* interaction, ADBDPlayer* requester, bool force, bool usingInputPersistence)
{
	return false;
}

bool ADBDPlayer::TryFireScoreEvent(EDBDScoreTypes scoreType, float percentToAward)
{
	return false;
}

void ADBDPlayer::TriggerAnimNotify(EAnimNotifyType animNotifyType)
{

}

void ADBDPlayer::StopMontage()
{

}

void ADBDPlayer::SnapCharacter(bool snapPosition, FVector position, float stopSnapDistance, bool snapRotation, FRotator rotation, float time, bool useZCoord, bool sweepOnFinalSnap, bool snapRoll)
{

}

bool ADBDPlayer::ShouldPlayCarryAnim() const
{
	return false;
}

bool ADBDPlayer::ShouldFall() const
{
	return false;
}

void ADBDPlayer::SetShouldPlayCarryAnim(bool shouldPlayCarryAnim)
{

}

void ADBDPlayer::SetReverseMontage(bool reverse)
{

}

void ADBDPlayer::SetQuestEventHandlerComponent(UActorComponent* component)
{

}

void ADBDPlayer::SetItemUseAsToggle(bool value)
{

}

void ADBDPlayer::SetIsCloaked(bool isCloaked, bool forced)
{

}

void ADBDPlayer::SetForceDisableSkillChecks(bool isEnabled)
{

}

void ADBDPlayer::SetFirstPersonVfxsVisibility(bool isFirstPerson)
{

}

void ADBDPlayer::SetFirstPersonModelEnabled(bool enabled, bool force)
{

}

void ADBDPlayer::SetFeetOnGround(bool feetOnGround)
{

}

void ADBDPlayer::SetDetectionZoneEnabled(EDetectionZone detectionZoneID, bool enabled)
{

}

void ADBDPlayer::SetAllowNavigation(bool enable)
{

}

void ADBDPlayer::SetAllDetectionZonesEnabled(bool enabled)
{

}

void ADBDPlayer::Server_UpdateScreenAspectRatio_Implementation(const float value)
{

}

void ADBDPlayer::Server_SendSecondaryActionPressed_Implementation(bool fromCancelRequest)
{

}

void ADBDPlayer::Server_SendItemUseInput_Implementation(bool pressed, bool requestItemUse)
{

}

void ADBDPlayer::Server_SendItemDropInput_Implementation(bool pressed)
{

}

void ADBDPlayer::Server_SendInteractionInput_Implementation(bool pressed)
{

}

void ADBDPlayer::Server_SendFastInteractionInput_Implementation(bool pressed)
{

}

void ADBDPlayer::Server_SendAbilityTwoInput_Implementation(bool pressed)
{

}

void ADBDPlayer::Server_SendAbilityInput_Implementation(bool pressed)
{

}

void ADBDPlayer::Server_PlayerReady_Implementation()
{

}

void ADBDPlayer::Server_GameTimeSync_Implementation()
{

}

void ADBDPlayer::Server_Drop_Implementation(ACollectable* item, const FVector& location, const FRotator& rotation, bool onDeath)
{

}

void ADBDPlayer::Server_SetCustomization(TArray<FName> customizationParts, TArray<FCharmIdSlot> customizationCharms){}

void ADBDPlayer::Server_Broadcast_DebugPlayMontage_Implementation(FAnimationMontageDescriptor animMontageID, float playRate)
{

}

void ADBDPlayer::ResetPitchScale(float adjustTime)
{

}

void ADBDPlayer::ResetCamera()
{

}

void ADBDPlayer::RemoveStatusEffect(UStatusEffect* statusEffect)
{

}

UAnimMontage* ADBDPlayer::PlayMontage(FAnimationMontageDescriptor animMontageID, float playRate, bool isFollower)
{
	return NULL;
}

void ADBDPlayer::OnRep_Interactable()
{

}

void ADBDPlayer::OnRep_DreamworldComponent()
{

}

void ADBDPlayer::OnPostProcessInput()
{

}

void ADBDPlayer::OnPickupStart(ADBDPlayer* target)
{

}

void ADBDPlayer::OnPickupEnd(ADBDPlayer* target)
{

}

void ADBDPlayer::OnLevelReadyToPlay_Implementation()
{

}

void ADBDPlayer::OnIntroCompletedNative()
{

}

void ADBDPlayer::OnHudVisibilityChangedNative(const bool isVisible)
{

}

FString ADBDPlayer::OnGetCharacterName_Implementation() const
{
	return TEXT("");
}

void ADBDPlayer::OnCurrentMontageComplete(UAnimMontage* MontageAsset, bool interrupted)
{

}

void ADBDPlayer::OnCurrentMontageBlendingOut(UAnimMontage* MontageAsset, bool interrupted)
{

}

void ADBDPlayer::OnControllerChanged(APawn* pawn, AController* oldController, AController* newController)
{

}

void ADBDPlayer::OnBlindChargeEmptied()
{

}

void ADBDPlayer::OnAnimInstanceChanged()
{

}

void ADBDPlayer::OnAllPlayerLoaded()
{

}

void ADBDPlayer::Multicast_SetRunVaultEnabled_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetReverseTraverseEnabled_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetInteractingPlayer_Implementation(ADBDPlayer* interactingPlayer)
{

}

void ADBDPlayer::Multicast_SetForceAuthoritativeMovement_Implementation(bool value)
{

}

void ADBDPlayer::Multicast_SetEnableCapsuleDynamicResize_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetDebugSnapPoint_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetDebugPrintAvailableInteractions_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetDebugCarry_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetCustomization(TArray< FName> customizationParts, TArray< FCharmIdSlot> customizationCharms){}

void ADBDPlayer::Multicast_SetContinuousPrintDebug_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_SetAuthoritativeMovement_Implementation(bool enabled)
{

}

void ADBDPlayer::Multicast_ServerResetMeshRelativeOffSet_Implementation()
{

}

void ADBDPlayer::Multicast_ReplicateController_Implementation(AController* newController)
{

}

void ADBDPlayer::Multicast_LeaveGame_Implementation(FGuid uniqueLeavingPlayerId)
{

}

void ADBDPlayer::Multicast_Debug_SetMaxWalkSpeed_Implementation(float maxWalkSpeed)
{

}

void ADBDPlayer::Multicast_ConfirmItemDrop_Implementation(bool pressed)
{

}

void ADBDPlayer::Multicast_Broadcast_DebugPlayMontage_Implementation(FAnimationMontageDescriptor animMontageID, float playRate)
{

}

void ADBDPlayer::Local_NotifyMatchEnded_Implementation()
{

}

bool ADBDPlayer::Local_IsInteractionInputPressed(EInputInteractionType interactionType) const
{
	return false;
}

bool ADBDPlayer::K2_SetActorLocationByBottomCapsule(FVector NewLocation, bool bSweep, FHitResult& SweepHitResult)
{
	return false;
}

void ADBDPlayer::ItemUseReleased()
{

}

void ADBDPlayer::ItemUsePressed()
{

}

bool ADBDPlayer::IsRunning() const
{
	return false;
}

bool ADBDPlayer::IsPlayingMontage(FAnimationMontageDescriptor animMontageID) const
{
	return false;
}

bool ADBDPlayer::IsPlayingAnyMontage() const
{
	return false;
}

bool ADBDPlayer::IsMoving() const
{
	return false;
}

bool ADBDPlayer::IsLocallyObserved() const
{
	return false;
}

bool ADBDPlayer::IsInTerrorRadius() const
{
	return false;
}

bool ADBDPlayer::IsInteractionInputPressed(EInputInteractionType interactionType) const
{
	return false;
}

bool ADBDPlayer::IsInStalkMode() const
{
	return false;
}

bool ADBDPlayer::IsInsideCloset() const
{
	return false;
}

bool ADBDPlayer::IsInParadise() const
{
	return false;
}

bool ADBDPlayer::IsInMeathookZone() const
{
	return false;
}

bool ADBDPlayer::IsIncapacitated() const
{
	return false;
}

bool ADBDPlayer::IsHeadHidden() const
{
	return false;
}

bool ADBDPlayer::IsExhausted() const
{
	return false;
}

bool ADBDPlayer::IsCrouchPressed() const
{
	return false;
}

bool ADBDPlayer::IsCrouching() const
{
	return false;
}

bool ADBDPlayer::IsCloaked() const
{
	return false;
}

bool ADBDPlayer::IsBeingInterrupted() const
{
	return false;
}

bool ADBDPlayer::IsAllowedNavigation() const
{
	return false;
}

void ADBDPlayer::InteractionInputReleased()
{

}

void ADBDPlayer::InteractionInputPressed()
{

}

bool ADBDPlayer::HasMoveInput() const
{
	return false;
}

bool ADBDPlayer::HasDamageImmunity() const
{
	return false;
}

bool ADBDPlayer::HasClearPathToTargetWithIgnore(FVector targetPosition, const TArray<AActor*>& ignoreActors) const
{
	return false;
}

bool ADBDPlayer::HasClearPathToTarget(FVector targetPosition) const
{
	return false;
}

float ADBDPlayer::GetTunableValue(FName key, float defaultValue, bool warnIfRowMissing) const
{
	return 0.0f;
}

ADBDPlayerController* ADBDPlayer::GetSharedPlayerController_Implementation() const
{
	return NULL;
}

bool ADBDPlayer::GetRunVaultEnabled() const
{
	return false;
}

bool ADBDPlayer::GetReverseTraverseEnabled() const
{
	return false;
}

FRotator ADBDPlayer::GetRepControlRotation() const
{
	return FRotator{};
}

EPlayerTeam ADBDPlayer::GetPlayerTeam() const
{
	return EPlayerTeam::VE_None;
}

EPlayerRole ADBDPlayer::GetPlayerRole() const
{
	return EPlayerRole::VE_None;
}

UPlayerInteractionHandler* ADBDPlayer::GetPlayerInteractionHandler() const
{
	return NULL;
}

FRotator ADBDPlayer::GetPlayerDirection() const
{
	return FRotator{};
}

ADBDPlayerController* ADBDPlayer::GetPlayerController() const
{
	return NULL;
}

UCameraComponent* ADBDPlayer::GetPlayerCamera() const
{
	return NULL;
}

UPerkManager* ADBDPlayer::GetPerkManager() const
{
	return NULL;
}

float ADBDPlayer::GetPercentMovementSpeed() const
{
	return 0.0f;
}

EPawnType ADBDPlayer::GetPawnType() const
{
	return EPawnType::VE_None;
}

UOtherCharactersVerticalCollisionsHandler* ADBDPlayer::GetOtherCharactersVerticalCollisionsHandler() const
{
	return NULL;
}

UGameplayTagContainerComponent* ADBDPlayer::GetObjectState() const
{
	return NULL;
}

FString ADBDPlayer::GetNameDebugString() const
{
	return TEXT("");
}

UMontagePlayer* ADBDPlayer::GetMontagePlayer() const
{
	return NULL;
}

FMontagePlaybackDefinition ADBDPlayer::GetMontagePlaybackDefinition(FAnimationMontageDescriptor animMontageID, float playRate, bool isFollower) const
{
	return FMontagePlaybackDefinition{};
}

float ADBDPlayer::GetMontageLength(FAnimationMontageDescriptor animMontageID) const
{
	return 0.0f;
}

UAnimMontage* ADBDPlayer::GetMontage(FAnimationMontageDescriptor animMontageID) const
{
	return NULL;
}

float ADBDPlayer::GetMaxSpeed() const
{
	return 0.0f;
}

float ADBDPlayer::GetLuck() const
{
	return 0.0f;
}

TArray<UItemModifier*> ADBDPlayer::GetItemModifiers() const
{
	return TArray<UItemModifier*>();
}

TArray<UItemAddon*> ADBDPlayer::GetItemAddons() const
{
	return TArray<UItemAddon*>();
}

bool ADBDPlayer::GetIsInterrupting() const
{
	return false;
}

bool ADBDPlayer::GetIsInteracting() const
{
	return false;
}

bool ADBDPlayer::GetIsInFirstPerson() const
{
	return false;
}

FInteractionPlayerProperties ADBDPlayer::GetInteractionPlayerProperties()
{
	return FInteractionPlayerProperties{};
}

UInteractionDetectorComponent* ADBDPlayer::GetInteractionDetectorComponent() const
{
	return NULL;
}

AInteractable* ADBDPlayer::GetInteractable() const
{
	return NULL;
}

ADBDPlayer* ADBDPlayer::GetGuidingPlayer() const
{
	return NULL;
}

float ADBDPlayer::GetGrassEffectRadiusMultiplier_Implementation() const
{
	return 0.0f;
}

UActorComponent* ADBDPlayer::GetFirstComponentByClass(TSubclassOf<UActorComponent> ComponentClass) const
{
	return NULL;
}

FVector ADBDPlayer::GetFeetPosition() const
{
	return FVector{};
}

UCharacterDreamworldComponent* ADBDPlayer::GetDreamworldComponent() const
{
	return NULL;
}

UPrimitiveComponent* ADBDPlayer::GetDetectionZone(EDetectionZone detectionZoneID) const
{
	return NULL;
}

ADBDPlayerState* ADBDPlayer::GetDBDPlayerState() const
{
	return NULL;
}

EInteractionAnimation ADBDPlayer::GetCurrentInteractionAnimation() const
{
	return EInteractionAnimation::VE_None;
}

UInteractionDefinition* ADBDPlayer::GetCurrentInteraction() const
{
	return NULL;
}

UChaseComponent* ADBDPlayer::GetChaseComponent() const
{
	return NULL;
}

UCharacterInventoryComponent* ADBDPlayer::GetCharacterInventoryComponent() const
{
	return NULL;
}

ADBDPlayerCameraManager* ADBDPlayer::GetCameraManager() const
{
	return NULL;
}

FVector ADBDPlayer::GetBoneLocation(FName name, TEnumAsByte<EBoneSpaces::Type> space) const
{
	return FVector{};
}

UBlindableComponent* ADBDPlayer::GetBlindableComponent() const
{
	return NULL;
}

FVector ADBDPlayer::GetAverageVelocity() const
{
	return FVector{};
}

UAuthoritativeMovementComponent* ADBDPlayer::GetAuthoritativeMovementComponent() const
{
	return NULL;
}

USceneComponent* ADBDPlayer::GetAttachPoint_Implementation(FName attachPointName) const
{
	return NULL;
}

APlayerState* ADBDPlayer::GetAssociatedPlayerState_Implementation() const
{
	return NULL;
}

void ADBDPlayer::GetAnimTags(TArray<FName>& outTags) const
{

}

UAnimInstance* ADBDPlayer::GetAnimInstance() const
{
	return NULL;
}

FVector ADBDPlayer::GetActorLocationFromFeetLocation(const FVector FeetLocation) const
{
	return FVector{};
}

ADBDPlayer* ADBDPlayer::FindClosestSlashablePlayerInDetectionZone(EDetectionZone detectionZoneID) const
{
	return NULL;
}

void ADBDPlayer::FastInteractionInputReleased()
{

}

void ADBDPlayer::FastInteractionInputPressed()
{

}

void ADBDPlayer::DetachInteractor()
{

}

void ADBDPlayer::DBDUnCrouch_Implementation()
{

}

void ADBDPlayer::DBDCrouch_Implementation()
{

}

void ADBDPlayer::DBD_ToggleForceAuthoritativeMovement()
{

}

void ADBDPlayer::DBD_ToggleDebugInteractionInZone()
{

}

void ADBDPlayer::DBD_SetMouseTurnSpeedMultiplier(float value)
{

}

void ADBDPlayer::DBD_SetMouseLookUpSpeedMultiplier(float value)
{

}

void ADBDPlayer::DBD_DebugStartInteraction()
{

}

void ADBDPlayer::DBD_CancelInteraction()
{

}

void ADBDPlayer::Client_TryInteractionType_Implementation(EInputInteractionType interactionType, ADBDPlayer* requester)
{

}

void ADBDPlayer::Client_TryInteraction_Implementation(UInteractionDefinition* interaction, ADBDPlayer* requester, bool force, bool usingInputPersistence)
{

}

void ADBDPlayer::Client_SendCancelInteraction_Implementation(const UInteractionDefinition* interactionDefinition)
{

}

void ADBDPlayer::Client_Debug_PlayerStartSnapping_Implementation(const FVector& location, const float duration)
{

}

bool ADBDPlayer::CanInterrupt_BP_Implementation() const
{
	return false;
}

void ADBDPlayer::CancelCarry(bool alsoCancelForOtherPlayer)
{

}

void ADBDPlayer::CameraUpdated()
{

}

void ADBDPlayer::Authority_SetDreamworldComponent(UCharacterDreamworldComponent* component)
{

}

void ADBDPlayer::Authority_RequestStun(EStunType stunType, ADBDPlayer* stunner)
{

}

void ADBDPlayer::Authority_RemoveStatusEffectByID(FName statusEffectId, bool bRemoveAllWithID)
{

}

UStatusEffect* ADBDPlayer::Authority_ImposeStatusEffect_DEPRECATED(FName statusEffectID, ADBDPlayer* originatingPlayer, float customParam, UGameplayModifierContainer* originatingEffect, bool shouldDisplay, float lifetime)
{
	return NULL;
}

UStatusEffect* ADBDPlayer::Authority_ImposeDynamicStatusEffect_DEPRECATED(FName statusEffectID, ADBDPlayer* originatingPlayer, float customParam, UGameplayModifierContainer* originatingEffect)
{
	return NULL;
}

void ADBDPlayer::Authority_HandleScoreEvent(FGameplayTag scoreTypeTag, FScoreEventData scoreEventData)
{

}

void ADBDPlayer::Authority_EvaluateIfPlayerCanSee()
{

}

void ADBDPlayer::AttachInteractor(UInteractor* interactor)
{

}

void ADBDPlayer::AddDetectionZone(EDetectionZone detectionZoneID, UPrimitiveComponent* zone)
{

}

void ADBDPlayer::AbilityTwoInputReleased()
{

}

void ADBDPlayer::AbilityTwoInputPressed()
{

}

void ADBDPlayer::AbilityInputReleased()
{

}

void ADBDPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADBDPlayer, _interactable);
	DOREPLIFETIME(ADBDPlayer, _dreamworldComponent);
	DOREPLIFETIME(ADBDPlayer, _screenAspectRatio);
}

ADBDPlayer::ADBDPlayer()
{
	this->AllowInterrupting = false;
	this->MinFallHeight = 50.000000;
	this->IsInterruptable = false;
	this->AllowNavigationInput = false;
	this->AllowNavigationBackwardInput = true;
	this->AllowTurningInput = false;
	this->AllowPitchInput = false;
	this->AllowStrafeInput = true;
	this->IsInInteractionUpdate = false;
	this->IsInteractionChargeCompleted = false;
	this->PitchLimitLower = -40.000000;
	this->PitchLimitUpper = 40.000000;
	this->PelvisHeight = 1.000000;
	this->PelvisHeightForPounceOnStandingCamper = 0.500000;
	this->PelvisHeightForPounceOnCrouchingCamper = 0.000000;
	this->CameraBoom = NULL;
	this->ForceSkillChecks = false;
	this->CameraResetSpeed = 2.250000;
	this->AverageSpeedBufferTime = 0.000000;
	this->AlmostCurrentSpeedBufferTime = 0.000000;
	this->GamepadYawCurve = NULL;
	this->GamepadPitchCurve = NULL;
	this->GamepadSettingToYawRateCurve = NULL;
	this->GamepadSettingToPitchRateCurve = NULL;
	this->JoyconSettingToYawRateCurve = NULL;
	this->JoyconSettingToPitchRateCurve = NULL;
	this->Camera = NULL;
	this->MaterialHelper = CreateDefaultSubobject<UMaterialHelper>(TEXT("MaterialHelperNative"));
	this->Interactable = NULL;
	this->_characterInventoryComponent = CreateDefaultSubobject<UCharacterInventoryComponent>(TEXT("CharacterInventoryComponent"));
	this->CarryJointName = TEXT("Camper_SocketLT");
	this->_pitchOffsetForInteractionPriority = 0.000000;
	this->_renderedPixelCounter = CreateDefaultSubobject<UBoxOcclusionQueryComponent>(TEXT("RenderedPixelCounter"));
	this->_standingOcclusionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Standing Occlusion Box"));
	this->_crouchingOcclusionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Crouching Occlusion Box"));
	this->_activator = CreateDefaultSubobject<UActivatorComponent>(TEXT("Activator"));
	this->IsInteracting = false;
	this->_aiCanBeSeenTestCrouchScale = 0.700000;
	this->_aiCanBeSeenTestRightOffset = 15.000000;
	this->_aiCanBeSeenTestHighOffset = 25.000000;
	this->_aiCanBeSeenTestLowOffset = 10.000000;
	this->ClearPathTestRadiusMultiplier = 0.990000;
	this->ClearPathTestHeightMultiplier = 0.900000;
	this->LocationClearTestRadiusMultiplier = 0.900000;
	this->LocationClearTestHeightMultiplier = 0.900000;
	this->ClearPathTestStepHeight = 20.000000;
	this->MouseTurnSpeedMultiplier = 1.000000;
	this->MouseLookUpSpeedMultiplier = 1.000000;
	this->DeathSound = NULL;
	this->CurrentCamperState = ECamperState::VE_None;
	this->CollectableAttachPoint = NAME_None;
	this->_stateMachine = NULL;
	this->_interactionHandler = CreateDefaultSubobject<UPlayerInteractionHandler>(TEXT("InteractionHandler"));
	this->_montagePlayer = CreateDefaultSubobject<UMontagePlayer>(TEXT("MontagePlayer"));
	this->_perkManager = CreateDefaultSubobject<UPerkManager>(TEXT("PerkManager"));
	this->_playerData = NULL;
	this->_interactable = NULL;
	this->_guidingPlayer = NULL;
	this->_interactingPlayer = NULL;
	this->_nextAttackSubstate = EAttackSubstate::VE_None;
	this->_hitTargets = TArray<ADBDPlayer*>();
	this->_dreamworldComponent = NULL;
	this->_characterChaseVisualComponent = CreateDefaultSubobject<UCharacterChaseVisualComponent>(TEXT("CharacterChaseVisualComponent"));
	this->_cameraHandlerComponent = CreateDefaultSubobject<UCameraHandlerComponent>(TEXT("CameraHandlerComponent"));
	this->_reversibleActionSystemComponent = CreateDefaultSubobject<UReversibleActionSystemComponent>(TEXT("ActionSystemComponent"));
	this->_itemDropOffPosition = CreateDefaultSubobject<USceneComponent>(TEXT("ItemDropOffPosition"));
	this->_perceptionStimuliComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSourceComponent"));
	this->_ignoreActors = TArray<AActor*>();
	this->EffectCameraTypeSettings = TArray<FEffectCameraTypeSettings>();
	this->_detectionZoneEnabledMap = TMap<USceneComponent*, bool>();
	this->_blindingChargeableComponent = CreateDefaultSubobject<UChargeableComponent>(TEXT("BlindnessChargeableComponent"));
	this->_shouldUpdateStateMachineDriverOnPossessed = true;
	this->_blindableComponent = CreateDefaultSubobject<UBlindableComponent>(TEXT("BlindableComponent"));
	this->_tutorialChargeableInteractionMultiplier = 1.000000;
	this->_eventListener = CreateDefaultSubobject<UPollableEventListener>(TEXT("EventListener"));
	this->_chaseComponent = CreateDefaultSubobject<UChaseComponent>(TEXT("Chase Component"));
	this->_meatHookZoneDetector = CreateDefaultSubobject<UZoneDetectorComponent>(TEXT("MeatHookZoneDetector"));
	this->_basementZoneDetector = CreateDefaultSubobject<UZoneDetectorComponent>(TEXT("BasementZoneDetector"));
	this->_bookmarkedInteraction = NULL;
	this->_detectionZoneMap = TMap<EDetectionZone, UPrimitiveComponent*>();
	this->_authoritativeMovementComponent = CreateDefaultSubobject<UAuthoritativeMovementComponent>(TEXT("AuthoritativeMovement"));
	this->_screenAspectRatio = 1.777778;
	this->_objectState = CreateDefaultSubobject<UGameplayTagContainerComponent>(TEXT("ObjectState"));
	this->_audioFXComponent = CreateDefaultSubobject<UAudioFXComponent>(TEXT("AudioFXComponent"));
	this->_playerPerspectiveComponent = CreateDefaultSubobject<UPlayerPerspectiveComponent>(TEXT("PlayerPerspectiveComponent"));
	this->_characterSightComponent = CreateDefaultSubobject<UCharacterSightComponent>(TEXT("CharacterSightComponent"));
	this->_characterSightableComponent = CreateDefaultSubobject<UCharacterSightableComponent>(TEXT("CharacterSightableComponent"));
	this->_interactionDetectorComponent = CreateDefaultSubobject<UInteractionDetectorComponent>(TEXT("InteractionDetectorComponent"));
	this->_clippablePrimitivesRegistererComponent = CreateDefaultSubobject<UPrimitivesRegistererComponent>(TEXT("PrimitiveRegistererComponent"));
	this->_clippableProviderComponent = CreateDefaultSubobject<UClippableProviderComponent>(TEXT("ClippableProviderComponent"));
	this->_dynCapsuleResizer = CreateDefaultSubobject<UDynamicCapsuleResizerComponent>(TEXT("Dyn Capsule Resizer"));
	this->_playerGameRelevancyComponent = CreateDefaultSubobject<UPlayerGameRelevancyComponent>(TEXT("PlayerGameRelevancyComponent"));
	this->_contextualQuestComponent = CreateDefaultSubobject<UContextualQuestComponent>(TEXT("ContextualQuestComponent"));
	this->_questEventHandler = NULL;
	this->_presentationChargeableProgressComponent = CreateDefaultSubobject<UChargeableProgressProviderComponent>(TEXT("Presentation Chargeable Progress"));
	this->_currentGamepadYawCurve = NULL;
	this->_currentGamepadPitchCurve = NULL;
	this->_associatedPlayerStateCache = NULL;
	this->_otherCharactersVerticalCollisionsHandler = CreateDefaultSubobject<UOtherCharactersVerticalCollisionsHandler>(TEXT("OtherCharactersVerticalCollisionsHandler"));
}
