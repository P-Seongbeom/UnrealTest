// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefault�� ����ؼ� UStaticMeshComponent�� �޸𸮸� �ڵ������� ����
	//Mesh �ؿ� �ִ� Hp, Mp�� ���� �ȵ�
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));

	RootComponent = Mesh;

	//MyActor�� ������ �ѷ��� �ε��� �ѹ��� �ص� �Ǵϱ� static
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	//StaticMesh ��ο��� ���������� ã���� Mesh���ٰ� StaticMesh�� ���� ������
	//�ڵ�󿡼� ���� ������ Mesh�� �⺻������ ���´�.
	//�Ŀ� ������ �����ϸ� ������ ������ ��� �ٲ��.
	if (StaticMesh.Succeeded())
	{
		Mesh->SetStaticMesh(StaticMesh.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
