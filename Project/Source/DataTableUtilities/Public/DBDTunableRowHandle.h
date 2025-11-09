#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DBDTunableRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FDBDTunableRowHandle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDataTableRowHandle _dataTableRowHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _defaultValue;

public:
	DATATABLEUTILITIES_API FDBDTunableRowHandle();
};

FORCEINLINE uint32 GetTypeHash(const FDBDTunableRowHandle) { return 0; }
