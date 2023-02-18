
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall CPc::__FetchPcBase(CPc *this,ulong param_1)

{
  CSqlPc *this_00;
  undefined *puVar1;
  byte bVar2;
  undefined uVar3;
  undefined2 uVar4;
  ulong uVar5;
  CMap *pCVar6;
  ETerritory EVar7;
  char cVar8;
  byte bVar9;
  uchar uVar10;
  ushort uVar11;
  int iVar12;
  ulong uVar13;
  uint uVar14;
  longlong lVar15;
  CGuild *pCVar16;
  CDisciple *pCVar17;
  CMapInfo *pCVar18;
  CSector *pCVar19;
  CRegion *pCVar20;
  CSector *pCVar21;
  C3D_float_ *pCVar22;
  CMapInfo *pCVar23;
  longlong lVar24;
  char *pcVar25;
  longlong lVar26;
  uint uVar27;
  CSector *this_01;
  CSector *this_02;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined8 local_res18;
  ETerritory local_res20 [2];
  ulonglong in_stack_ffffffffffffff18;
  ulonglong in_stack_ffffffffffffff20;
  ulonglong uVar31;
  ulonglong in_stack_ffffffffffffff28;
  ulonglong uVar32;
  undefined8 in_stack_ffffffffffffff30;
  undefined4 uVar34;
  ulonglong uVar33;
  undefined8 in_stack_ffffffffffffff38;
  undefined4 uVar35;
  int local_a8;
  CSector *local_a0;
  C3D_float_ local_90;
  C3D_float_ local_80 [2];
  C3D_float_ local_68 [4];
  
  uVar34 = (undefined4)((ulonglong)in_stack_ffffffffffffff30 >> 0x20);
  uVar35 = (undefined4)((ulonglong)in_stack_ffffffffffffff38 >> 0x20);
  lVar15 = (*(code *)0x16a81e8)(0x16a821e);
  this_00 = (CSqlPc *)(lVar15 + 0x1aba8);
  iVar12 = CSqlPc::GetPcDetail(this_00,param_1);
  if (iVar12 == 0) {
    cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x11);
    if ((cVar8 == '\0') && (*(char *)(lVar15 + 0x23d98) == '\x03')) {
      return ::eErrNoContentsNotSupport;
    }
    cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x40);
    if ((cVar8 == '\0') && (*(char *)(lVar15 + 0x23d98) == '\x04')) {
      return 0;
    }
    puVar1 = &this->field_0x15288;
    (*(code *)0x169c7d0)(puVar1);
    (*(code *)0x169c7ac)(&this->field_0x15318);
    uVar33 = CONCAT44(uVar34,*(undefined4 *)(lVar15 + 0x23e38));
    uVar32 = in_stack_ffffffffffffff28 & 0xffffffffffffff00 | (ulonglong)*(byte *)(lVar15 + 0x24040)
    ;
    uVar31 = in_stack_ffffffffffffff20 & 0xffffffffffffff00 | (ulonglong)*(byte *)(lVar15 + 0x24018)
    ;
    uVar13 = (*(code *)0x169ba7c)
                       (puVar1,param_1,*(undefined *)(lVar15 + 0x23d98),
                        *(ushort *)(lVar15 + 0x23dc0) & 0xff00 | (ushort)*(byte *)(lVar15 + 0x23fc8)
                        ,in_stack_ffffffffffffff18 & 0xffffffffffffff00 |
                         (ulonglong)*(byte *)(lVar15 + 0x23ff0),uVar31,uVar32,uVar33,
                        CONCAT44(uVar35,*(undefined4 *)(lVar15 + 0x23e88)),
                        *(undefined8 *)(lVar15 + 0x23de8),*(ushort *)(lVar15 + 0x23dc0),
                        lVar15 + 0x23d68);
    if (0 < (int)uVar13) {
      (*(code *)0x16a813c)(0x16a8172,0,2,uVar13,"%s=>Simple",lVar15 + 0x23d68);
      return uVar13;
    }
    this->__mBeginHp = *(int *)&this->field_0x152c0;
    this->__mBeginMp = *(int *)&this->field_0x152c4;
    uVar4 = *(undefined2 *)(_DAT_016a81c0 + 0xc);
    *(ulong *)&this->field_0x152f4 = param_1;
    *(undefined2 *)&this->field_0x152f0 = uVar4;
    *(undefined2 *)&this->field_0xf4 = *(undefined2 *)(lVar15 + 0x23e10);
    *(undefined2 *)&this->field_0xf6 = *(undefined2 *)(lVar15 + 0x23e60);
    this->__mPreventItemDrop = *(char *)(lVar15 + 0x26378) != '\0';
    (*(code *)0x169ba52)(puVar1,*(undefined2 *)(lVar15 + 0x23f50));
    if (*(longlong *)(lVar15 + 0x24178) != -1) {
      pCVar16 = CGuildMgr::Load(&CGuildMgr::__mSingleton,*(ulong *)(lVar15 + 0x24180),(char *)0x0);
      if (pCVar16 == (CGuild *)0x0) {
        uVar31 = uVar32 & 0xffffffff00000000 | (ulonglong)*(uint *)(lVar15 + 0x24180);
        pcVar25 = "%s=>Guild(%d)";
        goto LAB_140175000;
      }
      local_res18 = " ";
      if (*(longlong *)(lVar15 + 0x241c8) != -1) {
        local_res18 = (char *)(lVar15 + 0x241d0);
      }
      uVar13 = pCVar16->__mMarkSec;
      uVar5 = *(ulong *)(lVar15 + 0x24180);
      bVar2 = pCVar16->__mHonorOfEmblemSeq;
      uVar3 = *(undefined *)(lVar15 + 0x241a8);
      bVar9 = CUnitedGuildWarInfoMgr::GetEmblemOfHonorSeqEffect
                        (&CUnitedGuildWarInfoMgr::__mSingleton,uVar5,param_1);
      uVar33 = uVar33 & 0xffffffffffffff00 | (ulonglong)bVar9;
      uVar32 = uVar32 & 0xffffffffffffff00 | (ulonglong)bVar2;
      uVar13 = (*(code *)0x16a3b16)
                         (&this->field_0x15288,uVar5,uVar13,uVar3,local_res18,
                          uVar31 & 0xffffffff00000000 | (ulonglong)(uVar13 != 0),uVar32,uVar33);
      if (0 < (int)uVar13) {
        uVar31 = uVar32 & 0xffffffff00000000 | (ulonglong)*(uint *)(lVar15 + 0x24180);
        pcVar25 = "%s=>Guild(%d)";
        goto LAB_1401750e5;
      }
      uVar11 = CParmSiegeDfnsBenefit::GetDfnsBenefitLv
                         (&CParmSiegeDfnsBenefit::__mSingleton,pCVar16->__mCastleDfnsLv,
                          pCVar16->__mSpotDfnsLv,pCVar16->__mEtelrCastleDfnsLv);
      *(ushort *)&this->field_0x152b6 = uVar11;
      cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x57);
      if ((cVar8 != '\0') &&
         (((CCastleMgr::__mSingleton.__mIsSiege != false ||
           (CCastleMgr::__mSingleton.__mIsSiegeIslandSky != false)) &&
          (*(ulong *)&this->field_0x1528c == pCVar16->__mAtkTowerChar)))) {
        this->field_0x152b5 = 1;
      }
    }
    if (*(ushort *)(lVar15 + 0x263a0) != 0) {
      (this->__mPcFlag).__mFlag = (this->__mPcFlag).__mFlag | *(ushort *)(lVar15 + 0x263a0);
      if ((*(byte *)&(this->__mPcFlag).__mFlag & 0x40) != 0) {
        (this->__mPcFlag).__mFlag = (this->__mPcFlag).__mFlag & 0xffbf;
      }
      if ((*(byte *)&(this->__mPcFlag).__mFlag & 0x80) != 0) {
        (this->__mPcFlag).__mFlag = (this->__mPcFlag).__mFlag & 0xffbf;
      }
    }
    if (*(int *)(lVar15 + 0x24108) != 0) {
      pCVar17 = CDiscipleMgr::Load(&CDiscipleMgr::__mSingleton,*(int *)(lVar15 + 0x24108));
      if (pCVar17 == (CDisciple *)0x0) {
        uVar31 = uVar32 & 0xffffffff00000000 | (ulonglong)*(uint *)(lVar15 + 0x24108);
        pcVar25 = "%s=>Disciple(%d)";
LAB_140175000:
        (*(code *)0x16a813c)(0x16a8172,0,2,::eErrNoGuildNotExist,pcVar25,lVar15 + 0x23d68,uVar31);
        return ::eErrNoGuildNotExist;
      }
      uVar13 = (*(code *)0x16a3ad4)(&this->field_0x15288,*(undefined4 *)(lVar15 + 0x24108));
      if (0 < (int)uVar13) {
        pcVar25 = "%s=>Disciple(%d)";
        uVar31 = uVar32 & 0xffffffff00000000 | (ulonglong)*(uint *)(lVar15 + 0x24108);
LAB_1401750e5:
        (*(code *)0x16a813c)(0x16a8172,0,2,uVar13,pcVar25,lVar15 + 0x23d68,uVar31);
        return uVar13;
      }
    }
    uVar13 = (*(code *)0x16a3aac)(&this->field_0x15288,*(undefined2 *)(lVar15 + 0x23dc0));
    if (0 < (int)uVar13) {
      (*(code *)0x16a813c)
                (0x16a8172,0,2,uVar13,"%s:%s=>State(%d)",this->__mUserId,lVar15 + 0x23d68,
                 uVar33 & 0xffffffff00000000 | (ulonglong)*(ushort *)(lVar15 + 0x23dc0));
      return uVar13;
    }
    FnlApp::CVector::CVector
              ((CVector *)local_80,*(float *)(lVar15 + 0x24090),*(float *)(lVar15 + 0x240b8),
               *(float *)(lVar15 + 0x240e0));
    pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,local_80);
    if (pCVar18 == (CMapInfo *)0x0) {
LAB_140175342:
      local_80[0]._0_8_ = ::gPosExitedBeginIslandAshburn.__mPoint._0_8_;
      local_80[0].__mZ = ::gPosExitedBeginIslandAshburn.__mPoint.__mZ;
      pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,local_80);
      if (pCVar18 == (CMapInfo *)0x0) {
LAB_1401761b4:
        (*(code *)0x16a813c)(0x16a8172,0,2,::eErrNoPosInvalid,"%s:Home",lVar15 + 0x23d68);
        return ::eErrNoPosInvalid;
      }
      this_02 = (CSector *)pCVar18->mMap;
      local_a0 = CMap::FindSector((CMap *)this_02,local_80);
      if (local_a0 == (CSector *)0x0) goto LAB_1401761b4;
    }
    else {
      this_02 = (CSector *)pCVar18->mMap;
      if (((*(byte *)&this_02->mPc & 8) != 0) && (10 < *(ushort *)&this->field_0x152d8)) {
        local_80[0]._0_8_ = ::gPosExitedBeginIslandAshburn.__mPoint._0_8_;
        local_80[0].__mZ = ::gPosExitedBeginIslandAshburn.__mPoint.__mZ;
        pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,local_80);
        if (pCVar18 == (CMapInfo *)0x0) goto LAB_140175342;
        this_02 = (CSector *)pCVar18->mMap;
      }
      local_a0 = CMap::FindSector((CMap *)this_02,local_80);
      if (local_a0 == (CSector *)0x0) goto LAB_140175342;
    }
    pCVar21 = (CSector *)0x0;
    local_a8 = 0;
    FnlApp::CVector::CVector
              ((CVector *)&local_90,*(float *)(lVar15 + 0x23ed8),*(float *)(lVar15 + 0x23f00),
               *(float *)(lVar15 + 0x23f28));
    pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
    this_01 = pCVar21;
    if (pCVar18 != (CMapInfo *)0x0) {
      this_01 = (CSector *)pCVar18->mMap;
      pCVar19 = CMap::FindSector((CMap *)this_01,&local_90);
      if (((*(byte *)&this_01->mPc & 8) == 0) || (*(ushort *)&this->field_0x152d8 < 0xb)) {
        if ((*(byte *)&(pCVar18->mFlag).__mFlag & 0x20) == 0) {
          cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x21);
          if (cVar8 == '\0') {
            uVar14 = (int)(longlong)
                          ((local_90.__mX - *(float *)&(this_01->mPc).field_0x10) / 61.53846) -
                     (int)(longlong)
                          ((local_90.__mZ - *(float *)&(this_01->mPc).field_0x14) / -61.53846) *
                     (this_01->mMonLocker).__mSec.LockCount;
            uVar27 = *(uint *)&(this_01->mMonLocker).__mSec.OwningThread;
            if (uVar27 <= uVar14) {
              uVar14 = uVar27;
            }
            uVar11 = *(ushort *)
                      ((longlong)(this_01->mMonLocker).__mSec.LockSemaphore +
                      (ulonglong)uVar14 * 6 + 2);
            if (uVar11 < 0x144) {
              lVar26 = (ulonglong)uVar11 * 0x1c + 0x141fb7814;
            }
            else {
              lVar26 = 0x141fb9b84;
            }
            pCVar19 = (CSector *)((ulonglong)pCVar19 & -(ulonglong)(*(int *)(lVar26 + 8) != 0));
          }
          else if ((((pCVar18->mFlag).__mFlag >> 8 & 1) != 0) &&
                  (uVar27 = (*(code *)0x169b0c4)(), this->__mChargeItemInfo[2].mEndTick <= uVar27))
          goto LAB_14017545e;
        }
        else if (*(int *)&this->field_0x1c < 2) goto LAB_14017545e;
      }
      else {
LAB_14017545e:
        pCVar19 = pCVar21;
      }
      if ((((pCVar18->mFlag).__mFlag >> 10 & 1) != 0) && (*(int *)&this->field_0x1c < 2)) {
        pCVar19 = pCVar21;
      }
      if ((((pCVar18->mFlag).__mFlag >> 0xb & 1) != 0) && (*(int *)&this->field_0x1c < 2)) {
        pCVar19 = pCVar21;
      }
      if ((pCVar18->mMapNo == eMapCaveOfPrimordialPirates2) && (*(int *)&this->field_0x1c < 2)) {
        pCVar19 = pCVar21;
      }
      cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x5b);
      if (((cVar8 != '\0') && (((pCVar18->mFlag).__mFlag >> 0xd & 1) != 0)) &&
         (*(int *)&this->field_0x1c < 2)) {
        pCVar19 = pCVar21;
      }
      cVar8 = (*(code *)0x169b6c6)(0x169b6fa,100);
      if (((cVar8 != '\0') &&
          ((pCVar6 = pCVar18->mMap, (pCVar6->__mMapInfo).mMapNo == eMapHistoricSiteOfFullMoon ||
           ((0x7e < (int)(pCVar6->__mMapInfo).mMapNo && ((int)(pCVar6->__mMapInfo).mMapNo < 0x81))))
          )) && (*(int *)&this->field_0x1c < 2)) {
        fVar28 = (float)(*(code *)0x169b7ce)();
        local_a8 = (int)fVar28;
        if (local_a8 == 0) {
          if (pCVar18->mMapNo == eMapLakeOfFullMoon) {
            pCVar19 = (CSector *)0x0;
          }
        }
        else {
          pCVar19 = (CSector *)0x0;
        }
      }
      cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x68);
      if (((cVar8 != '\0') && (((pCVar18->mFlag).__mFlag >> 0xe & 1) != 0)) &&
         (*(int *)&this->field_0x1c < 2)) {
        pCVar19 = (CSector *)0x0;
      }
      cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x75);
      pCVar21 = pCVar19;
      if (((cVar8 != '\0') && (pCVar18->mMapNo == eMapLairOfMeteos)) &&
         (*(int *)&this->field_0x1c < 2)) {
        pCVar21 = (CSector *)0x0;
      }
    }
    pCVar20 = CMapMgr::GetRegion(&CMapMgr::__mSingleton,&local_90);
    if (pCVar20 == (CRegion *)0x0) {
      fVar28 = (float)(*(code *)0x169b848)(&local_90);
      fVar29 = (float)(*(code *)0x169bb8e)(&local_90);
      fVar30 = (float)(*(code *)0x169b828)(&local_90);
      pcVar25 = "PC(%s), X(%.1f), Y(%.1f), Z(%.1f)";
      goto LAB_140175677;
    }
    if ((*(int *)(lVar15 + 0x23e38) < 1) && (1 < pCVar20->mPlace - 0x7f)) {
      if (pCVar20->mPlace == 0x1b) {
        local_90._0_8_ = ::gSummonPos[0]._0_8_;
        local_90.__mZ = ::gSummonPos[0].__mZ;
        pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
        if (pCVar18 != (CMapInfo *)0x0) {
          this_01 = (CSector *)pCVar18->mMap;
          pCVar21 = CMap::FindSector((CMap *)this_01,&local_90);
          goto LAB_140175711;
        }
      }
LAB_140175a3c:
      pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
      if (pCVar18 == (CMapInfo *)0x0) {
        local_90._0_8_ = local_80[0]._0_8_;
        local_90.__mZ = local_80[0].__mZ;
      }
      else {
        pCVar6 = pCVar18->mMap;
        uVar14 = (int)(longlong)((local_90.__mX - (pCVar6->__mMapInfo).mStxX) / 61.53846) -
                 (int)(longlong)((local_90.__mZ - (pCVar6->__mMapInfo).mStxZ) / -61.53846) *
                 (pCVar6->__mRegion).__mSz.__mX;
        uVar27 = (pCVar6->__mRegion).__mArray.__mSz;
        if (uVar14 < uVar27) {
          uVar27 = uVar14;
        }
        uVar27 = (byte)(pCVar6->__mRegion).__mArray.__mArray[uVar27].field_0x1 & 0xf;
        cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x5b);
        if ((cVar8 != '\0') && (uVar27 == 0xc)) {
          uVar27 = 3;
        }
        if (uVar27 == 0) {
          cVar8 = *(char *)(lVar15 + 0x23d98);
          if (cVar8 == '\0') {
            iVar12 = (*(code *)0x169ad8c)();
            iVar12 = iVar12 % 5;
            local_90._0_8_ =
                 CONCAT44(::gGuineaRespawnPosOfNight[iVar12].__mY,
                          ::gGuineaRespawnPosOfNight[iVar12].__mX);
            local_90.__mZ = ::gGuineaRespawnPosOfNight[iVar12].__mZ;
          }
          else if (cVar8 == '\x01') {
            iVar12 = (*(code *)0x169ad8c)();
            iVar12 = iVar12 % 5;
            local_90._0_8_ =
                 CONCAT44(::gGuineaRespawnPosOfDragon[iVar12].__mY,
                          ::gGuineaRespawnPosOfDragon[iVar12].__mX);
            local_90.__mZ = ::gGuineaRespawnPosOfDragon[iVar12].__mZ;
          }
          else if (((cVar8 == '\x02') || ((cVar8 != '\x03' && (cVar8 == '\x04')))) &&
                  (cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x40), cVar8 != '\0')) {
            pCVar22 = STerritoryInfo::GetTownPos(gTerritoryInfo,local_68,(CChar *)0x0);
            local_90._0_8_ = *(undefined8 *)pCVar22;
            local_90.__mZ = pCVar22->__mZ;
          }
          else {
            iVar12 = (*(code *)0x169ad8c)();
            iVar12 = iVar12 % 5;
            local_90._0_8_ =
                 CONCAT44(::gGuineaRespawnPosOfAssassin[iVar12].__mY,
                          ::gGuineaRespawnPosOfAssassin[iVar12].__mX);
            local_90.__mZ = ::gGuineaRespawnPosOfAssassin[iVar12].__mZ;
          }
        }
        else {
          pCVar22 = STerritoryInfo::GetTownPos(gTerritoryInfo + (int)uVar27,local_68,(CChar *)0x0);
          local_90._0_8_ = *(undefined8 *)pCVar22;
          local_90.__mZ = pCVar22->__mZ;
          cVar8 = (*(code *)0x169b6c6)(0x169b6fa,100);
          if (((cVar8 != '\0') && (pCVar18->mMapNo == eMapLakeOfFullMoon)) && (local_a8 == 0)) {
            iVar12 = (*(code *)0x169ad8c)();
            iVar12 = iVar12 % 5;
            local_90._0_8_ =
                 CONCAT44(::gFullMoonCampRespawnPos[iVar12].__mY,
                          ::gFullMoonCampRespawnPos[iVar12].__mX);
            local_90.__mZ = ::gFullMoonCampRespawnPos[iVar12].__mZ;
          }
        }
        pCVar23 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
        this_02 = (CSector *)pCVar23->mMap;
        if (((*(byte *)&this_02->mPc & 8) == 0) || (*(ushort *)&this->field_0x152d8 < 0xb)) {
          if ((*(int *)(lVar15 + 0x23e38) < 1) && ((*(byte *)&(this->__mPcFlag).__mFlag & 4) != 0))
          {
            if (uVar27 == 0) {
              cVar8 = *(char *)(lVar15 + 0x23d98);
              if (cVar8 == '\0') {
                iVar12 = (*(code *)0x169ad8c)();
                iVar12 = iVar12 % 5;
                local_90._0_8_ =
                     CONCAT44(::gGuineaRespawnPosOfNight[iVar12].__mY,
                              ::gGuineaRespawnPosOfNight[iVar12].__mX);
                local_90.__mZ = ::gGuineaRespawnPosOfNight[iVar12].__mZ;
              }
              else if (cVar8 == '\x01') {
                iVar12 = (*(code *)0x169ad8c)();
                iVar12 = iVar12 % 5;
                local_90._0_8_ =
                     CONCAT44(::gGuineaRespawnPosOfDragon[iVar12].__mY,
                              ::gGuineaRespawnPosOfDragon[iVar12].__mX);
                local_90.__mZ = ::gGuineaRespawnPosOfDragon[iVar12].__mZ;
              }
              else if (((cVar8 == '\x02') || ((cVar8 != '\x03' && (cVar8 == '\x04')))) &&
                      (cVar8 = (*(code *)0x169b6c6)(0x169b6fa,0x40), cVar8 != '\0')) {
                local_90._0_8_ =
                     CONCAT44(gTerritoryInfo[0].mRespawnPos.__mY,gTerritoryInfo[0].mRespawnPos.__mX)
                ;
                local_90.__mZ = gTerritoryInfo[0].mRespawnPos.__mZ;
              }
              else {
                iVar12 = (*(code *)0x169ad8c)();
                iVar12 = iVar12 % 5;
                local_90._0_8_ =
                     CONCAT44(::gGuineaRespawnPosOfAssassin[iVar12].__mY,
                              ::gGuineaRespawnPosOfAssassin[iVar12].__mX);
                local_90.__mZ = ::gGuineaRespawnPosOfAssassin[iVar12].__mZ;
              }
            }
            else if (pCVar18->mMapNo != eMapLakeOfFullMoon) {
              if (pCVar18->mMapNo == eMapHorizonOfFullMoon) {
                iVar12 = (*(code *)0x169ad8c)();
                iVar12 = iVar12 % 5;
                local_90._0_8_ =
                     CONCAT44(::gFullMoonCampRespawnPos[iVar12].__mY,
                              ::gFullMoonCampRespawnPos[iVar12].__mX);
                local_90.__mZ = ::gFullMoonCampRespawnPos[iVar12].__mZ;
                goto LAB_1401760b4;
              }
              local_90._0_8_ = *(undefined8 *)&gTerritoryInfo[(int)uVar27].mRespawnPos;
              local_90.__mZ = gTerritoryInfo[(int)uVar27].mRespawnPos.__mZ;
            }
          }
        }
        else {
          local_90._0_8_ = ::gPosExitedBeginIslandAshburn.__mPoint._0_8_;
          local_90.__mZ = ::gPosExitedBeginIslandAshburn.__mPoint.__mZ;
LAB_1401760b4:
          pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
          this_02 = (CSector *)pCVar18->mMap;
        }
        local_a0 = CMap::FindSector((CMap *)this_02,&local_90);
      }
      pCVar21 = local_a0;
      this_01 = this_02;
      if (local_a0 == (CSector *)0x0) {
        fVar28 = (float)(*(code *)0x169b848)(&local_90);
        fVar29 = (float)(*(code *)0x169bb8e)(&local_90);
        fVar30 = (float)(*(code *)0x169b828)(&local_90);
        pcVar25 = "PC(%s), X(%.1f), Y(%.1f), Z(%.1f), aSec is NULL!!!";
LAB_140175677:
        (*(code *)0x16a813c)
                  (0x16a8172,0,2,::eErrNoInvalidPosition,pcVar25,lVar15 + 0x23d68,(double)fVar30,
                   (double)fVar29,(double)fVar28);
        return ::eErrNoInvalidPosition;
      }
    }
    else {
LAB_140175711:
      if (pCVar21 == (CSector *)0x0) goto LAB_140175a3c;
      lVar26 = 0x141fc1074;
      uVar27 = (uint)pCVar20->mPlace;
      if (uVar27 < 0x143) {
        lVar24 = (longlong)(int)uVar27 * 0x40 + 0x141fbbfb4;
      }
      else {
        lVar24 = 0x141fc1074;
      }
      if ((*(byte *)(lVar24 + 4) & 4) == 0) {
        if (uVar27 < 0x143) {
          lVar26 = (ulonglong)pCVar20->mPlace * 0x40 + 0x141fbbfb4;
        }
        iVar12 = *(int *)(lVar26 + 8);
        if (iVar12 < 0x60) goto LAB_140175b89;
        if (0x62 < iVar12) {
          if (iVar12 < 0x69) {
            uVar14 = (int)(longlong)
                          ((local_90.__mX - *(float *)&(this_01->mPc).field_0x10) / 61.53846) -
                     (int)(longlong)
                          ((local_90.__mZ - *(float *)&(this_01->mPc).field_0x14) / -61.53846) *
                     (this_01->mMonLocker).__mSec.LockCount;
            uVar27 = *(uint *)&(this_01->mMonLocker).__mSec.OwningThread;
            if (uVar27 <= uVar14) {
              uVar14 = uVar27;
            }
            bVar2 = *(byte *)((longlong)(this_01->mMonLocker).__mSec.LockSemaphore +
                             (ulonglong)uVar14 * 6 + 1);
            lVar26 = (*(code *)0x16a81e8)(0x16a821e);
            uVar13 = CSqlBanquetHall::CheckOwnBanquetHall
                               ((CSqlBanquetHall *)(lVar26 + 0x377e8),bVar2 & eTerritoryArena,
                                *(ulong *)&this->field_0x1528c);
            if (uVar13 == 0) {
              if (*(int *)(lVar26 + 0x39088) == 0) {
                if (*(char *)(lVar26 + 0x391e0) != '\0') goto LAB_140175b89;
                goto LAB_140175b82;
              }
            }
            else {
              (*(code *)0x16a8198)(lVar26 + 0x377e8,"CSqlBanquetHall::CheckOwnBanquetHall");
            }
          }
          else if (iVar12 != 0x6d) {
            if ((iVar12 < 0xb0) || ((0xb3 < iVar12 && (iVar12 != 0x116)))) goto LAB_140175b89;
            goto LAB_140175873;
          }
          goto LAB_140175a3c;
        }
LAB_140175873:
        local_res18 = (char *)CONCAT44(local_res18._4_4_,0xffffffff);
        local_res20[0] = eTerritoryCnt;
        if (*(int *)&this->field_0x15298 != 0) {
          local_68[0]._0_8_ = local_90._0_8_;
          local_68[0].__mZ = local_90.__mZ;
          iVar12 = CGuildAgitMgr::FindAgit
                             (&CGuildAgitMgr::__mSingleton,local_68,local_res20,(int *)&local_res18)
          ;
          if (iVar12 != 0) {
            lVar26 = (*(code *)0x16a81e8)(0x16a821e);
            EVar7 = local_res20[0];
            uVar13 = CSqlGuildAgit::CheckOwnGuildAgitInfo
                               ((CSqlGuildAgit *)(lVar26 + 0x33c90),local_res20[0],(int)local_res18,
                                *(ulong *)&this->field_0x15298);
            if (uVar13 != 0) {
              if ((int)uVar13 < 0) {
                (*(code *)0x16a8198)(lVar26 + 0x33c90,"CSqlGuildAgit::CheckOwnGuildAgitInfo");
              }
              iVar12 = CGuildAgitMgr::IsOwnerUTGWGuildAgit
                                 (&CGuildAgitMgr::__mSingleton,*(ulong *)&this->field_0x15298,EVar7,
                                  (int)local_res18);
              if ((iVar12 == 0) &&
                 ((((CGuildAgitMgr::__mSingleton.__mInfiniteAgit == (SGuildAgitInfo *)0x0 ||
                    (EVar7 != (CGuildAgitMgr::__mSingleton.__mInfiniteAgit)->mTerritory)) ||
                   ((int)local_res18 != (CGuildAgitMgr::__mSingleton.__mInfiniteAgit)->mGuildAgitNo)
                   ) || (*(ulong *)&this->field_0x15298 !=
                         (CGuildAgitMgr::__mSingleton.__mInfiniteAgit)->mOwnerGID))))
              goto LAB_140175a3c;
            }
            goto LAB_140175b89;
          }
        }
LAB_140175b82:
        pCVar21 = (CSector *)0x0;
      }
      else {
        if (uVar27 < 0x143) {
          lVar24 = (longlong)(int)uVar27 * 0x40 + 0x141fbbfb4;
        }
        else {
          lVar24 = 0x141fc1074;
        }
        iVar12 = *(int *)(lVar24 + 8);
        if (CCastleMgr::__mSingleton.__mIsSiege == false) {
          if ((CCastleMgr::__mSingleton.__mIsSiegeIslandSky != false) &&
             ((iVar12 == 0x114 || (iVar12 == 0x115)))) goto code_r0x0001401757bb;
        }
        else if ((iVar12 != 0x114) && (iVar12 != 0x115)) {
code_r0x0001401757bb:
          if (uVar27 < 0x143) {
            lVar26 = (longlong)(int)uVar27 * 0x40 + 0x141fbbfb4;
          }
          uVar27 = *(uint *)(lVar26 + 8);
          if (uVar27 == 0x114) {
            uVar27 = 0x115;
          }
          if (((int)uVar27 < 0) || (0x142 < uVar27)) {
            lVar26 = 0x141760528;
          }
          else {
            lVar26 = (longlong)(int)uVar27 * 0xb0 + 0x141752718;
          }
          if (((*(int **)(lVar26 + 0x18) == (int *)0x0) ||
              (**(int **)(lVar26 + 0x18) != *(int *)&this->field_0x15298)) &&
             (*(int *)&this->field_0x1c < 2)) goto LAB_140175b82;
        }
      }
LAB_140175b89:
      if (pCVar21 == (CSector *)0x0) goto LAB_140175a3c;
    }
    fVar28 = (float)(*(code *)0x169b7ce)(0x169b6fa,0x1d,6);
    if ((((fVar28 != 0.0) &&
         (fVar28 = (float)(*(code *)0x169b7ce)(0x169b6fa,0x1d,2),
         fVar28 <= (float)(uint)this->__mUseMacroTimes)) &&
        (pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90), pCVar18 != (CMapInfo *)0x0
        )) && (pCVar18->mMapNo != eMapStrangeDungeon)) {
      local_90._0_8_ = ::gSummonPos[0]._0_8_;
      local_90.__mZ = ::gSummonPos[0].__mZ;
      pCVar18 = CMapMgr::GetMapInfo(&CMapMgr::__mSingleton,&local_90);
      if (pCVar18 != (CMapInfo *)0x0) {
        this_01 = (CSector *)pCVar18->mMap;
        pCVar21 = CMap::FindSector((CMap *)this_01,&local_90);
      }
    }
    CGbject::SetPosition((CGbject *)this,(CMap *)this_01,pCVar21,&local_90,false);
    CChar::SetHome((CChar *)this,&local_90);
    *(undefined4 *)&this->field_0x1533c = *(undefined4 *)(lVar15 + 0x23f78);
    (*(code *)0x169bbce)(&this->field_0x15318,(int)*(short *)(lVar15 + 0x23fa0));
    uVar13 = CSqlPc::GetPcPartyMemCntLevel(this_00,param_1);
    if (uVar13 == 0) {
      *(undefined4 *)&this->field_0x17304 = *(undefined4 *)(lVar15 + 0x242d0);
      (**(code **)(*(longlong *)this + 0x70))(this);
      *(uint *)&this->field_0x15348 = (uint)(*(char *)(lVar15 + 0x24158) != '\0');
      (this->__mPcFlag).__mFlag = (this->__mPcFlag).__mFlag | 4;
      iVar12 = CSqlPc::UpdatePcFlag(this_00,param_1,(this->__mPcFlag).__mFlag);
      if (iVar12 == 0) {
        uVar10 = CUnitedGuildWarInfoMgr::GetTeamRankSeqEffect
                           (&CUnitedGuildWarInfoMgr::__mSingleton,param_1);
        this->field_0x15300 = uVar10;
        return 0;
      }
      pcVar25 = "CPc::__FetchPcBase(UpdatePcFlag)";
      goto LAB_140174e0c;
    }
  }
  else if (-1 < iVar12) {
    return ::eErrNoSqlInternalError;
  }
  pcVar25 = "CPc::__FetchPcBase";
LAB_140174e0c:
  (*(code *)0x16a8198)(this_00,pcVar25);
  return ::eErrNoSqlInternalError;
}

