#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OnCustomizationChanged.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Chaos/ChaosEngineInterface.h"
#include "DBDBasePlayer.generated.h"

class UAkComponent;
class UCustomizedSkeletalMesh;
class UBaseGroundDetectorComponent;
class UCustomizedAudioComponent;

UCLASS()
class DEADBYDAYLIGHT_API ADBDBasePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnCustomizationChanged OnCustomizationChanged;

protected:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer _semanticGameplayTags;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UBaseGroundDetectorComponent* _leftFootGroundDetector;

	UPROPERTY(VisibleAnywhere, meta=(BindWidgetOptional))
	UBaseGroundDetectorComponent* _rightFootGroundDetector;

private:
	UPROPERTY(EditAnywhere)
	int32 _characterIndex;

public:
	UFUNCTION(BlueprintCallable)
	bool TeleportWithClothHandling(const FVector& location, const FRotator& rotation, bool checkCollisions);

protected:
	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void Multicast_SwapCosmetics(FName cosmeticId);

public:
	UFUNCTION(BlueprintPure)
	bool GetShowBlindDebugInfo() const;

	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetSemanticTag() const;

	UFUNCTION(BlueprintPure)
	TEnumAsByte<EPhysicalSurface> GetRightFootSurfaceType() const;

	UFUNCTION(BlueprintPure)
	FString GetRightFootAudioSurfaceName() const;

	UFUNCTION(BlueprintPure)
	TEnumAsByte<EPhysicalSurface> GetLeftFootSurfaceType() const;

	UFUNCTION(BlueprintPure)
	FString GetLeftFootAudioSurfaceName() const;

	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	UCustomizedSkeletalMesh* GetCustomizedSkeletalMesh() const;

	UFUNCTION(BlueprintPure)
	UCustomizedAudioComponent* GetCustomizedAudio() const;

	UFUNCTION(BlueprintPure)
	FName GetCharacterName() const;

	UFUNCTION(BlueprintPure)
	int32 GetCharacterIndex() const;

	UFUNCTION(BlueprintPure)
	UAkComponent* GetAudioComponent() const;

protected:
	UFUNCTION(Exec)
	void DBD_SwapCosmetics(FName cosmeticId);

public:
	ADBDBasePlayer();
};

FORCEINLINE uint32 GetTypeHash(const ADBDBasePlayer) { return 0; }
