#pragma once

#include "CoreMinimal.h"
#include "BaseStat.h"
#include "DBDTunableRowHandle.h"
#include "TunableStat.generated.h"

USTRUCT(BlueprintType)
struct FTunableStat: public FBaseStat
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDBDTunableRowHandle _baseValue;

public:
	STATSYSTEM_API FTunableStat();
};

FORCEINLINE uint32 GetTypeHash(const FTunableStat) { return 0; }
