//Стратегия, в которой есть разные фракции (народности). Фракции отличаются цветом, видом строений, юнитов и пр.
// к примеру Fraction1 живут в живопином лесу, Fraction2 живут в горах

/////// Реализация метода абстрактная фабрика ///////

/////////////////////
///   Factory.h   ///
/////////////////////

#include "House.h"
#include "Unit.h"
#include "Factory.generated.h"

class AFactory : public AActor
{
public:
	virtual House* CreateHouse() PURE_VIRTUAL(AFactory::CreateHouse, return nullptr;);
	virtual Unit* CreateUnit() PURE_VIRTUAL(AFactory::CreateUnit, return nullptr;);
protected:
	void* GetInfoHouse(Uclass* HouseClass);
	void* GetInfoUnit(Uclass* UnitClass);
};

class AFraction1_Factory : public AFactory
{
public:
	House* CreateHouse() override;
	Unit* CreateUnit() override;
};
inline House* CreateHouse()
{
	auto House = dynamic_cast<AHouse*>(GetWorld()->SpawnActor(AFraction1_House::StaticClass()));
	if (House)
	{
		House->SetupInfoHouse(GetInfoHouse(AFraction1_House::StaticClass()));
	}
}
inline Unit* CreateUnit()
{
	auto Unit = dynamic_cast<AUnit*>(GetWorld()->SpawnActor(AFraction1_Unit::StaticClass()));
	if (Unit)
	{
		Unit->SetupInfoUnit(GetInfoUnit(AFraction1_Unit::StaticClass()));
	}
}

class AFraction2_Factory : public AFactory
{
public:
	House* CreateHouse() override;
	Unit* CreateUnit() override;
};
inline House* CreateHouse()
{
	auto House = dynamic_cast<AHouse*>(GetWorld()->SpawnActor(AFraction2_House::StaticClass()));
	if (House)
	{
		House->SetupInfoHouse(GetInfoHouse(AFraction2_House::StaticClass()));
	}
}
inline Unit* CreateUnit()
{
	auto Unit = dynamic_cast<AUnit*>(GetWorld()->SpawnActor(AFraction2_Unit::StaticClass()));
	if (Unit)
	{
		Unit->SetupInfoUnit(GetInfoUnit(AFraction2_Unit::StaticClass()));
	}
}

///////////////////
///   House.h   ///
///////////////////
#include "Types.h"
#include "House.generated.h"

class AHouse : public AActor
{
public:
	virtual void SetupInfoHouse(void InfoPtr);
private:
	UStaticMesh* HouseMesh{ nullptr };
};

class AFraction1_House : public AHouse, private FHouses
{
	void SetupInfoHouse(void InfoPtr) override;
};
inline void AFraction1_House::SetupInfoHouse(void InfoPtr)
{
	auto House = dynamic_cast<FHouses*>(InfoPtr);
	if (House)
	{
		TypeHouse = House->TypeHouse;
		Durability = House->Durability;
	}
}

class AFraction2_House : public AHouse, private FHouses
{
	void SetupInfoHouse(void InfoPtr) override;
};
inline void AFraction2_House::SetupInfoHouse(void InfoPtr)
{
	auto House = dynamic_cast<FHouses*>(InfoPtr);
	if (House)
	{
		TypeHouse = House->TypeHouse;
		Durability = House->Durability;
	}
}

//////////////////
///   Unit.h   ///
//////////////////
#include "Types.h"
#include "Unit.generated.h"

class AUnit : public AActor
{
public:
	virtual void SetupInfoUnit(void InfoPtr);
private:
	USkeletalMesh* UnitMesh{ nullptr };
};

class AFraction1_Unit : public AUnit, private FUnits
{
	void SetupInfoUnit(void InfoPtr) override;
};
inline void AFraction1_Unit::SetupInfoUnit(void InfoPtr)
{
	auto Unit = dynamic_cast<FUnits*>(InfoPtr);
	if (Unit)
	{
		TypeUnit = Unit->TypeUnit;
		Durability = Unit->Durability;
		Damage = Unit->Damage;
	}
}
class AFraction2_Unit : public AUnit, private FUnits
{
	void SetupInfoUnit(void InfoPtr) override;
};
inline void AFraction2_Unit::SetupInfoUnit(void InfoPtr)
{
	auto Unit = dynamic_cast<FUnits*>(InfoPtr);
	if (Unit)
	{
		TypeUnit = Unit->TypeUnit;
		Durability = Unit->Durability;
		Damage = Unit->Damage;
	}
}

///////////////////
///   Types.h   ///
///////////////////

struct FHouses
{
	int TypeHouse{ 0 };  // тип здания (0- жилой дом, 1- оружейная, 2- тренировочный лагерь и тд.
	int Durability{ 0 };
};

struct FUnits
{
	int TypeUnit{ 0 };  // тип здания (0- копейщики, 1- лучники, 2- строители и тд.
	int Durability{ 0 };  //количество человечков в одном юните
	int Damage{ 0 };
};

/////// Реализация метода Строитель ///////

///////////////////////////
///   GenerateBases.h   ///
///////////////////////////

#include "GenerateBases.generated.h"

