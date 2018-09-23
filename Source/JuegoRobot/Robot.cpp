// Fill out your copyright notice in the Description page of Project Settings.

#include "Robot.h"
#include "Public/UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"


// Sets default values
ARobot::ARobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocidad = 600.0f;
	DistanceCamera = 500.0f;
	VelocidadCorrer = 1200.0f;
	VelocidadCaminar = 800.0f;




	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Origen"));
	Cuerpo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cuerpo"));
	Cuerpo->SetupAttachment(RootComponent);
	Cuerpo->SetRelativeLocation(FVector(0.0f, 0.0f, 107.5f));
	Cuerpo->SetWorldScale3D(FVector(0.75f, 1.0f, 0.75f));
	
	Cabeza = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cabeza"));
	Cabeza->SetupAttachment(RootComponent);
	Cabeza->SetRelativeLocation(FVector(0.0f, 0.0f, 197.5f));
	Cabeza->SetWorldScale3D(FVector(0.5f, 0.75f, 0.45f));

	ManoDerecha = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ManoDerecha"));
	ManoDerecha->SetupAttachment(RootComponent);
	ManoDerecha->SetRelativeLocation(FVector(0.0f, 100.0f, 112.5f));
	ManoDerecha->SetWorldScale3D(FVector(0.4f, 0.25f, 0.35f));

	ManoIzquierda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ManoIzquierda"));
	ManoIzquierda->SetupAttachment(RootComponent);
	ManoIzquierda->SetRelativeLocation(FVector(0.0f, -100.0f, 112.5f));
	ManoIzquierda->SetWorldScale3D(FVector(0.4f, 0.25f, 0.35f));

	PieDerecho = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PieDerecho"));
	PieDerecho->SetupAttachment(RootComponent);
	PieDerecho->SetRelativeLocation(FVector(0.0f, 27.5f, 12.5f));
	PieDerecho->SetWorldScale3D(FVector(0.7f, 0.45f, 0.25f));

	PieIzquierdo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PieIzquierdo"));
	PieIzquierdo->SetupAttachment(RootComponent);
	PieIzquierdo->SetRelativeLocation(FVector(0.0f, -27.5f, 12.5f));
	PieIzquierdo->SetWorldScale3D(FVector(0.7f, 0.45f, 0.25f));

	Camara = CreateDefaultSubobject<UCameraComponent>(TEXT("Camara"));
	Camara->SetupAttachment(RootComponent);
	Camara->SetRelativeLocation(FVector(-350.0f, 0.0f, 425.0f));
	Camara->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f));




	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/JuegoRobot/Materials/RobotMaterial.RobotMaterial'"));

	if (MeshAsset.Succeeded()) // Comprobando que el mesh haya sido encontrado
	{ 
		Cuerpo->SetStaticMesh(MeshAsset.Object); // asignado el mesh encontrado como mesh del componente Cuerpo 
		Cabeza->SetStaticMesh(MeshAsset.Object); // en este caso usaremos el mismo mesh del cuerpo para la cabeza
		ManoDerecha->SetStaticMesh(MeshAsset.Object);
		ManoIzquierda->SetStaticMesh(MeshAsset.Object);
		PieDerecho->SetStaticMesh(MeshAsset.Object);
		PieIzquierdo->SetStaticMesh(MeshAsset.Object);


		if (MaterialAsset.Succeeded()) // Comprobando que el material haya sido encontrado
		{ 
			Cuerpo->SetMaterial(0, MaterialAsset.Object); // asignando em material encontrado como material para el mesn del Cupepo
			Cabeza->SetMaterial(0, MaterialAsset.Object); // usaremos el mismo material que el cuperpo
			ManoDerecha->SetMaterial(0, MaterialAsset.Object);
			ManoIzquierda->SetMaterial(0, MaterialAsset.Object);
			PieDerecho->SetMaterial(0, MaterialAsset.Object);
			PieIzquierdo->SetMaterial(0, MaterialAsset.Object);

		}
	}


	

}

// Called when the game starts or when spawned
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//float MX = InputComponent->GetAxisValue("MoveForward");
	//float MY = InputComponent->GetAxisValue("MoveRight");

	if (!Movimiento.IsZero())
	{
		FVector Desplazamiento = GetActorForwardVector() * Movimiento.X + GetActorRightVector() * Movimiento.Y;
		FVector NewLocation = GetActorLocation() + Desplazamiento.GetSafeNormal() * Velocidad * DeltaTime;
		SetActorLocation(NewLocation);
	}

	float RYaw = GetInputAxisValue("RotateYaw");

	if (RYaw)
	{
		FRotator NewRotator = GetActorRotation();
		NewRotator.Yaw += RYaw;
		SetActorRotation(NewRotator);
	}


}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &ARobot::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARobot::MoveRight);
	InputComponent->BindAxis("RotateYaw");
	InputComponent->BindAxis("RotatePitch", this, &ARobot::RotatePitch);
	InputComponent->BindAction("Correr", IE_Pressed, this, &ARobot::Correr);
	InputComponent->BindAction("Correr", IE_Released, this, &ARobot::Caminar);

}

void ARobot::MoveForward(float AxisValue)
{
	Movimiento.X = AxisValue;
}

void ARobot::MoveRight(float AxisValue)
{
	Movimiento.Y = AxisValue;
}

void ARobot::RotatePitch(float AxisValue)
{


	if (AxisValue)
	{
		FRotator NewRotationCamara = Camara->GetRelativeTransform().GetRotation().Rotator();
		NewRotationCamara.Pitch = FMath::Clamp(NewRotationCamara.Pitch + AxisValue, -85.0f, 5.0f);
		Camara->SetRelativeRotation(NewRotationCamara);
		FVector NewLocationCamara = FVector::ZeroVector;
		NewLocationCamara.X = -DistanceCamera * FMath::Cos(FMath::DegreesToRadians(Camara->GetComponentRotation().Pitch));
		NewLocationCamara.Z = -DistanceCamera * FMath::Sin(FMath::DegreesToRadians(Camara->GetComponentRotation().Pitch)) + 185.0f;
		Camara->SetRelativeLocation(NewLocationCamara);

	}


}

void ARobot::Caminar()
{
	Velocidad = VelocidadCaminar;

}

void ARobot::Correr()
{
	UE_LOG(LogClass, Log, TEXT("Corriendo"));

	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(-1,2.0f,FColor::Blue,TEXT("Corriendo"));
	}

	Velocidad = VelocidadCorrer;
}

