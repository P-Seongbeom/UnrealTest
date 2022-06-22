// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UNREALTEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)//툴에서 노출시키기
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = BattleStat)//툴에서 수치 변경 가능
	int32 Hp;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Mp;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	float RotateSpeed = 30.f;
};
