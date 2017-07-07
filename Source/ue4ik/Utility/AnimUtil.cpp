// Copyright (c) Henry Cooney 2017

// Provides animation utility functions (many blueprintable). All functions defined here are pure.

#include "AnimUtil.h"
#include "AnimationRuntime.h"


// Get the world space location vector for a bone
FVector FAnimUtil::GetBoneWorldLocation(USkeletalMeshComponent& SkelComp, FCSPose<FCompactPose>& MeshBases, FCompactPoseBoneIndex BoneIndex)
{
	FTransform BoneTransform = MeshBases.GetComponentSpaceTransform(BoneIndex);
	FAnimationRuntime::ConvertCSTransformToBoneSpace(SkelComp.GetComponentTransform(), MeshBases, BoneTransform, BoneIndex, BCS_WorldSpace);
	return BoneTransform.GetLocation();
}

// Get the world space transform for a bone
FTransform FAnimUtil::GetBoneWorldTransform(USkeletalMeshComponent& SkelComp, FCSPose<FCompactPose>& MeshBases, FCompactPoseBoneIndex BoneIndex)
{
	FTransform BoneTransform = MeshBases.GetComponentSpaceTransform(BoneIndex);
	FAnimationRuntime::ConvertCSTransformToBoneSpace(SkelComp.GetComponentTransform(), MeshBases, BoneTransform, BoneIndex, BCS_WorldSpace);
	return BoneTransform;
}