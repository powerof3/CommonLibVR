#pragma once
#include <cstdint>

namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			// VTable: .?AUActivateHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F22E8;	 // VR 1_4_15
		}


		namespace ActiveEffect
		{
			// IndirectSig: E8 ? ? ? ? 48 85 DB 75 C9
			constexpr std::uintptr_t Dispell = 0x00541100;	// VR 1_4_15
		}


		namespace Actor
		{
			// IndirectSig: E8 ? ? ? ? 0F B6 F0 49 8D 4E 30
			constexpr std::uintptr_t AddSpell = 0x00638430;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 49 8B D5 49 8B 8D ? ? ? ?
			constexpr std::uintptr_t DispelWornItemEnchantments = 0x0055CCB0;  // VR 1_4_15
			// DirectSig: 40 55 56 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 0F B6 DA 48 8B F1
			constexpr std::uintptr_t DoReset3D = 0x0069C710;  // VR 1_4_15
			// DirectSig: 40 55 56 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 0F B6 DA 48 8B F1
			constexpr std::uintptr_t Decapitate = 0x005FAC70;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CD E8 ? ? ? ? 85 C0 74 0B
			constexpr std::uintptr_t EvaluatePackage = 0x005E3990;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 49 0F 45 F4
			constexpr std::uintptr_t GetGhost = 0x005DAAE0;	 // VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F2 48 8B D9 40 32 FF
			constexpr std::uintptr_t GetHostileToActor = 0x005F0560;  // VR 1_4_15
			// DirectSig: 48 8B 49 40 48 83 C1 30 E9 ? ? ? ?
			constexpr std::uintptr_t GetLevel = 0x005DE910;	 // VR 1_4_15
			//
			constexpr std::uintptr_t GetSoulLevel = 0x0063D770;	 // VR 1_4_15
			// DirectSig: 48 83 EC 28 48 8B 81 ? ? ? ? 48 85 C0 74 16
			constexpr std::uintptr_t HasPerk = 0x006025A0;	// VR 1_4_15
			//
			constexpr std::uintptr_t HasSpell = 0x0063BBE0;	 // VR 1_4_15
			//
			constexpr std::uintptr_t InstantKill = 0x00603E30;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CF 0F B6 E8
			constexpr std::uintptr_t IsRunning = 0x005D9770;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 85 C0 7E 2D
			constexpr std::uintptr_t RequestDetectionLevel = 0x00605190;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 1D 8B 4D 7F
			constexpr std::uintptr_t StealAlarm = 0x005E5DC0;  // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 41 56 48 83 EC 40
			constexpr std::uintptr_t SwitchRace = 0x00610000;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 89 7D D8 48 8D 55 D8
			constexpr std::uintptr_t UpdateArmorAbility = 0x0063A230;  // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 6C 24 ? 56 57
			constexpr std::uintptr_t UpdateWeaponAbility = 0x0063A2A0;	// VR 1_4_15
			// VTable: .?AVActor@@
			constexpr std::uintptr_t Vtbl = 0x016CE888;	 // VR 1_4_15
		}


		namespace ActorEquipManager
		{
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 57 48 83 EC 50 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			constexpr std::uintptr_t EquipObject = 0x00640A90;	// VR 1_4_15
			// 88 4C 24 30 48 8B 0D ? ? ? ? 48 C7 44 24 ? ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02F896D8;  // VR
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 94 C0 33 F6
			constexpr std::uintptr_t UnequipObject = 0x006411A0;  // VR 1_4_15
		}


		namespace ActorValueOwner
		{
			// IndirectSig: E8 ? ? ? ? F3 44 0F 2C C0
			constexpr std::uintptr_t GetClampedActorValue = 0x003F4DA0;	 // VR 1_4_15
		}


		namespace ActorValueList
		{
			constexpr std::uintptr_t Singleton = 0x01F82AC8;  // VR 1_4_15
		}


		namespace AIProcess
		{
			constexpr std::uintptr_t SetActorRefraction = 0x0068A230;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 0F 28 C7 0F 28 7C 24 ?
			constexpr std::uintptr_t SetBaseScale = 0x00665BD0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 8B 4F 08
			constexpr std::uintptr_t Update3DModel = 0x0065A140;  // VR 1_4_15
		}


		namespace AttackBlockHandler
		{
			// VTable: .?AUAttackBlockHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2258;	 // VR 1_4_15
		}


		namespace AutoMoveHandler
		{
			// VTable: .?AUAutoMoveHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2338;	 // VR 1_4_15
		}


		namespace BGSDefaultObjectManager
		{
			// IndirectSig: E8 ? ? ? ? 4C 63 C3
			constexpr std::uintptr_t GetSingleton = 0x0001077C0;  // VR 1_4_15
		}


		namespace BGSFootstepManager
		{
			// E8 ? ? ? ? 90 48 89 1D ? ? ? ? 48 8D 0D ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02FEBC50;  // VR 1_4_15
		}


		namespace BGSListForm
		{
			// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 48 83 7B ? ? 75 5E
			constexpr std::uintptr_t AddForm = 0x002D6B40;	// VR 1_4_15
		}


		namespace BGSSaveLoadManager
		{
			// DirectSig: 44 89 44 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ?
			constexpr std::uintptr_t Save = 0x0058E310;	 // VR 1_4_15
			// 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 81 C1 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02FEB248;  // VR 1_4_15
			// DirectSig: 48 8B C4 48 89 58 10 57 48 81 EC ? ? ? ? 48 8B DA 66 C7 40 ? ? ?
			constexpr std::uintptr_t Load = 0x0058E920;	 // VR 1_4_15
		}


		namespace BGSStoryTeller
		{
			// DirectSig: 40 56 57 41 56 48 83 EC 40 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 8B FA 48 8B E9 44 8B 05 ? ? ? ? 65 48 8B 04 25 ? ? ? ? B9 ? ? ? ? 4A 8B 34 C0 48 03 F1 8B 1E 89 5C 24 68
			constexpr std::uintptr_t BeginShutDownQuest = 0x004E8240;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 35 ? ? ? ? 40 84 F6
			constexpr std::uintptr_t BeginStartUpQuest = 0x004E8120;  // VR 1_4_15
			// 48 8B 0D ? ? ? ? 48 8B D3 45 84 C0
			constexpr std::uintptr_t Singleton = 0x01EC3B80;  // 1_5_97
		}


		namespace BGSWaterSystemManager
		{
			constexpr std::uintptr_t CreateBulletWaterDisplacement = 0x004D8A40;  // VR 1_4_15
			constexpr std::uintptr_t Singleton = 0x01F85120;					  // VR 1_4_15
		}


		namespace BipedAnim
		{
			// IndirectSig: E8 ? ? ? ? BA ? ? ? ? 48 8B CF E8 ? ? ? ? 48 8B 5C 24 ? EB 76
			constexpr std::uintptr_t Dtor = 0x001D6200;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 48 8D 8B ? ? ? ? 4C 8D 0D ? ? ? ? BA ? ? ? ? 44 8D 42 B2
			constexpr std::uintptr_t RemoveAllParts = 0x001D6530;  // VR 1_4_15
		}


		namespace BSAudioManager
		{
			// IndirectSig: E8 ? ? ? ? BA 33 00 00 00
			constexpr std::uintptr_t GetSingleton = 0x00C29430;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? C6 46 04 01
			constexpr std::uintptr_t BuildSoundDataFromDescriptor = 0x00C29F60;	 // VR 1_4_15
			constexpr std::uintptr_t BuildSoundDataFromEditorID = 0x00C29ED0;	 // VR 1_4_15
		}


		namespace BSFixedString
		{
			// IndirectSig: E8 ? ? ? ? 83 CD 01
			constexpr std::uintptr_t Ctor_CStr = 0x00C6DB20;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 89 7D 98
			constexpr std::uintptr_t Ctor_Copy = 0x00C6DBB0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 01 5F 1C
			constexpr std::uintptr_t Set_CStr = 0x00C6DC90;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F7 DF
			constexpr std::uintptr_t Set_Copy = 0x00C6DD50;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 94
			constexpr std::uintptr_t Dtor = 0x00C6DC70;	 // VR 1_4_15
		}


		namespace BSFixedStringW
		{
			// DirectSig: 40 53 48 83 EC 20 48 C7 01 00 00 00 00 4C 8B DA
			constexpr std::uintptr_t Ctor = 0x00C6E440;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 45 C8 48 8D 55 D8
			constexpr std::uintptr_t Dtor = 0x00C6E550;	 // VR 1_4_15
		}


		namespace BSInputDeviceManager
		{
			// 74 0D 48 83 C0 A8
			constexpr std::uintptr_t Singleton = 0x02FEA520;  // VR
		}


		namespace BSLightingShaderMaterialBase
		{
			constexpr std::uintptr_t Ctor = 0x0130DC60;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterial
		{
			constexpr std::uintptr_t Vtbl = 0x016900D8;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialEnvmap
		{
			constexpr std::uintptr_t Ctor = 0x0130F0B0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialEye
		{
			constexpr std::uintptr_t Ctor = 0x0130F760;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialFacegen
		{
			constexpr std::uintptr_t Ctor = 0x01310E80;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialFacegenTint
		{
			constexpr std::uintptr_t Ctor = 0x013115A0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialGlowmap
		{
			constexpr std::uintptr_t Ctor = 0x0130FF20;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialHairTint
		{
			constexpr std::uintptr_t Ctor = 0x013117C0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialMultiLayerParallax
		{
			constexpr std::uintptr_t Ctor = 0x013129E0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialLandscape
		{
			constexpr std::uintptr_t Ctor = 0x013119D0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialLODLandscape
		{
			constexpr std::uintptr_t Ctor = 0x01312270;	 // VR 1_4_15;
		}


		namespace BSLightingShaderMaterialParallax
		{
			constexpr std::uintptr_t Ctor = 0x013103C0;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialParallaxOcc
		{
			constexpr std::uintptr_t Ctor = 0x01310860;	 // VR 1_4_15
		}


		namespace BSLightingShaderMaterialSnow
		{
			constexpr std::uintptr_t Ctor = 0x01312800;	 // VR 1_4_15
		}


		namespace BSLightingShaderProperty
		{
			constexpr std::uintptr_t InvalidateTextures = 0x01303EA0;  // VR 1_4_15
		}


		namespace BSReadWriteLock
		{
			// IndirectSig: E8 ? ? ? ? 4D 8B 27
			constexpr std::uintptr_t LockForRead = 0x00C42150;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 40 88 77 2C
			constexpr std::uintptr_t LockForWrite = 0x00C421D0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 EB 2E
			constexpr std::uintptr_t UnlockForRead = 0x00C42410;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 56 14
			constexpr std::uintptr_t UnlockForWrite = 0x00C42420;  // VR 1_4_15
		}


		namespace BSResourceNiBinaryStream
		{
			// DirectSig: 48 89 4C 24 ? 57 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			constexpr std::uintptr_t Ctor = 0x00CBC490;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 84 24 ? ? ? ? 89 07
			constexpr std::uintptr_t Dtor = 0x00CBC770;	 // VR 1_4_15
			// DirectSig: 48 83 79 ? ? 4C 8B C9
			constexpr std::uintptr_t Seek = 0x00CBC8C0;	 // VR 1_4_15
			// ??_7BSResourceNiBinaryStream@@6B@ + 0x5
			constexpr std::uintptr_t SetEndianSwap = 0x00CBC9B0;  // VR 1_4_15
		}


		namespace BSScaleformManager
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 74 50 48 8B 4F 10
			constexpr std::uintptr_t LoadMovie = 0x00F2B480;  // VR 1_4_15
			// 48 89 0D ? ? ? ? 4C 89 79 18
			constexpr std::uintptr_t Singleton = 0x02FEA518;  // VR
		}


		namespace BSScaleformTranslator
		{
			// VTable: .?AVBSScaleformTranslator@@
			constexpr std::uintptr_t Vtbl = 0x01866FA0;	 // VR 1_4_15
		}


		namespace BSScript
		{
			namespace Object
			{
				// IndirectSig: E8 ? ? ? ? 49 8B CE E8 ? ? ? ? 48 85 DB 74 08
				constexpr std::uintptr_t Dtor = 0x0126BB20;	 // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 49 89 3F
				constexpr std::uintptr_t IncRef = 0x0126C810;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 85 C0 75 10 49 8B CE
				constexpr std::uintptr_t DecRef = 0x0126C8C0;  // VR 1_4_15
			}


			namespace ObjectTypeInfo
			{
				// IndirectSig: E8 ? ? ? ? 90 48 8D 4B 18 E8 ? ? ? ? 90 48 8B 4B 10
				constexpr std::uintptr_t ReleaseData = 0x01270B80;	// VR 1_4_15
			}


			namespace ObjectBindPolicy
			{
				// IndirectSig: E8 ? ? ? ? 80 BD ? ? ? ? ? 0F 84 ? ? ? ? 48 C7 44 24 ? ? ? ? ?
				constexpr std::uintptr_t BindObject = 0x01265F80;  // VR 1_4_15
			}


			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					// DirectSig: 48 8B C4 4C 89 48 20 4C 89 40 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 48 C7 44 24 ? ? ? ? ? 48 89 58 08
					constexpr std::uintptr_t Call = 0x0129DD90;	 // VR 1_4_15
				}
			}


			namespace Stack
			{
				// IndirectSig: E8 ? ? ? ? BA A0 00 00 00 49 8B CF
				constexpr std::uintptr_t Dtor = 0x0129A210;	 // VR 1_4_15
			}
		}


		namespace BSShaderProperty
		{
			constexpr std::uintptr_t InvalidateMaterial = 0x001AC0E0;  // VR 1_4_15
			constexpr std::uintptr_t SetFlags = 0x012CA540;			   // VR 1_4_15
			constexpr std::uintptr_t SetMaterial = 0x012CA650;		   // VR 1_4_15
		}


		namespace BSShaderTextureSet
		{
			constexpr std::uintptr_t Ctor = 0x01307710;	 // VR 1_4_15
		}


		namespace BSSoundHandle
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 75 5C 49 8B 85 ? ? ? ?
			constexpr std::uintptr_t IsValid = 0x00C28540;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 0E 84 C0
			constexpr std::uintptr_t Play = 0x00C283E0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F3 0F 10 5D 9F
			constexpr std::uintptr_t SetObjectToFollow = 0x00C289C0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8D 7E 20
			constexpr std::uintptr_t SetPosition = 0x00C287D0;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CE E8 ? ? ? ? E9 ? ? ? ? B9 ? ? ? ?
			constexpr std::uintptr_t Stop = 0x00C284B0;	 // VR 1_4_15
		}


		namespace BSString
		{
			// DirectSig: 40 57 41 54 41 55 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 41 8B F8
			constexpr std::uintptr_t Set_CStr = 0x00010A440;  // VR 1_4_15
		}


		namespace BSTaskPool
		{
			constexpr std::uintptr_t Singleton = 0x02FFD778;						 // VR 1_4_15
			constexpr std::uintptr_t ShouldUseTaskPool = 0x006488A0;				 // VR 1_4_15
			constexpr std::uintptr_t QueueBulletWaterDisplacementTask = 0x005CD7C0;	 // VR 1_4_15
		}


		namespace BSUntypedPointerHandle
		{
			// 8B 05 ? ? ? ? 89 44 24 78 48 8D 44 24 ? 8B 00
			constexpr std::uintptr_t NullHandle = 0x01F8319C;  // VR 1_4_15
		}


		namespace BucketTable
		{
			// IndirectSig: E8 ? ? ? ? 41 8B FE 41 8B CE
			constexpr std::uintptr_t GetSingleton = 0x00C6F400;	 // VR 1_4_15
		}


		namespace BSWin32SaveDataSystemUtility
		{
			// IndirectSig: E8 ? ? ? ? 4C 8B 18
			constexpr std::uintptr_t GetSingleton = 0x0137C200;	 // VR 1_4_15
		}


		namespace Calendar
		{
			//
			constexpr std::uintptr_t Singleton = 0x01F85108;  // VR
		}


		namespace ChestsLooted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 51
			constexpr std::uintptr_t GetEventSource = 0x0088D4E0;  // VR 1_4_15
		}


		namespace Console
		{
			// 48 8D 0D ? ? ? ? E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 45 33 C9 45 33 C0 BA ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 89 44 24 ?
			constexpr std::uintptr_t SelectedRef = 0x02F4C31C;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? BE 02 00 00 00 8B C6
			constexpr std::uintptr_t SetSelectedRef = 0x008864D0;  // VR 1_4_15
		}


		namespace ConsoleLog
		{
			// E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02FC4FE0;  // VR
			// DirectSig: 48 8B C4 57 41 54 41 55 41 56 41 57 48 83 EC 40 48 C7 40 ? ? ? ? ? 48 89 58 10 48 89 68 18 48 89 70 20 4D 8B F8 4C 8B E2
			constexpr std::uintptr_t VPrint = 0x00886DF0;  // VR 1_4_15
		}


		namespace ControlMap
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 8B 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02EC5BD0;  // 1_5_97
		}


		namespace CRC32Calculator
		{
			// IndirectSig: E8 ? ? ? ? 8B 75 AB
			constexpr std::uintptr_t SizeOf32 = 0x00C41370;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B 5D C0
			constexpr std::uintptr_t SizeOf64 = 0x00C413F0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B 9D B8 00 00 00
			constexpr std::uintptr_t SizeOfSize = 0x00C41310;  // VR 1_4_15
		}


		namespace DialogueItem
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 41 89 1E 48 8B C7 48 8B 5C 24 70
			constexpr std::uintptr_t Ctor = 0x00572FD0;	 // VR 1_4_15
		}


		namespace ExtraAliasInstanceArray
		{
			// VTable: .?AVExtraAliasInstanceArray@@
			constexpr std::uintptr_t Vtbl = 0x015A3CF0;	 // VR 1_4_15
		}


		namespace ExtraAshPileRef
		{
			// VTable: .?AVExtraAshPileRef@@
			constexpr std::uintptr_t Vtbl = 0x015A3630;	 // VR 1_4_15
		}


		namespace ExtraCannotWear
		{
			// VTable: .?AVExtraCannotWear@@
			constexpr std::uintptr_t Vtbl = 0x015A3390;	 // VR 1_4_15
		}


		namespace ExtraCanTalkToPlayer
		{
			// VTable: .?AVExtraCanTalkToPlayer@@
			constexpr std::uintptr_t Vtbl = 0x015A3A90;	 // VR 1_4_15
		}


		namespace ExtraCharge
		{
			// VTable: .?AVExtraCharge@@
			constexpr std::uintptr_t Vtbl = 0x015A3410;	 // VR 1_4_15
		}


		namespace ExtraContainerChanges
		{
			// VTable: .?AVExtraContainerChanges@@
			constexpr std::uintptr_t Vtbl = 0x015A65D0;	 // VR 1_4_15
		}


		namespace ExtraCount
		{
			// VTable: .?AVExtraCount@@
			constexpr std::uintptr_t Vtbl = 0x015A3330;	 // VR 1_4_15
		}


		namespace ExtraDataList
		{
			// IndirectSig: E8 ? ? ? ? 4C 8D 75 10
			constexpr std::uintptr_t Add = 0x00142140;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F7 43 28 FF 03 00 00 75 0C
			constexpr std::uintptr_t SetExtraFlags = 0x00136360;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 41 89 1E 48 8B C7 48 8B 5C 24 60 48 8B 6C 24 68 48 83 C4 30 41 5E
			constexpr std::uintptr_t SetInventoryChanges = 0x0011FBA0;	// VR 1_4_15
		}


		namespace ExtraEnchantment
		{
			// VTable: .?AVExtraEnchantment@@
			constexpr std::uintptr_t Vtbl = 0x015A37D0;	 // VR 1_4_15
		}


		namespace ExtraForcedTarget
		{
			// VTable: .?AVExtraForcedTarget@@
			constexpr std::uintptr_t Vtbl = 0x015A3EB0;	 // VR 1_4_15
		}


		namespace ExtraHealth
		{
			// VTable: .?AVExtraHealth@@
			constexpr std::uintptr_t Vtbl = 0x015A33B0;	 // VR 1_4_15
		}


		namespace ExtraHotkey
		{
			// VTable: .?AVExtraHotkey@@
			constexpr std::uintptr_t Vtbl = 0x015A3470;	 // VR 1_4_15
		}


		namespace ExtraLightData
		{
			// VTable: .?AVExtraLightData@@
			constexpr std::uintptr_t Vtbl = 0x015A3D50;	 // VR 1_4_15
		}


		namespace ExtraOwnership
		{
			// VTable: .?AVExtraOwnership@@
			constexpr std::uintptr_t Vtbl = 0x015A32D0;	 // VR 1_4_15
		}


		namespace ExtraPoison
		{
			// VTable: .?AVExtraPoison@@
			constexpr std::uintptr_t Vtbl = 0x015A37B0;	 // VR 1_4_15
		}


		namespace ExtraRank
		{
			// VTable: .?AVExtraRank@@
			constexpr std::uintptr_t Vtbl = 0x015A3310;	 // VR 1_4_15
		}


		namespace ExtraReferenceHandle
		{
			// VTable: .?AVExtraReferenceHandle@@
			constexpr std::uintptr_t Vtbl = 0x015A34B0;	 // VR 1_4_15
		}


		namespace ExtraSoul
		{
			// VTable: .?AVExtraSoul@@
			constexpr std::uintptr_t Vtbl = 0x015A6650;	 // VR 1_4_15
		}


		namespace ExtraTextDisplayData
		{
			// IndirectSig: E8 ? ? ? ? EB 08 48 8B 0F
			constexpr std::uintptr_t GenerateName = 0x0014D130;	 // VR 1_4_15
			// VTable: .?AVExtraTextDisplayData@@
			constexpr std::uintptr_t Vtbl = 0x015A3E30;	 // VR 1_4_15
		}


		namespace ExtraUniqueID
		{
			// VTable: .?AVExtraUniqueID@@
			constexpr std::uintptr_t Vtbl = 0x015A3EF0;	 // VR 1_4_15
		}


		namespace FaceGen
		{
			constexpr std::uintptr_t RegenerateHead = 0x003E23D0;  // VR 1_4_15
			constexpr std::uintptr_t Singleton = 0x01F83220;	   // VR 1_4_15
		}


		namespace FavoritesHandler
		{
			// VTable: .?AUFavoritesHandler@@
			constexpr std::uintptr_t Vtbl = 0x0173C9C0;	 // VR 1_4_15
		}


		namespace FavoritesMenu
		{
			// VTable: .?AVFavoritesMenu@@
			constexpr std::uintptr_t Vtbl = 0x01734F50;	 // VR 1_4_15
		}


		namespace FirstPersonState
		{
			// VTable: .?AVFirstPersonState@@
			constexpr std::uintptr_t Vtbl = 0x0172CEB0;	 // VR 1_4_15
		}


		namespace GameSettingCollection
		{
			// 48 83 3D ? ? ? ? ? 75 63
			constexpr std::uintptr_t Singleton = 0x02F8A780;  // VR
		}


		namespace GFxLoader
		{
			// DirectSig: 45 8B D0 48 8B C1
			constexpr std::uintptr_t CreateMovie = 0x00F38CA0;	// VR 1_4_15
		}


		namespace GFxMovieView
		{
			// IndirectSig: E8 ? ? ? ? C6 44 24 20 01 41 B9 03 00 00 00 44 8D 47 69
			constexpr std::uintptr_t InvokeNoReturn = 0x00F30F20;  // VR 1_4_15
		}


		namespace GFxValue
		{
			namespace ObjectInterface
			{
				// IndirectSig: E8 ? ? ? ? 4C 8D 45 F0 48 8B 54 24 ?
				constexpr std::uintptr_t AttachMovie = 0x00F24EF0;	// VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B D8 48 8B FA 48 8B F1 45 84 C9
				constexpr std::uintptr_t DeleteMember = 0x00F25FE0;	 // VR 1_4_15
				// DirectSig: 48 85 D2 74 04 8B 42 58
				constexpr std::uintptr_t GetArraySize = 0x00F26720;	 // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 66 83 8D ? ? ? ? ? F3 0F 10 05 ? ? ? ?
				constexpr std::uintptr_t GetDisplayInfo = 0x00F26770;  // VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 49 63 F0
				constexpr std::uintptr_t GetElement = 0x00F26A80;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 48 8B 4B 20 40 38 7D E8
				constexpr std::uintptr_t GetMember = 0x00F26CA0;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 4C 8D 0D ? ? ? ? E9 ? ? ? ? 4C 89 75 E8
				constexpr std::uintptr_t GotoAndPlay = 0x00F270C0;	// VR 1_4_15
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 60 49 8B D8
				constexpr std::uintptr_t HasMember = 0x00F27170;  // VR 1_4_15
				// DirectSig: 40 53 41 54 41 56 41 57 48 81 EC ? ? ? ?
				constexpr std::uintptr_t Invoke = 0x00F273B0;  // VR 1_4_15
				// DirectSig: 48 83 EC 28 8B 42 08 25 ? ? ? ?
				constexpr std::uintptr_t ObjectAddRef = 0x00F27BD0;	 // VR 1_4_15
				// DirectSig: 40 53 48 83 EC 20 8B 42 08
				constexpr std::uintptr_t ObjectRelease = 0x00F27C30;  // VR 1_4_15
				// DirectSig: 40 53 48 83 EC 40 49 8B C0
				constexpr std::uintptr_t PushBack = 0x00F27E50;	 // VR 1_4_15
				// DirectSig: 48 83 EC 28 45 8B D0
				constexpr std::uintptr_t RemoveElements = 0x00F28210;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 80 BE FE 03 03 00 00
				constexpr std::uintptr_t SetArraySize = 0x00F28870;	 // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 4C 89 B5 ? ? ? ? 4C 89 74 24 ?
				constexpr std::uintptr_t SetDisplayInfo = 0x00F28900;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? FF C3 48 83 C6 18
				constexpr std::uintptr_t SetElement = 0x00F294B0;  // VR 1_4_15
				// DirectSig: 48 89 6C 24 ? 56 57 41 56 48 83 EC 50 80 BC 24 ? ? ? ? ?
				constexpr std::uintptr_t SetMember = 0x00F296F0;  // VR 1_4_15
				// IndirectSig: E8 ? ? ? ? 8B 44 24 48 C1 E8 06 A8 01 74 19 4C 8B 44 24 ? 48 8D 54 24 ? 48 8B 4C 24 ? E8 ? ? ? ? 4C 89 6C 24 ?
				constexpr std::uintptr_t SetText = 0x00F29840;	// VR 1_4_15
			}
		}


		namespace GlobalLookupInfo
		{
			//
			constexpr std::uintptr_t Singleton = 0x01EC3CB0;  // 1_5_97
		}


		namespace GMemory
		{
			// GFxFunctionHandler::virt_dtor + 35
			constexpr std::uintptr_t GlobalHeap = 0x0318CE40;  // VR
		}


		namespace GString
		{
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 8B FA 4C 8B F1 48 85 D2 74 3B
			constexpr std::uintptr_t Ctor = 0x00F2DA40;	 // VR 1_4_15
		}


		namespace hkContainerHeapAllocator
		{
			// 48 8D 0D ? ? ? ? 48 8B 93 C8 00 00 00
			constexpr std::uintptr_t Singleton = 0x01DF5E70;  // 1_5_97
		}


		namespace hkReferencedObject
		{
			// DirectSig: 40 57 48 83 EC 20 66 83 79 ? ?
			constexpr std::uintptr_t AddReference = 0x00A01280;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 89 6E 18 EB 19
			constexpr std::uintptr_t RemoveReference = 0x00A01340;	// VR 1_4_15
		}


		namespace INIPrefSettingCollection
		{
			// 48 8D 4B 08 4C 3B C1 74 11 BA ? ? ? ? FF 15 ? ? ? ? EB 04 C6 43 08 00 48 8B 03 B2 01 48 8B CB FF 50 28 84 C0 74 18
			constexpr std::uintptr_t Singleton = 0x030C3B18;  // VR
		}


		namespace INISettingCollection
		{
			// 48 05 ? ? ? ? 74 4B
			constexpr std::uintptr_t Singleton = 0x03175FE0;  // VR
		}


		namespace InterfaceStrings
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 83 3D ? ? ? ? ? 75 20
			constexpr std::uintptr_t Singleton = 0x01F85100;  // VR 1_4_15
		}


		namespace Inventory
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? 49 8B 0F
			constexpr std::uintptr_t GetEventSource = 0x001FFE10;  // VR 1_4_15
		}


		namespace InventoryChanges
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B D7 48 8B CD
			constexpr std::uintptr_t Ctor = 0x001E9DA0;	 // VR 1_4_15
			// DirectSig: 40 57 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 4C 8B F9 4C 8B 31
			constexpr std::uintptr_t Dtor = 0x001E9E90;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 8B 44 24 68 41 89 06 48 83 C4 38
			constexpr std::uintptr_t GenerateLeveledListChanges = 0x001F1470;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 0F B7 F8
			constexpr std::uintptr_t GetNextUniqueID = 0x001FD8A0;	// VR 1_4_15
			//
			constexpr std::uintptr_t GetItemCount = 0x001F7ED0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 85 ED 74 3F
			constexpr std::uintptr_t SendContainerChangedEvent = 0x001FD990;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 80 BC 24 ? ? ? ? ? 74 0D
			constexpr std::uintptr_t SetUniqueID = 0x001FD7D0;	// VR 1_4_15
			// IndirectSig:
			constexpr std::uintptr_t TransferItemUID = 0x001FD990;	// VR 1_4_15
		}


		namespace InventoryEntryData
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 5B 08 44 8B F8
			constexpr std::uintptr_t GetValue = 0x001E7280;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 48 8B 3F
			constexpr std::uintptr_t IsOwnedBy = 0x001E8130;  // VR 1_4_15
		}


		namespace ItemCrafted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 55 B8 E8 ? ? ? ? 45 85 E4
			constexpr std::uintptr_t GetEventSource = 0x0089BE30;  // VR 1_4_15
		}


		namespace ItemList
		{
			// IndirectSig: E8 ? ? ? ? EB 4A 80 7D 1A 1B
			constexpr std::uintptr_t Update = 0x00880E10;  // VR 1_4_15
		}


		namespace ItemsPickpocketed
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? EB 7B
			constexpr std::uintptr_t GetEventSource = 0x0088D5D0;  // VR 1_4_15
		}


		namespace JournalMenu
		{
			// VTable: .?AVJournalMenu@@
			constexpr std::uintptr_t Vtbl = 0x0174E278;	 // VR 1_4_15
		}


		namespace JumpHandler
		{
			// VTable: .?AUJumpHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2408;	 // VR 1_4_15
		}


		namespace LocalMapCamera
		{
			// IndirectSig: E8 ? ? ? ? 90 33 F6 48 89 B3 ? ? ? ? 48 8D 8B ? ? ? ?
			constexpr std::uintptr_t Ctor = 0x00205EF0;	 // VR 1_4_15
			// DirectSig: 48 8B C4 53 48 81 EC ? ? ? ? 0F 28 05 ? ? ? ? 48 8B D9
			constexpr std::uintptr_t SetNorthRotation = 0x002062B0;	 // VR 1_4_15
		}


		namespace LookHandler
		{
			// VTable: .?AULookHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2070;	 // VR 1_4_15
		}


		namespace LooseFileStream
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 EB 02 33 FF 40 F6 C6 02 74 11
			constexpr std::uintptr_t Ctor = 0x00C90A40;	 // VR 1_4_15
		}


		namespace MagicFavorites
		{
			// 48 C7 05 ? ? ? ? ? ? ? ? 48 8B 5C 24 ? 48 83 C4 30 5F C3 CC 48 89 5C 24 ?
			constexpr std::uintptr_t Singleton = 0x02FEB238;  // VR
		}


		namespace MagicItem
		{
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? F3 0F 2C C0
			constexpr std::uintptr_t CalculateCost = 0x00111FE0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 85 C0 74 0C 48 8B 40 10
			constexpr std::uintptr_t GetCostliestEffectItem = 0x00112270;  // VR 1_4_15
		}


		namespace MagicTarget
		{
			// DirectSig: 48 89 5C 24 18 56 48 83 EC 20 48 8B 01 48 8B F2 FF 50 38
			constexpr std::uintptr_t HasMagicEffect = 0x00557380;  // VR 1_4_15
		}


		namespace Main
		{
			// 74 04 8B 40 28
			constexpr std::uintptr_t Singleton = 0x02FEB7A0;  // VR 1_4_15
		}


		namespace MemoryManager
		{
			// DirectSig: 48 89 5C 24 ? 55 57 41 54 41 55 41 57 48 83 EC 30 65 48 8B 04 25 ? ? ? ?
			constexpr std::uintptr_t Allocate = 0x00C3D0E0;	 // VR 1_4_15
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 5C 24 ? 48 89 54 24 ? 57 48 83 EC 20 80 39 00
			constexpr std::uintptr_t Deallocate = 0x00C3D3E0;  // VR 1_4_15
			// DirectSig: 40 53 48 83 EC 20 83 3D ? ? ? ? ? 74 1F
			constexpr std::uintptr_t GetSingleton = 0x00010D590;  // VR 1_4_15
			// DirectSig: 40 56 57 41 54 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 8B F1 33 ED
			constexpr std::uintptr_t GetThreadScrapHeap = 0x00C3C680;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 3B 77 48
			constexpr std::uintptr_t Reallocate = 0x00C3D330;  // VR 1_4_15
		}


		namespace MenuControls
		{
			// 48 89 2D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 01 48 8D 05 ? ? ? ? 48 89 41 08 48 8D 59 18
			constexpr std::uintptr_t Singleton = 0x02F003F8;  // 1_5_97
		}


		namespace MenuOpenHandler
		{
			// VTable: .?AUMenuOpenHandler@@
			constexpr std::uintptr_t Vtbl = 0x0173C970;	 // VR 1_4_15
		}


		namespace MessageDataFactoryManager
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 57 08
			constexpr std::uintptr_t GetSingleton = 0x00335CA0;	 // VR 1_4_15
		}


		namespace MovementHandler
		{
			// VTable: .?AUMovementHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F21C8;	 // VR 1_4_15
		}


		namespace NiAVObject
		{
			// IndirectSig: E8 ? ? ? ? 44 88 65 6F
			constexpr std::uintptr_t SetMotionType = 0x00DFD160;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB 09 48 8B CB E8 ? ? ? ? 90 48 8B 8C 24 ? ? ? ?
			constexpr std::uintptr_t Update = 0x00C9BC10;  // VR 1_4_15
		}


		namespace NiBooleanExtraData
		{
			constexpr std::uintptr_t Vtbl = 0x017F5220;	 //VR 1_4_15
		}


		namespace NiCamera
		{
			// DirectSig: 48 83 EC 18 F3 41 0F 10 60 04
			constexpr std::uintptr_t WorldPtToScreenPt3 = 0x00CAC0E0;  // VR 1_4_15
		}


		namespace NiFloatExtraData
		{
			constexpr std::uintptr_t Vtbl = 0x017F57B8;	 // VR 1_4_15
		}


		namespace NiIntegerExtraData
		{
			constexpr std::uintptr_t Vtbl = 0x017F5D08;	 // VR 1_4_15
		}


		namespace NiIntegersExtraData
		{
			constexpr std::uintptr_t Vtbl = 0x017F5EE8;	 // VR 1_4_15
		}


		namespace NiMemManager
		{
			// 48 89 44 24 30 48 89 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x030CF888;  // VR 1_4_15
		}


		namespace NiNode
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B 0E 48 3B CF
			constexpr std::uintptr_t Ctor = 0x00C9CCD0;	 // VR 1_4_15
		}


		namespace NiObject
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 44 24 ? 48 89 44 24 ? 48 85 C0
			constexpr std::uintptr_t CreateDeepCopy = 0x00C97A60;  // VR 1_4_15
		}


		namespace NiRefObject
		{
			// NiRefObject::virt_dtor + 13
			constexpr std::uintptr_t TotalObjectCount = 0x0316AD20;	 //  VR 1_4_15
		}


		namespace NiSkinInstance
		{
			// DirectSig: 40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 48 8D 4B 60
			constexpr std::uintptr_t Ctor = 0x00CC5250;	 // VR 1_4_15
		}


		namespace NiStringsExtraData
		{
			constexpr std::uintptr_t Vtbl = 0x017F0A20;	 //  VR 1_4_15
		}


		namespace PlayerCamera
		{
			// 74 0D 48 83 C0 C7
			constexpr std::uintptr_t Singleton = 0x02F8A888;  // VR
			// IndirectSig: E8 ? ? ? ? 48 3B 1D ? ? ? ? 75 1C 48 8B 0D ? ? ? ?
			constexpr std::uintptr_t UpdateThirdPerson = 0x00877DB0;  // VR 1_4_15
		}


		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				// IndirectSig: E8 ? ? ? ? 48 8B 15 ? ? ? ? 48 81 C2 40 01 00 00
				constexpr std::uintptr_t AdvanceLevel = 0x0070D630;	 // VR 1_4_15
			}


			// IndirectSig: E8 ? ? ? ? 66 C7 43 18 00 00
			constexpr std::uintptr_t ActivatePickRef = 0x006B2C60;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 84 C0 75 08 40 32 F6
			constexpr std::uintptr_t AttemptPickpocket = 0x006D58A0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 0F 28 F0 48 85 FF 0F 84 ? ? ? ?
			constexpr std::uintptr_t GetArmorValue = 0x0069C2D0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? F3 0F 2C C8 8B C7
			constexpr std::uintptr_t GetDamage = 0x0069C650;  // VR 1_4_15
			// DirectSig: 44 8B 81 ? ? ? ? 33 C0 45 85 C0 74 27
			constexpr std::uintptr_t GetNumTints = 0x006D8730;	// VR 1_4_15
			// DirectSig: 48 83 EC 38 80 7C 24 70 00
			constexpr std::uintptr_t GetPickpocketChance = 0x003CCD90;	// VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 44 8B 99 ? ? ? ? 45 33 C9
			constexpr std::uintptr_t GetTintMask = 0x006D8580;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 89 65 67
			constexpr std::uintptr_t PlayPickupEvent = 0x006C0640;	// VR 1_4_15
			// E8 ? ? ? ? 48 89 35 ? ? ? ? 48 8B C6
			constexpr std::uintptr_t Singleton = 0x02FEB9F0;  // VR
			// IndirectSig: E8 ? ? ? ? 48 8B 05 ? ? ? ? 83 B8 ? ? ? ? ? 0F 95 C0
			constexpr std::uintptr_t StartGrabObject = 0x006CC000;	// VR 1_4_15
			// VTable: .?AVPlayerCharacter@@
			constexpr std::uintptr_t Vtbl = 0x016E2230;	 // VR 1_4_15
		}


		namespace PlayerControls
		{
			// IndirectSig: E8 ? ? ? ? 90 48 89 05 ? ? ? ? 43 89 1C 34
			constexpr std::uintptr_t Ctor = 0x0072B900;	 // VR 1_4_15
			// 74 0D 48 83 C0 E0 48 89 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02F8AAA8;  // VR
		}


		namespace ProcessLists
		{
			// 4C 8B F9 48 89 0D ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x01F831B0;  // VR
			// IndirectSig: E8 ? ? ? ? 48 8B 13 48 8B CB FF 92 ? ? ? ? 33 D2
			constexpr std::uintptr_t StopCombatAndAlarmOnActor = 0x00700330;  // VR 1_4_15
		}


		namespace ReadyWeaponHandler
		{
			// VTable: .?AUReadyWeaponHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F22A8;	 // VR 1_4_15
		}


		namespace REFR_LOCK
		{
			// IndirectSig: E8 ? ? ? ? 83 F8 05 74 35
			constexpr std::uintptr_t GetLockLevel = 0x00145380;	 // VR 1_4_15
		}


		namespace RunHandler
		{
			// VTable: .?AURunHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F23B8;	 // VR 1_4_15
		}


		namespace Script
		{
			// DirectSig: 41 54 41 56 41 57 48 83 EC 40 48 C7 44 24 38 FE FF FF FF 48 89 5C 24 60 48 89 6C 24 68 48 89 74 24 70 48 89 7C 24 78 4D 8B F1
			constexpr std::uintptr_t CompileAndRun = 0x002F8AF0;  // VR 1_4_15
		}


		namespace ScriptEventSourceHolder
		{
			// IndirectSig: E8 ? ? ? ? 8B 15 ? ? ? ? 65 48 8B 0C 25 ? ? ? ? 41 B8 ? ? ? ? 48 8B 3C D1
			constexpr std::uintptr_t GetSingleton = 0x001964C0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 90 48 8B 45 D7 48 85 C0 74 1C
			constexpr std::uintptr_t SendActivateEvent = 0x002B37E0;  // VR 1_4_15
		}


		namespace SCRIPT_FUNCTION
		{
			// E8 ? ? ? ? 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 44 00 ?
			constexpr std::uintptr_t FirstConsoleCommand = 0x01DC6F60;	// 1_5_97
			// 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 00
			constexpr std::uintptr_t FirstScriptCommand = 0x01DB8910;  // 1_5_97
		}


		namespace ShoutHandler
		{
			// VTable: .?AUShoutHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2488;	 // VR 1_4_15
		}


		namespace Sky
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 40 48
			constexpr std::uintptr_t GetSingleton = 0x001876A0;	 // VR 1_4_15
		}


		namespace SkyrimVM
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 94 C3 48 8B 4C 24 ? 48 85 C9 74 15
			constexpr std::uintptr_t QueuePostRenderCall = 0x0095FD10;	// VR 1_4_15
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x01F889D8;  // VR 1_4_15
		}


		namespace SneakHandler
		{
			// VTable: .?AUSneakHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2448;	 // VR 1_4_15
		}


		namespace SprintHandler
		{
			// VTable: .?AUSprintHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2208;	 // VR 1_4_15
		}


		namespace TES
		{
			// 45 33 C9 48 8B 0D ? ? ? ? 48 C7 44 24 28 00 00 00 00
			constexpr std::uintptr_t Singleton = 0x02FEB6F8;  // VR 1_4_15
		}


		namespace TESCamera
		{
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 48 8B 49 28 48 85 C9 74 06
			constexpr std::uintptr_t SetState = 0x00505F60;	 // VR 1_4_15
		}


		namespace TESCondition
		{
			namespace Node
			{
				// IndirectSig: E8 ? ? ? ? 44 0F B6 C0 45 84 F6
				constexpr std::uintptr_t Run = 0x00455010;	// VR 1_4_15
			}


			// IndirectSig: E8 ? ? ? ? 0F B6 D8 EB 08
			constexpr std::uintptr_t Run = 0x004542F0;	// VR 1_4_15
		}


		namespace TESDataHandler
		{
			// IndirectSig: E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 33 D2 48 8D 0D ? ? ? ? E8 ? ? ? ? 8B 0D ? ? ? ?
			constexpr std::uintptr_t LoadScripts = 0x00181B80;	// VR 1_4_15
			// 48 89 05 ? ? ? ? 49 8B D6
			constexpr std::uintptr_t Singleton = 0x01F82AD8;  // VR
		}


		namespace TESDescription
		{
			// IndirectSig: E8 ? ? ? ? 44 0F 11 4C 24 ?
			constexpr std::uintptr_t GetDescription = 0x001A01B0;  // VR 1_4_15
		}


		namespace TESFile
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 07 EB CA
			constexpr std::uintptr_t Duplicate = 0x0018E210;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? EB E0
			constexpr std::uintptr_t GetCurrentSubRecordType = 0x0018D6F0;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 3C 5E
			constexpr std::uintptr_t GetFormType = 0x0018D2A0;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 44 8B DB
			constexpr std::uintptr_t ReadData = 0x0018D7F0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 33 FF 8B B3 88 02 00 00
			constexpr std::uintptr_t Seek = 0x0018D330;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 49 83 C6 28
			constexpr std::uintptr_t SeekNextSubrecord = 0x0018D740;  // VR 1_4_15
		}


		namespace TESForm
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 07 EB CA
			constexpr std::uintptr_t LookupByID = 0x001A3F60;  // VR 1_4_15
		}


		namespace TESHavokUtilities
		{
			// IndirectSig: E8 ? ? ? ? 48 3B 05 ? ? ? ? 75 0C
			constexpr std::uintptr_t FindCollidableRef = 0x003B4940;  // VR 1_4_15
		}


		namespace TESNPC
		{
			// IndirectSig: E8 ? ? ? ? EB 07 8B D5
			constexpr std::uintptr_t ChangeHeadPart = 0x00375550;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B CD 48 8B D8 E8 ? ? ? ? 8B F0
			constexpr std::uintptr_t GetBaseOverlays = 0x00378490;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 8B F0 B8 ? ? ? ? 85 F6
			constexpr std::uintptr_t GetNumBaseOverlays = 0x00378520;  // VR 1_4_15
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 83 79 14 07
			constexpr std::uintptr_t HasOverlays = 0x00378380;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 63 03 48 6B C8 78 48 8B 43 08 4C 8B 7C 01 ?
			constexpr std::uintptr_t SetSkinFromTint = 0x0036FD80;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 0F B6 05 ? ? ? ? 84 C0
			constexpr std::uintptr_t UpdateNeck = 0x0036FFD0;  // VR 1_4_15
			// VTable: .?AVTESNPC@@
			constexpr std::uintptr_t Vtbl = 0x01616E60;	 // VR 1_4_15
		}


		namespace TESObjectACTI
		{
			// VTable: .?AVTESObjectACTI@@
			constexpr std::uintptr_t Vtbl = 0x015CF2C0;	 // VR 1_4_15
		}


		namespace TESObjectCONT
		{
			// VTable: .?AVTESObjectCONT@@
			constexpr std::uintptr_t Vtbl = 0x015D1500;	 // VR 1_4_15
		}


		namespace TESObjectREFR
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 4E 40 48 8B 01 8B 55 77
			constexpr std::uintptr_t InitChildActivates = 0x002BA430;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8B C8 89 74 24 20 4C 8B C3 48 8D 15 ? ? ? ? 48 8B CD E8 ? ? ? ? B0 01
			constexpr std::uintptr_t GetDisplayFullName = 0x002A78F0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? FF 40 18
			constexpr std::uintptr_t GetLock = 0x002B8C30;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 3B D8 75 08
			constexpr std::uintptr_t GetOwner = 0x002B7DE0;	 // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 41 8B CE 3B C1
			constexpr std::uintptr_t GetStealValue = 0x001E9C20;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 89 85 ? ? ? ? 48 85 C0 74 04 F0 FF 40 28 84 DB
			constexpr std::uintptr_t FindReferenceFor3D = 0x002A5CF0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4D 85 FF 75 26
			constexpr std::uintptr_t InitInventoryIfRequired = 0x001E98B0;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 1D ? ? ? ? 48 8B CF 83 FE 01
			constexpr std::uintptr_t IsCrimeToActivate = 0x002ABA40;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? 4D 89 26
			constexpr std::uintptr_t MoveTo = 0x009E90E0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 41 B4 01 EB 1B
			constexpr std::uintptr_t PlayAnimation = 0x00199B60;  // VR 1_4_15
		}


		namespace TESQuest
		{
			// DirectSig: 48 89 5C 24 ? 56 48 83 EC 20 C6 02 00
			constexpr std::uintptr_t EnsureQuestStarted = 0x003802B0;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 54 24 ? 0F B6 8A ? ? ? ?
			constexpr std::uintptr_t ResetQuest = 0x00380830;  // VR 1_4_15
		}


		namespace TESWorldSpace
		{
			constexpr std::uintptr_t GetOrCreateSkyCell = 0x002C7B20;  // VR 1_4_15
		}


		namespace ThirdPersonState
		{
			// VTable: .?AVThirdPersonState@@
			constexpr std::uintptr_t Vtbl = 0x016A57A0;	 // VR 1_4_15
		}


		namespace TogglePOVHandler
		{
			// VTable: .?AUTogglePOVHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F24C8;	 // VR 1_4_15
		}


		namespace ToggleRunHandler
		{
			// VTable: .?AUToggleRunHandler@@
			constexpr std::uintptr_t Vtbl = 0x016F2378;	 // VR 1_4_15
		}


		namespace UI
		{
			// 48 89 0D ? ? ? ? 48 83 C1 08 E8 ? ? ? ? 90 48 8D 4F 60
			constexpr std::uintptr_t Singleton = 0x01F83200;  // VR
		}


		namespace UIBlurManager
		{
			// IndirectSig: 0F B7 41 18 66 85 C0
			constexpr std::uintptr_t DecrementBlurCount = 0x00902C50;  // VR 1_4_15
			// IndirectSig: 40 53 48 83 EC 20 66 83 79 ? ? 48 8B D9 75 1E
			constexpr std::uintptr_t IncrementBlurCount = 0x00902C10;  // VR 1_4_15
			// 48 89 0D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 66 89 4B 18
			constexpr std::uintptr_t Singleton = 0x02F26780;  // 1_5_97
		}


		namespace UIMessageQueue
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 80 B8 ? ? ? ? ? 0F 85 ? ? ? ? 80 B8 ? ? ? ? ?
			constexpr std::uintptr_t AddMessage = 0x00175A10;  // VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 4C 8B F0 48 85 C0 0F 84 ? ? ? ? 48 89 75 D8
			constexpr std::uintptr_t CreateUIMessageData = 0x00F1FCA0;	// VR 1_4_15
			// IndirectSig: E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 41 C6 86 ? ? ? ? ?
			constexpr std::uintptr_t ProcessCommands = 0x00F1FBC0;	// VR 1_4_15
			// 48 89 0D ? ? ? ? 33 C9 89 4B 10
			constexpr std::uintptr_t Singleton = 0x01F850F8;  // VR
		}


		namespace UserEvents
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8D 4F 60
			constexpr std::uintptr_t Singleton = 0x02FEA140;  // VR
		}


		// IndirectSig: E8 ? ? ? ? 8B 45 80 41 89 44 24 ?
		constexpr std::uintptr_t CreateRefHandle = 0x001428A0;	// VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 83 FE 0C
		constexpr std::uintptr_t DebugNotification = 0x00908170;  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 90 48 8B BC 24 ? ? ? ? 48 85 FF 74 20 8B 47 10
		constexpr std::uintptr_t LookupReferenceByHandle = 0x00143180;	// VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 44 38 7E 50
		constexpr std::uintptr_t PlaySound = 0x0090B1D0;  // VR 1_4_15
		// IndirectSig: E8 ? ? ? ? 48 8B F5
		constexpr std::uintptr_t RTDynamicCast = 0x0138BABA;  // VR 1_4_15
		//
		constexpr std::uintptr_t TlsIndex = 0x03497408;	 // 1_5_97
		//FEC - BSTaskPool hook
		constexpr std::uintptr_t func2FAE50 = 0x002FAE50;  // VR 1_4_15
	}
}
