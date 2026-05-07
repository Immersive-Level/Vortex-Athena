#include "pch-cpp.hpp"





template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename T1>
struct ConstrainedActionInvoker1;
template <typename T1>
struct ConstrainedActionInvoker1<T1*>
{
	static inline void Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, params, params[0]);
	}
};
template <typename R>
struct ConstrainedFuncInvoker0
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj)
	{
		R ret;
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, NULL, &ret);
		return ret;
	}
};
template <typename R, typename T1>
struct ConstrainedFuncInvoker1
{
	static inline R Invoke (RuntimeClass* type, const RuntimeMethod* constrainedMethod, void* boxBuffer, void* obj, T1 p1)
	{
		R ret;
		void* params[1] = { &p1 };
		il2cpp_codegen_runtime_constrained_call(type, constrainedMethod, boxBuffer, obj, params, &ret);
		return ret;
	}
};

struct UnsafeList_1_t894EC58BE6EA99FD1F51CF2FF691144CF00F515D;
struct UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674;
struct UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718;
struct UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613;
struct UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6;
struct UnsafeList_1_tC512AB26A525DF3622FBF1917719AEBFF48AAB27;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582;
struct ArchetypeQuery_t45938EA78C5B9A37BBD17621D4A2DACAB98BFCEA;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A;
struct ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47;
struct ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA;
struct ComponentTypeInArchetype_t44B3E807C4EDD199FFB36EE44950B3DAEBF7D90E;
struct ComponentTypeList_t8A43AFD2ABD042DD0F0FAA4F95F3FDA3A1D8C053;
struct Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD;
struct EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F;
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36;
struct EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F;
struct EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26;
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct IntPtr_t;
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08;
struct MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C;
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455;
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct WorldUnmanagedImpl_tB98600E1E80A2ABD0C6F29D8C55829750507D830;
struct DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15;
struct BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5;
struct QueryTypes_tE3A9F854C5272D3077BA4C51A154002D3B0E7408;
struct BufferEntityPatchInfo_tE60CA9D4A0AE04EFCD622B87704F214AAE31C879;
struct EntityPatchInfo_tFA0BDF4E389E1C56A096EE783A969B8C75A4CA47;
struct EntityOffsetInfo_tAA68D1FC74ADF57FB76987377354ED848C7CC9D1;
struct TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9;
IL2CPP_EXTERN_C const RuntimeMethod* UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EntityQueryExtensionsForComponentArray_tFFC5C612CF24D6D9A7462FF944D2EBAB316CFFBF  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F 
{
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* ___m_ListData;
};
struct NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 
{
	UnsafeList_1_t3A26A222433F7993EC942046A500D6EA3DCB97E6* ___m_ListData;
};
struct SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F 
{
	void* ____buffer;
};
struct SharedStatic_1_tB042D7198B3BD170F6B8D07127F90A916DCE64B5 
{
	void* ____buffer;
};
struct SharedStatic_1_t06174270CC879833E66A2A61C363018B785C3CC7 
{
	void* ____buffer;
};
struct SharedStatic_1_t62A57D8B0A16F2D71A8FF3F21C3924439A647CA0 
{
	void* ____buffer;
};
struct ArchetypeChunkData_t5D1EB2889C02131353F4F231F4908F0E872BDBF5 
{
	void* ___m_Data;
	int32_t ___U3CCapacityU3Ek__BackingField;
	int32_t ___U3CCountU3Ek__BackingField;
	int32_t ___SharedComponentCount;
	int32_t ___ComponentCount;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A 
{
	int32_t ___Value;
};
struct Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD 
{
	int32_t ___Index;
	int32_t ___Version;
};
struct EntityArchetype_tE1D293B55B4783642BB593531A57460AB7709354 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
};
struct EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _____impl;
	uint64_t _____seqno;
};
struct EntityQueryMask_tA3298547B0A6701B30F8E223B5346B40E68DDEEF 
{
	uint8_t ___Index;
	uint8_t ___Mask;
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___EntityComponentStore;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
#pragma pack(push, tp, 1)
struct FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					uint8_t ___byte0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					uint8_t ___byte0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0001_OffsetPadding[1];
					uint8_t ___byte0001;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0001_OffsetPadding_forAlignmentOnly[1];
					uint8_t ___byte0001_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0002_OffsetPadding[2];
					uint8_t ___byte0002;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0002_OffsetPadding_forAlignmentOnly[2];
					uint8_t ___byte0002_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0003_OffsetPadding[3];
					uint8_t ___byte0003;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0003_OffsetPadding_forAlignmentOnly[3];
					uint8_t ___byte0003_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0004_OffsetPadding[4];
					uint8_t ___byte0004;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0004_OffsetPadding_forAlignmentOnly[4];
					uint8_t ___byte0004_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0005_OffsetPadding[5];
					uint8_t ___byte0005;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0005_OffsetPadding_forAlignmentOnly[5];
					uint8_t ___byte0005_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0006_OffsetPadding[6];
					uint8_t ___byte0006;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0006_OffsetPadding_forAlignmentOnly[6];
					uint8_t ___byte0006_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0007_OffsetPadding[7];
					uint8_t ___byte0007;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0007_OffsetPadding_forAlignmentOnly[7];
					uint8_t ___byte0007_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0008_OffsetPadding[8];
					uint8_t ___byte0008;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0008_OffsetPadding_forAlignmentOnly[8];
					uint8_t ___byte0008_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0009_OffsetPadding[9];
					uint8_t ___byte0009;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0009_OffsetPadding_forAlignmentOnly[9];
					uint8_t ___byte0009_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0010_OffsetPadding[10];
					uint8_t ___byte0010;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0010_OffsetPadding_forAlignmentOnly[10];
					uint8_t ___byte0010_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0011_OffsetPadding[11];
					uint8_t ___byte0011;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0011_OffsetPadding_forAlignmentOnly[11];
					uint8_t ___byte0011_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0012_OffsetPadding[12];
					uint8_t ___byte0012;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0012_OffsetPadding_forAlignmentOnly[12];
					uint8_t ___byte0012_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0013_OffsetPadding[13];
					uint8_t ___byte0013;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0013_OffsetPadding_forAlignmentOnly[13];
					uint8_t ___byte0013_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0014_OffsetPadding[14];
					uint8_t ___byte0014;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0014_OffsetPadding_forAlignmentOnly[14];
					uint8_t ___byte0014_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0015_OffsetPadding[15];
					uint8_t ___byte0015;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0015_OffsetPadding_forAlignmentOnly[15];
					uint8_t ___byte0015_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0__padding[16];
	};
};
#pragma pack(pop, tp)
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct LookupCache_t3C0A5C02880755A14500AADCA75DC1CB85D12851 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
	int32_t ___ComponentOffset;
	uint16_t ___ComponentSizeOf;
	int16_t ___IndexInArchetype;
};
struct PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 
{
	uint32_t ___Value;
};
struct SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 
{
	int32_t ___SceneSectionIndex;
};
struct SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E 
{
	uint64_t ___Value;
};
#pragma pack(push, tp, 1)
struct TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					int32_t ___Value;
				};
				#pragma pack(pop, tp)
				struct
				{
					int32_t ___Value_forAlignmentOnly;
				};
			};
		};
		uint8_t TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C__padding[4];
	};
};
#pragma pack(pop, tp)
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 
{
	UnsafeList_1_t894EC58BE6EA99FD1F51CF2FF691144CF00F515D* ___MatchingChunks;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718* ___PerChunkMatchingArchetypeIndex;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718* ___ChunkIndexInArchetype;
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___EntityComponentStore;
	int32_t ___CacheValid;
};
struct UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566 
{
	UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613* ___ListData;
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___entityComponentStore;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F 
{
	WorldUnmanagedImpl_tB98600E1E80A2ABD0C6F29D8C55829750507D830* ___m_Impl;
};
struct uint4_t6C69CBFAE9BF0F727D52B68779D4A3F0DBA8D5C9 
{
	uint32_t ___x;
	uint32_t ___y;
	uint32_t ___z;
	uint32_t ___w;
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct U3CQueryMaskArrayU3Ee__FixedBuffer_tFFF30B49C581FF74C9B02B81388A6ED363C3A35C 
{
	union
	{
		struct
		{
			uint8_t ___FixedElementField;
		};
		uint8_t U3CQueryMaskArrayU3Ee__FixedBuffer_tFFF30B49C581FF74C9B02B81388A6ED363C3A35C__padding[128];
	};
};
struct ChunkListChanges_tC57E06E14D1D6D3D87675D05619E0539A86564D8 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___ArchetypeTrackingHead;
};
struct U3CIndexInArchetypeU3Ee__FixedBuffer_t170AD5FA997C14F5017A342DD4D7545160BAF695 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CIndexInArchetypeU3Ee__FixedBuffer_t170AD5FA997C14F5017A342DD4D7545160BAF695__padding[4];
	};
};
struct PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
	int32_t ___EntityCount;
	int32_t ___ListIndex;
};
struct U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A__padding[8];
	};
};
struct U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9__padding[8];
	};
};
struct U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0 
{
	union
	{
		struct
		{
			int32_t ___FixedElementField;
		};
		uint8_t U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0__padding[8];
	};
};
struct ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572 
{
	LookupCache_t3C0A5C02880755A14500AADCA75DC1CB85D12851 ___m_LookupCache;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_TypeIndex;
	int32_t ___m_SizeInChunk;
	uint32_t ___m_GlobalSystemVersion;
	uint8_t ___m_IsReadOnly;
	uint8_t ___m_IsZeroSized;
	int32_t ___m_Length;
};
struct HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9 
{
	uint8_t* ___Ptr;
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeList_1_tA21F92C4A814A112A95FFC7861B906E3523E4EEF 
{
	UnsafeList_1_tC512AB26A525DF3622FBF1917719AEBFF48AAB27* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t894EC58BE6EA99FD1F51CF2FF691144CF00F515D 
{
	ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 
{
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t81DA7B1F50305CF2C5A3DAE7C5027E809A808B8C 
{
	ComponentTypeList_t8A43AFD2ABD042DD0F0FAA4F95F3FDA3A1D8C053* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 
{
	int32_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 
{
	intptr_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tEE6D0269E6E8E59E96623AA3410F283FE7B8CF65 
{
	alignas(IL2CPP_SIZEOF_VOID_P) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_tA2B6A040C4F2656D88ABB4345257ADE8F2F30F35 
{
	uint32_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t1B7B48A9B1389CD907B27629BAA5B0F080F48D58 
{
	QueryTypes_tE3A9F854C5272D3077BA4C51A154002D3B0E7408* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeParallelMultiHashMap_2_tF97D13A4436BE5A45CEFAE2066E0ABE4AB22DC94 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582** ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafePtrList_1_t9303472093C8513F7E98E3EFE8C3560679C4CAA6 
{
	EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26** ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct ArchetypeFlags_t2A77259CC5D0AFE108711E53C924FB63B0DE2C8F 
{
	uint16_t ___value__;
};
struct DynamicComponentTypeHandle_t3E20E0F3BAD2BBFEF185BE607A282ECFEAF35CB6 
{
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_TypeIndex;
	uint32_t ___m_GlobalSystemVersion;
	uint8_t ___m_IsReadOnly;
	uint8_t ___m_IsZeroSized;
	int16_t ___m_TypeLookupCache;
	int32_t ___m_Length;
};
struct EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D 
{
	BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* ____builderDataPtr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ____allocator;
};
struct EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26 
{
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* ___RequiredComponents;
	int32_t ___RequiredComponentsCount;
	alignas(IL2CPP_SIZEOF_VOID_P) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___ReaderTypes;
	int32_t ___ReaderTypesCount;
	alignas(IL2CPP_SIZEOF_VOID_P) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___WriterTypes;
	int32_t ___WriterTypesCount;
	alignas(IL2CPP_SIZEOF_VOID_P) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___EnableableComponentTypeIndices;
	int32_t ___EnableableComponentTypeIndexCount;
	ArchetypeQuery_t45938EA78C5B9A37BBD17621D4A2DACAB98BFCEA* ___ArchetypeQueries;
	int32_t ___ArchetypeQueryCount;
	EntityQueryMask_tA3298547B0A6701B30F8E223B5346B40E68DDEEF ___EntityQueryMask;
	UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566 ___MatchingArchetypes;
	UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 ___MatchingChunkCache;
	uint8_t ___HasEnableableComponents;
};
struct EntityQueryOptions_t92CCDF8D6C6B7CA6FD47494CE90A2D496114F66D 
{
	int32_t ___value__;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
#pragma pack(push, tp, 1)
struct FixedBytes30_t7721F11929A3AC08287DF5E6D7AEF85CCEE04AD2 
{
	union
	{
		struct
		{
			union
			{
				#pragma pack(push, tp, 1)
				struct
				{
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0000;
				};
				#pragma pack(pop, tp)
				struct
				{
					FixedBytes16_tBBD888116CBD6329886E0FE97A82EEB4B7CB3FA0 ___offset0000_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0016_OffsetPadding[16];
					uint8_t ___byte0016;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0016_OffsetPadding_forAlignmentOnly[16];
					uint8_t ___byte0016_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0017_OffsetPadding[17];
					uint8_t ___byte0017;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0017_OffsetPadding_forAlignmentOnly[17];
					uint8_t ___byte0017_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0018_OffsetPadding[18];
					uint8_t ___byte0018;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0018_OffsetPadding_forAlignmentOnly[18];
					uint8_t ___byte0018_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0019_OffsetPadding[19];
					uint8_t ___byte0019;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0019_OffsetPadding_forAlignmentOnly[19];
					uint8_t ___byte0019_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0020_OffsetPadding[20];
					uint8_t ___byte0020;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0020_OffsetPadding_forAlignmentOnly[20];
					uint8_t ___byte0020_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0021_OffsetPadding[21];
					uint8_t ___byte0021;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0021_OffsetPadding_forAlignmentOnly[21];
					uint8_t ___byte0021_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0022_OffsetPadding[22];
					uint8_t ___byte0022;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0022_OffsetPadding_forAlignmentOnly[22];
					uint8_t ___byte0022_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0023_OffsetPadding[23];
					uint8_t ___byte0023;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0023_OffsetPadding_forAlignmentOnly[23];
					uint8_t ___byte0023_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0024_OffsetPadding[24];
					uint8_t ___byte0024;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0024_OffsetPadding_forAlignmentOnly[24];
					uint8_t ___byte0024_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0025_OffsetPadding[25];
					uint8_t ___byte0025;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0025_OffsetPadding_forAlignmentOnly[25];
					uint8_t ___byte0025_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0026_OffsetPadding[26];
					uint8_t ___byte0026;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0026_OffsetPadding_forAlignmentOnly[26];
					uint8_t ___byte0026_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0027_OffsetPadding[27];
					uint8_t ___byte0027;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0027_OffsetPadding_forAlignmentOnly[27];
					uint8_t ___byte0027_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0028_OffsetPadding[28];
					uint8_t ___byte0028;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0028_OffsetPadding_forAlignmentOnly[28];
					uint8_t ___byte0028_forAlignmentOnly;
				};
				#pragma pack(push, tp, 1)
				struct
				{
					char ___byte0029_OffsetPadding[29];
					uint8_t ___byte0029;
				};
				#pragma pack(pop, tp)
				struct
				{
					char ___byte0029_OffsetPadding_forAlignmentOnly[29];
					uint8_t ___byte0029_forAlignmentOnly;
				};
			};
		};
		uint8_t FixedBytes30_t7721F11929A3AC08287DF5E6D7AEF85CCEE04AD2__padding[30];
	};
};
#pragma pack(pop, tp)
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B 
{
	uint4_t6C69CBFAE9BF0F727D52B68779D4A3F0DBA8D5C9 ___Value;
};
struct MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9 
{
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___Archetype;
	int32_t ___RequiredComponentCount;
	int32_t ___EnableableComponentsCount_All;
	int32_t ___EnableableComponentsCount_None;
	int32_t ___EnableableComponentsCount_Any;
	int32_t ___EnableableComponentsCount_Disabled;
	U3CIndexInArchetypeU3Ee__FixedBuffer_t170AD5FA997C14F5017A342DD4D7545160BAF695 ___IndexInArchetype;
};
struct NativeArrayOptions_t3E979EEF4B4840228A7692A97DA07553C6465F1D 
{
	int32_t ___value__;
};
struct ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD 
{
	intptr_t ___m_Ptr;
};
struct SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 
{
	Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___SceneEntity;
};
struct UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 
{
	uint8_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___Alignment;
};
struct UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 
{
	uint64_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 
{
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct FrameRateMode_tA21C103890821A7BE140C7A6FCA32DBC312DBFFA 
{
	int32_t ___value__;
};
struct AccessMode_t08155A76104B91A50C66C3D69AB1F04FF5D91B5D 
{
	int32_t ___value__;
};
struct ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE 
{
	int32_t ___Count;
	U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A ___IndexInEntityQuery;
};
struct SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8 
{
	int32_t ___Count;
	U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9 ___IndexInEntityQuery;
	U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0 ___SharedComponentIndex;
};
struct NativeArray_1_tDDBE2218E06075EFCDE280D90B6FA7C4BF46BFD2 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct UnsafeHashSet_1_t982205DCD82C95EDB86B40937DA9AC768D4723A8 
{
	HashMapHelper_1_tF4097677DF54F9B7101CE52DA301CACDF02D8AD9 ___m_Data;
};
struct ArchetypeListMap_t9B5C7F814630CC95D11AE3A6D713646CDE4A33AD 
{
	UnsafeList_1_tA2B6A040C4F2656D88ABB4345257ADE8F2F30F35 ___hashes;
	UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 ___archetypes;
	int32_t ___emptyNodes;
	int32_t ___skipNodes;
};
struct BufferAllocatorHeap_t8B23AEAD3FF0104ED854068D0451346730DAC3AE 
{
	UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 ___Buffers;
	UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 ___FreeList;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Handle;
	int32_t ___BufferSizeInBytes;
};
struct ChunkListMap_t597E56D196A1BE611335E367152A64E6FF1BB311 
{
	UnsafeList_1_tA2B6A040C4F2656D88ABB4345257ADE8F2F30F35 ___hashes;
	UnsafeList_1_t894EC58BE6EA99FD1F51CF2FF691144CF00F515D ___chunks;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___archetype;
	int32_t ___emptyNodes;
	int32_t ___skipNodes;
};
struct ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 
{
	int32_t ___SimulationTickRate;
	int32_t ___PredictedFixedStepSimulationTickRatio;
	int32_t ___NetworkTickRate;
	int32_t ___MaxSimulationStepsPerFrame;
	int32_t ___MaxSimulationStepBatchSize;
	int32_t ___TargetFrameRateMode;
	bool ___m_SendSnapshotsForCatchUpTicks;
	uint32_t ___SnapshotAckMaskCapacity;
	int32_t ___U3CClampPartialTicksThresholdU3Ek__BackingField;
	uint32_t ___HandshakeApprovalTimeoutMS;
};
struct ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_marshaled_pinvoke
{
	int32_t ___SimulationTickRate;
	int32_t ___PredictedFixedStepSimulationTickRatio;
	int32_t ___NetworkTickRate;
	int32_t ___MaxSimulationStepsPerFrame;
	int32_t ___MaxSimulationStepBatchSize;
	int32_t ___TargetFrameRateMode;
	int32_t ___m_SendSnapshotsForCatchUpTicks;
	uint32_t ___SnapshotAckMaskCapacity;
	int32_t ___U3CClampPartialTicksThresholdU3Ek__BackingField;
	uint32_t ___HandshakeApprovalTimeoutMS;
};
struct ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_marshaled_com
{
	int32_t ___SimulationTickRate;
	int32_t ___PredictedFixedStepSimulationTickRatio;
	int32_t ___NetworkTickRate;
	int32_t ___MaxSimulationStepsPerFrame;
	int32_t ___MaxSimulationStepBatchSize;
	int32_t ___TargetFrameRateMode;
	int32_t ___m_SendSnapshotsForCatchUpTicks;
	uint32_t ___SnapshotAckMaskCapacity;
	int32_t ___U3CClampPartialTicksThresholdU3Ek__BackingField;
	uint32_t ___HandshakeApprovalTimeoutMS;
};
struct ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47 
{
	uint16_t* ___m_TypeArrayIndices;
	DependencyHandle_t73038501598DF9B7E83BF8486D87B9DED6200B15* ___m_DependencyHandles;
	uint16_t ___m_DependencyHandlesCount;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___m_ReadJobFences;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___EntityTypeIndex;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___m_ExclusiveTransactionDependency;
	uint8_t ____IsInTransaction;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___m_Marker;
	WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F ___m_World;
};
struct ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA 
{
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___TypeIndex;
	int32_t ___AccessModeType;
};
struct EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B 
{
	uint32_t ___RequiredChangeVersion;
	SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8 ___Shared;
	ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE ___Changed;
	uint32_t ____UseOrderFiltering;
};
struct FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824 
{
	union
	{
		struct
		{
			uint16_t ___utf8LengthInBytes;
			alignas(1) FixedBytes30_t7721F11929A3AC08287DF5E6D7AEF85CCEE04AD2 ___bytes;
		};
		uint8_t FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824__padding[32];
	};
};
struct ManagedDeferredCommands_t3585F563AFB19DC3B6EB9250562B62FC78A0E9A1 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___ECS;
	UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 ___CommandBuffer;
};
struct SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 
{
	Hash128_t2EA8F45F10BC2DF40B0CE9AE04F222072EB1345B ___SceneGUID;
	int32_t ___Section;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5 
{
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____typeData;
	UnsafeList_1_t1B7B48A9B1389CD907B27629BAA5B0F080F48D58 ____indexData;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____all;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____any;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____none;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____disabled;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____absent;
	UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674 ____present;
	int32_t ____pendingOptions;
	uint8_t ____isFinalized;
};
struct Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582 
{
	ArchetypeChunkData_t5D1EB2889C02131353F4F231F4908F0E872BDBF5 ___Chunks;
	UnsafeList_1_t894EC58BE6EA99FD1F51CF2FF691144CF00F515D ___ChunksWithEmptySlots;
	ChunkListMap_t597E56D196A1BE611335E367152A64E6FF1BB311 ___FreeChunksBySharedComponents;
	ComponentTypeInArchetype_t44B3E807C4EDD199FFB36EE44950B3DAEBF7D90E* ___Types;
	int32_t* ___EnableableTypeIndexInArchetype;
	UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 ___MatchingQueryData;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___NextChangedArchetype;
	int32_t ___EntityCount;
	int32_t ___ChunkCapacity;
	int32_t ___TypesCount;
	int32_t ___EnableableTypesCount;
	int32_t ___InstanceSize;
	int32_t ___InstanceSizeWithOverhead;
	int32_t ___ScalarEntityPatchCount;
	int32_t ___BufferEntityPatchCount;
	uint64_t ___StableHash;
	uint64_t ___BloomFilterMask;
	int32_t* ___TypeMemoryOrderIndexToIndexInArchetype;
	int32_t* ___TypeIndexInArchetypeToMemoryOrderIndex;
	int32_t* ___Offsets;
	uint16_t* ___SizeOfs;
	int32_t* ___BufferCapacities;
	int16_t ___FirstBufferComponent;
	int16_t ___FirstManagedComponent;
	int16_t ___FirstTagComponent;
	int16_t ___FirstSharedComponent;
	int16_t ___FirstChunkComponent;
	uint16_t ___Flags;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___CopyArchetype;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___InstantiateArchetype;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___CleanupResidueArchetype;
	Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___MetaChunkArchetype;
	EntityPatchInfo_tFA0BDF4E389E1C56A096EE783A969B8C75A4CA47* ___ScalarEntityPatches;
	BufferEntityPatchInfo_tE60CA9D4A0AE04EFCD622B87704F214AAE31C879* ___BufferEntityPatches;
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___EntityComponentStore;
	U3CQueryMaskArrayU3Ee__FixedBuffer_tFFF30B49C581FF74C9B02B81388A6ED363C3A35C ___QueryMaskArray;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct BufferAllocator_tBE0961382918F823D26ED519F45D281AA06494D4 
{
	BufferAllocatorHeap_t8B23AEAD3FF0104ED854068D0451346730DAC3AE ___Allocator;
};
struct EntityNameStoreAccess_tF60EECC3572FC72F6BBE88730AC291BE9B45BAD6 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* ___m_EntityComponentStore;
	UnsafeHashSet_1_t982205DCD82C95EDB86B40937DA9AC768D4723A8 ___m_EntitiesNameSet;
	EntityNameStoreAccessData_t5AC842F68D9F5083E23B12C17F81F43535F2ED1F* ___m_Data;
};
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574 
{
	EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* ____Access;
	EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* ____QueryData;
	EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B ____Filter;
	uint64_t ____SeqNo;
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ____CachedState;
};
struct BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE 
{
	BufferAllocator_tBE0961382918F823D26ED519F45D281AA06494D4 ___m_bufferAllocator;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 ___m_allocations;
	int32_t ___m_currentBlockIndex;
	uint8_t* ___m_nextPtr;
};
struct EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F 
{
	int32_t* ___m_ComponentTypeOrderVersion;
	BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE ___m_ArchetypeChunkAllocator;
	UnsafePtrList_1_t3BA56CBE50A217517D1FA78C345C0AF8242F8088 ___m_Archetypes;
	ArchetypeListMap_t9B5C7F814630CC95D11AE3A6D713646CDE4A33AD ___m_TypeLookup;
	int32_t ___m_ManagedComponentIndex;
	int32_t ___m_ManagedComponentIndexCapacity;
	UnsafeAppendBuffer_t9EC160EA10485CD9DD96EDCBCEA06C7BCEF81500 ___m_ManagedComponentFreeIndex;
	ManagedDeferredCommands_t3585F563AFB19DC3B6EB9250562B62FC78A0E9A1 ___ManagedChangesTracker;
	int32_t ___m_SharedComponentVersion;
	int32_t ___m_SharedComponentGlobalVersion;
	int32_t ___m_UnmanagedSharedComponentCount;
	UnsafeList_1_t81DA7B1F50305CF2C5A3DAE7C5027E809A808B8C ___m_UnmanagedSharedComponentsByType;
	UnsafeList_1_tEE6D0269E6E8E59E96623AA3410F283FE7B8CF65 ___m_UnmanagedSharedComponentTypes;
	UnsafeList_1_tA21F92C4A814A112A95FFC7861B906E3523E4EEF ___m_UnmanagedSharedComponentInfo;
	UnsafeParallelMultiHashMap_2_tF97D13A4436BE5A45CEFAE2066E0ABE4AB22DC94 ___m_HashLookup;
	ChunkListChanges_tC57E06E14D1D6D3D87675D05619E0539A86564D8 ___m_ChunkListChangesTracker;
	uint64_t ___m_WorldSequenceNumber;
	uint64_t ___m_NextChunkSequenceNumber;
	uint32_t ___m_GlobalSystemVersion;
	int32_t ___m_IntentionallyInconsistent;
	uint32_t ___m_ArchetypeTrackingVersion;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_LinkedGroupType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_ChunkHeaderType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_PrefabType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_OmitLinkedEntityGroupFromPrefabInstanceType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_CleanupEntityType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_DisabledType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_EntityType;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_SystemInstanceType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_ChunkHeaderComponentType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_EntityComponentType;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___m_SimulateComponentType;
	TypeInfo_tD43B08A8D19156EEC98399693A96161F02139654* ___m_TypeInfos;
	EntityOffsetInfo_tAA68D1FC74ADF57FB76987377354ED848C7CC9D1* ___m_EntityOffsetInfos;
	int32_t ___m_DebugOnlyManagedAccess;
	uint8_t ___memoryInitPattern;
	uint8_t ___useMemoryInitPattern;
	EntityNameStoreAccess_tF60EECC3572FC72F6BBE88730AC291BE9B45BAD6 ___m_NameStoreAccess;
};
struct EntityQueryManager_tCD6CFC49CDD19B4E639F214958CC0B81011ACD0A 
{
	ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* ___m_DependencyManager;
	BlockAllocator_tE609150FFA2B257EBBBEEEFDF795FB7073A4E7AE ___m_EntityQueryDataChunkAllocator;
	UnsafePtrList_1_t9303472093C8513F7E98E3EFE8C3560679C4CAA6 ___m_EntityQueryDatas;
	UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 ___m_EntityQueryDataCacheUntyped;
	int32_t ___m_EntityQueryMasksAllocated;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_disabledTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_prefabTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_systemInstanceTypeIndex;
	alignas(4) TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___m_chunkHeaderTypeIndex;
};
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36 
{
	EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F ___m_EntityComponentStore;
	EntityQueryManager_tCD6CFC49CDD19B4E639F214958CC0B81011ACD0A ___m_EntityQueryManager;
	ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47 ___m_DependencyManager;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 ___m_ManagedReferenceIndexList;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQuery;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithChunks;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithSystems;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_UniversalQueryWithChunksAndSystems;
	EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___m_EntityGuidQuery;
	WorldUnmanaged_t7B736084B2D4749A9CE36AD9A7F9D930DAA9F88F ___m_WorldUnmanaged;
	int32_t ___m_ManagedAccessHandle;
	EntityArchetype_tE1D293B55B4783642BB593531A57460AB7709354 ___m_EntityAndSimulateOnlyArchetype;
	UntypedUnsafeParallelHashMap_t926EFEEE26C4DE4FE2FA5A27FEA1D83CDD4B1B17 ___m_AliveEntityQueries;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_StaticFields
{
	FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824 ___kMsg_None;
	FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824 ___kMsg_Space_Buffer;
	FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824 ___kMsg_Space_Exclude;
	FixedString32Bytes_t0FB200DC482825CC1EF24B4640201CC039631824 ___kMsg_Space_Readonly;
};
struct EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_StaticFields
{
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ____bfp_ResetFilter;
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ____bfp_FreeCachedState;
};
struct EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_StaticFields
{
	SharedStatic_1_tB042D7198B3BD170F6B8D07127F90A916DCE64B5 ___s_TotalChunkAddressSpaceInBytes;
	uint64_t ___DefaultChunkAddressSpaceInBytes;
	SharedStatic_1_t06174270CC879833E66A2A61C363018B785C3CC7 ___s_chunkStore;
	SharedStatic_1_t62A57D8B0A16F2D71A8FF3F21C3924439A647CA0 ___s_entityStore;
};
struct EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_StaticFields
{
	SharedStatic_1_t0A9894CA2483CA9491C550F8D66FBA5213718E9F ___s_ManagedPlaybackTrampoline;
	RuntimeObject* ___s_DelegateGCPrevention;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGoInGameRequest_tDF8F9520CB18418B3570B25E646464A90C8D2B8B_m639CBC8B7A74187E8A8EF69A4C51B753D99C2963_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m47BA8188DCB537ED8911366260DDD9054B00BE49_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mF32B07397F399C3B9C5DE1C1AED74B5FA0F0B29E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_m8736F800BCDEAF183953B7B8922DA04BE569102B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m864F382F53065240543247AE0DBD61F9B70B7618_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_mFD8268FF9C7C966C60C10879CB3B2956E7FC6FEE_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mED674BAF8C637D42FB820B9312EE84249EC64975_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m1A81156C63974EA84F0A4643642D358A715B6A6D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m35B180D8E0FB2E919950E250BE18134F7343708A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionLinkTransform_tBCA469674FB09DE2A20CC9E6A9B26B92462A7F11_m167A714D37B6E2167FA0AAF692B3A25A8C22F852_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostDistancePartitionShared_t2A64D9C74B21E979B0B3AD3C5D8DBE31102CC92F_m4DB2E2D0B2E1ECA6C888F68BE3E2BBDBFED82D05_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabMetaData_tCF69584BEDF11A9D0486F3C9211F045B8C0B9544_mF0E9F2FD37BD5E7FE640240461B1A5724D1EC64C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabRuntimeStrip_t7F62492831ECDA11D63D2F4792B1CB5FB10E5654_m8262AFA119F9096D0239E841F1CEE0E2AD2D90DF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m537342EAA4D2B3FE8B8C6180362468A4FA0F19EA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsConstrainedBodyPair_t11C5D7FDF2C7D1E0AC01DD9AA0E95492E8C14728_m9D1B79B617CE177B561F6A0BDCB036BAB1372BF6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsJoint_t7E81076F134608B1FDEA0070C11135E9B30A0897_mEE2012D86F5668FDA5C8C1FCCBB4EC0F7313D50B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_m31F3748EDFD132CF6325D066FBBB03817FD96582_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m6E5167680CB403CE5BCEFBD109A722100C4FC127_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_m7A56721F25F4850E27698151B4BD87DF85028EE5_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_m315BBB7014A48D6EA91CE5F41D270F8D90D3F6C1_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMaterialMeshInfo_tA5DA20397A2C8CE93BBE1B1262E8B3448450117D_m5230672F6FF2F02CDAB4863BBD19ECB7A8E83239_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m4A43FA491A0AE43E872830E9A1C18021D64990E0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkId_t15A7021DA0A22D42A3251B2BAF4A349D27D8662B_mED3112F9956CB3E49C69694B11DA315E60B116FD_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m3777EB9629F5FF189A339D465A78B52501BDB692_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m597CCDD4EBC54745902BD61843D1ECB79E56B3A0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mFE5BD238935245103669D542C46955C97945BA4F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisAdditionalEntitiesBakingData_t16B67AE176CF0186E6E62B375C8B59BFB902D4E1_m6DCEFDA00308D5CF93ACF4FF75A1E5B207B212D1_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m0F23A448C61CCF70DF9C04FC86EB10D61DDC3A72_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBroadphaseData_t283ED0771F35DEB34BC13ED55C73772D7CD154A3_m231A9F12C94DCC196177B0153F47393B403460E7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuildPhysicsWorldData_t2B48F1A635280E8C32969EF1108844731186F1B2_m11C0F36734285030D82A9424C569C0F21C28DD8D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapIndex_tB3FFBA44070A59D7CE3FE43E525EE67F62F7DD77_m7842F319E5F79C371C19D99A3BDABAB48983A50E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapST_tF3B17F024F3A80DEC0F7FA53C4B605A79202D14E_m0D48267FE6D42C6E933EBC874096C29538382795_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisChild_tCA0AD12FC56504F3D4A64E40855F54238020861E_mE906F6A32DF896D9054B52C72D4CFFAE0D70A494_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m253E94A751C8AAD2F9AE71E695614F8BBC0DD5B0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisClientTickRate_t0E92DBFF5847A71B95752CF3292FD2FC140495C9_m390277FD3E8D44958907E1768F3B9908034DE49C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisColliderBlobCleanupData_tFEC8BF2F69AE15547D452B79FACB5A3A88064E32_mF56C17C837A47992FA0744957F8F579F05DA3C27_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostAuthoringComponentBakingData_t963B503B28A9BE4F9D7B22F4D23BFEC2BB1A255E_mEF0F44EA07DFEB48AE2DF8762EEE545B36C78ED6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCleanup_tE96F7C9F4DC59AEB2C9996CBA308E8A0603F6BBC_m78442F5D825A49D22A62F85A2BC9478AB4370516_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollection_t13EDF41F2078D02C47FB76ED953412292F745219_mB84A324CCF547FBD67690E998133E3316B02262D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollectionComponentIndex_tAED81E493A6621B761612432F7D2A0374567BD84_m63920CCC9152FABBE2E08F5766B8094FD82C15FF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollectionPrefab_t8AF4B66BAD32F1BF1FD8A7E9B236EEBDFBC81D60_m61CC8A58EF4C6E694005B54187F76C650A450856_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostComponentSerializerCollectionData_tBA662EAD4B94AC75D75278CE1D22A56621C92191_mC7BF4B5DAF5CE5F55E0D9958CA2C1FEB85D76CD5_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCount_t28FC783F6F6AEE97C5F7B67CA58CA6652CFC1083_m276861C40F10051DE071E11EEAE9E22E85F6BA5F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostDespawnQueues_tFCC28D3C6222373756344D11F4950B1CEF4E1B5B_mAA9E66F0BC0A862293B28E564D5D202BB83FEFD8_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwnerPredictedSwitchingQueue_tC005A4D4732805D5D7C6FB393E20241F47551491_mC966ED9D00528305CFDB87205580567B9300B224_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionGroupTickState_tB8F7B7A4ADC6DDAD8291FA77A797B6BFF50BF0A2_m4DEFA234023B38F121CE84B02E5B962A0F23256A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionHistoryState_tD55DF52D9563D83B55FA94B94BBF30A0D9F9DC28_m050C814D3893DBF216CD02CBA893469EFFBFE59A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionSmoothing_tB6587249ECA5A9C2182026512CFF914FF75B37E0_mE52515741C176ED61587830941DF3C059A16C7B5_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionSwitchingQueues_t766AA5F381338A4D531193C3CBFFFE35055BA661_m10AA7712D2825A6D27DDFDE11E6B105635F9B4D1_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostRelevancy_t24C834524E3673B5061DBA61F39D29751B32D659_m989972E6870512C5B294502FAE3E2D3F932271D6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSendSystemData_tAD3978C66B82BC5C4FFB9470AD3CBF2B7B2EFC84_m8C2570044726DBC4BAFFAFB783DE81D0613B8C7D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSnapshotLastBackupTick_tDE3EE53D10E5A0F839C2BD162E0F100B1C0E3C43_m47664754B590B07BBBBE9EFA0EE7BA4601B9147F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSpawnBuffer_t1197943A694681C3FAC0C0F3C2C09D0F6DA9A1E7_m852EAF6FE241869B308E43BF6541FE2BB5F5F88A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostUpdateVersion_t74F31010DC4C97BC537DDF95D069CCE7A8EE6F3B_m0B697ADDA809280663E0CADAA267473B14029797_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationRequest_t793D74CBCD50A6ABDE6207C870BF4E7C4A25FB2F_mC7347E922FE49D5FEC7E0258894E7822A7842CF7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationStats_tDE18034DF01DE6526E9ABF564569D9DF59AF3F98_m6255420A1FA5C5C36A1F01C26ED6FE9293C51DE6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationStorage_tB54A3D46F88EA01AF9F858207660B01268B2AEB9_m59254AB00660A1341D13E6E151B28A26C64373DA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLinkedEntityGroup_t97546F2DE9AF4E5A8E97F4E215FCCA6395D0EB38_mE9932D6D9BB9C62F7AEF531CE8BF7C2A3A4193E4_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMigrateComponents_t3BA4F4C873FDF8727F39673AD03B067C678F6AA2_m03F0D48BD31BE472602521772BC660AE44DF48E7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetDebug_t04383CA2B98C846A55C5A8960A6CCA2F84B8AEB8_m7AA2E5CD9D1A2AA84EFF2A267ABD87574F67FC25_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamDriver_t09BCA975B6457E5C7517A235088519050F9952B6_mC4F0E45FECBE15839CEA93350F6A697E227595F0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkTimeSystemData_t6CF678998DCD95CDA09785B46DED450CD8874A53_mA61D7AB2E054347C602039E12980BC2CB36D3603_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisOutgoingCommandDataStreamBuffer_t74C9B36A80DF8A270BE763F2EBA733C6FC5E0A70_m42F3C278B4CAA92D678E4C3C7F09F8A04DEB0A24_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsColliderKeyEntityPair_tAEF837B39E3949BB41536084707EE655C69D40FE_mC5A4A8875E6EF47D1F65327252F076A9BB3B9F3B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsCompoundData_t25E7A437D24DFE2C810FCF3B2B950BB889513648_m34960BFF4B1D94D25519D3B5FDC4A8C6A0476CD6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsGraphicalInterpolationBuffer_t4425E9311BC421D1E03F6699B1CEDACD6598D8E9_mEBAE7050FABF64F14D7C29810C05D5EA822A917D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_mD1C40FAD70ED135D27F57C7BD54FEE4A3C144429_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldHistorySingleton_tAB64E013DD6A12815A31F2B5432265555C160209_m2239A2238DEDB2342B2CF2977D35648403D3425C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldSingleton_t378ADEC7BEB4615C6B7972AB0EC26DF2BD864AFA_m0E191D35FB6B760FEFDFCC07AB95174523A5A10E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m23D5738433CC0127CEA78AA0DE8AA0576F26BF9F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhostSpawn_t96659E85EA19D71C225AD96C6245B47BCBA92B29_m90242CEA3F0F1E1724ACF50662A9FA176D74C3A1_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnGhostBaseline_tA12CE09F9336397F5AAC7F1F995F70002471CCE7_m1CB9F69046CFEDA6400C6A7A5298BB0B701149F3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnGhostIdRange_tA869F9D0F6CB1DD79ABF8E1923B07C6D295EC734_mD7417A0D218F851EDD3EAABFF156B0D38C305B3B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnSceneLoaded_t93BAB26B3D178EBACA87F7E8978635032B016F3C_mA7AB7109BC1FF4B68186F1B9F6619E57CC52565B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mEF28DFCAD423E26B81F10A8CB792E628B9553C50_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m489D25E73D17754E1617D080BC4D80F47732BC69_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_mDA9DDA0556CCFFE8D45941BA53503BA2812E2CBD_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D_mC379C8817A25B9D2B39DB4B07A96533E4686D41D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_mBB6E1A3B821CE326AED3045B286B16AAA2243D30_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssetPtr_tB58F0A9A302FCFEFE95EAB011F522AFFB283873F_mBB5DB3E42C1BDDB96F2A8AA88913165166EDDE5A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssets_t190E68112895048346A189ADC59FD9CCAE9C73B3_m6F8DA48C67546418A606D3F2DF3EE2345F91C7C4_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRpcCollection_tF5A8386ADA59B8E4787F09F2F82406BFEECBDA11_mB21B699AA298587C6AB3C2A46115850046E36B0B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mE63D71E60B319B3370A91FD5A60641283BFBEAD6_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_m30F2158F2643D7C9BEB0138EF959CC01FE2F2F70_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSimulationSingleton_tC8F3A5395E08472F6FDD1EFF8D449D42732BBE52_m3C2CD339E07C033F82072E5E639868FA26EE8580_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSpawnedGhostEntityMap_t0BCFA4A062202D8F78450F55D68776FF38A95807_m68A55004084BB1E962BEAB28B359FD2D8D6BDC7A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStepInputSingleton_tF8533E0D6AACD3BB57B6641B05F78A5C48F3A92E_m9E5B4EA89C750E36B3353073165EB59FBFEB9851_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneWithGhostCleanup_t687703217183BD3C6CC5D419F1157A4886DC0A9E_mD2695FD6A566AD86B765890CA29454ED2249CDEF_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisURPMaterialPropertyBaseColor_t8CF3D5B869C67266D711C7954064BBC7B4012233_mE05B07850D34AB0EAB9ABA11CEBE2359F8B6A95E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisUniqueInputTickMap_tD54F27A8967281B8FC4FCD0D0113C3B1A5F5D436_m3B11CD86D34C535158387E8B8EDB356FDD3D4D8E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t3BE4D7DACA33583BBE2C8373A5C47EFC4B20049F_m1289448A6EDDF07B5229C7FBFCC9F48B79E319D7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t3C4D290E03B1550607585431A91F6254C68B5D91_mF4039B4DA6EE4DE3F43D34D2026BAC6B6F05497E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tAC4EAD27362F01BBF5BD1EDDAF3EC58ED8A36720_mF50E4BFE613D533A8E57BF4BCD315D96B1E0B7E9_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tCAA7B5B53C65D96E834EED2D2BF2AB5506867D26_m3A1D7602D30967D8B78AE0633F0CD129C726A0DD_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t26DC1AF10CA15B26730980E6E27C1EF0C2BE9477_mAB99D63691B68A0CFA1C1C9DE78049F54DD82BB3_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t1651082D66AC0E8FDCC10F98F216B9BF100ED8C4_m2AF1E6707AEBF72608178F8898735EB50A2E0533_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t64065E6CEC923A03666B8AB0360CC5BEBD4584C3_m1C299D989AA51186FDE6E61D2AAA9B8A7167C48D_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t98A3C260D7EC2417778B2B6B5C85A94CB302CEDE_mD858397FD2BEA5A31DEF9087B588F06FAF3A7315_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tAEE471B70CD3AE022A4745E8DE8A7ABD1027B7A9_mE09FB0A77084985937E1C63137044359A6DEC698_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t7B01EB05343F6EBACE8022A40F0E4ADE261DE7BF_m939EDDD6784881C87ED4781C84DA6202FF5C5761_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t374672F8E4A603D633C5ABEBA6FB5F00833D1A2D_m79F42C098FD5196D1B6B493E240BDDD32869E340_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisState_t583D7FAB6D38B74AF495A7205BBCEBEADCBAC09A_m4AA6770C3F7E3C446E8E3165C39B10C8058C7013_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m034B261205C75B76955DD2B074998C7708E87E84_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t5DD8E367CBD667FFC7D1AB73A7A2E2977008D79E_m88F5E0CF21829DAD6CDAA92C035B35E13D78E6F9_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_mEF6863C1F6A7D2877D414B4EB0215D36635861C0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m32613B7A68993E09512739825CEBD2E50AF4201A_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mF46A945D1FBC5F730FE4AB9CE92E455E9840E868_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPublicEntityRef_t499E2838255A5FCF6E1CE9B5E7C366D795D9D634_mF018CFE927579488AF20C4292FBA364866BBC730_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSwitchPredictionSmoothing_t77F66A976B2B8967484C1CDF987CA6EB0CA27D54_m72FD8CC28BD7A6680CD1A129DE5F652A3F96FC90_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_m52F6874E1B8C0B5D6C83885D95B32E602356CAD4_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostChildEntity_tBA1424BC5FFA91C3F17C633F75AD7C26078F59C2_m70CA927E5514BC3451D74FF75207BCE63FD818DC_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMeshRendererBakingData_tB57745402D0323D65CD2CF85D95648D4C699862E_m8C1E7F147ECEEBD946BA39F37EC7D07FF8E76769_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSkinnedMeshRendererBakingData_t150FE20D34A6D7BBE2D3F0BB6029B3588DA7FA36_m53301195B532F30D951D795C0A1962C762DF29EC_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisForcePrespawnListPrefabCreate_t9F075B92BAE534B12F86ADC432D8D57F6E09799E_m7024E62EC3B8A9729FD3F0FE6247CBA54E162756_gshared (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_gshared_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_gshared_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhostSpawnRequest_tF1875A417A0FD6CAB1170E11F1678E1764BA1539_m829F34926C0A340AC2D96739B01F218C3F84088E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBakedEntity_tA80601A59125E066241325C1A5191D59FAD23352_m31FAE09135CA0F29701CDE7C1901130F6F94A718_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionGameObjectUpdateTransformCleanup_t4325DBFD102F432340DCC8AA5701D7913E4F9E34_mF2C8DC4BDB8F31AC2F6F6E5B391D3BEB9ADEF960_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDeformedEntity_t8F7AE546463F5A6834571235356695DFFD2685E3_mEDDD3EAEFA2A4D216868E43D1D9ABA64325E8B69_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisableLiveConversion_t746C62A5B0E100BC2D7F32238C0F3BCC3CE2CE07_mEC7620E2DDE33A35AF5F36C78B413DD3DD36E0BC_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisEnableAnimationControllerPredictionUpdate_t6D3E235A97E377B7DAD18008455DE685F137CE59_m90B0ADF1564567D920E61B96C0CF339053DFFD60_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPresentationGameObjectPrefabReference_t1AFF652EC976B64380DB8145839D772CE5CF8A95_mC646D34F024A5AB325100490CDBBEFB50ABCB503_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPresentationGameObjectState_t4F0310F7B47CF37DE88C8818451706A83729E32D_m99D3AC2F8AAC7A08E5CFCFA5CE99D143049CACE0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamRequestDisconnect_t4D1CE81C990B34C77F1D5C540F735C8C69953324_m0C1C639B8AE47B7253939CD1762F5998EB69E8F7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisParent_t473162287DAADFBE8C1A231B52DC5D0C80687304_m8B12138A3E7C48A95753F440F4414C59E885BF21_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPendingSpawnPlaceholder_t4FA3256A1F6054A88E6E18ECB308EF9676B1B8A5_m5F297EF814EE1940C3E5EF944A7A3AF390F542C7_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceInfo_t687207DF0B7ABEFCF3D015765DE3B943AF917FD3_mD793CCE84E010C5AB5BCE93ABA33A943469DA5B2_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrefabAssetReference_t5ED5CF37BAB8B0CA45F2B99F97AA5447955E9736_mFE7F5D5A3287D32CD3E34997E18D8BA62021381B_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnsSceneInitialized_tCEA0B8F6DB786927C82C9642B8C742C87F2A1AC3_mCB2F48637F4626AB7B0A1A0CC6041F628EA4CC55_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestEntityPrefabLoaded_t7619E45BAFEDDF1F5FAD060DFD61BBB7080A8FE7_m9280A0A88A6F0BBF7615664B2772B9148992F094_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSectionEntity_tD18069CE6AD2FA61A39B747F346310DD10B77CEE_m078846ECEE3F065DCB87E457F4E17150A512D54E_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSharedMeshTracker_t32B97BE3ACFA13F4D721D6B3B1D5AF089C22FA90_m01226CD6DE3BA04F680042132A26BBF196F9A135_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionGameObjectActiveCleanup_tE1E7380BD2CA958C6AAC9DCF6A1AE76CBD95D862_m87F3F2DE88FDBBFF35981828034E7E157B7ED7EA_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabTracking_tFA42422DC954B461D79DE19415390FBAFFCF27DC_m759831DB84D3C3F05E13E00CA17D7F0B49A507FD_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ComponentType_ReadOnly_TisRuntimeObject_m93761FC33BD499D49F5261781D3813D3A587324F_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* EntityDataAccessManagedComponentExtensions_GetComponentObject_TisRuntimeObject_mEDF197D32F7C7436F640D9048E56F1AF813E4D9A_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* ___0_dataAccess, Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___1_entity, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___2_componentType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m68431935F220203D0292B8621D0AD80604D0DA33_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m6F02A97AF4DA258F3BBAA8A8BC7C45896188D3E8_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m41A5AB70F7F7F99F70A72A41C65E66BE044E2549_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m199BB7A3CBAF22F26FD007C71A3F76692916CCEA_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_mCC3183AA55D2733CF075B0BA420B2631E5F1A67C_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8E0E3674B0C5495242906CBF41B67EDDF06E64D3_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m078E25BD8009BACE0C87F2A5AF94A2A292CF4057_gshared (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_newData, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_jobhandle, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___2_outer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 ___0_componentDataList, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___2_additionalInputDep, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___3_outJobHandle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_gshared_inline (void* ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeList_1_Resize_m62AE410F7B9BB1F934C33AB8E6E65198CF695A1F_gshared (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, int32_t ___0_length, int32_t ___1_options, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA UnsafeList_1_get_Item_m32C5F76D029656B707A73DAEFC7FE6A171DC48ED_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeList_1_get_Length_m9CCC57A9A6B0D52DEA4CD66A9B78C2C5A5A12B96_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, const RuntimeMethod* method) ;

inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41_gshared)(method);
}
inline void UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*, const RuntimeMethod*))UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_gshared_inline)(__this, ___0_value, method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGoInGameRequest_tDF8F9520CB18418B3570B25E646464A90C8D2B8B_m639CBC8B7A74187E8A8EF69A4C51B753D99C2963 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGoInGameRequest_tDF8F9520CB18418B3570B25E646464A90C8D2B8B_m639CBC8B7A74187E8A8EF69A4C51B753D99C2963_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m47BA8188DCB537ED8911366260DDD9054B00BE49 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m47BA8188DCB537ED8911366260DDD9054B00BE49_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mF32B07397F399C3B9C5DE1C1AED74B5FA0F0B29E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mF32B07397F399C3B9C5DE1C1AED74B5FA0F0B29E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_m8736F800BCDEAF183953B7B8922DA04BE569102B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_m8736F800BCDEAF183953B7B8922DA04BE569102B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m864F382F53065240543247AE0DBD61F9B70B7618 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m864F382F53065240543247AE0DBD61F9B70B7618_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_mFD8268FF9C7C966C60C10879CB3B2956E7FC6FEE (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_mFD8268FF9C7C966C60C10879CB3B2956E7FC6FEE_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mED674BAF8C637D42FB820B9312EE84249EC64975 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mED674BAF8C637D42FB820B9312EE84249EC64975_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m1A81156C63974EA84F0A4643642D358A715B6A6D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m1A81156C63974EA84F0A4643642D358A715B6A6D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m35B180D8E0FB2E919950E250BE18134F7343708A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m35B180D8E0FB2E919950E250BE18134F7343708A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionLinkTransform_tBCA469674FB09DE2A20CC9E6A9B26B92462A7F11_m167A714D37B6E2167FA0AAF692B3A25A8C22F852 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCompanionLinkTransform_tBCA469674FB09DE2A20CC9E6A9B26B92462A7F11_m167A714D37B6E2167FA0AAF692B3A25A8C22F852_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostDistancePartitionShared_t2A64D9C74B21E979B0B3AD3C5D8DBE31102CC92F_m4DB2E2D0B2E1ECA6C888F68BE3E2BBDBFED82D05 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostDistancePartitionShared_t2A64D9C74B21E979B0B3AD3C5D8DBE31102CC92F_m4DB2E2D0B2E1ECA6C888F68BE3E2BBDBFED82D05_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabMetaData_tCF69584BEDF11A9D0486F3C9211F045B8C0B9544_mF0E9F2FD37BD5E7FE640240461B1A5724D1EC64C (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPrefabMetaData_tCF69584BEDF11A9D0486F3C9211F045B8C0B9544_mF0E9F2FD37BD5E7FE640240461B1A5724D1EC64C_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabRuntimeStrip_t7F62492831ECDA11D63D2F4792B1CB5FB10E5654_m8262AFA119F9096D0239E841F1CEE0E2AD2D90DF (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPrefabRuntimeStrip_t7F62492831ECDA11D63D2F4792B1CB5FB10E5654_m8262AFA119F9096D0239E841F1CEE0E2AD2D90DF_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m537342EAA4D2B3FE8B8C6180362468A4FA0F19EA (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m537342EAA4D2B3FE8B8C6180362468A4FA0F19EA_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsConstrainedBodyPair_t11C5D7FDF2C7D1E0AC01DD9AA0E95492E8C14728_m9D1B79B617CE177B561F6A0BDCB036BAB1372BF6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsConstrainedBodyPair_t11C5D7FDF2C7D1E0AC01DD9AA0E95492E8C14728_m9D1B79B617CE177B561F6A0BDCB036BAB1372BF6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsJoint_t7E81076F134608B1FDEA0070C11135E9B30A0897_mEE2012D86F5668FDA5C8C1FCCBB4EC0F7313D50B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsJoint_t7E81076F134608B1FDEA0070C11135E9B30A0897_mEE2012D86F5668FDA5C8C1FCCBB4EC0F7313D50B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_m31F3748EDFD132CF6325D066FBBB03817FD96582 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_m31F3748EDFD132CF6325D066FBBB03817FD96582_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m6E5167680CB403CE5BCEFBD109A722100C4FC127 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m6E5167680CB403CE5BCEFBD109A722100C4FC127_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_m7A56721F25F4850E27698151B4BD87DF85028EE5 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_m7A56721F25F4850E27698151B4BD87DF85028EE5_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_m315BBB7014A48D6EA91CE5F41D270F8D90D3F6C1 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_m315BBB7014A48D6EA91CE5F41D270F8D90D3F6C1_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMaterialMeshInfo_tA5DA20397A2C8CE93BBE1B1262E8B3448450117D_m5230672F6FF2F02CDAB4863BBD19ECB7A8E83239 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisMaterialMeshInfo_tA5DA20397A2C8CE93BBE1B1262E8B3448450117D_m5230672F6FF2F02CDAB4863BBD19ECB7A8E83239_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m4A43FA491A0AE43E872830E9A1C18021D64990E0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m4A43FA491A0AE43E872830E9A1C18021D64990E0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkId_t15A7021DA0A22D42A3251B2BAF4A349D27D8662B_mED3112F9956CB3E49C69694B11DA315E60B116FD (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkId_t15A7021DA0A22D42A3251B2BAF4A349D27D8662B_mED3112F9956CB3E49C69694B11DA315E60B116FD_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m3777EB9629F5FF189A339D465A78B52501BDB692 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m3777EB9629F5FF189A339D465A78B52501BDB692_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m597CCDD4EBC54745902BD61843D1ECB79E56B3A0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m597CCDD4EBC54745902BD61843D1ECB79E56B3A0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mFE5BD238935245103669D542C46955C97945BA4F (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mFE5BD238935245103669D542C46955C97945BA4F_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisAdditionalEntitiesBakingData_t16B67AE176CF0186E6E62B375C8B59BFB902D4E1_m6DCEFDA00308D5CF93ACF4FF75A1E5B207B212D1 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisAdditionalEntitiesBakingData_t16B67AE176CF0186E6E62B375C8B59BFB902D4E1_m6DCEFDA00308D5CF93ACF4FF75A1E5B207B212D1_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m0F23A448C61CCF70DF9C04FC86EB10D61DDC3A72 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m0F23A448C61CCF70DF9C04FC86EB10D61DDC3A72_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBroadphaseData_t283ED0771F35DEB34BC13ED55C73772D7CD154A3_m231A9F12C94DCC196177B0153F47393B403460E7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBroadphaseData_t283ED0771F35DEB34BC13ED55C73772D7CD154A3_m231A9F12C94DCC196177B0153F47393B403460E7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuildPhysicsWorldData_t2B48F1A635280E8C32969EF1108844731186F1B2_m11C0F36734285030D82A9424C569C0F21C28DD8D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBuildPhysicsWorldData_t2B48F1A635280E8C32969EF1108844731186F1B2_m11C0F36734285030D82A9424C569C0F21C28DD8D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapIndex_tB3FFBA44070A59D7CE3FE43E525EE67F62F7DD77_m7842F319E5F79C371C19D99A3BDABAB48983A50E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapIndex_tB3FFBA44070A59D7CE3FE43E525EE67F62F7DD77_m7842F319E5F79C371C19D99A3BDABAB48983A50E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapST_tF3B17F024F3A80DEC0F7FA53C4B605A79202D14E_m0D48267FE6D42C6E933EBC874096C29538382795 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapST_tF3B17F024F3A80DEC0F7FA53C4B605A79202D14E_m0D48267FE6D42C6E933EBC874096C29538382795_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisChild_tCA0AD12FC56504F3D4A64E40855F54238020861E_mE906F6A32DF896D9054B52C72D4CFFAE0D70A494 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisChild_tCA0AD12FC56504F3D4A64E40855F54238020861E_mE906F6A32DF896D9054B52C72D4CFFAE0D70A494_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m253E94A751C8AAD2F9AE71E695614F8BBC0DD5B0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m253E94A751C8AAD2F9AE71E695614F8BBC0DD5B0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisClientTickRate_t0E92DBFF5847A71B95752CF3292FD2FC140495C9_m390277FD3E8D44958907E1768F3B9908034DE49C (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisClientTickRate_t0E92DBFF5847A71B95752CF3292FD2FC140495C9_m390277FD3E8D44958907E1768F3B9908034DE49C_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisColliderBlobCleanupData_tFEC8BF2F69AE15547D452B79FACB5A3A88064E32_mF56C17C837A47992FA0744957F8F579F05DA3C27 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisColliderBlobCleanupData_tFEC8BF2F69AE15547D452B79FACB5A3A88064E32_mF56C17C837A47992FA0744957F8F579F05DA3C27_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostAuthoringComponentBakingData_t963B503B28A9BE4F9D7B22F4D23BFEC2BB1A255E_mEF0F44EA07DFEB48AE2DF8762EEE545B36C78ED6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostAuthoringComponentBakingData_t963B503B28A9BE4F9D7B22F4D23BFEC2BB1A255E_mEF0F44EA07DFEB48AE2DF8762EEE545B36C78ED6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCleanup_tE96F7C9F4DC59AEB2C9996CBA308E8A0603F6BBC_m78442F5D825A49D22A62F85A2BC9478AB4370516 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostCleanup_tE96F7C9F4DC59AEB2C9996CBA308E8A0603F6BBC_m78442F5D825A49D22A62F85A2BC9478AB4370516_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollection_t13EDF41F2078D02C47FB76ED953412292F745219_mB84A324CCF547FBD67690E998133E3316B02262D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostCollection_t13EDF41F2078D02C47FB76ED953412292F745219_mB84A324CCF547FBD67690E998133E3316B02262D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollectionComponentIndex_tAED81E493A6621B761612432F7D2A0374567BD84_m63920CCC9152FABBE2E08F5766B8094FD82C15FF (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostCollectionComponentIndex_tAED81E493A6621B761612432F7D2A0374567BD84_m63920CCC9152FABBE2E08F5766B8094FD82C15FF_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCollectionPrefab_t8AF4B66BAD32F1BF1FD8A7E9B236EEBDFBC81D60_m61CC8A58EF4C6E694005B54187F76C650A450856 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostCollectionPrefab_t8AF4B66BAD32F1BF1FD8A7E9B236EEBDFBC81D60_m61CC8A58EF4C6E694005B54187F76C650A450856_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostComponentSerializerCollectionData_tBA662EAD4B94AC75D75278CE1D22A56621C92191_mC7BF4B5DAF5CE5F55E0D9958CA2C1FEB85D76CD5 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostComponentSerializerCollectionData_tBA662EAD4B94AC75D75278CE1D22A56621C92191_mC7BF4B5DAF5CE5F55E0D9958CA2C1FEB85D76CD5_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostCount_t28FC783F6F6AEE97C5F7B67CA58CA6652CFC1083_m276861C40F10051DE071E11EEAE9E22E85F6BA5F (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostCount_t28FC783F6F6AEE97C5F7B67CA58CA6652CFC1083_m276861C40F10051DE071E11EEAE9E22E85F6BA5F_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostDespawnQueues_tFCC28D3C6222373756344D11F4950B1CEF4E1B5B_mAA9E66F0BC0A862293B28E564D5D202BB83FEFD8 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostDespawnQueues_tFCC28D3C6222373756344D11F4950B1CEF4E1B5B_mAA9E66F0BC0A862293B28E564D5D202BB83FEFD8_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostOwnerPredictedSwitchingQueue_tC005A4D4732805D5D7C6FB393E20241F47551491_mC966ED9D00528305CFDB87205580567B9300B224 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostOwnerPredictedSwitchingQueue_tC005A4D4732805D5D7C6FB393E20241F47551491_mC966ED9D00528305CFDB87205580567B9300B224_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionGroupTickState_tB8F7B7A4ADC6DDAD8291FA77A797B6BFF50BF0A2_m4DEFA234023B38F121CE84B02E5B962A0F23256A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPredictionGroupTickState_tB8F7B7A4ADC6DDAD8291FA77A797B6BFF50BF0A2_m4DEFA234023B38F121CE84B02E5B962A0F23256A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionHistoryState_tD55DF52D9563D83B55FA94B94BBF30A0D9F9DC28_m050C814D3893DBF216CD02CBA893469EFFBFE59A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPredictionHistoryState_tD55DF52D9563D83B55FA94B94BBF30A0D9F9DC28_m050C814D3893DBF216CD02CBA893469EFFBFE59A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionSmoothing_tB6587249ECA5A9C2182026512CFF914FF75B37E0_mE52515741C176ED61587830941DF3C059A16C7B5 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPredictionSmoothing_tB6587249ECA5A9C2182026512CFF914FF75B37E0_mE52515741C176ED61587830941DF3C059A16C7B5_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPredictionSwitchingQueues_t766AA5F381338A4D531193C3CBFFFE35055BA661_m10AA7712D2825A6D27DDFDE11E6B105635F9B4D1 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPredictionSwitchingQueues_t766AA5F381338A4D531193C3CBFFFE35055BA661_m10AA7712D2825A6D27DDFDE11E6B105635F9B4D1_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostRelevancy_t24C834524E3673B5061DBA61F39D29751B32D659_m989972E6870512C5B294502FAE3E2D3F932271D6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostRelevancy_t24C834524E3673B5061DBA61F39D29751B32D659_m989972E6870512C5B294502FAE3E2D3F932271D6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSendSystemData_tAD3978C66B82BC5C4FFB9470AD3CBF2B7B2EFC84_m8C2570044726DBC4BAFFAFB783DE81D0613B8C7D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostSendSystemData_tAD3978C66B82BC5C4FFB9470AD3CBF2B7B2EFC84_m8C2570044726DBC4BAFFAFB783DE81D0613B8C7D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSnapshotLastBackupTick_tDE3EE53D10E5A0F839C2BD162E0F100B1C0E3C43_m47664754B590B07BBBBE9EFA0EE7BA4601B9147F (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostSnapshotLastBackupTick_tDE3EE53D10E5A0F839C2BD162E0F100B1C0E3C43_m47664754B590B07BBBBE9EFA0EE7BA4601B9147F_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostSpawnBuffer_t1197943A694681C3FAC0C0F3C2C09D0F6DA9A1E7_m852EAF6FE241869B308E43BF6541FE2BB5F5F88A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostSpawnBuffer_t1197943A694681C3FAC0C0F3C2C09D0F6DA9A1E7_m852EAF6FE241869B308E43BF6541FE2BB5F5F88A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostUpdateVersion_t74F31010DC4C97BC537DDF95D069CCE7A8EE6F3B_m0B697ADDA809280663E0CADAA267473B14029797 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostUpdateVersion_t74F31010DC4C97BC537DDF95D069CCE7A8EE6F3B_m0B697ADDA809280663E0CADAA267473B14029797_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationRequest_t793D74CBCD50A6ABDE6207C870BF4E7C4A25FB2F_mC7347E922FE49D5FEC7E0258894E7822A7842CF7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisHostMigrationRequest_t793D74CBCD50A6ABDE6207C870BF4E7C4A25FB2F_mC7347E922FE49D5FEC7E0258894E7822A7842CF7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationStats_tDE18034DF01DE6526E9ABF564569D9DF59AF3F98_m6255420A1FA5C5C36A1F01C26ED6FE9293C51DE6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisHostMigrationStats_tDE18034DF01DE6526E9ABF564569D9DF59AF3F98_m6255420A1FA5C5C36A1F01C26ED6FE9293C51DE6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisHostMigrationStorage_tB54A3D46F88EA01AF9F858207660B01268B2AEB9_m59254AB00660A1341D13E6E151B28A26C64373DA (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisHostMigrationStorage_tB54A3D46F88EA01AF9F858207660B01268B2AEB9_m59254AB00660A1341D13E6E151B28A26C64373DA_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisLinkedEntityGroup_t97546F2DE9AF4E5A8E97F4E215FCCA6395D0EB38_mE9932D6D9BB9C62F7AEF531CE8BF7C2A3A4193E4 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisLinkedEntityGroup_t97546F2DE9AF4E5A8E97F4E215FCCA6395D0EB38_mE9932D6D9BB9C62F7AEF531CE8BF7C2A3A4193E4_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMigrateComponents_t3BA4F4C873FDF8727F39673AD03B067C678F6AA2_m03F0D48BD31BE472602521772BC660AE44DF48E7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisMigrateComponents_t3BA4F4C873FDF8727F39673AD03B067C678F6AA2_m03F0D48BD31BE472602521772BC660AE44DF48E7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetDebug_t04383CA2B98C846A55C5A8960A6CCA2F84B8AEB8_m7AA2E5CD9D1A2AA84EFF2A267ABD87574F67FC25 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetDebug_t04383CA2B98C846A55C5A8960A6CCA2F84B8AEB8_m7AA2E5CD9D1A2AA84EFF2A267ABD87574F67FC25_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamDriver_t09BCA975B6457E5C7517A235088519050F9952B6_mC4F0E45FECBE15839CEA93350F6A697E227595F0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkStreamDriver_t09BCA975B6457E5C7517A235088519050F9952B6_mC4F0E45FECBE15839CEA93350F6A697E227595F0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkTimeSystemData_t6CF678998DCD95CDA09785B46DED450CD8874A53_mA61D7AB2E054347C602039E12980BC2CB36D3603 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkTimeSystemData_t6CF678998DCD95CDA09785B46DED450CD8874A53_mA61D7AB2E054347C602039E12980BC2CB36D3603_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisOutgoingCommandDataStreamBuffer_t74C9B36A80DF8A270BE763F2EBA733C6FC5E0A70_m42F3C278B4CAA92D678E4C3C7F09F8A04DEB0A24 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisOutgoingCommandDataStreamBuffer_t74C9B36A80DF8A270BE763F2EBA733C6FC5E0A70_m42F3C278B4CAA92D678E4C3C7F09F8A04DEB0A24_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsColliderKeyEntityPair_tAEF837B39E3949BB41536084707EE655C69D40FE_mC5A4A8875E6EF47D1F65327252F076A9BB3B9F3B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsColliderKeyEntityPair_tAEF837B39E3949BB41536084707EE655C69D40FE_mC5A4A8875E6EF47D1F65327252F076A9BB3B9F3B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsCompoundData_t25E7A437D24DFE2C810FCF3B2B950BB889513648_m34960BFF4B1D94D25519D3B5FDC4A8C6A0476CD6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsCompoundData_t25E7A437D24DFE2C810FCF3B2B950BB889513648_m34960BFF4B1D94D25519D3B5FDC4A8C6A0476CD6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsGraphicalInterpolationBuffer_t4425E9311BC421D1E03F6699B1CEDACD6598D8E9_mEBAE7050FABF64F14D7C29810C05D5EA822A917D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsGraphicalInterpolationBuffer_t4425E9311BC421D1E03F6699B1CEDACD6598D8E9_mEBAE7050FABF64F14D7C29810C05D5EA822A917D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_mD1C40FAD70ED135D27F57C7BD54FEE4A3C144429 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_mD1C40FAD70ED135D27F57C7BD54FEE4A3C144429_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldHistorySingleton_tAB64E013DD6A12815A31F2B5432265555C160209_m2239A2238DEDB2342B2CF2977D35648403D3425C (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsWorldHistorySingleton_tAB64E013DD6A12815A31F2B5432265555C160209_m2239A2238DEDB2342B2CF2977D35648403D3425C_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsWorldSingleton_t378ADEC7BEB4615C6B7972AB0EC26DF2BD864AFA_m0E191D35FB6B760FEFDFCC07AB95174523A5A10E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsWorldSingleton_t378ADEC7BEB4615C6B7972AB0EC26DF2BD864AFA_m0E191D35FB6B760FEFDFCC07AB95174523A5A10E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m23D5738433CC0127CEA78AA0DE8AA0576F26BF9F (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m23D5738433CC0127CEA78AA0DE8AA0576F26BF9F_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhostSpawn_t96659E85EA19D71C225AD96C6245B47BCBA92B29_m90242CEA3F0F1E1724ACF50662A9FA176D74C3A1 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPredictedGhostSpawn_t96659E85EA19D71C225AD96C6245B47BCBA92B29_m90242CEA3F0F1E1724ACF50662A9FA176D74C3A1_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnGhostBaseline_tA12CE09F9336397F5AAC7F1F995F70002471CCE7_m1CB9F69046CFEDA6400C6A7A5298BB0B701149F3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrespawnGhostBaseline_tA12CE09F9336397F5AAC7F1F995F70002471CCE7_m1CB9F69046CFEDA6400C6A7A5298BB0B701149F3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnGhostIdRange_tA869F9D0F6CB1DD79ABF8E1923B07C6D295EC734_mD7417A0D218F851EDD3EAABFF156B0D38C305B3B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrespawnGhostIdRange_tA869F9D0F6CB1DD79ABF8E1923B07C6D295EC734_mD7417A0D218F851EDD3EAABFF156B0D38C305B3B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnSceneLoaded_t93BAB26B3D178EBACA87F7E8978635032B016F3C_mA7AB7109BC1FF4B68186F1B9F6619E57CC52565B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrespawnSceneLoaded_t93BAB26B3D178EBACA87F7E8978635032B016F3C_mA7AB7109BC1FF4B68186F1B9F6619E57CC52565B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mEF28DFCAD423E26B81F10A8CB792E628B9553C50 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mEF28DFCAD423E26B81F10A8CB792E628B9553C50_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m489D25E73D17754E1617D080BC4D80F47732BC69 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m489D25E73D17754E1617D080BC4D80F47732BC69_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_mDA9DDA0556CCFFE8D45941BA53503BA2812E2CBD (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_mDA9DDA0556CCFFE8D45941BA53503BA2812E2CBD_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D_mC379C8817A25B9D2B39DB4B07A96533E4686D41D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D_mC379C8817A25B9D2B39DB4B07A96533E4686D41D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_mBB6E1A3B821CE326AED3045B286B16AAA2243D30 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_mBB6E1A3B821CE326AED3045B286B16AAA2243D30_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssetPtr_tB58F0A9A302FCFEFE95EAB011F522AFFB283873F_mBB5DB3E42C1BDDB96F2A8AA88913165166EDDE5A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRetainBlobAssetPtr_tB58F0A9A302FCFEFE95EAB011F522AFFB283873F_mBB5DB3E42C1BDDB96F2A8AA88913165166EDDE5A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRetainBlobAssets_t190E68112895048346A189ADC59FD9CCAE9C73B3_m6F8DA48C67546418A606D3F2DF3EE2345F91C7C4 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRetainBlobAssets_t190E68112895048346A189ADC59FD9CCAE9C73B3_m6F8DA48C67546418A606D3F2DF3EE2345F91C7C4_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRpcCollection_tF5A8386ADA59B8E4787F09F2F82406BFEECBDA11_mB21B699AA298587C6AB3C2A46115850046E36B0B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRpcCollection_tF5A8386ADA59B8E4787F09F2F82406BFEECBDA11_mB21B699AA298587C6AB3C2A46115850046E36B0B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mE63D71E60B319B3370A91FD5A60641283BFBEAD6 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mE63D71E60B319B3370A91FD5A60641283BFBEAD6_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_m30F2158F2643D7C9BEB0138EF959CC01FE2F2F70 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_m30F2158F2643D7C9BEB0138EF959CC01FE2F2F70_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSimulationSingleton_tC8F3A5395E08472F6FDD1EFF8D449D42732BBE52_m3C2CD339E07C033F82072E5E639868FA26EE8580 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSimulationSingleton_tC8F3A5395E08472F6FDD1EFF8D449D42732BBE52_m3C2CD339E07C033F82072E5E639868FA26EE8580_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSpawnedGhostEntityMap_t0BCFA4A062202D8F78450F55D68776FF38A95807_m68A55004084BB1E962BEAB28B359FD2D8D6BDC7A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSpawnedGhostEntityMap_t0BCFA4A062202D8F78450F55D68776FF38A95807_m68A55004084BB1E962BEAB28B359FD2D8D6BDC7A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStepInputSingleton_tF8533E0D6AACD3BB57B6641B05F78A5C48F3A92E_m9E5B4EA89C750E36B3353073165EB59FBFEB9851 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisStepInputSingleton_tF8533E0D6AACD3BB57B6641B05F78A5C48F3A92E_m9E5B4EA89C750E36B3353073165EB59FBFEB9851_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSubSceneWithGhostCleanup_t687703217183BD3C6CC5D419F1157A4886DC0A9E_mD2695FD6A566AD86B765890CA29454ED2249CDEF (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSubSceneWithGhostCleanup_t687703217183BD3C6CC5D419F1157A4886DC0A9E_mD2695FD6A566AD86B765890CA29454ED2249CDEF_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisURPMaterialPropertyBaseColor_t8CF3D5B869C67266D711C7954064BBC7B4012233_mE05B07850D34AB0EAB9ABA11CEBE2359F8B6A95E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisURPMaterialPropertyBaseColor_t8CF3D5B869C67266D711C7954064BBC7B4012233_mE05B07850D34AB0EAB9ABA11CEBE2359F8B6A95E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisUniqueInputTickMap_tD54F27A8967281B8FC4FCD0D0113C3B1A5F5D436_m3B11CD86D34C535158387E8B8EDB356FDD3D4D8E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisUniqueInputTickMap_tD54F27A8967281B8FC4FCD0D0113C3B1A5F5D436_m3B11CD86D34C535158387E8B8EDB356FDD3D4D8E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t3BE4D7DACA33583BBE2C8373A5C47EFC4B20049F_m1289448A6EDDF07B5229C7FBFCC9F48B79E319D7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t3BE4D7DACA33583BBE2C8373A5C47EFC4B20049F_m1289448A6EDDF07B5229C7FBFCC9F48B79E319D7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t3C4D290E03B1550607585431A91F6254C68B5D91_mF4039B4DA6EE4DE3F43D34D2026BAC6B6F05497E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t3C4D290E03B1550607585431A91F6254C68B5D91_mF4039B4DA6EE4DE3F43D34D2026BAC6B6F05497E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tAC4EAD27362F01BBF5BD1EDDAF3EC58ED8A36720_mF50E4BFE613D533A8E57BF4BCD315D96B1E0B7E9 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_tAC4EAD27362F01BBF5BD1EDDAF3EC58ED8A36720_mF50E4BFE613D533A8E57BF4BCD315D96B1E0B7E9_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tCAA7B5B53C65D96E834EED2D2BF2AB5506867D26_m3A1D7602D30967D8B78AE0633F0CD129C726A0DD (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_tCAA7B5B53C65D96E834EED2D2BF2AB5506867D26_m3A1D7602D30967D8B78AE0633F0CD129C726A0DD_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t26DC1AF10CA15B26730980E6E27C1EF0C2BE9477_mAB99D63691B68A0CFA1C1C9DE78049F54DD82BB3 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t26DC1AF10CA15B26730980E6E27C1EF0C2BE9477_mAB99D63691B68A0CFA1C1C9DE78049F54DD82BB3_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t1651082D66AC0E8FDCC10F98F216B9BF100ED8C4_m2AF1E6707AEBF72608178F8898735EB50A2E0533 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t1651082D66AC0E8FDCC10F98F216B9BF100ED8C4_m2AF1E6707AEBF72608178F8898735EB50A2E0533_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t64065E6CEC923A03666B8AB0360CC5BEBD4584C3_m1C299D989AA51186FDE6E61D2AAA9B8A7167C48D (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t64065E6CEC923A03666B8AB0360CC5BEBD4584C3_m1C299D989AA51186FDE6E61D2AAA9B8A7167C48D_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t98A3C260D7EC2417778B2B6B5C85A94CB302CEDE_mD858397FD2BEA5A31DEF9087B588F06FAF3A7315 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t98A3C260D7EC2417778B2B6B5C85A94CB302CEDE_mD858397FD2BEA5A31DEF9087B588F06FAF3A7315_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_tAEE471B70CD3AE022A4745E8DE8A7ABD1027B7A9_mE09FB0A77084985937E1C63137044359A6DEC698 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_tAEE471B70CD3AE022A4745E8DE8A7ABD1027B7A9_mE09FB0A77084985937E1C63137044359A6DEC698_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t7B01EB05343F6EBACE8022A40F0E4ADE261DE7BF_m939EDDD6784881C87ED4781C84DA6202FF5C5761 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t7B01EB05343F6EBACE8022A40F0E4ADE261DE7BF_m939EDDD6784881C87ED4781C84DA6202FF5C5761_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t374672F8E4A603D633C5ABEBA6FB5F00833D1A2D_m79F42C098FD5196D1B6B493E240BDDD32869E340 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t374672F8E4A603D633C5ABEBA6FB5F00833D1A2D_m79F42C098FD5196D1B6B493E240BDDD32869E340_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisState_t583D7FAB6D38B74AF495A7205BBCEBEADCBAC09A_m4AA6770C3F7E3C446E8E3165C39B10C8058C7013 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisState_t583D7FAB6D38B74AF495A7205BBCEBEADCBAC09A_m4AA6770C3F7E3C446E8E3165C39B10C8058C7013_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m034B261205C75B76955DD2B074998C7708E87E84 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m034B261205C75B76955DD2B074998C7708E87E84_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSingleton_t5DD8E367CBD667FFC7D1AB73A7A2E2977008D79E_m88F5E0CF21829DAD6CDAA92C035B35E13D78E6F9 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSingleton_t5DD8E367CBD667FFC7D1AB73A7A2E2977008D79E_m88F5E0CF21829DAD6CDAA92C035B35E13D78E6F9_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_mEF6863C1F6A7D2877D414B4EB0215D36635861C0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_mEF6863C1F6A7D2877D414B4EB0215D36635861C0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m32613B7A68993E09512739825CEBD2E50AF4201A (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m32613B7A68993E09512739825CEBD2E50AF4201A_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mF46A945D1FBC5F730FE4AB9CE92E455E9840E868 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mF46A945D1FBC5F730FE4AB9CE92E455E9840E868_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPublicEntityRef_t499E2838255A5FCF6E1CE9B5E7C366D795D9D634_mF018CFE927579488AF20C4292FBA364866BBC730 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPublicEntityRef_t499E2838255A5FCF6E1CE9B5E7C366D795D9D634_mF018CFE927579488AF20C4292FBA364866BBC730_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSwitchPredictionSmoothing_t77F66A976B2B8967484C1CDF987CA6EB0CA27D54_m72FD8CC28BD7A6680CD1A129DE5F652A3F96FC90 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSwitchPredictionSmoothing_t77F66A976B2B8967484C1CDF987CA6EB0CA27D54_m72FD8CC28BD7A6680CD1A129DE5F652A3F96FC90_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_m52F6874E1B8C0B5D6C83885D95B32E602356CAD4 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_m52F6874E1B8C0B5D6C83885D95B32E602356CAD4_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostChildEntity_tBA1424BC5FFA91C3F17C633F75AD7C26078F59C2_m70CA927E5514BC3451D74FF75207BCE63FD818DC (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostChildEntity_tBA1424BC5FFA91C3F17C633F75AD7C26078F59C2_m70CA927E5514BC3451D74FF75207BCE63FD818DC_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisMeshRendererBakingData_tB57745402D0323D65CD2CF85D95648D4C699862E_m8C1E7F147ECEEBD946BA39F37EC7D07FF8E76769 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisMeshRendererBakingData_tB57745402D0323D65CD2CF85D95648D4C699862E_m8C1E7F147ECEEBD946BA39F37EC7D07FF8E76769_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSkinnedMeshRendererBakingData_t150FE20D34A6D7BBE2D3F0BB6029B3588DA7FA36_m53301195B532F30D951D795C0A1962C762DF29EC (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSkinnedMeshRendererBakingData_t150FE20D34A6D7BBE2D3F0BB6029B3588DA7FA36_m53301195B532F30D951D795C0A1962C762DF29EC_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisForcePrespawnListPrefabCreate_t9F075B92BAE534B12F86ADC432D8D57F6E09799E_m7024E62EC3B8A9729FD3F0FE6247CBA54E162756 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisForcePrespawnListPrefabCreate_t9F075B92BAE534B12F86ADC432D8D57F6E09799E_m7024E62EC3B8A9729FD3F0FE6247CBA54E162756_gshared)(method);
}
inline ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F*, int32_t, const RuntimeMethod*))NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_gshared_inline)(__this, ___0_index, method);
}
inline int32_t NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F*, const RuntimeMethod*))NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_gshared_inline)(__this, method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPredictedGhostSpawnRequest_tF1875A417A0FD6CAB1170E11F1678E1764BA1539_m829F34926C0A340AC2D96739B01F218C3F84088E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPredictedGhostSpawnRequest_tF1875A417A0FD6CAB1170E11F1678E1764BA1539_m829F34926C0A340AC2D96739B01F218C3F84088E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisBakedEntity_tA80601A59125E066241325C1A5191D59FAD23352_m31FAE09135CA0F29701CDE7C1901130F6F94A718 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisBakedEntity_tA80601A59125E066241325C1A5191D59FAD23352_m31FAE09135CA0F29701CDE7C1901130F6F94A718_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionGameObjectUpdateTransformCleanup_t4325DBFD102F432340DCC8AA5701D7913E4F9E34_mF2C8DC4BDB8F31AC2F6F6E5B391D3BEB9ADEF960 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCompanionGameObjectUpdateTransformCleanup_t4325DBFD102F432340DCC8AA5701D7913E4F9E34_mF2C8DC4BDB8F31AC2F6F6E5B391D3BEB9ADEF960_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDeformedEntity_t8F7AE546463F5A6834571235356695DFFD2685E3_mEDDD3EAEFA2A4D216868E43D1D9ABA64325E8B69 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisDeformedEntity_t8F7AE546463F5A6834571235356695DFFD2685E3_mEDDD3EAEFA2A4D216868E43D1D9ABA64325E8B69_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisableLiveConversion_t746C62A5B0E100BC2D7F32238C0F3BCC3CE2CE07_mEC7620E2DDE33A35AF5F36C78B413DD3DD36E0BC (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisDisableLiveConversion_t746C62A5B0E100BC2D7F32238C0F3BCC3CE2CE07_mEC7620E2DDE33A35AF5F36C78B413DD3DD36E0BC_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisEnableAnimationControllerPredictionUpdate_t6D3E235A97E377B7DAD18008455DE685F137CE59_m90B0ADF1564567D920E61B96C0CF339053DFFD60 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisEnableAnimationControllerPredictionUpdate_t6D3E235A97E377B7DAD18008455DE685F137CE59_m90B0ADF1564567D920E61B96C0CF339053DFFD60_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPresentationGameObjectPrefabReference_t1AFF652EC976B64380DB8145839D772CE5CF8A95_mC646D34F024A5AB325100490CDBBEFB50ABCB503 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPresentationGameObjectPrefabReference_t1AFF652EC976B64380DB8145839D772CE5CF8A95_mC646D34F024A5AB325100490CDBBEFB50ABCB503_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPresentationGameObjectState_t4F0310F7B47CF37DE88C8818451706A83729E32D_m99D3AC2F8AAC7A08E5CFCFA5CE99D143049CACE0 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPresentationGameObjectState_t4F0310F7B47CF37DE88C8818451706A83729E32D_m99D3AC2F8AAC7A08E5CFCFA5CE99D143049CACE0_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisNetworkStreamRequestDisconnect_t4D1CE81C990B34C77F1D5C540F735C8C69953324_m0C1C639B8AE47B7253939CD1762F5998EB69E8F7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisNetworkStreamRequestDisconnect_t4D1CE81C990B34C77F1D5C540F735C8C69953324_m0C1C639B8AE47B7253939CD1762F5998EB69E8F7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisParent_t473162287DAADFBE8C1A231B52DC5D0C80687304_m8B12138A3E7C48A95753F440F4414C59E885BF21 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisParent_t473162287DAADFBE8C1A231B52DC5D0C80687304_m8B12138A3E7C48A95753F440F4414C59E885BF21_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPendingSpawnPlaceholder_t4FA3256A1F6054A88E6E18ECB308EF9676B1B8A5_m5F297EF814EE1940C3E5EF944A7A3AF390F542C7 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPendingSpawnPlaceholder_t4FA3256A1F6054A88E6E18ECB308EF9676B1B8A5_m5F297EF814EE1940C3E5EF944A7A3AF390F542C7_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceInfo_t687207DF0B7ABEFCF3D015765DE3B943AF917FD3_mD793CCE84E010C5AB5BCE93ABA33A943469DA5B2 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceInfo_t687207DF0B7ABEFCF3D015765DE3B943AF917FD3_mD793CCE84E010C5AB5BCE93ABA33A943469DA5B2_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrefabAssetReference_t5ED5CF37BAB8B0CA45F2B99F97AA5447955E9736_mFE7F5D5A3287D32CD3E34997E18D8BA62021381B (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrefabAssetReference_t5ED5CF37BAB8B0CA45F2B99F97AA5447955E9736_mFE7F5D5A3287D32CD3E34997E18D8BA62021381B_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisPrespawnsSceneInitialized_tCEA0B8F6DB786927C82C9642B8C742C87F2A1AC3_mCB2F48637F4626AB7B0A1A0CC6041F628EA4CC55 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisPrespawnsSceneInitialized_tCEA0B8F6DB786927C82C9642B8C742C87F2A1AC3_mCB2F48637F4626AB7B0A1A0CC6041F628EA4CC55_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisRequestEntityPrefabLoaded_t7619E45BAFEDDF1F5FAD060DFD61BBB7080A8FE7_m9280A0A88A6F0BBF7615664B2772B9148992F094 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisRequestEntityPrefabLoaded_t7619E45BAFEDDF1F5FAD060DFD61BBB7080A8FE7_m9280A0A88A6F0BBF7615664B2772B9148992F094_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisResolvedSectionEntity_tD18069CE6AD2FA61A39B747F346310DD10B77CEE_m078846ECEE3F065DCB87E457F4E17150A512D54E (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisResolvedSectionEntity_tD18069CE6AD2FA61A39B747F346310DD10B77CEE_m078846ECEE3F065DCB87E457F4E17150A512D54E_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSharedMeshTracker_t32B97BE3ACFA13F4D721D6B3B1D5AF089C22FA90_m01226CD6DE3BA04F680042132A26BBF196F9A135 (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSharedMeshTracker_t32B97BE3ACFA13F4D721D6B3B1D5AF089C22FA90_m01226CD6DE3BA04F680042132A26BBF196F9A135_gshared)(method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisCompanionGameObjectActiveCleanup_tE1E7380BD2CA958C6AAC9DCF6A1AE76CBD95D862_m87F3F2DE88FDBBFF35981828034E7E157B7ED7EA (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisCompanionGameObjectActiveCleanup_tE1E7380BD2CA958C6AAC9DCF6A1AE76CBD95D862_m87F3F2DE88FDBBFF35981828034E7E157B7ED7EA_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ComponentType_ReadOnly_m2D5468BFC22BC6CA460ABA797AAF04F1E5D8EF5A (TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_typeIndex, const RuntimeMethod* method) ;
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisGhostPrefabTracking_tFA42422DC954B461D79DE19415390FBAFFCF27DC_m759831DB84D3C3F05E13E00CA17D7F0B49A507FD (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisGhostPrefabTracking_tFA42422DC954B461D79DE19415390FBAFFCF27DC_m759831DB84D3C3F05E13E00CA17D7F0B49A507FD_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 AllocatorHandle_op_Implicit_mDCF4431F31BB4A09438AE644785C4273F86B2B8D (int32_t ___0_a, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_tDDBE2218E06075EFCDE280D90B6FA7C4BF46BFD2 EntityQuery_ToEntityArray_m3D36DCB25EE0C3CA3D5F31C5234DFCF5860E4790 (EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90* __this, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* EntityQuery__GetImpl_m3E1EC62BB22FA905262DB3199F289864B47AA7AE_inline (EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90* __this, const RuntimeMethod* method) ;
inline ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ComponentType_ReadOnly_TisRuntimeObject_m93761FC33BD499D49F5261781D3813D3A587324F (const RuntimeMethod* method)
{
	return ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))ComponentType_ReadOnly_TisRuntimeObject_m93761FC33BD499D49F5261781D3813D3A587324F_gshared)(method);
}
inline RuntimeObject* EntityDataAccessManagedComponentExtensions_GetComponentObject_TisRuntimeObject_mEDF197D32F7C7436F640D9048E56F1AF813E4D9A (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* ___0_dataAccess, Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD ___1_entity, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___2_componentType, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, const RuntimeMethod*))EntityDataAccessManagedComponentExtensions_GetComponentObject_TisRuntimeObject_mEDF197D32F7C7436F640D9048E56F1AF813E4D9A_gshared)(___0_dataAccess, ___1_entity, ___2_componentType, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_componentType, const RuntimeMethod* method) ;
inline int32_t EntityDataAccess_InsertSharedComponent_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m68431935F220203D0292B8621D0AD80604D0DA33 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m68431935F220203D0292B8621D0AD80604D0DA33_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986_gshared)(__this, ___0_sharedComponent, method);
}
inline void EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, Il2CppFullySharedGenericStruct, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938_gshared)((EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*)__this, ___0_sharedComponent, method);
}
inline int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m6F02A97AF4DA258F3BBAA8A8BC7C45896188D3E8 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_Unmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m6F02A97AF4DA258F3BBAA8A8BC7C45896188D3E8_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927_gshared)(__this, ___0_sharedComponent, method);
}
inline int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m41A5AB70F7F7F99F70A72A41C65E66BE044E2549 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m41A5AB70F7F7F99F70A72A41C65E66BE044E2549_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB_gshared)(__this, ___0_sharedComponent, method);
}
inline int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m199BB7A3CBAF22F26FD007C71A3F76692916CCEA (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m199BB7A3CBAF22F26FD007C71A3F76692916CCEA_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222_gshared)(__this, ___0_sharedComponent, method);
}
inline TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C TypeManager_GetTypeIndex_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_mCC3183AA55D2733CF075B0BA420B2631E5F1A67C (const RuntimeMethod* method)
{
	return ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))TypeManager_GetTypeIndex_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_mCC3183AA55D2733CF075B0BA420B2631E5F1A67C_gshared)(method);
}
inline int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8E0E3674B0C5495242906CBF41B67EDDF06E64D3 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_Unmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8E0E3674B0C5495242906CBF41B67EDDF06E64D3_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410_gshared)(__this, ___0_sharedComponent, method);
}
inline int32_t EntityDataAccess_InsertSharedComponent_Unmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m078E25BD8009BACE0C87F2A5AF94A2A292CF4057 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_newData, const RuntimeMethod* method)
{
	return ((  int32_t (*) (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E, const RuntimeMethod*))EntityDataAccess_InsertSharedComponent_Unmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m078E25BD8009BACE0C87F2A5AF94A2A292CF4057_gshared)(__this, ___0_newData, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780_gshared)(__this, ___0_sharedComponent, method);
}
inline void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, Il2CppFullySharedGenericStruct, const RuntimeMethod*))EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14_gshared)((EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*)__this, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t EntityQueryImpl_CalculateEntityCount_m558615E38234893FE6A4A7DB3162A9939800C867 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* EntityDataAccess_get_DependencyManager_m393F3E50C2B049B984CCC546CE9B188E6488E879 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ComponentDependencyManager_CompleteReadAndWriteDependency_m48DAC16D2E14225B4B5D631D214740245AC7A345 (ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* __this, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054 (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t EntityComponentStore_get_GlobalSystemVersion_m19BE06808BCF2249B439A2FEAA9DF8F4DCEFA5D4_inline (EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* __this, const RuntimeMethod* method) ;
inline void EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, const RuntimeMethod*))EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F_gshared)(__this, ___0_componentDataArray, ___1_outer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 EntityQueryImpl_GetDependency_mF8A0166CFBF65428EE75B84AA491061FB9910261 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method) ;
inline void EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_jobhandle, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___2_outer, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, const RuntimeMethod*))EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F_gshared)(__this, ___0_componentDataArray, ___1_jobhandle, ___2_outer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DynamicComponentTypeHandle__ctor_m39E2F07A25D23F62BB3FF158D80FAD2CF125EC2F (DynamicComponentTypeHandle_t3E20E0F3BAD2BBFEF185BE607A282ECFEAF35CB6* __this, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA ___0_componentType, uint32_t ___1_globalSystemVersion, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ComponentDependencyManager_GetDependency_m0A677FF59E9B267E27AB5898CDEAD88CF1E0C0D7 (ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* __this, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___0_readerTypes, int32_t ___1_readerTypesCount, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* ___2_writerTypes, int32_t ___3_writerTypesCount, bool ___4_clearReadFencesAfterCombining, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 JobHandle_CombineDependencies_mA265FBED9D75AEF610251410AFC7766F40D5BB05 (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_job0, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_job1, const RuntimeMethod* method) ;
inline void EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3 (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 ___0_componentDataList, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___2_additionalInputDep, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___3_outJobHandle, const RuntimeMethod* method)
{
	((  void (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, const RuntimeMethod*))EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3_gshared)(__this, ___0_componentDataList, ___1_outer, ___2_additionalInputDep, ___3_outJobHandle, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool EntityQueryFilter_get_RequiresMatchesFilter_mE75B9A9EB4397E4364063D44B5B9094BDA71885E (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool TypeIndex_op_Equality_mB89F45E805E8BCEE5144CBB65B915C5C6841FDAA_inline (TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_lhs, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___1_rhs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 EntityQueryImpl_GetMatchingChunkCache_m02A0624170E25001E9653BB3DF1071BF0467F21A (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A* UnsafeCachedChunkList_get_ChunkIndices_m23D1D0D4A6DB3DC973C45A700D2F298557A54D27 (UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9** UnsafeMatchingArchetypePtrList_get_Ptr_mB3D87332ACA44E460C04BE0980062299360C3715 (UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* EntityComponentStore_GetArchetype_mBED719B36E99CD84831EECCB8815350088F28821_inline (EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* __this, ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A ___0_chunk, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* ChunkIterationUtility_GetChunkComponentDataROPtr_m72023A410F08B53747F1DE466CC4BADF3AE42727 (Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* ___0_archetype, ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A ___1_chunk, int32_t ___2_indexInArchetype, const RuntimeMethod* method) ;
inline ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_inline (void* ___0_ptr, const RuntimeMethod* method)
{
	return ((  ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* (*) (void*, const RuntimeMethod*))UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_gshared_inline)(___0_ptr, method);
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void EntityQueryImpl_GetSingletonChunkAndEntity_m9294DADB80BDAA2C49500FADC85AB9DACE5D995F (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_typeIndex, int32_t* ___1_outIndexInArchetype, ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A* ___2_outChunk, int32_t* ___3_outEntityIndexInChunk, const RuntimeMethod* method) ;
inline ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method)
{
	return ((  ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 (*) (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*, const RuntimeMethod*))EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135* PerChunkArray_get_ChunkData_m91CBDB364CCABDF0BD9DCC037E3F974C31511A65 (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ChunkIndex_op_Implicit_m8816E6F68BE715713DCAB578270F3DE6D6B07A85_inline (ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A ___0_index, const RuntimeMethod* method) ;
inline void UnsafeList_1_Resize_m62AE410F7B9BB1F934C33AB8E6E65198CF695A1F (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, int32_t ___0_length, int32_t ___1_options, const RuntimeMethod* method)
{
	((  void (*) (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*, int32_t, int32_t, const RuntimeMethod*))UnsafeList_1_Resize_m62AE410F7B9BB1F934C33AB8E6E65198CF695A1F_gshared)(__this, ___0_length, ___1_options, method);
}
inline ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA UnsafeList_1_get_Item_m32C5F76D029656B707A73DAEFC7FE6A171DC48ED_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*, int32_t, const RuntimeMethod*))UnsafeList_1_get_Item_m32C5F76D029656B707A73DAEFC7FE6A171DC48ED_gshared_inline)(__this, ___0_index, method);
}
inline int32_t UnsafeList_1_get_Length_m9CCC57A9A6B0D52DEA4CD66A9B78C2C5A5A12B96_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*, const RuntimeMethod*))UnsafeList_1_get_Length_m9CCC57A9A6B0D52DEA4CD66A9B78C2C5A5A12B96_gshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t CollectionHelper_AssumePositive_mD1EC1F05F50F605141D9BA5D70C4332AC902B4B1_inline (int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_TisGoInGameRequest_tDF8F9520CB18418B3570B25E646464A90C8D2B8B_m12419D783D90982C05D79597876603A2AE010F3E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGoInGameRequest_tDF8F9520CB18418B3570B25E646464A90C8D2B8B_m639CBC8B7A74187E8A8EF69A4C51B753D99C2963(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m9C6033A2C94987141FE7897163B185750463C8A7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m47BA8188DCB537ED8911366260DDD9054B00BE49(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_m659566A890776772467D4FE50FC2CAC469AA9BFB_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSendRpcCommandRequest_t04BAEEA519602F115089FD9526C06660D2AF702E_m657EC137B43E232DD2AD18CDB35219BCF4BDEA41(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mF32B07397F399C3B9C5DE1C1AED74B5FA0F0B29E(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_mD1E5AC48461F24D9A20A96313D7C68245CB88C7E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_m8736F800BCDEAF183953B7B8922DA04BE569102B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m92E519F4516B76CB195B36F35079C798897EBC5E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m864F382F53065240543247AE0DBD61F9B70B7618(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_m24D42132EF5665B6156F5D9D94ABB8EE38CA0895_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_mFD8268FF9C7C966C60C10879CB3B2956E7FC6FEE(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mAA08F7DFF7C2F1F1F84023858B6082226B1E07AD_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mED674BAF8C637D42FB820B9312EE84249EC64975(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m9FD0AD7978FDCA8D1BB9480F789E8131BF55E1F4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m1A81156C63974EA84F0A4643642D358A715B6A6D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m7BF8F79FE755556BAEF48214551F07B86D841850_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m2D97582FBBB6B4F7BDA68A1C05F4343176530A3B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_m89838E563AC85F153446CA6FB54431472CF3C12B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_mD4E3642D642F0FD0231233160E5FC0E3A0B9463E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mB467ECAB5BEC54EF8CAE9524DA564136BDC2BEE3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_TisCompanionLinkTransform_tBCA469674FB09DE2A20CC9E6A9B26B92462A7F11_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m7861724F0FB868C7401FEBD2317A8FCAC18DA474_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m35B180D8E0FB2E919950E250BE18134F7343708A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCompanionLinkTransform_tBCA469674FB09DE2A20CC9E6A9B26B92462A7F11_m167A714D37B6E2167FA0AAF692B3A25A8C22F852(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisGhostDistancePartitionShared_t2A64D9C74B21E979B0B3AD3C5D8DBE31102CC92F_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_mBB22630549EAEA83660DE0EE3FD4B70377A23A2B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostDistancePartitionShared_t2A64D9C74B21E979B0B3AD3C5D8DBE31102CC92F_m4DB2E2D0B2E1ECA6C888F68BE3E2BBDBFED82D05(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisGhostPrefabMetaData_tCF69584BEDF11A9D0486F3C9211F045B8C0B9544_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_TisGhostPrefabRuntimeStrip_t7F62492831ECDA11D63D2F4792B1CB5FB10E5654_m166583B1D4E26F77FBC40E3E7F79B7B6DDB96069_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPrefabMetaData_tCF69584BEDF11A9D0486F3C9211F045B8C0B9544_mF0E9F2FD37BD5E7FE640240461B1A5724D1EC64C(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostPrefabRuntimeStrip_t7F62492831ECDA11D63D2F4792B1CB5FB10E5654_m8262AFA119F9096D0239E841F1CEE0E2AD2D90DF(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_mE3A45EB08F84EFCFC3364DF78B2BD167A415CE4C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_mA7ED3A98EE122A3F2C02A5CBD8D230F6606F7A82_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m537342EAA4D2B3FE8B8C6180362468A4FA0F19EA(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisPhysicsConstrainedBodyPair_t11C5D7FDF2C7D1E0AC01DD9AA0E95492E8C14728_TisPhysicsJoint_t7E81076F134608B1FDEA0070C11135E9B30A0897_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m36EDAF93F0930870769ECB1AB011408577BAB100_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsConstrainedBodyPair_t11C5D7FDF2C7D1E0AC01DD9AA0E95492E8C14728_m9D1B79B617CE177B561F6A0BDCB036BAB1372BF6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPhysicsJoint_t7E81076F134608B1FDEA0070C11135E9B30A0897_mEE2012D86F5668FDA5C8C1FCCBB4EC0F7313D50B(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mE3856C666E4026D5A034F02CFF8B41F06D418F5C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_m31F3748EDFD132CF6325D066FBBB03817FD96582(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m6E5167680CB403CE5BCEFBD109A722100C4FC127(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m953C8B22F5D56EA56EFB86171C2AC4E14D9743BE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_mF2B55DA1FA9C1149F13297C0B9CABABE8063F6D1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSnapshotData_t6B1E9DEBD977F5E7CC7EAEA947DB0F618B972E55_m8736F800BCDEAF183953B7B8922DA04BE569102B(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_m7A56721F25F4850E27698151B4BD87DF85028EE5(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_TisMaterialMeshInfo_tA5DA20397A2C8CE93BBE1B1262E8B3448450117D_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mBB50ECA7747DAAB0C13B392318C854817EC8DE6D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_m315BBB7014A48D6EA91CE5F41D270F8D90D3F6C1(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisMaterialMeshInfo_tA5DA20397A2C8CE93BBE1B1262E8B3448450117D_m5230672F6FF2F02CDAB4863BBD19ECB7A8E83239(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mAA83E7EEE19BAE62152885822A2EC4208D73614B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m90909D010E9AADD6871F610AC41B49FF6138B727_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = TypeManager_GetTypeIndex_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m4A43FA491A0AE43E872830E9A1C18021D64990E0(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisNetworkId_t15A7021DA0A22D42A3251B2BAF4A349D27D8662B_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m806967A2D3B85B5EE4B8ACDC46AECA9C4E059721_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkId_t15A7021DA0A22D42A3251B2BAF4A349D27D8662B_mED3112F9956CB3E49C69694B11DA315E60B116FD(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m3777EB9629F5FF189A339D465A78B52501BDB692(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = TypeManager_GetTypeIndex_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m597CCDD4EBC54745902BD61843D1ECB79E56B3A0(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m80DAD71557A1F1732E54B3263278CA268BB76BCC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mAFDA6676515D3D6088E5AF09E2207A1338ECE062_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = TypeManager_GetTypeIndex_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mFE5BD238935245103669D542C46955C97945BA4F(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_m6493D2BDDE2295A449C1C59BFB4A6AEDFDA3F979_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostOwner_t00E10310781534F6A1E9BD56773C9BEE64046FE9_m5D55C72709635A7AC7831132DF8F2456EEDECDF3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = TypeManager_GetTypeIndex_TisAutoCommandTarget_t2DDAA53D1DF20CAAD90902389BEF5E6088EFC191_mFE5BD238935245103669D542C46955C97945BA4F(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m146B3D708331CF42A3CE7FC9CA1DA3D4AE0AE166_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m89472431128FE99492111181D36CBB1C6D18CBAE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		L_18->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_19 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m683C5806E4BEA7CA74F0B58DA7F52F7A3F8CF393_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_19 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_18->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_20;
		L_20 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		(&V_0)->___TypeIndex = L_20;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_19, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_21 = __this->____builderDataPtr;
		NullCheck(L_21);
		L_21->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_22 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAll_TisIl2CppFullySharedGenericAny_m0F97DF3E84CAD7F2CC1E8D6BCC5D7DED59D2FE10_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, Il2CppFullySharedGenericAny* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		Il2CppFullySharedGenericAny* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_5;
		L_5 = ConstrainedFuncInvoker1< ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 2), L_4, (void*)L_2, L_3);
		V_1 = L_5;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0028:
	{
		int32_t L_7 = V_0;
		Il2CppFullySharedGenericAny* L_8 = ___0_componentTypes;
		int32_t L_10;
		L_10 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 3), L_9, (void*)L_8);
		if ((((int32_t)L_7) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_11 = __this->____builderDataPtr;
		NullCheck(L_11);
		L_11->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_12 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllChunkComponent_TisIl2CppFullySharedGenericAny_mB7B541E89CDEC4148A6DF23106B0D38F86ED8DAB_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllChunkComponentRW_TisIl2CppFullySharedGenericAny_m22E9FE998E260FDD6F797AB8E6F383EF256498FF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mE71DF05996E1379B87C2994530E0E3CA84654D4B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_t497986DB2B7E6C5F65C3E78A6208B720FCCA7C3F_mA77F5FC5881C45805D0DF2764B90D971199CB927(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_mE541FFAB4EB736D613BC6F293B4359579054C88C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisInputBufferData_1_tEF202C700C36973CEFED86A7A7264695B5D1E0AD_m24A9AF9B591C3FB3B184A75A94A9628569CDE6E3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisAdditionalEntitiesBakingData_t16B67AE176CF0186E6E62B375C8B59BFB902D4E1_mD0DEC2F8E756128EDCBC725A3F061D8E5FA66E64_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisAdditionalEntitiesBakingData_t16B67AE176CF0186E6E62B375C8B59BFB902D4E1_m6DCEFDA00308D5CF93ACF4FF75A1E5B207B212D1(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m616C15DEFB625DB9ED372B07E7FA363BE48BE75E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m0F23A448C61CCF70DF9C04FC86EB10D61DDC3A72(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisBroadphaseData_t283ED0771F35DEB34BC13ED55C73772D7CD154A3_m4D7E4DFEF071DFA94C0530498B601CBD4297C111_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBroadphaseData_t283ED0771F35DEB34BC13ED55C73772D7CD154A3_m231A9F12C94DCC196177B0153F47393B403460E7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisBuildPhysicsWorldData_t2B48F1A635280E8C32969EF1108844731186F1B2_m99487B4552A1A5DE3DA3171784BF27A950E71B3E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBuildPhysicsWorldData_t2B48F1A635280E8C32969EF1108844731186F1B2_m11C0F36734285030D82A9424C569C0F21C28DD8D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisBuiltinMaterialPropertyUnity_LightmapIndex_tB3FFBA44070A59D7CE3FE43E525EE67F62F7DD77_m079C73D791E515EED35D8147B80DEE6F126D24C8_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapIndex_tB3FFBA44070A59D7CE3FE43E525EE67F62F7DD77_m7842F319E5F79C371C19D99A3BDABAB48983A50E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisBuiltinMaterialPropertyUnity_LightmapST_tF3B17F024F3A80DEC0F7FA53C4B605A79202D14E_mCB3008EE6288956E7D6DD78EC9BAC7FE2DAA1783_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBuiltinMaterialPropertyUnity_LightmapST_tF3B17F024F3A80DEC0F7FA53C4B605A79202D14E_m0D48267FE6D42C6E933EBC874096C29538382795(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisChild_tCA0AD12FC56504F3D4A64E40855F54238020861E_mD5AEDD52728F75584FD93285FD48111FA7EDC0C3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisChild_tCA0AD12FC56504F3D4A64E40855F54238020861E_mE906F6A32DF896D9054B52C72D4CFFAE0D70A494(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m2823A0F7F190FFD77F62E6E7EB59BE8BCC647BCC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m253E94A751C8AAD2F9AE71E695614F8BBC0DD5B0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisClientTickRate_t0E92DBFF5847A71B95752CF3292FD2FC140495C9_m6E8A27BF6D6B06694C6C5B2B521286371A802964_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisClientTickRate_t0E92DBFF5847A71B95752CF3292FD2FC140495C9_m390277FD3E8D44958907E1768F3B9908034DE49C(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisColliderBlobCleanupData_tFEC8BF2F69AE15547D452B79FACB5A3A88064E32_m859B5CCF9115839A625B737B4D81C38A1A79901C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisColliderBlobCleanupData_tFEC8BF2F69AE15547D452B79FACB5A3A88064E32_mF56C17C837A47992FA0744957F8F579F05DA3C27(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m56D9EAB88C7C153E870764BD0AA70922C5F586AD_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCommandTarget_tEA67C6BE043BB1BBC06C4561C6829C20067BCC01_m3777EB9629F5FF189A339D465A78B52501BDB692(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_mD992C3CDCDA1EEDCEFFB2EABD23D60CBE8523F0A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisConnectionUniqueId_t888A577417BA125A54FEAF96DDA34B57619FEFA1_m597CCDD4EBC54745902BD61843D1ECB79E56B3A0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_mC34084D9C1B34A1FAE5218ACDA82225DB542D1ED_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCubeInput_tDABEE6E4B437F22ABF09877B18DF027BA628F9F8_m86087B7A6F88CF929FAF8E28E20ABB121727AFD3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m7EA732E2ADFD5351972F85B0E53F1FAF135CC0AA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCubeInput_t6048A02ABB4A6787B786329F7CE132844EB3B2A5_m80EF2469C8894694B3E66CD173E48E55D32660C6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m73C640DD9418380E702D6FD80520B4A466A7D561_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCustomPhysicsProxyDriver_tA12A54FDC4F2780192F2BCB674A38F48A584F225_m6E5167680CB403CE5BCEFBD109A722100C4FC127(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostAuthoringComponentBakingData_t963B503B28A9BE4F9D7B22F4D23BFEC2BB1A255E_m5DAAE5ED70F4923C56CA2DD1C3D9136841EC21B4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostAuthoringComponentBakingData_t963B503B28A9BE4F9D7B22F4D23BFEC2BB1A255E_mEF0F44EA07DFEB48AE2DF8762EEE545B36C78ED6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostCleanup_tE96F7C9F4DC59AEB2C9996CBA308E8A0603F6BBC_m2413EF02990143CAC4277A8A25181558833B702B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostCleanup_tE96F7C9F4DC59AEB2C9996CBA308E8A0603F6BBC_m78442F5D825A49D22A62F85A2BC9478AB4370516(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostCollection_t13EDF41F2078D02C47FB76ED953412292F745219_mF8223B1DAFD329920197BF87E6DC379E0EC767B4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostCollection_t13EDF41F2078D02C47FB76ED953412292F745219_mB84A324CCF547FBD67690E998133E3316B02262D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostCollectionComponentIndex_tAED81E493A6621B761612432F7D2A0374567BD84_m0372D18B5DE6251D43EE27F4CEF25437E32E22F4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostCollectionComponentIndex_tAED81E493A6621B761612432F7D2A0374567BD84_m63920CCC9152FABBE2E08F5766B8094FD82C15FF(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostCollectionPrefab_t8AF4B66BAD32F1BF1FD8A7E9B236EEBDFBC81D60_m3A6E9554EF5B4FED3B098EBE2C1531268EB28BE3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostCollectionPrefab_t8AF4B66BAD32F1BF1FD8A7E9B236EEBDFBC81D60_m61CC8A58EF4C6E694005B54187F76C650A450856(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostComponentSerializerCollectionData_tBA662EAD4B94AC75D75278CE1D22A56621C92191_mFEACF51B45C11D4A27C06FC7DB339234FA519ADE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostComponentSerializerCollectionData_tBA662EAD4B94AC75D75278CE1D22A56621C92191_mC7BF4B5DAF5CE5F55E0D9958CA2C1FEB85D76CD5(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostCount_t28FC783F6F6AEE97C5F7B67CA58CA6652CFC1083_m3980C3C9F97F69852364E2CB850777B2D4B7A043_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostCount_t28FC783F6F6AEE97C5F7B67CA58CA6652CFC1083_m276861C40F10051DE071E11EEAE9E22E85F6BA5F(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostDespawnQueues_tFCC28D3C6222373756344D11F4950B1CEF4E1B5B_m586622557C2B64894E49C5F76B9DE3F0ACEE34CA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostDespawnQueues_tFCC28D3C6222373756344D11F4950B1CEF4E1B5B_mAA9E66F0BC0A862293B28E564D5D202BB83FEFD8(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m5112E4E2C76386DCAA26C8FE17FC2CD2C28CDE87_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m940ADCC288B6533F03C274777D94FB9E57212BB4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostOwnerIsLocal_t4E499D03832B8417A5F683345468DBF00BED0D9F_m429A072DFC20903E1578F2F87BC665BF94792F73(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostOwnerPredictedSwitchingQueue_tC005A4D4732805D5D7C6FB393E20241F47551491_mE8F560924388F4294879ED413D907C87241A1F11_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostOwnerPredictedSwitchingQueue_tC005A4D4732805D5D7C6FB393E20241F47551491_mC966ED9D00528305CFDB87205580567B9300B224(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostPredictionGroupTickState_tB8F7B7A4ADC6DDAD8291FA77A797B6BFF50BF0A2_m1F71014C37C4F3C8D2F9B76FD6928726E36848AA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPredictionGroupTickState_tB8F7B7A4ADC6DDAD8291FA77A797B6BFF50BF0A2_m4DEFA234023B38F121CE84B02E5B962A0F23256A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostPredictionHistoryState_tD55DF52D9563D83B55FA94B94BBF30A0D9F9DC28_m6CD7FAA994D683D00D8FD586D3F2CDB3911916D1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPredictionHistoryState_tD55DF52D9563D83B55FA94B94BBF30A0D9F9DC28_m050C814D3893DBF216CD02CBA893469EFFBFE59A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostPredictionSmoothing_tB6587249ECA5A9C2182026512CFF914FF75B37E0_mA8FE019A6784D436D7803978F05CEE475378C83E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPredictionSmoothing_tB6587249ECA5A9C2182026512CFF914FF75B37E0_mE52515741C176ED61587830941DF3C059A16C7B5(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostPredictionSwitchingQueues_t766AA5F381338A4D531193C3CBFFFE35055BA661_m52DF1B8B1B3CC903EFBA6F7BE5FFC42114ABD95A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPredictionSwitchingQueues_t766AA5F381338A4D531193C3CBFFFE35055BA661_m10AA7712D2825A6D27DDFDE11E6B105635F9B4D1(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostRelevancy_t24C834524E3673B5061DBA61F39D29751B32D659_m249C615CC73092381A60078AC935EFA21065F260_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostRelevancy_t24C834524E3673B5061DBA61F39D29751B32D659_m989972E6870512C5B294502FAE3E2D3F932271D6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostSendSystemData_tAD3978C66B82BC5C4FFB9470AD3CBF2B7B2EFC84_m77E294D71ECD1C6E33CDB8A80B0E5E8F091504CD_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostSendSystemData_tAD3978C66B82BC5C4FFB9470AD3CBF2B7B2EFC84_m8C2570044726DBC4BAFFAFB783DE81D0613B8C7D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostSnapshotLastBackupTick_tDE3EE53D10E5A0F839C2BD162E0F100B1C0E3C43_m93B1F9A6F1414CC96E46BBF37DA292645CB3BCDA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostSnapshotLastBackupTick_tDE3EE53D10E5A0F839C2BD162E0F100B1C0E3C43_m47664754B590B07BBBBE9EFA0EE7BA4601B9147F(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostSpawnBuffer_t1197943A694681C3FAC0C0F3C2C09D0F6DA9A1E7_m478A7AE41638D07EEC5B8017C2D19BA4442F9B46_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostSpawnBuffer_t1197943A694681C3FAC0C0F3C2C09D0F6DA9A1E7_m852EAF6FE241869B308E43BF6541FE2BB5F5F88A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisGhostUpdateVersion_t74F31010DC4C97BC537DDF95D069CCE7A8EE6F3B_m6D930086D19C00FE18D2D8A52DD5B8BA6FD29705_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostUpdateVersion_t74F31010DC4C97BC537DDF95D069CCE7A8EE6F3B_m0B697ADDA809280663E0CADAA267473B14029797(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisHostMigrationRequest_t793D74CBCD50A6ABDE6207C870BF4E7C4A25FB2F_m178A93046B2F62B9E9A166AEE36BD7171CEF059D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisHostMigrationRequest_t793D74CBCD50A6ABDE6207C870BF4E7C4A25FB2F_mC7347E922FE49D5FEC7E0258894E7822A7842CF7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisHostMigrationStats_tDE18034DF01DE6526E9ABF564569D9DF59AF3F98_mC3179DBF4A473E32325292DE9EDC96D0FC3DCF6E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisHostMigrationStats_tDE18034DF01DE6526E9ABF564569D9DF59AF3F98_m6255420A1FA5C5C36A1F01C26ED6FE9293C51DE6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisHostMigrationStorage_tB54A3D46F88EA01AF9F858207660B01268B2AEB9_mA8403655A987426C74335E9DA9DC0FA9E434143B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisHostMigrationStorage_tB54A3D46F88EA01AF9F858207660B01268B2AEB9_m59254AB00660A1341D13E6E151B28A26C64373DA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m03370A92101F2FBD95360F7830AA09EA4F212F85_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisIncomingCommandDataStreamBuffer_t2976645F480CEBDE41DA0C7C7087249B04E21C4D_m537342EAA4D2B3FE8B8C6180362468A4FA0F19EA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisLinkedEntityGroup_t97546F2DE9AF4E5A8E97F4E215FCCA6395D0EB38_mA5CF82C359967973C01E99A9BC60630DA43E8D85_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLinkedEntityGroup_t97546F2DE9AF4E5A8E97F4E215FCCA6395D0EB38_mE9932D6D9BB9C62F7AEF531CE8BF7C2A3A4193E4(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m98542EA7EC88AA51489DDDC32C086CCD52AE7DE2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m055C2BA2CCC85BCD4A93D2A460E1A287AB9AD04D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisMigrateComponents_t3BA4F4C873FDF8727F39673AD03B067C678F6AA2_m21D1D4C79B445F90D88C61634FFCD7AD64AD30F0_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisMigrateComponents_t3BA4F4C873FDF8727F39673AD03B067C678F6AA2_m03F0D48BD31BE472602521772BC660AE44DF48E7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisNetDebug_t04383CA2B98C846A55C5A8960A6CCA2F84B8AEB8_m7376A10E3794852CB27E4996996062146581724A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetDebug_t04383CA2B98C846A55C5A8960A6CCA2F84B8AEB8_m7AA2E5CD9D1A2AA84EFF2A267ABD87574F67FC25(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_mD623EBE43C1FE3BAC752DD097922B636B803E985_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkSnapshotAck_tEBFBE4349E543087DE15E67A67024EF80A8D1C51_m7E3D5387743B797F3102A04A73201B028796B8EF(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m5744ED98B3CDEEE0E3E122EB4F456A68FB112CD4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamConnection_t98A98017358147EFE1F0C4FEB79C8CF376E44620_m9FB73CA49A71611CC798F3729B6EB08530B638D6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisNetworkStreamDriver_t09BCA975B6457E5C7517A235088519050F9952B6_m2D3A61869DE4C2D75ABFEC21372A2CF6F9DFAD85_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamDriver_t09BCA975B6457E5C7517A235088519050F9952B6_mC4F0E45FECBE15839CEA93350F6A697E227595F0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisNetworkTimeSystemData_t6CF678998DCD95CDA09785B46DED450CD8874A53_m1287C06194A3755AAEBB883F9FD3CA97F6F85F9F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkTimeSystemData_t6CF678998DCD95CDA09785B46DED450CD8874A53_mA61D7AB2E054347C602039E12980BC2CB36D3603(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisOutgoingCommandDataStreamBuffer_t74C9B36A80DF8A270BE763F2EBA733C6FC5E0A70_m10194C626F0A62A3B334EDEF3CB7D4CE62F39E0A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisOutgoingCommandDataStreamBuffer_t74C9B36A80DF8A270BE763F2EBA733C6FC5E0A70_m42F3C278B4CAA92D678E4C3C7F09F8A04DEB0A24(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mAB7B83060DCFD112081C37C353958C5C0DC7EC3D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsColliderKeyEntityPair_tAEF837B39E3949BB41536084707EE655C69D40FE_m5A416A228D4A6F4E22D12D09A0296B40D16ACB6D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsColliderKeyEntityPair_tAEF837B39E3949BB41536084707EE655C69D40FE_mC5A4A8875E6EF47D1F65327252F076A9BB3B9F3B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsCompoundData_t25E7A437D24DFE2C810FCF3B2B950BB889513648_m08FA3D0CB15E785F9ADAB2F988466D830C809F00_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsCompoundData_t25E7A437D24DFE2C810FCF3B2B950BB889513648_m34960BFF4B1D94D25519D3B5FDC4A8C6A0476CD6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsGraphicalInterpolationBuffer_t4425E9311BC421D1E03F6699B1CEDACD6598D8E9_m83EE4DA23C86F535DA3C7AF3090DBC4F84CB0871_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsGraphicalInterpolationBuffer_t4425E9311BC421D1E03F6699B1CEDACD6598D8E9_mEBAE7050FABF64F14D7C29810C05D5EA822A917D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_mD984FE7022B77F398BC7F185B0D394358579491B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsGraphicalSmoothing_t9C3A887741C265D0E64E04E05F9FB8DA8B2716A4_m4A43FA491A0AE43E872830E9A1C18021D64990E0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_mA868FAF0D4A24331236385BB816AC423EA0E5E3E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsMass_t89D2497E5A7CAD756D1DCA9A91394F291AB191A2_m31F3748EDFD132CF6325D066FBBB03817FD96582(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_m60C54AD16F7EFCB7B38FCD14F6F7F3E636E66475_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_mD1C40FAD70ED135D27F57C7BD54FEE4A3C144429(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m5B8326A57AD9CCE8DA15DFAF2189BADA241923AE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsWorldHistorySingleton_tAB64E013DD6A12815A31F2B5432265555C160209_m87F632FC63D050589125B98F327B200F98DF5DE6_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsWorldHistorySingleton_tAB64E013DD6A12815A31F2B5432265555C160209_m2239A2238DEDB2342B2CF2977D35648403D3425C(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPhysicsWorldSingleton_t378ADEC7BEB4615C6B7972AB0EC26DF2BD864AFA_m49D1645D8CABAE811836AEBD2985ACBC305340E5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsWorldSingleton_t378ADEC7BEB4615C6B7972AB0EC26DF2BD864AFA_m0E191D35FB6B760FEFDFCC07AB95174523A5A10E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m9A1762856FAAFD39D26AABDEE16B576C8919B280_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m23D5738433CC0127CEA78AA0DE8AA0576F26BF9F(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPredictedGhostSpawn_t96659E85EA19D71C225AD96C6245B47BCBA92B29_m4670473A1E8FFFD848FB42F50803ADE9BF7BDBF1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPredictedGhostSpawn_t96659E85EA19D71C225AD96C6245B47BCBA92B29_m90242CEA3F0F1E1724ACF50662A9FA176D74C3A1(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPrespawnGhostBaseline_tA12CE09F9336397F5AAC7F1F995F70002471CCE7_m171E6F1AA2D7C02F50D44314D3D0F3C7387506E1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrespawnGhostBaseline_tA12CE09F9336397F5AAC7F1F995F70002471CCE7_m1CB9F69046CFEDA6400C6A7A5298BB0B701149F3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPrespawnGhostIdRange_tA869F9D0F6CB1DD79ABF8E1923B07C6D295EC734_m0FEA981BA3D35C614A5B92EB473A753CEE3F691C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrespawnGhostIdRange_tA869F9D0F6CB1DD79ABF8E1923B07C6D295EC734_mD7417A0D218F851EDD3EAABFF156B0D38C305B3B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPrespawnSceneLoaded_t93BAB26B3D178EBACA87F7E8978635032B016F3C_m14BE50C77D1A6ABB6D1B3267B76F1CC2E3F589F3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrespawnSceneLoaded_t93BAB26B3D178EBACA87F7E8978635032B016F3C_mA7AB7109BC1FF4B68186F1B9F6619E57CC52565B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mE9B7505E51FF4C462AB5337A979BCB4D0F3B34F4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mEF28DFCAD423E26B81F10A8CB792E628B9553C50(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_mDE12B542DF5364E743F4A0751D360E66F611736B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRenderMeshUnmanaged_tE7BB4BC0043D5F2763A5D79EF50E34D65BAFB9C0_m315BBB7014A48D6EA91CE5F41D270F8D90D3F6C1(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_mA2AD43A8ED9DD5E85244461C553382BED36716AA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m489D25E73D17754E1617D080BC4D80F47732BC69(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_m0F4EF20C6ABB1C1F2F32DBFC82E2006ECF667AE9_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_m4615EAD4118CFB0A0BD88AC6747A09C23FBEB095_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_mDA9DDA0556CCFFE8D45941BA53503BA2812E2CBD(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D_m9B2F497C06397E5818C8B4CB0C029FF911A60296_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisResolvedSectionPath_t87B9F3F0B0115B2D7CCADAD376C33481F1B5BE1D_mC379C8817A25B9D2B39DB4B07A96533E4686D41D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_m42875AD3DFEC7289BF888FF25031F05E8224FBC9_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_mBB6E1A3B821CE326AED3045B286B16AAA2243D30(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRetainBlobAssetPtr_tB58F0A9A302FCFEFE95EAB011F522AFFB283873F_m09EAA76B9F83FC79897B7C8316349A35F7A6550F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRetainBlobAssetPtr_tB58F0A9A302FCFEFE95EAB011F522AFFB283873F_mBB5DB3E42C1BDDB96F2A8AA88913165166EDDE5A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRetainBlobAssets_t190E68112895048346A189ADC59FD9CCAE9C73B3_m8959F9FD2FD208152E82D3CE880267FC5EBD094F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRetainBlobAssets_t190E68112895048346A189ADC59FD9CCAE9C73B3_m6F8DA48C67546418A606D3F2DF3EE2345F91C7C4(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRpcCollection_tF5A8386ADA59B8E4787F09F2F82406BFEECBDA11_m2240DBC4FF3A836519D761DF6223E1ED7186B7A1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRpcCollection_tF5A8386ADA59B8E4787F09F2F82406BFEECBDA11_mB21B699AA298587C6AB3C2A46115850046E36B0B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mA543A8CAAF1836E0B8E5689EC77CAF2E9A199F46_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mE63D71E60B319B3370A91FD5A60641283BFBEAD6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m4BD016AA95EAAFB445F04F1ECD21583E98A373FC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_mA985C56A3FE45954A36D711D83966027E0688F5F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_m30F2158F2643D7C9BEB0138EF959CC01FE2F2F70(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSimulationSingleton_tC8F3A5395E08472F6FDD1EFF8D449D42732BBE52_m5B5870AD2E182A530DB1AAC609C38E6D6F4C77EE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSimulationSingleton_tC8F3A5395E08472F6FDD1EFF8D449D42732BBE52_m3C2CD339E07C033F82072E5E639868FA26EE8580(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_mBEF6C43F2CF868D29433717A062AEC5F7412242E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSnapshotDataBuffer_tBA1761F30A19383F777879F53C1C3FE2528CACE3_m7A56721F25F4850E27698151B4BD87DF85028EE5(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSpawnedGhostEntityMap_t0BCFA4A062202D8F78450F55D68776FF38A95807_m44AAC146C69093D594EE3FFB3488DCCA2B9EF4C6_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSpawnedGhostEntityMap_t0BCFA4A062202D8F78450F55D68776FF38A95807_m68A55004084BB1E962BEAB28B359FD2D8D6BDC7A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisStepInputSingleton_tF8533E0D6AACD3BB57B6641B05F78A5C48F3A92E_m48F2A43D6BB342C2E20F293BEED732D50620716D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisStepInputSingleton_tF8533E0D6AACD3BB57B6641B05F78A5C48F3A92E_m9E5B4EA89C750E36B3353073165EB59FBFEB9851(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSubSceneWithGhostCleanup_t687703217183BD3C6CC5D419F1157A4886DC0A9E_m07035C69EFE4762093D12CE671E78872FC3D2FA7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubSceneWithGhostCleanup_t687703217183BD3C6CC5D419F1157A4886DC0A9E_mD2695FD6A566AD86B765890CA29454ED2249CDEF(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m3AB760048DEEF52E3D785C2F2EA3D148204ACDA8_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisTransformAuthoring_t3C311DCBF21C302795452FF32440FC0C77A00939_m1A81156C63974EA84F0A4643642D358A715B6A6D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisURPMaterialPropertyBaseColor_t8CF3D5B869C67266D711C7954064BBC7B4012233_m66917F0787975499274D8B897FFF95E35D41EBA1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisURPMaterialPropertyBaseColor_t8CF3D5B869C67266D711C7954064BBC7B4012233_mE05B07850D34AB0EAB9ABA11CEBE2359F8B6A95E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisUniqueInputTickMap_tD54F27A8967281B8FC4FCD0D0113C3B1A5F5D436_mDD970BF6F21A7CC10226C20A274E9337CDF880EC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisUniqueInputTickMap_tD54F27A8967281B8FC4FCD0D0113C3B1A5F5D436_m3B11CD86D34C535158387E8B8EDB356FDD3D4D8E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisIl2CppFullySharedGenericAny_mA75DEEF98BD920A35760228D3F0D7BFFF68CD491_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t3BE4D7DACA33583BBE2C8373A5C47EFC4B20049F_mB73C3CAE2E00987974D038533A36E842733F9C37_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t3BE4D7DACA33583BBE2C8373A5C47EFC4B20049F_m1289448A6EDDF07B5229C7FBFCC9F48B79E319D7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t3C4D290E03B1550607585431A91F6254C68B5D91_m57BA15078FFE58664A8AB15D25E3ADD005D4BAB1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t3C4D290E03B1550607585431A91F6254C68B5D91_mF4039B4DA6EE4DE3F43D34D2026BAC6B6F05497E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_tAC4EAD27362F01BBF5BD1EDDAF3EC58ED8A36720_mDB23E797C6E4A6700BA8EF0678C197B22BB72F8B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_tAC4EAD27362F01BBF5BD1EDDAF3EC58ED8A36720_mF50E4BFE613D533A8E57BF4BCD315D96B1E0B7E9(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_tCAA7B5B53C65D96E834EED2D2BF2AB5506867D26_mC2B966A36EA577C50EF211CEFAA25872A830667D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_tCAA7B5B53C65D96E834EED2D2BF2AB5506867D26_m3A1D7602D30967D8B78AE0633F0CD129C726A0DD(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t26DC1AF10CA15B26730980E6E27C1EF0C2BE9477_mCA9C612EF463CFD4AF5FA244F83D6C245E43F66A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t26DC1AF10CA15B26730980E6E27C1EF0C2BE9477_mAB99D63691B68A0CFA1C1C9DE78049F54DD82BB3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t1651082D66AC0E8FDCC10F98F216B9BF100ED8C4_mD4683C3D6FDB575E98AD8D35101C2B0473B3C787_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t1651082D66AC0E8FDCC10F98F216B9BF100ED8C4_m2AF1E6707AEBF72608178F8898735EB50A2E0533(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t64065E6CEC923A03666B8AB0360CC5BEBD4584C3_m071C6BC4468E1C23C2055F6259A550E7859401E6_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t64065E6CEC923A03666B8AB0360CC5BEBD4584C3_m1C299D989AA51186FDE6E61D2AAA9B8A7167C48D(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t98A3C260D7EC2417778B2B6B5C85A94CB302CEDE_m1B57D3CD98E909454692F5F66BD4E041311F3D2A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t98A3C260D7EC2417778B2B6B5C85A94CB302CEDE_mD858397FD2BEA5A31DEF9087B588F06FAF3A7315(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_tAEE471B70CD3AE022A4745E8DE8A7ABD1027B7A9_mE966070B5911579500FEEF68A2ECA57B39783840_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_tAEE471B70CD3AE022A4745E8DE8A7ABD1027B7A9_mE09FB0A77084985937E1C63137044359A6DEC698(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t7B01EB05343F6EBACE8022A40F0E4ADE261DE7BF_m8A223D109796C7159DD503DD5BAFECDD5B571F0B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t7B01EB05343F6EBACE8022A40F0E4ADE261DE7BF_m939EDDD6784881C87ED4781C84DA6202FF5C5761(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t374672F8E4A603D633C5ABEBA6FB5F00833D1A2D_m66EF2571BE85077AE3D2D4CCABAF06F5AAE19A67_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t374672F8E4A603D633C5ABEBA6FB5F00833D1A2D_m79F42C098FD5196D1B6B493E240BDDD32869E340(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisState_t583D7FAB6D38B74AF495A7205BBCEBEADCBAC09A_m62917A7A063CBD97903B3EC0776173AC15057FE4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisState_t583D7FAB6D38B74AF495A7205BBCEBEADCBAC09A_m4AA6770C3F7E3C446E8E3165C39B10C8058C7013(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m978A145D7DBA0E5E7FF961C782789C68B95D5488_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m034B261205C75B76955DD2B074998C7708E87E84(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSingleton_t5DD8E367CBD667FFC7D1AB73A7A2E2977008D79E_m7E298D7E7977DDD724BF44AD2FF267DB9D749979_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSingleton_t5DD8E367CBD667FFC7D1AB73A7A2E2977008D79E_m88F5E0CF21829DAD6CDAA92C035B35E13D78E6F9(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_m13D83DF381584E888DD3A5A8F74772CED512DC6A_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_mEF6863C1F6A7D2877D414B4EB0215D36635861C0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m13FD6F350C528CDF131F389D51DA3A825A33E53F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m32613B7A68993E09512739825CEBD2E50AF4201A(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m02D0F446F06923EB56202D8B2481E3E56CDB8A02_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mE3F306C9F75E3655785EAF36C6F85D9E46A2EBBF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneSectionData_t22BBFAD9EE6AF38CC454C77315B0DDCEC2FAEE12_m32613B7A68993E09512739825CEBD2E50AF4201A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mF46A945D1FBC5F730FE4AB9CE92E455E9840E868(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_TisPublicEntityRef_t499E2838255A5FCF6E1CE9B5E7C366D795D9D634_mCAF730B6322207A1E1BB1A437BB84417966A9EE2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPublicEntityRef_t499E2838255A5FCF6E1CE9B5E7C366D795D9D634_mF018CFE927579488AF20C4292FBA364866BBC730(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisSwitchPredictionSmoothing_t77F66A976B2B8967484C1CDF987CA6EB0CA27D54_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m2817B309CE789515EA3C4A82BBA3FDEFF6AA082E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSwitchPredictionSmoothing_t77F66A976B2B8967484C1CDF987CA6EB0CA27D54_m72FD8CC28BD7A6680CD1A129DE5F652A3F96FC90(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAllRW_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m0238E9ABC1B2FF8201356D746D764EF18BD5308B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____all);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m30578FF84269C3006E11CEB608755D370AF69FB3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_m3C46DEC610F7A882A97B1838653EE28CA78D75D3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_mD8A139D2A3BD0AAFAA25E169F7D8D9228435D674_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_m52F6874E1B8C0B5D6C83885D95B32E602356CAD4(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_TisGhostChildEntity_tBA1424BC5FFA91C3F17C633F75AD7C26078F59C2_m35E7B6F60A902A2903BFC3E00A91C571783552A7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostChildEntity_tBA1424BC5FFA91C3F17C633F75AD7C26078F59C2_m70CA927E5514BC3451D74FF75207BCE63FD818DC(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_mEBF9B95CA3778A5E4C5EAD3AAED41D8A3D746DD0_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisMeshRendererBakingData_tB57745402D0323D65CD2CF85D95648D4C699862E_TisSkinnedMeshRendererBakingData_t150FE20D34A6D7BBE2D3F0BB6029B3588DA7FA36_m043A408231FADACB4DED30960C14309651B34663_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisMeshRendererBakingData_tB57745402D0323D65CD2CF85D95648D4C699862E_m8C1E7F147ECEEBD946BA39F37EC7D07FF8E76769(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisSkinnedMeshRendererBakingData_t150FE20D34A6D7BBE2D3F0BB6029B3588DA7FA36_m53301195B532F30D951D795C0A1962C762DF29EC(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_m2D0542B9614CA008DAD4E243BC7809124120F978_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m8C5B3D045C6A6BC250557CA83069E2D450D77CEE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mC950D4B0470475CAE0A45F0776341628D7717043_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisStartStreamingSceneGhosts_t1E0DFE2559BA591C2891A3767A75CD40C599ED14_m47BA8188DCB537ED8911366260DDD9054B00BE49(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisStopStreamingSceneGhosts_tDBBF4164BBE2BCF060A8E33708FDAC668B6CF578_mF32B07397F399C3B9C5DE1C1AED74B5FA0F0B29E(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_TisForcePrespawnListPrefabCreate_t9F075B92BAE534B12F86ADC432D8D57F6E09799E_mBB78709AD4B1B08533F9506B2E064C5F386AC421_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubSceneWithPrespawnGhosts_tE41A850295EB89C7FBDC9199273A3D423FFF34F4_mC24E02DAF5E12147F17D481ACCBDDCE4BF105358(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisForcePrespawnListPrefabCreate_t9F075B92BAE534B12F86ADC432D8D57F6E09799E_m7024E62EC3B8A9729FD3F0FE6247CBA54E162756(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m0CBAA410E7CFEC03ADA8624D7E88D991B513E8E5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m3CDFD7A832B9AA70DB23EEE152E30300A7BA5D7B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mC2296A4725ED0BD79237CE9D81ADD6067579EAB7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE9EE97E634773D380B740EE07E31FDB028FC9CC7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m107B896A232B8067040F42532061191AB9DFCBD4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		L_18->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_19 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m9DB4E22D46753F9610EA72A84AE46755960D578D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_19 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_18->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_20;
		L_20 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		(&V_0)->___TypeIndex = L_20;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_19, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_21 = __this->____builderDataPtr;
		NullCheck(L_21);
		L_21->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_22 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisNativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F_m5222A85C87FA30E0A961EFCC7DBFCADEDBA00207_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_4;
		L_4 = NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_inline(L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_1 = L_4;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_5 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0028:
	{
		int32_t L_6 = V_0;
		NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* L_7 = ___0_componentTypes;
		int32_t L_8;
		L_8 = NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_inline(L_7, il2cpp_rgctx_method(method->rgctx_data, 3));
		if ((((int32_t)L_6) < ((int32_t)L_8)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAny_TisIl2CppFullySharedGenericAny_m8F53C341EC7C5DE3722349BBD799965BFB6A4183_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, Il2CppFullySharedGenericAny* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		Il2CppFullySharedGenericAny* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_5;
		L_5 = ConstrainedFuncInvoker1< ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 2), L_4, (void*)L_2, L_3);
		V_1 = L_5;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0028:
	{
		int32_t L_7 = V_0;
		Il2CppFullySharedGenericAny* L_8 = ___0_componentTypes;
		int32_t L_10;
		L_10 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 3), L_9, (void*)L_8);
		if ((((int32_t)L_7) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_11 = __this->____builderDataPtr;
		NullCheck(L_11);
		L_11->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_12 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAnyChunkComponent_TisIl2CppFullySharedGenericAny_m2BD9449AB44E2FBC29BBA6812929859AFC58EA1B_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAnyChunkComponentRW_TisIl2CppFullySharedGenericAny_m742EED0862D799A42ECCF17DC29B3BF701A66E69_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAnyRW_TisIl2CppFullySharedGenericAny_m982C350CB8A145E63AA93253CEA4ED744BE4AE66_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAnyRW_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m21201A4FBF5744D556D9DB774C4352682D3EAED3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____any);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithAspect_TisIl2CppFullySharedGenericStruct_mCCD8BF07F94E0EF3BB3853DE67FAC1CEAFFBC441_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_TAspect_t03D4D5D28513BB8E05E9E4CC3E73FDBDA0294AB5 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 0));
	void* L_3 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 0)));
	Il2CppFullySharedGenericStruct V_0 = alloca(SizeOf_TAspect_t03D4D5D28513BB8E05E9E4CC3E73FDBDA0294AB5);
	memset(V_0, 0, SizeOf_TAspect_t03D4D5D28513BB8E05E9E4CC3E73FDBDA0294AB5);
	{
		Il2CppFullySharedGenericStruct* L_0 = (Il2CppFullySharedGenericStruct*)V_0;
		il2cpp_codegen_initobj(L_0, SizeOf_TAspect_t03D4D5D28513BB8E05E9E4CC3E73FDBDA0294AB5);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_1 = __this->____builderDataPtr;
		NullCheck(L_1);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_2 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_1->____all);
		ConstrainedActionInvoker1< UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 0), il2cpp_rgctx_method(method->rgctx_data, 2), L_3, (void*)L_0, L_2);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_4 = __this->____builderDataPtr;
		NullCheck(L_4);
		L_4->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_5 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisPredictedGhostSpawnRequest_tF1875A417A0FD6CAB1170E11F1678E1764BA1539_m3E962EE767EA73E88D18FF321AB26CAE41CA9072_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPredictedGhostSpawnRequest_tF1875A417A0FD6CAB1170E11F1678E1764BA1539_m829F34926C0A340AC2D96739B01F218C3F84088E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_mD8A016ED6D2A2FF8616434FC9592209E36ACD4E8_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSimulate_t838A3C68E54E617018D34FCE95DCFF8F2F942127_m30F2158F2643D7C9BEB0138EF959CC01FE2F2F70(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_m034C7B3CBDB15CEF2D3B15D970E53EBD49A056F1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m9EC931D466AA39A894EB3A8F2D12B2A6EB7EFC14_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mC8DDBD5D8F903642B23A579B9E2411D49209106E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mABA79A4ECF78BDD62CC8034E61A17C5C2DD5E9B5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mA22860C11CE9DC980CE51AE31A87F508E19FCB79_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m64D6F6ABE88E96E69BDDACF6DD2E8364CC592038_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		L_18->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_19 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m68A868928F52BA0185E263100455D485C13C2F91_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_19 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_18->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_20;
		L_20 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		(&V_0)->___TypeIndex = L_20;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_19, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_21 = __this->____builderDataPtr;
		NullCheck(L_21);
		L_21->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_22 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabled_TisIl2CppFullySharedGenericAny_m9BF7D25E9DB1859F8F6F4D534215FB6500B75FE9_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, Il2CppFullySharedGenericAny* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		Il2CppFullySharedGenericAny* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_5;
		L_5 = ConstrainedFuncInvoker1< ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 2), L_4, (void*)L_2, L_3);
		V_1 = L_5;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0028:
	{
		int32_t L_7 = V_0;
		Il2CppFullySharedGenericAny* L_8 = ___0_componentTypes;
		int32_t L_10;
		L_10 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 3), L_9, (void*)L_8);
		if ((((int32_t)L_7) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_11 = __this->____builderDataPtr;
		NullCheck(L_11);
		L_11->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_12 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabledRW_TisIl2CppFullySharedGenericAny_mE3DF734FACDB8636282F5AF70208184AD14C537F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithDisabledRW_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m6C27504A4541EE8793A096DD63293651EB8FEB66_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____disabled);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisBakedEntity_tA80601A59125E066241325C1A5191D59FAD23352_m29A6BEFC760546DF0ED53B7DDC326AD697005AAA_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBakedEntity_tA80601A59125E066241325C1A5191D59FAD23352_m31FAE09135CA0F29701CDE7C1901130F6F94A718(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m303E4ECF9CF1B06E5EAD36E663B5641F1FF5CB1F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m4A8F9BC5A855AFEC91B4274672776F4849BEB164_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBlobAssetOwner_t48F662D0AF49A5BBFD013EF59C8BD9C335A854AD_m0F23A448C61CCF70DF9C04FC86EB10D61DDC3A72(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisCompanionGameObjectUpdateTransformCleanup_t4325DBFD102F432340DCC8AA5701D7913E4F9E34_m719FEBC057E44EF04ABDA6F35DB3B94BE10C00BF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCompanionGameObjectUpdateTransformCleanup_t4325DBFD102F432340DCC8AA5701D7913E4F9E34_mF2C8DC4BDB8F31AC2F6F6E5B391D3BEB9ADEF960(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m1E113633020C0DF8531CB678498761EE7EA5CF7F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCompanionLink_t2C6D134D2EB0678CF010E15832684060591FA368_m35B180D8E0FB2E919950E250BE18134F7343708A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisDeformedEntity_t8F7AE546463F5A6834571235356695DFFD2685E3_m93AA24F5C06EE685C864B26DCAF653D3AC634CC2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisDeformedEntity_t8F7AE546463F5A6834571235356695DFFD2685E3_mEDDD3EAEFA2A4D216868E43D1D9ABA64325E8B69(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisDisableLiveConversion_t746C62A5B0E100BC2D7F32238C0F3BCC3CE2CE07_mE50A467B6705E2A076EFE3AC7E8ABC253470A02E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisDisableLiveConversion_t746C62A5B0E100BC2D7F32238C0F3BCC3CE2CE07_mEC7620E2DDE33A35AF5F36C78B413DD3DD36E0BC(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m6F67A62A3D54A9BDB255C3152C24B9F7BDBBE8D8_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisEnableAnimationControllerPredictionUpdate_t6D3E235A97E377B7DAD18008455DE685F137CE59_mB053D09F2870C14469DFCADBF8C9AFF19E2CEE61_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisEnableAnimationControllerPredictionUpdate_t6D3E235A97E377B7DAD18008455DE685F137CE59_m90B0ADF1564567D920E61B96C0CF339053DFFD60(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_mC4EF037A831C0E26B000DE5BB9CAB5B52E76C496_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostInstance_t30DDDB852D6EAB696456DCCC3008DE30823D5C56_m69243FA53C01E6A04D62F7D4FE19FA0F5E9D3A6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisGhostPresentationGameObjectPrefabReference_t1AFF652EC976B64380DB8145839D772CE5CF8A95_m53D0F03EAE84F7B44D8DEFDB0133625E525707DD_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPresentationGameObjectPrefabReference_t1AFF652EC976B64380DB8145839D772CE5CF8A95_mC646D34F024A5AB325100490CDBBEFB50ABCB503(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisGhostPresentationGameObjectState_t4F0310F7B47CF37DE88C8818451706A83729E32D_m5721CEFE9A4F448A8637D3BCFEF08C222DE7DBF7_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPresentationGameObjectState_t4F0310F7B47CF37DE88C8818451706A83729E32D_m99D3AC2F8AAC7A08E5CFCFA5CE99D143049CACE0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m9CD3B4D526CD06F2947B68EE784E83425EE72F23_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_m62061CEF39E8595C6D03EEDEBAA7A1CE4784AA21_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisIsSectionLoaded_tBF08B3985E7B90393E9188BA6E4FE4B612667455_mFD8268FF9C7C966C60C10879CB3B2956E7FC6FEE(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m3A4B25F34216C77F0409E1088C65EF4B37FD992D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m64DD12A37A8AE2C5F2FBB9B443E49FD0A11FF063_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamInGame_t0201368261216D0E58A4F1A8F6DF30F2987D4F0B_m7CD1869A1B8F96774012746387B3085F74F9F881(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisNetworkStreamRequestDisconnect_t4D1CE81C990B34C77F1D5C540F735C8C69953324_m75F6BD748D89ED8462EBDEC47D472FB8CC1482E1_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisNetworkStreamRequestDisconnect_t4D1CE81C990B34C77F1D5C540F735C8C69953324_m0C1C639B8AE47B7253939CD1762F5998EB69E8F7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisParent_t473162287DAADFBE8C1A231B52DC5D0C80687304_m44E6BEF4D5B6C6B9BF3F5052259341ABDD56FD00_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisParent_t473162287DAADFBE8C1A231B52DC5D0C80687304_m8B12138A3E7C48A95753F440F4414C59E885BF21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPendingSpawnPlaceholder_t4FA3256A1F6054A88E6E18ECB308EF9676B1B8A5_m3F8343A5C069DC420DE3EF357DA976C884BE6686_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPendingSpawnPlaceholder_t4FA3256A1F6054A88E6E18ECB308EF9676B1B8A5_m5F297EF814EE1940C3E5EF944A7A3AF390F542C7(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPhysicsTemporalCoherenceInfo_t687207DF0B7ABEFCF3D015765DE3B943AF917FD3_m408B6B7123AE2F32DEDA7B2E1C9F6B4B7800C1F3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceInfo_t687207DF0B7ABEFCF3D015765DE3B943AF917FD3_mD793CCE84E010C5AB5BCE93ABA33A943469DA5B2(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_m713F4B6CE5DA7795CA1A93598CF9CBBC894F1BEC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsTemporalCoherenceTag_t36AD20C7CC2757DD29698462895002BF0911B2B4_mD1C40FAD70ED135D27F57C7BD54FEE4A3C144429(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_mCB8FD50299F00F8944F90FD4E213AAADB0B7FFF3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mE3953C9A64CF717550E0AD1FB2593A90041E06F5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_mA33388295870CD0C9916D67601215E4F421CC8A0_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPreSpawnedGhostIndex_t86F3B58DA3DA317013EC9E6BFD41DEFB2E243015_m23D5738433CC0127CEA78AA0DE8AA0576F26BF9F(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mA67D02CFA14FCBE4D5442DA725A354C471940B44_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPredictedGhost_t56170BD20B02F39FBC5BEC0E00EC85521F7DC713_mBD28BA67E6A7F5691191CC2BC33B8E3EB9DA59E9(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPrefabAssetReference_t5ED5CF37BAB8B0CA45F2B99F97AA5447955E9736_m31B9448C35AAF92ED0C7EFF5D90F81D67CAFEC76_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrefabAssetReference_t5ED5CF37BAB8B0CA45F2B99F97AA5447955E9736_mFE7F5D5A3287D32CD3E34997E18D8BA62021381B(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPrespawnsSceneInitialized_tCEA0B8F6DB786927C82C9642B8C742C87F2A1AC3_mE9824BD5AB0545FB287B9C1C0AB4F024BA3DC981_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrespawnsSceneInitialized_tCEA0B8F6DB786927C82C9642B8C742C87F2A1AC3_mCB2F48637F4626AB7B0A1A0CC6041F628EA4CC55(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_m6A8C28514273DA1C85EF6663DEBEFB46C943B85F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPreviousParent_t4879AE063F14CAD6263F68FB5BCBFDC18889BEDD_mEF28DFCAD423E26B81F10A8CB792E628B9553C50(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisRequestEntityPrefabLoaded_t7619E45BAFEDDF1F5FAD060DFD61BBB7080A8FE7_mB72BCB010B2B2D42289039F31EE29CF3512A09A4_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestEntityPrefabLoaded_t7619E45BAFEDDF1F5FAD060DFD61BBB7080A8FE7_m9280A0A88A6F0BBF7615664B2772B9148992F094(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m9FF2A92F7537E900B1F60FF34E8A50E13F0418CE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneHeader_tFB164D8BD279642D1C1FF039036393F4C8A31AC6_m489D25E73D17754E1617D080BC4D80F47732BC69(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_m98923332AE304691258910C8082AFF9CF0F44EB5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_m07029EA7394C7C60C0F11662AFA71811EB8BB3EF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisResolvedSceneHash_t5CA34693F082AFC6F60F638176577BDA620C9B20_mDA9DDA0556CCFFE8D45941BA53503BA2812E2CBD(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisResolvedSectionEntity_tD18069CE6AD2FA61A39B747F346310DD10B77CEE_mE6A5C919542D42689E0A3A62D894AFE2FBE0FBFF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisResolvedSectionEntity_tD18069CE6AD2FA61A39B747F346310DD10B77CEE_m078846ECEE3F065DCB87E457F4E17150A512D54E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_m8137EB2F2A934AD511EE75ED86E6A05DAFDDF81F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRetainBlobAssetBatchPtr_t3C4E424C414A65ED2C7215C76B298CA04E362306_mBB6E1A3B821CE326AED3045B286B16AAA2243D30(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mFD84486A7F9F535195593C0F60E1285108877541_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneEntityReference_t66E50E7C54B23425953959208B308D7E9C5F4DC2_mF46A945D1FBC5F730FE4AB9CE92E455E9840E868(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_m081582C2D2A8AF2CA4F886E2991770D0900CDF5F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSceneReference_t2807450F0E3141AA80D97BE5CDC40D70965940B5_mE63D71E60B319B3370A91FD5A60641283BFBEAD6(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisSharedMeshTracker_t32B97BE3ACFA13F4D721D6B3B1D5AF089C22FA90_m8DF479D4981A4D2E16F2F60F5EEDEB09DD319C7D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSharedMeshTracker_t32B97BE3ACFA13F4D721D6B3B1D5AF089C22FA90_m01226CD6DE3BA04F680042132A26BBF196F9A135(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_m7A10A95AEA3801DB84617016C76BBE9980020F5D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisSubScenePrespawnBaselineResolved_tB25FB1FFE6B19222EA8510EE41863D0EE300CE1F_mED674BAF8C637D42FB820B9312EE84249EC64975(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_m70814C396EFF1EE42465AE2DF4CF242D4B415126_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m4F04B4FBD6CEB1C37AF075B3FBC3139BD4987999_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisMaterialReferenceElement_t92B9C280FA5368F6A6C297561C172FA97EFBECAC_m034B261205C75B76955DD2B074998C7708E87E84(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m52F9EF738DA459149842DDC529E10ED424F6F6D2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisBakingOnlyEntity_tBDD362F696A87274ED664FDE5FD13A74CFA7A2CE_m96B9401FC8FD0B04F55F3BC782166E5FD434CB6E(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisRemoveUnusedEntityInBake_tD9ECD1A4695A5071B0D2316B09A8B48A3FFB4DE1_m4C57DE307DAAF466D6E263D507E046DD4C2128E3(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisCompanionGameObjectActiveCleanup_tE1E7380BD2CA958C6AAC9DCF6A1AE76CBD95D862_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_mEFBE540954B4AFA4D43266A91FED02E58D40BD8C_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisCompanionGameObjectActiveCleanup_tE1E7380BD2CA958C6AAC9DCF6A1AE76CBD95D862_m87F3F2DE88FDBBFF35981828034E7E157B7ED7EA(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisDisabled_t1C72FE38756BF6A95146AFE331F04FC71B3A79A6_m52F6874E1B8C0B5D6C83885D95B32E602356CAD4(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m3EDECA32E7B24F27CE306C72F9FE77200D659337_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisLocalToWorld_t23B3E8CDA5838EF771A49AC5B39A57AF233E038D_m1EC12243DF81B126C8C9E933280E1FA79A7F07F8(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisLocalTransform_t8D1FEB4386DEE0D22FA43322268BF76E9FF687BD_m58AEA1DED6EDF65EDA210250777DEECF91753995(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mAF3FBD594F197869B4FA93695A20F747D0B8EC44_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPhysicsVelocity_tD8FD9AE4143DA8547016CDB52234BDF420F14DD2_m4D6D8D55D1B1E84DCB7D1EA56993A632D31BE236(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisPhysicsCollider_t26A94D6ECCA8ECDCAEA83F12DEA8ADC15153DCDA_mDF41949DE496AE94DE78B9A53C7408A033EA3516(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m5B90E5A991D7D7035D7AFF9A68D118651674706F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisRequestSceneLoaded_t84D63EB24CFB758BF46A3B4DDB00140B84E2F9B4_mCA5211449B686BA7B83148CDFC9095DC7360FB21(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m4B9CB68598D0DCAE4991F0511460D30A884DEE2D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m166D5B7A8E15873284A2997CB816307C890B3EF5_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisStreamingState_t26FE12C040BCF324059A9D9487A142D51678EBB7_mEF6863C1F6A7D2877D414B4EB0215D36635861C0(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisDisableSceneResolveAndLoad_t4250381D87869C0AD2D831D3414EBA2C7A26B516_m82021480FD67E604C45BDDF5F6E52194A966CBDA(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE0DD87BACE73BF6AFC88E59DAEFC6763027D9EAF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m3C02A9B912A36D43D330946BA3E9EF7F2EC3B8E3_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m5BED1D4288E49B4039A8447251F3DFEB0FB4CAB6_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m56ADB15345CF51A307549789A1DBB683C3AB7D8D_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		L_18->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_19 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m5C12F9060DB5A4E165D1EDAA6D329CDA7766A4AE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_19 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_18->____none);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_20;
		L_20 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		(&V_0)->___TypeIndex = L_20;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_19, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_21 = __this->____builderDataPtr;
		NullCheck(L_21);
		L_21->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_22 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNone_TisIl2CppFullySharedGenericAny_m0AB205519364436DDC2BE1C4A105C931362F739F_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, Il2CppFullySharedGenericAny* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	void* L_11 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0032;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		Il2CppFullySharedGenericAny* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_5;
		L_5 = ConstrainedFuncInvoker1< ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 2), L_4, (void*)L_2, L_3);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_6 = L_5.___TypeIndex;
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_7;
		L_7 = ComponentType_ReadOnly_m2D5468BFC22BC6CA460ABA797AAF04F1E5D8EF5A(L_6, NULL);
		V_1 = L_7;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_8 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_0032:
	{
		int32_t L_9 = V_0;
		Il2CppFullySharedGenericAny* L_10 = ___0_componentTypes;
		int32_t L_12;
		L_12 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 3), L_11, (void*)L_10);
		if ((((int32_t)L_9) < ((int32_t)L_12)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_13 = __this->____builderDataPtr;
		NullCheck(L_13);
		L_13->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_14 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithNoneChunkComponent_TisIl2CppFullySharedGenericAny_m5FC07121FF7443576037FAAFE310F1EE426DCBD6_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____none);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisGhostPrefabTracking_tFA42422DC954B461D79DE19415390FBAFFCF27DC_m92CF84EE4068797CD50766E27D4904F0700D87DC_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisGhostPrefabTracking_tFA42422DC954B461D79DE19415390FBAFFCF27DC_m759831DB84D3C3F05E13E00CA17D7F0B49A507FD(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_m32DF4A4EB188A3601F47D0FC0F95D2F0CF81E89E_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_mFFD4AD07DF639455157E2D01B7208FB3F6EBEB10_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = TypeManager_GetTypeIndex_TisPrefab_tB7A76B34FB77A40D8ED20199BACEC0A6BE189B1F_m76ED19F2481A5858F9D3F419A014636A3F96F372(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = TypeManager_GetTypeIndex_TisGhostType_tA0682225DDDF8FA7FA48FBFF8B051400E320CB5D_m4967700ED0F7915C03F24F49312F4B26510D4BCF(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m7F46F9F38B82F73F0677357F24FEEC409943ADB0_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mBDDA8635BDF40467081411929C27CC3E6F652074_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m27F2F3A4B96505C8697E1F56E1560AC9B5A40ACE_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		L_12->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_13 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mF6022BF1D29A46C536FF70B9D67BB122234BC7B2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		L_15->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_16 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_16;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mA73BB8D7BF59BFD6C5E19978B6D89963B35B4BDF_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		L_18->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_19 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_19;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m546C0F942F1095FA0985BB0957E53CEE2BDDFD61_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_7 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_6->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8;
		L_8 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(il2cpp_rgctx_method(method->rgctx_data, 2));
		(&V_0)->___TypeIndex = L_8;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_7, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_10 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_9->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_11;
		L_11 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(il2cpp_rgctx_method(method->rgctx_data, 3));
		(&V_0)->___TypeIndex = L_11;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_10, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_12 = __this->____builderDataPtr;
		NullCheck(L_12);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_13 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_12->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_14;
		L_14 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(il2cpp_rgctx_method(method->rgctx_data, 4));
		(&V_0)->___TypeIndex = L_14;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_13, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_15 = __this->____builderDataPtr;
		NullCheck(L_15);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_16 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_15->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_17;
		L_17 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 5)))(il2cpp_rgctx_method(method->rgctx_data, 5));
		(&V_0)->___TypeIndex = L_17;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_16, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_18 = __this->____builderDataPtr;
		NullCheck(L_18);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_19 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_18->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_20;
		L_20 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 6)))(il2cpp_rgctx_method(method->rgctx_data, 6));
		(&V_0)->___TypeIndex = L_20;
		(&V_0)->___AccessModeType = (int32_t)1;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_19, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_21 = __this->____builderDataPtr;
		NullCheck(L_21);
		L_21->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_22 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_22;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisNativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F_mBD82A2ADA865668C4E3A9880936D0469DA0BBD32_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_4;
		L_4 = NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_inline(L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 2));
		V_1 = L_4;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_5 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0028:
	{
		int32_t L_6 = V_0;
		NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* L_7 = ___0_componentTypes;
		int32_t L_8;
		L_8 = NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_inline(L_7, il2cpp_rgctx_method(method->rgctx_data, 3));
		if ((((int32_t)L_6) < ((int32_t)L_8)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_9 = __this->____builderDataPtr;
		NullCheck(L_9);
		L_9->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_10 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresent_TisIl2CppFullySharedGenericAny_m035A38A72F312DBC5F42EDB0047CCF9966010E92_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, Il2CppFullySharedGenericAny* ___0_componentTypes, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	void* L_4 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	void* L_9 = alloca(Il2CppFakeBoxBuffer::SizeNeededFor(il2cpp_rgctx_data(method->rgctx_data, 1)));
	int32_t V_0 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		V_0 = 0;
		goto IL_0028;
	}

IL_0004:
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		Il2CppFullySharedGenericAny* L_2 = ___0_componentTypes;
		int32_t L_3 = V_0;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_5;
		L_5 = ConstrainedFuncInvoker1< ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA, int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 2), L_4, (void*)L_2, L_3);
		V_1 = L_5;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_1), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0028:
	{
		int32_t L_7 = V_0;
		Il2CppFullySharedGenericAny* L_8 = ___0_componentTypes;
		int32_t L_10;
		L_10 = ConstrainedFuncInvoker0< int32_t >::Invoke(il2cpp_rgctx_data(method->rgctx_data, 1), il2cpp_rgctx_method(method->rgctx_data, 3), L_9, (void*)L_8);
		if ((((int32_t)L_7) < ((int32_t)L_10)))
		{
			goto IL_0004;
		}
	}
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_11 = __this->____builderDataPtr;
		NullCheck(L_11);
		L_11->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_12 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresentChunkComponent_TisIl2CppFullySharedGenericAny_m21F721FB5F362218161F649720178891886D7B33_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresentChunkComponentRW_TisIl2CppFullySharedGenericAny_mA6DF22AF549003E441B687995877B635A5634D85_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_2;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresentRW_TisIl2CppFullySharedGenericAny_mDC621109260258BAFE8841D1DE7120B06CE5EC29_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		L_3->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_4 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D EntityQueryBuilder_WithPresentRW_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_m7C2F1D3C416C00D5875D9D0EEB520C52E22791F2_gshared (EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_0 = __this->____builderDataPtr;
		NullCheck(L_0);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_1 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_0->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2;
		L_2 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		(&V_0)->___TypeIndex = L_2;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_1, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_3 = __this->____builderDataPtr;
		NullCheck(L_3);
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_4 = (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)(&L_3->____present);
		il2cpp_codegen_initobj((&V_0), sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_5;
		L_5 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		(&V_0)->___TypeIndex = L_5;
		(&V_0)->___AccessModeType = (int32_t)0;
		UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_inline(L_4, (&V_0), UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_RuntimeMethod_var);
		BuilderData_tF9D92CF095D83A4BA431DD170F268AA60A29B3B5* L_6 = __this->____builderDataPtr;
		NullCheck(L_6);
		L_6->____isFinalized = (uint8_t)0;
		EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D L_7 = (*(EntityQueryBuilder_t7CADF5AE1875E4EFA9968A992B7367F79E45419D*)__this);
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* EntityQueryExtensionsForComponentArray_ToComponentArray_TisRuntimeObject_mE35361CC1F759A190F89B2E2CB06E2FBA8A131DE_gshared (EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___0_query, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	NativeArray_1_tDDBE2218E06075EFCDE280D90B6FA7C4BF46BFD2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_2 = NULL;
	EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36 V_3;
	memset((&V_3), 0, sizeof(V_3));
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	{
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_0;
		L_0 = AllocatorHandle_op_Implicit_mDCF4431F31BB4A09438AE644785C4273F86B2B8D((int32_t)2, NULL);
		NativeArray_1_tDDBE2218E06075EFCDE280D90B6FA7C4BF46BFD2 L_1;
		L_1 = EntityQuery_ToEntityArray_m3D36DCB25EE0C3CA3D5F31C5234DFCF5860E4790((&___0_query), L_0, NULL);
		V_0 = L_1;
		int32_t L_2;
		L_2 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&V_0))->___m_Length);
		V_1 = L_2;
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH(((&V_0))->___m_Length);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(il2cpp_rgctx_data(method->rgctx_data, 0), (uint32_t)L_3);
		V_2 = L_4;
		EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* L_5;
		L_5 = EntityQuery__GetImpl_m3E1EC62BB22FA905262DB3199F289864B47AA7AE_inline((&___0_query), NULL);
		NullCheck(L_5);
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_6 = L_5->____Access;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36 L_7 = (*(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_6);
		V_3 = L_7;
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_8;
		L_8 = ComponentType_ReadOnly_TisRuntimeObject_m93761FC33BD499D49F5261781D3813D3A587324F(il2cpp_rgctx_method(method->rgctx_data, 1));
		V_4 = L_8;
		V_5 = 0;
		goto IL_0061;
	}

IL_0041:
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_9 = V_2;
		int32_t L_10 = V_5;
		int32_t L_11 = V_5;
		Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD L_12;
		L_12 = IL2CPP_NATIVEARRAY_GET_ITEM(Entity_t56176FC78C475061A82383D9E0CEE352C6C52ABD, ((&V_0))->___m_Buffer, L_11);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_13 = V_4;
		RuntimeObject* L_14;
		L_14 = EntityDataAccessManagedComponentExtensions_GetComponentObject_TisRuntimeObject_mEDF197D32F7C7436F640D9048E56F1AF813E4D9A((&V_3), L_12, L_13, il2cpp_rgctx_method(method->rgctx_data, 2));
		NullCheck(L_9);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(L_10), (RuntimeObject*)L_14);
		int32_t L_15 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0061:
	{
		int32_t L_16 = V_5;
		int32_t L_17 = V_1;
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_0041;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_18 = V_2;
		return L_18;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m68431935F220203D0292B8621D0AD80604D0DA33((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986_AdjustorThunk (RuntimeObject* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilter_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7FB61FDF11DFCDFA9D05A56A05769B983FB6B986(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_SharedComponent_t3B17F5665306213ACFE9A03D779A6AE54B5BCA27 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_24 = alloca(SizeOf_SharedComponent_t3B17F5665306213ACFE9A03D779A6AE54B5BCA27);
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		il2cpp_codegen_memcpy(L_24, ___0_sharedComponent, SizeOf_SharedComponent_t3B17F5665306213ACFE9A03D779A6AE54B5BCA27);
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilter_TisIl2CppFullySharedGenericStruct_m4E385C53D0D6697FCA3B8096B624FA22B3C2A938(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFEBF6B22ED4CEA161CF6464761F9755851CD7E6A(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_Unmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_m6F02A97AF4DA258F3BBAA8A8BC7C45896188D3E8((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927_AdjustorThunk (RuntimeObject* __this, PhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09 ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisPhysicsWorldIndex_t0854846356C37045E9B11936A6949B1A14704F09_mFD6BE05C65369D637390156AE558F207DD79C927(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m7C789162C825ADC557A30503F60AF978B6946C6C(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_m41A5AB70F7F7F99F70A72A41C65E66BE044E2549((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB_AdjustorThunk (RuntimeObject* __this, SceneSection_t7E9283B521FC08050547458EF3248964019A36B8 ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneSection_t7E9283B521FC08050547458EF3248964019A36B8_mE35F185A05F308C42FBD90BE6041F0203F916BEB(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mC76A7CC02C34296E51EAFFB2A94EA1BF05629CEA(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_Unmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_m199BB7A3CBAF22F26FD007C71A3F76692916CCEA((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222_AdjustorThunk (RuntimeObject* __this, SceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265 ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSceneTag_tB221EEA403DB2442BE5A335F4D6CF932E44A6265_mE576726448496BBF8F0EBE6CA07C238FB4334222(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_mCC3183AA55D2733CF075B0BA420B2631E5F1A67C(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_Unmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8E0E3674B0C5495242906CBF41B67EDDF06E64D3((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410_AdjustorThunk (RuntimeObject* __this, SectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3 ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSectionMetadataSetup_tAA4925FBDF24CDE3AC041BF2F3682116EE780CF3_m8F2DE7DDB1E20D9F54394D95410D1F91DBAC2410(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = TypeManager_GetTypeIndex_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m864F382F53065240543247AE0DBD61F9B70B7618(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E L_24 = ___0_sharedComponent;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = EntityDataAccess_InsertSharedComponent_Unmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m078E25BD8009BACE0C87F2A5AF94A2A292CF4057((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24, il2cpp_rgctx_method(method->rgctx_data, 2));
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780_AdjustorThunk (RuntimeObject* __this, SubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisSubSceneGhostComponentHash_t198FDA3A491AFEAF7307DA027529936DDE4D730E_m397161A470A32CE1CDAD7A06389EA95D6B5B6780(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_SharedComponent_t1B4C2DD53CA25308E0C8FAA8E42EBAFC0320CD20 = il2cpp_codegen_sizeof(il2cpp_rgctx_data_no_init(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_24 = alloca(SizeOf_SharedComponent_t1B4C2DD53CA25308E0C8FAA8E42EBAFC0320CD20);
	int32_t V_0 = 0;
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_0 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_1 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_0->___Shared);
		int32_t L_2 = L_1->___Count;
		V_0 = L_2;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) < ((int32_t)2)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_4 = 2;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int32_class, &L_4);
		String_t* L_6;
		L_6 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral1ADE495F5CE08F2C34ED5A5FD6D9017232ED6CD9)), L_5, NULL);
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_7 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_002b:
	{
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_9 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_8->___Shared);
		int32_t L_10 = V_0;
		L_9->___Count = ((int32_t)il2cpp_codegen_add(L_10, 1));
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_11 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_12 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_11->___Shared);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9* L_13 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_tF74E8C082C63D1F5EC4A529909287F360012EDD9*)(&L_12->___IndexInEntityQuery);
		int32_t* L_14 = (int32_t*)(&L_13->___FixedElementField);
		int32_t L_15 = V_0;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_16;
		L_16 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_17;
		L_17 = EntityQueryImpl_GetIndexInEntityQuery_mB9EFD157125608980637EE72F88024DFF04FDCBE(__this, L_16, NULL);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_14, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_15), 4))))) = (int32_t)L_17;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_18 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8* L_19 = (SharedComponentData_tCB3DB8493786CFDD25A66AE32E2C053EECE862C8*)(&L_18->___Shared);
		U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0* L_20 = (U3CSharedComponentIndexU3Ee__FixedBuffer_t6678D7BCFF071F01975BEAE7FF8C6FA532C1FDA0*)(&L_19->___SharedComponentIndex);
		int32_t* L_21 = (int32_t*)(&L_20->___FixedElementField);
		int32_t L_22 = V_0;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_23 = __this->____Access;
		il2cpp_codegen_memcpy(L_24, ___0_sharedComponent, SizeOf_SharedComponent_t1B4C2DD53CA25308E0C8FAA8E42EBAFC0320CD20);
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		int32_t L_25;
		L_25 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), (EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_23, L_24);
		*((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_21, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_22), 4))))) = (int32_t)L_25;
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14_AdjustorThunk (RuntimeObject* __this, Il2CppFullySharedGenericStruct ___0_sharedComponent, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_AddSharedComponentFilterUnmanaged_TisIl2CppFullySharedGenericStruct_mF88C2E6780C0C1EF29F1C7C57F341E0D3B8C8C14(_thisAdjusted, ___0_sharedComponent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C V_0;
	memset((&V_0), 0, sizeof(V_0));
	ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		int32_t L_0;
		L_0 = EntityQueryImpl_CalculateEntityCount_m558615E38234893FE6A4A7DB3162A9939800C867(__this, NULL);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_1;
		L_1 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_1;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_2 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* L_3;
		L_3 = EntityDataAccess_get_DependencyManager_m393F3E50C2B049B984CCC546CE9B188E6488E879((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_2, NULL);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_4 = V_0;
		ComponentDependencyManager_CompleteReadAndWriteDependency_m48DAC16D2E14225B4B5D631D214740245AC7A345((ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47*)L_3, L_4, NULL);
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_5 = __this->____Access;
		EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* L_6;
		L_6 = EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_5, NULL);
		il2cpp_codegen_runtime_class_init_inline(EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		uint32_t L_7;
		L_7 = EntityComponentStore_get_GlobalSystemVersion_m19BE06808BCF2249B439A2FEAA9DF8F4DCEFA5D4_inline((EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F*)L_6, NULL);
		((  void (*) (ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572*, bool, uint32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((&V_1), (bool)0, L_7, il2cpp_rgctx_method(method->rgctx_data, 1));
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_8 = ___0_componentDataArray;
		EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 L_9 = ___1_outer;
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572*, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 4)))(L_8, (&V_1), L_9, il2cpp_rgctx_method(method->rgctx_data, 4));
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F_AdjustorThunk (RuntimeObject* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_CopyFromComponentDataArray_TisIl2CppFullySharedGenericStruct_mE5A40412FF8F3BC35542A2AB64291E1C8AB4779F(_thisAdjusted, ___0_componentDataArray, ___1_outer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_jobhandle, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___2_outer, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_0 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* L_1;
		L_1 = EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = EntityComponentStore_get_GlobalSystemVersion_m19BE06808BCF2249B439A2FEAA9DF8F4DCEFA5D4_inline((EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F*)L_1, NULL);
		((  void (*) (ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572*, bool, uint32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((&V_0), (bool)0, L_2, il2cpp_rgctx_method(method->rgctx_data, 0));
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_3 = __this->____QueryData;
		NullCheck(L_3);
		UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566 L_4 = L_3->___MatchingArchetypes;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_5 = ___0_componentDataArray;
		EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 L_6 = ___2_outer;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_7 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_8 = ___1_jobhandle;
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_9;
		L_9 = EntityQueryImpl_GetDependency_mF8A0166CFBF65428EE75B84AA491061FB9910261(__this, NULL);
		((  void (*) (UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, ComponentTypeHandle_1_t47AF98F426FD894987FDF5DE06EB648CE9997572*, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_4, L_5, (&V_0), L_6, L_7, L_8, L_9, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F_AdjustorThunk (RuntimeObject* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_componentDataArray, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_jobhandle, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___2_outer, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_CopyFromComponentDataArrayAsync_TisIl2CppFullySharedGenericStruct_mB156A74E28D9DF319D7051B230AEB72CA24F8B4F(_thisAdjusted, ___0_componentDataArray, ___1_jobhandle, ___2_outer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 ___0_componentDataList, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___2_additionalInputDep, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___3_outJobHandle, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C V_0;
	memset((&V_0), 0, sizeof(V_0));
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_1;
	memset((&V_1), 0, sizeof(V_1));
	DynamicComponentTypeHandle_t3E20E0F3BAD2BBFEF185BE607A282ECFEAF35CB6 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* V_6 = NULL;
	int32_t V_7 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_8;
	memset((&V_8), 0, sizeof(V_8));
	int32_t V_9 = 0;
	ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA V_10;
	memset((&V_10), 0, sizeof(V_10));
	int32_t V_11 = 0;
	{
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_0;
		L_0 = ((  TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_0;
		il2cpp_codegen_runtime_class_init_inline(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA_il2cpp_TypeInfo_var);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_1;
		L_1 = ((  ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		V_1 = L_1;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2 = V_1;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_3 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* L_4;
		L_4 = EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_3, NULL);
		il2cpp_codegen_runtime_class_init_inline(EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		uint32_t L_5;
		L_5 = EntityComponentStore_get_GlobalSystemVersion_m19BE06808BCF2249B439A2FEAA9DF8F4DCEFA5D4_inline((EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F*)L_4, NULL);
		DynamicComponentTypeHandle__ctor_m39E2F07A25D23F62BB3FF158D80FAD2CF125EC2F((&V_2), L_2, L_5, NULL);
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_6 = __this->____QueryData;
		NullCheck(L_6);
		int32_t L_7 = L_6->___EnableableComponentTypeIndexCount;
		V_3 = L_7;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_8 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE* L_9 = (ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE*)(&L_8->___Changed);
		int32_t L_10 = L_9->___Count;
		V_4 = L_10;
		int32_t L_11 = V_3;
		int32_t L_12 = V_4;
		V_5 = ((int32_t)il2cpp_codegen_add(L_11, L_12));
		int32_t L_13 = V_5;
		uint32_t L_14 = sizeof(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C);
		if ((uintptr_t)((uintptr_t)L_13) * (uintptr_t)L_14 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_15 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)((uintptr_t)L_13), (int32_t)L_14));
		int8_t* L_16 = (int8_t*) (L_15 ? alloca(L_15) : NULL);
		memset(L_16, 0, L_15);
		V_6 = (TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)(L_16);
		V_7 = 0;
		V_9 = 0;
		goto IL_00b9;
	}

IL_005e:
	{
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_17 = __this->____QueryData;
		NullCheck(L_17);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_18 = L_17->___RequiredComponents;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_19 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE* L_20 = (ChangedFilter_t55DB3F02469E53626DA400F9A19ABE3183B485EE*)(&L_19->___Changed);
		U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A* L_21 = (U3CIndexInEntityQueryU3Ee__FixedBuffer_t16145BD96786E58BD62F3D7542DA41E279C0E65A*)(&L_20->___IndexInEntityQuery);
		int32_t* L_22 = (int32_t*)(&L_21->___FixedElementField);
		int32_t L_23 = V_9;
		int32_t L_24 = *((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_22, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_23), 4)))));
		uint32_t L_25 = sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_26 = (*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_18, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_24), (int32_t)L_25)))));
		V_10 = L_26;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_27 = V_6;
		int32_t L_28 = V_7;
		int32_t L_29 = L_28;
		V_7 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		uint32_t L_30 = sizeof(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_31 = V_10;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_32 = L_31.___TypeIndex;
		*(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)((TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)il2cpp_codegen_add((intptr_t)L_27, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_29), (int32_t)L_30)))) = L_32;
		int32_t L_33 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_33, 1));
	}

IL_00b9:
	{
		int32_t L_34 = V_9;
		int32_t L_35 = V_4;
		if ((((int32_t)L_34) < ((int32_t)L_35)))
		{
			goto IL_005e;
		}
	}
	{
		V_11 = 0;
		goto IL_00fc;
	}

IL_00c4:
	{
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_36 = V_6;
		int32_t L_37 = V_7;
		int32_t L_38 = L_37;
		V_7 = ((int32_t)il2cpp_codegen_add(L_38, 1));
		uint32_t L_39 = sizeof(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C);
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_40 = __this->____QueryData;
		NullCheck(L_40);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_41 = L_40->___EnableableComponentTypeIndices;
		int32_t L_42 = V_11;
		uint32_t L_43 = sizeof(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_44 = (*(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)((TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)il2cpp_codegen_add((intptr_t)L_41, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_42), (int32_t)L_43)))));
		*(TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)((TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)il2cpp_codegen_add((intptr_t)L_36, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_38), (int32_t)L_39)))) = L_44;
		int32_t L_45 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_45, 1));
	}

IL_00fc:
	{
		int32_t L_46 = V_11;
		int32_t L_47 = V_3;
		if ((((int32_t)L_46) < ((int32_t)L_47)))
		{
			goto IL_00c4;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_48 = ___2_additionalInputDep;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_49 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47* L_50;
		L_50 = EntityDataAccess_get_DependencyManager_m393F3E50C2B049B984CCC546CE9B188E6488E879((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_49, NULL);
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C* L_51 = V_6;
		int32_t L_52 = V_5;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_53;
		L_53 = ComponentDependencyManager_GetDependency_m0A677FF59E9B267E27AB5898CDEAD88CF1E0C0D7((ComponentDependencyManager_t88715270EBD172A299D4F6DB471143B7E0BCDB47*)L_50, L_51, L_52, (TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C*)((uintptr_t)(&V_0)), 1, (bool)0, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_54;
		L_54 = JobHandle_CombineDependencies_mA265FBED9D75AEF610251410AFC7766F40D5BB05(L_48, L_53, NULL);
		V_8 = L_54;
		NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 L_55 = ___0_componentDataList;
		EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 L_56 = ___1_outer;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_57 = V_8;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_58 = ___3_outJobHandle;
		((  void (*) (NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1, DynamicComponentTypeHandle_t3E20E0F3BAD2BBFEF185BE607A282ECFEAF35CB6*, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 3)))(L_55, (&V_2), L_56, L_57, L_58, il2cpp_rgctx_method(method->rgctx_data, 3));
		return;
	}
}
IL2CPP_EXTERN_C  void EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3_AdjustorThunk (RuntimeObject* __this, NativeList_1_tC1434025FAC1738D2E1A0029AA90EC61D91370C1 ___0_componentDataList, EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90 ___1_outer, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___2_additionalInputDep, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___3_outJobHandle, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	EntityQueryImpl_CopyFromComponentDataListAsync_TisIl2CppFullySharedGenericStruct_m8F8400F8DAC33BAD98AAACE3F1078DFB746DF4D3(_thisAdjusted, ___0_componentDataList, ___1_outer, ___2_additionalInputDep, ___3_outJobHandle, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A_gshared (EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* __this, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C V_0;
	memset((&V_0), 0, sizeof(V_0));
	UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9* V_4 = NULL;
	int32_t V_5 = 0;
	ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A V_6;
	memset((&V_6), 0, sizeof(V_6));
	int32_t V_7 = 0;
	ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* V_8 = NULL;
	{
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_0;
		L_0 = TypeManager_GetTypeIndex_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m253E94A751C8AAD2F9AE71E695614F8BBC0DD5B0(il2cpp_rgctx_method(method->rgctx_data, 0));
		V_0 = L_0;
		EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B* L_1 = (EntityQueryFilter_t4A9651CB7DA59AFE8AAF946C19EC6B0D1ACA2F8B*)(&__this->____Filter);
		bool L_2;
		L_2 = EntityQueryFilter_get_RequiresMatchesFilter_mE75B9A9EB4397E4364063D44B5B9094BDA71885E(L_1, NULL);
		if (L_2)
		{
			goto IL_00b5;
		}
	}
	{
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_3 = __this->____QueryData;
		NullCheck(L_3);
		int32_t L_4 = L_3->___RequiredComponentsCount;
		if ((((int32_t)L_4) > ((int32_t)2)))
		{
			goto IL_00b5;
		}
	}
	{
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_5 = __this->____QueryData;
		NullCheck(L_5);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_6 = L_5->___RequiredComponents;
		uint32_t L_7 = sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA);
		NullCheck(((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_6, (int32_t)L_7)));
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_8 = ((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_6, (int32_t)L_7))->___TypeIndex;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_9 = V_0;
		bool L_10;
		L_10 = TypeIndex_op_Equality_mB89F45E805E8BCEE5144CBB65B915C5C6841FDAA_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_00b5;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 L_11;
		L_11 = EntityQueryImpl_GetMatchingChunkCache_m02A0624170E25001E9653BB3DF1071BF0467F21A(__this, NULL);
		V_1 = L_11;
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A* L_12;
		L_12 = UnsafeCachedChunkList_get_ChunkIndices_m23D1D0D4A6DB3DC973C45A700D2F298557A54D27((&V_1), NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_13 = (*(ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A*)L_12);
		V_2 = L_13;
		UnsafeCachedChunkList_t48CE8479B1EEA20F34D6EB59806214668DB204A3 L_14 = V_1;
		UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718* L_15 = L_14.___PerChunkMatchingArchetypeIndex;
		NullCheck(L_15);
		int32_t* L_16 = L_15->___Ptr;
		int32_t L_17 = (*(L_16));
		V_3 = L_17;
		EntityQueryData_t20DB32E7BB3F8732C371E45E8A8CEBCE62B61C26* L_18 = __this->____QueryData;
		NullCheck(L_18);
		UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566* L_19 = (UnsafeMatchingArchetypePtrList_t7BE58FA0D1C0757782B0CA05207B0E07690ED566*)(&L_18->___MatchingArchetypes);
		MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9** L_20;
		L_20 = UnsafeMatchingArchetypePtrList_get_Ptr_mB3D87332ACA44E460C04BE0980062299360C3715(L_19, NULL);
		int32_t L_21 = V_3;
		uint32_t L_22 = sizeof(MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9*);
		intptr_t L_23 = *((intptr_t*)((MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9**)il2cpp_codegen_add((intptr_t)L_20, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_21), (int32_t)L_22)))));
		V_4 = (MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9*)L_23;
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_24 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* L_25;
		L_25 = EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_24, NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_26 = V_2;
		il2cpp_codegen_runtime_class_init_inline(EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* L_27;
		L_27 = EntityComponentStore_GetArchetype_mBED719B36E99CD84831EECCB8815350088F28821_inline((EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F*)L_25, L_26, NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_28 = V_2;
		MatchingArchetype_t1D80A6ED7DFEC90CD004B3D338666243DB31D7D9* L_29 = V_4;
		NullCheck(L_29);
		U3CIndexInArchetypeU3Ee__FixedBuffer_t170AD5FA997C14F5017A342DD4D7545160BAF695* L_30 = (U3CIndexInArchetypeU3Ee__FixedBuffer_t170AD5FA997C14F5017A342DD4D7545160BAF695*)(&L_29->___IndexInArchetype);
		int32_t* L_31 = (int32_t*)(&L_30->___FixedElementField);
		int32_t L_32 = *((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_31, 4)));
		void* L_33;
		L_33 = ChunkIterationUtility_GetChunkComponentDataROPtr_m72023A410F08B53747F1DE466CC4BADF3AE42727(L_27, L_28, L_32, NULL);
		ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* L_34;
		L_34 = UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_inline(L_33, il2cpp_rgctx_method(method->rgctx_data, 1));
		ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 L_35 = (*(ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602*)L_34);
		return L_35;
	}

IL_00b5:
	{
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_36 = V_0;
		il2cpp_codegen_runtime_class_init_inline(EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574_il2cpp_TypeInfo_var);
		EntityQueryImpl_GetSingletonChunkAndEntity_m9294DADB80BDAA2C49500FADC85AB9DACE5D995F(__this, L_36, (&V_5), (&V_6), (&V_7), NULL);
		EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36* L_37 = __this->____Access;
		il2cpp_codegen_runtime_class_init_inline(EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36_il2cpp_TypeInfo_var);
		EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* L_38;
		L_38 = EntityDataAccess_get_EntityComponentStore_m326C3B90484B39F30DF478BCC5C586FDFACB3054((EntityDataAccess_t98E1CF6F73892A92AA3FF870A4BD941364E9CD36*)L_37, NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_39 = V_6;
		il2cpp_codegen_runtime_class_init_inline(EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F_il2cpp_TypeInfo_var);
		Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* L_40;
		L_40 = EntityComponentStore_GetArchetype_mBED719B36E99CD84831EECCB8815350088F28821_inline((EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F*)L_38, L_39, NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_41 = V_6;
		int32_t L_42 = V_5;
		void* L_43;
		L_43 = ChunkIterationUtility_GetChunkComponentDataROPtr_m72023A410F08B53747F1DE466CC4BADF3AE42727(L_40, L_41, L_42, NULL);
		V_8 = (ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602*)L_43;
		ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* L_44 = V_8;
		int32_t L_45 = V_7;
		uint32_t L_46 = sizeof(ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602);
		ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* L_47;
		L_47 = UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_inline((void*)((ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602*)il2cpp_codegen_add((intptr_t)L_44, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_45), (int32_t)L_46)))), il2cpp_rgctx_method(method->rgctx_data, 1));
		ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 L_48 = (*(ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602*)L_47);
		return L_48;
	}
}
IL2CPP_EXTERN_C  ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574*>(__this + _offset);
	ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602 _returnValue;
	_returnValue = EntityQueryImpl_GetSingleton_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_mAAD60AC8CF8260230D2D758775F66EFC3AFAAA1A(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* EntityQuery__GetImpl_m3E1EC62BB22FA905262DB3199F289864B47AA7AE_inline (EntityQuery_t23B7A11FAA475D860E94409BFD4CF7E4B337CF90* __this, const RuntimeMethod* method) 
{
	{
		EntityQueryImpl_t3E7DD11B3ECD6D708BF02ACF2C07B42A913F7574* L_0 = __this->_____impl;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t EntityComponentStore_get_GlobalSystemVersion_m19BE06808BCF2249B439A2FEAA9DF8F4DCEFA5D4_inline (EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* __this, const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = __this->___m_GlobalSystemVersion;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool TypeIndex_op_Equality_mB89F45E805E8BCEE5144CBB65B915C5C6841FDAA_inline (TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___0_lhs, TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C ___1_rhs, const RuntimeMethod* method) 
{
	{
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_0 = ___0_lhs;
		int32_t L_1 = L_0.___Value;
		TypeIndex_t18365699387F045FB6E4ED39554CD5BE82A04F7C L_2 = ___1_rhs;
		int32_t L_3 = L_2.___Value;
		return (bool)((((int32_t)L_1) == ((int32_t)L_3))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* EntityComponentStore_GetArchetype_mBED719B36E99CD84831EECCB8815350088F28821_inline (EntityComponentStore_tA85E100ECD667365B260A68DFD9DF9B7C04D037F* __this, ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A ___0_chunk, const RuntimeMethod* method) 
{
	{
		PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135* L_0;
		L_0 = PerChunkArray_get_ChunkData_m91CBDB364CCABDF0BD9DCC037E3F974C31511A65(NULL);
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_1 = ___0_chunk;
		int32_t L_2;
		L_2 = ChunkIndex_op_Implicit_m8816E6F68BE715713DCAB578270F3DE6D6B07A85_inline(L_1, NULL);
		uint32_t L_3 = sizeof(PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135);
		NullCheck(((PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		Archetype_t96EB5691CCC58A7A4E29CA4F9EA62A25E4C14582* L_4 = ((PerChunkData_t1837BB30B95C4DD39A4908ECC71AB0B75DFF9135*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3))))->___Archetype;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeList_1_Add_m5F84A82FA4F996EC7C26858636817A67765BA83E_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* ___0_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->___m_length;
		V_0 = L_0;
		int32_t L_1 = __this->___m_length;
		int32_t L_2 = __this->___m_capacity;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003f;
		}
	}
	{
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_3 = __this->___Ptr;
		int32_t L_4 = V_0;
		uint32_t L_5 = sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_6 = ___0_value;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_7 = (*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)L_6);
		*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_3, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_4), (int32_t)L_5)))) = L_7;
		int32_t L_8 = __this->___m_length;
		__this->___m_length = ((int32_t)il2cpp_codegen_add(L_8, 1));
		return;
	}

IL_003f:
	{
		int32_t L_9 = V_0;
		UnsafeList_1_Resize_m62AE410F7B9BB1F934C33AB8E6E65198CF695A1F(__this, ((int32_t)il2cpp_codegen_add(L_9, 1)), (int32_t)0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 3));
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_10 = __this->___Ptr;
		int32_t L_11 = V_0;
		uint32_t L_12 = sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_13 = ___0_value;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_14 = (*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)L_13);
		*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_10, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_11), (int32_t)L_12)))) = L_14;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA NativeList_1_get_Item_mDB1235665FA232DD11F045172D369C9EF2570A90_gshared_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_0 = __this->___m_ListData;
		int32_t L_1 = ___0_index;
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_2;
		L_2 = UnsafeList_1_get_Item_m32C5F76D029656B707A73DAEFC7FE6A171DC48ED_inline((UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)L_0, L_1, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 6));
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t NativeList_1_get_Length_mC63BD08AA6FC1366F2CC2A4CFA7DF2B1ADC80849_gshared_inline (NativeList_1_tE0880900DE1F3AA8060D398970BECC5DD7055F6F* __this, const RuntimeMethod* method) 
{
	{
		UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* L_0 = __this->___m_ListData;
		int32_t L_1;
		L_1 = UnsafeList_1_get_Length_m9CCC57A9A6B0D52DEA4CD66A9B78C2C5A5A12B96_inline((UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674*)L_0, il2cpp_rgctx_method(InitializedTypeInfo(method->klass)->rgctx_data, 11));
		int32_t L_2;
		L_2 = CollectionHelper_AssumePositive_mD1EC1F05F50F605141D9BA5D70C4332AC902B4B1_inline(L_1, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602* UnsafeUtility_AsRef_TisClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602_m4C7406DDF24B2388D18828302A2DDBFAAD19B9D7_gshared_inline (void* ___0_ptr, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		return (ClientServerTickRate_t16FDBD0A027833FD92846C5F6B046820DE125602*)(L_0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ChunkIndex_op_Implicit_m8816E6F68BE715713DCAB578270F3DE6D6B07A85_inline (ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A ___0_index, const RuntimeMethod* method) 
{
	{
		ChunkIndex_t932E9A325E198362B9521CAD777D34C98F26792A L_0 = ___0_index;
		int32_t L_1 = L_0.___Value;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t CollectionHelper_AssumePositive_mD1EC1F05F50F605141D9BA5D70C4332AC902B4B1_inline (int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA UnsafeList_1_get_Item_m32C5F76D029656B707A73DAEFC7FE6A171DC48ED_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA* L_0 = __this->___Ptr;
		int32_t L_1 = ___0_index;
		int32_t L_2;
		L_2 = CollectionHelper_AssumePositive_mD1EC1F05F50F605141D9BA5D70C4332AC902B4B1_inline(L_1, NULL);
		uint32_t L_3 = sizeof(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA);
		ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA L_4 = (*(ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)((ComponentType_t0CB4E9723924AAC17CE8F38A0080018ED412DBDA*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(((intptr_t)L_2), (int32_t)L_3)))));
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeList_1_get_Length_m9CCC57A9A6B0D52DEA4CD66A9B78C2C5A5A12B96_gshared_inline (UnsafeList_1_tF6E128EA51C65242C59010B65BDAD99951E1A674* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___m_length;
		int32_t L_1;
		L_1 = CollectionHelper_AssumePositive_mD1EC1F05F50F605141D9BA5D70C4332AC902B4B1_inline(L_0, NULL);
		return L_1;
	}
}