class UGenerateBases : public UInterface
{

};
class IGenerateBases
{
	virtual UObject* GetResult() const PURE_VIRTUAL(IGenerateBases::GetResult, return nullptr;);
	virtual void GenerateGrounds() PURE_VIRTUAL(IGenerateBases::GenerateTrees, );
	virtual void GenerateHouses() PURE_VIRTUAL(IGenerateBases::GenerateHouses, );
	virtual void GenerateWalls() PURE_VIRTUAL(IGenerateBases::GenerateWalls, );
};

class UFraction1_Generator : public UObject, public IGenerateBases
{
public:
	UObject* GetResult() const override;
	void GenerateGrounds() override;
	void GenerateHouses() override;
	void GenerateWalls() override;
protected:
	void SpawnRootBase();
	void SpawnGrass();
	void SpawnTrees();
	void SpawnRivers();
	void SpawnHouses_1();
	void SpawnWalls_1();
private:
	UPROPERTY()
	AActor* RootBase{ nullptr };
};
inline UObject UFraction1_Generator::GetResult() const
{
	return RootBase;
}
inline void UFraction1_Generator::GenerateGrounds()
{
	SpawnRootBase();
	SpawnGrass();
	SpawnTrees();
	SpawnRivers();
}
inline void UFraction1_Generator::GenerateHouses()
{
	SpawnHouses_1();
}
inline void UFraction1_Generator::GenerateWalls()
{
	SpawnWalls_1();
}

class UFraction2_Generator : public UObject, public IGenerateBases
{
public:
	UObject* GetResult() const override;
	void GenerateGrounds() override;
	void GenerateHouses() override;
	void GenerateWalls() override;
protected:
	void SpawnRootBase();
	void SpawnStone();
	void SpawnBush();
	void SpawnRivers();
	void SpawnHouses_2();
	void SpawnWalls_2();
private:
	UPROPERTY()
	AActor* RootBase{ nullptr };
};
inline UObject UFraction2_Generator::GetResult() const
{
	return RootBase;
}
inline void UFraction2_Generator::GenerateGrounds()
{
	SpawnRootBase();
	SpawnStone();
	SpawnBush();
	SpawnRivers();
}
inline void UFraction2_Generator::GenerateHouses()
{
	SpawnHouses_2();
}

////////////////////////////////
///   GenerationDirector.h   ///
////////////////////////////////

#iclude "GenerateBases.h"
#include "GenerationDirector.generated.h"

class UGenerationDirector : public UBlueprintFunctionLibrary
{
public:
	static void GenerateFraction1_Base(IGenerateBases* Generator);
	static void GenerateFraction2_Base(IGenerateBases* Generator);
};
inline void UGenerationDirector::GenerateFraction1_Base(IGenerateBases* Generator)
{
	if (Generator)
	{
		Generator->GenerateGrounds();
		Generator->GenerateHouses();
		Generator->GenerateWalls();
	}
}
inline void UGenerationDirector::GenerateFraction2_Base(IGenerateBases* Generator)
{
	if (Generator)
	{
		Generator->GenerateGrounds();
		Generator->GenerateHouses();
	}
}

//////////////////////////
///   MapGenerator.h   ///
//////////////////////////

class AMapGenerator : public AActor
{
public:
	void GenerateMap();
private:
	UPROPERTY()
	TArray<AActor*> Fractions;
};
template<class T>
IGenerateBases* CastToGenerateBases(T* Object)
{
	class UGenerateBases; public UInterface
		return static_cast<IGenerateBases>(Object->GetInterfaceAddress(UGenerateBases::StaticClass()));
}
inline void AMapGenerator::GenerateMap
{
	auto Fraction1Generator = NewObject<UFraction1_Generator>(this);
	auto IGenerator1 = CastToGenerateBases(Fraction1Generator);
	UGenerationDirector::GenerateFraction1_Base(IGenerator1);
	Fractions.Emplace(Fraction1Generator->GetResult());

	auto Fraction2Generator = NewObject<UFraction2_Generator>(this);
	auto IGenerator2 = CastToGenerateBases(Fraction2Generator);
	UGenerationDirector::GenerateFraction2_Base(IGenerator2);
	Fractions.Emplace(Fraction2Generator->GetResult());
}

/////// Реализация метода Прототип ///////

//////////////////////
///   CanClone.h   ///
//////////////////////

class UCanClone : public UInterface
{

};
class ICanClone
{
	virtual void* Clone() PURE_VIRTUAL(ICanClone::Clone, return nullptr;);
};

///////////////////
///   Quest.h   ///
///////////////////

class UQuest : public UObject, public ICanClone
{
public:
	void* Clone() override;
	bool GetIsrepeatable()
	{
		return Isrepeatable;
	}
	float GetTimer()
	{
		return Timer;
	}
private:
	bool Isrepeatable{ true };
	float Timer{ 0 };
};
inline void* UQuest::Clone()
{
	auto Copy = NewObject<UQuest>(GetOuter());
	if (Copy)
	{
		Copy->Isrepeatable = GetIsrepeatable();
		Copy->Timer = GetTimer();
	}
	return Copy;
}

/////// Реализация метода Одиночка ///////

//////////////////////
///   DataManager.h   ///
//////////////////////

class UDataBase : public UObject
{
public:
	static UDataBase* Get();
	int GetGold();
	int GetStone();
	int GetWood();
private:
	static UDataBase* Instance;
};
inline UDataBase* UDataBase::Get()
{
	if (Instance)
	{
		Instance = NewObject<UDataBase>();
	}
	return Instance;
}
