//
//  CCScale9ProgressBar.h
//  MagicEra
//
//  Created by wenlong on 13-1-7.
//
//

#ifndef MagicEra_CCScale9ProgressBar_h
#define MagicEra_CCScale9ProgressBar_h

#include "cocos2d.h"
#include "ExtensionMacros.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class CCScale9ProgressBar : public CCNodeRGBA {
public:
    CCScale9ProgressBar();
    virtual ~CCScale9ProgressBar();
    
public:
    /** Original sprite's size. */
    CC_SYNTHESIZE_READONLY(CCSize, m_originalSize, OriginalSize);
    /** Prefered sprite's size. By default the prefered size is the original size. */
    
    //if the preferredSize component is given as -1, it is ignored
    CC_PROPERTY(CCSize, m_preferredSize, PreferredSize);
    /**
     * The end-cap insets.
     * On a non-resizeable sprite, this property is set to CGRectZero; the sprite
     * does not use end caps and the entire sprite is subject to stretching.
     */
    CC_PROPERTY(CCRect, m_capInsets, CapInsets);
    /** Sets the left side inset */
    CC_PROPERTY(float, m_insetLeft, InsetLeft);
    /** Sets the top side inset */
    CC_PROPERTY(float, m_insetTop, InsetTop);
    /** Sets the right side inset */
    CC_PROPERTY(float, m_insetRight, InsetRight);
    /** Sets the bottom side inset */
    CC_PROPERTY(float, m_insetBottom, InsetBottom);
    
    /** Sets is progress with head*/
    CC_PROPERTY(bool, m_bIsProgressWithHead, IsProgressWithHead);
    
    /** Sets is progress with head*/
    CC_PROPERTY(float, ratio, VisibleRatio);
    
    /** Opacity: conforms to CCRGBAProtocol protocol */
    CC_PROPERTY(GLubyte, m_cOpacity, Opacity)
    /** Color: conforms to CCRGBAProtocol protocol */
    CC_PROPERTY_PASS_BY_REF(ccColor3B, m_tColor, Color)
    
protected:
    bool m_bSpritesGenerated;
    CCRect m_spriteRect;
    bool   m_bSpriteFrameRotated;
    CCRect m_capInsetsInternal;
    bool m_positionsAreDirty;
    bool m_percentIsDirty;
    
    void setLeftPercent(int per);
    void setCenterPercent(int per);
    void setRightPercent(int per);
    
    CCSpriteBatchNode* scale9Image;
    
    CCProgressTimer* createProgressTimer(CCSprite* sprite);
    
    float leftWidth, centerWidth, rightWidth;
    
    CCProgressTimer* top;
    CCProgressTimer* bottom;
    CCProgressTimer* centre;
    
    CCProgressTimer* topLeft;
    CCProgressTimer* bottomLeft;
    CCProgressTimer* left;
    
    CCProgressTimer* topRight;
    CCProgressTimer* bottomRight;
    CCProgressTimer* right;

    /** Conforms to CocosNodeRGBA protocol. */
    ccColor3B m_sColorUnmodified;
    bool m_bIsOpacityModifyRGB;
    
    void updateCapInset();
    void updatePositions();
    
    void updateVisiblePercent();
    
    void updatePercentWithHead();
    
    void updatePercent();
    
    // add by wenlong
    float m_fRatio;
    
public:
    static CCScale9ProgressBar* createWithSpriteFrame(CCSpriteFrame* frame, CCRect capInsets);
    static CCScale9ProgressBar* createWithSpriteFrame(CCSpriteFrame* frame);
    
    virtual void setContentSize(const CCSize & size);
    virtual void visit();
    
    virtual bool init();
    
    virtual bool initWithBatchNode(CCSpriteBatchNode* batchnode, CCRect rect, bool rotated, CCRect capInsets);
    virtual bool initWithBatchNode(CCSpriteBatchNode* batchnode, CCRect rect, CCRect capInsets);
    
    
    /**
     * Initializes a 9-slice sprite with an sprite frame and with the specified
     * cap insets.
     * Once the sprite is created, you can then call its "setContentSize:" method
     * to resize the sprite will all it's 9-slice goodness intract.
     * It respects the anchorPoint too.
     *
     * @param spriteFrame The sprite frame object.
     * @param capInsets The values to use for the cap insets.
     */
    virtual bool initWithSpriteFrame(CCSpriteFrame* spriteFrame, CCRect capInsets);
    
    /**
     * Creates and returns a new sprite object with the specified cap insets.
     * You use this method to add cap insets to a sprite or to change the existing
     * cap insets of a sprite. In both cases, you get back a new image and the
     * original sprite remains untouched.
     *
     * @param capInsets The values to use for the cap insets.
     */
    CCScale9ProgressBar* resizableSpriteWithCapInsets(CCRect capInsets);
    
    // optional
    
    /** sets the premultipliedAlphaOpacity property.
     If set to NO then opacity will be applied as: glColor(R,G,B,opacity);
     If set to YES then oapcity will be applied as: glColor(opacity, opacity, opacity, opacity );
     Textures with premultiplied alpha will have this property by default on YES. Otherwise the default value is NO
     @since v0.8
     */
    virtual void setOpacityModifyRGB(bool bValue);
    
    /** returns whether or not the opacity will be applied using glColor(R,G,B,opacity) or glColor(opacity, opacity, opacity, opacity);
     @since v0.8
     */
    virtual bool isOpacityModifyRGB(void);
    
    virtual bool updateWithBatchNode(CCSpriteBatchNode* batchnode, CCRect rect, bool rotated, CCRect capInsets);
    
    virtual void setSpriteFrame(CCSpriteFrame * spriteFrame);
};

#endif
