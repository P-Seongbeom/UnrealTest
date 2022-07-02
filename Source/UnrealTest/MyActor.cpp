// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefault를 사용해서 UStaticMeshComponent의 메모리를 자동적으로 관리
	//Mesh 밑에 있는 Hp, Mp는 관리 안됨
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));

	RootComponent = Mesh;

	//MyActor를 여러번 뿌려도 로딩은 한번만 해도 되니까 static
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	//StaticMesh 경로에서 성공적으로 찾으면 Mesh에다가 StaticMesh를 덮어 씌워줌
	//코드상에서 먼저 세팅한 Mesh가 기본적으로 나온다.
	//후에 툴에서 변경하면 툴에서 변경한 대로 바뀐다.
	if (StaticMesh.Succeeded())
	{
		Mesh->SetStaticMesh(StaticMesh.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//카테고리, 로깅 수준, 형식, 인자
	//카테고리에따라서만 로그를 찾아보고 할 수 있음, 일부 카테고리는 파일로 저장도 됨
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 123);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);
	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}

