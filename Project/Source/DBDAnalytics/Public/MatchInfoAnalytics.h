#pragma once

#include "CoreMinimal.h"
#include "EGameType.h"
#include "UniquelyIdentifiedAnalytic.h"
#include "EPlayerRole.h"
#include "EAIDifficultyLevel.h"
#include "MatchInfoAnalytics.generated.h"

USTRUCT(BlueprintType)
struct FMatchInfoAnalytics: public FUniquelyIdentifiedAnalytic
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EGameType GameMode;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPlayerRole Role;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsABot;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString BotId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAIDifficultyLevel BotDifficultyLevel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PartySize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Rank;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Prestige;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Pips;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PipsTotal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MapSeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString MapName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PartyHostMirrorsId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString LobbyId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString MatchId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString KrakenMatchId;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SelectedCountry;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool FirstTimePlaying;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CumulativeMatches;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CumulativeMatchesAsSurvivor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CumulativeMatchesAsKiller;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString LastMatchTimestamp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ExactPing;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool hasAnActiveArchiveQuest;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsUsingKeyboard;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ControllerType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsTutorialBotMatch;

public:
	DBDANALYTICS_API FMatchInfoAnalytics();
};

FORCEINLINE uint32 GetTypeHash(const FMatchInfoAnalytics) { return 0; }
