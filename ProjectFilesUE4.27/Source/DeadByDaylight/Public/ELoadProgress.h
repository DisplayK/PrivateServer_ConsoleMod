#pragma once

#include "CoreMinimal.h"
#include "ELoadProgress.generated.h"

UENUM(BlueprintType)
enum class ELoadProgress : uint8
{
	NotStarted,
	Init,
	SetupPIE,
	ArtificialDelay,
	DisconnectingPresencePlugin,
	ValidateOnlineSubsystem,
	CheckingPlatformService,
	PreMirrorsLogin,
	ConnectingToMirrors,
	StartEAC,
	LoadingAuthInfo,
	LoadingBackendConfigs,
	SetupRichPresence,
	LoadingBackendTunables,
	ApplyingCDNPatch,
	AquiringExternalAuthentication,
	LoadingPlayerIndependentShopData,
	LicenseCache,
	LoadingEvents,
	LoadingInventory,
	SyncingOwnedCharacters,
	LoadingProfile,
	LoadingMirrorCurrencies,
	LoadingWallet,
	LoadingConsent,
	LoadingGameConfigs,
	LoadingCharacterXPTables,
	CheckingPendingTransactions,
	LoadingContentSchedule,
	LoadingNews,
	SendingAnalytics,
	LoadingDailyRituals,
	CalculatingLatencies,
	ValidateData,
	ValidatingClientVersion,
	CheckingNeedForCurrencyMigration,
	MigratingCurrenciesToMirror,
	SyncingFriendsList,
	Complete,
	Locating,
	InitializingRTMConnection,
	LoadingStreamVideoData,
	CollectingFreeCatalogItems,
	DownloadDynamicContent,
	CheckingMobilePendingTransactions,
	LoadMarketingBanners,
	LoadingSubscriptionStatus,
	RequestingTrackingAuthorization,
	LoadingExperimentalFeatures,
	LoadingMatchIncentives,
	LoadingLoadoutPresets,
	LoadingBackendCharacterData,
	LoadingPrestige,
	UpdatingOwnedContent,
	LoadingShrine,
	LoadingGameConfigsDS,
	LoadingCatalog,
	LoadingS3PrestigeData,
};
