#ifndef J3DMODELDATA_H
#define J3DMODELDATA_H

#include "JSystem/J3DGraphAnimator/J3DJointTree.h"
#include "JSystem/J3DGraphAnimator/J3DMaterialAttach.h"
#include "JSystem/J3DGraphAnimator/J3DShapeTable.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "JSystem/J3DGraphBase/J3DVertex.h"
#include "JSystem/J3DGraphBase/J3DMaterial.h"

typedef struct _GXColor GXColor;
class JUTNameTab;

enum J3DMaterialCopyFlag {
    J3DMatCopyFlag_Material = 0x01,
    J3DMatCopyFlag_Texture = 0x02,
    J3DMatCopyFlag_All = 0x03,
};

class J3DModelData {
public:
    void clear();
    J3DModelData();
    s32 newSharedDisplayList(u32);
    bool isDeformablePositionFormat() const;
    void indexToPtr();
    void makeSharedDL();
    void initShapeNodes();
    void sortVcdVatCmd();
    void setMaterialTable(J3DMaterialTable*, J3DMaterialCopyFlag);

    virtual ~J3DModelData();

    J3DMaterialTable& getMaterialTable() { return mMaterialTable; }
    JUTNameTab* getMaterialName() const { return mMaterialTable.getMaterialName(); }
    J3DVertexData& getVertexData() { return mVertexData; }
    GXVtxAttrFmtList* getVtxAttrFmtList() const { return ((J3DVertexData*)&mVertexData)->getVtxAttrFmtList(); }
    u16 getShapeNum() const { return mShapeTable.getShapeNum(); }
    u16 getMaterialNum() const { return mMaterialTable.getMaterialNum(); }
    u16 getJointNum() const { return mJointTree.getJointNum(); }
    u16 getDrawMtxNum() const { return mJointTree.getDrawMtxNum(); }
    J3DMaterial* getMaterialNodePointer(u16 idx) const {
        return mMaterialTable.getMaterialNodePointer(idx);
    }
    u32 getVtxNum() const { return mVertexData.getVtxNum(); }
    u32 getNrmNum() const { return mVertexData.getNrmNum(); }
    J3DDrawMtxData * getDrawMtxData() { return mJointTree.getDrawMtxData(); }
    u8 getDrawMtxFlag(u16 idx) const { return mJointTree.getDrawMtxFlag(idx); }
    u16 getDrawMtxIndex(u16 idx) const { return mJointTree.getDrawMtxIndex(idx); }
    J3DShape* getShapeNodePointer(u16 idx) const { return mShapeTable.getShapeNodePointer(idx); }
    J3DJoint* getJointNodePointer(u16 idx) const { return mJointTree.getJointNodePointer(idx); }
    J3DJointTree& getJointTree() { return mJointTree; }
    JUTNameTab* getJointName() const { return mJointTree.getJointName(); }
    Mtx& getInvJointMtx(s32 idx) const { return mJointTree.getInvJointMtx(idx); }
    J3DTexture* getTexture() const { return mMaterialTable.getTexture(); }
    JUTNameTab* getTextureName() const { return mMaterialTable.getTextureName(); }
    void setTexture(J3DTexture* pTexture) { mMaterialTable.setTexture(pTexture); }
    void setTextureName(JUTNameTab* pTextureName) { mMaterialTable.setTextureName(pTextureName); }
    bool isLocked() { return mMaterialTable.isLocked(); }
    u16 getDrawFullWgtMtxNum() const { return mJointTree.getDrawFullWgtMtxNum(); }
    u16 getWEvlpMtxNum() const { return mJointTree.getWEvlpMtxNum(); }
    u16* getWEvlpMixMtxIndex() const { return mJointTree.getWEvlpMixIndex(); }
    f32* getWEvlpMixWeight() const { return mJointTree.getWEvlpMixWeight(); }
    u8 getWEvlpMixMtxNum(u16 idx) const { return mJointTree.getWEvlpMixMtxNum(idx); }
    u32 getModelDataType() const { return mJointTree.getModelDataType(); }
    void* getVtxPosArray() const { return mVertexData.getVtxPosArray(); }
    void* getVtxNrmArray() const { return mVertexData.getVtxNrmArray(); }
    GXColor* getVtxColorArray(u8 idx) const { return mVertexData.getVtxColorArray(idx); }
    bool checkFlag(u32 flag) const { return (mFlags & flag) ? true : false; }
    u32 getFlag() const { return mFlags; }
    void* getRawData() const { return mpRawData; }
    u16 checkBumpFlag() const { return mbHasBumpArray; }
    void setBumpFlag(u32 flag) { mbHasBumpArray = flag; }
    bool checkBBoardFlag() const { return mbHasBillboard == 1; }
    void entryTexMtxAnimator(J3DAnmTextureSRTKey* anm) { mMaterialTable.entryTexMtxAnimator(anm); }
    void entryTevRegAnimator(J3DAnmTevRegKey* anm) { mMaterialTable.entryTevRegAnimator(anm); }
    void entryTexNoAnimator(J3DAnmTexPattern* anm) { mMaterialTable.entryTexNoAnimator(anm); }
    int removeTexNoAnimator(J3DAnmTexPattern* anm) {
        return mMaterialTable.removeTexNoAnimator(anm);
    }
    int removeTexMtxAnimator(J3DAnmTextureSRTKey* anm) {
        return mMaterialTable.removeTexMtxAnimator(anm);
    }
    int removeTevRegAnimator(J3DAnmTevRegKey* anm) {
        return mMaterialTable.removeTevRegAnimator(anm);
    }
    int removeMatColorAnimator(J3DAnmColor* anm) {
        return mMaterialTable.removeMatColorAnimator(anm);
    }

private:
    /* 0x04 */ void* mpRawData;
    /* 0x08 */ u32 mFlags;
    /* 0x0C */ u16 mbHasBumpArray;
    /* 0x0E */ u16 mbHasBillboard;
    /* 0x10 */ J3DJointTree mJointTree;
    /* 0x58 */ J3DMaterialTable mMaterialTable;
    /* 0x7C */ J3DShapeTable mShapeTable;
    /* 0x84 */ J3DVertexData mVertexData;
    /* 0xE0 */ JUTNameTab * mName;
};  // Size: 0xE4

STATIC_ASSERT(sizeof(J3DModelData) == 0xE4);

#endif /* J3DMODELDATA_H */
